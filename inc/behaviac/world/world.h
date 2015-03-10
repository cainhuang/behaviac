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

#ifndef _BEHAVIAC_WORLD_H_
#define _BEHAVIAC_WORLD_H_

#include "behaviac/base/base.h"
#include "behaviac/agent/agent.h"
#include "behaviac/base/logging/logging.h"
#include "behaviac/base/socket/socketconnect.h"

#include "behaviac/base/core/singleton.h"

namespace behaviac
{
	/*! \addtogroup World	
	* @{ */

	/**
	world's ctor and dtor are protected, so that it can't be instantiated directly and it can only be derived by subclass.

	you should create a world instance by Agent::CreateInstance<YourWorldClass>() before creating any other agents.
	YourWorldClass should derive from World.
	*/
    class BEHAVIAC_API World : public Agent
    {
	private:
		static World* _GetWorld(int contextId);

	public:
		static World* GetInstance(int contextId = 0)
		{
			World* pWorld = World::_GetWorld(contextId);

			return pWorld;
		}

    public:
        DECLARE_BEHAVIAC_OBJECT(behaviac::World, Agent);


		/**
		0. LogManager::GetInstance()->Log("[frame]%d\n", ms_frame++);
		1. HandleRequests, handle network requests from the designer, for debugging purposes
		2. btexec, tick world's bt if any
		3. btexec_agents, tick the agents' bt, if m_bTickAgents == true

		by default, m_bTickAgents is true, it ticks all agents, but if agents' behavior tree are managed and ticked by other system, 
		you need to set m_bTickAgents = false

		@sa ToggleTickAgents
		*/
		virtual EBTStatus btexec();

		/**
		enable/disable ticking agents

		by default, btexec ticks all agents added to it
		*/
		void ToggleTickAgents(bool bTickAgents);

		bool IsTickAgents() const;

		void LogCurrentStates();

		void AddAgent(Agent* pAgent);
		void RemoveAgent(Agent* pAgent);

		void RemoveAllAgents();

		virtual void btreloadall();
	protected:
		World();
		virtual ~World();

		/**
		btexec agents managed by this world
		*/
		void btexec_agents();
	protected:
		typedef behaviac::map<int, Agent*> Agents_t;

		struct HeapItem_t
		{
			int priority;
			Agents_t agents;
		};

		struct HeapFinder_t
		{
			int priority;
			HeapFinder_t(int p) : priority(p)
			{}

			bool operator()(const HeapItem_t& item) const
			{
				return item.priority == priority;
			}
		};

		struct HeapCompare_t
		{
			bool operator()(const HeapItem_t& lhs, const HeapItem_t& rhs) const
			{
				return lhs.priority < rhs.priority;
			}
		};

		typedef behaviac::vector<HeapItem_t> PriorityAgents_t;
		PriorityAgents_t m_agents;
		bool m_bTickAgents;
    };
	/*! @} */
}



#endif//#ifndef _BEHAVIAC_WORLD_H_
