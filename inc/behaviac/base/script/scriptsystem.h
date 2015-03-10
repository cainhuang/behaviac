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

#ifndef _ENGINESERVICES_SCRIPTSYSTEM_H_
#define _ENGINESERVICES_SCRIPTSYSTEM_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/core/singleton.h"
#include "behaviac/base/string/pathid.h"

#include "behaviac/base/script/scriptreference.h"
#include "behaviac/base/script/scriptserialisation.h"
#include "behaviac/base/script/scriptmarshaltype.h"

#include <list>
#include <set>
#include <map>
#include <string>

#include "behaviac/base/script/lua/lua.h"

struct IScriptObject;
class XmlNodeRef;
class CDynamicType;

typedef int SCRIPT_USER_DATA;

#define CHECK_PARAMETERS(_func, _n, _mod) \
    if (pH->GetParamCount() != _n) \
    {  \
        GetScriptSystem()->RaiseError(GetScriptState(), "%s.%s wrong number of arguments",#_mod,#_func); \
        return 0; \
    }

#define CHECK_PARAMETERS_ATLEAST(_func, _n, _mod) \
    if (pH->GetParamCount() < _n) \
    {  \
        GetScriptSystem()->RaiseError(GetScriptState(), "%s.%s wrong number of arguments",#_mod,#_func); \
        return 0; \
    }

#define REG_FUNC(_class,_func) _class::RegisterFunction(#_func,&_class::_func);
#define FAIL_IF_NULL(_var) if((_var)==NULL){return pH->EndFunctionNull(); }

#define HSCRIPT void*
//	#define HSCRIPTFUNCTION unsigned int
//	typedef	unsigned int HSCRIPTFUNCTION;
struct	HSCRIPTFUNCTION
{
    HSCRIPTFUNCTION() : m_func(0)
    {}
    unsigned int	operator =(unsigned int val)
    {
        m_func = val;
        return	val;
    }
    int		operator =(int val)
    {
        m_func = (unsigned int)val;
        return	val;
    }
    operator	int	()	const
    {
        return	m_func;
    }
    unsigned	int		m_func;
};

#define THIS_PTR void*
#define HTAG int


struct USER_DATA_CHUNK
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(USER_DATA_CHUNK)
    int                 nRef;
    CDynamicType*       userData;
};

typedef int(*SCRIPT_FUNCTION)(HSCRIPT hScript);


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

typedef behaviac::map<int, int> UserDataMap;
typedef UserDataMap::iterator UserDataMapItor;

class CScriptObject;

template <bool Guard>
struct ScriptStackGuard
{
    ScriptStackGuard(lua_State* L): L(L)
    {
        top = lua_gettop(L);
    }
    ~ScriptStackGuard()
    {
        if (top != lua_gettop(L))
        {
            if (!Guard)
            {
                BEHAVIAC_ASSERT(0, "Lua stack is unbalanced! This error must be fixed!");
            }

            lua_settop(L, top);
        }
    }
private:
    lua_State* L;
    int top;
};

#define SCRIPT_STACK_GUARD(L) ScriptStackGuard<true>  __stack_guard(L);
#define SCRIPT_STACK_CHECK(L) ScriptStackGuard<false> __stack_check(L);


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
#include "behaviac/base/script/functionhandler.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
class BEHAVIAC_API CScriptSystem : public CDynamicType, public TSingleton<CScriptSystem>
{
    CScriptSystem();
    ~CScriptSystem();
    BEHAVIAC_DELCARE_SINGLETON(CScriptSystem);
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptSystem);
    BEHAVIAC_DECLARE_DYNAMIC_TYPE(CScriptSystem, CDynamicType);
public:
    SCRIPTMARSHAL_DECLARE_TYPE(CScriptSystem);

public:
    static void* LuaAlloc(void* ud, void* ptr, size_t osize, size_t nsize);
    void Init();
    void Shutdown();
    void Reset();

    lua_State* GetLuaState()
    {
        return m_pLS;
    }
private:
    lua_State* m_pLS;
    int m_environmentTable;

public:
    void RaiseError(lua_State* L, const char* sErr, ...);
    void HandleErrorCode(lua_State* L, int errorCode);

    void PushErrorHandler(lua_State* L);
private:
    static int ErrorHandler(lua_State* L);
    int m_errorHandler;

public:
    bool ExecuteFile(const char* sFileName, bool forceReload);
    bool ExecuteFunction(lua_State* L, int nargs, int nresults);
    bool ExecuteBuffer(const char* sBuffer, int nSize, const char* name = NULL, bool useEnv = false);
    bool ExecuteString(const char* sBuffer, bool useEnv = false);

    void UnloadScript(const char* sFileName);
    void UnloadScripts();
    bool ReloadScripts();
    bool ReloadScript(const char* sFileName);

    // Script API (System).
public:
    void Trace(const char* message);
    void Log(const char* message);
    void Warning(const char* message);

    // Compatibility with previous script serialisation system.
public:
    void SetTag(lua_State* L, int tag);

    // BELOW THIS LINE IS OLD STUFF THAT SHOULD EVENTUALLY BE REMOVED.
public:
    void ReleaseScriptObject(CScriptObject* p);

    // Imported from CScriptSink
    void Update(float currTime, float frameTime, int aiTicks);

public:
    CFunctionHandler* GetFunctionHandler();
    IScriptObject* GetGlobalObject();

    IScriptObject* CreateEmptyObject();
    IScriptObject* CreateObject();
    IScriptObject* CreateGlobalObject(const char* sName);

    // use this with precaution
    void SetCurrentDeep();

    ///
    int BeginCall(HSCRIPTFUNCTION hFunc, const bool bRaiseError = true);
    int BeginCall(const char* sFuncName, const bool bRaiseError = true);
    int BeginCall(const char* sTableName, const char* sFuncName, const bool bRaiseError = true);
    void EndCall();
    void EndCall(int& nRet);
    void EndCall(float& fRet);
    void EndCall(const char*& sRet);
    void EndCall(bool& bRet);
    void EndCall(IScriptObject* pScriptObject);
    void EndCall(behaviac::vector<behaviac::string>& array);

    HSCRIPTFUNCTION GetFunctionPtr(const char* sFuncName);
    HSCRIPTFUNCTION GetFunctionPtr(const char* sTableName, const char* sFuncName);

    void PushFuncParam(int nVal);
    void PushFuncParam(float fVal);
    void PushFuncParam(uint64_t value);
    void PushFuncParam(const char* sVal);
    void PushFuncParam(bool bVal);
    void PushFuncParam(IScriptObject* pVal);
    void PushFuncParam(CDynamicType* ud);

    // would rather declare this one as PushFuncParam(CTagObject*),
    // but I need a template since it's also used with DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL objects
    template <class ObjectType> void PushFuncParamTagObject(ObjectType* object)
    {
        PushFuncParam(object, object->GetScriptTag());
    }

    void PushFuncParam(void*, int scriptTag);

    void SetGlobalValue(const char* sKey, int nVal);
    void SetGlobalValue(const char* sKey, float fVal);
    void SetGlobalValue(const char* sKey, const char* sVal);
    void SetGlobalValue(const char* sKey, IScriptObject* pObj);
    void SetGlobalToNull(const char* sKey);

    bool GetGlobalValue(const char* sKey, int& nVal);
    bool GetGlobalValue(const char* sKey, float& fVal);
    bool GetGlobalValue(const char* sKey, const char*& sVal);
    bool GetGlobalValue(const char* sKey, IScriptObject* pObj);

    SCRIPT_USER_DATA CreateUserData(CDynamicType* userData);

    void ForceGarbageCollection();
    int GetGCCount();
    void ReleaseFunc(HSCRIPTFUNCTION f);

    void UnbindUserdata();


    int GetFunctionParamName(HSCRIPTFUNCTION func, XmlNodeRef& funcNode);
private:
    CScriptObject* CreateScriptObject();

    void RegisterTagHandlers();

    bool _ExecuteFile(const char* sFileName);

private:
    // LUA stack corruption detection
    void CheckStackOnBeginCall();
    void CheckStackOnEndCall();
    int  m_CurrentDeep;
    int  m_BeginStackTop;

    int m_nTempArg;
    static unsigned long m_myThreadId;

    static int GCTagHandler(lua_State* L);
    int m_nGCTag;

    CFunctionHandler m_feFuntionHandler; // NEVER INITIALIZED?

    typedef behaviac::list<CPathID> ScriptFileList;
    typedef ScriptFileList::iterator ScriptFileListItor;
    ScriptFileList m_dqLoadedFiles;

    ScriptFileListItor findFile(const CPathID& path);
private:

    //debug variable
    int m_nObjCreationNumber;

private:
    int m_lastGarbageCollectCount;
};

BEHAVIAC_API CScriptSystem* GetScriptSystem();
BEHAVIAC_API lua_State* GetScriptState();

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

struct IScriptObjectDumpSink
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(IScriptObjectDumpSink)
    virtual ~IScriptObjectDumpSink() {}
    virtual void OnElementFound(const char* sName, ScriptVarType type) = 0;
    virtual void OnElementFound(int nIdx, ScriptVarType type) = 0;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
struct IScriptObject
{
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(IScriptObject)

    virtual ~IScriptObject() {}

    //! internal use
    virtual int GetRef() const = 0;
    //! internal use
    virtual void Attach() = 0;
    virtual void Attach(IScriptObject* so) = 0;

    virtual void Delegate(IScriptObject* pObj) = 0;
    virtual void PushBack(int nVal) = 0;
    virtual void PushBack(float fVal) = 0;
    virtual void PushBack(const char* sVal) = 0;
    virtual void PushBack(bool bVal) = 0;
    virtual void PushBack(IScriptObject* pObj) = 0;

    /*! Set the value of a memeber varible
    @param sKey variable name
    @param val variable value
    */
    //@{
    virtual void SetValue(const char* sKey, int nVal) = 0;
    virtual void SetValue(const char* sKey, float fVal) = 0;
    virtual void SetValue(const char* sKey, const char* sVal) = 0;
    virtual void SetValue(const char* sKey, bool bVal) = 0;
    virtual void SetValue(const char* sKey, IScriptObject* pObj) = 0;
    virtual void SetValue(const char* sKey, CDynamicType* udValue) = 0;
    //@}
    /*! Set the value of a member variable to nil
    @param sKey variable name
    */
    virtual void SetToNull(const char* sKey) = 0;

    /*! Get the value of a memeber varible
    @param sKey variable name
    @param val reference to the C++ variable that will store the value
    @return false if failed true if succeded
    */
    //@{
    template	<class T>
    bool GetValueGeneric(const char* sKey, T& nVal)
    {
        int	val;

        if	(!GetValue(sKey, val))
        {
            return	false;
        }

        nVal = (T)val;
        return	true;
    }

    virtual bool GetValue(const char* sKey, int& nVal) = 0;
    virtual bool GetValue(const char* sKey, float& fVal) = 0;
    virtual bool GetValue(const char* sKey, bool& bVal) = 0;
    virtual bool GetValue(const char* sKey, const char*& sVal) = 0;
    virtual bool GetValue(const char* sKey, IScriptObject* pObj) = 0;
    virtual bool GetValue(const char* sKey, HSCRIPTFUNCTION& funcVal) = 0;
    virtual bool GetValue(const char* sKey, CDynamicType*& udValue) = 0;
    //@}

    /*! Get the value of a memeber varible
    @param sKey variable name
    @param val reference to the C++ variable that will store the value
    @return false if failed true if succeded
    */
    //@{
    virtual bool BeginSetGetChain() = 0;
    virtual bool GetValueChain(const char* sKey, int& nVal) = 0;
    virtual bool GetValueChain(const char* sKey, float& fVal) = 0;
    virtual bool GetValueChain(const char* sKey, bool& bVal) = 0;
    virtual bool GetValueChain(const char* sKey, const char*& sVal) = 0;
    virtual bool GetValueChain(const char* sKey, IScriptObject* pObj) = 0;
    virtual bool GetValueChain(const char* sKey, HSCRIPTFUNCTION& funcVal) = 0;
    virtual void SetValueChain(const char* sKey, int nVal) = 0;
    virtual void SetValueChain(const char* sKey, float fVal) = 0;
    virtual void SetValueChain(const char* sKey, bool bVal) = 0;
    virtual void SetValueChain(const char* sKey, const char* sVal) = 0;
    virtual void SetValueChain(const char* sKey, IScriptObject* pObj) = 0;
    virtual void SetToNullChain(const char* sKey) = 0;
    virtual void EndSetGetChain() = 0;
    //@}

    /*!Get the vaue type of a table member
    @param sKey variable name
    @return the value type (svtNull if doesn't exist)
    */
    virtual ScriptVarType GetValueType(const char* sKey) = 0;
    virtual ScriptVarType GetAtType(int nIdx) = 0;

    /*! Set the value of a memeber varible at the specified index
    this mean that you will use the object as vector into the script
    @param nIdx index of the variable
    @param val variable value
    */
    //@{
    virtual void SetAt(int nIdx, int nVal) = 0;
    virtual void SetAt(int nIdx, float fVal) = 0;
    virtual void SetAt(int nIdx, bool bVal) = 0;
    virtual void SetAt(int nIdx, const char* sVal) = 0;
    virtual void SetAt(int nIdx, IScriptObject* pObj) = 0;
    //@}

    /*! Set the value of a member variable to nil at the specified index
    @param nIdx index of the variable
    */
    virtual void SetNullAt(int nIdx) = 0;

    /*! Get the value of a memeber varible at the specified index
    @param nIdx index of the variable
    @param val reference to the C++ variable that will store the value
    @return false if failed true if succeded
    */
    //@{
    virtual bool GetAt(int nIdx, int& nVal) = 0;
    virtual bool GetAt(int nIdx, float& fVal) = 0;
    virtual bool GetAt(int nIdx, bool& bVal) = 0;
    virtual bool GetAt(int nIdx, const char*& sVal) = 0;
    virtual bool GetAt(int nIdx, IScriptObject* pObj) = 0;
    //@}

    virtual bool BeginIteration() = 0;
    virtual bool MoveNext() = 0;
    virtual bool GetCurrent(int& nVal) = 0;
    virtual bool GetCurrent(float& fVal) = 0;
    virtual bool GetCurrent(bool& bVal) = 0;
    virtual bool GetCurrent(const char*& sVal) = 0;
    virtual bool GetCurrent(IScriptObject* pObj) = 0;
    virtual const void* GetCurrentPointer() = 0;
    virtual bool GetCurrentKey(const char*& sVal) = 0;
    virtual bool GetCurrentKey(int& nKey) = 0;
    virtual ScriptVarType GetCurrentType() = 0;
    virtual void EndIteration() = 0;

    virtual void SetNativeData(void*) = 0;
    virtual void* GetNativeData() = 0;

    virtual void Clear() = 0;
    //! get the count of elements into the object
    virtual int Count() = 0 ;

    /*
    */
    virtual bool Clone(IScriptObject* pObj) = 0;
    /*under development*/
    virtual void Dump(IScriptObjectDumpSink* p) = 0;
    /*!	add afunction to the object
    @param name of the function
    @param C++ function pointer(declared as SCRIPT_FUNCTION)
    @param nFuncID id of the funtion that will be passed beck by the engine
    @return false if failed true if succeded
    */
    virtual bool AddFunction(const char* sName, SCRIPT_FUNCTION pThunk, int nFuncID) = 0;
    /*!	register the host object as parent
    @param pSink pointer to an object that implement IScriptObjectSink

    NOTE: if the parent is registered the script object will notify when is deleted
    */

    virtual bool AddSetGetHandlers(SCRIPT_FUNCTION pSetThunk, SCRIPT_FUNCTION pGetThunk) = 0;
    /*! detach the IScriptObject from the "real" script object */
    virtual void Detach() = 0;
    /*! delete the IScriptObject */
    virtual void Release() = 0;

    virtual CScriptReferenceRef GetScriptReference() = 0;
    virtual bool IsReference(CScriptReferenceRef reference) = 0;
    virtual bool GetCurrentKeyName(behaviac::string& keyName) = 0;
    virtual ScriptVarType GetCurrentKeyType() = 0;
};

/////////////////////////////////////////////////////////////////////////////
//Utility classes
/////////////////////////////////////////////////////////////////////////////

class _SmartScriptObject
{
private:
    //we dont want to use these functions :: too heavy because of the CreateEmptyObject function
    _SmartScriptObject& operator =(const _SmartScriptObject&)
    {
        return *this;
    }
    _SmartScriptObject& operator =(IScriptObject*)
    {
        return *this;
    }
    _SmartScriptObject(const _SmartScriptObject& src)
    {
    }
    //

public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(_SmartScriptObject)
    _SmartScriptObject(IScriptObject* p)
    {
        m_pSO = GetScriptSystem()->CreateEmptyObject();
        m_pSO->Attach(p);
    }
    _SmartScriptObject(bool bCreateEmpty = false)
    {
        if (!bCreateEmpty)
        {
            m_pSO = GetScriptSystem()->CreateObject();
        }
        else
        {
            m_pSO = GetScriptSystem()->CreateEmptyObject();
        }
    }
    ~_SmartScriptObject()
    {
        if (m_pSO)
        {
            m_pSO->Release();
        }
    }
    IScriptObject* operator ->()
    {
        return m_pSO;
    }
    IScriptObject* operator *()
    {
        return m_pSO;
    }
    operator const IScriptObject* () const
    {
        return m_pSO;
    }
    operator IScriptObject* () const
    {
        return m_pSO;
    }
    operator IScriptObject* ()
    {
        return m_pSO;
    }
    /*	bool Create()
    	{
    		m_pSO=GetScriptSystem()->CreateObject();
    		return m_pSO?true:false;
    	}*/
protected:
    IScriptObject* m_pSO;
};

class _HScriptFunction
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(_HScriptFunction)
    _HScriptFunction()
    {
        m_hFunc = 0;
    };
    _HScriptFunction(HSCRIPTFUNCTION hFunc)
    {
        m_hFunc = 0;
    }
    ~_HScriptFunction()
    {
        if (m_hFunc)
        {
            GetScriptSystem()->ReleaseFunc(m_hFunc);
        }

        m_hFunc = 0;
    }
    void Init(HSCRIPTFUNCTION hFunc)
    {
        if (m_hFunc)
        {
            GetScriptSystem()->ReleaseFunc(m_hFunc);
        }

        m_hFunc = hFunc;
    }
    operator HSCRIPTFUNCTION() const
    {
        return m_hFunc;
    }
    _HScriptFunction& operator =(HSCRIPTFUNCTION f)
    {
        if (m_hFunc)
        {
            GetScriptSystem()->ReleaseFunc(m_hFunc);
        }

        m_hFunc = f;
        return *this;
    }
    _HScriptFunction& operator =(int val)
    {
        if (m_hFunc)
        {
            GetScriptSystem()->ReleaseFunc(m_hFunc);
        }

        m_hFunc = val;
        return *this;
    }
    operator	bool	()	const
    {
        return	m_hFunc != 0;
    }
private:
    HSCRIPTFUNCTION m_hFunc;
};
#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTSYSTEM_H_
