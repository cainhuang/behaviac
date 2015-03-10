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
using System.IO;
using System.Reflection;
using UnityEngine;

namespace behaviac
{
    public class World : Agent
    {
        protected World()
        {
        }

        protected new void OnDestroy()
        {
            Context c = Context.GetContext(this.m_contextId);
            World pW = c.GetWorld(false);

            if (pW == this)
            {
                c.SetWorld(null);
            }

            base.OnDestroy();
        }

        protected new void Init()
        {
            Context c = Context.GetContext(this.m_contextId);
            c.SetWorld(this);

            base.Init();
            m_bTickAgents = true;
        }

        public static World GetInstance(int contextId)
        {
            Context c = Context.GetContext(contextId);
            World pWorld = c.GetWorld(true);

            Debug.Check(pWorld != null);

            return pWorld;
        }


        public struct HeapItem_t : IComparable<HeapItem_t>
        {
            public int priority;
            public Dictionary<int, Agent> agents;

            public int CompareTo(HeapItem_t other)
            {
                if (this.priority < other.priority)
                {
                    return -1;
                }
                else if (this.priority > other.priority)
                {
                    return 1;
                }

                return 0;
            }
        }

        List<HeapItem_t> m_agents;
        public List<HeapItem_t> Agents
        {
            get
            {
                if (m_agents == null)
                {
                    m_agents = new List<HeapItem_t>();
                }

                return m_agents;
            }
            set
            {
                m_agents = value;
            }
        }

        bool m_bTickAgents;

        public void AddAgent(Agent pAgent)
        {
            //ASSERT_MAIN_THREAD();
            int agentId = pAgent.GetId();
            int priority = pAgent.GetPriority();
            int itemIndex = this.Agents.FindIndex(delegate(HeapItem_t h) { return h.priority == priority; });

            if (itemIndex == -1)
            {
                HeapItem_t pa = new HeapItem_t();
                pa.agents = new Dictionary<int, Agent>();
                pa.priority = priority;
                pa.agents[agentId] = pAgent;
                this.Agents.Add(pa);
            }
            else
            {
                this.Agents[itemIndex].agents[agentId] = pAgent;
            }
        }

        public void RemoveAgent(Agent pAgent)
        {
            //ASSERT_MAIN_THREAD();

            int agentId = pAgent.GetId();
            int priority = pAgent.GetPriority();
            int itemIndex = this.Agents.FindIndex(delegate(HeapItem_t h) { return h.priority == priority; });

            if (itemIndex != -1)
            {
                if (this.Agents[itemIndex].agents.ContainsKey(agentId))
                {
                    this.Agents[itemIndex].agents.Remove(agentId);
                }
            }
        }

        public void RemoveAllAgents()
        {
            //ASSERT_MAIN_THREAD();

            this.Agents.Clear();
        }

        public override EBTStatus btexec()
        {
            //behaviac.Profiler.GetInstance().BeginFrame();
			Workspace.LogFrames ();
            Workspace.HandleRequests();

            if (Workspace.GetAutoHotReload())
            {
                Workspace.HotReload();
            }

            /*EBTStatus s = */base.btexec();

            if (this.m_bTickAgents)
            {
                this.btexec_agents();
            }

            //behaviac.Profiler.GetInstance().EndFrame();

            //TODO:return invalid or s?
            return EBTStatus.BT_RUNNING;
        }

        public void ToggleTickAgents(bool bTickAgents)
        {
            this.m_bTickAgents = bTickAgents;
        }

        public bool IsTickAgents()
        {
            return this.m_bTickAgents;
        }

        void btexec_agents()
        {
            this.Agents.Sort();

			for (int i = 0; i < this.Agents.Count; ++i)
            {
				HeapItem_t pa = this.Agents[i];
                foreach (Agent pA in pa.agents.Values)
                {
                    if (pA.IsActive())
                    {
                        pA.btexec();

                        //in case m_bTickAgents was set to false by pA's bt
                        if (!this.m_bTickAgents)
                        {
                            break;
                        }
                    }
                }
            }

            if (Agent.IdMask() != 0)
            {
                int contextId = this.GetContextId();
                Context c = Context.GetContext(contextId);

                c.LogStaticVariables(null);
            }
        }

        #region SocketLog
        public void LogCurrentStates()
        {
            string msg = string.Format("LogCurrentStates {0} {1}", this.GetClassTypeName(), this.Agents.Count);
            behaviac.Debug.Log(msg);

            //force to log vars
            foreach (HeapItem_t pa in this.Agents)
            {
                foreach (Agent pA in pa.agents.Values)
                {
                    if (pA.IsMasked())
                    {
                        pA.LogVariables(true);
                    }
                }
            }

            if (this.IsMasked())
            {
                this.LogVariables(true);
            }
        }
		#endregion
	}
}