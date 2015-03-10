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
    public class WaitforSignal : BehaviorNode
    {
        public WaitforSignal()
        {
		}

        ~WaitforSignal()
        {
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is WaitforSignal))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            WaitforSignalTask pTask = new WaitforSignalTask();

            return pTask;
        }
    }

    // ============================================================================
    class WaitforSignalTask : SingeChildTask
    {
        public WaitforSignalTask()
            : base()
        {
            m_bTriggered = false;
        }
        ~WaitforSignalTask()
        {
        }

        public override void copyto(BehaviorTask target)
        {
            base.copyto(target);

            Debug.Check(target is WaitforSignalTask);
            WaitforSignalTask ttask = (WaitforSignalTask)target;

            ttask.m_bTriggered = this.m_bTriggered;
        }

        public override void save(ISerializableNode node)
        {
            base.save(node);

            CSerializationID triggeredId = new CSerializationID("triggered");
            node.setAttr(triggeredId, this.m_bTriggered);
        }

        public override void load(ISerializableNode node)
        {
            base.load(node);
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
        }

		public override bool CheckPredicates(Agent pAgent)
		{
			//when there are no predicates, not triggered
			bool bTriggered = false;
			if (this.m_attachments != null)
			{
				bTriggered = base.CheckPredicates(pAgent);
			}

			return bTriggered;
		}

        protected override bool onenter(Agent pAgent)
        {
			this.m_bTriggered = false;

            return true;
        }

        protected override void onexit(Agent pAgent, EBTStatus s)
        {
        }

        protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            if (childStatus != EBTStatus.BT_RUNNING)
            {
                return childStatus;
            }

            if (!this.m_bTriggered)
            {
                this.m_bTriggered = this.CheckPredicates(pAgent);
            }

            if (this.m_bTriggered)
            {
                if (this.m_root == null)
                {
                    return EBTStatus.BT_SUCCESS;
                }

                EBTStatus status = base.update(pAgent, childStatus);

                return status;
            }

            return EBTStatus.BT_RUNNING;
        }

        protected override bool isContinueTicking()
        {
            //return !this.m_bTriggered;
            return true;
        }

        bool m_bTriggered;
    }
}