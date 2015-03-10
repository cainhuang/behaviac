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
    public class SelectorLoop : BehaviorNode
    {
        public SelectorLoop()
        {
		}
        ~SelectorLoop()
        {
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is SelectorLoop))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            SelectorLoopTask pTask = new SelectorLoopTask();

            return pTask;
        }

        //List<BehaviorNode> m_preconditions;
        //List<BehaviorNode> m_actions;

        // ============================================================================
        /**
        behavives similarly to SelectorTask, i.e. executing chidren until the first successful one.
	
        however, in the following ticks, it constantly monitors the higher priority nodes. 
        if any one's precondtion node returns success, it picks it and execute it, and before executing, 
        it first cleans up the original executing one.

        all its children are WithPreconditionTask or its derivatives.
        */
        public class SelectorLoopTask : CompositeTask
        {
            public SelectorLoopTask()
            {
			}

            ~SelectorLoopTask()
            {
            }

            public override void Init(BehaviorNode node)
            {
                base.Init(node);
            }

            protected override void addChild(BehaviorTask pBehavior)
            {
                base.addChild(pBehavior);

                Debug.Check(pBehavior is WithPreconditionTask);
            }

            public override void copyto(BehaviorTask target)
            {
                base.copyto(target);

                Debug.Check(target is SelectorLoopTask);
                SelectorLoopTask ttask = (SelectorLoopTask)target;

                ttask.m_activeChildIndex = this.m_activeChildIndex;
            }

            public override void save(ISerializableNode node)
            {
                base.save(node);

                CSerializationID activeChildId = new CSerializationID("activeChild");
                node.setAttr(activeChildId, this.m_activeChildIndex);
            }

            public override void load(ISerializableNode node)
            {
                base.load(node);
            }

            protected override bool onenter(Agent pAgent)
            {
                //reset the action child as it will be checked in the update
                this.m_activeChildIndex = CompositeTask.InvalidChildIndex;
                Debug.Check(this.m_activeChildIndex == CompositeTask.InvalidChildIndex);

                return base.onenter(pAgent);
            }

            protected override void onexit(Agent pAgent, EBTStatus s)
            {
                base.onexit(pAgent, s);
            }

            protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
            {
                //checking the preconditions and take the first action tree
                int index = (int)-1;
                for (int i = 0; i < this.m_children.Count; ++i)
                {
                    WithPreconditionTask pSubTree = (WithPreconditionTask)this.m_children[i];
                    Debug.Check(pSubTree is WithPreconditionTask);

                    BehaviorTask pPrecondTree = pSubTree.PreconditionNode();

                    EBTStatus status = pPrecondTree.exec(pAgent);

                    if (status == EBTStatus.BT_SUCCESS)
                    {
                        index = i;
                        break;
                    }
                }

                //clean up the current ticking action tree
                if (index != (int)-1)
                {
                    if (this.m_activeChildIndex != CompositeTask.InvalidChildIndex)
                    {
                        WithPreconditionTask pCurrentSubTree = (WithPreconditionTask)this.m_children[this.m_activeChildIndex];
                        Debug.Check(pCurrentSubTree is WithPreconditionTask);
                        BehaviorTask pCurrentActionTree = pCurrentSubTree.Action();

                        WithPreconditionTask pSubTree = (WithPreconditionTask)this.m_children[index];
                        Debug.Check(pSubTree is WithPreconditionTask);

                        BehaviorTask pActionTree = pSubTree.Action();

                        if (pCurrentActionTree != pActionTree)
                        {
                            pCurrentActionTree.abort(pAgent);

                            pCurrentSubTree.abort(pAgent);

                            this.m_activeChildIndex = index;
                        }
                    }

                    for (int i = 0; i < this.m_children.Count; ++i)
                    {
                        WithPreconditionTask pSubTree = (WithPreconditionTask)this.m_children[i];
                        Debug.Check(pSubTree is WithPreconditionTask);

                        //dummy ticking so that the designer knows it is updating
                        EBTStatus statusDummy = pSubTree.exec(pAgent);
                        Debug.Check(statusDummy == EBTStatus.BT_RUNNING);

                        //when i < index, the precondition is failure, so to continue
                        if (i < index)
                        {
                            continue;
                        }

                        if (i > index)
                        {
                            BehaviorTask pPreconditionTree = pSubTree.PreconditionNode();

                            EBTStatus status = pPreconditionTree.exec(pAgent);

                            //to search for the first one whose precondition is success
                            if (status != EBTStatus.BT_SUCCESS)
                            {
                                continue;
                            }
                        }

                        BehaviorTask pActionTree = pSubTree.Action();

						EBTStatus s = pActionTree.exec(pAgent);

						if (s == EBTStatus.BT_RUNNING)
                        {
                            this.m_activeChildIndex = index;
                        }
                        else
                        {
                            pActionTree.reset(pAgent);

							if (s == EBTStatus.BT_FAILURE || s == EBTStatus.BT_INVALID)
							{
								//THE ACTION failed, to try the next one
								continue;
							}
                        }

						Debug.Check(s == EBTStatus.BT_RUNNING || s == EBTStatus.BT_SUCCESS);

                        return s;
                    }
                }

				return EBTStatus.BT_FAILURE;
            }

            protected override bool isContinueTicking()
            {
                return true;
            }
        }
    }
}