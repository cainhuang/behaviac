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
#include "behaviac/base/script/scriptserialisation.h"

#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/script/lua/lua.h"

BEHAVIAC_IMPLEMNT_SINGLETON(CScriptObjectHierarchicalValidator);

CScriptObjectHierarchicalValidator::CScriptObjectHierarchicalValidator()
{
}

CScriptObjectHierarchicalValidator::~CScriptObjectHierarchicalValidator()
{
}

void CScriptSerialisation::Init()
{
    CScriptObjectHierarchicalValidator::CreateInstance();
}

void CScriptSerialisation::Shutdown()
{
    CScriptObjectHierarchicalValidator::DestroyInstance();
}

int LuaCreateTag(const char* name)
{
    lua_State* L = GetScriptState();
    SCRIPT_STACK_CHECK(L);
    lua_newtable(L);    // metatable
    lua_newtable(L);    // function table
    lua_pushvalue(L, -1);
    lua_setglobal(L, name);
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_REGISTRYINDEX, name);
    // Set function table as index of metatable.
    lua_setfield(L, -2, "__index");
    // Return reference to metatable to be set to userdata (was a tag in the old version).
    lua_pushvalue(L, -1);
    int tag = lua_ref(L, true);
    // Keep tag inside metatable.
    lua_pushlightuserdata(L, (void*)tag);
    lua_rawseti(L, -2, 0);
    lua_pop(L, 1);
    return tag;
}

void LuaRegisterFunction(const char* parent, const char* name, lua_CFunction func)
{
    lua_State* L = GetScriptState();
    SCRIPT_STACK_CHECK(L);

    if (parent == NULL)
    {
        lua_pushcfunction(L, func);
        lua_setglobal(L, name);
    }
    else
    {
        lua_getglobal(L, parent);
        lua_pushstring(L, name);
        lua_pushcfunction(L, func);
        lua_settable(L, -3);
        lua_pop(L, 1);
    }
}

void LuaCopyTag(int tagSrc, int tagDest)
{
    lua_State* L = GetScriptState();
    SCRIPT_STACK_CHECK(L);
    lua_getref(L, tagDest);     // push function table of object on stack
    lua_getfield(L, -1, "__index");
    lua_remove(L, -2);
    lua_getref(L, tagSrc);      // push function table of parent on stack
    lua_getfield(L, -1, "__index");
    lua_remove(L, -2);
    lua_pushnil(L);             // first index
    // for each element in the parent table, copy the function to object table
    int next(0);

    while ((next = lua_next(L, -2)) != 0)
    {
        // only copy function table key/value
        if (lua_isstring(L, -2) && lua_iscfunction(L, -1))
        {
            lua_pushvalue(L, -2); // push key
            lua_pushvalue(L, -2); // push value
            lua_settable(L, -6);  // unstack key and value
        }

        lua_pop(L, 1); // removes value
    }

    lua_pop(L, 2); // remove stacked tables
}

int LuaGetTag(lua_State* L, int idx)
{
    SCRIPT_STACK_CHECK(L);

    if (!lua_isuserdata(L, idx) || !lua_getmetatable(L, idx))
    {
        return 0;
    }

    lua_rawgeti(L, -1, 0);
    BEHAVIAC_ASSERT(lua_islightuserdata(L, -1));
    int tag = (int)lua_touserdata(L, -1);
    lua_pop(L, 2);
    return tag;
}
#endif//#if BEHAVIAC_ENABLE_LUA