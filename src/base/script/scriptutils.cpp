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
#include "behaviac/base/script/scriptutils.h"

#include "behaviac/base/script/lua/lua.h"

// Clones the table at 'idx' to the table at the top of the stack.
void CScriptUtils::CloneTable(lua_State* L, int idx, bool deep)
{
    BEHAVIAC_ASSERT(lua_istable(L, idx));

    if (!lua_istable(L, idx))
    {
        return;
    }

    BEHAVIAC_ASSERT(!deep, "Not implemented");
    lua_pushnil(L);

    if (idx < 0)
    {
        idx--;
    }

    while (lua_next(L, idx) != 0)
    {
        // Key/value is on the stack.
        // Duplicate key/value.
        lua_pushvalue(L, -2);
        lua_pushvalue(L, -2);
        // Set key/value to new table.
        lua_settable(L, -5);
        // Pop original value.
        lua_pop(L, 1);
    }
}
#endif//#if BEHAVIAC_ENABLE_LUA