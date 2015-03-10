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

using System.Collections;
using System.Collections.Generic;

namespace behaviac
{
    public class Predicate : ConditionBase
    {
        public Predicate()
        {
            m_bAnd = false;
        }
        ~Predicate()
        {
            m_opl = null;
            m_opr = null;
            m_opl_m = null;
            m_comparator = null;
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is Predicate))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);

            string typeName = null;
            string propertyName = null;
            string comparatorName = null;

            foreach (property_t p in properties)
            {
                if (p.name == "Operator")
                {
                    comparatorName = p.value;
                }
                else if (p.name == "Opl")
                {
                    int pParenthesis = p.value.IndexOf('(');
                    if (pParenthesis == -1)
                    {
                        this.m_opl = Condition.LoadLeft(p.value, ref propertyName, null);
                    }
                    else
                    {
                        //method
                        this.m_opl_m = Action.LoadMethod(p.value);
                    }
                }
                else if (p.name == "Opr")
                {
                    this.m_opr = Condition.LoadRight(p.value, propertyName, ref typeName);
                }
                else if (p.name == "BinaryOperator")
                {
                    if (p.value == "Or")
                    {
                        this.m_bAnd = false;
                    }
                    else if (p.value == "And")
                    {
                        this.m_bAnd = true;
                    }
                    else
                    {
                        Debug.Check(false);
                    }
                }
                else
                {
                    //Debug.Check(0, "unrecognised property %s", p.name);
                }
            }

            if (!string.IsNullOrEmpty(comparatorName) && (this.m_opl != null || this.m_opl_m != null) && this.m_opr != null)
            {
                this.m_comparator = Condition.Create(typeName, comparatorName, this.m_opl, this.m_opr);
            }
        }

        protected override BehaviorTask createTask()
        {
            PredicateTask pTask = new PredicateTask();

            return pTask;
        }

        protected Property m_opl;
        protected Property m_opr;
        protected CMethodBase m_opl_m;
        protected VariableComparator m_comparator;
        protected bool m_bAnd;

        // ============================================================================
        public class PredicateTask : AttachmentTask
        {
            public PredicateTask()
            {
            }
            ~PredicateTask()
            {
            }

            public override void copyto(BehaviorTask target)
            {
                base.copyto(target);
            }
            public override void save(ISerializableNode node)
            {
                base.save(node);
            }
            public override void load(ISerializableNode node)
            {
                base.load(node);
            }

            protected override bool onenter(Agent pAgent)
            {
                return true;
            }
            protected override void onexit(Agent pAgent, EBTStatus s)
            {
            }

            protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
            {
                EBTStatus result = EBTStatus.BT_FAILURE;

                Predicate pPredicateNode = this.GetNode() as Predicate;

                if (pPredicateNode.m_comparator != null) 
				{
					bool bResult = Condition.DoCompare (pAgent, pPredicateNode.m_comparator, pPredicateNode.m_opl, pPredicateNode.m_opl_m, pPredicateNode.m_opr);

					if (bResult) 
					{
						result = EBTStatus.BT_SUCCESS;
					}
				}
				else
				{
					result = pPredicateNode.update_impl(pAgent, childStatus);
				}

               	return result;
            }

            public override bool NeedRestart()
            {
                return true;
            }

            public bool IsAnd()
            {
                Predicate pPredicateNode = this.GetNode() as Predicate;
                return pPredicateNode.m_bAnd;
            }
        }
    }
}
