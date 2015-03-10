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

#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/agent/registermacros.h"

#include "behaviac/world/world.h"

#include "behaviac/behaviortree/attachments/predicate.h"
#include "behaviac/behaviortree/attachments/event.h"

#include "behaviac/base/core/profiler/profiler.h"

#if BEHAVIAC_COMPILER_MSVC
#include <windows.h>
#endif//BEHAVIAC_COMPILER_MSVC

BEGIN_ENUM_DESCRIPTION(behaviac::EBTStatus, EBTStatus)
	ENUMCLASS_DISPLAYNAME(L"BT״̬");
	ENUMCLASS_DESC(L"BT״̬");

	DEFINE_ENUM_VALUE(behaviac::BT_INVALID, "invalid");
	DEFINE_ENUM_VALUE(behaviac::BT_SUCCESS, "success");
	DEFINE_ENUM_VALUE(behaviac::BT_FAILURE, "failure");
	DEFINE_ENUM_VALUE(behaviac::BT_RUNNING, "running");
END_ENUM_DESCRIPTION()


namespace behaviac
{
	BehaviorTask::BehaviorTask() : m_status(BT_INVALID), m_node(0), m_parent(0), m_attachments(0)
	{
	}

	BehaviorTask::~BehaviorTask()
	{
		this->FreeAttachments();
	}

	void BehaviorTask::FreeAttachments()
	{
		if (this->m_attachments)
		{
			for (size_t i = 0; i < this->m_attachments->size(); ++i)
			{
				BehaviorTask* pAttachment = (*m_attachments)[i];
				BEHAVIAC_DELETE(pAttachment);
			}
			this->m_attachments->clear();
			BEHAVIAC_DELETE(this->m_attachments);
			this->m_attachments = 0;
		}
	}

	void BehaviorTask::Clear()
	{
		this->m_status = BT_INVALID;
		this->m_parent = 0;
		this->m_id = -1;
		this->FreeAttachments();

		this->m_node = 0;
	}

	void BehaviorTask::Init(const BehaviorNode* node)
	{
		BEHAVIAC_ASSERT(node);

		this->m_node = node;
		this->m_id = this->m_node->GetId();

		uint32_t attachmentsCount = node->GetAttachmentsCount();
		if (attachmentsCount > 0)
		{
			for (uint32_t i = 0; i < attachmentsCount; i++)
			{
				const BehaviorNode* attachmentNode = node->GetAttachment(i);
				AttachmentTask* attachmentTask = (AttachmentTask*)attachmentNode->CreateAndInitTask();

				this->Attach(attachmentTask);
			}
		}
	}

	void BehaviorTask::DestroyTask(BehaviorTask* task)
	{
		BEHAVIAC_DELETE(task);
	}

	void BehaviorTask::Attach(AttachmentTask* pAttachment)
	{
        if (!this->m_attachments)
        {
            this->m_attachments = BEHAVIAC_NEW Attachments;
        }

        this->m_attachments->push_back(pAttachment);
    }

	const behaviac::string& BehaviorTask::GetClassNameString() const
	{
		if (this->m_node)
		{
			return this->m_node->GetClassNameString();
		}

		static behaviac::string s_subBT("SubBT");
		return s_subBT;
	}

	int BehaviorTask::GetId() const
	{
		//if (this->m_node)
		//{
		//	return this->m_node->GetId();
		//}

		//static int s_subBTId(0);
		//return s_subBTId;
		return this->m_id;
	}

	void BehaviorTask::SetId(int id)
	{
		this->m_id = id;
	}

	const BehaviorNode* BehaviorTask::GetNode() const
	{
		return this->m_node;
	}

	bool BehaviorTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		return true;
	}

	//max number of threads used for BT ticking. 
	//usually, only 1 thread is used for BT ticking.
	const static int kMaxThreads = 32;

	struct ThreadStatus_t
	{
		THREAD_ID_TYPE	tid_;
		EBTStatus		status_;
		int				nodeId_;
	};

	//thread safe and no more mutex or memory allocation
	//
	static behaviac::Mutex* gs_tickingMutex = 0;
	static ThreadStatus_t gs_lastStatus[kMaxThreads];

	static behaviac::Mutex& GetTickingMutex()
	{
		if (!gs_tickingMutex)
		{
			gs_tickingMutex = BEHAVIAC_NEW behaviac::Mutex;
		}

		return *gs_tickingMutex;
	}

	void CleanupTickingMutex()
	{
		BEHAVIAC_DELETE gs_tickingMutex;
		gs_tickingMutex = 0;
	}

	EBTStatus GetNodeExitStatus()
	{
		THREAD_ID_TYPE tid = behaviac::GetTID();

		{
			behaviac::ScopedLock lock(GetTickingMutex());

			for (int i = 0; i < kMaxThreads; ++i)
			{
				const ThreadStatus_t& ts = gs_lastStatus[i];
				if  (ts.tid_ == tid)
				{
					return ts.status_;
				}
			}
		}

		BEHAVIAC_ASSERT(false, "this function is only valid when it is called instead of an 'ExitAction' of any Node.\n \
			it should not be called in any other functions!");

		return BT_INVALID;
	}

	int SetNodeId(int nodeId)
	{
		THREAD_ID_TYPE tid = behaviac::GetTID();

		int slot = -1;
		{
			behaviac::ScopedLock lock(GetTickingMutex());

			for (int i = 0; i < kMaxThreads; ++i)
			{
				ThreadStatus_t& ts = gs_lastStatus[i];
				if  (ts.tid_ == 0)
				{
					ts.tid_ = tid;
					ts.nodeId_ = nodeId;
					slot = i;

					break;
				}
			}
		}

		return slot;
	}

	void ClearNodeId(int slot)
	{
		THREAD_ID_TYPE tid = behaviac::GetTID();

		BEHAVIAC_UNUSED_VAR(tid);
		{
			behaviac::ScopedLock lock(GetTickingMutex());

			ThreadStatus_t& ts = gs_lastStatus[slot];
			BEHAVIAC_ASSERT(ts.tid_ == tid);

			ts.tid_ = 0;
			ts.nodeId_ = INVALID_NODE_ID;
		}
	}

	int GetNodeId()
	{
		THREAD_ID_TYPE tid = behaviac::GetTID();

		{
			behaviac::ScopedLock lock(GetTickingMutex());

			for (int i = 0; i < kMaxThreads; ++i)
			{
				const ThreadStatus_t& ts = gs_lastStatus[i];
				if  (ts.tid_ == tid)
				{
					return ts.nodeId_;
				}
			}
		}

		//BEHAVIAC_ASSERT(false, "this function is only valid when it is called instead of an 'Action' Node.\n");

		return INVALID_NODE_ID;
	}

	void BehaviorTask::onexit(Agent* pAgent, EBTStatus status)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(status);
	}

#if !defined(BEHAVIAC_RELEASE)
	behaviac::string GetTickInfo(const behaviac::Agent* pAgent, const behaviac::BehaviorTask* b, const char* action)
	{
		if (pAgent && pAgent->IsMasked())
		{
			//BEHAVIAC_PROFILE("GetTickInfo", true);

			const behaviac::string& bClassName = b->GetClassNameString();

			//filter out intermediate bt, whose class name is empty
			if (!bClassName.empty())
			{
				int nodeId = b->GetId();
				const BehaviorTreeTask* bt = pAgent ? pAgent->btgetcurrent() : 0;

				//TestBehaviorGroup\scratch.xml->EventetTask[0]:enter
				behaviac::string bpstr;
				if (bt)
				{
					const behaviac::string& btName = bt->GetName();

					bpstr = FormatString("%s.xml->", btName.c_str());
				}

				bpstr += FormatString("%s[%i]", bClassName.c_str(), nodeId);

				if (action)
				{
					bpstr += FormatString(":%s", action);
				}

				return bpstr;
			}
		}

		return behaviac::string();
	}

	//static const char* GetActionResultStr(EActionResult actionResult)
	//{
	//	const char* actionResultStr = ""; 
	//	if (actionResult == EAR_success) 
	//	{ 
	//		actionResultStr = " [success]"; 
	//	} 
	//	else if (actionResult == EAR_failure) 
	//	{ 
	//		actionResultStr = " [failure]"; 
	//	} 
	//	else
	//	{
	//		//although actionResult can be EAR_none or EAR_all, but, as this is the real result of an action
	//		//it can only be success or failure
	//		BEHAVIAC_ASSERT(false);
	//	}

	//	return actionResultStr;
	//}

	#define _MY_BREAKPOINT_BREAK_(pAgent, btMsg, actionResult) \
		{ \
			/*const char* actionResultStr = GetActionResultStr(actionResult); \
			const char* msg = FormatString("BehaviorTreeTask Breakpoints at: %s(%d)\n\n'%s%s'\n\nOk to continue.", __FILE__, __LINE__, btMsg, actionResultStr); \
			if (IDOK == MessageBoxA(0, msg, "BehaviorTreeTask Breakpoints", MB_OK | MB_ICONHAND | MB_SETFOREGROUND | MB_SYSTEMMODAL)) \
			{ \
				DebugBreak_(); \
			}*/ \
			Workspace::WaitforContinue(); \
		}

	//CheckBreakpoint should be after log of onenter/onexit/update, as it needs to flush msg to the client
	#define CHECK_BREAKPOINT(pAgent, b, action, actionResult) \
		if (Config::IsLoggingOrSocketing()) \
		{ \
			behaviac::string bpstr = behaviac::GetTickInfo(pAgent, b, action); \
			if (!bpstr.empty()) \
			{ \
				LogManager::GetInstance()->Log(pAgent, bpstr.c_str(), actionResult, ELM_tick); \
				if (behaviac::Config::IsDebugging()) \
				{	\
					if (Workspace::CheckBreakpoint(pAgent, b, action, actionResult)) \
					{ \
						LogManager::GetInstance()->Log(pAgent, bpstr.c_str(), actionResult, ELM_breaked); \
						LogManager::GetInstance()->Flush(pAgent); \
						behaviac::Socket::Flush(); \
						BreakpointPromptHandler_fn fn = GetBreakpointPromptHandler(); \
						if (fn == 0) \
						{ \
							_MY_BREAKPOINT_BREAK_(pAgent, bpstr.c_str(), actionResult); \
						} \
						else \
						{ \
							fn(bpstr.c_str()); \
						} \
						LogManager::GetInstance()->Log(pAgent, bpstr.c_str(), actionResult, ELM_continue); \
						LogManager::GetInstance()->Flush(pAgent); \
						behaviac::Socket::Flush(); \
					} \
				} \
			} \
		}
#else
	#define CHECK_BREAKPOINT(pAgent, b, action, actionResult)
#endif//#if !defined(BEHAVIAC_RELEASE)


	bool BehaviorTask::onenter_action(Agent* pAgent)
	{
		//this needs to be before onenter
		this->InstantiatePars(pAgent);
		
		//this->SetReturnStatus(BT_INVALID);

		bool bResult = this->onenter(pAgent);

		if (this->m_node)
		{
			if (this->m_node->m_enterAction)
			{
				ParentType pt = this->m_node->m_enterAction->GetParentType();
				Agent* pParent = pAgent;
				if (pt == PT_INSTANCE)
				{
					pParent = Agent::GetInstance(this->m_node->m_enterAction->GetInstanceNameString(), pParent->GetContextId());
					BEHAVIAC_ASSERT(pParent);
				}

				this->m_node->m_enterAction->run(pParent, pAgent);
			}
			else
			{
				((BehaviorNode*)(this->m_node))->enteraction_impl(pAgent);
			}
		}

		if (!bResult)
		{
			this->UnInstantiatePars(pAgent);
		}
		else
		{
			//BEHAVIAC_PROFILE_DEBUGBLOCK("Debug", true);

			CHECK_BREAKPOINT(pAgent, this, "enter", bResult ? EAR_success : EAR_failure);
		}

		return bResult;
	}

	void BehaviorTask::onexit_action(Agent* pAgent, EBTStatus status)
	{
		this->onexit(pAgent, status);
		this->SetReturnStatus(BT_INVALID);

		if (this->m_node)
		{
			if (this->m_node->m_exitAction)
			{
				ParentType pt = this->m_node->m_exitAction->GetParentType();
				Agent* pParent = pAgent;
				if (pt == PT_INSTANCE)
				{
					pParent = Agent::GetInstance(this->m_node->m_exitAction->GetInstanceNameString(), pParent->GetContextId());
					BEHAVIAC_ASSERT(pParent);
				}

				THREAD_ID_TYPE tid = behaviac::GetTID();
				int slot = -1;

				{
					behaviac::ScopedLock lock(GetTickingMutex());
					for (int i = 0; i < kMaxThreads; ++i)
					{
						ThreadStatus_t& ts = gs_lastStatus[i];
						if  (ts.tid_ == 0)
						{
							ts.tid_ = tid;
							ts.status_ = status;

							slot = i;

							break;
						}
					}

					BEHAVIAC_ASSERT(slot >= 0 && slot < kMaxThreads, "number of threads used for BT is larger than kMaxThreads(32)!");
				}

				this->m_node->m_exitAction->run(pParent, pAgent);

				{
					behaviac::ScopedLock lock(GetTickingMutex());
					//clear it to invalidate it
					ThreadStatus_t& ts = gs_lastStatus[slot];
					BEHAVIAC_ASSERT(ts.tid_ == tid);
					BEHAVIAC_ASSERT(ts.status_ == status);
					ts.tid_ = 0;
					ts.status_ = BT_INVALID;
				}
			}
			else
			{
				((BehaviorNode*)(this->m_node))->exitaction_impl(pAgent);
			}
		}

		this->UnInstantiatePars(pAgent);

		{
			//BEHAVIAC_PROFILE_DEBUGBLOCK("Debug", true);
			if (status == BT_SUCCESS)
			{
				CHECK_BREAKPOINT(pAgent, this, "exit", EAR_success);
			}
			else
			{
				CHECK_BREAKPOINT(pAgent, this, "exit", EAR_failure);
			}
		}
	}


	void BehaviorTask::InstantiatePars(Agent* pAgent)
	{
		const BehaviorNode* pNode = this->m_node;

		//pNode could be 0 when the bt is a sub tree of parallel node/referenced bt, etc.
		if (pNode && pNode->m_pars)
		{
			for (BehaviorNode::Properties_t::iterator it = pNode->m_pars->begin(); it != pNode->m_pars->end(); ++it)
			{
				Property* property_ = *it;

				property_->Instantiate(pAgent);
			}
		}
	}

	void BehaviorTask::UnInstantiatePars(Agent* pAgent)
	{
		const BehaviorNode* pNode = this->m_node;

		//pNode could be 0 when the bt is a sub tree of parallel node/referenced bt, etc.
		if (pNode && pNode->m_pars)
		{
			for (BehaviorNode::Properties_t::iterator it = pNode->m_pars->begin(); it != pNode->m_pars->end(); ++it)
			{
				Property* property_ = *it;

				property_->UnInstantiate(pAgent);
			}
		}
	}

#if BEHAVIAC_ENABLE_PROFILING
	/// Helper class for automatically beginning and ending a profiling block
	class AutoProfileBlockSend
	{
	public:
		/// Construct. begin a profiling block with the specified name and optional call count.
		AutoProfileBlockSend(Profiler* profiler, const behaviac::string& taskClassid, const Agent* agent) : profiler_(profiler)
		{
			if (Config::IsProfiling())
			{
				profiler_ = profiler;

				if (profiler_)
				{
					profiler_->BeginBlock(taskClassid.c_str(), agent);
				}
			}
		}

		/// Destruct. end the profiling block.
		~AutoProfileBlockSend()
		{
			if (Config::IsProfiling())
			{
				if (profiler_)
				{
					profiler_->EndBlock(true);
				}
			}
		}

	private:
		/// Profiler.
		Profiler* profiler_;
	};
#endif

	EBTStatus BehaviorTask::GetReturnStatus() const {
		return BT_INVALID;
	}

	void BehaviorTask::SetReturnStatus(EBTStatus status) {
		BEHAVIAC_UNUSED_VAR(status);
	}

    EBTStatus BehaviorTask::exec(Agent* pAgent)
    {
#if BEHAVIAC_ENABLE_PROFILING
#if 1
		const char* classStr = (this->m_node ? this->m_node->GetClassNameString().c_str() : "BT");
		int nodeId = (this->m_node ? this->m_node->GetId() : -1);
		behaviac::string taskClassid = FormatString("%s[%i]", classStr, nodeId);

		AutoProfileBlockSend profiler_block(Profiler::GetInstance(), taskClassid, pAgent);
#else
		const char* classStr = (this->m_node ? this->m_node->GetClassNameString().c_str() : "BT");
		BEHAVIAC_PROFILE(classStr);
#endif
#endif//#if BEHAVIAC_ENABLE_PROFILING

		BEHAVIAC_ASSERT(!this->m_node || this->m_node->IsValid(pAgent, this), 	
			FormatString("Agent In BT:%s while the Agent used for: %s", this->m_node->m_agentType.c_str(), pAgent->GetClassTypeName()));

        bool bEnterResult = false;
		if (this->m_status == BT_RUNNING)
		{
			bEnterResult = true;
		}
		else
		{
			//reset it to invalid when it was success/failure
			this->m_status = BT_INVALID;

			bEnterResult = this->onenter_action(pAgent);

			//for continue ticking task, to set it as the cached current task
			bool bIsContinueTicking = this->isContinueTicking();
			if (bIsContinueTicking)
			{
				BranchTask* pBranch = this->GetParentBranch();

				if (pBranch && pBranch != this)
				{
					//if 'this' is a tree, don't set it into it parent's current node
					BEHAVIAC_ASSERT(!BehaviorTreeTask::DynamicCast(this));

					pBranch->SetCurrentTask(this);
				}
			}
		}

        if (bEnterResult)
        {
#if !defined(BEHAVIAC_RELEASE)
			if (Config::IsLoggingOrSocketing())
			{
				//BEHAVIAC_PROFILE_DEBUGBLOCK("Debug", true);

				behaviac::string btStr = behaviac::GetTickInfo(pAgent, this, "update"); 
				//empty btStr is for internal BehaviorTreeTask
				if (!btStr.empty())
				{
					LogManager::GetInstance()->Log(pAgent, btStr.c_str(), EAR_none, ELM_tick);
				}
			}
#endif//#if !defined(BEHAVIAC_RELEASE)

			EBTStatus returnStatus = this->GetReturnStatus();
			if (returnStatus == BT_INVALID)	{
				this->m_status = this->update(pAgent, BT_RUNNING);
			}
			else {
				this->m_status = returnStatus;
				//this->SetReturnStatus(BT_INVALID);
			}

            if (this->m_status != BT_RUNNING)
            {
				//clear it
				bool bIsContinueTicking = this->isContinueTicking();
				if (bIsContinueTicking)
				{
					BranchTask* pBranch = this->GetParentBranch();

					if (pBranch && pBranch != this)
					{
						//if 'this' is a tree, don't set it into it parent's current node
						BEHAVIAC_ASSERT(!BehaviorTreeTask::DynamicCast(this));

						pBranch->SetCurrentTask(0);
					}
				}


                this->onexit_action(pAgent, this->m_status);

				//this node is possibly ticked by its parent or by the topBranch who records it as currrent node
				//so, we can't here reset the topBranch's current node
            }
        }
        else
        {
            this->m_status = BT_FAILURE;
        }

		EBTStatus currentStatus = this->m_status;
		if (this->m_status != BT_RUNNING && this->NeedRestart())
		{
			//reset it to invalid when it needs restarting
			//don't need to reset the sub tree
			this->m_status = BT_INVALID;
			this->SetReturnStatus(BT_INVALID);
		}

		return currentStatus;
    }

	bool abort_handler(BehaviorTask* node, Agent* pAgent, void* user_data)
	{
		BEHAVIAC_UNUSED_VAR(user_data);

		if (node->m_status == BT_RUNNING)
		{
			node->onexit_action(pAgent, BT_FAILURE);

			node->m_status = BT_FAILURE;

			node->SetCurrentTask(0);
		}

		return true;
	}

	bool reset_handler(BehaviorTask* node, Agent* pAgent, void* user_data)
	{
		BEHAVIAC_UNUSED_VAR(user_data);		
		BEHAVIAC_UNUSED_VAR(pAgent);

		node->m_status = BT_INVALID;

		node->SetCurrentTask(0);
		//node->SetReturnStatus(BT_INVALID);
		//BEHAVIAC_ASSERT(node->GetReturnStatus() == BT_INVALID);

		//node->onreset(pAgent);

		return true;
	}


	void BehaviorTask::abort(Agent* pAgent)
	{
		this->traverse(&abort_handler, pAgent, 0);
	}

	void BehaviorTask::reset(Agent* pAgent)
	{
#if BEHAVIAC_ENABLE_PROFILING
		BEHAVIAC_PROFILE("BehaviorTask::reset");
#endif
		this->traverse(&reset_handler, pAgent, 0);
	}

	
	AttachmentTask::AttachmentTask() : BehaviorTask()
	{}

	void AttachmentTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
	}

	AttachmentTask::~AttachmentTask()
	{}

	void AttachmentTask::traverse(NodeHandler_t handler, Agent* pAgent, void* user_data)
	{
		handler(this, pAgent, user_data);
	}


	BranchTask::BranchTask() : BehaviorTask(), m_currentTask(0), m_returnStatus(BT_INVALID)
	{
	}

	BranchTask::~BranchTask()
	{
	}

	bool BranchTask::onenter(Agent* pAgent)	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		//return super::onenter(pAgent);
		return true;
	}

	void BranchTask::onexit(Agent* pAgent, EBTStatus s) {
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(s);
		//super::onexit(pAgent, s);
	}

	EBTStatus BranchTask::GetReturnStatus() const {
		return m_returnStatus;
	}

	void BranchTask::SetReturnStatus(EBTStatus status) {
		m_returnStatus = status;
	}

	BranchTask* BehaviorTask::GetParentBranch()
	{
		BehaviorTask* pTopNode = this->m_parent;

		while (pTopNode)
		{
			BranchTask* pBranch = BranchTask::DynamicCast(pTopNode);
			if (pBranch && pBranch->isContinueTicking())
			{
				return pBranch;
			}

			pTopNode = pTopNode->m_parent;
		}

		return 0;
	}

	EBTStatus BehaviorTask::GetStatus() const
	{
		return this->m_status;
	}


	//bool BehaviorTask::CheckPredicates(Agent* pAgent)
	//{
	//	if (this->m_attachments)
	//	{
	//		bool bTriggered = false;
	//		int index = 0;
	//		bool bAnd = true;
	//		uint32_t numberOfSuccess = 0;
	//		for (Attachments::iterator it = this->m_attachments->begin();
	//			it != this->m_attachments->end(); ++it, ++index)
	//		{
	//			AttachmentTask* pA = *it;
	//			PredicateTask* pP = PredicateTask::DynamicCast(pA);

	//			//check predicates only
	//			if (pP)
	//			{
	//				if (index > 0)
	//				{
	//					bAnd = pP->IsAnd();
	//				}

	//				EBTStatus currentStatus = pA->GetStatus();

	//				if (currentStatus == BT_RUNNING || currentStatus == BT_INVALID)
	//				{
	//					currentStatus = pA->exec(pAgent);
	//				}

	//				if (currentStatus == BT_SUCCESS)
	//				{
	//					numberOfSuccess++;

	//					if (!bAnd)
	//					{
	//						//or
	//						bTriggered = true;
	//						break;
	//					}
	//				}
	//				else if (currentStatus == BT_FAILURE)
	//				{
	//					if (bAnd)
	//					{
	//						//and
	//						break;
	//					}
	//				}
	//			}
	//		}

	//		if (!bTriggered && numberOfSuccess == this->m_attachments->size())
	//		{
	//			BEHAVIAC_ASSERT(numberOfSuccess >= 1 && bAnd);

	//			bTriggered = true;
	//		}

	//		return bTriggered;
	//	}

	//	return true;
	//}

	static bool getBooleanFromStatus(EBTStatus status)
	{
		if (status == BT_FAILURE)
			return false;
		else if (status == BT_SUCCESS)
			return true;
		else
		{
			BEHAVIAC_ASSERT(false);
			return false;
		}
	}

	bool BehaviorTask::CheckPredicates(Agent* pAgent)
	{
		if (this->m_attachments == NULL || this->m_attachments->size() == 0)
			return true;

		bool lastCombineValue = false;
		for (Attachments::iterator it = this->m_attachments->begin(); it != this->m_attachments->end(); ++it)
		{
			AttachmentTask* attchment = *it;
			PredicateTask* predicateTask = PredicateTask::DynamicCast(attchment);

			if (predicateTask != NULL)
			{
				EBTStatus executeStatus = predicateTask->GetStatus();
				if (executeStatus == BT_RUNNING || executeStatus == BT_INVALID)
					executeStatus = predicateTask->exec(pAgent);

				bool taskBoolean = getBooleanFromStatus(executeStatus);
				if (it == this->m_attachments->begin())
				{
					lastCombineValue = taskBoolean;
				}
				else
				{
					bool andOp = predicateTask->IsAnd();
					if (andOp)
						lastCombineValue = lastCombineValue && taskBoolean;
					else
						lastCombineValue = lastCombineValue || taskBoolean;
				}
			}
		}

		return lastCombineValue;
	}

	bool BehaviorTask::CheckEvents(const char* eventName, Agent* pAgent)
	{
		if (this->m_attachments)
		{
			//bool bTriggered = false;
			for (Attachments::iterator it = this->m_attachments->begin();
				it != this->m_attachments->end(); ++it)
			{
				AttachmentTask* pA = *it;
				EventetTask* pE = EventetTask::DynamicCast(pA);

				//check events only
				if (pE && eventName)
				{
					const char* pEventName = pE->GetEventName();

					if (pEventName && string_icmp(pEventName, eventName) == 0)
					{
						EBTStatus currentStatus = pA->GetStatus();

						if (currentStatus == BT_RUNNING || currentStatus == BT_INVALID)
						{
							currentStatus = pA->exec(pAgent);
						}

						if (currentStatus == BT_SUCCESS)
						{
							//bTriggered = true;

							if (pE->TriggeredOnce())
							{
								return false;
							}
						}
						else if (currentStatus == BT_FAILURE)
						{
						}
					}
				}
			}
		}

		return true;
	}

	void BehaviorTask::copyto(BehaviorTask* target) const
	{
		target->m_status = this->m_status;
	}

	void BehaviorTask::save(ISerializableNode* node) const
	{
		CSerializationID  classId("class");
		node->setAttr(classId, this->GetClassNameString());

		CSerializationID  idId("id");
		node->setAttr(idId, this->GetId());

		CSerializationID  statusId("status");
		node->setAttr(statusId, this->m_status);
	}

	void BehaviorTask::load(ISerializableNode* node)
	{
        BEHAVIAC_UNUSED_VAR(node);
	}

	void AttachmentTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void AttachmentTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void AttachmentTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	void LeafTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void LeafTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void LeafTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	struct getnode_t
	{
		int				id_;
		BehaviorTask*	task_;

		getnode_t(int id) : id_(id), task_(0)
		{}

		getnode_t& operator=(const getnode_t&);
	};

	bool getid_handler(BehaviorTask* task, Agent* pAgent, void* user_data)
	{
        BEHAVIAC_UNUSED_VAR(pAgent);
		getnode_t* temp = (getnode_t*)user_data;

		int oldId = task->GetId();
		if (oldId == temp->id_)
		{
			temp->task_ = task;

			return false;
		}

		return true;
	}

	void BranchTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		BEHAVIAC_ASSERT(BranchTask::DynamicCast(target));
		BranchTask* ttask = (BranchTask*)target;

		if (this->m_currentTask)
		{
			int id = this->m_currentTask->GetId();
			getnode_t temp(id);

			ttask->traverse(&getid_handler, 0, &temp);
			BEHAVIAC_ASSERT(temp.task_);

			ttask->m_currentTask = temp.task_;
		}
	}

	void BranchTask::save(ISerializableNode* node) const
	{
		super::save(node);

		if (this->m_currentTask)
		{
			int id = this->m_currentTask->GetId();
			CSerializationID statusId("current");

			node->setAttr(statusId, id);
		}
	}

	void BranchTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	EBTStatus BranchTask::tickCurrentNode(Agent* pAgent)
	{
		BEHAVIAC_ASSERT(this->m_currentTask);

		EBTStatus s = this->m_currentTask->GetStatus();

		if (s == BT_INVALID || s == BT_RUNNING)
		{
			//this->m_currentTask could be cleared in ::exec, to remember it
			BehaviorTask* currentTask = this->m_currentTask;
			EBTStatus status = this->m_currentTask->exec(pAgent);

			//give the handling back to parents
			if (status != BT_RUNNING)
			{
				BEHAVIAC_ASSERT(currentTask->m_status == BT_SUCCESS || 
					currentTask->m_status == BT_FAILURE ||
					(currentTask->m_status == BT_INVALID && currentTask->NeedRestart()));

				BranchTask* parentBranch = currentTask->GetParent();

				this->SetCurrentTask(0);

				//back track the parents until the branch
				while (parentBranch && parentBranch != this)
				{
					status = parentBranch->update(pAgent, status);
					if (status == BT_RUNNING)
					{
						return BT_RUNNING;
					}

					parentBranch->onexit_action(pAgent, status);

					parentBranch->m_status = status;

					BEHAVIAC_ASSERT(parentBranch->m_currentTask == 0);

					parentBranch = parentBranch->GetParent();
				}
			}

			return status;
		}

		return s;
	}


	EBTStatus BranchTask::update(Agent* pAgent, EBTStatus childStatus)
	{
        BEHAVIAC_UNUSED_VAR(childStatus);

		EBTStatus status = BT_INVALID;

		if (this->m_currentTask)
		{
			EBTStatus s = this->m_currentTask->GetStatus();
			if (s != BT_RUNNING)
			{
				this->SetCurrentTask(0);
			}
		}

		if (this->m_currentTask)
		{
			status = this->tickCurrentNode(pAgent);
		}

		return status;
	}


	uint32_t CompositeTask::InvalidChildIndex = (uint32_t)-1;

	CompositeTask::CompositeTask() : BranchTask(), m_activeChildIndex(InvalidChildIndex)
	{
	}

	void CompositeTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
		BEHAVIAC_ASSERT(node->GetChildrenCount() > 0);

		uint32_t childrenCount = node->GetChildrenCount();
		for (uint32_t i = 0; i < childrenCount; i++)
		{
			const BehaviorNode* childNode = node->GetChild(i);
			BehaviorTask* childTask = childNode->CreateAndInitTask();

			this->addChild(childTask);
		}
	}


	void CompositeTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		BEHAVIAC_ASSERT(CompositeTask::DynamicCast(target));
		CompositeTask* ttask = (CompositeTask*)target;

		ttask->m_activeChildIndex = this->m_activeChildIndex;

		BEHAVIAC_ASSERT(this->m_children.size() > 0);
		BEHAVIAC_ASSERT(this->m_children.size() == ttask->m_children.size());

		BehaviorTasks_t::size_type count = this->m_children.size();

		for (BehaviorTasks_t::size_type i = 0; i < count; ++i)
		{
			BehaviorTask* childTask = this->m_children[i];
			BehaviorTask* childTTask = ttask->m_children[i];

			childTask->copyto(childTTask);
		}
	}

	void CompositeTask::save(ISerializableNode* node) const
	{
		super::save(node);

		BehaviorTasks_t::size_type count = this->m_children.size();
		for (BehaviorTasks_t::size_type i = 0; i < count; ++i)
		{
			BehaviorTask* childTask = this->m_children[i];

			CSerializationID  nodeId("node");
			ISerializableNode* chidlNode = node->newChild(nodeId);
			childTask->save(chidlNode);
		}
	}

	void CompositeTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	CompositeTask::~CompositeTask()
	{
		for (size_t i = 0; i < this->m_children.size(); ++i)
		{
			BehaviorTask* pChild = this->m_children[i];
			BEHAVIAC_DELETE(pChild);
		}
		this->m_children.clear();
	}

	void CompositeTask::addChild(BehaviorTask* pBehavior)
	{
		pBehavior->SetParent(this);

		this->m_children.push_back(pBehavior);
	}

	void CompositeTask::traverse(NodeHandler_t handler, Agent* pAgent, void* user_data)
	{
		if (handler(this, pAgent, user_data))
		{
			for (BehaviorTasks_t::iterator it = this->m_children.begin(); 
				it != this->m_children.end(); ++it)
			{
				BehaviorTask* task = *it;

				task->traverse(handler, pAgent, user_data);
			}
		}
	}

	SingeChildTask::SingeChildTask() : m_root(0)
	{}

	SingeChildTask::~SingeChildTask()
	{
		BEHAVIAC_DELETE(m_root);
	}

	void SingeChildTask::addChild(BehaviorTask* pBehavior)
	{
		pBehavior->SetParent(this);

		this->m_root = pBehavior;
	}

	void SingeChildTask::traverse(NodeHandler_t handler, Agent* pAgent, void* user_data)
	{
		if (handler(this, pAgent, user_data))
		{
			if (this->m_root)
			{
				this->m_root->traverse(handler, pAgent, user_data);
			}
		}
	}

	void SingeChildTask::Init(const BehaviorNode* node)
	{
		super::Init(node);

		BEHAVIAC_ASSERT(node->GetChildrenCount() <= 1);

		if (node->GetChildrenCount() == 1)
		{
			const BehaviorNode* childNode = node->GetChild(0);

			BehaviorTask* childTask = childNode->CreateAndInitTask();

			this->addChild(childTask);
		}
		else
		{
			BEHAVIAC_ASSERT(true);
		}
	}

	void SingeChildTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		BEHAVIAC_ASSERT(SingeChildTask::DynamicCast(target));
		SingeChildTask* ttask = (SingeChildTask*)target;

		if (this->m_root)
		{
			//referencebehavior/query, etc.
			if (!ttask->m_root)
			{
				const BehaviorNode* pNode = this->m_root->GetNode();
				BEHAVIAC_ASSERT(BehaviorTree::DynamicCast(pNode));
				ttask->m_root = pNode->CreateAndInitTask();
			}

			BEHAVIAC_ASSERT(ttask->m_root);
			this->m_root->copyto(ttask->m_root);
		}
	}

	void SingeChildTask::save(ISerializableNode* node) const
	{
		super::save(node);

		if (this->m_root)
		{
			CSerializationID  nodeId("root");
			ISerializableNode* chidlNode = node->newChild(nodeId);
			this->m_root->save(chidlNode);
		}
	}

	void SingeChildTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	EBTStatus SingeChildTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		if (this->m_currentTask)
		{
			EBTStatus s = super::update(pAgent, childStatus);

			return s;
		}

		if (this->m_root)
		{
			EBTStatus s = this->m_root->exec(pAgent);
			return s;
		}

		return BT_INVALID;
	}

	DecoratorTask::DecoratorTask() : SingeChildTask(), m_bDecorateWhenChildEnds(false)
	{
	}

	void DecoratorTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
        DecoratorNode* pDN = (DecoratorNode*)node;

		this->m_bDecorateWhenChildEnds = pDN->m_bDecorateWhenChildEnds;
	}

	void DecoratorTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		// BEHAVIAC_ASSERT(DecoratorTask::DynamicCast(target));
		// DecoratorTask* ttask = (DecoratorTask*)target;
	}

	void DecoratorTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void DecoratorTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	DecoratorTask::~DecoratorTask()
	{
	}

	bool DecoratorTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);

		return true;
	}

	EBTStatus DecoratorTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		EBTStatus status = super::update(pAgent, childStatus);

		if (!this->m_bDecorateWhenChildEnds || status != BT_RUNNING)
		{
			EBTStatus result = this->decorate(status);

			if (status != BT_RUNNING)
			{
				BehaviorTask* child = this->m_root;
				if (child)
				{
					child->m_status = BT_INVALID;
				}

				this->SetCurrentTask(0);
			}

			return result;
		}

		return BT_RUNNING;
	}

	LeafTask::LeafTask() : BehaviorTask()
	{}

	void LeafTask::Init(const BehaviorNode* node)
	{
		super::Init(node);

		BEHAVIAC_ASSERT(node && node->GetChildrenCount() == 0);
	}

	LeafTask::~LeafTask()
	{}

	void LeafTask::traverse(NodeHandler_t handler, Agent* pAgent, void* user_data)
	{
		handler(this, pAgent, user_data);
	}


	BehaviorTreeTask::BehaviorTreeTask() : SingeChildTask()
	{}


	void BehaviorTreeTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
	}

	void BehaviorTreeTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);

		// BEHAVIAC_ASSERT(BehaviorTreeTask::DynamicCast(target));
		// BehaviorTreeTask* ttask = (BehaviorTreeTask*)target;
		
	}

	void BehaviorTreeTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void BehaviorTreeTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	BehaviorTreeTask::~BehaviorTreeTask()
	{
		//if (this->m_root)
		//{
		//	BehaviorTask::DestroyTask(this->m_root);
		//}
	}

	void BehaviorTreeTask::Clear()
	{
		BehaviorTask::Clear();

		BEHAVIAC_DELETE this->m_root;
		this->m_root = NULL;

		this->m_currentTask = 0;
		this->m_returnStatus = BT_INVALID;
	}

	const behaviac::string& BehaviorTreeTask::GetName() const
	{
		BEHAVIAC_ASSERT(BehaviorTree::DynamicCast(this->m_node));
		const BehaviorTree* bt = (const BehaviorTree*)(this->m_node);
		BEHAVIAC_ASSERT(bt);
		return bt->GetName();
	}

    bool BehaviorTreeTask::onenter(Agent* pAgent)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);

        return true;
    }

    void BehaviorTreeTask::onexit(Agent* pAgent, EBTStatus status)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(status);
    }

	bool BehaviorTreeTask::NeedRestart() const
	{
		const BehaviorTask* root = this->m_root;
		if (root && root->NeedRestart())
		{
			return true;
		}

		return false;
	}

    EBTStatus BehaviorTreeTask::update(Agent* pAgent, EBTStatus childStatus)
    {
		EBTStatus status = super::update(pAgent, childStatus);

		if (status != BT_RUNNING)
		{
			this->SetCurrentTask(0);
		}

        return status;
    }

	void BehaviorTreeTask::SetRootTask(BehaviorTask* pRoot)
	{
		this->addChild(pRoot);
	}

	void BehaviorTreeTask::CopyTo(BehaviorTreeTask* target)
	{
		this->copyto(target);
	}

	EBTStatus BehaviorTreeTask::resume(Agent* pAgent, EBTStatus status) {
		BranchTask* prev = 0;
		BehaviorTask* p = this->m_currentTask;
		while (p) {
			BranchTask* branch = BranchTask::DynamicCast(p);
			if (branch) {
				prev = (branch);
				p = const_cast<BehaviorTask*>(branch->GetCurrentTask());
			}
			else {
				prev = p->GetParent();
				break;
			}
		}

		if (prev) {
			//prev is the last interrupted node, to find and let its parent update with 'stats' which is the subtree's return status
			BEHAVIAC_ASSERT(status == BT_SUCCESS || status == BT_FAILURE);
			prev->onexit_action(pAgent, status);

			prev->SetReturnStatus(status);
		}

		return status;
	}

	bool BehaviorTask::onevent(Agent* pAgent, const char* eventName)
	{
		if (this->m_status == BT_RUNNING && this->m_node->m_bHasEvents)
		{
			if (!this->CheckEvents(eventName, pAgent))
			{
				return false;
			}
		}

		return true;
	}

	void BranchTask::Init(const BehaviorNode* node)
	{
		super::Init(node);
	}

	bool BranchTask::oneventCurrentNode(Agent* pAgent, const char* eventName)
	{
		BEHAVIAC_ASSERT(this->m_currentTask);

		EBTStatus s = this->m_currentTask->GetStatus();
		BEHAVIAC_UNUSED_VAR(s);

		BEHAVIAC_ASSERT (s == BT_RUNNING && this->m_node->HasEvents());

		bool bGoOn = this->m_currentTask->onevent(pAgent, eventName);

		//give the handling back to parents
		if (bGoOn)
		{
			BranchTask* parentBranch = this->m_currentTask->GetParent();

			//back track the parents until the branch
			while (parentBranch && parentBranch != this)
			{
				BEHAVIAC_ASSERT(parentBranch->GetStatus() == BT_RUNNING);

				bGoOn = parentBranch->onevent(pAgent, eventName);
				if (!bGoOn)
				{
					return false;
				}

				parentBranch = parentBranch->GetParent();
			}
		}

		return bGoOn;
	}

	bool BranchTask::onevent(Agent* pAgent, const char* eventName)
	{
		bool bGoOn = true;

		if (this->m_status == BT_RUNNING && this->m_node->HasEvents())
		{
			BEHAVIAC_ASSERT(this->m_currentTask);

			bGoOn = this->oneventCurrentNode(pAgent, eventName);
		}

		return bGoOn;
	}

	bool LeafTask::onevent(Agent* pAgent, const char* eventName)
	{
		bool bGoOn = BehaviorTask::onevent(pAgent, eventName);

		return bGoOn;
	}

	bool BehaviorTreeTask::onevent(Agent* pAgent, const char* eventName)
	{
		if (this->m_node->HasEvents())
		{
			bool bGoOn = this->m_root->onevent(pAgent, eventName);

			if (bGoOn && !BehaviorTask::onevent(pAgent, eventName))
			{
				return false;
			}
		}

		return true;
	}

	void BehaviorTreeTask::Save(ISerializableNode* node) const
	{
		CSerializationID  btId("BehaviorTree");
		ISerializableNode* btNodeRoot = node->newChild(btId);

		BEHAVIAC_ASSERT(BehaviorTree::DynamicCast(this->GetNode()));
		BehaviorTree* bt = (BehaviorTree*)this->GetNode();

		CSerializationID  sourceId("source");
		btNodeRoot->setAttr(sourceId, bt->GetName());

		CSerializationID  nodeId("node");
		ISerializableNode* btNode = btNodeRoot->newChild(nodeId);

		this->save(btNode);
	}

	void BehaviorTreeTask::Load(ISerializableNode* node)
	{
		this->load(node);
	}

}//namespace behaviac