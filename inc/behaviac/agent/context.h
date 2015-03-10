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

#ifndef _BEHAVIAC_CONTEXT_H_
#define _BEHAVIAC_CONTEXT_H_

#include "behaviac/base/base.h"

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/core/factory.h"
#include "behaviac/base/object/tagobject.h"
#include "behaviac/base/core/string/stringid.h"
#include "behaviac/base/string/stringutils.h"

#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/agent/state.h"

class CNamedEvent;

namespace behaviac
{
	class Property;
	class World;
	class Agent;
	class BehaviorTreeTask;
	class Variables;
	class State_t;

	/*! \addtogroup Agent
	* @{
	* \addtogroup Context
	* @{ */

	/// The Context class
	/*!
	I don't know what is this!
	*/
	class BEHAVIAC_API Context
	{
	private:
		typedef behaviac::map<int, Context*> Contexts_t;
		static Contexts_t* ms_contexts;

	public:
		static Context& GetContext(int contextId);

		/**
		to cleanup the specified context.

		by default, contextId = -1, it cleans up all the contexts
		*/
		static void Cleanup(int contextId = -1);

		static void LogCurrentStates();

	public:
		virtual ~Context();

		void SetWorld(World* pWorld);

		/// return the world, if bCreate == true, it will create a world if there is not one yet
		World* GetWorld(bool bCreate = true);

		void ResetChangedVariables();

		/**
		log changed static variables(propery) for the specified agent class or all agent classes

		@param agentClassName
		if null, it logs for all the agent class
		*/
		void LogStaticVariables(const char* agentClassName = 0);

		/**
		if staticClassName is no null, it is for static variable
		*/
		template<typename VariableType>
		void SetStaticVariable(const CMemberBase* pMember, const char* variableName, const VariableType& value, const char* staticClassName, uint32_t varableId);

		const CNamedEvent* FindEventStatic(const char* eventName, const char* className);
		void InsertEventGlobal(const char* className, CNamedEvent* pEvent);
		CNamedEvent* FindNamedEventTemplate(const CTagObject::MethodsContainer& methods, const char* eventName);

		/**
		bind 'agentInstanceName' to 'pAgentInstance'. 
		'agentInstanceName' should have been registered to the class of 'pAgentInstance' or its parent class.

		@sa RegisterName
		*/
		bool BindInstance(const char* agentInstanceName, Agent* pAgentInstance);

		/**
		unbind 'agentInstanceName' from 'pAgentInstance'. 
		'agentInstanceName' should have been bound to 'pAgentInstance'.

		@sa RegisterName, BindInstance, CreateInstance
		*/
		bool UnbindInstance(const char* agentInstanceName);

		Agent* GetInstance(const char* agentInstanceName);

		bool Save(States_t& states);
		bool Load(const States_t& states);

	protected:
		Context(int contextId);

		void CleanupStaticVariables();
		void CleanupInstances();

	private:
		typedef behaviac::map<behaviac::string, Agent*> NamedAgents_t;
		NamedAgents_t m_namedAgents;
	
		typedef behaviac::map<behaviac::string, Variables> AgentTypeStaticVariables_t;
		AgentTypeStaticVariables_t	m_static_variables;

		typedef behaviac::map<CStringID, CNamedEvent*> AgentEvents_t;
		typedef behaviac::map<behaviac::string, AgentEvents_t> AgentStaticEvents_t;
		AgentStaticEvents_t	ms_eventInfosGlobal;

		int m_context_id;
		World*	m_world;
		bool	m_bCreatedByMe;

	};
	/*! @} */
	/*! @} */
}

#include "context.inl"


#endif//#ifndef _BEHAVIAC_CONTEXT_H_
