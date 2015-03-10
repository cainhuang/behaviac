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

#ifndef _BEHAVIAC_BASE_OBJECT_TAGOBJECT_H_
#define _BEHAVIAC_BASE_OBJECT_TAGOBJECT_H_

#include "behaviac/base/base.h"
#include "behaviac/base/serialization/serializablenode.h"
#include "behaviac/base/script/scriptserialisation.h"
#include "behaviac/base/script/scriptmarshaltype.h"
#include "behaviac/base/swapbyte.h"

#include "behaviac/base/serialization/textnode.h"

class CTagObject;
class CTagMethodParams;
class CMethodBase;

#if BEHAVIAC_COMPILER_MSVC
//C4189: 'ms_members' : local variable is initialized but not referenced
#pragma warning (disable : 4189 )
#endif//#if BEHAVIAC_COMPILER_MSVC

template<class Parent> void LuaCopyFunctionTable(int tagDest);

class BEHAVIAC_API CTagTypeDescriptor : public CDynamicType
{
public:
    BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(CTagTypeDescriptor, CDynamicType);

	typedef behaviac::map<const char*, const class CTagTypeDescriptor*> TypesMap_t;

	virtual void GetMembersDescription(TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode) const = 0;
};

class CTagObject;
////////////////////////////////////////////////////////////////////////////////
// CTagObjectDescriptor
//   Do not use by itself! It is only meant as a methods/members container for
//   CTagObject.
////////////////////////////////////////////////////////////////////////////////
class BEHAVIAC_API CTagObjectDescriptor : public CTagTypeDescriptor
{
public:
	BEHAVIAC_DECLARE_DYNAMIC_TYPE(CTagObjectDescriptor, CTagTypeDescriptor);

    typedef behaviac::vector<class CMemberBase*> MembersVector_t;
	typedef behaviac::map<CStringID, class CMemberBase*> MembersMap_t;

	struct MembersContainer
	{
		MembersMap_t		membersMap;
	    MembersVector_t		membersVector;
	};
	
    typedef behaviac::vector<class CMethodBase*> MethodsContainer;

	CTagObjectDescriptor() : m_parent(0), ms_flags(0), ms_isInitialized(false)
	{}

    void Load(CTagObject* parent, const ISerializableNode* node) const;
    void Save(const CTagObject* parent, ISerializableNode* node) const;

    void LoadState(CTagObject* parent, const ISerializableNode* node) const;
    void SaveState(const CTagObject* parent, ISerializableNode* node) const;

	const class CMemberBase* GetMember(const CStringID& propertyId) const;
#if BEHAVIAC_ENABLE_NETWORKD
	void ReplicateProperties(CTagObject* parent);
#endif

    virtual void GetMembersDescription(TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode) const;
    void GetMethodsDescription(TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode) const;

    static void PushBackMember(MembersContainer& inMembers, class CMemberBase* toAddMember);

    CTagObjectDescriptor& Get()
    {
        return *this;
    }

	CTagObjectDescriptor* m_parent;
    MembersContainer ms_members;
    MethodsContainer ms_methods;

	behaviac::wstring	m_displayName;
	behaviac::wstring	m_desc;

	uint32_t	ms_flags;
	bool		ms_isInitialized;
};

////////////////////////////////////////////////////////////////////////////////
// CTagObjectDescriptorBSS
////////////////////////////////////////////////////////////////////////////////
class BEHAVIAC_API CTagObjectDescriptorBSS
{
    CTagObjectDescriptor* m_descriptor;
public:
	CTagObjectDescriptorBSS() : m_descriptor(0)
	{}

    CTagObjectDescriptor& Get()
    {
		if (!m_descriptor)
		{
			m_descriptor = BEHAVIAC_NEW CTagObjectDescriptor;
		}

		BEHAVIAC_ASSERT(m_descriptor);

        return *m_descriptor;
    }

	void Cleanup();
};

////////////////////////////////////////////////////////////////////////////////
// CTagObject
////////////////////////////////////////////////////////////////////////////////
class BEHAVIAC_API CTagObject : public CDynamicType
{
public:
    typedef CTagObjectDescriptor::MembersContainer MembersContainer;
    typedef CTagObjectDescriptor::MethodsContainer MethodsContainer;

    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CTagObject)
    BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(CTagObject, CDynamicType);



    template<class ValueType>
    ValueType       GetMember(const CStringID& nameId);
    template<class ValueType>
    void            SetMember(const CStringID& nameId, const ValueType& value);

#ifdef USE_METHOD_PARAMS_SYSTEM
    void            vCallOld(const CStringID& functionName, const CTagMethodParams& params);
    void            GetMethodParams(const CStringID& functionName, CTagMethodParams& out_param);
#endif

    CMethodBase*    GetMethod(const CStringID& functionName);

    template<class ParamType>
    void            CallMethod(const CStringID& functionName);
    template<class ParamType>
    void            CallMethod(const CStringID& functionName, const ParamType& param);
    template<class ParamType1, class ParamType2>
    void            CallMethod(const CStringID& functionName, const ParamType1& param1, const ParamType2& param2);
    template<class ParamType1, class ParamType2, class ParamType3>
    void            CallMethod(const CStringID& functionName, const ParamType1& param1, const ParamType2& param2, const ParamType3& param3);

    void LoadFromXML(const XmlConstNodeRef& xmlNode);
    void SaveToXML(const XmlNodeRef& xmlNode);

    void Load(const ISerializableNode* node);
    void Save(ISerializableNode* node) const;

    void LoadState(const ISerializableNode* node)
    {
        GetDescriptor().LoadState(this, node);
    }
    void SaveState(ISerializableNode* node) const
    {
        GetDescriptor().SaveState(this, node);
    }

    void GetMembersDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode) const
    {
        GetDescriptor().GetMembersDescription(types, this, xmlNode);
    }
    void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode) const
    {
        GetDescriptor().GetMethodsDescription(types, this, xmlNode);
    }

    // NOTE: before T::GetDescriptor() returns, it must make sure T::RegisterProperties() has been called
    virtual const CTagObjectDescriptor& GetDescriptor() const = 0;

    static void RegisterProperties() { }

    // Scripting
    static int GetScriptTag()
    {
        return -1;
    }
    static void CopyScriptProperties(int tagDest) 
    {
        BEHAVIAC_UNUSED_VAR(tagDest);
    }
    static bool IsAScriptKindOf(int tag)
    {
        BEHAVIAC_UNUSED_VAR(tag);        
        return false;
    }

#if BEHAVIAC_ENABLE_LUA
    // Declare table and holder for a basic tag object.
    SCRIPTMARSHAL_DECLARE_TYPE(CTagObject);
#endif//#if BEHAVIAC_ENABLE_LUA

    static CTagObjectDescriptor& GetObjectDescriptor();
	static CTagObjectDescriptor& GetObjectDescriptorDirectly();
	static void CleanupObjectDescriptor();
protected:
    inline bool ValidateParameters(const char* src, const char* dst);

    static CTagObjectDescriptorBSS ms_descriptor;
};


bool CTagObject::ValidateParameters(const char* src, const char* dst)
{
    BEHAVIAC_UNUSED_VAR(src);
    BEHAVIAC_UNUSED_VAR(dst);
#ifdef _DEBUG

    if (src != dst)
    {
        BEHAVIAC_ASSERT(0, "Invalid parameters passed to CTagObject::CallMethod function. Given Type : %s, Expected Type : %s", src, dst);
    }

    return (src == dst);
#else
    return true;
#endif
}

//template<class NoParam>
//void CTagObject::CallMethod(const CStringID& functionName)
//{
//    CMethodBase* method = GetMethod(functionName);
//    method->vCall(this);
//}
//
//template<class ParamType>
//void CTagObject::CallMethod(const CStringID& functionName,const ParamType& param)
//{
//    CMethodBase* method = GetMethod(functionName);
//    if( ValidateParameters(::GetClassTypeName<ParamType>((ParamType*)0),method->GetParamTypeName(0)) )
//    {
//        method->vCall(this,&param);
//    }
//}
//
//template<class ParamType1,class ParamType2>
//void CTagObject::CallMethod(const CStringID& functionName,const ParamType1& param1,const ParamType2& param2)
//{
//    CMethodBase* method = GetMethod(functionName);
//    if( ValidateParameters(::GetClassTypeName<ParamType1>((ParamType1*)0),method->GetParamTypeName(0)) &&
//        ValidateParameters(::GetClassTypeName<ParamType2>((ParamType2*)0),method->GetParamTypeName(1)) )
//    {
//        method->vCall(this,&param1,&param2);
//    }
//}
//
//template<class ParamType1,class ParamType2,class ParamType3>
//void CTagObject::CallMethod(const CStringID& functionName,const ParamType1& param1,const ParamType2& param2,const ParamType3& param3)
//{
//    CMethodBase* method = GetMethod(functionName);
//    if( ValidateParameters(::GetClassTypeName<ParamType1>((ParamType1*)0),method->GetParamTypeName(0)) &&
//        ValidateParameters(::GetClassTypeName<ParamType2>((ParamType2*)0),method->GetParamTypeName(1)) &&
//        ValidateParameters(::GetClassTypeName<ParamType3>((ParamType3*)0),method->GetParamTypeName(2))
//        )
//    {
//        method->vCall(this,&param1,&param2,&param3);
//    }
//}
namespace behaviac
{
namespace StringUtils
{
	BEHAVIAC_API XmlNodeRef MakeXmlNodeStruct(const char* str, const behaviac::string& typeNameT);

	template<typename T>
	inline bool FromString_Struct(const char* str, T& val)
	{
		behaviac::string typeNameT = FormatString("%s", GetClassTypeName((T*)0));

		XmlNodeRef xmlNode = MakeXmlNodeStruct(str, typeNameT);

		if ((IXmlNode*)xmlNode)
		{
			CTextNode textNode(xmlNode);

			val.Load(&textNode);

			return true;
		}

		return false;
	}

	BEHAVIAC_API bool MakeStringFromXmlNodeStruct(XmlConstNodeRef xmlNode, behaviac::string& result);

	template<typename T>
	inline behaviac::string ToString_Struct(T& val)
	{
		//behaviac::string typeNameT = FormatString("%s", GetClassTypeName((T*)0));
		const char* typeNameT = GetClassTypeName((T*)0);

		XmlNodeRef xmlNode	= CreateXmlNode(typeNameT);

		CTextNode textNode(xmlNode);

		val.Save(&textNode);

		behaviac::string result;

		if (MakeStringFromXmlNodeStruct(xmlNode, result))
		{
			return result;
		}

		return "";
	}
}
}


BEHAVIAC_API bool Equal_Struct(const CTagObjectDescriptor& object_desc, const CTagObject* lhs, const CTagObject* rhs);

////////////////////////////////////////////////////////////////////////////////
// CTagObject macros
////////////////////////////////////////////////////////////////////////////////
#if BEHAVIAC_ENABLE_LUA
#define DECLARE_BEHAVIAC_OBJECT_LUA_NOVIRTUAL(className)						\
    static int GetScriptTag();							                        \
    static void SetScriptTag(int tag);											\
    static int ms_scriptTag;                                                    \
    static void CopyScriptProperties(int tagDest) {}                            \
    static bool IsAScriptKindOf(int tag)										\
    {                                                                           \
        if (ms_scriptTag == tag)                                                \
        {                                                                       \
            return true;                                                        \
        }                                                                       \
        return false;                                                           \
    }																			\
    SCRIPTMARSHAL_DECLARE_OBJECT_TABLE(className)								\

#define DECLARE_BEHAVIAC_OBJECT_LUA(className)									\
    static int GetScriptTag();  						                        \
    static void SetScriptTag(int tag);											\
    static int ms_scriptTag;                                                    \
    static void CopyScriptProperties(int tagDest)                               \
    {                                                                           \
        if (super::GetScriptTag() == -1)                                        \
        {                                                                       \
            super::CopyScriptProperties(tagDest);                               \
            return;                                                             \
        }                                                                       \
        else                                                                    \
            LuaCopyTag(super::GetScriptTag(), tagDest);                         \
    }                                                                           \
    static bool IsAScriptKindOf(int tag)										\
    {                                                                           \
        if (GetScriptTag() == tag)                                              \
        {                                                                       \
            return true;                                                        \
        }                                                                       \
        return super::IsAScriptKindOf(tag);                                     \
    }																			\
    SCRIPTMARSHAL_DECLARE_OBJECT_TABLE(className)
#else
#define DECLARE_BEHAVIAC_OBJECT_LUA_NOVIRTUAL(className)
#define DECLARE_BEHAVIAC_OBJECT_LUA(className)
#endif//#if BEHAVIAC_ENABLE_LUA

#define ACCESS_PROPERTY_METHOD				\
	template<typename T, typename R>		\
	BEHAVIAC_FORCEINLINE R& _Get_Property_();					\
											\
	template<typename T, typename R>										\
	BEHAVIAC_FORCEINLINE R _Execute_Method_();													\
	template<typename T, typename R, typename P0>							\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&);												\
	template<typename T, typename R, typename P0, typename P1>				\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&);											\
	template<typename T, typename R, typename P0, typename P1, typename P2>	\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&);										\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3>										\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&);																						\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3, typename P4>							\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&, P4&);																				\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5>				\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&, P4&, P5&);																			\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>	\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&, P4&, P5&, P6&);																									\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>				\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&, P4&, P5&, P6&, P7&);																								\
	template<typename T, typename R, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>	\
	BEHAVIAC_FORCEINLINE R _Execute_Method_(P0&, P1&, P2&, P3&, P4&, P5&, P6&, P7&, P8&);

#define DECLARE_BEHAVIAC_OBJECT_SIMPLE(className, parentClassName)				\
    private:                                                                    \
    static void RegisterParent()                                                \
    {                                                                           \
        super::RegisterProperties();                                            \
		CTagObjectDescriptor& parentDescriptor = super::GetObjectDescriptorDirectly();	\
		CTagObjectDescriptor& objDesc = className::GetObjectDescriptorDirectly();		\
		objDesc.m_parent = &parentDescriptor;									\
		objDesc.ms_flags |= parentDescriptor.ms_flags;							\
    }                                                                           \
    protected:                                                                  \
    static CTagObjectDescriptorBSS ms_descriptor;								\
																				\
    public:                                                                     \
    static CTagObjectDescriptor& GetObjectDescriptor();							\
	static CTagObjectDescriptor& GetObjectDescriptorDirectly();					\
    virtual const CTagObjectDescriptor& GetDescriptor() const					\
    { RegisterProperties(); return className::GetObjectDescriptor(); }          \
    static void RegisterProperties();                                           \
	DECLARE_BEHAVIAC_OBJECT_LUA(className)

/////////////////////////////////////////////////////////////////////////////////////////
/**
classFullNameWithNamespace is the class full name with namespace, like test_ns::AgentTest

even the class is delared in a namespace, it is still advised to use the full name with the name space.
the corresponding BEGIN_PROPERTIES_DESCRIPTION/END_PROPERTIES_DESCRIPTION in the cpp can be put in or out of that namespace.
*/
#define DECLARE_BEHAVIAC_OBJECT(classFullNameWithNamespace, parentClassName)					\
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(classFullNameWithNamespace)								\
    BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(classFullNameWithNamespace, parentClassName);			\
    DECLARE_BEHAVIAC_OBJECT_SIMPLE(classFullNameWithNamespace, parentClassName);				\
	ACCESS_PROPERTY_METHOD

/////////////////////////////////////////////////////////////////////////////////////////
#if BEHAVIAC_ENABLE_LUA
#define BEHAVIAC_OBJECT_LUA_DESCRIPTION(className)								\
	SCRIPTMARSHAL_IMPLEMENT_OBJECT_TABLE(className);                            \
    int className::ms_scriptTag = -1;                                           \
	int className::GetScriptTag() { return ms_scriptTag; }                      \
	void className::SetScriptTag(int tag)										\
	{ if (ms_scriptTag != -1) return; ms_scriptTag = tag; }						

#define BEHAVIAC_OBJECT_LUA_DESCRIPTION_TEMPLATE(className)						\
    template<class T> SCRIPTMARSHAL_IMPLEMENT_OBJECT_TABLE(className<T>)        \
    template<class T> int className<T>::ms_scriptTag = -1;                      
#else
#define BEHAVIAC_OBJECT_LUA_DESCRIPTION(className)
#define BEHAVIAC_OBJECT_LUA_DESCRIPTION_TEMPLATE(className)
#endif//if BEHAVIAC_ENABLE_LUA

typedef behaviac::map<behaviac::string, const CTagObjectDescriptorBSS*>	TagObjectDescriptorMap_t;
BEHAVIAC_API TagObjectDescriptorMap_t& GetTagObjectDescriptorMaps();
BEHAVIAC_API void CleanupTagObjectDescriptorMaps();

template <typename T>
inline CTagObjectDescriptor& GetObjectDescriptor()					     
{																		 
    static CTagObjectDescriptor s_temp;
	return s_temp;
}															 

template <typename T>
inline void RegisterProperties()                                         
{                                                                         
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, bool bManagedType>
struct ObjectDescriptorGettter
{		
	static CTagObjectDescriptor& _GetObjectDescriptor()					     																 
	{
        return GetObjectDescriptor<T>();
	}	
};																	 

template <typename T, bool bManagedType>
struct RegisterPropertiesGetter
{
	static void _RegisterProperties()
	{                                                                         
		RegisterProperties<T>();
	}
};


template <typename T>
struct ObjectDescriptorGettter<T, true>
{		
	static CTagObjectDescriptor& _GetObjectDescriptor()					     																 
	{
        return T::GetObjectDescriptor();
	}	
};																		 

template <typename T>
struct RegisterPropertiesGetter<T, true>
{
	static void _RegisterProperties()
	{                                                                         
		T::RegisterProperties();
	}
};


#define BEGIN_PROPERTIES_DESCRIPTION(className)									\
    CTagObjectDescriptorBSS className::ms_descriptor;							\
	CTagObjectDescriptor& className::GetObjectDescriptorDirectly(){return className::ms_descriptor.Get();}\
    CTagObjectDescriptor& className::GetObjectDescriptor()						\
    {																			\
		className::RegisterProperties();										\
        return className::ms_descriptor.Get();									\
    }																			\
	BEHAVIAC_OBJECT_LUA_DESCRIPTION(className)									\
    void className::RegisterProperties()                                        \
    {                                                                           \
        if (className::GetObjectDescriptorDirectly().ms_isInitialized)			\
            return;                                                             \
																				\
		TagObjectDescriptorMap_t& maps = GetTagObjectDescriptorMaps();			\
		const char* classNameStr = className::GetClassTypeName();				\
		TagObjectDescriptorMap_t::iterator it = maps.find(classNameStr);		\
		if (it != maps.end()) {													\
			BEHAVIAC_LOG1(BEHAVIAC_LOG_WARNING, "%s duplated in BEGIN_PROPERTIES_DESCRIPTION!\n", classNameStr);\
				}																		\
		maps[classNameStr] = &className::ms_descriptor;							\
        RegisterParent();                                                       \
        CTagObjectDescriptor::MembersContainer& ms_members = className::GetObjectDescriptorDirectly().ms_members;\
        CTagObjectDescriptor::MethodsContainer& ms_methods = className::GetObjectDescriptorDirectly().ms_methods;\
        BEHAVIAC_UNUSED_VAR(ms_members);                                        \
        BEHAVIAC_UNUSED_VAR(ms_methods);                                        \
        typedef className objectType;                                           \
        objectType::GetObjectDescriptorDirectly().ms_isInitialized = true;

/////////////////////////////////////////////////////////////////////////////////////////
#define BEGIN_TEMPLATE1_PROPERTIES_DESCRIPTION(className)                       \
    template<class T> CTagObjectDescriptorBSS className<T>::ms_descriptor;		\
    template<class T> CTagObjectDescriptor& className<T>::GetObjectDescriptor()	\
    {																			\
		className<T>::RegisterProperties();										\
        return className<T>::ms_descriptor.Get();								\
    }																			\
	template<class T> CTagObjectDescriptor& className<T>::GetObjectDescriptorDirectly()	{return className<T>::ms_descriptor.Get();}\
	BEHAVIAC_OBJECT_LUA_DESCRIPTION_TEMPLATE(className)							\
    template<class T> inline void className<T>::RegisterProperties()            \
    {                                                                           \
        if (className<T>::GetObjectDescriptorDirectly().ms_isInitialized)       \
            return;                                                             \
		TagObjectDescriptorMap_t& maps = GetTagObjectDescriptorMaps();			\
		const char* classNameStr = className<T>::GetClassTypeName();			\
		TagObjectDescriptorMap_t::iterator it = maps.find(classNameStr);		\
		if (it != maps.end()) {													\
			BEHAVIAC_LOG1(BEHAVIAC_LOG_WARNING, "%s duplated in BEGIN_PROPERTIES_DESCRIPTION!\n", classNameStr);\
						}														\
		maps[classNameStr] = &className<T>::ms_descriptor;						\
        RegisterParent();                                                       \
        CTagObjectDescriptor::MembersContainer& ms_members = className<T>::GetObjectDescriptorDirectly().ms_members;\
        CTagObjectDescriptor::MethodsContainer& ms_methods = className<T>::GetObjectDescriptorDirectly().ms_methods;\
        typedef className<T> objectType;                                        \
        objectType::GetObjectDescriptorDirectly().ms_isInitialized = true;


/////////////////////////////////////////////////////////////////////////////////////////
#define END_PROPERTIES_DESCRIPTION()         }

//deparated, to use CLASS_DISPLAY_INFO
#define CLASS_DISPLAYNAME(displayName)    objectType::GetObjectDescriptorDirectly().m_displayName = displayName;
#define CLASS_DESC(desc)    objectType::GetObjectDescriptorDirectly().m_desc = desc;

#define CLASS_DISPLAY_INFO(displayName, desc)									\
	objectType::GetObjectDescriptorDirectly().m_displayName = displayName;		\
	if (desc) {objectType::GetObjectDescriptorDirectly().m_desc = desc;}		\
		else {objectType::GetObjectDescriptorDirectly().m_desc = displayName;}

////////////////////////////////////////////////////////////////////////////////
// No-virtual CTagObject declaration
////////////////////////////////////////////////////////////////////////////////
#define DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL_BASE_MACRO(className)					\
    protected:                                                                  \
    static CTagObjectDescriptorBSS ms_descriptor;								\
    public:                                                                     \
    static CTagObjectDescriptor& GetObjectDescriptor();							\
	static CTagObjectDescriptor& GetObjectDescriptorDirectly();					\
    void Load(const ISerializableNode* node)                                    \
    {                                                                           \
        RegisterProperties();                                                   \
        className::GetObjectDescriptorDirectly().Load((CTagObject*)this, node);         \
    }                                                                           \
    void Save(ISerializableNode* node) const                                    \
    {                                                                           \
        RegisterProperties();                                                   \
        className::GetObjectDescriptorDirectly().Save((CTagObject*)this, node);         \
    }                                                                           \
																				\
    void LoadState(const ISerializableNode* node)                               \
    {                                                                           \
        RegisterProperties();                                                   \
        className::GetObjectDescriptorDirectly().LoadState((CTagObject*)this, node);    \
    }                                                                           \
    void SaveState(ISerializableNode* node) const                               \
    {                                                                           \
        RegisterProperties();                                                   \
        className::GetObjectDescriptorDirectly().SaveState((CTagObject*)this, node);    \
    }                                                                           \
    \
    void GetMembersDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode) const	\
    {                                                                           \
        RegisterProperties();                                                   \
        className::GetObjectDescriptorDirectly().GetMembersDescription(types, (CTagObject*)this, xmlNode);	\
    }                                                                           \
    void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode) const	\
    {																			\
        RegisterProperties();													\
        className::GetObjectDescriptorDirectly().GetMethodsDescription(types, (CTagObject*)this, xmlNode);  \
    }																			\
    \
    static void RegisterParent() {}                                             \
    static void RegisterProperties();                                           \
    DECLARE_BEHAVIAC_OBJECT_LUA_NOVIRTUAL(className)							\
	bool Equal(const className& rhs)	const									\
	{																			\
		const CTagObjectDescriptor& object_desc = className::GetObjectDescriptor();	\
		return Equal_Struct(object_desc, (const CTagObject*)this, (const CTagObject*)&rhs);\
	}																			\
	bool operator==(const className& rhs)	const								\
	{																			\
		return this->Equal(rhs);												\
	}																			\
	bool operator!=(const className& rhs)	const								\
	{																			\
		return !this->Equal(rhs);												\
	}																			\
	bool FromString(const char* str)											\
	{																			\
		return behaviac::StringUtils::FromString_Struct(str, *this);						\
	}																			\
	behaviac::string ToString() const											\
	{																			\
		return behaviac::StringUtils::ToString_Struct(*this);								\
	}



/////////////////////////////////////////////////////////////////////////////////////////
#define DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL_BUT_DYNAMICTYPE(className)			\
    DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL_BASE_MACRO(className)

/////////////////////////////////////////////////////////////////////////////////////////
/**
classFullNameWithNamespace is the class full name with namespace, like test_ns::AgentTest, 

even the class is delared in a namespace, it is still advised to use the full name with the name space.
the corresponding BEGIN_PROPERTIES_DESCRIPTION/END_PROPERTIES_DESCRIPTION in the cpp can be put in or out of that namespace.
*/
#define DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(classFullNameWithNamespace)				\
    DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL_BASE_MACRO(classFullNameWithNamespace)		\
    static bool IsOfMyKind(const CTagObject*)										\
    { return true; }																\
    static const char* GetClassTypeName()											\
    { return #classFullNameWithNamespace; }											


/////////////////////////////////////////////////////////////////////////////////////////
struct EnumValueItem_t
{
	behaviac::string		nativeName;
	behaviac::string		name;
	behaviac::wstring		m_displayName;
	behaviac::wstring		m_desc;

	EnumValueItem_t& DISPLAYNAME(const wchar_t* _displayName)
	{
		m_displayName = _displayName;

		return *this;
	}

	EnumValueItem_t& DESC(const wchar_t* _desc)
	{
		m_desc = _desc;

		return *this;
	}

	EnumValueItem_t& DISPLAY_INFO(const wchar_t* _displayName, const wchar_t* _desc = 0)
	{
		m_displayName = _displayName;
		if (_desc)
		{
			m_desc = _desc;
		}
		else
		{
			m_desc = m_displayName;
		}

		return *this;
	}
};

typedef behaviac::map<uint32_t, EnumValueItem_t>	EnumValueNameMap_t;

class EnumClassDescription_t : public CTagTypeDescriptor
{
public:
	BEHAVIAC_DECLARE_DYNAMIC_TYPE(EnumClassDescription_t, CTagTypeDescriptor);

	EnumValueNameMap_t		valueMaps;
	behaviac::wstring		m_displayName;
	behaviac::wstring		m_desc;

	virtual void GetMembersDescription(TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode) const
	{
		BEHAVIAC_UNUSED_VAR(types);
		BEHAVIAC_UNUSED_VAR(parent);

		xmlNode->setAttr("DisplayName", m_displayName);
		xmlNode->setAttr("Desc", m_desc);

		for (EnumValueNameMap_t::const_iterator it = valueMaps.begin(); it != valueMaps.end(); ++it)
		{
			const EnumValueItem_t& valueItem = it->second;
			XmlNodeRef enumNodeElement = xmlNode->newChild("enum");
			enumNodeElement->setAttr("NativeValue", valueItem.nativeName.c_str());
			enumNodeElement->setAttr("Value", valueItem.name.c_str());
			enumNodeElement->setAttr("DisplayName", valueItem.m_displayName);
			enumNodeElement->setAttr("Desc", valueItem.m_desc);
		}
	}
};

//template<typename T>
//inline const EnumClassDescription_t& GetEnumClassValueNames(T*p)
//{
//	BEHAVIAC_ASSERT(0);
//    return *((EnumClassDescription_t*)0);
//}
template<typename T>
const EnumClassDescription_t& GetEnumClassValueNames(T*p);


template<typename T>
inline behaviac::string EnumValueToString(const T& v)
{
	const EnumClassDescription_t& ecd = ::GetEnumClassValueNames((T*)0);

	for (EnumValueNameMap_t::const_iterator it = ecd.valueMaps.begin(); it != ecd.valueMaps.end(); ++it)
	{
		const EnumValueItem_t& valueItem = it->second;

		if (((T)it->first) == v)
		{
			return valueItem.name;
		}
	}

	return "NotAnEnum";
}

template<typename T>
inline bool EnumValueFromString(const char* valueStr, T& v)
{
	const EnumClassDescription_t& ecd = ::GetEnumClassValueNames((T*)0);

	for (EnumValueNameMap_t::const_iterator it = ecd.valueMaps.begin(); it != ecd.valueMaps.end(); ++it)
	{
		const EnumValueItem_t& valueItem = it->second;

		const char* pItemStr = valueItem.name.c_str();
		if (string_nicmp(valueStr, pItemStr, strlen(pItemStr)) == 0)
		{
			v = (T)it->first;
			return true;
		}
	}

	return false;
}

struct EnumClassDescriptionBSS_t
{
	EnumClassDescription_t* descriptor;
};


typedef behaviac::map<behaviac::string, const EnumClassDescriptionBSS_t*>	EnumClassMap_t;
BEHAVIAC_API EnumClassMap_t& GetEnumValueNameMaps();
BEHAVIAC_API void CleanupEnumValueNameMaps();


/**
you need to accompany DECLARE_BEHAVIAC_OBJECT_ENUM(ENUMCLASS_FullNameWithNamespace)
in the cpp, BEGIN_ENUM_DESCRIPTION/END_ENUM_DESCRIPTION

DECLARE_BEHAVIAC_OBJECT_ENUM(namespace::ENUMCLASS_FullNameWithNamespace, EnumClass) should be defined in the global namespace.
*/
#define DECLARE_BEHAVIAC_OBJECT_ENUM(ENUMCLASS_FullNameWithNamespace, EnumClassName)										\
	BEHAVIAC_OVERRIDE_TYPE_NAME(ENUMCLASS_FullNameWithNamespace);															\
	BEHAVIAC_OVERRIDE_TYPE_NAME(behaviac::vector<ENUMCLASS_FullNameWithNamespace>);											\
	SPECIALIZE_TYPE_HANDLER(ENUMCLASS_FullNameWithNamespace, BasicTypeHandlerEnum<ENUMCLASS_FullNameWithNamespace>);		\
	SPECIALIZE_TYPE_HANDLER(behaviac::vector<ENUMCLASS_FullNameWithNamespace>, BasicTypeHandlerEnum<behaviac::vector<ENUMCLASS_FullNameWithNamespace> >);\
	BEHAVIAC_API EnumClassDescriptionBSS_t& EnumClassName##GetEnumClassValueNames();\
	BEHAVIAC_API void RegisterEnumClass(ENUMCLASS_FullNameWithNamespace*);		\
	template<>																	\
	BEHAVIAC_FORCEINLINE  const EnumClassDescription_t& GetEnumClassValueNames<ENUMCLASS_FullNameWithNamespace>(ENUMCLASS_FullNameWithNamespace*p)\
	{																			\
		RegisterEnumClass(p);													\
		EnumClassDescriptionBSS_t& descriptorBSS = EnumClassName##GetEnumClassValueNames();\
		return *descriptorBSS.descriptor;										\
	}																			\
	template< typename SWAPPER >												\
	inline void SwapByteTempl(ENUMCLASS_FullNameWithNamespace& s)				\
	{																			\
		int t = (int)s;															\
		SwapByte(t);															\
		s = (ENUMCLASS_FullNameWithNamespace)t;									\
	}


#define BEGIN_ENUM_DESCRIPTION(ENUMCLASS, EnumClassName)						\
	EnumClassDescriptionBSS_t& EnumClassName##GetEnumClassValueNames()			\
	{																			\
		static EnumClassDescriptionBSS_t s_ValueNameMap;						\
		if (!s_ValueNameMap.descriptor)											\
		{																		\
			s_ValueNameMap.descriptor = BEHAVIAC_NEW EnumClassDescription_t;	\
		}																		\
		return s_ValueNameMap;													\
	}																			\
	void RegisterEnumClass(ENUMCLASS*)											\
	{																			\
		const char* enumClassName = ::GetClassTypeName((ENUMCLASS*)0);			\
		EnumClassMap_t& maps = GetEnumValueNameMaps();							\
		EnumClassMap_t::iterator it = maps.find(enumClassName);					\
		if (it != maps.end())													\
		{																		\
			return;																\
		}																		\
		EnumClassDescriptionBSS_t& enumClassDescBSS = EnumClassName##GetEnumClassValueNames();\
		maps[enumClassName] = &enumClassDescBSS;									\
		EnumClassDescription_t& enumClassDesc = *enumClassDescBSS.descriptor;

//deparated, to use ENUMCLASS_DISPLAY_INFO
#define ENUMCLASS_DISPLAYNAME(displayName_)    enumClassDesc.m_displayName = displayName_;
#define ENUMCLASS_DESC(desc_)    enumClassDesc.m_desc = desc_;


#define ENUMCLASS_DISPLAY_INFO(displayName_, desc_)		\
	enumClassDesc.m_displayName = displayName_;			\
	if (desc_) {enumClassDesc.m_desc = desc_;}			\
	else {enumClassDesc.m_desc = displayName_;}

inline EnumValueItem_t& _defineEnumName(EnumClassDescription_t& ecd, uint32_t value, const char* nativeName, const char* name)
{
	EnumValueItem_t& e = ecd.valueMaps[value];
	e.nativeName = nativeName;
	e.name = name;

	return e;
}

#define DEFINE_ENUM_VALUE(value, name)	_defineEnumName(enumClassDesc, value, #value, name)

#define END_ENUM_DESCRIPTION()         }
/////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Utils
////////////////////////////////////////////////////////////////////////////////
#include "behaviac/base/object/typehandler.h"

#endif // #ifndef _BEHAVIAC_BASE_OBJECT_TAGOBJECT_H_
