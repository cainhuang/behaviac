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

#ifndef BEHAVIAC_ENGINESERVICES_OFFSETMEMBER_H
#define BEHAVIAC_ENGINESERVICES_OFFSETMEMBER_H

#include "behaviac/base/object/member.h"

/////////////////////////////////////////////////////////
/////////////////    OFFSET MEMBER     //////////////////
/////////////////////////////////////////////////////////

#define BEHAVIAC_REGISTER_OFFSET_MEMBER(propertyName, memberName, offset, propertyFlags, MemberHandler, UiDescriptor) \
    { \
        DECLARE_UIWRAPPER(UiDescriptor); \
        behaviac::CMemberBase* property = COffsetMemberFactory<MemberHandler, propertyFlags>::Create( \
                                objectType::GetClassTypeName(), propertyName, &objectType::memberName, offset, localWrapper); \
        CTagObjectDescriptor::PushBackMember(ms_members, property); \
    }

namespace behaviac {
	template<class ObjectType, class MemberType, template <class T> class MemberHandler, uint32_t PropertyFlags>
	class COffsetMember : public behaviac::CMemberBase
	{
	public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(COffsetMember);

		COffsetMember(MemberType ObjectType::* memberPtr, uint32_t offset, const char* className, const char* propertyName, UiGenericType* uiWrapper)
			: behaviac::CMemberBase(propertyName, className), m_memberPtr(memberPtr), m_offset(offset), m_uiWrapper(uiWrapper)
		{
		}

		COffsetMember(const COffsetMember& copy) : behaviac::CMemberBase(copy), m_memberPtr(copy.m_memberPtr), m_offset(copy.m_offset), m_uiWrapper(copy.m_uiWrapper)
		{}

		virtual behaviac::CMemberBase* clone() const
		{
			behaviac::CMemberBase* p = BEHAVIAC_NEW COffsetMember(*this);

			return p;
		}

		virtual void Load(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
		{
			if ((PropertyFlags & behaviac::EPersistenceType_Description_Load))
			{
				CHandlerGuesser<MemberHandler>::Load(node, (((ObjectType*)parent)->*m_memberPtr)[m_offset], this->m_classFullName, m_propertyID);
			}
		}

		virtual void Save(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
		{
			if ((PropertyFlags & behaviac::EPersistenceType_Description_Save))
			{
				CHandlerGuesser<MemberHandler>::Save(node, (((ObjectType*)parent)->*m_memberPtr)[m_offset], this->m_classFullName, m_propertyID);
			}
		}

		virtual void LoadState(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
		{
			if ((PropertyFlags & behaviac::EPersistenceType_State_Load))
			{
				CHandlerGuesser<MemberHandler>::LoadState(node, (((ObjectType*)parent)->*m_memberPtr)[m_offset], this->m_classFullName, m_propertyID);
			}
		}

		virtual void SaveState(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
		{
			if ((PropertyFlags & behaviac::EPersistenceType_State_Save))
			{
				CHandlerGuesser<MemberHandler>::SaveState(node, (((ObjectType*)parent)->*m_memberPtr)[m_offset], this->m_classFullName, m_propertyID);
			}
		}

		virtual void GetUiInfo(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
		{
			if ((PropertyFlags & behaviac::EPersistenceType_UiInfo))
			{
				int readonlyFlag = this->READONLYFLAG();
				CHandlerGuesser<MemberHandler>::GetUiInfo(types, xmlNode, (((ObjectType*)parent)->*m_memberPtr)[m_offset], m_bStatic, readonlyFlag, this->m_classFullName, m_propertyID, this->GetDisplayName(), this->GetDesc(), m_uiWrapper);
			}
		}

		virtual void GetMethodsDescription(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
		{
			CHandlerGuesser<MemberHandler>::GetMethodsDescription(types, xmlNode, (((ObjectType*)parent)->*m_memberPtr)[m_offset], this->m_classFullName, m_propertyID.GetString());
		}

		virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
		{
			BEHAVIAC_UNUSED_VAR(defaultValue);
			BEHAVIAC_UNUSED_VAR(bConst);

			//typedef behaviac::Meta::RemovePtr<MemberType>::Result			StoredMemberType;
			//behaviac::Property* pProperty = behaviac::Property::Creator<MemberType>(this, bConst);

			//return pProperty;
			return 0;
		}
	private:
		MemberType ObjectType::*    m_memberPtr;
		uint32_t                       m_offset;
		UiGenericType*              m_uiWrapper;
	};

	template<template <class T> class MemberHandler, uint32_t PropertyFlags>
	struct COffsetMemberFactory
	{
		template<class ObjectType, class MemberType>
		static behaviac::CMemberBase* Create(const char* className, const char* propertyName, MemberType(ObjectType::* memberPtr), uint32_t offset, UiGenericType* uiWrapper)
		{
			typedef COffsetMember<ObjectType, MemberType, MemberHandler, PropertyFlags> MemberTypeType;
			return BEHAVIAC_NEW MemberTypeType(memberPtr, offset, className, propertyName, uiWrapper);
		}
	};
}//

#endif // #ifndef BEHAVIAC_ENGINESERVICES_OFFSETMEMBER_H
