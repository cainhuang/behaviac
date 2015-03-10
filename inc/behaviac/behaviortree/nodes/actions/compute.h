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

#ifndef BEHAVIAC_BEHAVIORTREE_COMPUTE_H_
#define BEHAVIAC_BEHAVIORTREE_COMPUTE_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/agent/agent.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Compute
	* @{ */

	///Compute
	/**
	Compute the result of Operand1 and Operand2 and assign it to the Left Operand.
	Compute node can perform Add, Sub, Mul and Div operations. a left and right Operand 
	can be a agent property or a par value.
	*/
	class BEHAVIAC_API Compute : public BehaviorNode
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute, BehaviorNode);

		Compute();
		virtual ~Compute();
		virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);

			return BT_FAILURE;
		}

	private:
		virtual BehaviorTask* createTask() const;

	protected:
		Property*			m_opl;

		Property*			m_opr1;
		CMethodBase*		m_opr1_m;

		Property*			m_opr2;
		CMethodBase*		m_opr2_m;

		EComputeOperator	m_operator;

		friend class ComputeTask;
	};

	class BEHAVIAC_API ComputeTask : public LeafTask
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ComputeTask, LeafTask);

		ComputeTask();
		virtual ~ComputeTask();

	protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool isContinueTicking() const;

		virtual bool onenter(Agent* pAgent);
		virtual void onexit(Agent* pAgent, EBTStatus s);
		virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
	};
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_COMPUTE_H_