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

#ifndef _BEHAVIAC_AGENT_NAMEDEVENT_H_
#define _BEHAVIAC_AGENT_NAMEDEVENT_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/factory.h"
#include "behaviac/base/object/tagobject.h"
#include "behaviac/base/core/string/stringid.h"
#include "behaviac/base/object/method.h"

namespace behaviac
{
	class Property;
}

class BEHAVIAC_API CNamedEvent : public CMethodBase, public CDynamicType
{
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CNamedEvent);
	BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(CNamedEvent, CDynamicType)

		CNamedEvent(const char* className, const char* propertyName) 
		: CMethodBase(propertyName, className), m_bFired(false)
	{
		//this->m_flag = true;
	}

	CNamedEvent(const CNamedEvent& copy) : CMethodBase(copy), m_bFired(false)
	{
	}

	virtual void LoadFromXML(CTagObject* parent, const ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);
	}

	virtual void SaveToXML(const CTagObject* parent, ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		XmlNodeRef memberNode = xmlNode;
		if (types == NULL)
		{
			memberNode = xmlNode->newChild("Method");
			memberNode->setAttr("Name", this->m_propertyName);
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());

			if (this->m_flag & CMethodBase::KMETHOD_NAMEDEVENT)
			{
				memberNode->setAttr("Flag", "namedevent");
			}
			if (this->m_classFullName)
			{
				memberNode->setAttr("Class", this->m_classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			const char* pReturn = "bool";
			memberNode->setAttr("ReturnType", pReturn);
		}

		UserTypeInfoExport<bool>::Export(types, true, memberNode);
	}

	virtual void vCall(const CTagObject* parent)
	{
		BEHAVIAC_UNUSED_VAR(parent);
	}

	virtual int GetParams()
	{
		return 0;
	}

	virtual behaviac::string GetParamTypeName(uint32_t idx)
	{
		BEHAVIAC_UNUSED_VAR(idx);

		return behaviac::string();
	}

	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		behaviac::Property* pProperty = behaviac::Property::Creator<bool>(defaultValue, 0, bConst);

		return pProperty;
	}

	virtual CMethodBase* clone() const
	{
		return BEHAVIAC_NEW CNamedEvent(*this);
	}

	virtual void run(const CTagObject* parent, const CTagObject* parHolder);

#if BEHAVIAC_ENABLE_NETWORKD
	virtual void run(const CTagObject* parent, const CTagObject* parHolder, const behaviac::Variants_t& params)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);
		BEHAVIAC_UNUSED_VAR(params);
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD
	virtual bool IsNamedEvent() const
	{
		return true;
	}

	void SetFired(behaviac::Agent* pAgent, bool bFired);

	bool IsFired() const
	{
		return this->m_bFired;
	}

	CNamedEvent& SETSTATIC()
	{
		this->m_bStatic = true;

		return *this;
	}

	bool IsStatic() const
	{
		return this->m_bStatic;
	}

	const char* GetClassNameString() const
	{
		return this->m_bStatic ? this->m_classFullName : 0;
	}

protected:
	bool		m_bFired;
};


template<class ParamType>
class CNamedEvent1 : public CNamedEvent
{
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CNamedEvent1);
	BEHAVIAC_DECLARE_TEMPLATE_DYNAMIC_TYPE1(CNamedEvent1, ParamType, CNamedEvent)

	typedef PARAM_BASETYPE(ParamType)				ParamBaseType;
	typedef PARAM_POINTERTYPE(ParamType)			ParamPointerType;

	CNamedEvent1(const char* className, const char* propertyName) :
	CNamedEvent(className, propertyName)
	{
	}

	CNamedEvent1(const CNamedEvent1& copy) : CNamedEvent(copy)
	{

		this->m_paramDisplayName = copy.m_paramDisplayName;

		//this->m_param = copy.m_param;
	}


	virtual void LoadFromXML(CTagObject* parent, const ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType>::LoadFromXML(xmlNode, m_param, 0, "param1");
	}

	virtual void SaveToXML(const CTagObject* parent, ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType>::SaveToXML(xmlNode, m_param, 0, "param1");
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		XmlNodeRef memberNode = xmlNode;
		if (types == NULL)
		{
			memberNode = xmlNode->newChild("Method");
			memberNode->setAttr("Name", this->m_propertyName);
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());

			if (this->m_flag & CMethodBase::KMETHOD_NAMEDEVENT)
			{
				memberNode->setAttr("Flag", "namedevent");
			}
			if (this->m_classFullName)
			{
				memberNode->setAttr("Class", this->m_classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			const char* pReturn = "bool";
			memberNode->setAttr("ReturnType", pReturn);
		}

		UserTypeInfoExport<bool>::Export(types, true, memberNode);

		XmlNodeRef paramNode = memberNode;
		if (types == NULL)
		{
			paramNode = memberNode->newChild("Param");
			paramNode->setAttr("DisplayName", m_paramDisplayName);
			paramNode->setAttr("Desc", m_paramDesc);

			behaviac::string typeStr = ::GetTypeDescString<ParamType>();
			paramNode->setAttr("Type", typeStr.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType, behaviac::Meta::IsEnum<ParamBaseType>::Result>::GetUiInfo(types, paramNode);
	}

	virtual CMethodBase& PARAM_DISPLAYNAME(const wchar_t* paramDisplayName)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);

		if (m_paramDisplayName.empty())
		{
			m_paramDisplayName = paramDisplayName;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}
	virtual CMethodBase& PARAM_DESC(const wchar_t* paramDesc)
	{
		BEHAVIAC_UNUSED_VAR(paramDesc);

		if (m_paramDesc.empty())
		{
			m_paramDesc = paramDesc;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}

	virtual CMethodBase& PARAM_DISPLAY_INFO(const wchar_t* paramDisplayName, const wchar_t* paramDesc = 0, const DefaultParam_t& defaultParam = DefaultParam_t(), float rangeMin = CMETHODBASE_RANGE_MIN_DEFAULT, float rangeMax = CMETHODBASE_RANGE_MAX_DEFAULT)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);
		BEHAVIAC_UNUSED_VAR(paramDesc);
		BEHAVIAC_UNUSED_VAR(defaultParam);
		BEHAVIAC_UNUSED_VAR(rangeMin);
		BEHAVIAC_UNUSED_VAR(rangeMax);


		m_paramDisplayName = paramDisplayName;
		m_paramDesc = (paramDesc == 0 ?  m_paramDisplayName : paramDesc);

		return *this;
	}

	virtual int GetParams()
	{
		return 1;
	}

	virtual behaviac::string GetParamTypeName(uint32_t idx)
	{
		switch (idx)
		{
		case 0:
			{
				behaviac::string typeStr = ::GetTypeDescString<ParamType>();
				return typeStr;
			}

		default:
			return "";
		}
	}

	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		behaviac::Property* pProperty = behaviac::Property::Creator<bool>(defaultValue, 0, bConst);

		return pProperty;
	}

	virtual CMethodBase* clone() const
	{
		return BEHAVIAC_NEW CNamedEvent1(*this);
	}

	virtual void run(const CTagObject* parent, const CTagObject* parHolder)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);

		//const behaviac::Agent* pAgent = behaviac::Agent::DynamicCast(parent);
		//if (pAgent)
		//{
		//	const CNamedEvent* pE = pAgent->FindEvent(this->GetName(), this->GetClassNameString());

		//	if (pE)
		//	{
		//		const CNamedEvent1* pE1 = CNamedEvent1::DynamicCast(pE);

		//		if (pE1->IsFired() && pE1->m_param == this->m_param)
		//		{
		//			*(AsyncValue<bool>*)this->m_return = true;
		//		}
		//	}
		//}
	}

#if BEHAVIAC_ENABLE_NETWORKD
	virtual void run(const CTagObject* parent, const CTagObject* parHolder, const behaviac::Variants_t& params)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);
		BEHAVIAC_UNUSED_VAR(params);
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD

	void SetParam(behaviac::Agent* pAgent, const ParamBaseType& param)
	{
		//this->m_param = param;
		const char* eventName = FormatString("%s::%s::param0", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName, param);
	}

protected:

	behaviac::wstring				m_paramDisplayName;
	behaviac::wstring				m_paramDesc;

	//ParamBaseType				m_param;
};


template<class ParamType1, class ParamType2>
class CNamedEvent2 : public CNamedEvent
{
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CNamedEvent2);
	BEHAVIAC_DECLARE_TEMPLATE_DYNAMIC_TYPE2(CNamedEvent2, ParamType1, ParamType2, CNamedEvent)

		typedef PARAM_BASETYPE(ParamType1)				ParamBaseType1;
	typedef PARAM_BASETYPE(ParamType2)				ParamBaseType2;
	typedef PARAM_POINTERTYPE(ParamType1)			ParamPointerType1;
	typedef PARAM_POINTERTYPE(ParamType2)			ParamPointerType2;

	CNamedEvent2(const char* className, const char* propertyName) :
	CNamedEvent(className, propertyName)//, m_param1(), m_param2()
	{
	}

	CNamedEvent2(const CNamedEvent2& copy) : CNamedEvent(copy)
	{

		this->m_paramDisplayName1 = copy.m_paramDisplayName1;
		this->m_paramDisplayName2 = copy.m_paramDisplayName2;

		//this->m_param1 = copy.m_param1;
		//this->m_param2= copy.m_param2;
	}


	virtual void LoadFromXML(CTagObject* parent, const ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType1>::LoadFromXML(xmlNode, m_param1, 0, "param1");
		//GenericTypeHandler<ParamBaseType2>::LoadFromXML(xmlNode, m_param2, 0, "param2");
	}

	virtual void SaveToXML(const CTagObject* parent, ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType1>::SaveToXML(xmlNode, m_param1, 0, "param1");
		//GenericTypeHandler<ParamBaseType2>::SaveToXML(xmlNode, m_param2, 0, "param2");
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		XmlNodeRef memberNode = xmlNode;
		if (types == NULL)
		{
			memberNode = xmlNode->newChild("Method");
			memberNode->setAttr("Name", this->m_propertyName);
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());

			if (this->m_flag & CMethodBase::KMETHOD_NAMEDEVENT)
			{
				memberNode->setAttr("Flag", "namedevent");
			}
			if (this->m_classFullName)
			{
				memberNode->setAttr("Class", this->m_classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			const char* pReturn = "bool";
			memberNode->setAttr("ReturnType", pReturn);
		}

		UserTypeInfoExport<bool>::Export(types, true, memberNode);

		XmlNodeRef paramNode1 = memberNode;
		if (types == NULL)
		{
			paramNode1 = memberNode->newChild("Param");
			paramNode1->setAttr("DisplayName", m_paramDisplayName1);
			paramNode1->setAttr("Desc", m_paramDesc1);

			behaviac::string typeStr1 = ::GetTypeDescString<ParamType1>();
			paramNode1->setAttr("Type", typeStr1.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType1, behaviac::Meta::IsEnum<ParamBaseType1>::Result>::GetUiInfo(types, paramNode1);

		XmlNodeRef paramNode2 = memberNode;
		if (types == NULL)
		{
			paramNode2 = memberNode->newChild("Param");
			paramNode2->setAttr("DisplayName", m_paramDisplayName2);
			paramNode2->setAttr("Desc", m_paramDesc2);

			behaviac::string typeStr2 = ::GetTypeDescString<ParamType2>();
			paramNode2->setAttr("Type", typeStr2.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType2, behaviac::Meta::IsEnum<ParamBaseType2>::Result>::GetUiInfo(types, paramNode2);
	}

	virtual CMethodBase& PARAM_DISPLAYNAME(const wchar_t* paramDisplayName)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);

		if (m_paramDisplayName1.empty())
		{
			m_paramDisplayName1 = paramDisplayName;
		}
		else if (m_paramDisplayName2.empty())
		{
			m_paramDisplayName2 = paramDisplayName;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}

	virtual CMethodBase& PARAM_DESC(const wchar_t* paramDesc)
	{
		BEHAVIAC_UNUSED_VAR(paramDesc);

		if (m_paramDesc1.empty())
		{
			m_paramDesc1 = paramDesc;
		}
		else if (m_paramDesc2.empty())
		{
			m_paramDesc2 = paramDesc;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}

	virtual CMethodBase& PARAM_DISPLAY_INFO(const wchar_t* paramDisplayName, const wchar_t* paramDesc = 0, const DefaultParam_t& defaultParam = DefaultParam_t(), float rangeMin = CMETHODBASE_RANGE_MIN_DEFAULT, float rangeMax = CMETHODBASE_RANGE_MAX_DEFAULT)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);
		BEHAVIAC_UNUSED_VAR(paramDesc);
		BEHAVIAC_UNUSED_VAR(defaultParam);
		BEHAVIAC_UNUSED_VAR(rangeMin);
		BEHAVIAC_UNUSED_VAR(rangeMax);


		if (m_paramDisplayName1.empty())
		{
			m_paramDisplayName1 = paramDisplayName;
			m_paramDesc1 = (paramDesc == 0 ?  m_paramDisplayName1 : paramDesc);
		}
		else if (m_paramDisplayName2.empty())
		{
			m_paramDisplayName2 = paramDisplayName;
			m_paramDesc2 = (paramDesc == 0 ?  m_paramDisplayName2 : paramDesc);
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}


	virtual int GetParams()
	{
		return 2;
	}

	virtual behaviac::string GetParamTypeName(uint32_t idx)
	{
		switch (idx)
		{
		case 0:
			{
				behaviac::string typeStr1 = ::GetTypeDescString<ParamType1>();
				return typeStr1;
			}

		case 1:
			{
				behaviac::string typeStr2 = ::GetTypeDescString<ParamType2>();
				return typeStr2;
			}

		default:
			return "";
		}
	}

	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		behaviac::Property* pProperty = behaviac::Property::Creator<bool>(defaultValue, 0, bConst);

		return pProperty;
	}

	virtual CMethodBase* clone() const
	{
		return BEHAVIAC_NEW CNamedEvent2(*this);
	}

	virtual void run(const CTagObject* parent, const CTagObject* parHolder)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);

		//const behaviac::Agent* pAgent = behaviac::Agent::DynamicCast(parent);
		//if (pAgent)
		//{
		//	const CNamedEvent* pE = pAgent->FindEvent(this->GetName(), this->GetClassNameString());
		//	if (pE)
		//	{
		//		const CNamedEvent2* pE2 = CNamedEvent2::DynamicCast(pE);

		//		if (pE2->IsFired() && pE2->m_param1 == this->m_param1 && pE2->m_param2 == this->m_param2)
		//		{
		//			*(AsyncValue<bool>*)this->m_return = true;
		//		}
		//	}
		//}
	}

#if BEHAVIAC_ENABLE_NETWORKD
	virtual void run(const CTagObject* parent, const CTagObject* parHolder, const behaviac::Variants_t& params)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);
		BEHAVIAC_UNUSED_VAR(params);
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD

	void SetParam(behaviac::Agent* pAgent, const ParamBaseType1& param1, const ParamBaseType2& param2)
	{
		//this->m_param1 = param1;
		//this->m_param2 = param2;

		behaviac::string eventName1 = FormatString("%s::%s::param0", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName1.c_str(), param1);

		behaviac::string eventName2 = FormatString("%s::%s::param1", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName2.c_str(), param2);
	}


protected:

	behaviac::wstring				m_paramDisplayName1;
	behaviac::wstring				m_paramDesc1;
	behaviac::wstring				m_paramDisplayName2;
	behaviac::wstring				m_paramDesc2;

	//ParamBaseType1				m_param1;
	//ParamBaseType2				m_param2;
};


template<class ParamType1, class ParamType2, class ParamType3>
class CNamedEvent3 : public CNamedEvent
{
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CNamedEvent3);
	BEHAVIAC_DECLARE_TEMPLATE_DYNAMIC_TYPE3(CNamedEvent3, ParamType1, ParamType2, ParamType3, CNamedEvent)

		typedef PARAM_BASETYPE(ParamType1)				ParamBaseType1;
	typedef PARAM_BASETYPE(ParamType2)				ParamBaseType2;
	typedef PARAM_BASETYPE(ParamType3)				ParamBaseType3;
	typedef PARAM_POINTERTYPE(ParamType1)			ParamPointerType1;
	typedef PARAM_POINTERTYPE(ParamType2)			ParamPointerType2;
	typedef PARAM_POINTERTYPE(ParamType3)			ParamPointerType3;

	CNamedEvent3(const char* className, const char* propertyName) :
	CNamedEvent(className, propertyName)
	{
	}

	CNamedEvent3(const CNamedEvent3& copy) : CNamedEvent(copy)
	{

		this->m_paramDisplayName1 = copy.m_paramDisplayName1;
		this->m_paramDisplayName2 = copy.m_paramDisplayName2;
		this->m_paramDisplayName3 = copy.m_paramDisplayName3;

		//this->m_param1 = copy.m_param1;
		//this->m_param2= copy.m_param2;
		//this->m_param3= copy.m_param3;
	}


	virtual void LoadFromXML(CTagObject* parent, const ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType1>::LoadFromXML(xmlNode, m_param1, 0, "param1");
		//GenericTypeHandler<ParamBaseType2>::LoadFromXML(xmlNode, m_param2, 0, "param2");
		//GenericTypeHandler<ParamBaseType3>::LoadFromXML(xmlNode, m_param3, 0, "param3");
	}

	virtual void SaveToXML(const CTagObject* parent, ISerializableNode& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		//GenericTypeHandler<ParamBaseType1>::SaveToXML(xmlNode, m_param1, 0, "param1");
		//GenericTypeHandler<ParamBaseType2>::SaveToXML(xmlNode, m_param2, 0, "param2");
		//GenericTypeHandler<ParamBaseType3>::SaveToXML(xmlNode, m_param3, 0, "param3");
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(xmlNode);

		XmlNodeRef memberNode = xmlNode;
		if (types == NULL)
		{
			memberNode = xmlNode->newChild("Method");
			memberNode->setAttr("Name", this->m_propertyName);
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());

			if (this->m_flag & CMethodBase::KMETHOD_NAMEDEVENT)
			{
				memberNode->setAttr("Flag", "namedevent");
			}
			if (this->m_classFullName)
			{
				memberNode->setAttr("Class", this->m_classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			const char* pReturn = "bool";
			memberNode->setAttr("ReturnType", pReturn);
		}

		UserTypeInfoExport<bool>::Export(types, true, memberNode);

		XmlNodeRef paramNode1 = memberNode;
		if (types == NULL)
		{
			paramNode1 = memberNode->newChild("Param");
			paramNode1->setAttr("DisplayName", m_paramDisplayName1);
			paramNode1->setAttr("Desc", m_paramDesc1);

			behaviac::string typeStr1 = ::GetTypeDescString<ParamType1>();
			paramNode1->setAttr("Type", typeStr1.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType1, behaviac::Meta::IsEnum<ParamBaseType1>::Result>::GetUiInfo(types, paramNode1);

		XmlNodeRef paramNode2 = memberNode;
		if (types == NULL)
		{
			paramNode2 = memberNode->newChild("Param");
			paramNode2->setAttr("DisplayName", m_paramDisplayName2);
			paramNode2->setAttr("Desc", m_paramDesc2);

			behaviac::string typeStr2 = ::GetTypeDescString<ParamType2>();
			paramNode2->setAttr("Type", typeStr2.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType2, behaviac::Meta::IsEnum<ParamBaseType2>::Result>::GetUiInfo(types, paramNode2);

		XmlNodeRef paramNode3 = memberNode;
		if (types == NULL)
		{
			paramNode3 = memberNode->newChild("Param");
			paramNode3->setAttr("DisplayName", m_paramDisplayName3);
			paramNode3->setAttr("Desc", m_paramDesc3);

			behaviac::string typeStr3 = ::GetTypeDescString<ParamType3>();
			paramNode3->setAttr("Type", typeStr3.c_str());
		}

		EnumClassUiInfoGetter<ParamBaseType3, behaviac::Meta::IsEnum<ParamBaseType3>::Result>::GetUiInfo(types, paramNode3);
	}

	virtual CMethodBase& PARAM_DISPLAYNAME(const wchar_t* paramDisplayName)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);

		if (m_paramDisplayName1.empty())
		{
			m_paramDisplayName1 = paramDisplayName;
		}
		else if (m_paramDisplayName2.empty())
		{
			m_paramDisplayName2 = paramDisplayName;
		}
		else if (m_paramDisplayName3.empty())
		{
			m_paramDisplayName3 = paramDisplayName;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}

	virtual CMethodBase& PARAM_DESC(const wchar_t* paramDesc)
	{
		BEHAVIAC_UNUSED_VAR(paramDesc);

		if (m_paramDesc1.empty())
		{
			m_paramDesc1 = paramDesc;
		}
		else if (m_paramDesc2.empty())
		{
			m_paramDesc2 = paramDesc;
		}
		else if (m_paramDesc3.empty())
		{
			m_paramDesc3 = paramDesc;
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}

	virtual CMethodBase& PARAM_DISPLAY_INFO(const wchar_t* paramDisplayName, const wchar_t* paramDesc = 0, const DefaultParam_t& defaultParam = DefaultParam_t(), float rangeMin = CMETHODBASE_RANGE_MIN_DEFAULT, float rangeMax = CMETHODBASE_RANGE_MAX_DEFAULT)
	{
		BEHAVIAC_UNUSED_VAR(paramDisplayName);
		BEHAVIAC_UNUSED_VAR(paramDesc);
		BEHAVIAC_UNUSED_VAR(defaultParam);
		BEHAVIAC_UNUSED_VAR(rangeMin);
		BEHAVIAC_UNUSED_VAR(rangeMax);


		if (m_paramDisplayName1.empty())
		{
			m_paramDisplayName1 = paramDisplayName;
			m_paramDesc1 = (paramDesc == 0 ?  m_paramDisplayName1 : paramDesc);
		}
		else if (m_paramDisplayName2.empty())
		{
			m_paramDisplayName2 = paramDisplayName;
			m_paramDesc2 = (paramDesc == 0 ?  m_paramDisplayName2 : paramDesc);
		}
		else if (m_paramDisplayName3.empty())
		{
			m_paramDisplayName3 = paramDisplayName;
			m_paramDesc3 = (paramDesc == 0 ?  m_paramDisplayName3 : paramDesc);
		}
		else
		{
			BEHAVIAC_ASSERT(0, "too many params!");
		}

		return *this;
	}


	virtual int GetParams()
	{
		return 3;
	}

	virtual behaviac::string GetParamTypeName(uint32_t idx)
	{
		switch (idx)
		{
		case 0:
			{
				behaviac::string typeStr1 = ::GetTypeDescString<ParamType1>();
				return typeStr1;
			}

		case 1:
			{
				behaviac::string typeStr2 = ::GetTypeDescString<ParamType2>();
				return typeStr2;
			}

		case 2:
			{
				behaviac::string typeStr3 = ::GetTypeDescString<ParamType3>();
				return typeStr3;
			}

		default:
			return "";
		}
	}

	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		behaviac::Property* pProperty = behaviac::Property::Creator<bool>(defaultValue, 0, bConst);

		return pProperty;
	}

	virtual CMethodBase* clone() const
	{
		return BEHAVIAC_NEW CNamedEvent3(*this);
	}

	virtual void run(const CTagObject* parent, const CTagObject* parHolder)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);

		//const behaviac::Agent* pAgent = behaviac::Agent::DynamicCast(parent);
		//if (pAgent)
		//{
		//	const CNamedEvent* pE = pAgent->FindEvent(this->GetName(), this->GetClassNameString());
		//	if (pE)
		//	{
		//		const CNamedEvent3* pE3 = CNamedEvent3::DynamicCast(pE);

		//		if (pE3->IsFired() && 
		//			pE3->m_param1 == this->m_param1 && 
		//			pE3->m_param2 == this->m_param2 && 
		//			pE3->m_param3 == this->m_param3)
		//		{
		//			*(AsyncValue<bool>*)this->m_return = true;
		//		}
		//	}
		//}
	}

#if BEHAVIAC_ENABLE_NETWORKD
	virtual void run(const CTagObject* parent, const CTagObject* parHolder, const behaviac::Variants_t& params)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(parHolder);
		BEHAVIAC_UNUSED_VAR(params);
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD

	void SetParam(behaviac::Agent* pAgent, const ParamBaseType1& param1, const ParamBaseType2& param2, const ParamBaseType3& param3)
	{
		//this->m_param1 = param1;
		//this->m_param2 = param2;
		//this->m_param3 = param3;
		behaviac::string eventName0 = FormatString("%s::%s::param0", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName0.c_str(), param1);

		behaviac::string eventName1 = FormatString("%s::%s::param1", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName1.c_str(), param2);

		behaviac::string eventName2 = FormatString("%s::%s::param2", this->m_classFullName, this->m_propertyName);
		pAgent->SetVariable(eventName2.c_str(), param3);
	}


protected:

	behaviac::wstring				m_paramDisplayName1;
	behaviac::wstring				m_paramDesc1;
	behaviac::wstring				m_paramDisplayName2;
	behaviac::wstring				m_paramDesc2;
	behaviac::wstring				m_paramDisplayName3;
	behaviac::wstring				m_paramDesc3;

	//ParamBaseType1				m_param1;
	//ParamBaseType2				m_param2;
	//ParamBaseType3				m_param3;
};


BEHAVIAC_FORCEINLINE CNamedEvent& _addEvent(behaviac::vector<class CMethodBase*>& methods, CNamedEvent* _method)
{
	_method->SetFlag(CMethodBase::KMETHOD_NAMEDEVENT);

	methods.push_back(_method);
	return *_method;
}


struct CEventFactory
{
	static CNamedEvent& Create(const char* className, const char* propertyName)
	{
		CNamedEvent* pMethod = BEHAVIAC_NEW CNamedEvent(className, propertyName);
		pMethod->AddResultHanlder<bool>();
		return *pMethod;
	}

	template<class ParamType1>
	static CNamedEvent& Create(const char* className, const char* propertyName)
	{
		typedef CNamedEvent1<ParamType1> EventType;
		CNamedEvent* pMethod = BEHAVIAC_NEW EventType(className, propertyName);
		pMethod->AddResultHanlder<bool>();
		return *pMethod;
	}

	template<class ParamType1, class ParamType2>
	static CNamedEvent& Create(const char* className, const char* propertyName)
	{
		typedef CNamedEvent2<ParamType1, ParamType2> EventType;
		CNamedEvent* pMethod = BEHAVIAC_NEW EventType(className, propertyName);
		pMethod->AddResultHanlder<bool>();
		return *pMethod;
	}

	template<class ParamType1, class ParamType2, class ParamType3>
	static CNamedEvent& Create(const char* className, const char* propertyName)
	{
		typedef CNamedEvent3<ParamType1, ParamType2, ParamType3> EventType;
		CNamedEvent* pMethod = BEHAVIAC_NEW EventType(className, propertyName);
		pMethod->AddResultHanlder<bool>();
		return *pMethod;
	}
};
#endif//#ifndef _BEHAVIAC_AGENT_NAMEDEVENT_H_
