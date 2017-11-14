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

#ifndef BEHAVIAC_HTN_AGENTSTATE_H
#define BEHAVIAC_HTN_AGENTSTATE_H
#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/property/properties.h"
#include "behaviac/base/core/thread/mutex.h"

#define BEHAVIAC_ENABLE_PUSH_OPT	1

namespace behaviac
{
    class BEHAVIAC_API AgentState : public Variables
    {
    public:
        struct AgentStateScope
        {
            AgentState* m_state;
            AgentStateScope(AgentState* currentState) : m_state(currentState)
            {

            }

            ~AgentStateScope()
            {
                m_state->Pop();
            }
        };
    private:

        behaviac::vector<AgentState*>			state_stack;
        static behaviac::Mutex					ms_mutex;
        static behaviac::vector<AgentState*>	pool;
        AgentState* 							parent;
#if BEHAVIAC_ENABLE_PUSH_OPT
        bool									m_forced;
        int										m_pushed;
#endif
    public:
        AgentState();
        virtual ~AgentState();
        AgentState(AgentState* parent);
        void Dispose();
        int Depth();
        int Top();
        AgentState* Push(bool bForcePush);
        void Pop();
        void Log(Agent* pAgent, bool bForce);

		virtual void Clear(bool bFull);

        template<typename VariableType>
        void Set(bool bMemberSet, Agent* pAgent, bool bLocal, const behaviac::CMemberBase* pMember, const char* variableName, const VariableType& value, uint32_t varId = 0);

        template<typename VariableType>
        const VariableType* Get(const Agent* pAgent, bool bMemberGet, const behaviac::CMemberBase* pMember, uint32_t varId) const;

    private:
        void PopTop();
    };
}
#endif
