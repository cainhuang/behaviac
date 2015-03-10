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
#include "behaviac/agent/agent.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"

#include "behaviac/behaviortree/attachments/predicate.h"

#include "behaviac/base/core/profiler/profiler.h"

namespace behaviac
{
	Predicate::Predicate() : m_opl(0), m_opr(0), m_opl_m(0), m_comparator(0), m_bAnd(false)
	{
	}

	Predicate::~Predicate()
	{
		BEHAVIAC_DELETE(m_opl);
		BEHAVIAC_DELETE(m_opr);
		BEHAVIAC_DELETE(m_opl_m);
		BEHAVIAC_DELETE(m_comparator);
	}
	
	CMethodBase* LoadMethod(const char* value);
	Property* LoadLeft(const char* value, behaviac::string& propertyName, const char* constValue);
	Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);

    void Predicate::load(int version, const char* agentType, const properties_t& properties)
    {
		super::load(version, agentType, properties);

		behaviac::string typeName;
		behaviac::string propertyName;
        behaviac::string comparatorName;

        for (propertie_const_iterator_t it = properties.begin(); it != properties.end(); ++it)
        {
            const property_t& p = (*it);

            if (strcmp(p.name, "Operator") == 0)
            {
                comparatorName = p.value;
            }
			else if (strcmp(p.name, "Opl") == 0)
            {
				const char* pParenthesis = strchr(p.value, '(');
				if (pParenthesis == 0)
				{
					this->m_opl = LoadLeft(p.value, propertyName, 0);
				}
				else
				{
					//method
					this->m_opl_m = LoadMethod(p.value);
				}
            }
            else if (strcmp(p.name, "Opr") == 0)
            {
				this->m_opr = LoadRight(p.value, propertyName, typeName);
            }
			else if (strcmp(p.name, "BinaryOperator") == 0)
			{
				if (strcmp(p.value, "Or") == 0)
				{
					this->m_bAnd = false;
				}
				else if (strcmp(p.value, "And") == 0)
				{
					this->m_bAnd = true;
				}
				else
				{
					BEHAVIAC_ASSERT(0);
				}
			}
            else
            {
                //BEHAVIAC_ASSERT(0, "unrecognised property %s", p.name);
            }
        }

		if (!comparatorName.empty() && (this->m_opl || this->m_opl_m) && this->m_opr)
		{
			this->m_comparator = Condition::Create(typeName.c_str(), comparatorName.c_str(), this->m_opl, this->m_opr);
		}
    }

	bool Predicate::IsValid(Agent* pAgent, BehaviorTask* pTask) const
	{
		if (!Predicate::DynamicCast(pTask->GetNode()))
		{
			return false;
		}

		return super::IsValid(pAgent, pTask);
	}

	BehaviorTask* Predicate::createTask() const
	{
		PredicateTask* pTask = BEHAVIAC_NEW PredicateTask();
		
		return pTask;
	}

	PredicateTask::PredicateTask() : AttachmentTask()
	{
	}

	PredicateTask::~PredicateTask()
	{
	}

	bool PredicateTask::NeedRestart() const
	{
		return true;
	}

	void PredicateTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void PredicateTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void PredicateTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	bool PredicateTask::IsAnd() const
	{
		BEHAVIAC_ASSERT(Predicate::DynamicCast(this->GetNode()));
		const Predicate* pPredicateNode = (const Predicate*)(this->GetNode());

		return pPredicateNode ? pPredicateNode->m_bAnd : false;
	}

    bool PredicateTask::onenter(Agent* pAgent)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);

        return true;
    }

    void PredicateTask::onexit(Agent* pAgent, EBTStatus s)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(s);
    }

	bool DoCompare(Agent* pAgent, VariableComparator* comparator, Property* opl, CMethodBase* opl_m, Property* opr);

    EBTStatus PredicateTask::update(Agent* pAgent, EBTStatus childStatus)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(childStatus);

		BEHAVIAC_ASSERT(Predicate::DynamicCast(this->GetNode()));
		Predicate* pPredicateNode = (Predicate*)(this->GetNode());

		EBTStatus result = BT_FAILURE;

		if (pPredicateNode->m_comparator)
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("Node");
//#endif
			if (DoCompare(pAgent, pPredicateNode->m_comparator, pPredicateNode->m_opl, pPredicateNode->m_opl_m, pPredicateNode->m_opr))
			{
				result = BT_SUCCESS;
			}
		}
		else
		{
//#if BEHAVIAC_ENABLE_PROFILING
//			BEHAVIAC_PROFILE("PredicateGenerated");
//#endif
			result = pPredicateNode->update_impl(pAgent, childStatus);
		}

        return result;
    }
}
