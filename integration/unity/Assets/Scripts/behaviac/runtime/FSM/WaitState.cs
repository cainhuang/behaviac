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
using System.Collections.Generic;

namespace behaviac
{
    public class WaitState : State
    {
        protected bool m_ignoreTimeScale;
        protected Property m_time_var;

        public WaitState()
        {
            this.m_ignoreTimeScale = false;
            this.m_time_var = null;
        }

        ~WaitState()
        {
            this.m_time_var = null;
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);

            foreach (property_t p in properties)
            {
                if (p.name == "IgnoreTimeScale")
                {
                    this.m_ignoreTimeScale = (p.value == "true");

                }
                else if (p.name == "Time")
                {
                    string typeName = null;
                    this.m_time_var = Condition.LoadRight(p.value, ref typeName);
                }
            }
        }

        protected virtual float GetTime(Agent pAgent)
        {
            if (this.m_time_var != null)
            {
                Debug.Check(this.m_time_var != null);
                object timeObj = this.m_time_var.GetValue(pAgent);
                return Convert.ToSingle(timeObj);
            }

            return 0;
        }

        protected override BehaviorTask createTask()
        {
            WaitStateTask pTask = new WaitStateTask();

            return pTask;
        }

        private class WaitStateTask : State.StateTask
        {
            private float m_start;
            private float m_time;

            public WaitStateTask()
            {
                m_start = 0;
                m_time = 0;
            }

            public override void copyto(BehaviorTask target)
            {
                base.copyto(target);

                Debug.Check(target is WaitStateTask);
                WaitStateTask ttask = (WaitStateTask)target;

                ttask.m_start = this.m_start;
                ttask.m_time = this.m_time;
            }

            public override void save(ISerializableNode node)
            {
                base.save(node);

                CSerializationID startId = new CSerializationID("start");
                node.setAttr(startId, this.m_start);

                CSerializationID timeId = new CSerializationID("time");
                node.setAttr(timeId, this.m_time);
            }

            public override void load(ISerializableNode node)
            {
                base.load(node);
            }

            private bool GetIgnoreTimeScale()
            {
                WaitState pWaitNode = this.GetNode() as WaitState;

                return pWaitNode != null ? pWaitNode.m_ignoreTimeScale : false;
            }

            private float GetTime(Agent pAgent)
            {
                WaitState pWaitNode = this.GetNode() as WaitState;

                return pWaitNode != null ? pWaitNode.GetTime(pAgent) : 0;
            }

            protected override bool onenter(Agent pAgent)
            {
                this.m_nextStateId = -1;

                if (this.GetIgnoreTimeScale())
                {
                    this.m_start = Workspace.Instance.TimeSinceStartup * 1000.0f;
                }
                else
                {
                    this.m_start = 0;
                }

                this.m_time = this.GetTime(pAgent);

                return (this.m_time >= 0);
            }

            protected override void onexit(Agent pAgent, EBTStatus s)
            {
            }

            protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
            {
                Debug.Check(childStatus == EBTStatus.BT_RUNNING);
            	Debug.Check(this.m_node is WaitState, "node is not an WaitState");
                WaitState pStateNode = (WaitState)this.m_node;

                if (this.GetIgnoreTimeScale())
                {
                    if (Workspace.Instance.TimeSinceStartup * 1000.0f - this.m_start >= this.m_time)
                    {
                        return EBTStatus.BT_SUCCESS;
                    }
                }
                else
                {
                    this.m_start += Workspace.Instance.DeltaTime * 1000.0f;

                    if (this.m_start >= this.m_time)
                    {
                        EBTStatus result = pStateNode.Update(pAgent, out this.m_nextStateId);

                        return EBTStatus.BT_SUCCESS;
                    }
                }

                return EBTStatus.BT_RUNNING;
            }
        }
    }
}
