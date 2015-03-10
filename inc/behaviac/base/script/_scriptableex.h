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

#ifndef _ENGINESERVICES_SCRIPTABLEEX_H_
#define _ENGINESERVICES_SCRIPTABLEEX_H_

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA
#include "scriptsystem.h"
#include <vector>

template<class T>
class _ScriptableEx
{
public:
    _ScriptableEx()
    {
        //m_nFuncNum=0;
        m_pScriptThis = NULL;
        m_nBase = NULL;
    }
    virtual ~_ScriptableEx()
    {
        if (m_pScriptThis)
        {
            m_pScriptThis->SetNativeData(NULL);
            m_pScriptThis->AddSetGetHandlers(NULL, NULL);
            m_pScriptThis->Release();
        }
    }

    typedef int(T::*MemberFunc)(class CFunctionHandler* pH);

    typedef behaviac::vector<MemberFunc> FunctionsVec;
    typedef typename FunctionsVec::iterator FunctionsVecItor;

    _ScriptableEx<T>*	GetScriptable()
    {
        return this;
    }

    unsigned int m_nBase;

    void Init(T* pParent)
    {
        _ScriptableEx<T>::m_pFunctionHandler = GetScriptSystem()->GetFunctionHandler();

        if (!_ScriptableEx<T>::m_pFunctionHandler)
        {
            BEHAVIAC_ASSERT(0, "Scriptable EX:FUNCTION HANDLER NULL");
        }

        m_pScriptThis = GetScriptSystem()->CreateObject();
        m_pScriptThis->SetNativeData(pParent);
        m_pScriptThis->Delegate(_ScriptableEx<T>::m_pTemplateTable);

        if (m_pScriptThis->GetNativeData() != pParent)
        {
            BEHAVIAC_ASSERT(0, "Scriptable EX:Properties map");
        }
    }
    void InitGlobal(const char* sName, T* pParent)
    {
        _ScriptableEx<T>::m_pFunctionHandler = GetScriptSystem()->GetFunctionHandler();

        if (!_ScriptableEx<T>::m_pFunctionHandler)
        {
            BEHAVIAC_ASSERT(0, "Scriptable EX:FUNCTION HANDLER NULL");
        }

        m_pScriptThis = GetScriptSystem()->CreateGlobalObject(sName);
        m_pScriptThis->SetNativeData(pParent);

        if (_ScriptableEx<T>::m_pTemplateTable)
        {
            m_pScriptThis->Clone(_ScriptableEx<T>::m_pTemplateTable);
        }

        if (m_pScriptThis->GetNativeData() != pParent)
        {
            BEHAVIAC_ASSERT(0, "Scriptable EX:Init Global");
        }
    }
    static void InitializeTemplate()
    {
        m_vFuncs.clear();
    }
    static void ReleaseTemplate()
    {
        if (m_pTemplateTable != NULL)
        {
            m_pTemplateTable->Release();
            m_pTemplateTable = NULL;
        }

        m_vFuncs.clear();
    }

    static void RegisterFunction(const char* sName, MemberFunc mfunc)
    {
        if (m_pTemplateTable == NULL)
        {
            m_pTemplateTable = GetScriptSystem()->CreateObject();
        }

        int nIdx = (int)m_vFuncs.size();
        m_vFuncs.push_back(mfunc);
        m_pTemplateTable->AddFunction(sName, _ScriptableEx<T>::FuncThunk, nIdx);
    }

    IScriptObject* GetScriptObject()
    {
        return m_pScriptThis;
    }
    IScriptObject* operator ->()
    {
        return m_pScriptThis;
    }
    /////////////////////////////////////////
protected:
    static int FuncThunk(HSCRIPT h)
    {
        m_pFunctionHandler->__Attach(h);
        T* pThis = (T*)(m_pFunctionHandler->GetThis());

        if (!pThis)
        {
            GetScriptSystem()->RaiseError(GetScriptState(), "Null Self");
            BEHAVIAC_LOGINFO("Null Self\n");
            return 0;
        }

        //int i=m_pFunctionHandler->GetFunctionID();
        return (pThis->*(pThis->GetScriptable()->m_vFuncs[m_pFunctionHandler->GetFunctionID()]))(m_pFunctionHandler);
    }

    //unsigned long m_nFuncNum;
    IScriptObject* m_pScriptThis;

    static FunctionsVec m_vFuncs;
    static IScriptObject* m_pTemplateTable;
    static CFunctionHandler* m_pFunctionHandler;
};
/////////////////////////////////////////////////////////////////////////////
#define _DECLARE_SCRIPTABLEEX(_class) \
    template <> CFunctionHandler* _ScriptableEx<_class>::m_pFunctionHandler=NULL; \
    template <> _ScriptableEx<_class>::FunctionsVec _ScriptableEx<_class>::m_vFuncs = _ScriptableEx<_class>::FunctionsVec(); \
    template <> IScriptObject *_ScriptableEx<_class>::m_pTemplateTable=NULL;
#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTABLEEX_H_
