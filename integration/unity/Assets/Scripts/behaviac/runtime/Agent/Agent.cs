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
using System.ComponentModel;
using System.Globalization;

using UnityEngine;

namespace behaviac
{
    //[Behaviac.Design.ClassDesc("Agent", "Agent", true, "Agent", "Agent")]
    public class Agent : MonoBehaviour
    {
        #region State
        public class State_t
        {
            protected Variables m_vars = new Variables();
            public Variables Vars
            {
                get
                {
                    return this.m_vars;
                }
            }

            protected BehaviorTreeTask m_bt;
            public BehaviorTreeTask BT
            {
                get
                {
                    return m_bt;
                }
                set
                {
                    m_bt = value;
                }
            }

            public State_t()
            {
            }

            public State_t(State_t c)
            {
                c.m_vars.CopyTo(null, this.m_vars);

                if (c.m_bt != null)
                {
                    BehaviorNode pNode = c.m_bt.GetNode();
                    this.m_bt = (BehaviorTreeTask)pNode.CreateAndInitTask();

                    c.m_bt.CopyTo(this.m_bt);
                }
            }

            ~State_t()
            {
                this.Clear();
            }

            public void Clear()
            {
                this.m_vars.Clear();

                this.m_bt = null;
            }

            public bool SaveToFile(string fileName)
            {
                //XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

                //CTextNode node(xmlInfo);

                //this.m_vars.Save(node);

                //if (this.m_bt)
                //{
                //    this.m_bt.Save(node);
                //}

                //CFileSystem::MakeSureDirectoryExist(fileName);
                //return xmlInfo.saveToFile(fileName);
                return false;
            }

            public bool LoadFromFile(string fileName)
            {
                //XmlNodeRef xmlInfo = CreateXmlNode("AgentState");

                //CTextNode node(xmlInfo);

                //if (node.LoadFromFile(fileName))
                //{
                //    this.m_vars.Load(&node);

                //    return true;
                //}

                return false;
            }
        }
        #endregion

        protected void Init()
        {
            Init_(this.m_contextId, this, this.m_priority, this.name);
        }

        //protected Agent()
        //{
        //}

        //~Agent()
        //{
        //    behaviac.Debug.LogWarning("Agent.Finalizer");
        //}

#if !BEHAVIAC_RELEASE
		static Dictionary<string, Agent> ms_agents = new Dictionary<string, Agent>();
		public static Agent GetAgent(string agentName)
		{
			Agent pAgent = Agent.GetInstance(agentName);
			if (!System.Object.ReferenceEquals(pAgent, null))
			{
				return pAgent;
			}

			if (ms_agents.ContainsKey(agentName))
			{
				Agent pA = ms_agents[agentName];
				return pA;
			}

			return null;
		}
#endif//BEHAVIAC_RELEASE


        protected void OnDestroy()
        {
            this.UnSubsribeToNetwork();

#if !BEHAVIAC_RELEASE
			string agentClassName = this.GetClassTypeName();
			string agentInstanceName = this.GetName();
			
			string aName = string.Format("{0}#{1}", agentClassName, agentInstanceName);

			ms_agents.Remove(aName);
#endif

            if (this.m_contextId >= 0)
            {
                Context c = Context.GetContext(this.m_contextId);
                World pWorld = c.GetWorld(false);
                if (!System.Object.ReferenceEquals(pWorld, null) && !System.Object.ReferenceEquals(pWorld, this))
                {
                    pWorld.RemoveAgent(this);
                }
            }

            if (this.m_behaviorTreeTasks != null)
            {
				for (int i = 0; i < this.m_behaviorTreeTasks.Count; ++i)
                {
					BehaviorTreeTask bt = this.m_behaviorTreeTasks[i];
					Workspace.DestroyBehaviorTreeTask(bt, this);
                }

                this.m_behaviorTreeTasks.Clear();
                this.m_behaviorTreeTasks = null;
            }
            if (this.m_eventInfos != null)
            {
                this.m_eventInfos.Clear();
                this.m_eventInfos = null;
            }
        }

        List<BehaviorTreeTask> m_behaviorTreeTasks;
        List<BehaviorTreeTask> BehaviorTreeTasks
        {
            get
            {
                if (m_behaviorTreeTasks == null)
                {
                    m_behaviorTreeTasks = new List<BehaviorTreeTask>();
                }

                return m_behaviorTreeTasks;
            }
        }


		class BehaviorTreeStackItem_t
		{
			public BehaviorTreeTask	bt;
			public TriggerMode triggerMode;
			public bool triggerByEvent;

			public BehaviorTreeStackItem_t(BehaviorTreeTask bt_, TriggerMode tm, bool bByEvent){
                bt = bt_;
                triggerMode = tm;
				triggerByEvent = bByEvent;
			}
		}

        List<BehaviorTreeStackItem_t> m_btStack;
        List<BehaviorTreeStackItem_t> BTStack
        {
            get
            {
                if (m_btStack == null)
                {
                    m_btStack = new List<BehaviorTreeStackItem_t>();
                }

                return m_btStack;
            }
        }

        BehaviorTreeTask m_currentBT;

        int m_id = -1;
        bool m_bActive = true;

		bool m_referencetree = false;

        public int m_priority;
        public int m_contextId;

        public int GetId()
        {
            return this.m_id;
        }

        public int GetPriority()
        {
            return (int)this.m_priority;
        }

        public string GetClassTypeName()
        {
            return this.GetType().FullName;
        }

		static uint ms_idMask = 0xffffffff;
		uint m_idFlag = 0xffffffff;

        /**
        Each agent can be assigned to an id flag by 'SetIdFlag'. A global mask can be specified by SetIdMask.
        the id flag will be checked with this global mask.

        @sa SetIdFlag SetIdMask
        */
        public bool IsMasked()
        {
            return (this.m_idFlag & Agent.IdMask()) != 0;
        }

        /**
        @sa SetIdMask IsMasked
        */
        public void SetIdFlag(uint idMask)
        {
            this.m_idFlag = idMask;
        }

        public static bool IsDerived(Agent pAgent, string agentType)
        {
            bool bIsDerived = false;
            Type type = pAgent.GetType();

            while (type != null)
            {
                if (type.FullName == agentType)
                {
                    bIsDerived = true;
                    break;
                }

                type = type.BaseType;
            }

            return bIsDerived;
        }


        /**
        @sa SetIdFlag IsMasked
        */
        public static void SetIdMask(uint idMask)
        {
            ms_idMask = idMask;
        }

        public static uint IdMask()
        {
            return ms_idMask;
        }

#if !BEHAVIAC_RELEASE
		private string m_debug_name;
#endif

        public string GetName()
        {
#if !BEHAVIAC_RELEASE
			return this.m_debug_name;
#else
			return this.name;
#endif
        }

        Variables m_variables;
        Variables Variables
        {
            get
            {
                if (m_variables == null)
                {
                    m_variables = new Variables();
                }

                return m_variables;
            }
        }

        static int ms_agent_index;
        static Dictionary<string, int> ms_agent_type_index;

        public void SetName(string instanceName)
        {
            if (string.IsNullOrEmpty(instanceName))
            {
                int typeId = 0;
                string typeFullName = this.GetType().FullName;
                string typeName = null;
                int pIt = typeFullName.LastIndexOf(':');
                if (pIt != -1)
                {
                    typeName = typeFullName.Substring(pIt + 1);
                }
                else
                {
                    typeName = typeFullName;
                }

                if (ms_agent_type_index == null)
                {
                    ms_agent_type_index = new Dictionary<string, int>();
                }

                if (!ms_agent_type_index.ContainsKey(typeFullName))
                {
                    typeId = 0;
                    ms_agent_type_index[typeFullName] = 1;
                }
                else
                {
                    typeId = ms_agent_type_index[typeFullName]++;
                }

                this.name += string.Format("{0}_{1}_{2}", typeName, typeId, this.m_id);
            }
            else
            {
                this.name = instanceName;
            }

#if !BEHAVIAC_RELEASE
			this.m_debug_name = this.name.Replace(" ", "_");
#endif
        }

        public int GetContextId()
        {
            return this.m_contextId;
        }

        /**
        return if the agent is active or not.

        an active agent is ticked automatiacally by the world it is added.
        if it is inactive, it is not ticked automatiacally by the world it is added.

        @sa SetActive
        */
        public bool IsActive()
        {
            return this.m_bActive;
        }

        /**
        set the agent active or inactive
        */
        void SetActive(bool bActive)
        {
            this.m_bActive = bActive;
        }

		public void SetVariableRegistry(CMemberBase pMember, string variableName, object value, string staticClassName, uint variableId)
        {
            bool bValidName = !string.IsNullOrEmpty(variableName);

            if (bValidName)
            {
                if (!string.IsNullOrEmpty(staticClassName))
                {
                    int contextId = this.GetContextId();
                    Context c = Context.GetContext(contextId);

					c.SetStaticVariable(pMember, variableName, value, staticClassName, variableId);
                }
                else
                {
					this.Variables.Set(this, pMember, variableName, value, variableId);
                }
            }
        }

        public struct AgentName_t
        {
            public string instantceName_;
            public string className_;
            public string displayName_;
            public string desc_;

            public AgentName_t(string instanceName, string className,
                string displayName, string desc)
            {
                instantceName_ = instanceName;
                className_ = className;

                if (!string.IsNullOrEmpty(displayName))
                {
                    displayName_ = displayName;
                }
                else
                {
                    displayName_ = instantceName_.Replace(".", "::");
                }

                if (!string.IsNullOrEmpty(desc))
                {
                    desc_ = desc;
                }
                else
                {
                    desc_ = displayName_;
                }
            }

            public string ClassName
            {
                get
                {
                    return this.className_;
                }
            }
        }


        private static Dictionary<string, AgentName_t> ms_names;
        public static Dictionary<string, AgentName_t> Names
        {
            get
            {
                if (ms_names == null)
                {
                    ms_names = new Dictionary<string, AgentName_t>();
                }
                return ms_names;
            }
        }

        //return true if 'agentClassName' is an agent class name or agent derived class name
        //IsAgentClassName is different from IsRegistered that IsRegistered only returns true for those classes directly registered by 'Register'
        //IsAgentClassName also returns true for those base classes.
        public static bool IsAgentClassName(CStringID agentClassId)
        {
            if (Agent.Metas.ContainsKey(agentClassId))
            {
                return true;
            }

            return false;
        }

        public static bool IsAgentClassName(string agentClassName)
        {
            CStringID agentClassId = new CStringID(agentClassName);

            bool bResult = IsAgentClassName(agentClassId);

            return bResult;
        }
        ///////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////
        /**
        A name can be bound to an instance. before a name is bound to an instance, that name has to be registered by 'RegisterName'

        @param agentInstanceName
        the specified name to be used to access an instance of type 'TAGENT' or its derivative.
        if 'agentInstanceName' is 0, the class name of 'TAGENT' will be used to be registered.

        @sa CreateInstance
        */
        public static bool RegisterName<TAGENT>(string agentInstanceName, string displayName, string desc) where TAGENT : Agent
        {
            string agentInstanceNameAny = agentInstanceName;
            if (string.IsNullOrEmpty(agentInstanceNameAny))
            {
                agentInstanceNameAny = typeof(TAGENT).FullName;
            }

            if (!Agent.Names.ContainsKey(agentInstanceNameAny))
            {
                string className = typeof(TAGENT).FullName;
                Agent.Names[agentInstanceNameAny] = new AgentName_t(agentInstanceNameAny, className, displayName, desc);

                return true;
            }

            return false;
        }

        public static bool RegisterName<TAGENT>(string agentInstanceName) where TAGENT : Agent
        {
            return Agent.RegisterName<TAGENT>(agentInstanceName, null, null);
        }

        public static bool RegisterName<TAGENT>() where TAGENT : Agent
        {
            return Agent.RegisterName<TAGENT>(null, null, null);
        }

		public static bool RegisterStaticClass(Type type, string displayName, string desc)
		{
			Debug.Check(Utils.IsStaticType(type));

			string agentInstanceNameAny = type.FullName;

			if (!Agent.Names.ContainsKey(agentInstanceNameAny))
			{
				Agent.Names[agentInstanceNameAny] = new AgentName_t(agentInstanceNameAny, agentInstanceNameAny, displayName, desc);
				Utils.AddStaticClass(type);

				return true;
			}
			
			return false;
		}

        public static void UnRegisterName<TAGENT>(string agentInstanceName) where TAGENT : Agent
        {
            string agentInstanceNameAny = agentInstanceName;
            if (string.IsNullOrEmpty(agentInstanceNameAny))
            {
                agentInstanceNameAny = typeof(TAGENT).FullName;
            }

            if (Agent.Names.ContainsKey(agentInstanceNameAny))
            {
                Agent.Names.Remove(agentInstanceNameAny);
            }
        }

        public static void UnRegisterName<TAGENT>() where TAGENT : Agent
        {
            Agent.UnRegisterName<TAGENT>(null);
        }

        /**
		return if 'agentInstanceName' is registerd.

		@sa RegisterName
		*/
        public static bool IsNameRegistered(string agentInstanceName)
        {
            return Names.ContainsKey(agentInstanceName);
        }

        /**
        return the registered class name

        @sa RegisterName
        */
        public static string GetRegisteredClassName(string agentInstanceName)
        {

            if (Names.ContainsKey(agentInstanceName))
            {
                return Names[agentInstanceName].ClassName;
            }

            return null;
        }

#if BEHAVIAC_UNITY_CREATE
        /**
                create an Agent with type 'TAGENT', with priority and agentInstanceName as name

                higher priority are ticked earlier

                @contextId
                by default, it is 0

                @sa Destroy
        */
        public static TAGENT Create<TAGENT>(string agentInstanceName, int contextId, short priority) where TAGENT : Agent, new()
        {
            string agentInstanceNameAny = agentInstanceName;
            if (agentInstanceNameAny.IsNullOrEmpty())
            {
                agentInstanceNameAny = typeof(TAGENT).Name;
            }

            Debug.Check(!Agent.IsNameRegistered(agentInstanceNameAny), "a registered name should be created by CreateInstance");

            //TAGENT should be derived from Agent
            GameObject go = new GameObject();
            Agent pAgent = go.AddComponent<TAGENT>();

            Debug.Check(!Object.ReferenceEquals(pAgent, null) && typeof(TAGENT).IsSubclassOf(typeof(Agent)));

            //string agentClassName = typeof(TAGENT).Name;
            Init_(contextId, pAgent, priority, agentInstanceName);
            Debug.Check(pAgent is TAGENT);
            TAGENT pA = pAgent as TAGENT;

            return pA;
        }

        public static TAGENT Create<TAGENT>(string agentInstanceName, int contextId) where TAGENT : Agent, new()
        {
            return Agent.Create<TAGENT>(agentInstanceName, contextId, 0);
        }

        public static TAGENT Create<TAGENT>() where TAGENT : Agent, new()
        {
            return Agent.Create<TAGENT>(null, 0, 0);
        }

        /**
        destroy the agent created by 'Create'

        @sa Create
        */
        static void Destory(Agent pAgent)
        {
            //pAgent.UnSubsribeToNetwork();

            //BEHAVIAC_DELETE(pAgent);
        }

        /**
        create an instance of 'TAGENT' and bind it to 'agentInstanceName'

        @param agentInstanceName
        the specified name to bind the created instance.
        if 'agentInstanceName' is 0, the class name of 'TAGENT' will be used.

        @contextId
        by default, it is 0

        @sa RegisterName
        */
        public static TAGENT CreateInstance<TAGENT>(string agentInstanceName, int contextId, short priority) where TAGENT : Agent, new()
        {
            Context c = Context.GetContext(contextId);

            TAGENT pA = null;

            string agentInstanceNameAny = agentInstanceName;
            if (agentInstanceNameAny.IsNullOrEmpty())
            {
                agentInstanceNameAny = typeof(TAGENT).FullName;
            }

            Debug.Check(Agent.IsNameRegistered(agentInstanceNameAny), "only a registered name can be created by CreateInstance");

            Agent a = c.GetInstance(agentInstanceNameAny);
            if (a == null)
            {
                //TAGENT should be derived from Agent
                GameObject go = new GameObject();
                Agent pAgent = go.AddComponent<TAGENT>();
                Debug.Check(!Object.ReferenceEquals(pAgent, null) && typeof(TAGENT).IsSubclassOf(typeof(Agent)));

                Init_(contextId, pAgent, priority, agentInstanceNameAny);
                Debug.Check(pAgent is TAGENT);

                c.BindInstance(pAgent, agentInstanceNameAny);
            }
            else
            {
                Debug.Check(a is TAGENT);

                pA = (TAGENT)a;
            }

            return pA;
        }

        public static TAGENT CreateInstance<TAGENT>(string agentInstanceName, int contextId) where TAGENT : Agent, new()
        {
            return Agent.CreateInstance<TAGENT>(agentInstanceName, contextId, 0);
        }

        public static TAGENT CreateInstance<TAGENT>(string agentInstanceName) where TAGENT : Agent, new()
        {
            return Agent.CreateInstance<TAGENT>(agentInstanceName, 0, 0);
        }

        public static TAGENT CreateInstance<TAGENT>() where TAGENT : Agent, new()
        {
            return Agent.CreateInstance<TAGENT>(null, 0, 0);
        }

        public static void DestroyInstance<TAGENT>(string agentInstanceName, int contextId) where TAGENT : Agent, new()
        {
            Context c = Context.GetContext(contextId);

            string agentInstanceNameAny = agentInstanceName;
            if (agentInstanceNameAny.IsNullOrEmpty())
            {
                agentInstanceNameAny = typeof(TAGENT).FullName;
            }

            Agent a = c.GetInstance(agentInstanceNameAny);
            c.UnbindInstance(agentInstanceNameAny);
        }

        public static void DestroyInstance<TAGENT>(string agentInstanceName) where TAGENT : Agent, new()
        {
            Agent.DestroyInstance<TAGENT>(agentInstanceName, 0);
        }


        public static void DestroyInstance<TAGENT>() where TAGENT : Agent, new()
        {
            Agent.DestroyInstance<TAGENT>(null, 0);
        }
#endif//BEHAVIAC_UNITY_CREATE

        /**
        bind 'agentInstanceName' to 'pAgentInstance'. 
        'agentInstanceName' should have been registered to the class of 'pAgentInstance' or its parent class.

        if 'agentInstanceName' is not specified, the class type name of 'pAgentInstance' will be used.
        @sa RegisterName
        */
        public static bool BindInstance(Agent pAgentInstance, string agentInstanceName, int contextId)
        {
            Context c = Context.GetContext(contextId);

            return c.BindInstance(pAgentInstance, agentInstanceName);
        }

        public static bool BindInstance(Agent pAgentInstance, string agentInstanceName)
        {
            return Agent.BindInstance(pAgentInstance, agentInstanceName, 0);
        }

        /**
        bind 'pAgentInstance' to the class type name of 'pAgentInstance'.

        RegisterName<TAGENT>() should have been called to regiser 'the class type name'.
        @sa RegisterName
        */
        public static bool BindInstance(Agent pAgentInstance)
        {
            return Agent.BindInstance(pAgentInstance, null, 0);
        }

        /**
        unbind 'agentInstanceName' from 'pAgentInstance'. 
        'agentInstanceName' should have been bound to 'pAgentInstance'.

        @sa RegisterName, BindInstance, CreateInstance
        */
        public static bool UnbindInstance(string agentInstanceName, int contextId)
        {
            Context c = Context.GetContext(contextId);

            return c.UnbindInstance(agentInstanceName);
        }

        public static bool UnbindInstance(string agentInstanceName)
        {
            return Agent.UnbindInstance(agentInstanceName, 0);
        }

        public static bool UnbindInstance<T>()
        {
            string agentInstanceName = typeof(T).FullName;
            return Agent.UnbindInstance(agentInstanceName);
        }

        public static Agent GetInstance(string agentInstanceName, int contextId)
        {
            Context c = Context.GetContext(contextId);

            return c.GetInstance(agentInstanceName);
        }

        public static Agent GetInstance(string agentInstanceName)
        {
            return Agent.GetInstance(agentInstanceName, 0);
        }

        public static TAGENT GetInstance<TAGENT>(string agentInstanceName, int contextId) where TAGENT : Agent, new()
        {
            string agentInstanceNameAny = agentInstanceName;
            if (string.IsNullOrEmpty(agentInstanceNameAny))
            {
                agentInstanceNameAny = typeof(TAGENT).FullName;
            }

            Agent a = Agent.GetInstance(agentInstanceNameAny, contextId);

            Debug.Check(System.Object.ReferenceEquals(a, null) || a is TAGENT);
            TAGENT pA = (TAGENT)a;
            return pA;
        }

        public static TAGENT GetInstance<TAGENT>(string agentInstanceName) where TAGENT : Agent, new()
        {
            return Agent.GetInstance<TAGENT>(agentInstanceName, 0);
        }

        public static TAGENT GetInstance<TAGENT>() where TAGENT : Agent, new()
        {
            return Agent.GetInstance<TAGENT>(null, 0);
        }

        public class CTagObjectDescriptor
        {
            public CTagObjectDescriptor()
            {
            }

            public void Load(Agent parent, ISerializableNode node)
            {
                foreach (CMemberBase m in ms_members)
                {
                    m.Load(parent, node);
                }

                if (this.m_parent != null)
                {
                    this.m_parent.Load(parent, node);
                }
            }
            public void Save(Agent parent, ISerializableNode node)
            {
                if (this.m_parent != null)
                {
                    this.m_parent.Save(parent, node);
                }

                foreach (CMemberBase m in ms_members)
                {
                    m.Save(parent, node);
                }
            }

            public static void PushBackMember(List<CMemberBase> inMembers, CMemberBase toAddMember)
            {
                inMembers.Add(toAddMember);
            }

            public CMemberBase GetMember(string memberName)
            {
                if (this.ms_members != null)
                {
					//CMemberBase pMember = this.ms_members.Find(delegate (CMemberBase m) {return m.GetName() == memberName;});
					for (int i = 0; i < this.ms_members.Count; ++i)
					{
						CMemberBase pMember = this.ms_members[i];
						if (pMember.GetName() == memberName)
						{
							return pMember;
						}
					}
                }

                if (this.m_parent != null)
                {
                    return this.m_parent.GetMember(memberName);
                }

                return null;
            }

            public List<CMemberBase> ms_members = new List<CMemberBase>();
            public List<CMethodBase> ms_methods = new List<CMethodBase>();

            public Type type;
            public string displayName;
            public string desc;
            public CTagObjectDescriptor m_parent = null;
        }

        public static CTagObjectDescriptor GetDescriptorByName(string className)
        {
            CStringID classNameid = new CStringID(className);
            if (Metas.ContainsKey(classNameid))
            {
                return Metas[classNameid];
            }

            CTagObjectDescriptor od = new CTagObjectDescriptor();
            Metas.Add(classNameid, od);

            return od;
        }

		private CTagObjectDescriptor m_objectDescriptor = null;
        public CTagObjectDescriptor GetDescriptor()
        {
			if (m_objectDescriptor == null) 
			{
				m_objectDescriptor = Agent.GetDescriptorByName (this.GetType ().FullName);
			}

			return m_objectDescriptor;
        }

        private static Dictionary<CStringID, CTagObjectDescriptor> ms_metas;
        public static Dictionary<CStringID, CTagObjectDescriptor> Metas
        {
            get
            {
                if (ms_metas == null)
                {
                    ms_metas = new Dictionary<CStringID, CTagObjectDescriptor>();
                }
                return ms_metas;
            }
        }

        public static bool IsTypeRegisterd(string typeName)
        {
            CStringID typeId = new CStringID(typeName);

            return ms_metas.ContainsKey(typeId);
        }

        public CMemberBase FindMember(string propertyName)
        {
            uint propertyId = Utils.MakeVariableId(propertyName);

            CMemberBase m = this.FindMember(propertyId);
            return m;
        }

        public CMemberBase FindMember(uint propertyId)
        {
            CTagObjectDescriptor objectDesc = this.GetDescriptor();

			CMemberBase pMember = null;
			for(int i = 0; i < objectDesc.ms_members.Count; ++i)
			{
				pMember = objectDesc.ms_members[i];
				if (pMember.GetId().GetId() == propertyId)
				{
					return pMember;
				}
			}

            return null;
        }

        static int ParsePropertyNames(string fullPropertnName, ref string agentClassName)
        {
            //test_ns::AgentActionTest::Property1
            int pBeginProperty = fullPropertnName.LastIndexOf(':');
            if (pBeginProperty != -1)
            {
                //skip '::'
                Debug.Check(fullPropertnName[pBeginProperty] == ':' && fullPropertnName[pBeginProperty - 1] == ':');
                pBeginProperty += 1;

                int pos = pBeginProperty - 2;

                agentClassName = fullPropertnName.Substring(pBeginProperty);

                return pos;
            }

            return -1;
        }

        public static CMemberBase FindMemberBase(string propertyName)
        {
            string propertyBaseName = null;
            //test_ns::AgentActionTest::Property1
            int pos = ParsePropertyNames(propertyName, ref propertyBaseName);

            if (pos != -1)
            {
                string classNameTo = propertyName.Substring(0, pos).Replace("::", ".");

                CStringID agentClassId = new CStringID(classNameTo);
                CStringID propertyId = new CStringID(propertyBaseName);

                CMemberBase m = FindMemberBase(agentClassId, propertyId);
                return m;
            }

            return null;
        }

        public static CMethodBase FindMethodBase(string propertyName)
        {
            int pSep = propertyName.LastIndexOf(':');

            if (pSep != -1)
            {
                Debug.Check(propertyName[pSep - 1] == ':');
                string classNameTo = propertyName.Substring(0, pSep - 1);

                CStringID agentClassId = new CStringID(classNameTo);
                CStringID propertyId = new CStringID(propertyName.Substring(pSep + 1));

                CMethodBase m = FindMethodBase(agentClassId, propertyId);
                return m;
            }

            return null;
        }

        public static CMemberBase FindMemberBase(CStringID agentClassId, CStringID propertyId)
        {
            if (Metas.ContainsKey(agentClassId))
            {
                CTagObjectDescriptor pObejctDesc = Metas[agentClassId];
                //CMemberBase pMember = pObejctDesc.ms_members.Find(delegate(CMemberBase m) { return m.GetId() == propertyId; });
				for (int i = 0; i < pObejctDesc.ms_members.Count; ++i)
				{
					CMemberBase pMember = pObejctDesc.ms_members[i];
					if (pMember.GetId() == propertyId)
					{
						return pMember;
					}
				}

	            if (pObejctDesc.type.BaseType != null)
	            {
	                CStringID agentBaseClassId = new CStringID(pObejctDesc.type.BaseType.FullName);

					CMemberBase pMember = FindMemberBase(agentBaseClassId, propertyId);

					return pMember;
	            }
            }

            return null;
        }

        public static CMethodBase FindMethodBase(CStringID agentClassId, CStringID propertyId)
        {
            if (Metas.ContainsKey(agentClassId))
            {
                //const string& className = it.first;

                CTagObjectDescriptor pObejctDesc = Metas[agentClassId];
                //CMethodBase pMethod = pObejctDesc.ms_methods.Find(delegate(CMethodBase m) { return m.GetId() == propertyId; });
				for (int i = 0; i < pObejctDesc.ms_methods.Count; ++i)
				{
					CMethodBase pMethod = pObejctDesc.ms_methods[i];
					if (pMethod.GetId() == propertyId)
					{
						return pMethod;
					}
				}

				if (pObejctDesc.type != null)
				{
		            if (pObejctDesc.type.BaseType != null)
		            {
		                CStringID agentBaseClassId = new CStringID(pObejctDesc.type.BaseType.FullName);

						CMethodBase pMethod = FindMethodBase(agentBaseClassId, propertyId);
						return pMethod;
		            }
				}
            }

            return null;
        }

        public static Property CreateProperty(string typeName, string propertyName, string defaultValue)
        {
            CMemberBase pMember = Agent.FindMemberBase(propertyName);

            if (pMember != null)
            {
                Property pProperty = pMember.CreateProperty(defaultValue, false);

                return pProperty;
            }
            //else
            //{
            //    CMethodBase pMethod = null;
            //    if (!propertyName.IsNullOrEmpty())
            //    {
            //        pMethod = Agent.FindMethodBase(propertyName);
            //    }

            //    if (pMethod != null)
            //    {
            //        return pMethod.CreateProperty(defaultValue, true);
            //    }
            //}

            return null;
        }

        ///////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////
        public static CMethodBase CreateMethod(CStringID agentClassId, CStringID methodClassId)
        {
            CMethodBase pM = Agent.FindMethodBase(agentClassId, methodClassId);
            Debug.Check(pM != null);

            return pM.clone();
        }

        /**
        get a variable by its name

        it is invalid to call GetVariable<Type>("par_name") before exec the BT or SetVariableGetVariable<Type>("par_name") 
        as "par_name" would not had been created then
        */
        public object GetVariable(string variableName)
        {
			uint varId = Utils.MakeVariableId (variableName);
			object v = this.Variables.Get(this, varId);

            return v;
        }

		public object GetVariable(uint variableId)
		{
			object v = this.Variables.Get(this, variableId);
			
			return v;
		}

        public void SetVariable<VariableType>(string variableName, VariableType value)
        {
			uint variableId = Utils.MakeVariableId(variableName);

			this.SetVariable (variableName, value, variableId);
        }

		public void SetVariable<VariableType>(string variableName, VariableType value, uint variableId)
		{
			if (variableId == 0) 
			{
				variableId = Utils.MakeVariableId(variableName);
			}

			this.Variables.Set(this, null, variableName, value, variableId);
		}

        public void SetVariableFromString(string variableName, string valueStr)
        {
            this.Variables.SetFromString(this, variableName, valueStr);
        }


        public void Instantiate<VariableType>(VariableType value, Property property_)
        {
            this.Variables.Instantiate(property_, value);
        }

        public void UnInstantiate(string variableName)
        {
            this.Variables.UnInstantiate(variableName);
        }

        public void UnLoad(string variableName)
        {
            this.Variables.UnLoad(variableName);
        }
#if !BEHAVIAC_RELEASE
        int m_debug_verify;
        private const int kAGENT_DEBUG_VERY = 0x01010101;
#endif//#if !BEHAVIAC_RELEASE

        protected static void Init_(int contextId, Agent pAgent, int priority, string agentInstanceName)
        {
#if !BEHAVIAC_RELEASE
            pAgent.m_debug_verify = kAGENT_DEBUG_VERY;
#endif//#if !BEHAVIAC_RELEASE

            Debug.Check(contextId >= 0, "invalid context id");

            pAgent.m_contextId = contextId;
            pAgent.m_id = ms_agent_index++;
            pAgent.m_priority = priority;

            pAgent.SetName(agentInstanceName);
            pAgent.InitVariableRegistry();

            {
                //World pWorld = World::GetInstance(contextId);
                Context c = Context.GetContext(contextId);
                World pWorldPtr = c.GetWorld(true);

                if (!System.Object.ReferenceEquals(pWorldPtr, null) && !System.Object.ReferenceEquals(pWorldPtr, pAgent))
                {
                    //string msg = string.Format("AddAgent {0} {1}", pAgent.GetName(), pWorldPtr.GetName());
                    //behaviac.Debug.Log(msg);
                    pWorldPtr.AddAgent(pAgent);
                }
            }

#if !BEHAVIAC_RELEASE
			string agentClassName = pAgent.GetClassTypeName();
			string instanceName = pAgent.GetName();
			
			string aName = string.Format("{0}#{1}", agentClassName, instanceName);
			
			ms_agents[aName] = pAgent;
#endif

            pAgent.SubsribeToNetwork();
        }


        public void btresetcurrrent()
        {
            if (this.m_currentBT != null)
            {
                this.m_currentBT.reset(this);
            }
        }


        /**
        before set the found one as the current bt, 
        it aborts the current one and pushes it on the stack so that it will be continued later when the 
        new one is finished.
        */
		public void btsetcurrent(string relativePath)
		{
			_btsetcurrent (relativePath, TriggerMode.TM_Transfer, false);
		}

		public void btreferencetree(string relativePath)
		{
			this._btsetcurrent(relativePath, TriggerMode.TM_Return, false);
			this.m_referencetree = true;
		}
		
		public void bteventtree(string relativePath, TriggerMode triggerMode)
		{
			this._btsetcurrent(relativePath, triggerMode, true);
		}


        private void _btsetcurrent(string relativePath, TriggerMode triggerMode, bool bByEvent)
        {
            bool bEmptyPath = string.IsNullOrEmpty(relativePath);
            Debug.Check(!bEmptyPath && string.IsNullOrEmpty(Path.GetExtension(relativePath)));
            Debug.Check(Workspace.IsValidPath(relativePath));

            if (!bEmptyPath)
            {
//				if (this.m_currentBT != null && this.m_currentBT.GetName() == relativePath)
//				{
//					//the same bt is set again
//					return;
//				}

                bool bLoaded = Workspace.Load(relativePath);

                if (!bLoaded)
                {
                    string agentName = this.GetType().FullName;
                    agentName += "::";
                    agentName += this.name;

                    Debug.Check(false);
                    System.Diagnostics.Debug.WriteLine(string.Format("{0} is not a valid loaded behavior tree of {1}", relativePath, agentName));
                }
                else
                {
                    Workspace.RecordBTAgentMapping(relativePath, this);

					if (this.m_currentBT != null)
                    {
						//if trigger mode is 'return', just push the current bt 'oldBt' on the stack and do nothing more
						//'oldBt' will be restored when the new triggered one ends
						if (triggerMode == TriggerMode.TM_Return)
						{
							BehaviorTreeStackItem_t item = new BehaviorTreeStackItem_t(this.m_currentBT, triggerMode, bByEvent);
	                        Debug.Check(this.BTStack.Count < 200, "recursive?");

	                        this.BTStack.Add(item);
						}
                        else if (triggerMode == TriggerMode.TM_Transfer)
                        {
                            //don't use the bt stack to restore, we just abort the current one.
                            //as the bt node has onenter/onexit, the abort can make them paired
							//Debug.Check (this.m_currentBT.GetName() != relativePath);
	                        
							this.m_currentBT.abort(this);
	                        this.m_currentBT.reset(this);
                        }
                    }

					//BehaviorTreeTask pTask = this.BehaviorTreeTasks.Find(delegate (BehaviorTreeTask task) {return task.GetName() == relativePath;});
					BehaviorTreeTask pTask = null;
					for (int i = 0; i < this.BehaviorTreeTasks.Count; ++i)
					{
						BehaviorTreeTask t = this.BehaviorTreeTasks[i];
						if (t.GetName() == relativePath)
						{
							pTask = t;
							break;
						}
					}

                    bool bRecursive = false;
					if (pTask != null && this.BTStack.Count > 0)
                    {
						//bRecursive = this.BTStack.FindIndex(delegate (BehaviorTreeStackItem_t item){return item.bt.GetName() == relativePath;}) > -1;
						for (int i = 0; i < this.BTStack.Count; ++i)
						{
							BehaviorTreeStackItem_t item = this.BTStack[i];
							if (item.bt.GetName() == relativePath)
							{
								bRecursive = true;
								break;
							}
						}
                    }

                    if (pTask == null || bRecursive)
                    {
                        pTask = Workspace.CreateBehaviorTreeTask(relativePath);
                        Debug.Check(pTask != null);
                        this.BehaviorTreeTasks.Add(pTask);
                    }

                    this.m_currentBT = pTask;
                }
            }
        }

		public List<BehaviorNode> GetRunningNodes()
		{
			List<BehaviorNode> nodes = new List<BehaviorNode>();
			
			if (this.m_currentBT != null)
			{
				nodes = this.m_currentBT.GetRunningNodes();
			}

			return nodes;
		}

        private EBTStatus btexec_()
        {
            if (this.m_currentBT != null)
            {
                //the following might modify this.m_currentBT if the invoked function called btsetcurrent/FireEvent
                BehaviorTreeTask currentBT = this.m_currentBT;
                EBTStatus s = this.m_currentBT.exec(this);
                Debug.Check(s == EBTStatus.BT_RUNNING || currentBT == this.m_currentBT, "btsetcurrent/FireEvent is not allowed in the invoked function.");

                while (s != EBTStatus.BT_RUNNING)
                {
                    this.m_currentBT.reset(this);
                    if (this.BTStack.Count > 0)
                    {
                        //get the last one
                        BehaviorTreeStackItem_t lastOne = this.BTStack[this.BTStack.Count - 1];
                        this.m_currentBT = lastOne.bt;
                        this.BTStack.RemoveAt(this.BTStack.Count - 1);

                        if (lastOne.triggerMode == TriggerMode.TM_Return)
                        {
                            string newBT = this.m_currentBT.GetName();
                            LogManager.Log(this, newBT, EActionResult.EAR_none, LogMode.ELM_return);

							if (!lastOne.triggerByEvent)
							{
	                            /*EBTStatus s0 = */this.m_currentBT.resume(this, s);
	                            s = this.m_currentBT.exec(this);
							}
                        }
                        else
                        {
                            s = this.m_currentBT.exec(this);
                            break;
                        }

                    }
                    else
                    {
                        //this.m_currentBT = null;
                        break;
                    }
                }

                return s;
            }
            else
            {
                //behaviac.Debug.LogWarning("NO ACTIVE BT!\n");
            }

            return EBTStatus.BT_INVALID;
        }

        public virtual EBTStatus btexec()
        {
            if (this.m_bActive)
            {
#if !BEHAVIAC_RELEASE
                Debug.Check(this.m_debug_verify == kAGENT_DEBUG_VERY, "You did not call Agent.Init!");
#endif//#if !BEHAVIAC_RELEASE

                this.UpdateVariableRegistry();


                EBTStatus s = this.btexec_();

				while (this.m_referencetree && s == EBTStatus.BT_RUNNING)
				{
					this.m_referencetree = false;
					s = this.btexec_();
				}

                if (this.IsMasked())
                {
                    this.LogVariables(false);
                }

                return s;
            }

			Profiler.EndSample();

            return EBTStatus.BT_INVALID;
        }

        public void btonevent(string btEvent)
        {
            if (this.m_currentBT != null)
            {
                this.m_currentBT.onevent(this, btEvent);
            }
        }

        public BehaviorTreeTask btgetcurrent()
        {
            return m_currentBT;
        }

        public bool btload(string relativePath, bool bForce /*= false*/)
        {
            bool bOk = Workspace.Load(relativePath, bForce);

            if (bOk)
            {
                Workspace.RecordBTAgentMapping(relativePath, this);
            }

            return bOk;
        }

        public bool btload(string relativePath)
        {
            bool bOk = this.btload(relativePath, false);

            return bOk;
        }

        public void btunload(string relativePath)
        {
            Debug.Check(string.IsNullOrEmpty(Path.GetExtension(relativePath)), "no extention to specify");
            Debug.Check(Workspace.IsValidPath(relativePath));

            //clear the current bt if it is the current bt
            if (this.m_currentBT != null && this.m_currentBT.GetName() == relativePath)
            {
			    BehaviorNode btNode = this.m_currentBT.GetNode();
			    Debug.Check(btNode is BehaviorTree);
                BehaviorTree bt = btNode as BehaviorTree;
			    this.btunload_pars(bt);

                this.m_currentBT = null;
            }

            //remove it from stack
			for (int i = 0; i < this.BTStack.Count; ++i)
            {
				BehaviorTreeStackItem_t item = this.BTStack[i];
                if (item.bt.GetName() == relativePath)
                {
                    this.BTStack.Remove(item);
                    break;
                }
            }

			for (int i = 0; i < this.BehaviorTreeTasks.Count; ++i)
            {
				BehaviorTreeTask task = this.BehaviorTreeTasks[i];
                if (task.GetName() == relativePath)
                {
                    Workspace.DestroyBehaviorTreeTask(task, this);

                    this.BehaviorTreeTasks.Remove(task);
                    break;
                }
            }

            Workspace.UnLoad(relativePath);
        }

        /**
        called when hotreloaded

        the default implementation is unloading all pars. 

        it can be overridden to do some clean up, like to reset some internal states, etc.
        */
        public virtual void bthotreloaded(BehaviorTree bt)
        {
            this.btunload_pars(bt);
        }

        public void btunloadall()
        {
			List<BehaviorTree> bts = new List<BehaviorTree>();
			foreach (BehaviorTreeTask btTask in this.BehaviorTreeTasks)
            {
				BehaviorNode btNode = btTask.GetNode();
				Debug.Check(btNode is BehaviorTree);
				BehaviorTree bt = (BehaviorTree)btNode;

				bool bFound = false;
				foreach (BehaviorTree it in bts)
				{
					if (it == bt)
					{
						bFound = true;
						break;
					}
				}
				if (!bFound)
				{
					bts.Add(bt);
				}

				Workspace.DestroyBehaviorTreeTask(btTask, this);
            }

			foreach (BehaviorTree it in bts) 
			{
				this.btunload_pars (it);

				Workspace.UnLoad(it.GetName());
			}

            this.BehaviorTreeTasks.Clear();

            //just clear the name vector, don't unload it from cache
            this.m_currentBT = null;
            this.BTStack.Clear();

            this.Variables.Unload();
        }

        public void btreloadall()
        {
            this.m_currentBT = null;
            this.BTStack.Clear();

            if (this.m_behaviorTreeTasks != null)
            {
                List<string> bts = new List<string>();

                //collect the bts
                foreach (BehaviorTreeTask bt in this.m_behaviorTreeTasks)
                {
                    string btName = bt.GetName();
                    if (bts.IndexOf(btName) == -1)
                    {
                        bts.Add(btName);
                    }
                }

				for (int i = 0; i < bts.Count; ++i)
                {
					string btName = bts[i];
                    Workspace.Load(btName, true);
                }

                this.BehaviorTreeTasks.Clear();
            }

            this.Variables.Unload();
        }

        public bool btsave(State_t state)
        {
            this.m_variables.CopyTo(null, state.Vars);

            if (this.m_currentBT != null)
            {
                Workspace.DestroyBehaviorTreeTask(state.BT, this);

                BehaviorNode pNode = this.m_currentBT.GetNode();
                state.BT = (BehaviorTreeTask)pNode.CreateAndInitTask();
                this.m_currentBT.CopyTo(state.BT);

                return true;
            }

            return false;
        }

        public bool btload(State_t state)
        {
            state.Vars.CopyTo(this, this.m_variables);

            if (state.BT != null)
            {
                if (this.m_currentBT != null)
                {
					for (int i = 0; i < this.m_behaviorTreeTasks.Count; ++i)
                    {
						BehaviorTreeTask task = this.m_behaviorTreeTasks[i];
                        if (task == this.m_currentBT)
                        {
                            Workspace.DestroyBehaviorTreeTask(task, this);

                            this.m_behaviorTreeTasks.Remove(task);
                            break;
                        }
                    }
                }

                BehaviorNode pNode = state.BT.GetNode();
                this.m_currentBT = (BehaviorTreeTask)pNode.CreateAndInitTask();
                state.BT.CopyTo(this.m_currentBT);

                return true;
            }

            return false;
        }

        private void btunload_pars(BehaviorTree bt)
        {
			if(bt.m_pars != null)
			{
				for (int i = 0; i < bt.m_pars.Count; ++i)
	            {
					Property property = bt.m_pars[i];
	                property.UnLoad(this);
	            }
			}
        }

        CNamedEvent findEventStatic(string eventName, string className, int context_id)
        {
            Context c = Context.GetContext(context_id);

            return c.FindEventStatic(eventName, className);
        }

        void insertEventGlobal(string className, CNamedEvent pEvent, int context_id)
        {
            Context c = Context.GetContext(context_id);

            c.InsertEventGlobal(className, pEvent);
        }

        static CNamedEvent findNamedEventTemplate(List<CMethodBase> methods, string eventName, int context_id)
        {
            Context c = Context.GetContext(context_id);

            return c.FindNamedEventTemplate(methods, eventName);
        }

        Dictionary<CStringID, CNamedEvent> m_eventInfos;
        Dictionary<CStringID, CNamedEvent> EventInfos
        {
            get
            {
                if (m_eventInfos == null)
                {
                    m_eventInfos = new Dictionary<CStringID, CNamedEvent>();
                }

                return m_eventInfos;
            }
        }

        CNamedEvent findEvent(string eventName)
        {
            CTagObjectDescriptor meta = this.GetDescriptor();

            int contextId = this.GetContextId();
            CNamedEvent pNamedMethod = findNamedEventTemplate(meta.ms_methods, eventName, contextId);

            if (pNamedMethod != null)
            {
                CNamedEvent pEvent = (CNamedEvent)pNamedMethod.clone();

                CStringID eventID = new CStringID(eventName);

                this.EventInfos[eventID] = pEvent;

                return pEvent;
            }


            return null;
        }

        public void FireEvent(string eventName)
        {
            CNamedEvent pEvent = this.findEvent(eventName);
            if (pEvent == null)
            {
                int contextId = this.GetContextId();
                CTagObjectDescriptor meta = this.GetDescriptor();
                pEvent = Agent.findNamedEventTemplate(meta.ms_methods, eventName, contextId);
            }

            if (pEvent != null)
            {
                pEvent.SetFired(this, true);
            }
            else
            {
                Debug.Check(false, string.Format("unregistered event {0}", eventName));
            }
        }

        public void FireEvent<ParamType>(string eventName, ParamType param)
        {
            CNamedEvent pEvent = this.findEvent(eventName);
            if (pEvent == null)
            {
                int contextId = this.GetContextId();
                CTagObjectDescriptor meta = this.GetDescriptor();
                pEvent = Agent.findNamedEventTemplate(meta.ms_methods, eventName, contextId);
            }

            if (pEvent != null)
            {
                pEvent.SetParam(this, param);
                pEvent.SetFired(this, true);
            }
            else
            {
                Debug.Check(false, string.Format("unregistered event {0}", eventName));
            }
        }

        public void FireEvent<ParamType1, ParamType2>(string eventName, ParamType1 param1, ParamType2 param2)
        {
            CNamedEvent pEvent = this.findEvent(eventName);
            if (pEvent == null)
            {
                int contextId = this.GetContextId();
                CTagObjectDescriptor meta = this.GetDescriptor();
                pEvent = Agent.findNamedEventTemplate(meta.ms_methods, eventName, contextId);
            }

            if (pEvent != null)
            {
                pEvent.SetParam(this, param1, param2);
                pEvent.SetFired(this, true);
            }
            else
            {
                Debug.Check(false, string.Format("unregistered event {0}", eventName));
            }
        }

        public void FireEvent<ParamType1, ParamType2, ParamType3>(string eventName, ParamType1 param1, ParamType2 param2, ParamType3 param3)
        {
            CNamedEvent pEvent = this.findEvent(eventName);
            if (pEvent == null)
            {
                int contextId = this.GetContextId();
                CTagObjectDescriptor meta = this.GetDescriptor();
                pEvent = Agent.findNamedEventTemplate(meta.ms_methods, eventName, contextId);
            }

            if (pEvent != null)
            {
                pEvent.SetParam(this, param1, param2, param3);
                pEvent.SetFired(this, true);
            }
            else
            {
                Debug.Check(false, string.Format("unregistered event {0}", eventName));
            }
        }

        public bool IsFired(string eventName)
        {
            return false;
        }

        public void ResetEvent(string eventName)
        {
            CStringID eventID = new CStringID(eventName);

            if (this.EventInfos.ContainsKey(eventID))
            {
                CNamedEvent pEvent = this.EventInfos[eventID];

                pEvent.SetFired(this, false);

                return;
            }

            {
                int contextId = this.GetContextId();
                CTagObjectDescriptor meta = this.GetDescriptor();
                CNamedEvent pEvent = findNamedEventTemplate(meta.ms_methods, eventName, contextId);
                if (pEvent != null)
                {
                    pEvent.SetFired(this, false);
                }
            }
        }

        public void LogVariables(bool bForce)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                this.Variables.Log(this, bForce);
            }
#endif
        }

        void ResetChangedVariables()
        {
            this.Variables.Reset();
        }


        void InitVariableRegistry()
        {
            this.ResetChangedVariables();
#if !BEHAVIAC_RELEASE
			if (Config.IsLoggingOrSocketing) 
			{
				string className = this.GetType ().FullName;

				CPropertyNode properyNode = new CPropertyNode (this, className);

				this.Save (properyNode);
			}
#endif
        }

        void UpdateVariableRegistry()
        {
//#if !BEHAVIAC_RELEASE
//			if (Config.IsLoggingOrSocketing) 
//			{
//				CPropertyNode properyNode = new CPropertyNode (this, this.GetType ().FullName);
//
//				this.Save (properyNode);
//			}
//#endif
			this.ReplicateProperties ();
        }

        void Save(CPropertyNode node)
        {
            //Debug.Check(false);
        }

        void SubsribeToNetwork()
        {
            //behaviac.Network* pNw = behaviac.Network::GetInstance();
            //if (pNw && !pNw.IsSinglePlayer())
            //{
            //    const CTagObjectDescriptor& od = this.GetDescriptor();

            //    MethodsContainer::const_iterator it = od.ms_methods.begin();
            //    MethodsContainer::const_iterator itEnd = od.ms_methods.end();

            //    for (; it != itEnd; ++it)
            //    {
            //        CMethodBase* m = *it;
            //        //m.GetUiInfo(parent, xmlNode);
            //        m.SubsribeToNetwork(this);
            //    }
            //}
        }

        void UnSubsribeToNetwork()
        {
            //behaviac.Network* pNw = behaviac.Network::GetInstance();
            //if (pNw && !pNw.IsSinglePlayer())
            //{
            //    const CTagObjectDescriptor& od = this.GetDescriptor();

            //    MethodsContainer::const_iterator it = od.ms_methods.begin();
            //    MethodsContainer::const_iterator itEnd = od.ms_methods.end();

            //    for (; it != itEnd; ++it)
            //    {
            //        CMethodBase* m = *it;
            //        //m.GetUiInfo(parent, xmlNode);
            //        m.UnSubsribeToNetwork(this);
            //    }
            //}
        }

        void ReplicateProperties()
        {
            //behaviac.Network* pNw = behaviac.Network::GetInstance();
            //if (pNw && !pNw.IsSinglePlayer())
            //{
            //    const CTagObjectDescriptor& od = this.GetDescriptor();

            //    CTagObjectDescriptor::MembersVector_t::const_iterator it = od.ms_members.membersVector.begin();
            //    CTagObjectDescriptor::MembersVector_t::const_iterator itEnd = od.ms_members.membersVector.end();

            //    for (; it != itEnd; ++it)
            //    {
            //        CMemberBase* m = *it;

            //        m.ReplicateProperty(this);
            //    }
            //}
        }

        public static Type GetTypeFromName(string typeName)
        {
            CStringID typeNameId = new CStringID(typeName);

            if (Metas.ContainsKey(typeNameId))
            {
                CTagObjectDescriptor objectDesc = Metas[typeNameId];

                return objectDesc.type;
            }

            return null;
        }

        [TypeConverter()]
        public class StructConverter : TypeConverter
        {
            // Overrides the CanConvertFrom method of TypeConverter.
            // The ITypeDescriptorContext interface provides the context for the
            // conversion. Typically, this interface is used at design time to 
            // provide information about the design-time container.
            public override bool CanConvertFrom(ITypeDescriptorContext context,
               Type sourceType)
            {

                if (sourceType == typeof(string))
                {
                    return true;
                }
                return base.CanConvertFrom(context, sourceType);
            }
            // Overrides the ConvertFrom method of TypeConverter.
            public override object ConvertFrom(ITypeDescriptorContext context,
               CultureInfo culture, object value)
            {
                if (value is string)
                {
                }
                return base.ConvertFrom(context, culture, value);
            }
            // Overrides the ConvertTo method of TypeConverter.
            public override object ConvertTo(ITypeDescriptorContext context,
               CultureInfo culture, object value, Type destinationType)
            {
                if (destinationType == typeof(string))
                {
                }
                return base.ConvertTo(context, culture, value, destinationType);
            }
        }

    }
}
