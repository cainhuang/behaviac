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
#include "behaviac/behaviortree/nodes/actions/compute.h"

#include "behaviac/base/core/profiler/profiler.h"

namespace behaviac
{
	Compute::Compute() : m_opl(0), m_opr1(0), m_opr1_m(0), m_opr2(0), m_opr2_m(0), m_operator(E_INVALID)
	{
	}

	Compute::~Compute()
	{
		BEHAVIAC_DELETE(m_opl);
		BEHAVIAC_DELETE(m_opr1);
		BEHAVIAC_DELETE(m_opr1_m);

		BEHAVIAC_DELETE(m_opr2);
		BEHAVIAC_DELETE(m_opr2_m);
	}

	CMethodBase* LoadMethod(const char* value);
	Property* LoadLeft(const char* value, behaviac::string& propertyName, const char* constValue);
	Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);

	void Compute::load(int version, const char* agentType, const properties_t& properties)
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
			else if (strcmp(p.name, "Operator") == 0)
			{
				if (strcmp(p.value, "Add") == 0)
				{
					this->m_operator = E_ADD;
				}
				else if (strcmp(p.value, "Sub") == 0)
				{
					this->m_operator = E_SUB;
				}
				else if (strcmp(p.value, "Mul") == 0)
				{
					this->m_operator = E_MUL;
				}
				else if (strcmp(p.value, "Div") == 0)
				{
					this->m_operator = E_DIV;
				}
				else
				{
					BEHAVIAC_ASSERT(0);
				}
			}
			else if (strcmp(p.name, "Opr1") == 0)
			{
				const char* pParenthesis = strchr(p.value, '(');
				if (pParenthesis == 0)
				{
					behaviac::string typeName;
					this->m_opr1 = LoadRight(p.value, propertyName, typeName);
				}
				else
				{
					//method
					this->m_opr1_m = LoadMethod(p.value);
				}
			}
			else if (strcmp(p.name, "Opr2") == 0)
			{
				const char* pParenthesis = strchr(p.value, '(');
				if (pParenthesis == 0)
				{
					behaviac::string typeName;
					this->m_opr2 = LoadRight(p.value, propertyName, typeName);
				}
				else
				{
					//method
					this->m_opr2_m = LoadMethod(p.value);
				}
			}
			else
			{
				//BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
			}
		}

		BEHAVIAC_ASSERT(this->m_operator != E_INVALID);
	}

	bool Compute::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!Compute::DynamicCast(pTask->GetNode()))
		{
			return false;
		}

		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* Compute::createTask() const
	{
		ComputeTask* pTask = BEHAVIAC_NEW ComputeTask();

		return pTask;
	}

	ComputeTask::ComputeTask() : LeafTask()
	{
	}

	ComputeTask::~ComputeTask()
	{
	}

	void ComputeTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void ComputeTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void ComputeTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	bool ComputeTask::isContinueTicking() const
	{
		return false;
	}

	bool ComputeTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		return true;
	}

	void ComputeTask::onexit(Agent* pAgent, EBTStatus s)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(s);
	}

	EBTStatus ComputeTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(childStatus);

		EBTStatus result = BT_SUCCESS;

		BEHAVIAC_ASSERT(Compute::DynamicCast(this->GetNode()));
		Compute* pComputeNode = (Compute*)(this->GetNode());

		bool bValid = false;

		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("Node");
//#endif
			if (pComputeNode->m_opl)
			{
				if (pComputeNode->m_opr1_m)
				{
					bValid = true;
					ParentType pt = pComputeNode->m_opr1_m->GetParentType();
					Agent* pParent = pAgent;
					if (pt == PT_INSTANCE)
					{
						pParent = Agent::GetInstance(pComputeNode->m_opr1_m->GetInstanceNameString(), pParent->GetContextId());
						BEHAVIAC_ASSERT(pParent);
					}

					pComputeNode->m_opr1_m->run(pParent, pAgent);

					ParentType pt_opl = pComputeNode->m_opl->GetParentType();
					Agent* pParentOpl = pAgent;
					if (pt_opl == PT_INSTANCE)
					{
						pParentOpl = Agent::GetInstance(pComputeNode->m_opl->GetInstanceNameString(), pParentOpl->GetContextId());
						BEHAVIAC_ASSERT(pParentOpl);
					}

					pComputeNode->m_opr1_m->GetReturnValue(pParent, pComputeNode->m_opl, pParentOpl);
				}
				else if (pComputeNode->m_opr1)
				{
					bValid = true;

					Agent* pParentL = pAgent;
					Agent* pParentR = pAgent;

					{
						ParentType pt = pComputeNode->m_opl->GetParentType();
						if (pt == PT_INSTANCE)
						{
							pParentL = Agent::GetInstance(pComputeNode->m_opl->GetInstanceNameString(), pParentL->GetContextId());
							BEHAVIAC_ASSERT(pParentL);
						}
					}
					{
						ParentType pt = pComputeNode->m_opr1->GetParentType();
						if (pt == PT_INSTANCE)
						{
							pParentR = Agent::GetInstance(pComputeNode->m_opr1->GetInstanceNameString(), pParentR->GetContextId());

							//it is a const
							if (!pParentR)
							{
								pParentR = pParentL;
							}
						}
					}

					pComputeNode->m_opl->SetFrom(pParentR, pComputeNode->m_opr1, pParentL);
				}

				if (pComputeNode->m_opr2_m)
				{
					bValid = true;
					ParentType pt = pComputeNode->m_opr2_m->GetParentType();
					Agent* pParent = pAgent;
					if (pt == PT_INSTANCE)
					{
						pParent = Agent::GetInstance(pComputeNode->m_opr2_m->GetInstanceNameString(), pParent->GetContextId());
						BEHAVIAC_ASSERT(pParent);
					}

					pComputeNode->m_opr2_m->run(pParent, pAgent);

					ParentType pt_opl = pComputeNode->m_opl->GetParentType();
					Agent* pParentOpl = pAgent;
					if (pt_opl == PT_INSTANCE)
					{
						pParentOpl = Agent::GetInstance(pComputeNode->m_opl->GetInstanceNameString(), pParentOpl->GetContextId());
						BEHAVIAC_ASSERT(pParentOpl);
					}

					pComputeNode->m_opr2_m->ComputeReturnValue(pParent, pComputeNode->m_opl, pParentOpl, pComputeNode->m_operator);
				}
				else if (pComputeNode->m_opr2)
				{
					bValid = true;

					Agent* pParentL = pAgent;
					Agent* pParentR = pAgent;

					{
						ParentType pt = pComputeNode->m_opl->GetParentType();
						if (pt == PT_INSTANCE)
						{
							pParentL = Agent::GetInstance(pComputeNode->m_opl->GetInstanceNameString(), pParentL->GetContextId());
							BEHAVIAC_ASSERT(pParentL);
						}
					}
					{
						ParentType pt = pComputeNode->m_opr2->GetParentType();
						if (pt == PT_INSTANCE)
						{
							pParentR = Agent::GetInstance(pComputeNode->m_opr2->GetInstanceNameString(), pParentR->GetContextId());

							//it is a const
							if (!pParentR)
							{
								pParentR = pParentL;
							}
						}
					}

					pComputeNode->m_opl->ComputeFrom(pParentR, pComputeNode->m_opr2, pParentL, pComputeNode->m_operator);
				}
			}
		}

		if (!bValid)
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("ComputeGenerated");
//#endif
			result = pComputeNode->update_impl(pAgent, childStatus);
		}

		return result;
	}

}