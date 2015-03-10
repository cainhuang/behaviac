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
#include "behaviac/behaviortree/nodes/composites/selectorloop.h"
#include "behaviac/behaviortree/nodes/composites/withprecondition.h"

namespace behaviac
{
	SelectorLoop::SelectorLoop()// : m_preconditions(0), m_actions(0)
	{}

	SelectorLoop::~SelectorLoop()
	{}

	void SelectorLoop::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);
	}

	bool SelectorLoop::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!SelectorLoop::DynamicCast(pTask->GetNode()))
		{
			return false;
		}
	
		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* SelectorLoop::createTask() const
	{
		SelectorLoopTask* pTask = BEHAVIAC_NEW SelectorLoopTask();
		

		return pTask;
	}


	SelectorLoopTask::SelectorLoopTask() : CompositeTask()
	{
	}


	void SelectorLoopTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
	}


	void SelectorLoopTask::copyto(BehaviorTask* target) const
	{
		CompositeTask::copyto(target);

		BEHAVIAC_ASSERT(SelectorLoopTask::DynamicCast(target));
		SelectorLoopTask* ttask = (SelectorLoopTask*)target;

		ttask->m_activeChildIndex = this->m_activeChildIndex;
	}


	void SelectorLoopTask::save(ISerializableNode* node) const
	{
		super::save(node);

		CSerializationID  activeChildId("activeChild");
		node->setAttr(activeChildId, this->m_activeChildIndex);
	}

	void SelectorLoopTask::load(ISerializableNode* node)
	{
		super::load(node);
	}



    SelectorLoopTask::~SelectorLoopTask()
	{
	}


	void SelectorLoopTask::addChild(BehaviorTask* pBehavior)
	{
		super::addChild(pBehavior);

		BEHAVIAC_ASSERT(WithPreconditionTask::DynamicCast(pBehavior));
	}


    bool SelectorLoopTask::onenter(Agent* pAgent)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);

		//reset the action child as it will be checked in the update
		this->m_activeChildIndex = CompositeTask::InvalidChildIndex;
		BEHAVIAC_ASSERT(this->m_activeChildIndex == CompositeTask::InvalidChildIndex);

		return super::onenter(pAgent);
    }

    void SelectorLoopTask::onexit(Agent* pAgent, EBTStatus s)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
		super::onexit(pAgent, s);
    }

	EBTStatus SelectorLoopTask::update(Agent* pAgent, EBTStatus childStatus)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(childStatus);

		//checking the preconditions and take the first action tree
		uint32_t index = (uint32_t)-1;
        for (uint32_t i = 0; i < this->m_children.size(); ++i)
        {
			WithPreconditionTask* pSubTree = (WithPreconditionTask*)this->m_children[i];
			BEHAVIAC_ASSERT(WithPreconditionTask::DynamicCast(pSubTree));

			BehaviorTask* pPrecondTree = pSubTree->PreconditionNode();

			EBTStatus status = pPrecondTree->exec(pAgent);

			if (status == BT_SUCCESS)
			{
				index = i;
				break;
			}
        }

		//clean up the current ticking action tree
		if (index != (uint32_t)-1)
		{
			if (this->m_activeChildIndex != CompositeTask::InvalidChildIndex)
			{
				WithPreconditionTask* pCurrentSubTree = (WithPreconditionTask*)this->m_children[this->m_activeChildIndex];
				BEHAVIAC_ASSERT(WithPreconditionTask::DynamicCast(pCurrentSubTree));
				BehaviorTask* pCurrentActionTree = pCurrentSubTree->Action();

				WithPreconditionTask* pSubTree = (WithPreconditionTask*)this->m_children[index];
				BEHAVIAC_ASSERT(WithPreconditionTask::DynamicCast(pSubTree));

				BehaviorTask* pActionTree = pSubTree->Action();

				if (pCurrentActionTree != pActionTree)
				{
					pCurrentActionTree->abort(pAgent);

					pCurrentSubTree->abort(pAgent);

					this->m_activeChildIndex = index;
				}
			}


			for (uint32_t i = 0; i < this->m_children.size(); ++i)
			{
				WithPreconditionTask* pSubTree = (WithPreconditionTask*)this->m_children[i];
				BEHAVIAC_ASSERT(WithPreconditionTask::DynamicCast(pSubTree));

				//dummy ticking so that the designer knows it is updating
				EBTStatus statusDummy = pSubTree->exec(pAgent);
				BEHAVIAC_ASSERT(statusDummy == BT_RUNNING);
				BEHAVIAC_UNUSED_VAR(statusDummy);

				//when i < index, the precondition is failure, so to continue
				if (i < index)
				{
					continue;
				}

				if (i > index)
				{
					BehaviorTask* pPreconditionTree = pSubTree->PreconditionNode();

					EBTStatus status = pPreconditionTree->exec(pAgent);

					//to search for the first one whose precondition is success
					if (status != BT_SUCCESS)
					{
						continue;
					}
				}

				BehaviorTask* pActionTree = pSubTree->Action();

				EBTStatus status = pActionTree->exec(pAgent);

				if (status == BT_RUNNING)
				{
					this->m_activeChildIndex = index;
				}
				else
				{
					pActionTree->reset(pAgent);

					if (status == BT_FAILURE || status == BT_INVALID)
					{
						//THE ACTION failed, to try the next one
						continue;
					}
				}

				BEHAVIAC_ASSERT(status == BT_RUNNING || status == BT_SUCCESS);

				return status;
			}
		}

		return BT_FAILURE;
    }

}