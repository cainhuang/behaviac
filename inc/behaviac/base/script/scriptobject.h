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

#if !defined(AFX_SCRIPTOBJECT_H__6EA3E6D6_4FF9_4709_BD62_D5A97C40DB68__INCLUDED_)
#define AFX_SCRIPTOBJECT_H__6EA3E6D6_4FF9_4709_BD62_D5A97C40DB68__INCLUDED_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/script/scriptsystem.h"

struct lua_State;

//CScriptObject
class CScriptObject : public IScriptObject
{
public:

    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptObject)

    CScriptObject(int nCreationNumber);
    virtual ~CScriptObject();
    bool CreateEmpty();
    bool Create();
    bool CreateGlobal(const char* sName);

public:
    int GetRef() const
    {
        return m_nRef;
    };
    void Attach();
    void Attach(IScriptObject* so);
    void Init(int nCreationNumber, int iBuckIndex);
    void Close();

    void Delegate(IScriptObject* pObj);

    void PushBack(int nVal);
    void PushBack(float fVal);
    void PushBack(const char* sVal);
    void PushBack(bool bVal);
    void PushBack(IScriptObject* pObj);

    void SetValue(const char* sKey, int nVal);
    void SetValue(const char* sKey, float fVal);
    void SetValue(const char* sKey, const char* sVal);
    void SetValue(const char* sKey, bool bVal);
    void SetValue(const char* sKey, IScriptObject* pObj);
    void SetValue(const char* sKey, CDynamicType* udValue);
    void SetToNull(const char* sKey);

    bool GetValue(const char* sKey, int& nVal);
    bool GetValue(const char* sKey, float& fVal);
    bool GetValue(const char* sKey, bool& bVal);
    bool GetValue(const char* sKey, const char*& sVal);
    bool GetValue(const char* sKey, IScriptObject* pObj);
    bool GetValue(const char* sKey, HSCRIPTFUNCTION& funcVal);
    bool GetValue(const char* sKey, CDynamicType*& udValue);

    bool BeginSetGetChain();
    bool GetValueChain(const char* sKey, int& nVal);
    bool GetValueChain(const char* sKey, float& fVal);
    bool GetValueChain(const char* sKey, bool& bVal);
    bool GetValueChain(const char* sKey, const char*& sVal);
    bool GetValueChain(const char* sKey, IScriptObject* pObj);
    bool GetValueChain(const char* sKey, HSCRIPTFUNCTION& funcVal);
    void SetValueChain(const char* sKey, int nVal);
    void SetValueChain(const char* sKey, float fVal);
    void SetValueChain(const char* sKey, const char* sVal);
    void SetValueChain(const char* sKey, bool bVal);
    void SetValueChain(const char* sKey, IScriptObject* pObj);
    void SetToNullChain(const char* sKey);
    void EndSetGetChain();

    ScriptVarType GetValueType(const char* sKey);
    ScriptVarType GetAtType(int nIdx);

    void SetAt(int nIdx, int nVal);
    void SetAt(int nIdx, float fVal);
    void SetAt(int nIdx, bool bVal);
    void SetAt(int nIdx, const char* sVal);
    void SetAt(int nIdx, IScriptObject* pObj);
    void SetNullAt(int nIdx);

    bool GetAt(int nIdx, int& nVal);
    bool GetAt(int nIdx, float& fVal);
    bool GetAt(int nIdx, bool& bVal);
    bool GetAt(int nIdx, const char*& sVal);
    bool GetAt(int nIdx, IScriptObject* pObj);

    bool BeginIteration();
    bool MoveNext();
    bool GetCurrent(int& nVal);
    bool GetCurrent(float& fVal);
    bool GetCurrent(bool& bVal);
    bool GetCurrent(const char*& sVal);
    bool GetCurrent(IScriptObject* pObj);
    bool GetCurrentKey(int& nKey);
    bool GetCurrentKey(const char*& sKey);
    ScriptVarType GetCurrentType();
    void EndIteration();

    void Clear();

    int Count();

    bool Clone(IScriptObject* pObj);

    void Dump(IScriptObjectDumpSink* p);

    void SetNativeData(void*);
    void* GetNativeData();

    bool AddFunction(const char* sName, SCRIPT_FUNCTION pThunk, int nFuncID);

    bool AddSetGetHandlers(SCRIPT_FUNCTION pSetThunk, SCRIPT_FUNCTION pGetThunk);

    //used to detach from the C++ code quick objects like vectors or temporary structures

    void Detach();
    void Release();

    CScriptReferenceRef GetScriptReference();
    bool IsReference(CScriptReferenceRef reference);
    const void* GetCurrentPointer();
    bool GetCurrentKeyName(behaviac::string& keyName);
    ScriptVarType GetCurrentKeyType();

private:
    bool CloneTable(int nSource, int nDest);
    static int SetTableTagHandler(lua_State* L);
    static int GetTableTagHandler(lua_State* L);

    static int IndexTagHandler(lua_State* L);

    struct SetGetParams
    {
        SCRIPT_FUNCTION m_pSetThunk;
        SCRIPT_FUNCTION m_pGetThunk;
        HTAG m_hSetGetTag;
    }* m_pSetGetParams;
    lua_State* m_pLS;
    int m_nRef;
    int m_nIterationCounter;
    HTAG m_hDelegationTag;
public:
    int m_buckID;
#ifdef _DEBUG
    int m_nCreationNumber;
#endif
};
#endif//#if BEHAVIAC_ENABLE_LUA


#endif // !defined(AFX_SCRIPTOBJECT_H__6EA3E6D6_4FF9_4709_BD62_D5A97C40DB68__INCLUDED_)
