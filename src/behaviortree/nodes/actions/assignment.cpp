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
#include "behaviac/world/world.h"
#include "behaviac/property/property_t.h"
#include "behaviac/behaviortree/nodes/actions/assignment.h"

#include "behaviac/base/core/profiler/profiler.h"

namespace behaviac
{
	Assignment::Assignment() : m_opl(0), m_opr(0), m_opr_m(0)
	{
	}

	Assignment::~Assignment()
	{
		BEHAVIAC_DELETE(m_opl);
		BEHAVIAC_DELETE(m_opr);
		BEHAVIAC_DELETE(m_opr_m);
	}

	CMethodBase* LoadMethod(const char* value);
	Property* LoadLeft(const char* value, behaviac::string& propertyName, const char* constValue);
	Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);

	void Assignment::load(int version, const char* agentType, const properties_t& properties)
	{
		super::load(version, agentType, properties);

		behaviac::string propertyName;

		for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
		{
			const property_t& p = (*it);

			if (strcmp(p.name, "Opl") == 0)
			{
				this->m_opl = LoadLeft(p.value, propertyName, 0);
			}
			else if (strcmp(p.name, "Opr") == 0)
			{
				const char* pParenthesis = strchr(p.value, '(');
				if (pParenthesis == 0)
				{
					behaviac::string typeName;
					this->m_opr = LoadRight(p.value, propertyName, typeName);
				}
				else
				{
					//method
					this->m_opr_m = LoadMethod(p.value);
				}
			}
			else
			{
				//BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
			}
		}
	}

	bool Assignment::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!Assignment::DynamicCast(pTask->GetNode()))
		{
			return false;
		}

		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* Assignment::createTask() const
	{
		AssignmentTask* pTask = BEHAVIAC_NEW AssignmentTask();

		return pTask;
	}

	AssignmentTask::AssignmentTask() : LeafTask()
	{
	}

	AssignmentTask::~AssignmentTask()
	{
	}

	void AssignmentTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void AssignmentTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void AssignmentTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	bool AssignmentTask::isContinueTicking() const
	{
		return false;
	}

	bool AssignmentTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		return true;
	}

	void AssignmentTask::onexit(Agent* pAgent, EBTStatus s)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(s);
	}

	EBTStatus AssignmentTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(childStatus);

		EBTStatus result = BT_SUCCESS;

		BEHAVIAC_ASSERT(Assignment::DynamicCast(this->GetNode()));
		Assignment* pAssignmentNode = (Assignment*)(this->GetNode());

		if (pAssignmentNode->m_opr_m)
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("Node");
//#endif
			ParentType pt = pAssignmentNode->m_opr_m->GetParentType();
			Agent* pParent = pAgent;
			if (pt == PT_INSTANCE)
			{
				pParent = Agent::GetInstance(pAssignmentNode->m_opr_m->GetInstanceNameString(), pParent->GetContextId());
				BEHAVIAC_ASSERT(pParent);
			}

			pAssignmentNode->m_opr_m->run(pParent, pAgent);

			ParentType pt_opl = pAssignmentNode->m_opl->GetParentType();
			Agent* pParentOpl = pAgent;
			if (pt_opl == PT_INSTANCE)
			{
				pParentOpl = Agent::GetInstance(pAssignmentNode->m_opl->GetInstanceNameString(), pParentOpl->GetContextId());
				BEHAVIAC_ASSERT(pParentOpl);
			}

			pAssignmentNode->m_opr_m->GetReturnValue(pParent, pAssignmentNode->m_opl, pParentOpl);
		}
		else if (pAssignmentNode->m_opr && pAssignmentNode->m_opl)
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("Node");
//#endif
			Agent* pParentL = pAgent;
			Agent* pParentR = pAgent;

			{
				ParentType pt = pAssignmentNode->m_opl->GetParentType();
				if (pt == PT_INSTANCE)
				{
					pParentL = Agent::GetInstance(pAssignmentNode->m_opl->GetInstanceNameString(), pParentL->GetContextId());
					BEHAVIAC_ASSERT(pParentL);
				}
			}
			{
				ParentType pt = pAssignmentNode->m_opr->GetParentType();
				if (pt == PT_INSTANCE)
				{
					pParentR = Agent::GetInstance(pAssignmentNode->m_opr->GetInstanceNameString(), pParentR->GetContextId());

					//it is a const
					if (!pParentR)
					{
						pParentR = pParentL;
					}
				}
			}

			pAssignmentNode->m_opl->SetFrom(pParentR, pAssignmentNode->m_opr, pParentL);
		}
		else
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("AssignmentGenerated");
//#endif
			result = pAssignmentNode->update_impl(pAgent, childStatus);
		}

		return result;
	}

}