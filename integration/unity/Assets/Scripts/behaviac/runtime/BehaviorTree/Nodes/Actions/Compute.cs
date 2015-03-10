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

using System;
using System.Collections;
using System.Collections.Generic;

namespace behaviac
{
    public enum EComputeOperator
    {
        E_INVALID,
        E_ADD,
        E_SUB,
        E_MUL,
        E_DIV
    }

    public class Compute : BehaviorNode
    {
        public Compute()
        {
		}
        ~Compute()
        {
            m_opl = null;
            m_opr1 = null;
            m_opr1_m = null;
            m_opr2 = null;
            m_opr2_m = null;
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);

            string propertyName = null;

            foreach (property_t p in properties)
            {
                if (p.name == "Opl")
                {
                    this.m_opl = Condition.LoadLeft(p.value, ref propertyName, null);
                }
                else if (p.name == "Operator")
                {
                    if (p.value == "Add")
                    {
                        this.m_operator = EComputeOperator.E_ADD;
                    }
                    else if (p.value == "Sub")
                    {
                        this.m_operator = EComputeOperator.E_SUB;
                    }
                    else if (p.value == "Mul")
                    {
                        this.m_operator = EComputeOperator.E_MUL;
                    }
                    else if (p.value == "Div")
                    {
                        this.m_operator = EComputeOperator.E_DIV;
                    }
                    else
                    {
                        Debug.Check(false);
                    }
                }
                else if (p.name == "Opr1")
                {
                    int pParenthesis = p.value.IndexOf('(');
                    if (pParenthesis == -1)
                    {
                        string typeName = null;
                        this.m_opr1 = Condition.LoadRight(p.value, propertyName, ref typeName);
                    }
                    else
                    {
                        //method
                        this.m_opr1_m = Action.LoadMethod(p.value);
                    }
                }
                else if (p.name == "Opr2")
                {
                    int pParenthesis = p.value.IndexOf('(');
                    if (pParenthesis == -1)
                    {
                        string typeName = null;
                        this.m_opr2 = Condition.LoadRight(p.value, propertyName, ref typeName);
                    }
                    else
                    {
                        //method
                        this.m_opr2_m = Action.LoadMethod(p.value);
                    }
                }
                else
                {
                    //Debug.Check(0, "unrecognised property %s", p.name);
                }
            }
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is Compute))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            return new ComputeTask();
        }

        protected Property m_opl;
        protected Property m_opr1;
        protected CMethodBase m_opr1_m;
        protected Property m_opr2;
        protected CMethodBase m_opr2_m;
        protected EComputeOperator m_operator = EComputeOperator.E_INVALID;

        class ComputeTask : LeafTask
        {
            public ComputeTask()
            {
			}

            ~ComputeTask()
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

            protected override bool isContinueTicking()
            {
                return false;
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
                EBTStatus result = EBTStatus.BT_SUCCESS;

                Debug.Check(this.GetNode() is Compute);
                Compute pComputeNode = (Compute)(this.GetNode());

                bool bValid = false;
                object value1 = null;

                if (pComputeNode.m_opl != null)
                {
                    if (pComputeNode.m_opr1_m != null)
                    {
                        bValid = true;
                        ParentType pt = pComputeNode.m_opr1_m.GetParentType();
                        Agent pParent = pAgent;
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParent = Agent.GetInstance(pComputeNode.m_opr1_m.GetInstanceNameString(), pParent.GetContextId());
							Debug.Check(pParent != null || Utils.IsStaticClass(pComputeNode.m_opr1_m.GetInstanceNameString()));
                        }

                        value1 = pComputeNode.m_opr1_m.run(pParent, pAgent);
                    }
                    else if (pComputeNode.m_opr1 != null)
                    {
                        bValid = true;
                        Agent pParentL = pAgent;
                        Agent pParentR = pAgent;

                        {
                            ParentType pt = pComputeNode.m_opl.GetParentType();
                            if (pt == ParentType.PT_INSTANCE)
                            {
                                pParentL = Agent.GetInstance(pComputeNode.m_opl.GetInstanceNameString(), pParentL.GetContextId());
								Debug.Check(pParentL != null || Utils.IsStaticClass(pComputeNode.m_opl.GetInstanceNameString()));
                            }
                        }
                        {
                            ParentType pt = pComputeNode.m_opr1.GetParentType();
                            if (pt == ParentType.PT_INSTANCE)
                            {
                                pParentR = Agent.GetInstance(pComputeNode.m_opr1.GetInstanceNameString(), pParentR.GetContextId());

                                //it is a const
                                if (pParentR == null)
                                {
                                    pParentR = pParentL;
                                }
                            }
                        }

                        pComputeNode.m_opl.SetFrom(pParentR, pComputeNode.m_opr1, pParentL);

                        value1 = pComputeNode.m_opl.GetValue(pParentL);
                    }

                    if (pComputeNode.m_opr2_m != null)
                    {
                        bValid = true;
                        ParentType pt = pComputeNode.m_opr2_m.GetParentType();
                        Agent pParent = pAgent;
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParent = Agent.GetInstance(pComputeNode.m_opr2_m.GetInstanceNameString(), pParent.GetContextId());
							Debug.Check(pParent != null || Utils.IsStaticClass(pComputeNode.m_opr2_m.GetInstanceNameString()));
                        }

                        object value2 = pComputeNode.m_opr2_m.run(pParent, pAgent);

                        ParentType pt_opl = pComputeNode.m_opl.GetParentType();
                        Agent pParentOpl = pAgent;
                        if (pt_opl == ParentType.PT_INSTANCE)
                        {
                            pParentOpl = Agent.GetInstance(pComputeNode.m_opl.GetInstanceNameString(), pParentOpl.GetContextId());
							Debug.Check(pParentOpl != null || Utils.IsStaticClass(pComputeNode.m_opl.GetInstanceNameString()));
                        }

                        object returnValue = Details.ComputeValue(value1, value2, pComputeNode.m_operator);

                        pComputeNode.m_opl.SetValue(pParentOpl, returnValue);
                    }
                    else if (pComputeNode.m_opr2 != null)
                    {
                        bValid = true;
                        Agent pParentL = pAgent;
                        Agent pParentR = pAgent;

                        {
                            ParentType pt = pComputeNode.m_opl.GetParentType();
                            if (pt == ParentType.PT_INSTANCE)
                            {
                                pParentL = Agent.GetInstance(pComputeNode.m_opl.GetInstanceNameString(), pParentL.GetContextId());
								Debug.Check(pParentL != null || Utils.IsStaticClass(pComputeNode.m_opl.GetInstanceNameString()));
                            }
                        }
                        {
                            ParentType pt = pComputeNode.m_opr2.GetParentType();
                            if (pt == ParentType.PT_INSTANCE)
                            {
                                pParentR = Agent.GetInstance(pComputeNode.m_opr2.GetInstanceNameString(), pParentR.GetContextId());

                                //it is a const
                                if (pParentR == null)
                                {
                                    pParentR = pParentL;
                                }
                            }
                        }

                        object value2 = pComputeNode.m_opr2.GetValue(pParentR);

                        object returnValue = Details.ComputeValue(value1, value2, pComputeNode.m_operator);

                        pComputeNode.m_opl.SetValue(pParentL, returnValue);
                    }
                }

                if (!bValid)
                {
                    result = pComputeNode.update_impl(pAgent, childStatus);
                }

                return result;
            }
        }
    }
}
