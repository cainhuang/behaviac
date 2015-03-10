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
    public class ReferencedBehavior : BehaviorNode
    {
        public ReferencedBehavior()
        {
		}

        ~ReferencedBehavior()
        {
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);

            foreach (property_t p in properties)
            {
                if (p.name == "ReferenceFilename")
                {
                    this.m_referencedBehaviorPath = p.value;

                    bool bOk = Workspace.Load(this.m_referencedBehaviorPath);

                    Debug.Check(bOk);
                }
                else
                {
                    //Debug.Check(0, "unrecognised property %s", p.name);
                }
            }
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is ReferencedBehavior))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            ReferencedBehaviorTask pTask = new ReferencedBehaviorTask();

            return pTask;
        }

        protected string m_referencedBehaviorPath;

        class ReferencedBehaviorTask : SingeChildTask
        {
            public ReferencedBehaviorTask()
            {
			}
            ~ReferencedBehaviorTask()
            {
            }

            public override void Init(BehaviorNode node)
            {
                base.Init(node);
            }

            public override void copyto(BehaviorTask target)
            {
                base.copyto(target);

                // Debug.Check(target is ReferencedBehaviorTask);
                // ReferencedBehaviorTask ttask = (ReferencedBehaviorTask)target;
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
                return true;
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
                Debug.Check(m_returnStatus == EBTStatus.BT_INVALID);
                ReferencedBehavior pNode = this.GetNode() as ReferencedBehavior;

                if (pNode != null)
                {
                    string pThisTree = pAgent.btgetcurrent().GetName();
                    string msg = string.Format("{0}[{1}] {2}", pThisTree, pNode.GetId(), pNode.m_referencedBehaviorPath);

			        LogManager.Log(pAgent, msg, EActionResult.EAR_none, LogMode.ELM_jump);

                    pAgent.btreferencetree(pNode.m_referencedBehaviorPath);
                }

                return EBTStatus.BT_RUNNING;
            }
        }
    }
}