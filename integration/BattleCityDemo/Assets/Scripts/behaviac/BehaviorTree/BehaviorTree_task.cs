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

namespace behaviac
{
    /**
     Return values of tick/update and valid states for behaviors.
    */
    public enum EBTStatus
    {
        BT_INVALID,
        BT_SUCCESS,
        BT_FAILURE,
        BT_RUNNING,
    }

    /**
    trigger mode to control the bt switching and back
    */
    public enum TriggerMode
    {
        TM_Transfer,
        TM_Return
    }

    ///return false to stop traversing
    public delegate bool NodeHandler_t(BehaviorTask task, Agent agent, object user_data);

    /**
    Base class for the BehaviorTreeTask's runtime execution management.
    */
    public abstract class BehaviorTask
    {
        public static void DestroyTask(BehaviorTask task)
        {
            //nothing
        }

        protected void FreeAttachments()
	    {
            if (this.m_attachments != null)
            {
                this.m_attachments.Clear();
                this.m_attachments = null;
            }
	    }

        public virtual void Clear()
	    {
            this.m_status = EBTStatus.BT_INVALID;
            this.m_parent = null;
            this.m_id = -1;
            this.FreeAttachments();

            this.m_node = null;
	    }

        public virtual void Init(BehaviorNode node)
        {
            Debug.Check(node != null);

            this.m_node = node;
            this.m_id = this.m_node.GetId();

            int attachmentsCount = node.GetAttachmentsCount();
            if (attachmentsCount > 0)
            {
                for (int i = 0; i < attachmentsCount; i++)
                {
                    BehaviorNode attachmentNode = node.GetAttachment(i);
                    AttachmentTask attachmentTask = (AttachmentTask)attachmentNode.CreateAndInitTask();

                    this.Attach(attachmentTask);
                }
            }
        }

        public virtual void copyto(BehaviorTask target)
        {
            target.m_status = this.m_status;
        }

        public virtual void save(ISerializableNode node)
        {
            //CSerializationID  classId = new CSerializationID("class");
            //node.setAttr(classId, this.GetClassNameString());

            //CSerializationID  idId = new CSerializationID("id");
            //node.setAttr(idId, this.GetId());

            //CSerializationID  statusId = new CSerializationID("status");
            //node.setAttr(statusId, this.m_status);
        }

        public virtual void load(ISerializableNode node)
        {
        }

        public string GetClassNameString()
        {
            if (this.m_node != null)
            {
                return this.m_node.GetClassNameString();
            }

            string subBT = "SubBT";
            return subBT;
        }

        public int GetId()
        {
            return this.m_id;
        }

        public void SetId(int id)
        {
            this.m_id = id;
        }

        public virtual EBTStatus GetReturnStatus()
        {
            return EBTStatus.BT_INVALID;
        }

        public virtual void SetReturnStatus(EBTStatus status)
        {
        }

        public EBTStatus exec(Agent pAgent)
        {
#if !BEHAVIAC_RELEASE
            Debug.Check(this.m_node == null || this.m_node.IsValid(pAgent, this),
                string.Format("Agent In BT:{0} while the Agent used for: {1}", this.m_node.GetAgentType(), pAgent.GetClassTypeName()));
#endif//#if !BEHAVIAC_RELEASE
            bool bEnterResult = false;
            if (this.m_status == EBTStatus.BT_RUNNING)
            {
                bEnterResult = true;
            }
            else
            {
                //reset it to invalid when it was success/failure
                this.m_status = EBTStatus.BT_INVALID;

                bEnterResult = this.onenter_action(pAgent);

                //for continue ticking task, to set it as the cached current task
                bool bIsContinueTicking = this.isContinueTicking();
                if (bIsContinueTicking)
                {
                    BranchTask pBranch = this.GetParentBranch();

                    if (pBranch != null && pBranch != this)
                    {
                        //if 'this' is a tree, don't set it into it parent's current node
                        Debug.Check(!(this is BehaviorTreeTask));

                        pBranch.SetCurrentTask(this);
                    }
                }
            }

            if (bEnterResult)
            {
#if !BEHAVIAC_RELEASE
                if (Config.IsLoggingOrSocketing)
                {
                    string btStr = BehaviorTask.GetTickInfo(pAgent, this, "update");
                    //empty btStr is for internal BehaviorTreeTask
                    if (!string.IsNullOrEmpty(btStr))
                    {
                        LogManager.Log(pAgent, btStr, EActionResult.EAR_none, LogMode.ELM_tick);
                    }
                }
#endif
                bool bEnded = false;
                EBTStatus returnStatus = this.GetReturnStatus();
                if (returnStatus == EBTStatus.BT_INVALID)
                {
                    this.m_status = this.update(pAgent, EBTStatus.BT_RUNNING);
                }
                else
                {
                    this.m_status = returnStatus;
                    bEnded = true;
                }

                if (this.m_status != EBTStatus.BT_RUNNING)
                {
                    //clear it
                    bool bIsContinueTicking = this.isContinueTicking();
                    if (bIsContinueTicking)
                    {
                        BranchTask pBranch = this.GetParentBranch();

                        if (pBranch != null && pBranch != this)
                        {
                            //if 'this' is a tree, don't set it into it parent's current node
                            Debug.Check(!(this is BehaviorTreeTask));

                            pBranch.SetCurrentTask(null);
                        }
                    }

                    if (!bEnded)
                    {
                        this.onexit_action(pAgent, this.m_status);
                    }

                    //this node is possibly ticked by its parent or by the topBranch who records it as currrent node
                    //so, we can't here reset the topBranch's current node
                }
            }
            else
            {
                this.m_status = EBTStatus.BT_FAILURE;
            }

            EBTStatus currentStatus = this.m_status;
            if (this.m_status != EBTStatus.BT_RUNNING && this.NeedRestart())
            {
                //reset it to invalid when it needs restarting
                //don't need to reset the sub tree
                this.m_status = EBTStatus.BT_INVALID;
                this.SetReturnStatus(EBTStatus.BT_INVALID);
            }

            return currentStatus;
        }

        static bool abort_handler(BehaviorTask node, Agent pAgent, object user_data)
        {
            if (node.m_status == EBTStatus.BT_RUNNING)
            {
                node.onexit_action(pAgent, EBTStatus.BT_FAILURE);

                node.m_status = EBTStatus.BT_FAILURE;

                node.SetCurrentTask(null);
            }

            return true;
        }

        static bool reset_handler(BehaviorTask node, Agent pAgent, object user_data)
        {
            node.m_status = EBTStatus.BT_INVALID;

            node.SetCurrentTask(null);
            //node->SetReturnStatus(BT_INVALID);
            //BEHAVIAC_ASSERT(node->GetReturnStatus() == BT_INVALID);

            //node.onreset(pAgent);

            return true;
        }

		static NodeHandler_t abort_handler_ = abort_handler;
		static NodeHandler_t reset_handler_ = reset_handler;

        public void abort(Agent pAgent)
        {
            this.traverse(abort_handler_, pAgent, null);
        }

        ///reset the status to invalid
        public void reset(Agent pAgent)
        {
            //BEHAVIAC_PROFILE("BehaviorTask.reset");

            this.traverse(reset_handler_, pAgent, null);
        }

        public EBTStatus GetStatus()
        {
            return this.m_status;
        }
        public void SetStatus(EBTStatus s)
        {
            this.m_status = s;
        }

        public BehaviorNode GetNode()
        {
            return this.m_node;
        }

        /**
        a branch is a node whose isContinueTicking returns true

        BehaviorTreeTask, DecoratorTask, ParallelTask, SelectorLoopTask, etc.
        */
        public BranchTask GetParentBranch()
        {
            BehaviorTask pTopNode = this.m_parent;

            while (pTopNode != null)
            {
                BranchTask pBranch = pTopNode as BranchTask;
                if (pBranch != null && pBranch.isContinueTicking())
                {
                    return pBranch;
                }

                pTopNode = pTopNode.m_parent;
            }

            return null;
        }

        public void SetParent(BranchTask parent)
        {
            this.m_parent = parent;
        }

        public BranchTask GetParent()
        {
            return this.m_parent;
        }

        public abstract void traverse(NodeHandler_t handler, Agent pAgent, object user_data);

        /**
        when a node is ended(success/failure), this dertermines if the exit status(success/failure) should be kept.
        if it needs to restart, then, the exit status is just returned but not kept
        */
        public virtual bool NeedRestart()
        {
            return false;
        }

        public virtual void SetCurrentTask(BehaviorTask node)
        {
        }

//        public virtual bool CheckPredicates(Agent pAgent)
//        {
//            if (this.m_attachments != null)
//            {
//                bool bTriggered = false;
//                int index = 0;
//                bool bAnd = true;
//                int numberOfSuccess = 0;
//				for (int i = 0; i < this.m_attachments.Count; ++i)
//                {
//					AttachmentTask pA = this.m_attachments[i];
//                    Predicate.PredicateTask pP = pA as Predicate.PredicateTask;
//
//                    //check predicates only
//                    if (pP != null)
//                    {
//                        if (index > 0)
//                        {
//                            bAnd = pP.IsAnd();
//                        }
//
//                        EBTStatus currentStatus = pA.GetStatus();
//
//                        if (currentStatus == EBTStatus.BT_RUNNING || currentStatus == EBTStatus.BT_INVALID)
//                        {
//                            currentStatus = pA.exec(pAgent);
//                        }
//
//                        if (currentStatus == EBTStatus.BT_SUCCESS)
//                        {
//                            numberOfSuccess++;
//
//                            if (!bAnd)
//                            {
//                                //or
//                                bTriggered = true;
//                                break;
//                            }
//                        }
//                        else if (currentStatus == EBTStatus.BT_FAILURE)
//                        {
//                            if (bAnd)
//                            {
//                                //and
//                                break;
//                            }
//                        }
//                    }
//                }
//
//                if (!bTriggered && numberOfSuccess == this.m_attachments.Count)
//                {
//                    Debug.Check(numberOfSuccess >= 1 && bAnd);
//
//                    bTriggered = true;
//                }
//
//                return bTriggered;
//            }
//
//			//no predicates
//            return true;
//        }

		bool getBooleanFromStatus(EBTStatus status)
		{
			if(status == EBTStatus.BT_FAILURE)
				return false;
			else if(status == EBTStatus.BT_SUCCESS)
				return true;
			else
			{
				Debug.LogError("Predicate can not return RUNNING status!");
				return false;
			}
		}

		public virtual bool CheckPredicates(Agent pAgent)
		{
			if(this.m_attachments == null || this.m_attachments.Count == 0)
				return true;

			bool lastCombineValue = false;
			for(int i = 0; i < this.m_attachments.Count; ++i)
			{
				AttachmentTask attchment = this.m_attachments[i];
				Predicate.PredicateTask predicateTask = attchment as Predicate.PredicateTask;
				
				if (predicateTask != null)
				{
					EBTStatus executeStatus = predicateTask.GetStatus();
					if(executeStatus == EBTStatus.BT_RUNNING || executeStatus == EBTStatus.BT_INVALID)
						executeStatus = predicateTask.exec(pAgent);

					bool taskBoolean = getBooleanFromStatus(executeStatus);
					if(i == 0)
					{
						lastCombineValue = taskBoolean;
					}
					else
					{
						bool andOp = predicateTask.IsAnd();
						if(andOp)
							lastCombineValue = lastCombineValue && taskBoolean;
						else
							lastCombineValue = lastCombineValue || taskBoolean;
					}
				}
			}

			return lastCombineValue;
		}

        /**
        return false if the event handling needs to be stopped

        an event can be configured to stop being checked if triggered
        */
        public bool CheckEvents(string eventName, Agent pAgent)
        {
            if (this.m_attachments != null)
            {
                //bool bTriggered = false;
				for (int i = 0; i < this.m_attachments.Count; ++i)
                {
					AttachmentTask pA = this.m_attachments[i];
                    Event.EventTask pE = pA as Event.EventTask;

                    //check events only
                    if (pE != null && !string.IsNullOrEmpty(eventName))
                    {
                        string pEventName = pE.GetEventName();

                        if (!string.IsNullOrEmpty(pEventName) && pEventName == eventName)
                        {
                            EBTStatus currentStatus = pA.GetStatus();

                            if (currentStatus == EBTStatus.BT_RUNNING || currentStatus == EBTStatus.BT_INVALID)
                            {
                                currentStatus = pA.exec(pAgent);
                            }

                            if (currentStatus == EBTStatus.BT_SUCCESS)
                            {
                                //bTriggered = true;

                                if (pE.TriggeredOnce())
                                {
                                    return false;
                                }
                            }
                            else if (currentStatus == EBTStatus.BT_FAILURE)
                            {
                            }
                        }
                    }
                }
            }

            return true;
        }

        /**
        return false if the event handling  needs to be stopped
        return true, the event hanlding will be checked furtherly
        */
        public virtual bool onevent(Agent pAgent, string eventName)
        {
            if (this.m_status == EBTStatus.BT_RUNNING && this.m_node.HasEvents())
            {
                if (!this.CheckEvents(eventName, pAgent))
                {
                    return false;
                }
            }

            return true;
        }

        protected BehaviorTask()
        {
            m_status = EBTStatus.BT_INVALID;
            m_node = null;
            m_attachments = null;
            m_parent = null;
        }

        ~BehaviorTask()
        {
		}

        /**
        @sa isContinueTicking
        */
        protected virtual EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            return EBTStatus.BT_SUCCESS;
        }

        protected virtual bool onenter(Agent pAgent)
        {
            return true;
        }

        protected virtual void onexit(Agent pAgent, EBTStatus status)
        {
		}

        ///return true if it is continuing running for the next tick
        /**
        this virtual function is used for those nodes which will run continuously in the next tick
        so that the tree can record it to tick it directly in the next tick.

        so usually, the leaf nodes except the condition nodes need to override it to return true.
        the branch nodes usually return false. however, parallel need to return true.
        */
		protected virtual bool isContinueTicking()
        {
            return false;
        }

        private void Attach(AttachmentTask pAttachment)
        {
            if (this.m_attachments == null)
            {
                this.m_attachments = new List<AttachmentTask>();
            }

            this.m_attachments.Add(pAttachment);
        }

        private void InstantiatePars(Agent pAgent)
        {
            BehaviorNode pNode = this.m_node;

            //pNode could be 0 when the bt is a sub tree of parallel node/referenced bt, etc.
            if (pNode != null && pNode.m_pars != null)
            {
				for (int i = 0; i < pNode.m_pars.Count; ++i)
                {
					Property property_ = pNode.m_pars[i];

//					if(pAgent != null && property_.GetVariableName() == "par0_char_0")
//					{
//						behaviac.Debug.Check(true);
//					}

                    property_.Instantiate(pAgent);
                }
            }
        }

        private void UnInstantiatePars(Agent pAgent)
        {
            BehaviorNode pNode = this.m_node;

            //pNode could be 0 when the bt is a sub tree of parallel node/referenced bt, etc.
            if (pNode != null && pNode.m_pars != null)
            {
				for (int i = 0; i < pNode.m_pars.Count; ++i)
                {
					Property property_ = pNode.m_pars[i];
                    property_.UnInstantiate(pAgent);
                }
            }
        }

        public static string GetTickInfo(Agent pAgent, BehaviorTask b, string action)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
        	{
                if (pAgent != null && pAgent.IsMasked())
           		{
                    //BEHAVIAC_PROFILE("GetTickInfo", true);

                    string bClassName = b.GetClassNameString();

                    //filter out intermediate bt, whose class name is empty
                    if (!string.IsNullOrEmpty(bClassName))
                    {
                        int nodeId = b.GetId();
                        BehaviorTreeTask bt = pAgent != null ? pAgent.btgetcurrent() : null;

                        //TestBehaviorGroup\scratch.xml.EventetTask[0]:enter
                        string bpstr = "";
                        if (bt != null)
                        {
                            string btName = bt.GetName();

                            bpstr = string.Format("{0}.xml->", btName);
                        }

                        bpstr += string.Format("{0}[{1}]", bClassName, nodeId);

                        if (!string.IsNullOrEmpty(action))
                        {
                            bpstr += string.Format(":{0}", action);
                        }

                        return bpstr;
                    }
                }
            }
#endif
            return string.Empty;
        }

        private static string GetActionResultStr(EActionResult actionResult)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                string actionResultStr = "";
                if (actionResult == EActionResult.EAR_success)
                {
                    actionResultStr = " [success]";
                }
                else if (actionResult == EActionResult.EAR_failure)
                {
                    actionResultStr = " [failure]";
                }
                else
                {
                    //although actionResult can be EAR_none or EAR_all, but, as this is the real result of an action
                    //it can only be success or failure
                    Debug.Check(false);
                }

                return actionResultStr;
            }
#endif
            return string.Empty;
        }

        private static void _MY_BREAKPOINT_BREAK_(Agent pAgent, string btMsg, EActionResult actionResult)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                string actionResultStr = GetActionResultStr(actionResult);
                string msg = string.Format("BehaviorTreeTask Breakpoints at: '{0}{1}'\n\nOk to continue.", btMsg, actionResultStr);

                Workspace.RespondToBreak(msg, "BehaviorTreeTask Breakpoints");
            }
#endif
        }

        //CheckBreakpoint should be after log of onenter/onexit/update, as it needs to flush msg to the client
        private static void CHECK_BREAKPOINT(Agent pAgent, BehaviorTask b, string action, EActionResult actionResult)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                string bpstr = GetTickInfo(pAgent, b, action);
                if (!string.IsNullOrEmpty(bpstr))
                {
                    LogManager.Log(pAgent, bpstr, actionResult, LogMode.ELM_tick);
					if (Config.IsDebugging)
                    {
						if (Workspace.CheckBreakpoint(pAgent, b, action, actionResult))
                        {
							LogManager.Log(pAgent, bpstr, actionResult, LogMode.ELM_breaked);
							LogManager.Flush(pAgent);
							SocketUtils.Flush();

                            _MY_BREAKPOINT_BREAK_(pAgent, bpstr, actionResult);

							LogManager.Log(pAgent, bpstr, actionResult, LogMode.ELM_continue);
							LogManager.Flush(pAgent);
							SocketUtils.Flush();
                        }
                    }
                }
            }
#endif
        }

        public bool onenter_action(Agent pAgent)
        {
            //this needs to be before onenter
            this.InstantiatePars(pAgent);

            bool bResult = this.onenter(pAgent);

            if (this.m_node != null)
            {
                if (!((BehaviorNode)(this.m_node)).enteraction_impl(pAgent))
                {
                    if (this.m_node.m_enterAction != null)
                    {
                        ParentType pt = this.m_node.m_enterAction.GetParentType();
                        Agent pParent = pAgent;
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParent = Agent.GetInstance(this.m_node.m_enterAction.GetInstanceNameString(), pParent.GetContextId());
							Debug.Check(pParent != null || Utils.IsStaticClass(this.m_node.m_enterAction.GetInstanceNameString()));
                        }

                        this.m_node.m_enterAction.run(pParent, pAgent);
                    }
                }
            }

            if (!bResult)
            {
                this.UnInstantiatePars(pAgent);
            }
            else
            {
#if !BEHAVIAC_RELEASE
                //BEHAVIAC_PROFILE_DEBUGBLOCK("Debug", true);

                CHECK_BREAKPOINT(pAgent, this, "enter", bResult ? EActionResult.EAR_success : EActionResult.EAR_failure);
#endif
            }

            return bResult;
        }

        private static EBTStatus ms_lastExitStatus_ = EBTStatus.BT_INVALID;

		public static EBTStatus GetNodeExitStatus()
		{
			return ms_lastExitStatus_;
		}

        public void onexit_action(Agent pAgent, EBTStatus status)
        {
            this.onexit(pAgent, status);
            this.SetReturnStatus(EBTStatus.BT_INVALID);

            if (this.m_node != null)
            {
                bool exitImpl = ((BehaviorNode)(this.m_node)).exitaction_impl(pAgent);

                if (exitImpl || this.m_node.m_exitAction != null)
                {
                    Agent pParent = pAgent;

                    if (!exitImpl && this.m_node.m_exitAction != null)
                    {
                        ParentType pt = this.m_node.m_exitAction.GetParentType();
                        if (pt == ParentType.PT_INSTANCE)
                        {
                            pParent = Agent.GetInstance(this.m_node.m_exitAction.GetInstanceNameString(), pParent.GetContextId());
							Debug.Check(pParent != null || Utils.IsStaticClass(this.m_node.m_exitAction.GetInstanceNameString()));
                        }
                    }

                    if (!exitImpl && this.m_node.m_exitAction != null)
                    {
                        ms_lastExitStatus_ = status;
                        this.m_node.m_exitAction.run(pParent, pAgent);

                        ms_lastExitStatus_ = EBTStatus.BT_INVALID;
                    }
                }
            }

            this.UnInstantiatePars(pAgent);
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                //BEHAVIAC_PROFILE_DEBUGBLOCK("Debug", true);
                if (status == EBTStatus.BT_SUCCESS)
                {
                    CHECK_BREAKPOINT(pAgent, this, "exit", EActionResult.EAR_success);
                }
                else
                {
                    CHECK_BREAKPOINT(pAgent, this, "exit", EActionResult.EAR_failure);
                }
            }
#endif
        }

		public virtual List<BehaviorNode> GetRunningNodes()
		{
			List<BehaviorNode> nodes = new List<BehaviorNode>();
			return nodes;
		}

        public EBTStatus m_status;
        protected BehaviorNode m_node;
        protected BranchTask m_parent;
        protected List<AttachmentTask> m_attachments;

        private int m_id;
    }

    // ============================================================================
    public class AttachmentTask : BehaviorTask
    {
        protected AttachmentTask()
        {
        }

        ~AttachmentTask()
        {
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
        }

        public override void copyto(BehaviorTask target)
        {
            base.copyto(target);
        }

        public override void traverse(NodeHandler_t handler, Agent pAgent, object user_data)
        {
            handler(this, pAgent, user_data);
        }
    }

    // ============================================================================
    public class LeafTask : BehaviorTask
    {
        public override void traverse(NodeHandler_t handler, Agent pAgent, object user_data)
        {
            handler(this, pAgent, user_data);
        }

        protected LeafTask()
        {
		}

        ~LeafTask()
        {
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
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

		protected override bool isContinueTicking()
        {
            return true;
        }

        public override bool onevent(Agent pAgent, string eventName)
        {
            bool bGoOn = base.onevent(pAgent, eventName);

            return bGoOn;
        }

		public override List<BehaviorNode> GetRunningNodes()
		{
			List<BehaviorNode> nodes = new List<BehaviorNode>();
			
			if (this.isContinueTicking() && EBTStatus.BT_RUNNING == this.GetStatus())
			{
				nodes.Add(this.GetNode());
			}
			
			return nodes;
		}
    }

    // ============================================================================
    public abstract class BranchTask : BehaviorTask
    {
        public override void SetCurrentTask(BehaviorTask node)
        {
            this.m_currentTask = node;
        }

		public BehaviorTask GetCurrentTask()
		{
			return this.m_currentTask;
		}

        public override EBTStatus GetReturnStatus()
        {
            return m_returnStatus;
        }

        public override void SetReturnStatus(EBTStatus status)
        {
            m_returnStatus = status;
        }

        protected BranchTask()
        {
            m_returnStatus = EBTStatus.BT_INVALID;
        }

        ~BranchTask()
        {
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
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

        protected EBTStatus tickCurrentNode(Agent pAgent)
        {
            Debug.Check(this.m_currentTask != null);

            EBTStatus s = this.m_currentTask.GetStatus();

            if (s == EBTStatus.BT_INVALID || s == EBTStatus.BT_RUNNING)
            {
                //this.m_currentTask could be cleared in ::tick, to remember it
                BehaviorTask currentTask = this.m_currentTask;
                EBTStatus status = this.m_currentTask.exec(pAgent);

                //give the handling back to parents
                if (status != EBTStatus.BT_RUNNING)
                {
                    Debug.Check(currentTask.m_status == EBTStatus.BT_SUCCESS ||
                        currentTask.m_status == EBTStatus.BT_FAILURE ||
                        (currentTask.m_status == EBTStatus.BT_INVALID && currentTask.NeedRestart()));

                    BranchTask parentBranch = currentTask.GetParent();

                    this.SetCurrentTask(null);

                    //back track the parents until the branch
                    while (parentBranch != null && parentBranch != this)
                    {
                        status = parentBranch.update(pAgent, status);
                        if (status == EBTStatus.BT_RUNNING)
                        {
                            return EBTStatus.BT_RUNNING;
                        }

                        parentBranch.onexit_action(pAgent, status);

                        parentBranch.m_status = status;

                        Debug.Check(parentBranch.m_currentTask == null);

                        parentBranch = parentBranch.GetParent();
                    }
                }

                return status;
            }

            return s;
        }

        public override bool onevent(Agent pAgent, string eventName)
        {
            bool bGoOn = true;

            if (this.m_status == EBTStatus.BT_RUNNING && this.m_node.HasEvents())
            {
                Debug.Check(this.m_currentTask != null);

                bGoOn = this.oneventCurrentNode(pAgent, eventName);
            }

            return bGoOn;
        }

        protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            EBTStatus status = EBTStatus.BT_INVALID;

            if (this.m_currentTask != null)
            {
                EBTStatus s = this.m_currentTask.GetStatus();
                if (s != EBTStatus.BT_RUNNING)
                {
                    this.SetCurrentTask(null);
                }
            }

            if (this.m_currentTask != null)
            {
                status = this.tickCurrentNode(pAgent);
            }

            return status;
        }

		protected override bool isContinueTicking()
        {
            return false;
        }

        private bool oneventCurrentNode(Agent pAgent, string eventName)
        {
            Debug.Check(this.m_currentTask != null);

            EBTStatus s = this.m_currentTask.GetStatus();

            Debug.Check(s == EBTStatus.BT_RUNNING && this.m_node.HasEvents());

            bool bGoOn = this.m_currentTask.onevent(pAgent, eventName);

            //give the handling back to parents
            if (bGoOn)
            {
                BranchTask parentBranch = this.m_currentTask.GetParent();

                //back track the parents until the branch
                while (parentBranch != null && parentBranch != this)
                {
                    Debug.Check(parentBranch.GetStatus() == EBTStatus.BT_RUNNING);

                    bGoOn = parentBranch.onevent(pAgent, eventName);
                    if (!bGoOn)
                    {
                        return false;
                    }

                    parentBranch = parentBranch.GetParent();
                }
            }

            return bGoOn;
        }

        protected abstract void addChild(BehaviorTask pBehavior);

        //bookmark the current ticking node, it is different from m_activeChildIndex
        protected BehaviorTask m_currentTask;
        protected EBTStatus m_returnStatus;
    }

    // ============================================================================
    public class CompositeTask : BranchTask
    {
        public override void traverse(NodeHandler_t handler, Agent pAgent, object user_data)
        {
            if (handler(this, pAgent, user_data))
            {
				for (int i = 0; i < this.m_children.Count; ++i)
                {
					BehaviorTask task = this.m_children[i];
                    task.traverse(handler, pAgent, user_data);
                }
            }
        }

        protected CompositeTask()
        {
            m_activeChildIndex = InvalidChildIndex;
        }

        ~CompositeTask()
        {
            this.m_children.Clear();
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
            Debug.Check(node.GetChildrenCount() > 0);

            int childrenCount = node.GetChildrenCount();
            for (int i = 0; i < childrenCount; i++)
            {
                BehaviorNode childNode = node.GetChild(i);
                BehaviorTask childTask = childNode.CreateAndInitTask();

                this.addChild(childTask);
            }
        }

        public override void copyto(BehaviorTask target)
        {
            base.copyto(target);

            Debug.Check(target is CompositeTask);
            CompositeTask ttask = target as CompositeTask;

            ttask.m_activeChildIndex = this.m_activeChildIndex;

            Debug.Check(this.m_children.Count > 0);
            Debug.Check(this.m_children.Count == ttask.m_children.Count);

            int count = this.m_children.Count;

            for (int i = 0; i < count; ++i)
            {
                BehaviorTask childTask = this.m_children[i];
                BehaviorTask childTTask = ttask.m_children[i];

                childTask.copyto(childTTask);
            }
        }

        public override void save(ISerializableNode node)
        {
            base.save(node);

            //BehaviorTasks_t.size_type count = this.m_children.Count;
            //for (BehaviorTasks_t.size_type i = 0; i < count; ++i)
            //{
            //    BehaviorTask childTask = this.m_children[i];

            //    CSerializationID  nodeId = new CSerializationID("node");
            //    ISerializableNode chidlNode = node.newChild(nodeId);
            //    childTask.save(chidlNode);
            //}
        }

        public override void load(ISerializableNode node)
        {
            base.load(node);
        }

        protected override void addChild(BehaviorTask pBehavior)
        {
            pBehavior.SetParent(this);

            this.m_children.Add(pBehavior);
        }

		public override List<BehaviorNode> GetRunningNodes()
		{
			List<BehaviorNode> nodes = new List<BehaviorNode>();
			
			foreach (BehaviorTask task in m_children)
			{
				nodes.AddRange(task.GetRunningNodes());
			}
			
			return nodes;
		}

        protected List<BehaviorTask> m_children = new List<BehaviorTask>();

        //book mark the current child
        protected int m_activeChildIndex = InvalidChildIndex;
        protected const int InvalidChildIndex = -1;
    }

    // ============================================================================
    public class SingeChildTask : BranchTask
    {
        public override void traverse(NodeHandler_t handler, Agent pAgent, object user_data)
        {
            if (handler(this, pAgent, user_data))
            {
                if (this.m_root != null)
                {
                    this.m_root.traverse(handler, pAgent, user_data);
                }
            }
        }

        protected SingeChildTask()
        {
            m_root = null;
        }

        ~SingeChildTask()
        {
            m_root = null;
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);

            Debug.Check(node.GetChildrenCount() <= 1);

            if (node.GetChildrenCount() == 1)
            {
                BehaviorNode childNode = node.GetChild(0);

                BehaviorTask childTask = childNode.CreateAndInitTask();

                this.addChild(childTask);
            }
            else
            {
                Debug.Check(true);
            }
        }
        public override void copyto(BehaviorTask target)
        {
            base.copyto(target);

            Debug.Check(target is SingeChildTask);
            SingeChildTask ttask = target as SingeChildTask;

            if (this.m_root != null)
            {
                //referencebehavior/query, etc.
                if (ttask.m_root == null)
                {
                    BehaviorNode pNode = this.m_root.GetNode();
                    Debug.Check(pNode is BehaviorTree);
                    ttask.m_root = pNode.CreateAndInitTask();

                    //Debug.Check(ttask.m_root is BehaviorTreeTask);
                    //BehaviorTreeTask btt = ttask.m_root as BehaviorTreeTask;
                    //btt.ModifyId(ttask);
                }

                Debug.Check(ttask.m_root != null);
                this.m_root.copyto(ttask.m_root);
            }
        }

        public override void save(ISerializableNode node)
        {
            base.save(node);

            if (this.m_root != null)
            {
                //CSerializationID  nodeId = new CSerializationID("root");
                //ISerializableNode chidlNode = node.newChild(nodeId);
                //this.m_root.save(chidlNode);
            }
        }

        public override void load(ISerializableNode node)
        {
            base.load(node);
        }

        protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            if (this.m_currentTask != null)
            {
                EBTStatus s = base.update(pAgent, childStatus);

                return s;
            }

            if (this.m_root != null)
            {
                EBTStatus s = this.m_root.exec(pAgent);
                return s;
            }

            return EBTStatus.BT_INVALID;
        }

        protected override void addChild(BehaviorTask pBehavior)
        {
            pBehavior.SetParent(this);

            this.m_root = pBehavior;
        }

		public override List<BehaviorNode> GetRunningNodes()
		{
			List<BehaviorNode> nodes = new List<BehaviorNode>();

			BehaviorTask task = this.GetCurrentTask();	
			if (task == null)
			{
				task = m_root;
			}
				
			if (task != null)
			{
				nodes.AddRange(task.GetRunningNodes());
			}
			
			return nodes;
		}
		
		protected BehaviorTask m_root;
    }

    // ============================================================================
    public abstract class DecoratorTask : SingeChildTask
    {
        protected DecoratorTask()
        {
            m_bDecorateWhenChildEnds = false;
        }

        ~DecoratorTask()
        {
        }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
            DecoratorNode pDN = node as DecoratorNode;

            this.m_bDecorateWhenChildEnds = pDN.m_bDecorateWhenChildEnds;
        }

        public override void copyto(BehaviorTask target)
        {
            base.copyto(target);

            // Debug.Check(target is DecoratorTask);
            // DecoratorTask ttask = (DecoratorTask)target;
        }

        public override void save(ISerializableNode node)
        {
            base.save(node);
        }

        public override void load(ISerializableNode node)
        {
            base.load(node);
        }

        protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            EBTStatus status = base.update(pAgent, childStatus);

            if (!this.m_bDecorateWhenChildEnds || status != EBTStatus.BT_RUNNING)
            {
                EBTStatus result = this.decorate(status);

                if (status != EBTStatus.BT_RUNNING)
                {
                    BehaviorTask child = this.m_root;
                    if (child != null)
                    {
                        child.SetStatus(EBTStatus.BT_INVALID);
                    }

                    this.SetCurrentTask(null);
                }

                return result;
            }

            return EBTStatus.BT_RUNNING;
        }

        /*
        called when the child's tick returns success or failure.
        please note, it is not called if the child's tick returns running
        */
        protected abstract EBTStatus decorate(EBTStatus status);

		protected override bool isContinueTicking()
        {
            return true;
        }

        private bool m_bDecorateWhenChildEnds;
    }

    // ============================================================================
    public class BehaviorTreeTask : SingeChildTask
    {
        public void SetRootTask(BehaviorTask pRoot)
        {
            this.addChild(pRoot);
        }

        public void CopyTo(BehaviorTreeTask target)
        {
            this.copyto(target);
        }

        public void Save(ISerializableNode node)
        {
            //CSerializationID  btId = new CSerializationID("BehaviorTree");
            //ISerializableNode btNodeRoot = node.newChild(btId);

            //Debug.Check(this.GetNode() is BehaviorTree);
            //BehaviorTree bt = (BehaviorTree)this.GetNode();

            //CSerializationID  sourceId = new CSerializationID("source");
            //btNodeRoot.setAttr(sourceId, bt.GetName());

            //CSerializationID  nodeId = new CSerializationID("node");
            //ISerializableNode btNode = btNodeRoot.newChild(nodeId);

            //this.save(btNode);
        }

        public void Load(ISerializableNode node)
        {
            this.load(node);
        }

        /**
        return the path relative to the workspace path
        */
        public string GetName()
        {
            Debug.Check(this.m_node is BehaviorTree);
            BehaviorTree bt = this.m_node as BehaviorTree;
            Debug.Check(bt != null);
            return bt.GetName();
        }

        public BehaviorTreeTask()
        {
        }

        ~BehaviorTreeTask()
        {
        }

        public override void Clear()
	    {
		    base.Clear();

		    this.m_currentTask = null;
            this.m_returnStatus = EBTStatus.BT_INVALID;
		    this.m_root = null;
	    }

        public override void Init(BehaviorNode node)
        {
            base.Init(node);
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


	    public EBTStatus resume(Agent pAgent, EBTStatus status) {
		    BranchTask prev = null;
		    BehaviorTask p = this.m_currentTask;
            while (p is BranchTask)
            {
                BranchTask b = (BranchTask)p;
                if (b.GetCurrentTask() != null)
                {
                    p = b.GetCurrentTask();
                }
                else
                {
                    break;
                }
            }

		    while (p != null) {
                BranchTask branch = p as BranchTask;
			    if (branch != null) {
				    prev = branch;
				    p = branch.GetCurrentTask();
			    }
				else {
					prev = p.GetParent();
					break;
				}
		    }

		    if (prev != null) {
				//prev is the last interrupted node, to find and let its parent update with 'status' which is the subtree's return status
			    Debug.Check(status == EBTStatus.BT_SUCCESS || status == EBTStatus.BT_FAILURE);
			    prev.onexit_action(pAgent, status);

			    prev.SetReturnStatus(status);
		    }

		    return status;
	    }

        protected override bool onenter(Agent pAgent)
        {
            return true;
        }

        protected override void onexit(Agent pAgent, EBTStatus s)
        {
        }

        protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
        {
            EBTStatus status = base.update(pAgent, childStatus);

            if (status != EBTStatus.BT_RUNNING)
            {
                this.SetCurrentTask(null);
            }

            return status;
        }

        public override bool NeedRestart()
        {
            BehaviorTask root = this.m_root;
            if (root != null && root.NeedRestart())
            {
                return true;
            }

            return false;
        }

        /**
        return false if the event handling  needs to be stopped
        return true, the event hanlding will be checked furtherly
        */
        public override bool onevent(Agent pAgent, string eventName)
        {
            if (this.m_node.HasEvents())
            {
                bool bGoOn = this.m_root.onevent(pAgent, eventName);

                if (bGoOn)
                {
                    if (this.m_status == EBTStatus.BT_RUNNING && this.m_node.HasEvents())
                    {
                        if (!this.CheckEvents(eventName, pAgent))
                        {
                            return false;
                        }
                    }

                    return false;
                }
            }

            return true;
        }

		protected override bool isContinueTicking()
        {
            return true;
        }
    }
}