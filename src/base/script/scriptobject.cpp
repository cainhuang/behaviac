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
#include "behaviac/base/script/scriptobject.h"
#include "behaviac/base/script/lua/lua.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#ifdef _DEBUG

#define SO_BEGIN_CHECK_STACK \
    int __nStack = lua_stackspace(m_pLS);

#define SO_END_CHECK_STACK \
    {			\
        if (__nStack != lua_stackspace(m_pLS)) \
            BEHAVIAC_ASSERT(0,  "<Script> END_CHECK_STATE Failed." );	\
    }


#else

#define SO_BEGIN_CHECK_STACK
#define SO_END_CHECK_STACK

#endif


#define GET_FUNCTION lua_rawget
#define SET_FUNCTION lua_rawset

#define _GET_THIS() lua_xgetref(m_pLS, m_nRef)

CScriptObject::CScriptObject(int nCreationNumber)
{
    Init(nCreationNumber, -1);
}

CScriptObject::~CScriptObject()
{
    if (m_hDelegationTag != 0)
    {
        lua_deletetag(m_pLS, m_hDelegationTag);
    }

    Close();
}

void CScriptObject::Init(int nCreationNumber, int iBuckIndex)
{
    m_nRef = nCreationNumber;
    m_pLS = NULL;
    m_hDelegationTag = 0;
    m_nIterationCounter = -1;
    m_pSetGetParams = NULL;
    m_buckID = iBuckIndex;
    m_pSetGetParams = NULL;
}

void CScriptObject::Close()
{
    if (m_pSetGetParams)
    {
        BEHAVIAC_FREE(m_pSetGetParams);
    }
}


bool CScriptObject::CreateEmpty()
{
    m_pLS = GetScriptState();
    Detach();
    return true;
}

bool CScriptObject::Create()
{
    m_pLS = GetScriptState();
    SCRIPT_STACK_GUARD(m_pLS);
    Detach();
    lua_newtable(m_pLS);
    Attach();
    return true;
}

bool CScriptObject::CreateGlobal(const char* sName)
{
    m_pLS = GetScriptState();
    SCRIPT_STACK_GUARD(m_pLS);
    Detach();
    lua_newtable(m_pLS);
    Attach();
    _GET_THIS();
    lua_setglobal(m_pLS, sName);
    return true;
}

void CScriptObject::PushBack(int nVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int nLastPos = luaL_getn(m_pLS, -1);
    SetAt(nLastPos + 1, nVal);
}

void CScriptObject::PushBack(float fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int nLastPos = luaL_getn(m_pLS, -1);
    SetAt(nLastPos + 1, fVal);
}

void CScriptObject::PushBack(const char* sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int nLastPos = luaL_getn(m_pLS, -1);
    SetAt(nLastPos + 1, sVal);
}

void CScriptObject::PushBack(bool bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int nLastPos = luaL_getn(m_pLS, -1);
    SetAt(nLastPos + 1, bVal);
}

void CScriptObject::PushBack(IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int nLastPos = luaL_getn(m_pLS, -1);
    SetAt(nLastPos + 1, pObj);
}

bool CScriptObject::BeginSetGetChain()
{
    if (!_GET_THIS())
    {
        return false;
    }

    return true;
}

void CScriptObject::EndSetGetChain()
{
    if (lua_istable(m_pLS, -1))
    {
        lua_pop(m_pLS, 1);
    }
    else
    {
        BEHAVIAC_ASSERT(0);
    }
}

void CScriptObject::SetValueChain(const char* sKey, int nVal)
{
    lua_pushstring(m_pLS, sKey);
    lua_pushnumber(m_pLS, (lua_Number)nVal);
    SET_FUNCTION(m_pLS, - 3);
}

void CScriptObject::SetValue(const char* sKey, int nVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    SetValueChain(sKey, nVal);
}

void CScriptObject::SetValueChain(const char* sKey, float fVal)
{
    lua_pushstring(m_pLS, sKey);
    lua_pushnumber(m_pLS, fVal);
    SET_FUNCTION(m_pLS, - 3);
}

void CScriptObject::SetValue(const char* sKey, float fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    SetValueChain(sKey, fVal);
}

void CScriptObject::SetValueChain(const char* sKey, bool bVal)
{
    lua_pushstring(m_pLS, sKey);

    if (bVal)
    {
        lua_pushnumber(m_pLS, 1);
    }
    else
    {
        lua_pushnil(m_pLS);
    }

    SET_FUNCTION(m_pLS, - 3);
}

void CScriptObject::SetValue(const char* sKey, bool bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    // int nVal=bVal?1:0;
    if (!_GET_THIS())
    {
        return;
    }

    SetValueChain(sKey, bVal);
}

void CScriptObject::SetValueChain(const char* sKey, const char* sVal)
{
    lua_pushstring(m_pLS, sKey);
    lua_pushstring(m_pLS, sVal);
    SET_FUNCTION(m_pLS, - 3);
}

void CScriptObject::SetValue(const char* sKey, const char* sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    SetValueChain(sKey, sVal);
}



void CScriptObject::SetValueChain(const char* sKey, IScriptObject* pObj)
{
    BEHAVIAC_ASSERT(pObj && "CScriptObject::SetValueChain - Invalid object");

    if (pObj)
    {
        lua_pushstring(m_pLS, sKey);
        lua_xgetref(m_pLS, pObj->GetRef());
    }

    SET_FUNCTION(m_pLS, - 3);
}



void CScriptObject::SetValue(const char* sKey, IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    BEHAVIAC_ASSERT(pObj && "CScriptObject::SetValue - Invalid object");

    if (pObj)
    {
        SetValueChain(sKey, pObj);
    }
}



void CScriptObject::SetValue(const char* sKey, CDynamicType* udVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    SCRIPT_USER_DATA ud = CScriptSystem::GetInstance()->CreateUserData(udVal);
    lua_pushstring(m_pLS, sKey);

    if (ud)
    {
        lua_getref(m_pLS, ud);

        if (lua_isuserdata(m_pLS, -1))
        {
            SET_FUNCTION(m_pLS, - 3);
        }
    }
}

void CScriptObject::SetToNullChain(const char* sKey)
{
    lua_pushstring(m_pLS, sKey);
    lua_pushnil(m_pLS);
    SET_FUNCTION(m_pLS, - 3);
}

void CScriptObject::SetToNull(const char* sKey)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    SetToNullChain(sKey);
}

bool CScriptObject::GetValueChain(const char* sKey, int& nVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        nVal = (int)lua_tonumber(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, int& nVal)
{
    SCRIPT_STACK_CHECK(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    res = GetValueChain(sKey, nVal);
    lua_pop(m_pLS, 1);
    return res;
}

bool CScriptObject::GetValueChain(const char* sKey, HSCRIPTFUNCTION& funcVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isfunction(m_pLS, - 1))
    {
        res = true;
        funcVal = lua_ref(m_pLS, true);
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, HSCRIPTFUNCTION& funcVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    res = GetValueChain(sKey, funcVal);
    return res;
}

bool CScriptObject::GetValueChain(const char* sKey, bool& bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    int nVal;
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isnil(m_pLS, - 1))
    {
        res = true;
        bVal = false;
    }
    else if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        nVal = (int)lua_tonumber(m_pLS, - 1);

        if (nVal)
        {
            bVal = true;
        }
        else
        {
            bVal = false;
        }
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, bool& bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        bVal = false;
        return false;
    }

    return GetValueChain(sKey, bVal);
}

bool CScriptObject::GetValueChain(const char* sKey, float& fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        fVal = (float)lua_tonumber(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, float& fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    res = GetValueChain(sKey, fVal);
    return res;
}

bool CScriptObject::GetValueChain(const char* sKey, const char*& sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isstring(m_pLS, - 1))
    {
        res = true;
        sVal = (char*)lua_tostring(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, const char*& sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    res = GetValueChain(sKey, sVal);
    return res;
}

bool CScriptObject::GetValueChain(const char* sKey, IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_istable(m_pLS, - 1))
    {
        res = true;
        lua_pushvalue(m_pLS, - 1);
        pObj->Attach();
    }

    return res;
}

bool CScriptObject::GetValue(const char* sKey, IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    res = GetValueChain(sKey, pObj);
    return res;
}

bool CScriptObject::GetValue(const char* sKey, CDynamicType*& udValue)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return false;
    }

    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isuserdata(m_pLS, -1))
    {
        USER_DATA_CHUNK* udc = (USER_DATA_CHUNK*)lua_touserdata(m_pLS, -1);

        if (!udc)
        {
            return false;
        }

        udValue = udc->userData;
        return true;
    }

    return false;
}

void CScriptObject::SetAt(int nIdx, int nVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_pushnumber(m_pLS, (lua_Number)nVal);
    lua_rawseti(m_pLS, - 2, nIdx);
}

void CScriptObject::SetAt(int nIdx, float fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_pushnumber(m_pLS, fVal);
    lua_rawseti(m_pLS, - 2, nIdx);
}

void CScriptObject::SetAt(int nIdx, bool bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
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

    lua_rawseti(m_pLS, - 2, nIdx);
}

void CScriptObject::SetAt(int nIdx, const char* sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_pushstring(m_pLS, sVal);
    lua_rawseti(m_pLS, - 2, nIdx);
}

void CScriptObject::SetAt(int nIdx, IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_xgetref(m_pLS, pObj != NULL ? pObj->GetRef() : 0);
    lua_rawseti(m_pLS, - 2, nIdx);
}

void CScriptObject::SetNullAt(int nIdx)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_pushnil(m_pLS);
    lua_rawseti(m_pLS, - 2, nIdx);
}

int CScriptObject::Count()
{
    SCRIPT_STACK_GUARD(m_pLS);
    int top = lua_gettop(m_pLS);
    int nCount = 0;

    if (!_GET_THIS())
    {
        return -1;
    }

    int trgTable = top + 1;
    lua_pushnil(m_pLS);  // first key

    while (lua_next(m_pLS, trgTable) != 0)
    {
        // `key' is at index -2 and `value' at index -1
        nCount++;
        lua_pop(m_pLS, 1); // pop value, leave index.
    }

    //lua_settop(m_pLS, top); // Restore stack.
    return nCount;
}

bool CScriptObject::GetAt(int nIdx, int& nVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    if (luaL_getn(m_pLS, - 1) < nIdx)
    {
        return false;
    }

    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        nVal = (int)lua_tonumber(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetAt(int nIdx, float& fVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    if (luaL_getn(m_pLS, - 1) < nIdx)
    {
        return false;
    }

    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        fVal = lua_tonumber(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetAt(int nIdx, bool& bVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;
    int nVal;

    if (!_GET_THIS())
    {
        return false;
    }

    if (luaL_getn(m_pLS, - 1) < nIdx)
    {
        return false;
    }

    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        nVal = (int)lua_tonumber(m_pLS, - 1);

        if (nVal)
        {
            bVal = true;
        }
        else
        {
            bVal = false;
        }
    }

    return res;
}

bool CScriptObject::GetAt(int nIdx, const char*& sVal)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    if (luaL_getn(m_pLS, - 1) < nIdx)
    {
        return false;
    }

    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_isstring(m_pLS, - 1))
    {
        res = true;
        sVal = (char*)lua_tostring(m_pLS, - 1);
    }

    return res;
}

bool CScriptObject::GetAt(int nIdx, IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);
    bool res = false;

    if (!_GET_THIS())
    {
        return false;
    }

    // Remove this section since it prevents script persistence from being loaded back in correctly
    // 	if (luaL_getn(m_pLS, - 1) < nIdx)
    // 	{
    // 		return false;
    // 	}
    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_istable(m_pLS, - 1))
    {
        res = true;
        lua_pushvalue(m_pLS, - 1);
        pObj->Attach();
    }

    return res;
}

/*void CScriptObject::SetThis(THIS_PTR pThis)
{
	//m_pThis = pThis;
}

THIS_PTR CScriptObject::GetThis()
{
	THIS_PTR res = NULL;
	return m_pThis;
}*/

bool CScriptObject::AddFunction(const char* sName, SCRIPT_FUNCTION pThunk, int nFuncID)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return false;
    }

    lua_pushstring(m_pLS, sName);
    lua_pushnumber(m_pLS, (lua_Number)nFuncID);
    //lua_newuserdatabox(m_pLS, m_pThis);
    lua_pushcclosure(m_pLS, (lua_CFunction)pThunk, 1);
    SET_FUNCTION(m_pLS, -3);
    return true;
}

bool CScriptObject::AddSetGetHandlers(SCRIPT_FUNCTION pSetThunk, SCRIPT_FUNCTION pGetThunk)
{
    if ((!m_pSetGetParams) && pSetThunk && pGetThunk && m_hDelegationTag)
    {
        m_pSetGetParams = (CScriptObject::SetGetParams*)BEHAVIAC_MALLOC_WITHTAG(sizeof(CScriptObject::SetGetParams), "CScriptObject::Params");
        //int nTag = lua_newtag(m_pLS);
        lua_pushlightuserdata(m_pLS, this);
        //lua_newuserdatabox(m_pLS, m_pThis);
        lua_pushcclosure(m_pLS, CScriptObject::SetTableTagHandler, 1);
        lua_settagmethod(m_pLS, m_hDelegationTag, "settable");
        /*		lua_newuserdatabox(m_pLS, this);
        		//lua_newuserdatabox(m_pLS, m_pThis);
        		lua_pushcclosure(m_pLS, CScriptObject::GetTableTagHandler, 1);
        		lua_settagmethod(m_pLS, nTag, "gettable");*/

        if (!_GET_THIS())
        {
            lua_pushnil(m_pLS);
            lua_settagmethod(m_pLS, m_hDelegationTag, "settable");
            /*lua_pushnil(m_pLS);
            lua_settagmethod(m_pLS, nTag, "gettable");;*/
            return false;
        }

        lua_settag(m_pLS, m_hDelegationTag);
        lua_pop(m_pLS, 1);
        m_pSetGetParams->m_pSetThunk = pSetThunk;
        m_pSetGetParams->m_pGetThunk = pGetThunk;
        m_pSetGetParams->m_hSetGetTag = m_hDelegationTag;
    }
    else
    {
        if (m_pSetGetParams)
        {
            if (m_pSetGetParams->m_hSetGetTag)
            {
                lua_pushnil(m_pLS);
                lua_settagmethod(m_pLS, m_pSetGetParams->m_hSetGetTag, "settable");
                /*lua_pushnil(m_pLS);
                lua_settagmethod(m_pLS, m_pSetGetParams->m_hSetGetTag, "gettable");;*/
                m_pSetGetParams->m_hSetGetTag = NULL;
            }

            BEHAVIAC_FREE(m_pSetGetParams);
            m_pSetGetParams = NULL;
        }
    }

    return true;
}

int CScriptObject::GetTableTagHandler(lua_State* L)
{
    CScriptObject* pThis = (CScriptObject*)lua_touserdata(L, - 1);
    int nRet;
    BEHAVIAC_ASSERT(pThis->m_pSetGetParams->m_pGetThunk != NULL);
    /*{
    	//lua_pop(L,2);
    	BEHAVIAC_ASSERT(lua_istable(L,1));
    	lua_pop(L,1);
    	lua_rawget(L,1);

    	return 1;
    }*/

    if (((nRet = pThis->m_pSetGetParams->m_pGetThunk((HSCRIPT)L)) == -1))
    {
        //lua_pop(L,2);
        BEHAVIAC_ASSERT(lua_istable(L, 1));
        lua_pop(L, 1);
        lua_rawget(L, 1);
        return 1;
    }
    else
    {
        return nRet;
    }
}

int CScriptObject::SetTableTagHandler(lua_State* L)
{
    CScriptObject* pThis = (CScriptObject*)lua_touserdata(L, - 1);
    int nRet;
    BEHAVIAC_ASSERT(pThis->m_pSetGetParams->m_pGetThunk != NULL);

    /*if(!pThis->m_pSetThunk)
    {
    	BEHAVIAC_ASSERT(lua_istable(L,1));
    	lua_pop(L,1);
    	lua_rawset(L,1);
    	return 0;
    }*/
    if (/*!lua_isfunction(L,-2) && !lua_iscfunction(L,-2) && !lua_isuserdata(L,-2) &&*/ (!((nRet = pThis->m_pSetGetParams->m_pSetThunk((HSCRIPT)L)) == -1)))
    {
        BEHAVIAC_ASSERT(lua_istable(L, 1));
        lua_pop(L, 1);
    }
    else
    {
        BEHAVIAC_ASSERT(lua_istable(L, 1));
        lua_pop(L, 1);
        lua_rawset(L, 1);
        return 0;
    }

    return 0;
}

bool CScriptObject::Clone(IScriptObject* pObj)
{
    SCRIPT_STACK_GUARD(m_pLS);
    int top = lua_gettop(m_pLS);

    if (!lua_xgetref(m_pLS, pObj->GetRef()))
    {
        return false;
    }

    if (!_GET_THIS())
    {
        return false;
    }

    int srcTable = top + 1;
    int trgTable = top + 2;
    lua_pushnil(m_pLS);  // first key

    while (lua_next(m_pLS, srcTable) != 0)
    {
        // `key' is at index -2 and `value' at index -1
        lua_pushvalue(m_pLS, - 2); // Push again index.
        lua_pushvalue(m_pLS, - 2); // Push value.
        SET_FUNCTION(m_pLS, trgTable);
        lua_pop(m_pLS, 1); // pop value, leave index.
    }

    //lua_settop(m_pLS, top); // Restore stack.
    return true;
}



void CScriptObject::Dump(IScriptObjectDumpSink* p)
{
    if (!p)
    {
        return;
    }

    SCRIPT_STACK_GUARD(m_pLS);
    int top = lua_gettop(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int trgTable = top + 1;
    lua_pushnil(m_pLS);  // first key
    int reftop = lua_gettop(m_pLS);

    while (lua_next(m_pLS, trgTable) != 0)
    {
        // `key' is at index -2 and `value' at index -1
        if (lua_isnumber(m_pLS, - 2))
        {
            int nIdx = (int)lua_tonumber(m_pLS, - 2); // again index

            if (lua_isnil(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtNull);
            }
            else if (lua_isfunction(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtFunction);
            }
            else if (lua_isnumber(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtNumber);
            }
            else if (lua_isstring(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtString);
            }
            else if (lua_istable(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtObject);
            }
            else if (lua_isuserdata(m_pLS, - 1))
            {
                p->OnElementFound(nIdx, svtUserData);
            }
        }
        else
        {
            const char* sName = lua_tostring(m_pLS, - 2); // again index

            if (lua_isnil(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtNull);
            }
            else if (lua_isfunction(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtFunction);
            }
            else if (lua_isnumber(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtNumber);
            }
            else if (lua_isstring(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtString);
            }
            else if (lua_istable(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtObject);
            }
            else if (lua_isuserdata(m_pLS, - 1))
            {
                p->OnElementFound(sName, svtUserData);
            }
        }

        lua_settop(m_pLS, reftop); // pop value, leave index.
    }

    //lua_settop(m_pLS, top); // Restore stack.
    //SO_END_CHECK_STACK
}

ScriptVarType CScriptObject::GetValueType(const char* sKey)
{
    SCRIPT_STACK_GUARD(m_pLS);
    ScriptVarType svtRetVal = svtNull;

    if (!_GET_THIS())
    {
        return svtNull;
    }

    lua_pushstring(m_pLS, sKey);
    GET_FUNCTION(m_pLS, - 2);

    if (lua_isnil(m_pLS, - 1))
    {
        svtRetVal = svtNull;
    }
    else if (lua_isfunction(m_pLS, - 1))
    {
        svtRetVal = svtFunction;
    }
    else if (lua_isnumber(m_pLS, - 1))
    {
        svtRetVal = svtNumber;
    }
    else if (lua_isstring(m_pLS, - 1))
    {
        svtRetVal = svtString;
    }
    else if (lua_istable(m_pLS, - 1))
    {
        svtRetVal = svtObject;
    }
    else if (lua_isuserdata(m_pLS, - 1))
    {
        svtRetVal = svtUserData;
    }

    //lua_pop(m_pLS, 2);
    //SO_END_CHECK_STACK
    return svtRetVal;
}

ScriptVarType CScriptObject::GetAtType(int nIdx)
{
    SCRIPT_STACK_GUARD(m_pLS);
    ScriptVarType svtRetVal = svtNull;

    if (!_GET_THIS())
    {
        return svtNull;
    }

    if (luaL_getn(m_pLS, - 1) < nIdx)
    {
        //lua_pop(m_pLS, 1);
        return svtNull;
    }

    lua_rawgeti(m_pLS, - 1, nIdx);

    if (lua_isnil(m_pLS, - 1))
    {
        svtRetVal = svtNull;
    }
    else if (lua_isfunction(m_pLS, - 1))
    {
        svtRetVal = svtFunction;
    }
    else if (lua_isnumber(m_pLS, - 1))
    {
        svtRetVal = svtNumber;
    }
    else if (lua_isstring(m_pLS, - 1))
    {
        svtRetVal = svtString;
    }
    else if (lua_istable(m_pLS, - 1))
    {
        svtRetVal = svtObject;
    }

    //lua_pop(m_pLS, 2);
    //SO_END_CHECK_STACK
    return svtRetVal;
}

void CScriptObject::Detach()
{
    lua_xunref(m_pLS, m_nRef);
}

void CScriptObject::Release()
{
    AddSetGetHandlers(NULL, NULL);
    Detach();
    GetScriptSystem()->ReleaseScriptObject(this);
}

bool CScriptObject::BeginIteration()
{
    if (m_nIterationCounter != -1)
    {
        return false;
    }

    m_nIterationCounter = lua_gettop(m_pLS);

    if (!_GET_THIS())
    {
        return false;
    }

    lua_pushnil(m_pLS);
    return true;
}

bool CScriptObject::MoveNext()
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    //leave only the index into the stack
    while ((lua_gettop(m_pLS) - (m_nIterationCounter + 1)) > 1)
    {
        lua_pop(m_pLS, 1);
    }

    return (lua_next(m_pLS, m_nIterationCounter + 1) != 0);
}

bool CScriptObject::GetCurrent(int& nVal)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isnumber(m_pLS, -1))
    {
        nVal = (int)lua_tonumber(m_pLS, -1);
        return true;
    }

    return false;
}

bool CScriptObject::GetCurrent(float& fVal)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isnumber(m_pLS, -1))
    {
        fVal = lua_tonumber(m_pLS, -1);
        return true;
    }

    return false;
}

bool CScriptObject::GetCurrent(bool& bVal)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    bool res = false;

    if (lua_isnil(m_pLS, - 1))
    {
        res = true;
        bVal = false;
    }
    else if (lua_isnumber(m_pLS, - 1))
    {
        res = true;
        int nVal = (int)lua_tonumber(m_pLS, - 1);

        if (nVal)
        {
            bVal = true;
        }
        else
        {
            bVal = false;
        }
    }

    return res;
}

bool CScriptObject::GetCurrent(const char*& sVal)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isstring(m_pLS, - 1))
    {
        sVal = (char*)lua_tostring(m_pLS, - 1);
        return true;
    }

    return false;
}

bool CScriptObject::GetCurrent(IScriptObject* pObj)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    bool res = false;

    if (lua_istable(m_pLS, -1))
    {
        res = true;
        lua_pushvalue(m_pLS, -1);
        pObj->Attach();
    }

    return res;
}

bool CScriptObject::GetCurrentKey(const char*& sKey)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isstring(m_pLS, - 2))
    {
        sKey = (char*)lua_tostring(m_pLS, - 2);
        return true;
    }

    return false;
}

bool CScriptObject::GetCurrentKey(int& nKey)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isnumber(m_pLS, -2))
    {
        nKey = (int)lua_tonumber(m_pLS, -2);
        return true;
    }

    return false;
}


void CScriptObject::Attach()
{
    Detach();
    lua_xref(m_pLS, m_nRef);
}


void CScriptObject::Attach(IScriptObject* so)
{
    if (!lua_xgetref(m_pLS, so->GetRef()))
    {
        return;
    }

    Attach();
}

void CScriptObject::EndIteration()
{
    if (m_nIterationCounter == -1)
    {
        //Timur[2/20/2003]
        // This is invalid call, fire warning.
        BEHAVIAC_ASSERT(0);
        return;
    }

    lua_settop(m_pLS, m_nIterationCounter);
    m_nIterationCounter = -1;
}

ScriptVarType CScriptObject::GetCurrentType()
{
    int tag = lua_type(m_pLS, -1);

    switch (tag)
    {
        case LUA_TFUNCTION :
            return svtFunction;

        case LUA_TSTRING :
            return svtString;

        case LUA_TNUMBER :
            return svtNumber;

        case LUA_TTABLE :
            return svtObject;

        default :
            return svtNull;
    }
}

void CScriptObject::Clear()
{
    SCRIPT_STACK_GUARD(m_pLS);
    int top = lua_gettop(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    int trgTable = top + 1;
    lua_pushnil(m_pLS);  // first key

    while (lua_next(m_pLS, trgTable) != 0)
    {
        lua_pop(m_pLS, 1); // pop value, leave index.
        lua_pushvalue(m_pLS, -1); // Push again index.
        lua_pushnil(m_pLS);
        lua_rawset(m_pLS, trgTable);
    }

    //	lua_settop(m_pLS, top); // Restore stack.
    //	SO_END_CHECK_STACK
}

void CScriptObject::SetNativeData(void* nd)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return;
    }

    lua_setnativedata(m_pLS, -1, nd);
}

void* CScriptObject::GetNativeData()
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return NULL;
    }

    return lua_getnativedata(m_pLS, -1);
}

int CScriptObject::IndexTagHandler(lua_State* L)
{
    CScriptObject* p = (CScriptObject*)lua_touserdata(L, -2);
    int nRet = 0;

    if (p && p->m_pSetGetParams)
    {
        if ((nRet = p->m_pSetGetParams->m_pGetThunk((HSCRIPT)L)) != -1)
        {
            return nRet;
        }

        //lua_pop(L,1);
    }

    if (lua_istable(L, 4))
    {
        if (!lua_getnativedata(L, 1))
        {
            return 0;
        }

        lua_pushvalue(L, 2);
        lua_rawget(L, -2);
        lua_remove(L, -2);
        return 1;
    }

    return 0;
}

void CScriptObject::Delegate(IScriptObject* pObj)
{
    if (!pObj)
    {
        return;
    }

    m_hDelegationTag = lua_newtag(m_pLS);
    lua_pushlightuserdata(m_pLS, this);

    if (!lua_xgetref(m_pLS, pObj->GetRef()))
    {
        return;
    }

    lua_pushcclosure(m_pLS, CScriptObject::IndexTagHandler, 2);
    lua_settagmethod(m_pLS, m_hDelegationTag, "index");

    if (!_GET_THIS())
    {
        lua_pushnil(m_pLS);
        lua_settagmethod(m_pLS, m_hDelegationTag, "index");
        return ;
    }

    lua_settag(m_pLS, m_hDelegationTag);
    lua_pop(m_pLS, 1);
}

CScriptReferenceRef CScriptObject::GetScriptReference()
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return NULL;
    }

    return BEHAVIAC_NEW CScriptReference(m_pLS, -1);
}

bool CScriptObject::IsReference(CScriptReferenceRef reference)
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return false;
    }

    const void* thisPointer = lua_topointer(m_pLS, -1);
    lua_getregistry(m_pLS);
    lua_rawgeti(m_pLS, -1, *reference);
    const void* referencePointer = lua_topointer(m_pLS, -1);
    lua_pop(m_pLS, 2);
    return thisPointer == referencePointer;
}

const void* CScriptObject::GetCurrentPointer()
{
    SCRIPT_STACK_GUARD(m_pLS);

    if (!_GET_THIS())
    {
        return false;
    }

    return lua_topointer(m_pLS, -1);
}

bool CScriptObject::GetCurrentKeyName(behaviac::string& keyName)
{
    if (m_nIterationCounter == -1)
    {
        return false;
    }

    if (lua_isstring(m_pLS, - 2))
    {
        lua_pushvalue(m_pLS, -2); // Copy current key to avoid modify it in lua_tostring
        keyName = (char*)lua_tostring(m_pLS, -1);
        lua_pop(m_pLS, 1);
        return true;
    }

    return false;
}

ScriptVarType CScriptObject::GetCurrentKeyType()
{
    int tag = lua_type(m_pLS, -2);

    switch (tag)
    {
        case LUA_TUSERDATA :
            return svtUserData;

        case LUA_TNIL :
            return svtNull;

        case LUA_TNUMBER :
            return svtNumber;

        case LUA_TSTRING :
            return svtString;

        case LUA_TTABLE	:
            return svtObject;

        case LUA_TFUNCTION:
            return svtFunction;

        default:
            return svtNull;
    }
}
#endif//#if BEHAVIAC_ENABLE_LUA