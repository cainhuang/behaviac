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

#ifndef _ENGINESERVICES_ENTITYIDTYPEHANDLER_H_
#define _ENGINESERVICES_ENTITYIDTYPEHANDLER_H_

#include "behaviac/base/entity/entityid.h"
#include "behaviac/base/object/typehandler.h"

template <class TParentType, class TContainerType>
class CEmptyPredicate<TParentType, TContainerType, EntityId>
{
public:
	static bool IsEmpty(const EntityId& element)
	{
		return (element.GetUniqueID() == EntityId::InvalidEntityId || element.GetUniqueID() == -1);
	}
};

template <>
struct GenericTypeHandler<EntityId>
{
	static bool Load(const ISerializableNode* node, EntityId& member, const CSerializationID& propertyID)
	{
		EntityId::IdType tempValue;

		if (GenericTypeHandler<EntityId::IdType>::Load(node, tempValue, propertyID))
		{
			member = EntityId(tempValue);
			return true;
		}

		return false;
	}

	static void Save(ISerializableNode* node, const EntityId& member, const CSerializationID& propertyID)
	{
		GenericTypeHandler<EntityId::IdType>::Save(node, member.GetUniqueID(), propertyID);
	}

	static bool LoadState(const ISerializableNode* node, EntityId& member, const CSerializationID& propertyID)
	{
		return Load(node, member, propertyID);
	}

	static void SaveState(ISerializableNode* node, const EntityId& member, const CSerializationID& propertyID)
	{
		Save(node, member, propertyID);
	}

	static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const EntityId& member, const char* className, const char* classFullName, const CSerializationID& propertyID, UiGenericType* uiWrapper)
	{
		if (types == NULL)
		{
			XmlNodeRef memberNode = xmlNode->newChild("Member");
			memberNode->setAttr("Name", propertyID.GetString());
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());
			memberNode->setAttr("Type", "EntityId");
			if (classFullName)
			{
				memberNode->setAttr("Class", classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			if (uiWrapper)
			{
				uiWrapper->SaveDescription(memberNode);
			}
		}
	}

	static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const EntityId& member, const char* propertyName)
	{
		BEHAVIAC_UNUSED_VAR(types);
		BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
	}
};


template <>
struct NoChildTypeHandler<EntityId>
{
	static bool Load(const ISerializableNode* node, EntityId& member, const CSerializationID& propertyID)
	{
		EntityId::IdType tempValue;

		if (GenericTypeHandler<EntityId::IdType>::Load(node, tempValue, propertyID))
		{
			member = EntityId(tempValue);
			return true;
		}

		return false;
	}

	static void Save(ISerializableNode* node, const EntityId& member, const CSerializationID& propertyID)
	{
		GenericTypeHandler<EntityId::IdType>::Save(node, member.GetUniqueID(), propertyID);
	}

	static bool LoadState(const ISerializableNode* node, EntityId& member, const CSerializationID& propertyID)
	{
		return Load(node, member, propertyID);
	}

	static void SaveState(ISerializableNode* node, const EntityId& member, const CSerializationID& propertyID)
	{
		Save(node, member, propertyID);
	}

	static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const EntityId& member, const char* className, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
	{
		if (types == NULL)
		{
			XmlNodeRef memberNode = xmlNode->newChild("Member");
			memberNode->setAttr("Name", propertyID.GetString());
			memberNode->setAttr("DisplayName", this->GetDisplayName());
			memberNode->setAttr("Desc", this->GetDesc());
			memberNode->setAttr("Type", "EntityId");
			if (classFullName)
			{
				memberNode->setAttr("Class", classFullName);
			}
			if (m_bStatic)
			{
				memberNode->setAttr("Static", "true");
			}

			if (uiWrapper)
			{
				uiWrapper->SaveDescription(memberNode);
			}
		}
	}

	static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const EntityId& member, const char* propertyName)
	{
		BEHAVIAC_UNUSED_VAR(types);
		BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
	}
};

#endif // #ifndef _ENGINESERVICES_ENTITYIDTYPEHANDLER_H_
