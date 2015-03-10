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

#ifndef BEHAVIAC_BEHAVIORTREE_TEST_H_
#define BEHAVIAC_BEHAVIORTREE_TEST_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/property/property.h"

#include "behaviac/property/comparator.h"

namespace behaviac
{
    class BEHAVIAC_API Predicate : public ConditionBase
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate, ConditionBase);

        Predicate();
        virtual ~Predicate();
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
        Property*			m_opr;
		CMethodBase*		m_opl_m;

        VariableComparator* m_comparator;
		bool				m_bAnd;

		friend class PredicateTask;
    };   

    class BEHAVIAC_API PredicateTask : public AttachmentTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(PredicateTask, AttachmentTask);

        PredicateTask();
        virtual ~PredicateTask();

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		virtual bool NeedRestart() const;

		bool IsAnd() const;
    private:

		//to access m_bAnd;
		friend class BehaviorTask;
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_TEST_H_