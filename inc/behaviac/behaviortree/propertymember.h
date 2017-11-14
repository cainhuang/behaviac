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

#ifndef BEHAVIORTREE_PROPERTYMEMMBER_H
#define BEHAVIORTREE_PROPERTYMEMMBER_H

namespace behaviac {
	template<>
	struct GenericTypeHandler<behaviac::Property*>
	{
		static void Load(const behaviac::ISerializableNode* node, behaviac::Property* member, const char* className, const behaviac::CSerializationID& propertyID)
		{
			BEHAVIAC_UNUSED_VAR(node);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(className);
			BEHAVIAC_UNUSED_VAR(propertyID);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		static void Save(behaviac::ISerializableNode* node, behaviac::Property* member, const char* className, const behaviac::CSerializationID& propertyID)
		{
			BEHAVIAC_UNUSED_VAR(node);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(className);
			BEHAVIAC_UNUSED_VAR(propertyID);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		static void LoadState(const behaviac::ISerializableNode* node, behaviac::Property* member, const char* className, const behaviac::CSerializationID& propertyID)
		{
			BEHAVIAC_UNUSED_VAR(node);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(className);
			BEHAVIAC_UNUSED_VAR(propertyID);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		static void SaveState(behaviac::ISerializableNode* node, behaviac::Property* member, const char* className, const behaviac::CSerializationID& propertyID)
		{
			BEHAVIAC_UNUSED_VAR(node);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(className);
			BEHAVIAC_UNUSED_VAR(propertyID);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		static void GetUiInfo(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::XmlNodeRef& xmlNode, behaviac::Property* const& member, bool bStatic, int readonlyFlag, const char* classFullName, const behaviac::CSerializationID& propertyID, UiGenericType* uiWrapper)
		{
			BEHAVIAC_UNUSED_VAR(types);
			BEHAVIAC_UNUSED_VAR(xmlNode);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(bStatic);
			BEHAVIAC_UNUSED_VAR(classFullName);
			BEHAVIAC_UNUSED_VAR(propertyID);
			BEHAVIAC_UNUSED_VAR(uiWrapper);
			BEHAVIAC_UNUSED_VAR(readonlyFlag);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		static void GetMethodsDescription(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::XmlNodeRef& xmlNode, behaviac::Property* const& member, const char* className, const char* propertyName)
		{
			BEHAVIAC_UNUSED_VAR(types);
			BEHAVIAC_UNUSED_VAR(xmlNode);
			BEHAVIAC_UNUSED_VAR(member);
			BEHAVIAC_UNUSED_VAR(className);
			BEHAVIAC_UNUSED_VAR(propertyName);

			BEHAVIAC_ASSERT(0, "not implemented");
		}
	};

	//behaviac::Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);
	inline behaviac::Property* LoadProperty(const char* value)
	{
		behaviac::string typeName;
		behaviac::string propertyName;
		behaviac::Property* opr = behaviac::Condition::LoadRight(value, typeName);

		return opr;
	}

	template<class ObjectType, class MemberHandler, uint32_t PropertyFlags>
	class CGenericMember<ObjectType, behaviac::Property*, MemberHandler, PropertyFlags> : public behaviac::CMemberBase
	{
	public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(CGenericMember);

		CGenericMember(behaviac::Property * ObjectType::* memberPtr, const char* className, const char* propertyName, UiGenericType* uiWrapper) : behaviac::CMemberBase(propertyName, className), m_memberPtr(memberPtr), m_uiWrapper(uiWrapper)
		{
		}

		CGenericMember(const CGenericMember& copy) : behaviac::CMemberBase(copy), m_memberPtr(copy.m_memberPtr), m_uiWrapper(copy.m_uiWrapper)
		{}

		virtual behaviac::CMemberBase* clone() const
		{
			behaviac::CMemberBase* p = BEHAVIAC_NEW CGenericMember(*this);

			return p;
		}

		virtual void Load(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
		{
			if (PropertyFlags & behaviac::EPersistenceType_Description_Load)
			{
				const char* valueStr = node->getAttrRaw(m_propertyID);

				behaviac::string propertyName;
				((ObjectType*)parent)->*m_memberPtr = behaviac::LoadProperty(valueStr);
			}
		}

		virtual void Save(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(node);

			if (PropertyFlags & behaviac::EPersistenceType_Description_Save)
			{
				BEHAVIAC_ASSERT(0, "not implemented");
			}
		}

		virtual void LoadState(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(node);

			if (PropertyFlags & behaviac::EPersistenceType_State_Load)
			{
				BEHAVIAC_ASSERT(0, "not implemented");
			}
		}

		virtual void SaveState(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(node);

			if (PropertyFlags & behaviac::EPersistenceType_State_Save)
			{
				BEHAVIAC_ASSERT(0, "not implemented");
			}
		}

		virtual void GetUiInfo(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(xmlNode);
			BEHAVIAC_UNUSED_VAR(types);

			if (PropertyFlags & behaviac::EPersistenceType_UiInfo)
			{
				BEHAVIAC_ASSERT(0, "not implemented");
			}
		}

		virtual void GetMethodsDescription(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(xmlNode);
			BEHAVIAC_UNUSED_VAR(types);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		virtual void Set(const behaviac::CTagObject* parent, const void* value, int typeId) const
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(value);
			BEHAVIAC_UNUSED_VAR(typeId);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		virtual const void* Get(const behaviac::CTagObject* parent, int typeId) const
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(typeId);

			BEHAVIAC_ASSERT(0, "not implemented");
			return 0;
		}

		virtual void        SetVariable(const behaviac::CTagObject* parent, const void* value, int typeId) const
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(value);
			BEHAVIAC_UNUSED_VAR(typeId);

			BEHAVIAC_ASSERT(0, "not implemented");
		}

		virtual void*       GetVariable(const behaviac::CTagObject* parent, int typeId) const
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(typeId);

			BEHAVIAC_ASSERT(0, "not implemented");
			return NULL;
		};

		virtual int GetTypeId() const
		{
			BEHAVIAC_ASSERT(0, "not implemented");
			return 0;
		}

		virtual void SetFromProperty(behaviac::CTagObject* parent, const behaviac::CTagObject* parHolder, const behaviac::Property* pProperty) const
		{
			BEHAVIAC_UNUSED_VAR(parent);
			BEHAVIAC_UNUSED_VAR(parHolder);
			BEHAVIAC_UNUSED_VAR(pProperty);
			BEHAVIAC_ASSERT(0, "not implemented");
		}

		virtual bool       Equal(const behaviac::CTagObject* lhs, const behaviac::CTagObject* rhs) const
		{
			BEHAVIAC_UNUSED_VAR(lhs);
			BEHAVIAC_UNUSED_VAR(rhs);

			BEHAVIAC_ASSERT(0, "not implemented");
			return false;
		}

		virtual behaviac::Property* CreateProperty(const char* defaultValue, bool bConst) const
		{
			BEHAVIAC_UNUSED_VAR(defaultValue);
			BEHAVIAC_UNUSED_VAR(bConst);

			BEHAVIAC_ASSERT(0, "not implemented");
			return 0;
		}

	private:
		behaviac::Property* ObjectType::*    m_memberPtr;
		UiGenericType*						 m_uiWrapper;
	};
}//

#endif//BEHAVIORTREE_PROPERTYMEMMBER_H
