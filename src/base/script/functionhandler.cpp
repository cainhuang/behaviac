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

// FunctionHandler.cpp: implementation of the CFunctionHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "behaviac/base/script/functionhandler.h"
#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/script/lua/lua.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFunctionHandler::CFunctionHandler()
{
}

CFunctionHandler::~CFunctionHandler()
{
}

void CFunctionHandler::__Attach(HSCRIPT hScript)
{
    m_pLS = (lua_State*)hScript;
}

THIS_PTR CFunctionHandler::GetThis()
{
    if (!lua_istable(m_pLS, 1))
    {
        return NULL;
    }

    return lua_getnativedata(m_pLS, 1);
}

int CFunctionHandler::GetFunctionID()
{
    return static_cast<int>(lua_tonumber(m_pLS, lua_upvalueindex(1)));
}

int CFunctionHandler::GetParamCount()	const
{
    return lua_gettop(m_pLS) - 1; // -2 are "this" and "func ID"
}


bool CFunctionHandler::GetParam(int nIdx, int& n)	const
{
    int nRealIdx = nIdx + 1;
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");

    if (!lua_isnumber(m_pLS, nRealIdx))
    {
        return false;
    }

    n = (int)lua_tonumber(m_pLS, nRealIdx);
    return true;
}

bool CFunctionHandler::GetParam(int nIdx, unsigned int& n)	const
{
    int nRealIdx = nIdx + 1;
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");

    if (!lua_isnumber(m_pLS, nRealIdx))
    {
        return false;
    }

    n = (unsigned int)lua_tonumber(m_pLS, nRealIdx);
    return true;
}

bool CFunctionHandler::GetParam(int nIdx, float& f)	const
{
    int nRealIdx = nIdx + 1;
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");

    if (!lua_isnumber(m_pLS, nRealIdx))
    {
        return false;
    }

    f = (float)lua_tonumber(m_pLS, nRealIdx);
    return true;
}

bool CFunctionHandler::GetParam(int nIdx, const char*& s)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    //if(!lua_isstring(m_pLS,nIdx))return false;
    s = (char*)lua_tostring(m_pLS, nIdx + 1);

    if (s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CFunctionHandler::GetParam(int nIdx, char*& s)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    //if(!lua_isstring(m_pLS,nIdx))return false;
    s = (char*)lua_tostring(m_pLS, nIdx + 1);

    if (s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CFunctionHandler::GetParam(int nIdx, EntityId& entityId)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    const char* entityIdStr = (const char*)lua_tostring(m_pLS, nIdx + 1);
    EntityId::IdType id;
    sscanf(entityIdStr, "%llu", &id);
    entityId = EntityId(id);
    return entityId.IsValid();
}

bool CFunctionHandler::GetParam(int nIdx, bool& b)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    int nRealIdx = nIdx + 1;

    if (lua_isnil(m_pLS, nRealIdx))
    {
        b = false;
    }
    else if (lua_isnumber(m_pLS, nRealIdx))
    {
        int nVal = 0;
        nVal = (int)lua_tonumber(m_pLS, nRealIdx);

        if (nVal)
        {
            b = true;
        }
        else
        {
            b = false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

bool CFunctionHandler::GetParam(int nIdx, IScriptObject* pObj)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    int nRealIdx = nIdx + 1;

    if (!lua_istable(m_pLS, nRealIdx))
    {
        return false;
    }

    lua_pushvalue(m_pLS, nRealIdx);
    pObj->Attach();
    return true;
}

bool CFunctionHandler::GetParam(int nIdx, HSCRIPTFUNCTION& hFunc)	const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    const	int nRealIdx = nIdx + 1;

    if (!lua_isfunction(m_pLS, nRealIdx))
    {
        return false;
    }

    lua_pushvalue(m_pLS, nRealIdx);
    const	int nRef = lua_ref(m_pLS, 0);

    if	(!nRef)
    {
        return	false;
    }

    hFunc = nRef;
    return true;
}

bool CFunctionHandler::GetParam(int nIdx, CDynamicType*& ud) const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    USER_DATA_CHUNK* udc = (USER_DATA_CHUNK*)lua_touserdata(m_pLS, nIdx + 1);

    if (!udc)
    {
        return false;
    }

    ud = udc->userData;
    return true;
}

ScriptVarType CFunctionHandler::GetParamType(int nIdx) const
{
    BEHAVIAC_ASSERT(nIdx <= GetParamCount() && "CFunctionHandler::GetParam - (CODE/ERROR) Index out of range");
    int nRealIdx = nIdx + 1;

    if (lua_isnil(m_pLS, nRealIdx))
    {
        return svtNull;
    }
    else if (lua_iscfunction(m_pLS, nRealIdx) || lua_isfunction(m_pLS, nRealIdx))
    {
        return svtFunction;
    }
    else if (lua_isnumber(m_pLS, nRealIdx))
    {
        return svtNumber;
    }
    else if (lua_isstring(m_pLS, nRealIdx))
    {
        return svtString;
    }
    else if (lua_istable(m_pLS, nRealIdx))
    {
        return svtObject;
    }
    else if (lua_isuserdata(m_pLS, nRealIdx))	// Added by Mrcio
    {
        // was missing the userdata type
        return svtUserData;						//
    }											//

    return svtNull;
}

int CFunctionHandler::EndFunction(int nRetVal)
{
    lua_pushnumber(m_pLS, (lua_Number)nRetVal);
    return 1;
}

int CFunctionHandler::EndFunction(float fRetVal)
{
    lua_pushnumber(m_pLS, fRetVal);
    return 1;
}

int CFunctionHandler::EndFunction(const char* sRetVal)
{
    lua_pushstring(m_pLS, sRetVal);
    return 1;
}

int CFunctionHandler::EndFunction(EntityId entityId)
{
    // LUA does not support 64 bit numbers
    // convert the number to behaviac::string
    char str[1024];
	string_snprintf(str, 1024 - 1, "%llu", entityId.GetUniqueID());
    str[1023] = 0; // buffer overrun ensure
    lua_pushstring(m_pLS, str);
    return 1;
}

int CFunctionHandler::EndFunction(bool bRetVal)
{
    if (bRetVal)
    {
        lua_pushnumber(m_pLS, 1);
    }
    else
    {
        lua_pushnil(m_pLS);
    }

    return 1;
}

int CFunctionHandler::EndFunction(IScriptObject* pObj)
{
    if (!pObj)
    {
        BEHAVIAC_ASSERT(!"CFunctionHandler::EndFunction - Invalid object reference");
        lua_pushnil(m_pLS);
        return 0;
    }

    lua_xgetref(m_pLS, pObj->GetRef());
    return 1;
}

int CFunctionHandler::EndFunction(HSCRIPTFUNCTION hFunc)
{
    lua_getref(m_pLS, (int)hFunc);
    return 1;
}

int CFunctionHandler::EndFunction(CDynamicType* udVal)
{
    SCRIPT_USER_DATA ud = CScriptSystem::GetInstance()->CreateUserData(udVal);
    lua_getref(m_pLS, ud);
    return 1;
}

int CFunctionHandler::EndFunctionNull()
{
    lua_pushnil(m_pLS);
    return 1;
}

int CFunctionHandler::EndFunction()
{
    return 0;
}
#endif//#if BEHAVIAC_ENABLE_LUA