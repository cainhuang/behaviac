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
    public class Assignment : BehaviorNode
    {
        public Assignment()
        {
		}
        ~Assignment()
        {
            m_opl = null;
            m_opr = null;
            m_opr_m = null;
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
                else if (p.name == "Opr")
                {
                    int pParenthesis = p.value.IndexOf('(');
                    if (pParenthesis == -1)
                    {
                        string typeName = null;
                        this.m_opr = Condition.LoadRight(p.value, propertyName, ref typeName);
                    }
                    else
                    {
                        //method
                        this.m_opr_m = Action.LoadMethod(p.value);
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
            if (!(pTask.GetNode() is Assignment))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            return new AssignmentTask();
        }

        protected Property m_opl;
        protected Property m_opr;
        protected CMethodBase m_opr_m;

        class AssignmentTask : LeafTask
        {
            public AssignmentTask()
            { }

            ~AssignmentTask()
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

                Debug.Check(this.GetNode() is Assignment);
                Assignment pAssignmentNode = (Assignment)(this.GetNode());

                if (pAssignmentNode.m_opr_m != null)
                {
                    ParentType pt = pAssignmentNode.m_opr_m.GetParentType();
                    Agent pParent = pAgent;
                    if (pt == ParentType.PT_INSTANCE)
                    {
                        pParent = Agent.GetInstance(pAssignmentNode.m_opr_m.GetInstanceNameString(), pParent.GetContextId());
						Debug.Check(pParent != null || Utils.IsStaticClass(pAssignmentNode.m_opr_m.GetInstanceNameString()));
                    }

                    object returnValue = pAssignmentNode.m_opr_m.run(pParent, pAgent);

                    ParentType pt_opl = pAssignmentNode.m_opl.GetParentType();
                    Agent pParentOpl = pAgent;
                    if (pt_opl == ParentType.PT_INSTANCE)
                    {
                        pParentOpl = Agent.GetInstance(pAssignmentNode.m_opl.GetInstanceNameString(), pParentOpl.GetContextId());
						Debug.Check(pParentOpl != null || Utils.IsStaticClass(pAssignmentNode.m_opl.GetInstanceNameString()));
                    }

                    pAssignmentNode.m_opl.SetValue(pParentOpl, returnValue);
                }
                else if (pAssignmentNode.m_opr != null && pAssignmentNode.m_opl != null)
                {
                    Agent pParentL = pAgent;
                    Agent pParentR = pAgent;

                    {
                        ParentType pt = pAssignmentNode.m_opl.GetParentType();
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParentL = Agent.GetInstance(pAssignmentNode.m_opl.GetInstanceNameString(), pParentL.GetContextId());
							Debug.Check(pParentL != null || Utils.IsStaticClass(pAssignmentNode.m_opl.GetInstanceNameString()));
                        }
                    }
                    {
                        ParentType pt = pAssignmentNode.m_opr.GetParentType();
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParentR = Agent.GetInstance(pAssignmentNode.m_opr.GetInstanceNameString(), pParentR.GetContextId());

                            //it is a const
                            if (pParentR == null)
                            {
                                pParentR = pParentL;
                            }
                        }
                    }

                    pAssignmentNode.m_opl.SetFrom(pParentR, pAssignmentNode.m_opr, pParentL);
                }
                else
                {
                    result = pAssignmentNode.update_impl(pAgent, childStatus);
                }

                return result;
            }
        }
    }
}
