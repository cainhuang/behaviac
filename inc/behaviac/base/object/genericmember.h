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

#ifndef _ENGINESERVICES_GENERICMEMBER_H_
#define _ENGINESERVICES_GENERICMEMBER_H_


#include "behaviac/base/object/typehandler.h"
#include "behaviac/base/object/uitype.h"
#include "behaviac/base/object/member.h"
#include "behaviac/property/property.h"
#include "behaviac/property/operators.inl"
#include "behaviac/agent/agent.h"

#include "behaviac/network/network.h"

template<class ObjectType, class MemberType, class MemberHandler, uint32_t PropertyFlags>
class CGenericMember : public CMemberBase
{
public:
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CGenericMember);

	CGenericMember(MemberType ObjectType::* memberPtr, const char* className, const char* propertyName, UiGenericType* uiWrapper) : CMemberBase(propertyName, className), m_memberPtr(memberPtr), m_uiWrapper(uiWrapper)
	{
	}

	CGenericMember(const CGenericMember& copy) : CMemberBase(copy), m_memberPtr(copy.m_memberPtr), m_uiWrapper(copy.m_uiWrapper)
	{}

	virtual CMemberBase* clone() const
	{
		CMemberBase* p = BEHAVIAC_NEW CGenericMember(*this);

		return p;
	}

	virtual void Load(CTagObject* parent, const ISerializableNode* node)
	{
		if (PropertyFlags & EPersistenceType_Description_Load)
		{
			MemberHandler::Load(node, ((ObjectType*)parent)->*m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void Save(const CTagObject* parent, ISerializableNode* node)
	{
		if (PropertyFlags & EPersistenceType_Description_Save)
		{
			MemberHandler::Save(node, ((ObjectType*)parent)->*m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void LoadState(CTagObject* parent, const ISerializableNode* node)
	{
		if (PropertyFlags & EPersistenceType_State_Load)
		{
			MemberHandler::LoadState(node, ((ObjectType*)parent)->*m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void SaveState(const CTagObject* parent, ISerializableNode* node)
	{
		if (PropertyFlags & EPersistenceType_State_Save)
		{
			MemberHandler::SaveState(node, ((ObjectType*)parent)->*m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		if (PropertyFlags & EPersistenceType_UiInfo)
		{
			MemberHandler::GetUiInfo(types, xmlNode, ((ObjectType*)parent)->*m_memberPtr, m_bStatic, this->m_classFullName, m_propertyID, this->GetDisplayName(), this->GetDesc(), m_uiWrapper);
		}
	}

	virtual void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		MemberHandler::GetMethodsDescription(types, xmlNode, ((ObjectType*)parent)->*m_memberPtr, this->m_classFullName, m_propertyID.GetString());
	}

	virtual void Set(const CTagObject* parent, const void* value, int typeId) const
	{
		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);

		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			((ObjectType*)parent)->*m_memberPtr = *((MemberType*)value);
		}
	}

	virtual void* Get(const CTagObject* parent, int typeId) const
	{
		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);

		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			return &(((ObjectType*)parent)->*m_memberPtr);
		}

		return 0;
	}

	virtual void        SetVariable(const CTagObject* parent, const void* value, int typeId) const
	{
		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);
		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			behaviac::Agent* pAgent = (behaviac::Agent*)parent;
			const MemberType& v = *(MemberType*)value;

			const char* propertyName = m_propertyID.GetString();
			//pAgent->SetVariable(propertyName, v);
			pAgent->SetVariableRegistry(this, propertyName, v, 0, this->m_propertyID.GetID().GetUniqueID());

			//behaviac::NetworkRole netRole = this->GetNetRole();

			//if (netRole != behaviac::NET_ROLE_DEFAULT)
			//{
			//	behaviac::Network* pNw = behaviac::Network::GetInstance();

			//	if (pNw && !pNw->IsSinglePlayer())
			//	{
			//		if (netRole == behaviac::NET_ROLE_AUTHORITY && !pNw->IsAuthority() ||
			//			netRole == behaviac::NET_ROLE_NONAUTHORITY && pNw->IsAuthority())
			//		{
			//			pNw->ReplicateVariable(pAgent, propertyName, typeId, (void*)&v, true);
			//		}
			//	}
			//}
		}
	}
#if BEHAVIAC_ENABLE_NETWORKD
	virtual void ReplicateProperty(behaviac::Agent* pAgent)
	{
		const char* propertyName = m_propertyID.GetString();
		behaviac::NetworkRole netRole = this->NETROLE();

		if (netRole != behaviac::NET_ROLE_DEFAULT)
		{
			behaviac::Network* pNw = behaviac::Network::GetInstance();

			if (pNw && !pNw->IsSinglePlayer())
			{
				bool bSend = false;
				bool bReceive = false; 

				if (pNw->IsAuthority())
				{
					if (netRole == behaviac::NET_ROLE_NONAUTHORITY)
					{
						bSend = true;
					}
					else if (netRole == behaviac::NET_ROLE_AUTHORITY)
					{
						bReceive = true;
					}
				}
				else
				{
					if (netRole == behaviac::NET_ROLE_AUTHORITY)
					{
						bSend = true;
					}
					else if (netRole == behaviac::NET_ROLE_NONAUTHORITY)
					{
						bReceive = true;
					}
				}

				if (bSend || bReceive)
				{
					int typeId = GetClassTypeNumberId<MemberType>();

					pNw->ReplicateVariable(pAgent, propertyName, typeId, (void*)&(((ObjectType*)pAgent)->*m_memberPtr), bSend);
				}
			}
		}	
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD
	virtual void*       GetVariable(const CTagObject* parent, int typeId) const
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(typeId);

		BEHAVIAC_ASSERT(!"Only works with CGenericMembers");
		return NULL;
	};

	virtual int GetTypeId() const
	{
		return ::GetClassTypeNumberId<MemberType>();
	}

	virtual void SetFromProperty(CTagObject* parent, const CTagObject* parHolder, const behaviac::Property* pProperty) const
	{
		int typeId = this->GetTypeId();
		BEHAVIAC_ASSERT(pProperty->GetTypeId() == typeId);

		const behaviac::TProperty<MemberType>* pTProperty = (const behaviac::TProperty<MemberType>*)pProperty;
		const MemberType& v = pTProperty->GetValue((behaviac::Agent*)parHolder);

		this->Set(parent, &v, typeId);
	}

	virtual bool       Equal(const CTagObject* lhs, const CTagObject* rhs) const
	{
		const MemberType& l_v = *(const MemberType*)this->Get(lhs, GetClassTypeNumberId<MemberType>());
		const MemberType& r_v = *(const MemberType*)this->Get(rhs, GetClassTypeNumberId<MemberType>());

		return behaviac::Details::Equal(l_v, r_v);
	}

	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		typedef PARAM_BASETYPE(MemberType)				StoredMemberType;

		behaviac::Property* pProperty = behaviac::Property::Creator<StoredMemberType>(defaultValue, this, bConst);

		return pProperty;
	}

	virtual float DifferencePercentage(const behaviac::Property* l, const behaviac::Property* r)
	{
		return TDifferencePercentage<MemberType>(l, r);
	}

private:
	MemberType ObjectType::*    m_memberPtr;
	UiGenericType*              m_uiWrapper;
};


template<class MemberType, class MemberHandler, uint32_t PropertyFlags>
class CStaticMember : public CMemberBase
{
public:
	BEHAVIAC_DECLARE_MEMORY_OPERATORS(CStaticMember);

	CStaticMember(MemberType *memberPtr, const char* className, const char* propertyName, UiGenericType* uiWrapper) : CMemberBase(propertyName, className), m_memberPtr(memberPtr), m_uiWrapper(uiWrapper)
	{
		m_bStatic = true;
	}

	CStaticMember(const CStaticMember& copy) : CMemberBase(copy), m_memberPtr(copy.m_memberPtr), m_uiWrapper(copy.m_uiWrapper)
	{}

	virtual CMemberBase* clone() const
	{
		CMemberBase* p = BEHAVIAC_NEW CStaticMember(*this);

		return p;
	}

	virtual void Load(CTagObject* parent, const ISerializableNode* node)
	{
		BEHAVIAC_UNUSED_VAR(parent);

		if (PropertyFlags & EPersistenceType_Description_Load)
		{
			MemberHandler::Load(node, *m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void Save(const CTagObject* parent, ISerializableNode* node)
	{
		BEHAVIAC_UNUSED_VAR(parent);

		if (PropertyFlags & EPersistenceType_Description_Save)
		{
			MemberHandler::Save(node, *m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void LoadState(CTagObject* parent, const ISerializableNode* node)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(node);

		if (PropertyFlags & EPersistenceType_State_Load)
		{
			MemberHandler::LoadState(node, *m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void SaveState(const CTagObject* parent, ISerializableNode* node)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(node);

		if (PropertyFlags & EPersistenceType_State_Save)
		{
			MemberHandler::SaveState(node, *m_memberPtr, this->m_classFullName, m_propertyID);
		}
	}

	virtual void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);
		if (PropertyFlags & EPersistenceType_UiInfo)
		{
			MemberHandler::GetUiInfo(types, xmlNode, *m_memberPtr, m_bStatic, this->m_classFullName, m_propertyID, this->GetDisplayName(), this->GetDesc(), m_uiWrapper);
		}
	}

	virtual void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const CTagObject* parent, const XmlNodeRef& xmlNode)
	{
		BEHAVIAC_UNUSED_VAR(parent);

		MemberHandler::GetMethodsDescription(types, xmlNode, *m_memberPtr, this->m_classFullName, m_propertyID.GetString());
	}

	virtual void Set(const CTagObject* parent, const void* value, int typeId) const
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(typeId);
		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);

		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			*m_memberPtr = *((MemberType*)value);
		}
	}

	virtual void* Get(const CTagObject* parent, int typeId) const
	{
		BEHAVIAC_UNUSED_VAR(parent);

		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);

		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			return &(*m_memberPtr);
		}

		return 0;
	}

	virtual void        SetVariable(const CTagObject* parent, const void* value, int typeId) const
	{
		BEHAVIAC_UNUSED_VAR(typeId);

		BEHAVIAC_ASSERT(::GetClassTypeNumberId<MemberType>() == typeId);
		if (::GetClassTypeNumberId<MemberType>() == typeId)
		{
			behaviac::Agent* pAgent = (behaviac::Agent*)parent;
			const MemberType& v = *(MemberType*)value;

			const char* propertyName = m_propertyID.GetString();
			//pAgent->SetVariable(propertyName, v);
			pAgent->SetVariableRegistry(this, propertyName, v, this->m_classFullName, this->m_propertyID.GetID().GetUniqueID());

			//behaviac::NetworkRole netRole = this->GetNetRole();

			//if (netRole != behaviac::NET_ROLE_DEFAULT)
			//{
			//	behaviac::Network* pNw = behaviac::Network::GetInstance();

			//	if (pNw && !pNw->IsSinglePlayer())
			//	{
			//		if (netRole == behaviac::NET_ROLE_AUTHORITY && !pNw->IsAuthority() ||
			//			netRole == behaviac::NET_ROLE_NONAUTHORITY && pNw->IsAuthority())
			//		{
			//			pNw->ReplicateVariable(this->m_classFullName, propertyName, typeId, (void*)&v, true);
			//		}
			//	}
			//}
		}
	}
#if BEHAVIAC_ENABLE_NETWORKD
	virtual void ReplicateProperty(behaviac::Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);

		const char* propertyName = m_propertyID.GetString();
		behaviac::NetworkRole netRole = this->NETROLE();

		if (netRole != behaviac::NET_ROLE_DEFAULT)
		{
			behaviac::Network* pNw = behaviac::Network::GetInstance();

			if (pNw && !pNw->IsSinglePlayer())
			{
				bool bSend = false;
				bool bReceive = false; 

				if (pNw->IsAuthority())
				{
					if (netRole == behaviac::NET_ROLE_NONAUTHORITY)
					{
						bSend = true;
					}
					else if (netRole == behaviac::NET_ROLE_AUTHORITY)
					{
						bReceive = true;
					}
				}
				else
				{
					if (netRole == behaviac::NET_ROLE_AUTHORITY)
					{
						bSend = true;
					}
					else if (netRole == behaviac::NET_ROLE_NONAUTHORITY)
					{
						bReceive = true;
					}
				}

				if (bSend || bReceive)
				{
					int typeId = GetClassTypeNumberId<MemberType>();

					pNw->ReplicateVariable(this->m_classFullName, propertyName, typeId, (void*)&(*m_memberPtr), bSend);
				}
			}
		}	
	}
#endif//#if BEHAVIAC_ENABLE_NETWORKD
	virtual void*       GetVariable(const CTagObject* parent, int typeId) const
	{
		BEHAVIAC_UNUSED_VAR(parent);
		BEHAVIAC_UNUSED_VAR(typeId);

		BEHAVIAC_ASSERT(!"Only works with CGenericMembers");
		return NULL;
	}

	virtual int GetTypeId() const
	{
		return ::GetClassTypeNumberId<MemberType>();
	}

	virtual void SetFromProperty(CTagObject* parent, const CTagObject* parHolder, const behaviac::Property* pProperty) const
	{
		int typeId = this->GetTypeId();
		BEHAVIAC_ASSERT(pProperty->GetTypeId() == typeId);

		const behaviac::TProperty<MemberType>* pTProperty = (const behaviac::TProperty<MemberType>*)pProperty;
		const MemberType& v = pTProperty->GetValue((behaviac::Agent*)parHolder);

		this->Set(parent, &v, typeId);
	}

	virtual bool       Equal(const CTagObject* lhs, const CTagObject* rhs) const
	{
		const MemberType& l_v = *(const MemberType*)this->Get(lhs, GetClassTypeNumberId<MemberType>());
		const MemberType& r_v = *(const MemberType*)this->Get(rhs, GetClassTypeNumberId<MemberType>());

		return behaviac::Details::Equal(l_v, r_v);
	}


	virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
	{
		// typedef PARAM_BASETYPE(MemberType)				StoredMemberType;
		behaviac::Property* pProperty = behaviac::Property::Creator<MemberType>(defaultValue, this, bConst);

		return pProperty;
	}

	virtual float DifferencePercentage(const behaviac::Property* l, const behaviac::Property* r)
	{
		return TDifferencePercentage<MemberType>(l, r);
	}

private:
	MemberType*				m_memberPtr;
	UiGenericType*          m_uiWrapper;
};



BEHAVIAC_FORCEINLINE CMemberBase& _addMember(CTagObject::MembersContainer& members, CMemberBase* _member)
{
	members.membersVector.push_back(_member);
	members.membersMap[_member->GetID().GetID()] = _member;
	return *_member;
}


namespace CMemberFactory
{
	template<template <class T> class MemberHandler, uint32_t PropertyFlags, class ObjectType, class MemberType>
	static CMemberBase* Create(const char* className, const char* propertyName, MemberType ObjectType::* memberPtr, UiGenericType* uiWrapper)
	{
		BEHAVIAC_UNUSED_VAR(className);
		typedef CGenericMember<ObjectType, MemberType, MemberHandler<MemberType>, PropertyFlags> MemberTypeType;
		return BEHAVIAC_NEW MemberTypeType(memberPtr, className, propertyName, uiWrapper);
	}

	template<template <class T> class MemberHandler, uint32_t PropertyFlags, class MemberType>
	static CMemberBase* Create(const char* className, const char* propertyName, MemberType * memberPtr, UiGenericType* uiWrapper)
	{
		BEHAVIAC_UNUSED_VAR(className);
		typedef CStaticMember<MemberType, MemberHandler<MemberType>, PropertyFlags> MemberTypeType;
		return BEHAVIAC_NEW MemberTypeType(memberPtr, className, propertyName, uiWrapper);
	}

	template<class MemberHandler, uint32_t PropertyFlags, class ObjectType, class MemberType>
	static CMemberBase* Create(const char* className, const char* propertyName, MemberType ObjectType::* memberPtr, UiGenericType* uiWrapper)
	{
		BEHAVIAC_UNUSED_VAR(className);
		typedef CGenericMember<ObjectType, MemberType, MemberHandler, PropertyFlags> MemberTypeType;
		return BEHAVIAC_NEW MemberTypeType(memberPtr, className, propertyName, uiWrapper);
	}
};

#include "behaviac/base/object/uitype.h"
#include "behaviac/base/object/groupmember.h"
#include "behaviac/base/object/serializationevent.h"
#include "behaviac/base/object/containermember.h"
#include "behaviac/base/object/containermemberex.h"

// Macros for register_member description
#define UIDescription_Add(description) UiBasicType(Ui_None, description)
///////////////////////////////////////

#endif // #ifndef _ENGINESERVICES_GENERICMEMBER_H_
