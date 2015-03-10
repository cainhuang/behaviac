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
#include "behaviac/behaviortree/nodes/composites/selector.h"

namespace behaviac
{
	Selector::Selector()
	{}

	Selector::~Selector()
	{}

	void Selector::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);
	}

	bool Selector::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!Selector::DynamicCast(pTask->GetNode()))
		{
			return false;
		}
	
		return super::IsValid(pAgent, pTask);
	}


	BehaviorTask* Selector::createTask() const
	{
		SelectorTask* pTask = BEHAVIAC_NEW SelectorTask();
		

		return pTask;
	}

	SelectorTask::SelectorTask() : CompositeTask()
	{
	}

	SelectorTask::~SelectorTask()
	{
	}

	void SelectorTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void SelectorTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void SelectorTask::load(ISerializableNode* node)
	{
		super::load(node);
	}



    bool SelectorTask::onenter(Agent* pAgent)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_ASSERT(this->m_children.size() > 0);
		this->m_activeChildIndex = 0;
        return true;
    }

    EBTStatus SelectorTask::update(Agent* pAgent, EBTStatus childStatus)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);

		bool bFirst = true;

		BEHAVIAC_ASSERT(this->m_activeChildIndex < this->m_children.size());

        // Keep going until a child behavior says its running.
        for (;;)
		{	
			EBTStatus s = childStatus;
			if (!bFirst || s == BT_RUNNING)
			{
				BEHAVIAC_ASSERT(this->m_status == BT_INVALID ||
					this->m_status == BT_RUNNING);

				BehaviorTask* pBehavior = this->m_children[this->m_activeChildIndex];
				s = pBehavior->exec(pAgent);
			}
			
			bFirst = false;

			// If the child succeeds, or keeps running, do the same.
			if (s != BT_FAILURE)
			{
				return s;
			}

			// Hit the end of the array, job done!
			++this->m_activeChildIndex;
			if (this->m_activeChildIndex >= this->m_children.size())
			{
				return BT_FAILURE;
			}

			if (!this->CheckPredicates(pAgent))
			{
				return BT_FAILURE;
			}
		}
    }

    void SelectorTask::onexit(Agent* pAgent, EBTStatus s)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(s);
    }
}