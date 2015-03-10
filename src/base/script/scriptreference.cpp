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
#include "behaviac/base/script/scriptreference.h"
#include "behaviac/base/script/lua/lua.h"
#include "behaviac/base/script/scriptsystem.h"

CScriptReference::CScriptReference(lua_State* lua_state, int index)
{
    lua_pushvalue(lua_state, index);
    m_reference = lua_ref(lua_state, true);
    //BEHAVIAC_LOGINFO("Creating a script reference with number %d\n", m_reference);
}

CScriptReference::~CScriptReference()
{
    if (m_reference)
    {
        //BEHAVIAC_LOGINFO("Removing script reference number %d\n", m_reference);
        lua_State* lua_state = GetScriptState();
        lua_unref(lua_state, m_reference);
    }
}
#endif//#if BEHAVIAC_ENABLE_LUA