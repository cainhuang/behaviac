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

#ifndef _BEHAVIAC_PROPERTYNODE_H_
#define _BEHAVIAC_PROPERTYNODE_H_

#include "behaviac/base/serialization/serializablenode.h"
#include "behaviac/agent/agent.h"

class BEHAVIAC_API CPropertyNode : public ISerializableNode
{
public:
	CPropertyNode() : ISerializableNode(false, false), m_pAgent(0), m_bParseString(false)
	{}

	CPropertyNode(behaviac::Agent* pAgent, const char* tag, const char* valueStr = 0)
		: ISerializableNode(false, false), m_pAgent(pAgent), m_tag(tag), m_value(valueStr), m_bParseString(valueStr != 0)
	{}

	~CPropertyNode();

	CPropertyNode& operator=(const CPropertyNode&);

	//////////////////////////////////////////////////////////////////////////
	// ISerializableNode interface
	virtual SerializableNodeRef clone() const;

	virtual int32_t getChildCount() const;
	virtual ISerializableNode* getChild(int32_t childIndex);
	virtual const ISerializableNode* getChild(int32_t childIndex) const;

	virtual ISerializableNode* findChild(const CSerializationID& childID);
	virtual const ISerializableNode* findChild(const CSerializationID& childID) const;

	virtual CPropertyNode* newChild(const CSerializationID& childID);

	virtual void removeChild(ISerializableNode* child);

	virtual bool isTag(const CSerializationID& tagID) const
	{
		BEHAVIAC_UNUSED_VAR(tagID);

		return false;
	}
	virtual CSerializationID getTag() const
	{
		return CSerializationID("");
	}

	virtual int32_t getAttributesCount() const;

	virtual const char* getAttr(const CSerializationID& keyID) const
	{
        BEHAVIAC_UNUSED_VAR(keyID);

		return 0;
	}

    virtual const char* getAttrRaw(const CSerializationID& keyID, int typeId = 0, int length = 0) const;
    virtual void setAttrRaw(const CSerializationID& keyID, const char* valueData, int typeId = 0, int length = 0);

	virtual void addChild(const CSerializationID& keyID, const ISerializableNode* child);

	void addChild(XmlNodeRef xmlChild);

	virtual bool SaveToFile(const char* fileName) const;
	virtual bool LoadFromFile(const char* fileName);

	virtual bool SaveToFile(IFile* file) const;
	virtual bool LoadFromFile(IFile* file);

	virtual int32_t GetMemUsage() const;

private:
	void RebuildChildrenList();

	typedef behaviac::list<CPropertyNode> ChildrenContainer;
	ChildrenContainer m_children;

	behaviac::Agent*		m_pAgent;
	const behaviac::string		m_tag;
	//const behaviac::string		m_value;
	const char*				m_value;
	const bool				m_bParseString;
};

#endif //_BEHAVIAC_PROPERTYNODE_H_
