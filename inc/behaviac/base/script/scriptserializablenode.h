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


#ifndef _ENGINESERVICES_SCRIPTSERIALIZABLENODE_H_
#define _ENGINESERVICES_SCRIPTSERIALIZABLENODE_H_

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/serialization/serializablenode.h"

class BEHAVIAC_API CScriptSerializableNode : public ISerializableNode
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptSerializableNode);

    CScriptSerializableNode(const CSerializationID& serializationId);
    CScriptSerializableNode(const CScriptSerializableNode& other);
    virtual ~CScriptSerializableNode();

    virtual SerializableNodeRef clone() const;
private:
    CScriptSerializableNode* clonePtr() const;

public:
    virtual int32_t getChildCount() const
    {
        return m_children.size();
    }
    virtual ISerializableNode* getChild(int32_t childIndex)
    {
        BEHAVIAC_ASSERT(childIndex < getChildCount());
        return m_children[childIndex];
    }
    virtual const ISerializableNode* getChild(int32_t childIndex) const
    {
        BEHAVIAC_ASSERT(childIndex < getChildCount());
        return m_children[childIndex];
    }

    virtual ISerializableNode* findChild(const CSerializationID& childID);
    virtual const ISerializableNode* findChild(const CSerializationID& childID) const;

    virtual ISerializableNode* newChild(const CSerializationID& childID);
    virtual void removeChild(ISerializableNode* child);
    virtual void addChild(const CSerializationID& keyID, const ISerializableNode* child);

    virtual bool isTag(const CSerializationID& tagID) const
    {
        return m_tag == tagID;
    }
    virtual CSerializationID getTag() const
    {
        return m_tag;
    }

    virtual int32_t getAttributesCount() const;

    virtual bool SaveToFile(const char* fileName) const
    {
        BEHAVIAC_ASSERT("Not implemented");
        return false;
    }
    virtual bool LoadFromFile(const char* fileName)
    {
        BEHAVIAC_ASSERT("Not implemented");
        return false;
    }

    virtual bool SaveToFile(IFile* file) const
    {
        BEHAVIAC_ASSERT("Not implemented");
        return false;
    }
    virtual bool LoadFromFile(IFile* file)
    {
        BEHAVIAC_ASSERT("Not implemented");
        return false;
    }

    virtual int32_t GetMemUsage() const
    {
        BEHAVIAC_ASSERT("Not implemented");
        return 0;
    }

	template <class T>
    void setAttr(const CSerializationID& keyID, const T& value)
    {
        setAttrTemplate(keyID, value);
    }
    
	template <class T>
	bool getAttr(const CSerializationID& keyID, T& value) const
    {
        return getAttrTemplate(keyID, value);
    }
private:
    template <typename T> bool getAttrTemplate(const CSerializationID& keyID, T& value) const
	{
		lua_State* L = GetScriptState();
		lua_getref(L, m_table);
		lua_getfield(L, -1, keyID.GetString());
		bool result = CScriptMarshal::GetData(L, -1, value);
		lua_pop(L, 2);
		return result;
	}

    template <typename T> void setAttrTemplate(const CSerializationID& keyID, T value)
	{
		lua_State* L = GetScriptState();
		lua_getref(L, m_table);
		CScriptMarshal::PushData(L, value);
		lua_setfield(L, -2, keyID.GetString());
		lua_pop(L, 1);
	}

    template <typename T> void setAttrTemplateRef(const CSerializationID& keyID, const T& value);

public:

    void LinkChildren();

private:
    int m_table;

    CSerializationID m_tag;

    typedef behaviac::vector<CScriptSerializableNode*> NodesContainer;
    NodesContainer m_children;

    struct CompareNodeTag;
};

#endif//#if BEHAVIAC_ENABLE_LUA

#endif
