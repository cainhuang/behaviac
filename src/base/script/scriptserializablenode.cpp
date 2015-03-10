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

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA

#include "behaviac/base/script/scriptserializablenode.h"

#include "behaviac/base/script/scriptmarshal.h"
#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/script/scriptutils.h"

#include "behaviac/base/xml/xmlparser.h"

struct CScriptSerializableNode::CompareNodeTag : public std::unary_function<CScriptSerializableNode*, bool>
{
    CompareNodeTag& operator=(const CompareNodeTag&);

    CompareNodeTag(const CSerializationID& wantedTag)
        : m_wantedTag(wantedTag)
    {}

    bool operator()(const CScriptSerializableNode* other) const
    {
        return other->isTag(m_wantedTag);
    }

    const CSerializationID& m_wantedTag;
};

CScriptSerializableNode::CScriptSerializableNode(const CSerializationID& serializationId) : ISerializableNode(true)
{
    lua_State* L = CScriptSystem::GetInstance()->GetLuaState();
    lua_newtable(L);
    lua_pushstring(L, serializationId.GetString());
    lua_rawseti(L, -2, 0);
    m_table = lua_ref(L, true);
    m_tag = serializationId;
}

CScriptSerializableNode::CScriptSerializableNode(const CScriptSerializableNode& other) : ISerializableNode(other.m_bText), 
    m_tag(other.m_tag)
{
    lua_State* L = GetScriptState();
    lua_getref(L, other.m_table);
    lua_newtable(L);
    CScriptUtils::CloneTable(L, -2, false);
    m_table = lua_ref(L, true);
    lua_pop(L, 1);
    // Copy the children
    NodesContainer::const_iterator childIter, childEnd = other.m_children.end();

    for (childIter = other.m_children.begin(); childIter != childEnd; ++childIter)
    {
        m_children.push_back((*childIter)->clonePtr());
    }
}


CScriptSerializableNode::~CScriptSerializableNode()
{
    for (int i = 0; i < (int)m_children.size(); i++)
    {
        BEHAVIAC_DELETE(m_children)[i];
    }

    lua_State* L = GetScriptState();
    lua_unref(L, m_table);
}

SerializableNodeRef CScriptSerializableNode::clone() const
{
    return GetNodeRef(clonePtr());
}

CScriptSerializableNode* CScriptSerializableNode::clonePtr() const
{
    return BEHAVIAC_NEW CScriptSerializableNode(*this);
}

ISerializableNode* CScriptSerializableNode::findChild(const CSerializationID& childID)
{
    NodesContainer::iterator end = m_children.end();
    NodesContainer::iterator iter = std::find_if(m_children.begin(), end, CompareNodeTag(childID));

    if (iter != end)
    {
        return *iter;
    }

    return NULL;
}

const ISerializableNode* CScriptSerializableNode::findChild(const CSerializationID& childID) const
{
    NodesContainer::const_iterator end = m_children.end();
    NodesContainer::const_iterator iter = std::find_if(m_children.begin(), end, CompareNodeTag(childID));

    if (iter != end)
    {
        return *iter;
    }

    return NULL;
}

ISerializableNode* CScriptSerializableNode::newChild(const CSerializationID& childID)
{
    CScriptSerializableNode* newChild = BEHAVIAC_NEW CScriptSerializableNode(childID);
    m_children.push_back(newChild);
    return newChild;
}

void CScriptSerializableNode::removeChild(ISerializableNode* child)
{
    NodesContainer::iterator end = m_children.end();
    NodesContainer::iterator iter = std::find(m_children.begin(), end, (CScriptSerializableNode*)child);

    if (iter != end)
    {
        BEHAVIAC_DELETE(child);
        m_children.erase(iter);
    }
}

void CScriptSerializableNode::addChild(const CSerializationID& keyID, const ISerializableNode* child)
{
    const CScriptSerializableNode* scriptChild = static_cast<const CScriptSerializableNode*>(child);
    CScriptSerializableNode* cloneNode = scriptChild->clonePtr();
    cloneNode->m_tag = keyID;
    BEHAVIAC_ASSERT(std::find_if(m_children.begin(), m_children.end(), CompareNodeTag(keyID)) == m_children.end());
    m_children.push_back(cloneNode);
}


int32_t CScriptSerializableNode::getAttributesCount() const
{
    lua_State* L = GetScriptState();
    int count = 0;
    lua_getref(L, m_table);
    lua_pushnil(L);

    while (lua_next(L, -2) != 0)
    {
        count++;
        lua_pop(L, 1);
    }

    lua_pop(L, 1);
    return count;
}


template <typename T> void CScriptSerializableNode::setAttrTemplateRef(const CSerializationID& keyID, const T& value)
{
    lua_State* L = GetScriptState();
    lua_getref(L, m_table);
    CScriptMarshal::PushData(L, value);
    lua_setfield(L, -2, keyID.GetString());
    lua_pop(L, 1);
}

void CScriptSerializableNode::LinkChildren()
{
    lua_State* L = GetScriptState();
    lua_getref(L, m_table);
    int i = 1;

    for (; i <= (int)m_children.size(); i++)
    {
        m_children[i - 1]->LinkChildren();
        lua_getref(L, m_children[i - 1]->m_table);
        lua_rawseti(L, -2, i);
    }

    for (;; i++)
    {
        lua_rawgeti(L, -1, i);
        bool isNil = lua_isnil(L, -1);
        lua_pop(L, 1);

        if (isNil)
        {
            break;
        }

        lua_pushnil(L);
        lua_rawseti(L, -2, i);
    }

    lua_pop(L, 1);
}
#endif//#if BEHAVIAC_ENABLE_LUA