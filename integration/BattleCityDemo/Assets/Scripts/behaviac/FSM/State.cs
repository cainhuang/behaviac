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

using System.Collections.Generic;

namespace behaviac
{
    // ============================================================================
    public class State : Action
    {
        public State()
        {
        }

        ~State()
        {
            m_method = null;
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);
        }

        public override void Attach(BehaviorNode pAttachment, bool bIsPrecondition, bool bIsEffector, bool bIsTransition)
        {
            if (bIsTransition)
            {
                Debug.Check(!bIsEffector && !bIsPrecondition);

                if (this.m_transitions == null)
                {
                    this.m_transitions = new List<Transition>();
                }

                Transition pTransition = pAttachment as Transition;
                Debug.Check(pTransition != null);
                this.m_transitions.Add(pTransition);

                return;
            }

            Debug.Check(bIsTransition == false);
            base.Attach(pAttachment, bIsPrecondition, bIsEffector, bIsTransition);
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is State))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        protected override BehaviorTask createTask()
        {
            StateTask pTask = new StateTask();

            return pTask;
        }

        protected override EBTStatus update_impl(Agent pAgent, EBTStatus childStatus)
        {
            //when no method is specified, use the configured result status
            return this.m_resultOption;
        }

        //nextStateId holds the next state id if it returns running when a certain transition is satisfied
        //otherwise, it returns success or failure if it ends
        public EBTStatus Update(Agent pAgent, out int nextStateId)
        {
            nextStateId = -1;

            //when no method is specified(m_method == null),
            //'update_impl' is used to return the configured result status for both xml/bson and c#
            EBTStatus result = this.Execute(pAgent, EBTStatus.BT_RUNNING);

            bool bTransitioned = UpdateTransitions(pAgent, this, this.m_transitions, ref nextStateId, result);

            if (bTransitioned)
            {
                result = EBTStatus.BT_SUCCESS;
            }

            return result;
        }

        public static bool UpdateTransitions(Agent pAgent, BehaviorNode node, List<Transition> transitions, ref int nextStateId, EBTStatus result)
        {
            bool bTransitioned = false;

            if (transitions != null)
            {
                for (int i = 0; i < transitions.Count; ++i)
                {
                    Transition transition = transitions[i];

                    if (transition.Evaluate(pAgent, result))
                    {
                        nextStateId = transition.TargetStateId;
                        Debug.Check(nextStateId != -1);

                        //transition actions
                        transition.ApplyEffects(pAgent, Effector.EPhase.E_BOTH);

#if !BEHAVIAC_RELEASE
                        if (Config.IsLoggingOrSocketing)
                        {
                            BehaviorTask.CHECK_BREAKPOINT(pAgent, node, "transition", EActionResult.EAR_none);
                        }
#endif
                        bTransitioned = true;

                        break;
                    }
                }
            }

            return bTransitioned;
        }

        protected List<Transition> m_transitions;

        public class StateTask : LeafTask
        {
            public StateTask()
            {
            }

            ~StateTask()
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

            int m_nextStateId = -1;
            public override int GetNextStateId()
            {
                return m_nextStateId;
            }

            protected override bool onenter(Agent pAgent)
            {
                this.m_nextStateId = -1;
                return true;
            }

            protected override void onexit(Agent pAgent, EBTStatus s)
            {
            }

            protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
            {
                Debug.Check(childStatus == EBTStatus.BT_RUNNING);

                Debug.Check(this.GetNode() is State, "node is not an State");
                State pStateNode = (State)(this.GetNode());

                EBTStatus result = pStateNode.Update(pAgent, out this.m_nextStateId);

                return result;
            }

        }

    }
}
