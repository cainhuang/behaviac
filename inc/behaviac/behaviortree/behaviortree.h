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

#ifndef BEHAVIAC_BEHAVIORTREE_NODE_H_
#define BEHAVIAC_BEHAVIORTREE_NODE_H_

#include "behaviac/base/base.h"

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/object/tagobject.h"
#include "behaviac/base/core/factory.h"

#include "behaviac/base/workspace.h"

#include "behaviac/property/property.h"

#include "behaviac/base/core/rapidxml/rapidxml.hpp"

/*! \mainpage Behaviac Help Home Page
\section secOverview Overview
Behaviac is a system, the purpose of which is to streamline the iterative process of designing, 
integrating and debugging behavioral AI via behavior trees.Most behavior tree implementation, 
though generally working under the same principles, differ slightly in their definition of the 
practical method of behavior trees. if you are completely new to behavior trees then you are 
supposed to google some papers to learn first.

The structure of a tree is defined by a number of interconnected control nodes, ending in leaf nodes actions. 
Actions are the interfaces to your agent code. A btexe of a tree flows left to right, evaluating branching based 
on tree state and then bottom to top, propagating result values and updating the tree state.

Each control node has its own rule set setting it apart defining which child node it ticks and how it responds to the 
result of it Success/Failure or Running. In general, though, a result of Running (indicating more processing needed)
will always make sure that the child in question gets evaluated again next tick.

All nodes hold a tiny bit of state to indicate the current execution flow state such as the index of the last ticked 
child for sequences and selectors. This state is updated in accordance with the rule-set of the node in question in 
response to the result of the current tick.

With a few exceptions, once a node has updated its state, it also completes returning a result of Success/Failure or Running 
to its parent node. Generally this means that any tree tick will result in at least one action node ticked.The result of 
the root node is the result of the entire tree execution Running indicating that the tree has not completed and
Success/Failure indicating a complete run and its result.
*/


namespace behaviac
{
	const int INVALID_NODE_ID = -2;

	class Property;
	class Agent;
	class BehaviorTask;
	class BehaviorTreeTask;
	class Attachment;
	class BsonDeserizer;

	BEHAVIAC_API CMethodBase* LoadMethod(const char* value);

    /**
    * Base class for BehaviorTree Nodes. This is the static part
    */
    class BEHAVIAC_API BehaviorNode : public CDynamicType
	{
	public:
        template<typename T>
        static bool Register()
        {
            Factory().Register<T>();

			return true;
        }

        template<typename T>
        static void UnRegister()
        {
            Factory().UnRegister<T>();
        }

        static BehaviorNode* Create(const char* className);
		static void Cleanup();

	private:
		static CFactory<BehaviorNode>& Factory();

	public:
		BehaviorTask* CreateAndInitTask() const;
		bool HasEvents() const;
		void SetHasEvents(bool hasEvents);

		uint32_t GetChildrenCount() const;
		const BehaviorNode* GetChild(uint32_t index) const;

		uint32_t GetAttachmentsCount() const;
		const BehaviorNode* GetAttachment(uint32_t index) const;

		void Clear();

	protected:		
        BEHAVIAC_DECLARE_MEMORY_OPERATORS(BehaviorNode);
        BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(BehaviorNode, CDynamicType);

		BehaviorNode();
		virtual ~BehaviorNode();

		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

		virtual void load(int version, const char* agentType, const properties_t& properties);

		void load_par(int version, const char* agentType, rapidxml::xml_node<>* node);
		void load_properties(int version, const char* agentType, rapidxml::xml_node<>* node);
		void load_properties_pars(int version, const char* agentType, rapidxml::xml_node<>* node);
		void load_attachments(int version, const char* agentType, rapidxml::xml_node<>* node);
		void load_properties_pars_attachments_children(int version, const char* agentType, rapidxml::xml_node<>* node);
		BehaviorNode* load(const char* agentType, rapidxml::xml_node<>* node);

		void load_par(int version, const char* agentType, BsonDeserizer& d);
		void load_pars(int version, const char* agentType, BsonDeserizer& d);
		void load_properties(int version, const char* agentType, BsonDeserizer& d);
		void load_attachments(int version, const char* agentType, BsonDeserizer& d);
		void load_children(int version, const char* agentType, BsonDeserizer& d);
		void load_properties_pars_attachments_children(int version, const char* agentType, BsonDeserizer& d);
		BehaviorNode* load(const char* agentType, BsonDeserizer& d);

		void Attach(BehaviorNode* pAttachment);
		virtual void AddChild(BehaviorNode* pChild);

		void SetClassNameString(const char* className);
		const behaviac::string& GetClassNameString() const;

		int GetId() const;
		void SetId(int id);

		void SetAgentType(const behaviac::string& agentType);

		void AddPar(const char* type, const char* name, const char* value, const char* eventParam);

	private:
		virtual BehaviorTask* createTask() const = 0;

		virtual bool enteraction_impl(Agent* pAgent) { BEHAVIAC_UNUSED_VAR(pAgent); return false; }
		virtual bool exitaction_impl(Agent* pAgent) { BEHAVIAC_UNUSED_VAR(pAgent); return false; }

	private:
        static CFactory<BehaviorNode>* ms_factory;

		behaviac::string		m_className;
		int						m_id;
        behaviac::string		m_agentType;

	protected:
		typedef behaviac::vector<BehaviorNode*> Attachments;
        Attachments*		m_attachments;

		typedef behaviac::vector<Property*> Properties_t;
		Properties_t*		m_pars;

		BehaviorNode*		m_parent;
		typedef behaviac::vector<BehaviorNode*> Nodes;
		Nodes*				m_children;

		CMethodBase*		m_enterAction;
		CMethodBase*		m_exitAction;

		bool				m_bHasEvents;

		friend class BehaviorTree;
		friend class BehaviorTask;
		friend class Agent;
	};


    class BEHAVIAC_API DecoratorNode : public BehaviorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNode, BehaviorNode);

        DecoratorNode();
        virtual ~DecoratorNode();
        virtual void load(int version, const char* agentType, const properties_t& properties);

	protected:
		virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

	private:
		//virtual BehaviorTask* createTask() const;

	protected:
        bool m_bDecorateWhenChildEnds;

		friend class DecoratorTask;
    };

	// ============================================================================
    class BEHAVIAC_API BehaviorTree : public BehaviorNode
    {
	public:
		/**
		return the path relative to the workspace path
		*/
		const behaviac::string& GetName() const
		{
			return this->m_name;
		}

		void SetName(const char* name)
		{
			this->m_name = name;
		}

		const behaviac::string& GetDomains() const;
		void SetDomains(const behaviac::string& domains);

		struct Descriptor_t
		{
			Property*			Descriptor;
			Property*			Reference;

			Descriptor_t() : Descriptor(0), Reference(0)
			{}

			Descriptor_t(const Descriptor_t& copy)
				: Descriptor(copy.Descriptor ? copy.Descriptor->clone() : NULL)
				, Reference(copy.Reference ? copy.Reference->clone() : NULL)
			{}

			~Descriptor_t()
			{
				BEHAVIAC_DELETE(this->Descriptor);
				BEHAVIAC_DELETE(this->Reference);
			}

			DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL(BehaviorTree::Descriptor_t);
		};

		typedef behaviac::vector<Descriptor_t>	Descriptors_t;
		const Descriptors_t GetDescriptors() const;
		void SetDescriptors(const char* descriptors);

    protected:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(BehaviorTree);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(BehaviorTree, BehaviorNode);
        BehaviorTree();
		virtual ~BehaviorTree();
		virtual void load(int version, const char* agentType, const properties_t& properties);

	private:
		virtual BehaviorTask* createTask() const;
        bool load_xml(char* pBuffer);
		bool load_bson(const char* pBuffer);

	protected:
		behaviac::string			m_name;
		behaviac::string			m_domains;
		Descriptors_t				m_descriptorRefs;

		friend class BehaviorTreeTask;
		friend class BehaviorNode;
		friend class Workspace;
    };
} // namespace behaviac

#endif//BEHAVIAC_BEHAVIORTREE_NODE_H_
