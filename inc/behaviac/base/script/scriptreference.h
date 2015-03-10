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

#ifndef _ENGINESERVICES_SCRIPTREFERENCE_H_
#define _ENGINESERVICES_SCRIPTREFERENCE_H_

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/smartptr.h"

struct lua_State;

class CScriptReference;
typedef CSmartPtr<CScriptReference> CScriptReferenceRef;

// Just a int wrapper to differentiate when marshalling.
struct ScriptReferenceId
{
    ScriptReferenceId() : m_reference(0) {}
    ScriptReferenceId(int val)
    {
        *this = val;
    }

    int operator =(int val)
    {
        m_reference = val;
        return val;
    }

    operator int() const
    {
        return m_reference;
    }

    int m_reference;
};

class BEHAVIAC_API CScriptReference : public CRefCounted
{
public:
    CScriptReference() : m_reference(0) {}
    CScriptReference(lua_State* lua_state, int index);

    ~CScriptReference();

    ScriptReferenceId operator =(ScriptReferenceId val)
    {
        m_reference = val;
        return	val;
    }
    bool operator ==(const CScriptReference& r)
    {
        return (r.m_reference == m_reference);
    }

    operator int () const
    {
        return m_reference;
    }

protected:
private:
    ScriptReferenceId m_reference;
};

#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTREFERENCE_H_
