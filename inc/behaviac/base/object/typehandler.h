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

#ifndef BEHAVIAC_ENGINESERVICES_TYPEHANDLER_H
#define BEHAVIAC_ENGINESERVICES_TYPEHANDLER_H

#include "behaviac/base/serialization/serializablenode.h"
#include "behaviac/base/dynamictypefactory.h"
#include "behaviac/base/object/uitypeinterface.h"

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/object/tagobject.h"
#include "behaviac/base/meta/types.h"
#include "behaviac/property/vector_ext.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
enum ParentType
{
    PT_INVALID,
    PT_AGENT,
    PT_INSTANCE,
    PT_PAR
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void TGetUiInfo_(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode, const CTagObjectDescriptor& objDesc)
{
    if (types != NULL)
    {
        if (objDesc.ms_isInitialized)
        {
            const char* typeName = GetClassTypeName((T*)0);

            if (types->find(typeName) == types->end())
            {
                objDesc.GetMembersDescription(types, 0, memberNode);

                (*types)[typeName] = &objDesc;
            }
        }
    }
}

template <typename MemberType, bool bStruct>
struct ClassUiInfoGetterStruct
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        if (types != NULL)
        {
            RegisterPropertiesGetter<MemberType, false>::_RegisterProperties();
            const CTagObjectDescriptor& objDesc = ObjectDescriptorGettter<MemberType, false>::_GetObjectDescriptor();

            TGetUiInfo_<MemberType>(types, memberNode, objDesc);
        }
    }
};


template <bool bStruct>
struct ClassUiInfoGetterStruct<IList, bStruct>
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        if (types != NULL)
        {
            RegisterPropertiesGetter<IList, true>::_RegisterProperties();
            const CTagObjectDescriptor& objDesc = ObjectDescriptorGettter<IList, true>::_GetObjectDescriptor();

            TGetUiInfo_<IList>(types, memberNode, objDesc);
        }
    }
};

template <bool bStruct>
struct ClassUiInfoGetterStruct<System::Object, bStruct>
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        if (types != NULL)
        {
            RegisterPropertiesGetter<System::Object, true>::_RegisterProperties();
            const CTagObjectDescriptor& objDesc = ObjectDescriptorGettter<System::Object, true>::_GetObjectDescriptor();

            TGetUiInfo_<System::Object>(types, memberNode, objDesc);
        }
    }
};


template <typename MemberType>
struct ClassUiInfoGetterStruct<MemberType, true>
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        if (types != NULL)
        {
            const char* typeName = GetClassTypeName((MemberType*)0);

            if (types->find(typeName) == types->end())
            {
                RegisterPropertiesGetter<MemberType, true>::_RegisterProperties();
                const CTagObjectDescriptor& objDesc = ObjectDescriptorGettter<MemberType, true>::_GetObjectDescriptor();
                objDesc.GetMembersDescription(types, 0, memberNode);

                (*types)[typeName] = &objDesc;
            }
        }
    }
};

template <typename MemberType, bool bIsEnum>
struct EnumClassUiInfoGetter
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        ClassUiInfoGetterStruct<MemberType, behaviac::Meta::HasFromString<MemberType>::Result>::GetUiInfo(types, memberNode);
    }
};

template <typename MemberType>
struct EnumClassUiInfoGetter<MemberType, true>
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        BEHAVIAC_UNUSED_VAR(memberNode);

        if (types != NULL)
        {
            const char* typeName = GetClassTypeName((MemberType*)0);

            if (types->find(typeName) == types->end())
            {
                const EnumClassDescription_t& ecd = ::GetEnumClassValueNames((MemberType*)0);

                (*types)[typeName] = &ecd;
            }
        }
    }
};

template <typename MemberType, bool bIsVector>
struct VectorTypeUiInfoGetter
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        BEHAVIAC_UNUSED_VAR(memberNode);

        ClassUiInfoGetterStruct<MemberType, behaviac::Meta::HasFromString<MemberType>::Result>::GetUiInfo(types, memberNode);
    }
};

template <typename MemberType>
struct VectorTypeUiInfoGetter<MemberType, true>
{
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, XmlNodeRef& memberNode)
    {
        typedef typename behaviac::Meta::IsVector<MemberType>::ElementType ElementType_t;

        ClassUiInfoGetterStruct<ElementType_t, behaviac::Meta::HasFromString<ElementType_t>::Result>::GetUiInfo(types, memberNode);
    }
};

/////////////////////////////////////////////////////////
///////////////     GENERIC HANDLER      ////////////////
/////////////////////////////////////////////////////////

template<class MemberType>
struct GenericTypeHandler
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        // If property ID is empty use the current node to load
        const ISerializableNode* memberNode = (propertyID.GetID().IsValid()) ? node->findChild(propertyID) : node;

        if (memberNode)
        {
            member.Load(memberNode);
            return true;
        }

        return false;
    }

    static void Save(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        // Create a new node if the property ID is not empty, otherwise serialize it to the current node
        ISerializableNode* memberNode = (propertyID.GetID().IsValid()) ? node->newChild(propertyID) : node;
        member.Save(memberNode);
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        // If property ID is empty use the current node to load
        const ISerializableNode* memberNode = (propertyID.GetID().IsValid()) ? node->findChild(propertyID) : node;

        if (memberNode)
        {
            member.LoadState(memberNode);
            return true;
        }

        return false;
    }

    static void SaveState(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        // Create a new node if the property ID is not empty, otherwise serialize it to the current node
        ISerializableNode* memberNode = (propertyID.GetID().IsValid()) ? node->newChild(propertyID) : node;
        member.SaveState(memberNode);
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        // Create a new node if the property ID is not empty, otherwise serialize it to the current node
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            if (propertyID.GetID().IsValid())
            {
                memberNode = xmlNode->newChild("Member");
                memberNode->setAttr("Name", propertyID.GetString());
                memberNode->setAttr("DisplayName", displayName);
                memberNode->setAttr("Desc", desc);
                const behaviac::string memberTypeStr = ::GetTypeDescString<MemberType>();
                memberNode->setAttr("Type", memberTypeStr.c_str());

                if (classFullName)
                {
                    memberNode->setAttr("Class", classFullName);
                }

                if (bStatic)
                {
                    memberNode->setAttr("Static", "true");
                }

                if (readonlyFlag & 0x1)
                {
                    memberNode->setAttr("Readonly", "true");
                }

                if (readonlyFlag & 0x2)
                {
                    memberNode->setAttr("Property", "true");
                }

            }

        }
        else
        {
            const char* typeName = GetClassTypeName((MemberType*)0);

            if (types->find(typeName) == types->end())
            {
                member.GetMembersDescription(types, memberNode);

                (*types)[typeName] = &member.GetObjectDescriptor();
            }
        }

        if (uiWrapper)
        {
            uiWrapper->SaveDescription(memberNode);
        }
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        // TODO
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild(propertyName);
        }

        member.GetMethodsDescription(types, memberNode);
    }

    static void LoadFromXML(const ISerializableNode& xmlNode, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
        CSerializationID serializationId(propertyName);
        GenericTypeHandler<MemberType>::Load(&xmlNode, member, className, serializationId);
    }

    static void SaveToXML(ISerializableNode& xmlNode, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);
        BEHAVIAC_ASSERT(0, "unimplmented");
    }
};

template<class MemberType>
struct NoDescriptionTypeHandler
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        const ISerializableNode* memberNode = node->findChild(propertyID);

        if (memberNode)
        {
            member.Load(memberNode);
            return true;
        }

        return false;
    }

    static void Save(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        ISerializableNode* memberNode = node->newChild(propertyID);
        member.Save(memberNode);
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        const ISerializableNode* memberNode = node->findChild(propertyID);

        if (memberNode)
        {
            member.LoadState(memberNode);
            return true;
        }

        return false;
    }

    static void SaveState(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(member);

        ISerializableNode* memberNode = node->newChild(propertyID);
        member.SaveState(memberNode);
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(classFullName);
        BEHAVIAC_UNUSED_VAR(bStatic);
        BEHAVIAC_UNUSED_VAR(displayName);
        BEHAVIAC_UNUSED_VAR(desc);
        BEHAVIAC_UNUSED_VAR(uiWrapper);
        BEHAVIAC_UNUSED_VAR(propertyID);
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);
    }
};

template<class MemberType>
struct GenericTypeHandler<MemberType*>
{
    static void Load(const ISerializableNode* node, MemberType*& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            const ISerializableNode* memberNode = node->findChild(propertyID);

            if (memberNode)
            {
                member->Load(memberNode);

            }
            else
            {
                const char* valueStr = node->getAttrRaw(propertyID);

                if (valueStr && string_icmp(valueStr, "null") == 0)
                {
                    member = 0;
                }
            }
        }
    }

    template < typename T, bool bAgent >
    struct SaveSelector
    {
        static void Save(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
        {
            BEHAVIAC_UNUSED_VAR(node);
            BEHAVIAC_UNUSED_VAR(member);
            BEHAVIAC_UNUSED_VAR(className);
            BEHAVIAC_UNUSED_VAR(propertyID);

            if (member)
            {
                ISerializableNode* memberNode = node->newChild(propertyID);
                member->Save(memberNode);
            }
        }
    };

    template < typename T >
    struct SaveSelector < T, true >
    {
        static void Save(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
        {
            BEHAVIAC_UNUSED_VAR(node);
            BEHAVIAC_UNUSED_VAR(member);
            BEHAVIAC_UNUSED_VAR(className);
            BEHAVIAC_UNUSED_VAR(propertyID);

            //if (member)
            //{
            //	ISerializableNode* memberNode = node->newChild(propertyID);
            //	member->Save(memberNode);
            //}
        }
    };

    static void Save(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        SaveSelector<MemberType, behaviac::Meta::IsAgent<MemberType>::Result>::Save(node, member, className, propertyID);
    }

    static void LoadState(const ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            const ISerializableNode* memberNode = node->findChild(propertyID);

            if (memberNode)
            {
                member->LoadState(memberNode);
            }
        }
    }

    static void SaveState(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            ISerializableNode* memberNode = node->newChild(propertyID);
            member->SaveState(memberNode);
        }
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(classFullName);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (types == NULL)
        {
            XmlNodeRef memberNode = xmlNode->newChild("Member");
            memberNode->setAttr("Name", propertyID.GetString());
            memberNode->setAttr("DisplayName", displayName);
            memberNode->setAttr("Desc", desc);
            const behaviac::string memberTypeStr = ::GetTypeDescString<MemberType*>();
            memberNode->setAttr("Type", memberTypeStr.c_str());

            if (classFullName)
            {
                memberNode->setAttr("Class", classFullName);
            }

            if (bStatic)
            {
                memberNode->setAttr("Static", "true");
            }

            if (readonlyFlag & 0x1)
            {
                memberNode->setAttr("Readonly", "true");
            }

            if (readonlyFlag & 0x2)
            {
                memberNode->setAttr("Property", "true");
            }

            //if (member)
            //{
            //    member->GetMembersDescription(memberNode);
            //}

            if (uiWrapper)
            {
                uiWrapper->SaveDescription(memberNode);
            }
        }
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);

        // TODO
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild(propertyName);
        }

        member->GetMethodsDescription(types, memberNode);
    }

    static void SaveToXML(ISerializableNode& xmlNode, const MemberType* member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);
        BEHAVIAC_ASSERT(0, "unimplmented");
    }
};

template<class MemberType, uint32_t ArraySize >
struct GenericTypeHandler< MemberType[ArraySize] >
{
    typedef MemberType Array[ArraySize];

    static void Load(const ISerializableNode* node, Array& array, const CSerializationID& propertyID)
    {
        const ISerializableNode* arrayNode = node->findChild(propertyID);

        if (arrayNode)
        {
            for (uint32_t i = 0; i < ArraySize; ++i)
            {
                char name[16];
                string_sprintf(name, "Element%d", i);
                GenericTypeHandler< MemberType >::Load(arrayNode, array[i], name);
            }
        }
    }

    static void Save(ISerializableNode* node, Array& array, const CSerializationID& propertyID)
    {
        ISerializableNode* arrayNode = node->newChild(propertyID);

        for (uint32_t i = 0; i < ArraySize; ++i)
        {
            char name[16];
            string_sprintf(name, "Element%d", i);
            GenericTypeHandler< MemberType >::Save(arrayNode, array[i], name);
        }
    }

    static void LoadState(const ISerializableNode* node, Array& array, const CSerializationID& propertyID)
    {
        const ISerializableNode* arrayNode = node->findChild(propertyID);

        if (arrayNode)
        {
            for (uint32_t i = 0; i < ArraySize; ++i)
            {
                char name[16];
                string_sprintf(name, "Element%d", i);
                GenericTypeHandler< MemberType >::LoadState(arrayNode, array[i], name);
            }
        }
    }

    static void SaveState(ISerializableNode* node, const Array& array, const CSerializationID& propertyID)
    {
        ISerializableNode* arrayNode = node->newChild(propertyID);

        for (uint32_t i = 0; i < ArraySize; ++i)
        {
            char name[16];
            string_sprintf(name, "Element%d", i);
            GenericTypeHandler< MemberType >::SaveState(arrayNode, array[i], name);
        }
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const Array& array, const char* className, const char* classFullName, const CSerializationID& propertyID, UiGenericType* uiWrapper)
    {
        BEHAVIAC_ASSERT(!"Not implemented");
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const Array& array, const char* className, const char* propertyName)
    {
        BEHAVIAC_ASSERT(!"Not implemented");
    }
};

template<class MemberType>
struct GenericTypeHandler<behaviac::vector<MemberType> >
{
    typedef behaviac::vector<MemberType> Array;

    static void Load(const ISerializableNode* node, Array& _array, const CSerializationID& propertyID)
    {
        const ISerializableNode* arrayNode = node->findChild(propertyID);

        if (arrayNode)
        {
            uint32_t ArraySize;

            const IXmlNode* xmlNode = (IXmlNode*)arrayNode;
            xmlNode->getAttr("Count", ArraySize);

            _array.resize(ArraySize);

            for (uint32_t i = 0; i < ArraySize; ++i)
            {
                char name[16];
                string_sprintf(name, "Element%d", i);
                GenericTypeHandler< MemberType >::Load(arrayNode, _array[i], 0, name);
            }
        }
    }

    static void Save(ISerializableNode* node, Array& _array, const CSerializationID& propertyID)
    {
        ISerializableNode* arrayNode = node->newChild(propertyID);

        uint32_t ArraySize = _array.size();

        for (uint32_t i = 0; i < ArraySize; ++i)
        {
            char name[16];
            string_sprintf(name, "Element%d", i);
            GenericTypeHandler< MemberType >::Save(arrayNode, _array[i], 0, name);
        }
    }

    static void LoadState(const ISerializableNode* node, Array& _array, const CSerializationID& propertyID)
    {
        const ISerializableNode* arrayNode = node->findChild(propertyID);

        if (arrayNode)
        {
            uint32_t ArraySize = _array.size();

            for (uint32_t i = 0; i < ArraySize; ++i)
            {
                char name[16];
                string_sprintf(name, "Element%d", i);
                GenericTypeHandler< MemberType >::LoadState(arrayNode, _array[i], name);
            }
        }
    }

    static void SaveState(ISerializableNode* node, const Array& _array, const CSerializationID& propertyID)
    {
        ISerializableNode* arrayNode = node->newChild(propertyID);
        uint32_t ArraySize = _array.size();

        for (uint32_t i = 0; i < ArraySize; ++i)
        {
            char name[16];
            string_sprintf(name, "Element%d", i);
            GenericTypeHandler< MemberType >::SaveState(arrayNode, _array[i], name);
        }
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const Array& _array, const char* className, const char* classFullName, const CSerializationID& propertyID, UiGenericType* uiWrapper)
    {
        BEHAVIAC_ASSERT(!"Not implemented");
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const Array& _array, const char* className, const char* propertyName)
    {
        BEHAVIAC_ASSERT(!"Not implemented");
    }
};

#define DefaultTypeHandler GenericTypeHandler

/////////////////////////////////////////////////////////
///////////     NO CHILD TYPE HANDLER      //////////////
/////////////////////////////////////////////////////////

template<class MemberType>
struct NoChildTypeHandler
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        member.Load(node);
        return true;
    }

    static void Save(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        member.Save(node);
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        member.LoadState(node);
        return true;
    }

    static void SaveState(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        member.SaveState(node);
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(classFullName);
        BEHAVIAC_UNUSED_VAR(propertyID);
        BEHAVIAC_UNUSED_VAR(displayName);
        BEHAVIAC_UNUSED_VAR(desc);
        BEHAVIAC_UNUSED_VAR(uiWrapper);
        BEHAVIAC_UNUSED_VAR(bStatic);

        BEHAVIAC_ASSERT(!uiWrapper, "You cannot define UiInfo in a NoChild handler.\nProperty: %s", propertyID.GetString());
        member.GetMembersDescription(types, xmlNode);
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);

        // TODO
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild(propertyName);
        }

        member.GetMethodsDescription(types, memberNode);
    }
};

template<class MemberType>
struct NoChildTypeHandler<MemberType*>
{
    static void Load(const ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            member->Load(node);
        }
    }

    static void Save(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            member->Save(node);
        }
    }

    static void LoadState(const ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            member->LoadState(node);
        }
    }

    static void SaveState(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        if (member)
        {
            member->SaveState(node);
        }
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(classFullName);
        BEHAVIAC_UNUSED_VAR(propertyID);
        BEHAVIAC_UNUSED_VAR(displayName);
        BEHAVIAC_UNUSED_VAR(desc);
        BEHAVIAC_UNUSED_VAR(uiWrapper);

        BEHAVIAC_ASSERT(!uiWrapper, "You cannot define UiInfo in a NoChild handler.\nProperty: %s", propertyID.GetString());

        //if (member)
        //{
        //    member->GetMembersDescription(xmlNode);
        //}
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(className);

        // TODO
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild(propertyName);
        }

        member->GetMethodsDescription(types, memberNode);
    }
};

/////////////////////////////////////////////////////////
/////////////     BASIC TYPE HANDLER      ///////////////
/////////////////////////////////////////////////////////

template<class MemberType>
struct BasicTypeHandlerBase
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        return false;
    }

    static void Save(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);

        //if (className)
        //{
        //	behaviac::string propertyName = FormatString("%s::%s", className, propertyID.GetString());
        //	CSerializationID pId(propertyName.c_str());

        //	node->setAttr(pId, member);
        //}
        //else
        {
            node->setAttr(propertyID, member);
        }
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        return false;
    }

    static void SaveState(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        //if (className)
        //{
        //	behaviac::string propertyName = FormatString("%s::%s", className, propertyID.GetString());
        //	CSerializationID pId(propertyName.c_str());

        //	node->setAttr(pId, member);
        //}
        //else
        {
            node->setAttr(propertyID, member);
        }
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(member);

        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild("Member");
            memberNode->setAttr("Name", propertyID.GetString());
            memberNode->setAttr("DisplayName", displayName);
            memberNode->setAttr("Desc", desc);
            const behaviac::string memberTypeStr = ::GetTypeDescString<MemberType>();
            memberNode->setAttr("Type", memberTypeStr.c_str());

            if (classFullName)
            {
                memberNode->setAttr("Class", classFullName);
            }

            if (bStatic)
            {
                memberNode->setAttr("Static", "true");
            }

            if (readonlyFlag & 0x1)
            {
                memberNode->setAttr("Readonly", "true");
            }

            if (readonlyFlag & 0x2)
            {
                memberNode->setAttr("Property", "true");
            }

            if (uiWrapper)
            {
                uiWrapper->SaveDescription(memberNode);
            }
        }

        VectorTypeUiInfoGetter<MemberType, behaviac::Meta::IsVector<MemberType>::Result>::GetUiInfo(types, memberNode);
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);

        BEHAVIAC_ASSERT(0, "unimplmented");
    }

    static void LoadFromXML(const ISerializableNode& node, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
        CSerializationID serializationId(propertyName);
        GenericTypeHandler<MemberType>::Load(&node, member, className, serializationId);
    }

    static void SaveToXML(ISerializableNode& node, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
        CSerializationID serializationId(propertyName);
        GenericTypeHandler<MemberType>::Save(&node, member, className, serializationId);
    }
};

template<class MemberType>
struct BasicTypeHandlerNonConst : public BasicTypeHandlerBase<MemberType>
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        //if (className)
        //{
        //	behaviac::string propertyName = FormatString("%s::%s", className, propertyID.GetString());
        //	CSerializationID pId(propertyName.c_str());

        //	return node->getAttr(pId, member);
        //}
        //else
        {
            return node->getAttr(propertyID, member);
        }
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);

        //if (className)
        //{
        //	behaviac::string propertyName = FormatString("%s::%s", className, propertyID.GetString());
        //	CSerializationID pId(propertyName.c_str());

        //	return node->getAttr(pId, member);
        //}
        //else
        {
            return node->getAttr(propertyID, member);
        }
    }


};

template<class MemberType>
struct BasicTypeHandlerConst : public BasicTypeHandlerBase<MemberType>
{
};

template<class MemberType, bool bIsConst>
struct BasicTypeHandlerSelector
{
    typedef BasicTypeHandlerNonConst<MemberType> BasicTypeHandler;
};

template<class MemberType>
struct BasicTypeHandlerSelector<MemberType, true>
{
    typedef BasicTypeHandlerConst<MemberType> BasicTypeHandler;
};

template<class MemberType>
struct BasicTypeHandler : public BasicTypeHandlerSelector<MemberType, behaviac::Meta::IsConst<MemberType>::Result>::BasicTypeHandler
{
};

template<class MemberType>
struct BasicTypeHandlerEnum
{
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);

        return node->getAttr(propertyID, member);
    }

    static void Save(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);

        node->setAttr(propertyID, member);
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        return node->getAttr(propertyID, member);
    }

    static void SaveState(ISerializableNode* node, const MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(className);
        node->setAttr(propertyID, member);
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(classFullName);
        BEHAVIAC_UNUSED_VAR(member);

        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild("Member");
            memberNode->setAttr("Name", propertyID.GetString());
            memberNode->setAttr("DisplayName", displayName);
            memberNode->setAttr("Desc", desc);

            const char* memberTypeName = ::GetClassTypeName((MemberType*)0);
            memberNode->setAttr("Type", memberTypeName);

            if (classFullName)
            {
                memberNode->setAttr("Class", classFullName);
            }

            if (bStatic)
            {
                memberNode->setAttr("Static", "true");
            }

            if (readonlyFlag & 0x1)
            {
                memberNode->setAttr("Readonly", "true");
            }

            if (readonlyFlag & 0x2)
            {
                memberNode->setAttr("Property", "true");
            }

            if (uiWrapper)
            {
                uiWrapper->SaveDescription(memberNode);
            }
        }

        EnumClassUiInfoGetter<MemberType, behaviac::Meta::IsEnum<MemberType>::Result>::GetUiInfo(types, memberNode);
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyName);
    }

    static void LoadFromXML(const ISerializableNode& node, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
        CSerializationID serializationId(propertyName);
        GenericTypeHandler<MemberType>::Load(&node, member, className, serializationId);
    }

    static void SaveToXML(ISerializableNode& node, MemberType& member, const char* className, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);
        CSerializationID serializationId(propertyName);
        GenericTypeHandler<MemberType>::Save(&node, member, className, serializationId);
    }
};

#define SPECIALIZE_TYPE_HANDLER(typeToSpecialize, specializedHandler) \
    template<>  struct GenericTypeHandler< typeToSpecialize > : public specializedHandler{}; \
    template<>  struct NoChildTypeHandler< typeToSpecialize > : public specializedHandler{};

// Specialize types supported by the ixml interface
SPECIALIZE_TYPE_HANDLER(const char*, BasicTypeHandler<const char*>)
SPECIALIZE_TYPE_HANDLER(char*, BasicTypeHandler<char*>)

#undef M_PRIMITE_TYPE
#define M_PRIMITE_TYPE(type, typeNameStr)														\
    SPECIALIZE_TYPE_HANDLER(type, BasicTypeHandler<type>);										\
    SPECIALIZE_TYPE_HANDLER(const type, BasicTypeHandler<const type>);							\
    SPECIALIZE_TYPE_HANDLER(const type&, BasicTypeHandler<const type>);							\
    SPECIALIZE_TYPE_HANDLER(behaviac::vector<type>, BasicTypeHandler<behaviac::vector<type> >)	\
    SPECIALIZE_TYPE_HANDLER(std::vector<type>, BasicTypeHandler<std::vector<type> >)

M_PRIMITIVE_TYPES();

#undef M_SPECIALIZE_TYPE_HANDLER
#define M_SPECIALIZE_TYPE_HANDLER(type)		\
    M_PRIMITE_TYPE(type, #type)				\
    BEHAVIAC_OVERRIDE_TYPE_NAME(type);

#define M_SPECIALIZE_TYPE_HANDLER_COMPOUND()			\
    M_SPECIALIZE_TYPE_HANDLER(CStringID);				\
    M_SPECIALIZE_TYPE_HANDLER(CNoCaseStringID);			\
    M_SPECIALIZE_TYPE_HANDLER(CPathID);

M_SPECIALIZE_TYPE_HANDLER_COMPOUND()

/////////////////////////////////////////////////////////////////
///////////     'NOT IMPLEMENTED' STATE HANDLER      ////////////
/////////////////////////////////////////////////////////////////

// Inherit from this to implement only necessary functions
template <class MemberType>
class CNotImplementedTypeHandler
{
public:
    static bool Load(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        BEHAVIAC_LOGERROR("Not implemented");
        return false;
    }

    static void Save(ISerializableNode* node, MemberType const& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        BEHAVIAC_LOGERROR("Not implemented");
    }

    static bool LoadState(const ISerializableNode* node, MemberType& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        BEHAVIAC_LOGERROR("Not implemented");
        return false;
    }

    static void SaveState(ISerializableNode* node, MemberType const& member, const char* className, const CSerializationID& propertyID)
    {
        BEHAVIAC_UNUSED_VAR(node);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        BEHAVIAC_LOGERROR("Not implemented");
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType const& member, const char* className, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(className);
        BEHAVIAC_UNUSED_VAR(propertyID);

        BEHAVIAC_LOGERROR("Not implemented");
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType const& member, const char* propertyName)
    {
        BEHAVIAC_UNUSED_VAR(types);
        BEHAVIAC_UNUSED_VAR(xmlNode);
        BEHAVIAC_UNUSED_VAR(member);
        BEHAVIAC_UNUSED_VAR(propertyName);

        BEHAVIAC_LOGERROR("Not implemented");
    }
};

/////////////////////////////////////////////////////////////////
///////////////         HANDLER GUESSER         /////////////////
/////////////////////////////////////////////////////////////////

// This is a utility class to avoid explicit specification of the type the
// handler must take, it will instead be deduced from the function argument.
template <template <class T> class MemberHandler>
class CHandlerGuesser
{
public:
    template <class offsetmemberType>
    static void Load(const ISerializableNode* node, offsetmemberType& offsetmember, const char* className, const CSerializationID& propertyID)
    {
        MemberHandler<offsetmemberType>::Load(node, offsetmember, className, propertyID);
    }

    template <class offsetmemberType>
    static void Save(ISerializableNode* node, const offsetmemberType& offsetmember, const char* className, const CSerializationID& propertyID)
    {
        MemberHandler<offsetmemberType>::Save(node, offsetmember, className, propertyID);
    }

    template <class offsetmemberType>
    static void LoadState(const ISerializableNode* node, offsetmemberType& offsetmember, const char* className, const CSerializationID& propertyID)
    {
        MemberHandler<offsetmemberType>::LoadState(node, offsetmember, className, propertyID);
    }

    template <class offsetmemberType>
    static void SaveState(ISerializableNode* node, const offsetmemberType& offsetmember, const char* className, const CSerializationID& propertyID)
    {
        MemberHandler<offsetmemberType>::SaveState(node, offsetmember, className, propertyID);
    }

    template <class offsetmemberType>
    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const offsetmemberType& offsetmember, bool bStatic, int readonlyFlag, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        MemberHandler<offsetmemberType>::GetUiInfo(types, xmlNode, offsetmember, bStatic, readonlyFlag, classFullName, propertyID, displayName, desc, uiWrapper);
    }

    template <class offsetmemberType>
    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, const offsetmemberType& offsetmember, const char* className, const char* propertyName)
    {
        MemberHandler<offsetmemberType>::GetMethodsDescription(types, xmlNode, offsetmember, className, propertyName);
    }
};

//---------------------------------------------------------------------------------------
// Non Virtual Pointer Type Handler
// This handler can serialize pointer to objects that do not use inheritance.
// By that I mean that if the pointer is of type T* the object must be of type T, and
// NOT a derived type of type T.
//---------------------------------------------------------------------------------------
template<class MemberType>
struct NoVirtualPointerTypeHandler : public CNotImplementedTypeHandler<MemberType>
{
};

template<class MemberType>
struct NoVirtualPointerTypeHandler<MemberType*>
{
    static void Load(const ISerializableNode* node, MemberType*& member, const char* className, const CSerializationID& propertyID)
    {
        member = BEHAVIAC_NEW MemberType;
        const ISerializableNode* memberNode = propertyID.GetID().IsValid() ? node->findChild(propertyID) : node;

        if (memberNode)
        {
            member->Load(memberNode);
        }
    }

    static void Save(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        if (member)
        {
            ISerializableNode* memberNode = propertyID.GetID().IsValid() ? node->newChild(propertyID) : node;
            member->Save(memberNode);
        }
    }

    static void LoadState(const ISerializableNode* node, MemberType*& member, const char* className, const CSerializationID& propertyID)
    {
        // Currently not supported because the behavior could be error prone, because
        // of the possibility that the user would pass a vector that is not empty.
        CNotImplementedTypeHandler<MemberType*>::LoadState(node, member, className, propertyID);
    }

    static void SaveState(ISerializableNode* node, MemberType* member, const char* className, const CSerializationID& propertyID)
    {
        // Currently not implemented because it is assumed that LoadState() is error prone in this case.
        CNotImplementedTypeHandler<MemberType*>::SaveState(node, member, className, propertyID);
    }

    static void GetUiInfo(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, bool bStatic, const char* classFullName, const CSerializationID& propertyID, const behaviac::wstring& displayName, const behaviac::wstring& desc, UiGenericType* uiWrapper)
    {
        if (types == NULL)
        {
            XmlNodeRef memberNode = xmlNode->newChild("Member");
            memberNode->setAttr("Name", propertyID.GetString());
            memberNode->setAttr("DisplayName", displayName);
            memberNode->setAttr("Desc", desc);
            const behaviac::string memberTypeStr = ::GetTypeDescString<MemberType*>();
            memberNode->setAttr("Type", memberTypeStr.c_str());

            if (classFullName)
            {
                memberNode->setAttr("Class", classFullName);
            }

            if (bStatic)
            {
                memberNode->setAttr("Static", "true");
            }

            //if (member)
            //{
            //    member->GetMembersDescription(memberNode);
            //}

            if (uiWrapper)
            {
                uiWrapper->SaveDescription(memberNode);
            }
        }
    }

    static void GetMethodsDescription(CTagTypeDescriptor::TypesMap_t* types, const XmlNodeRef& xmlNode, MemberType* const& member, const char* className, const char* propertyName)
    {
        // TODO
        XmlNodeRef memberNode = xmlNode;

        if (types == NULL)
        {
            memberNode = xmlNode->newChild(propertyName);
        }

        member->GetMethodsDescription(types, memberNode);
    }
};

#include "behaviac/base/object/typehandlerex.h"

#endif // #ifndef BEHAVIAC_ENGINESERVICES_TYPEHANDLER_H
