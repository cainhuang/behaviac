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

#ifndef BEHAVIAC_BEHAVIORTREE_CONDITION_H_
#define BEHAVIAC_BEHAVIORTREE_CONDITION_H_

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/property/property.h"

#include "behaviac/property/comparator.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"

namespace behaviac
{
	/*! \addtogroup treeNodes Behavior Tree
	* @{
	* \addtogroup Condition
	* @{ */

	/**
	Condition node can compare the value of right and left. return Failure or Success
	*/
	BEHAVIAC_API Property* LoadRight(const char* value, const behaviac::string& propertyName, behaviac::string& typeName);

    class BEHAVIAC_API Condition : public ConditionBase
    {
	public:
        template<typename T>
        static bool Register(const char* typeName)
        {
            ComparatorCreators()[typeName] = &_Creator<T>;

			return true;
        }

        template<typename T>
        static void UnRegister(const char* typeName)
        {
            ComparatorCreators().erase(typeName);
        }

        static void RegisterBasicTypes();
        static void UnRegisterBasicTypes();
	public:
        static VariableComparator* Create(const char* typeName, const char* comparionOperator,
                                          const Property* lhs, const Property* rhs);

		static void Cleanup();
    private:
        template<typename T>
        static VariableComparator* _Creator(E_VariableComparisonType comparisonType,
                                            const Property* lhs, const Property* rhs)
        {
			typedef VariableComparatorImpl<T> VariableComparatorType;
            VariableComparatorType* pComparator = BEHAVIAC_NEW VariableComparatorType;
            pComparator->SetType(comparisonType);
            pComparator->SetProperty(const_cast<Property*>(lhs), const_cast<Property*>(rhs));
            return pComparator;
        }

        typedef VariableComparator* VariableComparatorCreator(E_VariableComparisonType comparisonType, const Property* lhs, const Property* rhs);
        typedef behaviac::map<behaviac::string, VariableComparatorCreator*> VariableComparators;
        typedef VariableComparators::iterator VariableComparatorIterator;
        static VariableComparators* ms_comparatorCreators;
		static VariableComparators& ComparatorCreators();

    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition, ConditionBase);

        Condition();
        virtual ~Condition();
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

		friend class ConditionTask;
    };
  
    class BEHAVIAC_API ConditionTask : public ConditionBaseTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(ConditionTask, ConditionBaseTask);

        ConditionTask() : ConditionBaseTask()
        {
        }

        virtual ~ConditionTask()
        {
        }

    protected:
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    };
	/*! @} */
	/*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_CONDITION_H_
