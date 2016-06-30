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

#ifndef BEHAVIAC_ENGINESERVICES_GROUPMEMBER_H
#define BEHAVIAC_ENGINESERVICES_GROUPMEMBER_H

#include "behaviac/base/object/tagobject.h"

////////////////////////////////////////////////////////////////////////////////
//////////////////////            GROUP MEMBER            //////////////////////
////////////////////////////////////////////////////////////////////////////////
// Logical grouping of members. Simply overloads ms_members in a local scope and
// therefore supports any type of member as its children, including other groups.
////////////////////////////////////////////////////////////////////////////////

#define BEGIN_GROUP_MEMBER(groupName, propertyFlags) \
    { \
        typedef CGroupMember<CreateChildNode, propertyFlags> MemberType; \
        MemberType* property_ = BEHAVIAC_NEW MemberType(groupName, objectType::GetClassTypeName()); \
        behaviac::CTagObjectDescriptor::PushBackMember(ms_members, property_); \
        { \
            ms_members = property_->GetMembers();

#define END_GROUP_MEMBER() \
    } \
    }

template <bool ChildNodeCreate, uint32_t PropertyFlags>
class CGroupMember : public behaviac::CMemberBase
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CGroupMember);

    CGroupMember(const char* groupName, const char* className)
        : behaviac::CMemberBase(groupName, className)
    {}

    CGroupMember(const CGroupMember& copy) : behaviac::CMemberBase(copy), ms_members(copy.ms_members)
    {}

    virtual behaviac::CMemberBase* clone() const
    {
        behaviac::CMemberBase* p = BEHAVIAC_NEW CGroupMember(*this);

        return p;
    }

    virtual void Load(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
    {
        if (PropertyFlags & behaviac::EPersistenceType_Description_Load)
        {
            const behaviac::ISerializableNode* groupNode;

            if (ChildNodeCreate)
            {
                groupNode = node->findChild(m_propertyID);

            }
            else
            {
                groupNode = node;
            }

            if (groupNode)
            {
                behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator it = ms_members.membersVector.begin();
                behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = ms_members.membersVector.end();

                for (; it != itEnd; ++it)
                {
                    behaviac::CMemberBase* m = *it;
                    m->Load(parent, groupNode);
                }
            }
        }
    }

    virtual void Save(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
    {
        if (PropertyFlags & behaviac::EPersistenceType_Description_Save)
        {
            behaviac::ISerializableNode* groupNode;

            if (ChildNodeCreate)
            {
                groupNode = node->newChild(m_propertyID);

            }
            else
            {
                groupNode = node;
            }

            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator it = ms_members.membersVector.begin();
            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = ms_members.membersVector.end();

            for (; it != itEnd; ++it)
            {
                behaviac::CMemberBase* m = *it;
                m->Save(parent, groupNode);
            }
        }
    }

    virtual void LoadState(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
    {
        if (PropertyFlags & behaviac::EPersistenceType_State_Load)
        {
            const behaviac::ISerializableNode* groupNode;

            if (ChildNodeCreate)
            {
                groupNode = node->findChild(m_propertyID);

            }
            else
            {
                groupNode = node;
            }

            if (groupNode)
            {
                behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator it = ms_members.membersVector.begin();
                behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = ms_members.membersVector.end();

                for (; it != itEnd; ++it)
                {
                    behaviac::CMemberBase* m = *it;
                    m->LoadState(parent, groupNode);
                }
            }
        }
    }

    virtual void SaveState(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
    {
        if (PropertyFlags & behaviac::EPersistenceType_State_Save)
        {
            behaviac::ISerializableNode* groupNode;

            if (ChildNodeCreate)
            {
                groupNode = node->newChild(m_propertyID);

            }
            else
            {
                groupNode = node;
            }

            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator it = ms_members.membersVector.begin();
            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = ms_members.membersVector.end();

            for (; it != itEnd; ++it)
            {
                behaviac::CMemberBase* m = *it;
                m->SaveState(parent, groupNode);
            }
        }
    }

    virtual void GetUiInfo(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
    {
        if (PropertyFlags & behaviac::EPersistenceType_UiInfo)
        {
            behaviac::XmlNodeRef groupNode = xmlNode;

            if (ChildNodeCreate && types == NULL)
            {
                groupNode = xmlNode->newChild("Member");
                groupNode->setAttr("Name", m_propertyID.GetString());

                if (this->m_classFullName)
                {
                    groupNode->setAttr("Class", this->m_classFullName);
                }

                if (m_bStatic)
                {
                    groupNode->setAttr("Static", "true");
                }
            }

            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator it = ms_members.membersVector.begin();
            behaviac::CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = ms_members.membersVector.end();

            for (; it != itEnd; ++it)
            {
                behaviac::CMemberBase* m = *it;
                m->GetUiInfo(types, parent, groupNode);
            }
        }
    }

    virtual void GetMethodsDescription(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
    {
        BEHAVIAC_UNUSED_VAR(parent);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(types);

        BEHAVIAC_ASSERT(false, "Not implemented");
    }

    behaviac::CTagObject::MembersContainer& GetMembers()
    {
        return ms_members;
    }

private:
    behaviac::CTagObject::MembersContainer ms_members;
};

////////////////////////////////////////////////////////////////////////////////
////////////////            CONDITIONAL GROUP MEMBER            ////////////////
////////////////////////////////////////////////////////////////////////////////
// Conditional group member, same as preceding except it evaluates the given
// condition function to determine if it serializes itself or not.
////////////////////////////////////////////////////////////////////////////////
#define BEGIN_CONDITIONAL_GROUP_MEMBER(groupName, conditionalName, propertyFlags, createChildNode) \
    { \
        typedef CConditionalGroupMember<objectType, createChildNode, propertyFlags> MemberType; \
        MemberType* property_ = BEHAVIAC_NEW MemberType(groupName, &objectType::conditionalName); \
        behaviac::CTagObjectDescriptor::PushBackMember(ms_members, property_); \
        { \
            behaviac::CTagObject::MembersContainer& ms_members = property_->GetMembers();

template <class ObjectType, bool ChildNodeCreate, uint32_t PropertyFlags>
class CConditionalGroupMember : public CGroupMember<ChildNodeCreate, PropertyFlags>
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CConditionalGroupMember);

    CConditionalGroupMember(const char* groupName, bool (ObjectType::*condition)(void) const)
        : CGroupMember<ChildNodeCreate, PropertyFlags>(groupName), m_condition(condition)
    {}

    virtual void Load(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
    {
        if ((PropertyFlags & behaviac::EPersistenceType_Description_Load) && (((ObjectType*)parent)->*m_condition)())
        {
            CGroupMember<ChildNodeCreate, PropertyFlags>::Load(parent, node);
        }
    }

    virtual void Save(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
    {
        if ((PropertyFlags & behaviac::EPersistenceType_Description_Save) && (((ObjectType*)parent)->*m_condition)())
        {
            CGroupMember<ChildNodeCreate, PropertyFlags>::Save(parent, node);
        }
    }

    virtual void LoadState(behaviac::CTagObject* parent, const behaviac::ISerializableNode* node)
    {
        if ((PropertyFlags & behaviac::EPersistenceType_State_Load) && (((ObjectType*)parent)->*m_condition)())
        {
            CGroupMember<ChildNodeCreate, PropertyFlags>::LoadState(parent, node);
        }
    }

    virtual void SaveState(const behaviac::CTagObject* parent, behaviac::ISerializableNode* node)
    {
        if ((PropertyFlags & behaviac::EPersistenceType_State_Save) && (((ObjectType*)parent)->*m_condition)())
        {
            CGroupMember<ChildNodeCreate, PropertyFlags>::SaveState(parent, node);
        }
    }

    virtual void GetUiInfo(behaviac::CTagTypeDescriptor::TypesMap_t* types, const behaviac::CTagObject* parent, const behaviac::XmlNodeRef& xmlNode)
    {
        if ((PropertyFlags & behaviac::EPersistenceType_UiInfo) && (((ObjectType*)parent)->*m_condition)())
        {
            CGroupMember<ChildNodeCreate, PropertyFlags>::GetUiInfo(types, parent, xmlNode);
        }
    }

private:
    bool (ObjectType::*m_condition)(void) const;
};

#endif // #ifndef BEHAVIAC_ENGINESERVICES_GROUPMEMBER_H
