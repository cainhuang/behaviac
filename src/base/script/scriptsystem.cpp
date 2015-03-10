/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA
//
//////////////////////////////////////////////////////////////////////


#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/file/filesystem.h"
#include "behaviac/base/file/filemanager.h"
#include "behaviac/base/script/scriptmarshal.h"
#include "behaviac/base/script/scriptobject.h"
#include "behaviac/base/xml/ixml.h"

#include "behaviac/base/script/lua/lua.h"
#include "behaviac/base/script/lua/lualib.h"

#include "lua/lfunc.h"
#include "lua/lobject.h"
#include "lua/lstate.h"

#ifndef LUA_MAX_GARBAGE_PERIOD
#define LUA_MAX_GARBAGE_PERIOD	256
#endif // LUA_MAX_GARBAGE_PERIOD


BEHAVIAC_IMPLEMNT_SINGLETON(CScriptSystem);

SCRIPTMARSHAL_IMPLEMENT_TYPE(CScriptSystem);

CScriptSystem* GetScriptSystem()
{
    BEHAVIAC_ASSERT(CScriptSystem::GetInstance() != NULL);
    return CScriptSystem::GetInstance();
}

struct lua_State* GetScriptState()
{
    return GetScriptSystem()->GetLuaState();
}


CScriptSystem::CScriptSystem()
{
}

CScriptSystem::~CScriptSystem()
{
    Shutdown();
}

void* CScriptSystem::LuaAlloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    if (nsize == 0)
    {
        BEHAVIAC_FREE(ptr);
        return NULL;
    }
    else
    {
        return BEHAVIAC_REALLOC_WITHTAG(ptr, nsize, "LuaMem");
    }
}

void CScriptSystem::Init()
{
    m_pLS = lua_newstate(CScriptSystem::LuaAlloc, NULL);
    BEHAVIAC_ASSERT("CRASH INCOMING: Unable to initialize Lua." && m_pLS != NULL);
    luaL_openlibs(m_pLS);
    CScriptMarshal::Init(m_pLS);
    // Setup error handler.
    lua_pushcfunction(m_pLS, ErrorHandler);
    m_errorHandler = lua_ref(m_pLS, true);
    // Setup System object.
    {
        SCRIPTMARSHAL_EXPOSE_TYPE_AS(CScriptSystem, "System");
        SCRIPTMARSHAL_REGISTER_FUNCTION(Trace);
        SCRIPTMARSHAL_REGISTER_FUNCTION(Log);
        SCRIPTMARSHAL_REGISTER_FUNCTION(Warning);
    }
    lua_newtable(m_pLS); // Environment table to run scripts in.
    CScriptMarshal::PushData(m_pLS, this);
    lua_setfield(m_pLS, -2, "System");
    CScriptMarshal::PushData(m_pLS, this);
    lua_setglobal(m_pLS, "System");
    m_environmentTable = lua_ref(m_pLS, true);
    m_nObjCreationNumber = 1;
    m_nGCTag = 0;
    RegisterTagHandlers();
    m_BeginStackTop = lua_gettop(m_pLS);
    m_CurrentDeep = 0;
    m_lastGarbageCollectCount = GetGCCount();
}

void CScriptSystem::Shutdown()
{
    if (m_pLS)
    {
        lua_close(m_pLS);
        m_pLS = NULL;
    }
}

void CScriptSystem::Reset()
{
    Shutdown();
    Init();
}

void CScriptSystem::RaiseError(lua_State* L, const char* sErr, ...)
{
    va_list arglist;
    char error[2048];
    va_start(arglist, sErr);
    vsprintf(error, sErr, arglist);
    va_end(arglist);
    behaviac::string errorMessage;
    errorMessage.reserve(1024);
    errorMessage = "A script error has occurred: ";
    errorMessage += error;
    errorMessage += "\nStack traceback:\n";
    int callDepth = 1;
    lua_Debug ar;

    while (lua_getstack(L, callDepth++, &ar))
    {
        errorMessage += "\t";

        if (lua_getinfo(L, "nSl", &ar))
        {
            char stackLine[256];
			string_snprintf(stackLine, 256, "\t%s (%s line %d)\n", ar.name, ar.source, ar.currentline);
            errorMessage += stackLine;
        }
        else
        {
            errorMessage += "\tNo call information";
        }
    }

    BEHAVIAC_ASSERT(0, errorMessage.c_str());
}

void CScriptSystem::HandleErrorCode(lua_State* L, int errorCode)
{
    const char* errorMessage = lua_isstring(L, -1) ? lua_tostring(L, -1) : "No information found about the error.";
    BEHAVIAC_UNUSED_VAR(errorMessage);

    switch (errorCode)
    {
        case LUA_ERRERR:
            BEHAVIAC_ASSERT(0, "An error occurred while running the error handler function: %s", errorMessage);
            break;

        case LUA_ERRRUN:
            // Error was already displayed by ErrorHandler
            break;

        case LUA_ERRSYNTAX:
            BEHAVIAC_ASSERT(0, "An error occurred while parsing a script: %s", errorMessage);
            break;

        case LUA_ERRMEM:
            BEHAVIAC_ASSERT(0, "An error occurred because of memory: %s", errorMessage);
            break;

        default:
            BEHAVIAC_ASSERT(0, "A script error has occurred: %s", errorMessage);
            break;
    }

    lua_pop(L, 1);
}

void CScriptSystem::PushErrorHandler(lua_State* L)
{
    lua_getref(L, m_errorHandler);
}

int CScriptSystem::ErrorHandler(lua_State* L)
{
    if (lua_isstring(L, 1))
    {
        const char* error = lua_tostring(L, 1);
        GetInstance()->RaiseError(L, error);
    }

    return 0;
}

bool CScriptSystem::_ExecuteFile(const char* sFileName)
{
    SCRIPT_STACK_GUARD(m_pLS);
    PushErrorHandler(m_pLS);
    int nRes = luaL_loadfile(m_pLS, sFileName);

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    nRes = lua_pcall(m_pLS, 0, 0, -2);

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    return true;
}

CScriptSystem::ScriptFileListItor CScriptSystem::findFile(const CPathID& path)
{
    for (ScriptFileListItor itor = m_dqLoadedFiles.begin(); itor != m_dqLoadedFiles.end(); ++itor)
    {
        if (*itor == path)
        {
            return itor;
        }
    }

    return m_dqLoadedFiles.end();
}

bool CScriptSystem::ExecuteFile(const char* sFileName, bool forceReload)
{
    if (strlen(sFileName) <= 0)
    {
        return false;
    }

    CPathID sTemp(sFileName);
    ScriptFileListItor itor = this->findFile(sTemp);

    if (itor == m_dqLoadedFiles.end() || forceReload)
    {
        char sRealFileName[MAX_PATH];
        string_sprintf(sRealFileName, "%s_compiled", sFileName);

        if (!_ExecuteFile(sFileName))
        {
            return false;
        }

        if (itor == m_dqLoadedFiles.end())
        {
            m_dqLoadedFiles.push_back(sTemp);
        }
    }

    return true;
}

void CScriptSystem::UnloadScript(const char* sFileName)
{
    if (strlen(sFileName) <= 0)
    {
        return;
    }

    CPathID sTemp(sFileName);
    ScriptFileListItor itor = this->findFile(sTemp);

    if (itor != m_dqLoadedFiles.end())
    {
#ifdef DEBUG_RESID
        BEHAVIAC_LOGINFO("ERASE :%s\n", sTemp.GetFileName());
#endif
        m_dqLoadedFiles.erase(itor);
    }
}

void CScriptSystem::UnloadScripts()
{
    m_dqLoadedFiles.clear();
}

bool CScriptSystem::ReloadScripts()
{
#ifdef DEBUG_RESID
    ScriptFileListItor itor;
    itor = m_dqLoadedFiles.begin();

    while (itor != m_dqLoadedFiles.end())
    {
        ReloadScript(itor->GetFileName(), true);
        ++itor;
    }

#endif
    return true;
}

bool CScriptSystem::ReloadScript(const char* sFileName)
{
    CPathID strTemp(sFileName);
    ScriptFileListItor itor = this->findFile(strTemp);

    if (itor == m_dqLoadedFiles.end())
    {
        RaiseError(m_pLS, "Error reloading \"%s\" the file was not loaded", sFileName);
        return false;
    }

    return _ExecuteFile(sFileName);
}

bool CScriptSystem::ExecuteFunction(lua_State* L, int nargs, int nresults)
{
    int errfunc = -(nargs + 2);
    PushErrorHandler(L);
    lua_insert(L, errfunc);
    int nRes = lua_pcall(L, nargs, nresults, errfunc);

    if (nRes)
    {
        HandleErrorCode(L, nRes);
        return false;
    }

    lua_remove(L, -(nresults + 1));
    return true;
}

bool CScriptSystem::ExecuteBuffer(const char* sBuffer, int nSize, const char* name, bool useEnv)
{
    SCRIPT_STACK_GUARD(m_pLS);
    PushErrorHandler(m_pLS);
    int nRes = luaL_loadbuffer(m_pLS, sBuffer, nSize, name ? name : "__script_buffer__");

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    if (useEnv)
    {
        lua_getref(m_pLS, m_environmentTable);
        lua_setfenv(m_pLS, -2);
    }

    nRes = lua_pcall(m_pLS, 0, 0, -2);

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    return true;
}

bool CScriptSystem::ExecuteString(const char* sBuffer, bool useEnv)
{
    SCRIPT_STACK_GUARD(m_pLS);
    PushErrorHandler(m_pLS);
    int nRes = luaL_loadstring(m_pLS, sBuffer);

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    if (useEnv)
    {
        lua_getref(m_pLS, m_environmentTable);
        lua_setfenv(m_pLS, -2);
    }

    nRes = lua_pcall(m_pLS, 0, 0, -2);

    if (nRes)
    {
        HandleErrorCode(m_pLS, nRes);
        return false;
    }

    return true;
}

void CScriptSystem::Trace(const char* message)
{
    BEHAVIAC_LOGINFO(message);
}

void CScriptSystem::Warning(const char* message)
{
    BEHAVIAC_LOGWARNING(message);
}


#define	SCRIPT_LOG_SHORT_PREFIX		" S> "
#define	SCRIPT_LOG_FULL_PREFIX		SCRIPT_LOG_SHORT_PREFIX

void CScriptSystem::Log(const char* message)
{
#ifdef _DEBUG

    if (message)
    {
        // add the "S>" prefix to understand that this message
        // has been called from a script function
        char sLogMessage[1024];

        if (message[0] <= 5)
        {
            sLogMessage[0] = message[0];
            strcpy(sLogMessage + 1, SCRIPT_LOG_SHORT_PREFIX);
            strncat(sLogMessage, message + 1, sizeof(sLogMessage) - sizeof(SCRIPT_LOG_SHORT_PREFIX));
        }
        else
        {
            strcpy(sLogMessage, SCRIPT_LOG_FULL_PREFIX);
            strncat(sLogMessage, message, sizeof(sLogMessage) - sizeof(SCRIPT_LOG_FULL_PREFIX));
        }

        sLogMessage[sizeof(sLogMessage) - 1] = '\0';	// strncat fail safe
        BEHAVIAC_LOGINFO(sLogMessage);
    }

#endif
}

void CScriptSystem::SetTag(lua_State* L, int tag)
{
    lua_getref(L, tag);
    lua_setmetatable(L, -2);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::RegisterTagHandlers()
{
    m_nGCTag = lua_newtag(m_pLS);
    lua_pushlightuserdata(m_pLS, NULL);
    lua_pushcclosure(m_pLS, GCTagHandler, 1);
    lua_settagmethod(m_pLS, m_nGCTag, "gc");
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
CFunctionHandler* CScriptSystem::GetFunctionHandler()
{
    return &m_feFuntionHandler;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
IScriptObject* CScriptSystem::CreateEmptyObject()
{
    SCRIPT_STACK_CHECK(m_pLS);
    CScriptObject* pObj = CreateScriptObject();

    if (!pObj->CreateEmpty())
    {
        pObj->Release();
        return NULL;
    };

    return pObj;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
IScriptObject* CScriptSystem::CreateObject()
{
    SCRIPT_STACK_CHECK(m_pLS);
    CScriptObject* pObj = CreateScriptObject();

    if (!pObj->Create())
    {
        pObj->Release();
        return NULL;
    };

    return pObj;
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
IScriptObject* CScriptSystem::CreateGlobalObject(const char* sName)
{
    SCRIPT_STACK_CHECK(m_pLS);
    CScriptObject* pObj = CreateScriptObject();

    if (!pObj->CreateGlobal(sName))
    {
        pObj->Release();
        return NULL;
    };

    return pObj;
}

void CScriptSystem::SetCurrentDeep()
{
    m_CurrentDeep = lua_gettop(m_pLS);
}

void CScriptSystem::CheckStackOnBeginCall()
{
    int aLocal = lua_gettop(m_pLS);

    if (m_CurrentDeep == 0)
    {
        BEHAVIAC_ASSERT(m_BeginStackTop == aLocal && "About to invoke a LUA script on a corrupted LUA stack (don't ignore all)");
        // Set new top (even if corrupted)
        m_BeginStackTop = aLocal;
    }

    m_CurrentDeep++;
}

void CScriptSystem::CheckStackOnEndCall()
{
    m_CurrentDeep = (m_CurrentDeep == 0) ? 0 : --m_CurrentDeep;
    int aLocal = lua_gettop(m_pLS);

    if (m_BeginStackTop != aLocal && m_CurrentDeep == 0)
    {
        BEHAVIAC_ASSERT(false && "Last invoked LUA script has corrupted the LUA stack (don't ignore all)");
        // Set new top (even if corrupted)
        m_BeginStackTop = aLocal;
    }
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int CScriptSystem::BeginCall(HSCRIPTFUNCTION hFunc, const bool bRaiseError /* = true */)
{
    ASSERT_MAIN_THREAD();
    // alberto_pushfunc(m_pLS,hFunc);
    // Check for LUA stack corruption
    CheckStackOnBeginCall();

    if (hFunc == 0)
    {
        if (bRaiseError)
        {
            RaiseError(m_pLS, "(BeginCall) failed NULL parameter");
        }

        m_nTempArg = -1;
        m_CurrentDeep--;
        return 0;
    }

    lua_getref(m_pLS, (int)hFunc);

    if (!lua_isfunction(m_pLS, -1))
    {
        if (bRaiseError)
        {
            RaiseError(m_pLS, "Function Ptr:%d not found", (int)hFunc);
        }

        m_nTempArg = -1;
        m_CurrentDeep--;
        lua_pop(m_pLS, 1);
        return 0;
    }

    m_nTempArg = 0;
    return 1;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int CScriptSystem::BeginCall(const char* sTableName, const char* sFuncName, const bool bRaiseError /* = true */)
{
    ASSERT_MAIN_THREAD();
    // Check for LUA stack corruption
    CheckStackOnBeginCall();
    lua_getglobal(m_pLS, sTableName);

    if (!lua_istable(m_pLS, -1))
    {
        if (bRaiseError)
        {
            RaiseError(m_pLS, "(BeginCall)Table %s: not found(check for syntax errors or if the file wasn't loaded)", sTableName);
        }

        m_nTempArg = -1;
        lua_pop(m_pLS, 1);
        m_CurrentDeep--;
        return 0;
    }

    lua_pushstring(m_pLS, sFuncName);
    lua_rawget(m_pLS, - 2);
    lua_remove(m_pLS, - 2); // Remove table global.
    m_nTempArg = 0;

    if (!lua_isfunction(m_pLS, -1))
    {
        if (bRaiseError)
        {
            RaiseError(m_pLS, "Function %s:%s not found(check for syntax errors or if the file wasn't loaded)", sTableName, sFuncName);
        }

        m_nTempArg = -1;
        lua_pop(m_pLS, 1);
        m_CurrentDeep--;
        return 0;
    }

    return 1;
}

int CScriptSystem::BeginCall(const char* sFuncName, const bool bRaiseError /* = true */)
{
    ASSERT_MAIN_THREAD();
    // Check for LUA stack corruption
    CheckStackOnBeginCall();
    lua_getglobal(m_pLS, sFuncName);
    m_nTempArg = 0;
#ifdef _DEBUG

    if (!lua_isfunction(m_pLS, -1))
    {
        if (bRaiseError)
        {
            RaiseError(m_pLS, "Function %s not found(check for syntax errors or if the file wasn't loaded)", sFuncName);
        }

        m_nTempArg = -1;
        lua_pop(m_pLS, 1);
        m_CurrentDeep--;
        return 0;
    }

#endif
    return 1;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
HSCRIPTFUNCTION CScriptSystem::GetFunctionPtr(const char* sFuncName)
{
    HSCRIPTFUNCTION func;
    lua_getglobal(m_pLS, sFuncName);

    if (lua_isnil(m_pLS, -1) || (!lua_isfunction(m_pLS, -1)))
    {
        lua_pop(m_pLS, 1);
        return	HSCRIPTFUNCTION();
    }

    func = lua_ref(m_pLS, true);
    return func;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
HSCRIPTFUNCTION CScriptSystem::GetFunctionPtr(const char* sTableName, const char* sFuncName)
{
    HSCRIPTFUNCTION func;
    lua_getglobal(m_pLS, sTableName);

    if (!lua_istable(m_pLS, -1))
    {
        RaiseError(m_pLS, "(GetFunctionPtr)Table %s: not found(check for syntax errors or if the file wasn't loaded)", sTableName);
        lua_pop(m_pLS, 1);
        return HSCRIPTFUNCTION();
    }

    lua_pushstring(m_pLS, sFuncName);
    lua_gettable(m_pLS, - 2);
    lua_remove(m_pLS, - 2); // Remove table global.

    if (lua_isnil(m_pLS, -1) || (!lua_isfunction(m_pLS, -1)))
    {
        lua_pop(m_pLS, 1);
        return HSCRIPTFUNCTION();
    }

    func = lua_ref(m_pLS, true);
    return func;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::EndCall()
{
    if (m_nTempArg == -1)
    {
        return;
    }

    ExecuteFunction(m_pLS, m_nTempArg, 0);
    // Check for LUA stack corruption
    CheckStackOnEndCall();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::EndCall(int& nRet)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        BEHAVIAC_ASSERT(lua_isnumber(m_pLS, -1) && "Invalid return value");

        if (lua_isnumber(m_pLS, -1))
        {
            nRet = (int)lua_tonumber(m_pLS, -1);
        }
        else
        {
            nRet = 0;
        }

        lua_pop(m_pLS, 1);
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::EndCall(float& fRet)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        BEHAVIAC_ASSERT(lua_isnumber(m_pLS, -1) && "Invalid return value");

        if (lua_isnumber(m_pLS, -1))
        {
            fRet = lua_tonumber(m_pLS, -1);
        }
        else
        {
            fRet = 0;
        }

        lua_pop(m_pLS, 1);
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::EndCall(const char*& sRet)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        BEHAVIAC_ASSERT(lua_isstring(m_pLS, -1) && "Invalid return value");

        if (lua_isstring(m_pLS, -1))
        {
            sRet = lua_tostring(m_pLS, -1);
        }
        else
        {
            sRet = NULL;
        }

        lua_pop(m_pLS, 1);
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::EndCall(bool& bRet)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        if (lua_isnil(m_pLS, -1))
        {
            bRet = false;
        }
        else if (lua_isboolean(m_pLS, -1))
        {
            bRet = lua_toboolean(m_pLS, -1) ? true : false;
        }
        else
        {
            bRet = true;
        }

        lua_pop(m_pLS, 1);
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void CScriptSystem::EndCall(IScriptObject* pObj)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        if (lua_istable(m_pLS, -1))
        {
            //int nRef = lua_ref(m_pLS, 1);
            pObj->Attach();
        }
        else
        {
            lua_pop(m_pLS, 1);
        }
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void CScriptSystem::EndCall(behaviac::vector<behaviac::string>& array)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (ExecuteFunction(m_pLS, m_nTempArg, 1))
    {
        if (lua_istable(m_pLS, -1))
        {
            int top = lua_gettop(m_pLS);
            lua_pushnil(m_pLS);  // first key

            while (lua_next(m_pLS, top) != 0)
            {
                // `key' is at index -2 and `value' at index -1
                const char* value = lua_tostring(m_pLS, -1);
                array.push_back(value);
                lua_pop(m_pLS, 1); // pop value, leave index.
            }
        }

        lua_pop(m_pLS, 1);
    }

    // Check for LUA stack corruption
    CheckStackOnEndCall();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(int nVal)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    lua_pushnumber(m_pLS, (lua_Number)nVal);
    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(float fVal)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    lua_pushnumber(m_pLS, fVal);
    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(uint64_t value)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    // LUA does not support 64 bit numbers
    // convert the number to behaviac::string
    char str[1024];
	string_snprintf(str, 1024 - 1, "%llu", value);
    str[1023] = 0; // buffer overrun ensure
    lua_pushstring(m_pLS, str);
    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(const char* sVal)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    lua_pushstring(m_pLS, sVal);
    m_nTempArg++;
}

void CScriptSystem::PushFuncParam(CDynamicType* udVal)
{
    SCRIPT_USER_DATA ud = CreateUserData(udVal);

    if (m_nTempArg == -1)
    {
        return;
    }

    lua_getref(m_pLS, ud);
    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(bool bVal)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    if (bVal)
    {
        lua_pushnumber(m_pLS, 1);
    }
    else
    {
        lua_pushnil(m_pLS);
    }

    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(IScriptObject* pVal)
{
    if (m_nTempArg == -1 || !pVal)
    {
        return;
    }

    if (!lua_xgetref(m_pLS, pVal->GetRef()))
    {
        lua_pushnil(m_pLS);
    }

    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::PushFuncParam(void* object, int scriptTag)
{
    if (m_nTempArg == -1)
    {
        return;
    }

    *(void**)lua_newuserdata(m_pLS, 4) = object;
    SetTag(m_pLS, scriptTag);
    m_nTempArg++;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::SetGlobalToNull(const char* sKey)
{
    lua_pushnil(m_pLS);
    lua_setglobal(m_pLS, sKey);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::SetGlobalValue(const char* sKey, int nVal)
{
    lua_pushnumber(m_pLS, (lua_Number)nVal);
    lua_setglobal(m_pLS, sKey);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::SetGlobalValue(const char* sKey, float fVal)
{
    lua_pushnumber(m_pLS, fVal);
    lua_setglobal(m_pLS, sKey);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::SetGlobalValue(const char* sKey, const char* sVal)
{
    lua_pushstring(m_pLS, sVal);
    lua_setglobal(m_pLS, sKey);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::SetGlobalValue(const char* sKey, IScriptObject* pObj)
{
    lua_xgetref(m_pLS, pObj->GetRef());
    lua_setglobal(m_pLS, sKey);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
IScriptObject* CScriptSystem::GetGlobalObject()
{
    CScriptObject* pObj = CreateScriptObject();
    lua_pushvalue(m_pLS, LUA_GLOBALSINDEX);
    pObj->CreateEmpty();
    pObj->Attach();
    return pObj;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
bool CScriptSystem::GetGlobalValue(const char* sKey, int& nVal)
{
    lua_getglobal(m_pLS, sKey);

    if (lua_isnumber(m_pLS, -1))
    {
        nVal = (int)(lua_tonumber(m_pLS, 1));
    }
    else
    {
        lua_pop(m_pLS, 1);
        return false;
    }

    lua_pop(m_pLS, 1);
    return true;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
bool CScriptSystem::GetGlobalValue(const char* sKey, float& fVal)
{
    lua_getglobal(m_pLS, sKey);

    if (lua_isnumber(m_pLS, -1))
    {
        fVal = (float)(lua_tonumber(m_pLS, 1));
    }
    else
    {
        lua_pop(m_pLS, 1);
        return false;
    }

    lua_pop(m_pLS, 1);
    return true;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
bool CScriptSystem::GetGlobalValue(const char* sKey, const char*& sVal)
{
    lua_getglobal(m_pLS, sKey);

    if (lua_isstring(m_pLS, -1))
    {
        sVal = (lua_tostring(m_pLS, -1));

        if (sVal == NULL)
        {
            //this cannot happen if it does call alberto
            lua_pop(m_pLS, 1);
            BEHAVIAC_ASSERT(0,  "<ScriptSystem> CScriptSystem::GetGlobalValue: Key %s cannot be converted to behaviac::string.", sKey);
            return false;
        }
    }
    else
    {
        lua_pop(m_pLS, 1);
        return false;
    }

    lua_pop(m_pLS, 1);
    return true;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
bool CScriptSystem::GetGlobalValue(const char* sKey, IScriptObject* pObj)
{
    lua_getglobal(m_pLS, sKey);

    if (lua_istable(m_pLS, -1))
    {
        pObj->Attach();
    }
    else
    {
        lua_pop(m_pLS, 1);
        return false;
    }

    return true;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CScriptSystem::ForceGarbageCollection()
{
    if (m_pLS)
    {
        lua_gc(m_pLS, LUA_GCCOLLECT, 0);
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int CScriptSystem::GetGCCount()
{
    return lua_getgccount(m_pLS);
}

int CScriptSystem::GCTagHandler(lua_State* L)
{
    USER_DATA_CHUNK* udc = (USER_DATA_CHUNK*)lua_touserdata(L, 1);

    if (udc)
    {
        BEHAVIAC_DELETE(udc)->userData;
        lua_unref(L, udc->nRef);
        udc->userData = (CDynamicType*)0xDEADBEEF;
    }

    return 0;
}

SCRIPT_USER_DATA CScriptSystem::CreateUserData(CDynamicType* userData)
{
    USER_DATA_CHUNK* pUDC = (USER_DATA_CHUNK*)lua_newuserdata(m_pLS, sizeof(USER_DATA_CHUNK));
    pUDC->userData = userData;
    lua_settag(m_pLS, m_nGCTag);
    pUDC->nRef = lua_ref(m_pLS, 0);
    return pUDC->nRef;
}

//////////////////////////////////////////////////////////////////////
CScriptObject* CScriptSystem::CreateScriptObject()
{
    int ref = 0;

    do
    {
        SCRIPT_STACK_GUARD(m_pLS);
        m_nObjCreationNumber++;

        if (m_nObjCreationNumber >= (1 << 24)) // check if integer cannot be in a float
        {
            m_nObjCreationNumber = 1;
        }

        ref = lua_xgetref(m_pLS, m_nObjCreationNumber);
    }
    while (ref);

    return BEHAVIAC_NEW CScriptObject(m_nObjCreationNumber);
}

void CScriptSystem::ReleaseScriptObject(CScriptObject* p)
{
    if (p->m_buckID == -1)
    {
        BEHAVIAC_DELETE(p);
    }
    else
    {
        BEHAVIAC_ASSERT(0);	// No bucket ID is possible when memory manager is disabled !
    }
}

void CScriptSystem::UnbindUserdata()
{
    lua_pushnil(m_pLS);
    lua_settagmethod(m_pLS, m_nGCTag, "gc");
}



void CScriptSystem::ReleaseFunc(HSCRIPTFUNCTION f)
{
    if (f)
    {
        lua_unref(m_pLS, f);
    }
}

//////////////////////////////////////////////////////////////////////////
void CScriptSystem::Update(float currTime, float frameTime, int aiTicks)
{
    // garbage-collect script-variables
    int gcCount = GetScriptSystem()->GetGCCount();

    if ((gcCount - m_lastGarbageCollectCount) > LUA_MAX_GARBAGE_PERIOD)
    {
        ForceGarbageCollection();
        m_lastGarbageCollectCount = GetGCCount();
    }
}

int CScriptSystem::GetFunctionParamName(HSCRIPTFUNCTION hFunc, XmlNodeRef& funcNode)
{
    lua_getref(m_pLS, (int)hFunc);
    StkId func = m_pLS->top - 1;
    Closure* cl;

    if (ttype(func) != LUA_TFUNCTION)
    {
        lua_pop(m_pLS, 1);
        return -1;
    }

    cl = clvalue(func);
    int numParams = cl->l.p->numparams;
    int validParams = numParams;

    for (int j = 0, i = 0 ; j < numParams; j++)
    {
        const char* name = luaF_getlocalname(cl->l.p, j + 1, 0);
        BEHAVIAC_ASSERT(name);

        if (!string_icmp(name, "self"))
        {
            validParams--;
            continue;
        }

        // There is no value for now, so store the index as the value
        funcNode->setAttr(name, i);
        ++i;
    }

    lua_pop(m_pLS, 1); // lua_getref pop
    return validParams;
}
#endif//#if BEHAVIAC_ENABLE_LUA