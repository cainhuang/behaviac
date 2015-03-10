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

#include "behaviac/agent/context.h"
#include "behaviac/world/world.h"
#include "behaviac/base/logging/logging.h"
#include "behaviac/base/socket/socketconnect.h"
#include "behaviac/base/file/filesystem.h"
#include "behaviac/property/property.h"

#include "behaviac/base/core/profiler/profiler.h"

BEGIN_PROPERTIES_DESCRIPTION(behaviac::World)
	//
END_PROPERTIES_DESCRIPTION()

namespace behaviac
{
	World::World() : Agent(), m_bTickAgents(true)
	{
	}

	World::~World()
	{
		Context& c = Context::GetContext(this->m_context_id);
		World* pW = c.GetWorld(false);
		BEHAVIAC_UNUSED_VAR(pW);
		BEHAVIAC_ASSERT(pW == 0 || pW == this);
		c.SetWorld(0);
	}


	class BEHAVIAC_API DefaultWorld : public World
	{
	public:
		DECLARE_BEHAVIAC_OBJECT(DefaultWorld, World);

		DefaultWorld()
		{
		}

		virtual ~DefaultWorld()
		{
		}
	};


	BEGIN_PROPERTIES_DESCRIPTION(DefaultWorld)
		//
	END_PROPERTIES_DESCRIPTION()

		
	World* CreateDefaultWorld(int contextId)
	{
		World* pWorld = Agent::Create<DefaultWorld>(0, contextId);	

		return pWorld;
	}


	World* World::_GetWorld(int contextId)
	{
		Context& c = Context::GetContext(contextId);
		World* pWorld = c.GetWorld();

		BEHAVIAC_ASSERT(pWorld);

		return pWorld;
	}

	void World::AddAgent(Agent* pAgent)
	{
		ASSERT_MAIN_THREAD();

		int agentId = pAgent->GetId();
		int priority = pAgent->GetPriority();
		PriorityAgents_t::iterator it = std::find_if(this->m_agents.begin(), this->m_agents.end(), HeapFinder_t(priority));
		if (it == this->m_agents.end())
		{
			HeapItem_t pa;
			pa.priority = priority;
			pa.agents[agentId] = pAgent;
			this->m_agents.push_back(pa);
		}
		else
		{
			HeapItem_t& pa = *it;
			pa.agents[agentId] = pAgent;
		}
	}

	void World::RemoveAgent(Agent* pAgent)
	{
		ASSERT_MAIN_THREAD();

		int agentId = pAgent->GetId();
		int priority = pAgent->GetPriority();

		PriorityAgents_t::iterator it = std::find_if(this->m_agents.begin(), this->m_agents.end(), HeapFinder_t(priority));

		if (it != this->m_agents.end())
		{
			HeapItem_t& pa = *it;

			Agents_t::iterator ita = pa.agents.find(agentId);
			if (ita != pa.agents.end())
			{
				pa.agents.erase(ita);
			}
		}
	}

	void World::RemoveAllAgents()
	{
		ASSERT_MAIN_THREAD();

		this->m_agents.clear();
	}


	void World::LogCurrentStates()
	{
		if (Config::IsLoggingOrSocketing())
		{
			//force to log vars
			for (PriorityAgents_t::iterator it = this->m_agents.begin(); it != this->m_agents.end(); ++it)
			{
				HeapItem_t& pa = *it;

				for (Agents_t::iterator ita = pa.agents.begin(); ita != pa.agents.end(); ++ita)
				{
					Agent* pA = ita->second;

					if (this->IsMasked())
					{
						pA->LogVariables(true);
					}
				}
			}

			if (this->IsMasked())
			{
				this->LogVariables(true);
			}
		}
	}

	EBTStatus World::btexec()
	{
		behaviac::Profiler::GetInstance()->BeginFrame();

		Workspace::LogFrames();
		Workspace::HandleRequests();

		if (Workspace::GetAutoHotReload())
		{
			Workspace::HotReload();
		}

		EBTStatus s = super::btexec();
		BEHAVIAC_UNUSED_VAR(s);

		if (this->m_bTickAgents)
		{
			this->btexec_agents();
		}

		behaviac::Profiler::GetInstance()->EndFrame();

		//TODO: BT_INVALID
		return BT_RUNNING;
	}

	void World::ToggleTickAgents(bool bTickAgents)
	{
		this->m_bTickAgents = bTickAgents;
	}

	bool World::IsTickAgents() const
	{
		return this->m_bTickAgents;
	}

	void World::btexec_agents()
	{
		std::make_heap(this->m_agents.begin(), this->m_agents.end(), HeapCompare_t());

		for (PriorityAgents_t::iterator it = this->m_agents.begin(); it != this->m_agents.end(); ++it)
		{
			HeapItem_t& pa = *it;

			for (Agents_t::iterator ita = pa.agents.begin(); ita != pa.agents.end(); ++ita)
			{
				Agent* pA = ita->second;

				if (pA->IsActive())
				{
					pA->btexec();

					//in case m_bTickAgents was set to false by pA's bt
					if (!this->m_bTickAgents)
					{
						break;
					}
				}
			}
		}

		if (Agent::IdMask() != 0)
		{
			int contextId = this->GetContextId();
			Context& c = Context::GetContext(contextId);

			c.LogStaticVariables(0);
		}
	}

	void World::btreloadall()
	{
		Agent::btreloadall();

		for (PriorityAgents_t::iterator it = this->m_agents.begin(); it != this->m_agents.end(); ++it)
		{
			HeapItem_t& pa = *it;

			for (Agents_t::iterator ita = pa.agents.begin(); ita != pa.agents.end(); ++ita)
			{
				Agent* pA = ita->second;

				pA->btreloadall();
			}
		}	
	}

}//namespace behaviac
