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

#ifndef BEHAVIAC_BEHAVIORTREE_TASK_H_
#define BEHAVIAC_BEHAVIORTREE_TASK_H_

#include "behaviac/base/base.h"

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/object/tagobject.h"

namespace behaviac
{
	class Agent;
	class BehaviorNode;
	class BehaviorTask;
	class AttachmentTask;
    // ============================================================================
    /**
    * Return values of exec/update and valid states for behaviors.
    */
    enum EBTStatus
    {
        BT_INVALID,
        BT_SUCCESS,
        BT_FAILURE,
        BT_RUNNING,
    };

	/**
	return the exit status.

	this function is only valid when it is called inside an 'ExitAction' of any Node.

	it should not be called in any other functions.
	*/
	EBTStatus GetNodeExitStatus();

	/**
	return the node id.

	this function is only valid when it is called inside an 'Action' Node.
	other it returns INVALID_NODE_ID.
	*/
	int GetNodeId();

	/**
	trigger mode to control the bt switching and back
	*/
    enum TriggerMode
    {
        TM_Transfer,
        TM_Return
    };

	///return false to stop traversing
	typedef bool (*NodeHandler_t)(BehaviorTask*, Agent*, void* user_data);

	class BranchTask;

	/**
	Base class for the BehaviorTreeTask's runtime execution management.
	*/
    class BEHAVIAC_API BehaviorTask : public CDynamicType
	{
	public:
		static void DestroyTask(BehaviorTask*);

	public:
        BEHAVIAC_DECLARE_MEMORY_OPERATORS(BehaviorTask);
        BEHAVIAC_DECLARE_ROOT_DYNAMIC_TYPE(BehaviorTask, CDynamicType);

		virtual void Init(const BehaviorNode* node) = 0;
		virtual void copyto(BehaviorTask* target) const = 0;
		virtual void save(ISerializableNode* node) const = 0;
		virtual void load(ISerializableNode* node) = 0;


		const behaviac::string& GetClassNameString() const;
		int GetId() const;
		void SetId(int id);

        EBTStatus exec(Agent* pAgent);
		void abort(Agent* pAgent);

		///reset the status to invalid
		void reset(Agent* pAgent);

		EBTStatus GetStatus() const;

		const BehaviorNode* GetNode() const;

		/**
		a branch is a node whose isContinueTicking returns true

		BehaviorTreeTask, DecoratorTask, ParallelTask, SelectorLoopTask, etc.
		*/
		BranchTask* GetParentBranch();

		void SetParent(BranchTask* parent)
		{
			this->m_parent = parent;
		}

		const BranchTask* GetParent() const
		{
			return this->m_parent;
		}
		
		BranchTask* GetParent()
		{
			return this->m_parent;
		}

		virtual void traverse(NodeHandler_t handler, Agent* pAgent, void* user_data) = 0;

		/**
		when a node is ended(success/failure), this dertermines if the exit status(success/failure) should be kept.
		if it needs to restart, then, the exit status is just returned but not kept
		*/
		virtual bool NeedRestart() const
		{
			return false;
		}

		virtual void SetCurrentTask(BehaviorTask* node)
		{
			BEHAVIAC_UNUSED_VAR(node);			
		}

		virtual bool CheckPredicates(Agent* pAgent);

		/**
		return false if the event handling needs to be stopped

		an event can be configured to stop being checked if triggered
		*/
		bool CheckEvents(const char* eventName, Agent* pAgent);

		/**
		return false if the event handling  needs to be stopped
		return true, the event hanlding will be checked furtherly
		*/
		virtual bool onevent(Agent* pAgent, const char* eventName);

		//when resume from sub tree caused by the ReferenceBehavior or Query, the sub tree's return status
		virtual EBTStatus GetReturnStatus() const;
		virtual void SetReturnStatus(EBTStatus status);

		virtual const BehaviorTask* GetTaskById(int id) const;
	protected:
		BehaviorTask();
		virtual ~BehaviorTask();

		/**
		@sa isContinueTicking
		*/
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus) = 0;
        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus status);

		void Clear();

	private:
		///return true if it is continuing running for the next exec
		/**
		this virtual function is used for those nodes which will run continuously in the next exec
		so that the tree can record it to exec it directly in the next exec.

		so usually, the leaf nodes except the condition nodes need to override it to return true.
		the branch nodes usually return false. however, parallel need to return true.
		*/
		virtual bool isContinueTicking() const
		{
			return false;
		}

		friend bool abort_handler(BehaviorTask* task, Agent* pAgent, void* user_data);
		friend bool reset_handler(BehaviorTask* task, Agent* pAgent, void* user_data);
		friend bool checkevent_handler(BehaviorTask* task, Agent* pAgent, void* user_data);

		void Attach(AttachmentTask* pAttachment);
		void InstantiatePars(Agent* pAgent);
		void UnInstantiatePars(Agent* pAgent);

        bool onenter_action(Agent* pAgent);
        void onexit_action(Agent* pAgent, EBTStatus status);

		void FreeAttachments();
	protected:
        EBTStatus				m_status;
		const BehaviorNode* 	m_node;
        BranchTask*				m_parent;
		typedef behaviac::vector<AttachmentTask*> Attachments;
        Attachments*			m_attachments;

	private:
		int						m_id;
		//access m_status
		friend class BranchTask;
		friend class DecoratorTask;

		//access update
		friend class BehaviorTreeTask;
	};

    // ============================================================================
    class BEHAVIAC_API AttachmentTask : public BehaviorTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(AttachmentTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(AttachmentTask, BehaviorTask);

    protected:
        AttachmentTask();
		virtual ~AttachmentTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);
    public:
		virtual void traverse(NodeHandler_t handler, Agent* pAgent, void* user_data);
    };

    // ============================================================================
    class BEHAVIAC_API LeafTask : public BehaviorTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(LeafTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(LeafTask, BehaviorTask);

		virtual void traverse(NodeHandler_t handler, Agent* pAgent, void* user_data);
    protected:
		LeafTask();
		virtual ~LeafTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool isContinueTicking() const
		{
			return true;
		}

		virtual bool onevent(Agent* pAgent, const char* eventName);
    };


    // ============================================================================
    class BEHAVIAC_API BranchTask : public BehaviorTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(BranchTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(BranchTask, BehaviorTask);

		virtual void SetCurrentTask(BehaviorTask* node)
		{
			this->m_currentTask = node;
		}

		const BehaviorTask* GetCurrentTask() const
		{
			return this->m_currentTask;
		}

		virtual EBTStatus GetReturnStatus() const;
		virtual void SetReturnStatus(EBTStatus status);
	protected:
		BranchTask();
		virtual ~BranchTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		EBTStatus tickCurrentNode(Agent* pAgent);

		virtual bool onevent(Agent* pAgent, const char* eventName);

		virtual bool onenter(Agent* pAgent);
		virtual void onexit(Agent* pAgent, EBTStatus s);
		virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
	private:
		//to access isContinueTicking
		friend class BehaviorTask;

		virtual bool isContinueTicking() const
		{
			return false;
		}

		bool oneventCurrentNode(Agent* pAgent, const char* eventName);

	protected:
		//bookmark the current ticking node, it is different from m_activeChildIndex
		BehaviorTask*		m_currentTask;
		//when resume from sub tree caused by the ReferenceBehavior or Query, the sub tree's return status
		EBTStatus			m_returnStatus;
    };

    // ============================================================================
    class BEHAVIAC_API CompositeTask : public BranchTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(CompositeTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(CompositeTask, BranchTask);

		virtual void traverse(NodeHandler_t handler, Agent* pAgent, void* user_data);
    protected:
        CompositeTask();
        virtual ~CompositeTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual void addChild(BehaviorTask* pBehavior);
		virtual const BehaviorTask* GetTaskById(int id) const;
    protected:
		typedef behaviac::vector<BehaviorTask*> BehaviorTasks_t;
        BehaviorTasks_t			m_children;

		//book mark the current child
        uint32_t				m_activeChildIndex;
		static uint32_t InvalidChildIndex;
    };

    // ============================================================================
    class BEHAVIAC_API SingeChildTask : public BranchTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(SingeChildTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(SingeChildTask, BranchTask);

		virtual void traverse(NodeHandler_t handler, Agent* pAgent, void* user_data);
	protected:
        SingeChildTask();
		virtual ~SingeChildTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		virtual void addChild(BehaviorTask* pBehavior);

		virtual const BehaviorTask* GetTaskById(int id) const;
	protected:
		BehaviorTask*	m_root;
    };

    // ============================================================================
    class BEHAVIAC_API DecoratorTask : public SingeChildTask
    {
    public:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(DecoratorTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorTask, SingeChildTask);

	protected:
        DecoratorTask();
		virtual ~DecoratorTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool onenter(Agent* pAgent);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);

		/**
		called when the child's exec returns success or failure.
		please note, it is not called if the child's exec returns running
		*/
        virtual EBTStatus decorate(EBTStatus status) = 0;

	private:
		virtual bool isContinueTicking() const
		{
			return true;
		}

	private:
		bool m_bDecorateWhenChildEnds;
    };

    // ============================================================================
    class BEHAVIAC_API BehaviorTreeTask : public SingeChildTask
    {
	public:
		void SetRootTask(BehaviorTask* pRoot);

		void CopyTo(BehaviorTreeTask* target);

		void Save(ISerializableNode* node) const;
		void Load(ISerializableNode* node);

		EBTStatus resume(Agent* pAgent, EBTStatus status);

		/**
		return the path relative to the workspace path
		*/
		const behaviac::string& GetName() const;

		void Clear();
    protected:
		BEHAVIAC_DECLARE_MEMORY_OPERATORS(BehaviorTreeTask);
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(BehaviorTreeTask, SingeChildTask);

		BehaviorTreeTask();
		virtual ~BehaviorTreeTask();

		virtual void Init(const BehaviorNode* node);
		virtual void copyto(BehaviorTask* target) const;
		virtual void save(ISerializableNode* node) const;
		virtual void load(ISerializableNode* node);

		virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    
		virtual bool NeedRestart() const;

		/**
		return false if the event handling  needs to be stopped
		return true, the event hanlding will be checked furtherly
		*/
		virtual bool onevent(Agent* pAgent, const char* eventName);

    private:
        bool load(const char* file);

		virtual bool isContinueTicking() const
		{
			return true;
		}

    };

} // namespace behaviac

DECLARE_BEHAVIAC_OBJECT_ENUM(behaviac::EBTStatus, EBTStatus);

#endif//BEHAVIAC_BEHAVIORTREE_TASK_H_
