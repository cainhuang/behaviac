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
#include "behaviac/behaviortree/nodes/composites/referencebehavior.h"
#include "behaviac/agent/agent.h"

namespace behaviac
{
	ReferencedBehavior::ReferencedBehavior()
	{}

	ReferencedBehavior::~ReferencedBehavior()
	{
	}

	void ReferencedBehavior::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);

        for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
        {
            const property_t& p = (*it);

			if (strcmp(p.name, "ReferenceFilename") == 0)
			{
				this->m_referencedBehaviorPath = p.value;

				bool bOk = Workspace::Load(this->m_referencedBehaviorPath.c_str());
				BEHAVIAC_UNUSED_VAR(bOk);

				BEHAVIAC_ASSERT(bOk);
			}
			else
			{
				//BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
			}
		}
	}

	bool ReferencedBehavior::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!ReferencedBehavior::DynamicCast(pTask->GetNode()))
		{
			return false;
		}
	
		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* ReferencedBehavior::createTask() const
	{
		ReferencedBehaviorTask* pTask = BEHAVIAC_NEW ReferencedBehaviorTask();
		

		return pTask;
	}

	ReferencedBehaviorTask::ReferencedBehaviorTask() : SingeChildTask()
	{
	}

	ReferencedBehaviorTask::~ReferencedBehaviorTask()
	{
	}

	void ReferencedBehaviorTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		// BEHAVIAC_ASSERT(ReferencedBehaviorTask::DynamicCast(target));
		// ReferencedBehaviorTask* ttask = (ReferencedBehaviorTask*)target;
	}

	void ReferencedBehaviorTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void ReferencedBehaviorTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	void ReferencedBehaviorTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
	}

	bool ReferencedBehaviorTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);

		return true;
	}

	void ReferencedBehaviorTask::onexit(Agent* pAgent, EBTStatus s)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(s);
	}

	EBTStatus ReferencedBehaviorTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		BEHAVIAC_UNUSED_VAR(childStatus);
		BEHAVIAC_ASSERT(m_returnStatus == BT_INVALID);
		const ReferencedBehavior* pNode = ReferencedBehavior::DynamicCast(this->GetNode());
		if (pNode)
		{
			const char* pThisTree = pAgent->btgetcurrent()->GetName().c_str();
			const char* pReferencedTree = pNode->m_referencedBehaviorPath.c_str();
			
			behaviac::string msg = FormatString("%s[%d] %s", pThisTree, pNode->GetId(), pReferencedTree);

			LogManager::GetInstance()->Log(pAgent, msg.c_str(), EAR_none, ELM_jump);
			pAgent->btreferencetree(pReferencedTree);

			//the referenced tree is set as 'TM_Return', when the referenced tree is finished, to use its exec status then
			//EBTStatus s = pAgent->btexec();

			//return s;
		}

		return BT_RUNNING;
	}

}//namespace behaviac