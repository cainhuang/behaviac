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

#include "behaviac/agent/agent.h"

#include "behaviac/base/file/filesystem.h"

namespace behaviac
{
	State_t::State_t() : m_bt(0)
	{
	}


	State_t::~State_t()
	{
		this->Clear();
	}

	State_t::State_t(const State_t& c) : m_bt(0)
	{
		*this = c;
	}

	State_t& State_t::operator=(const State_t& c)
	{
		c.m_vars.CopyTo(0, this->m_vars);

		if (c.m_bt)
		{
			const BehaviorNode* pNode = c.m_bt->GetNode();
			this->m_bt = (BehaviorTreeTask*)pNode->CreateAndInitTask();

			c.m_bt->CopyTo(this->m_bt);
		}

		return *this;
	}

	void State_t::Clear()
	{
		this->m_vars.Clear();

		BEHAVIAC_DELETE(this->m_bt);
		this->m_bt = 0;
	}

	bool State_t::SaveToFile(const char* fileName) const
	{
		XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

        CTextNode node(xmlInfo);
		
		this->m_vars.Save(&node);

		if (this->m_bt)
		{
			this->m_bt->Save(&node);
		}

        CFileSystem::MakeSureDirectoryExist(fileName);
        return xmlInfo->saveToFile(fileName);
	}


	bool State_t::LoadFromFile(const char* fileName)
	{
		XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

		CTextNode node(xmlInfo);

		if (node.LoadFromFile(fileName))
		{
			this->m_vars.Load(&node);

			return true;
		}

		return false;
	}

	bool State_t::SaveToFile(IFile* file) const
	{
		XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

        CTextNode node(xmlInfo);
        
		this->m_vars.Save(&node);

        return xmlInfo->saveToFile(file);
	}


	bool State_t::LoadFromFile(IFile* file)
	{
		XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

		CTextNode node(xmlInfo);

		if (node.LoadFromFile(file))
		{
			this->m_vars.Load(&node);

			return true;
		}

		return false;
	}

}

