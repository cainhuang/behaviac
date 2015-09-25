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

namespace behaviac
{
    class DefaultWorld : World
    {
        public DefaultWorld()
        {

        }
    }

    public class Context
    {
        private static Dictionary<int, Context> ms_contexts = new Dictionary<int, Context>();

        private Dictionary<string, Agent> m_namedAgents = new Dictionary<string, Agent>();
        private Dictionary<string, Variables> m_static_variables = new Dictionary<string, Variables>();
        private Dictionary<string, Dictionary<CStringID, CNamedEvent>> ms_eventInfosGlobal = new Dictionary<string, Dictionary<CStringID, CNamedEvent>>();

        int m_context_id;
        World m_world;

        Context(int contextId)
        {
            m_world = null;
            m_context_id = contextId;
        }

        ~Context()
        {
            this.m_world = null;

            this.CleanupStaticVariables();
            this.CleanupInstances();

            ms_eventInfosGlobal.Clear();
        }

		int GetContextId()
		{
			return this.m_context_id;
		}

        public static Context GetContext(int contextId)
        {
            Debug.Check(contextId >= 0);
            if (ms_contexts.ContainsKey(contextId))
            {
                Context pContext = ms_contexts[contextId];
                return pContext;
            }

            Context pC = new Context(contextId);
            ms_contexts[contextId] = pC;

            return pC;
        }


        public static void Cleanup(int contextId)
        {
            if (ms_contexts != null)
            {
                if (contextId == -1)
                {
                    ms_contexts.Clear();
                    //ms_contexts = null;
                }
                else
                {
                    if (ms_contexts.ContainsKey(contextId))
                    {
                        ms_contexts.Remove(contextId);
                    }
                    else
                    {
                        Debug.Check(false, "unused context id");
                    }
                }
            }
        }

        public void SetWorld(World pWorld)
        {
            if (this.m_world == null)
            {
                this.m_world = pWorld;
            }
            else
            {
                if (pWorld != null)
                {
                    if (this.m_world is DefaultWorld)
                    {
                        //in case world is not created before all agents
                        //copy the agents from the old world to the new one
                        pWorld.Agents = this.m_world.Agents;
                        this.m_world.Agents.Clear();
                    }
                }

                this.m_world = pWorld;
            }
        }

        public World GetWorld(bool bCreate)
        {
            if (System.Object.ReferenceEquals(m_world, null))
            {
                //check if an Workspace is already in the scene
                //m_world = UnityEngine.Object.FindObjectOfType(typeof(World)) as World;
                if (bCreate && System.Object.ReferenceEquals(m_world, null))
                {
                    UnityEngine.GameObject o = new UnityEngine.GameObject("_world_");

                    UnityEngine.GameObject.DontDestroyOnLoad(o);
                    m_world = o.AddComponent<DefaultWorld>();
                }
            }

            //Debug.Check(m_world != null);

            return m_world;
        }

        /**
        log changed static variables(propery) for the specified agent class or all agent classes

        @param agentClassName
        if null, it logs for all the agent class
        */
        public void LogStaticVariables(string agentClassName)
        {
            if (!string.IsNullOrEmpty(agentClassName))
            {
                if (m_static_variables.ContainsKey(agentClassName))
                {
                    Variables variables = m_static_variables[agentClassName];

                    variables.Log(null, false);
                }
            }
            else
            {
                foreach (Variables variables in m_static_variables.Values)
                {
                    variables.Log(null, false);
                }
            }
        }

        public static void LogCurrentStates()
        {
            if (ms_contexts != null)
            {
                foreach (Context pContext in ms_contexts.Values)
                {
                    if (!Object.ReferenceEquals(pContext.m_world, null))
                    {
                        pContext.m_world.LogCurrentStates();
                    }
                }
            }
        }

        void CleanupStaticVariables()
        {
            foreach (Variables variables in m_static_variables.Values)
            {
                variables.Clear();
            }

            m_static_variables.Clear();
        }

        public void ResetChangedVariables()
        {
            foreach (Variables variables in m_static_variables.Values)
            {
                variables.Reset();
            }
        }

        void CleanupInstances()
        {
            //foreach (KeyValuePair<string, Agent> p in m_namedAgents)
            //{
            //    string msg = string.Format("{0}:{1}", p.Key,p.Value.GetName());
            //    behaviac.Debug.Log(msg);
            //}

            //Debug.Check(m_namedAgents.Count == 0, "you need to call DestroyInstance or UnbindInstance");

            m_namedAgents.Clear();
        }
        /// <summary>
        /// if the caller's third parameter's type is object
        /// </summary>
        /// <param name="pMember"></param>
        /// <param name="variableName"></param>
        /// <param name="value"></param>
        /// <param name="staticClassName"></param>
        /// <param name="variableId"></param>
        public void SetStaticVariableObject(CMemberBase pMember, string variableName, object value, string staticClassName, uint variableId)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));
            Debug.Check(!string.IsNullOrEmpty(staticClassName));

            if (!m_static_variables.ContainsKey(staticClassName))
            {
                m_static_variables[staticClassName] = new Variables();
            }

            Variables variables = m_static_variables[staticClassName];
            variables.SetObject(null, pMember, variableName, value, variableId);
        }
        /**
        if staticClassName is no null, it is for static variable
        */
        public void SetStaticVariable<VariableType>(CMemberBase pMember, string variableName, VariableType value, string staticClassName, uint variableId)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));
            Debug.Check(!string.IsNullOrEmpty(staticClassName));

            if (!m_static_variables.ContainsKey(staticClassName))
            {
                m_static_variables[staticClassName] = new Variables();
            }

            Variables variables = m_static_variables[staticClassName];
			variables.Set(null, pMember, variableName, value, variableId);
        }

        static bool GetClassNameString(string variableName, ref string className)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));

            int pSep = variableName.LastIndexOf(':');

            if (pSep > 0)
            {
                Debug.Check(variableName[pSep - 1] == ':');
                className = variableName.Substring(0, pSep - 1);

                return true;
            }
            else
            {
                className = variableName;
                return true;
            }

            //return false;
        }

        public CNamedEvent FindEventStatic(string eventName, string className)
        {
            if (ms_eventInfosGlobal.ContainsKey(className))
            {
                Dictionary<CStringID, CNamedEvent> events = ms_eventInfosGlobal[className];
                CStringID eventID = new CStringID(eventName);

                if (events.ContainsKey(eventID))
                {
                    CNamedEvent pEvent = events[eventID];
                    return pEvent;
                }
            }

            return null;
        }

        public void InsertEventGlobal(string className, CNamedEvent pEvent)
        {
            CNamedEvent toFind = FindEventStatic(className, pEvent.Name);
            if (toFind == null)
            {
                if (!ms_eventInfosGlobal.ContainsKey(className))
                {
                    ms_eventInfosGlobal.Add(className, new Dictionary<CStringID, CNamedEvent>());
                }

                Dictionary<CStringID, CNamedEvent> events = ms_eventInfosGlobal[className];

                CNamedEvent e = (CNamedEvent)pEvent.clone();
                CStringID eventId = new CStringID(e.Name);
                events.Add(eventId, e);
            }
        }

        public CNamedEvent FindNamedEventTemplate(List<CMethodBase> methods, string eventName)
        {
            CStringID eventID = new CStringID(eventName);

            //reverse, so the event in the derived class can override the one in the base class
            for (int i = methods.Count - 1; i >= 0; --i)
            {
                CMethodBase pMethod = methods[i];
                string methodName = pMethod.Name;
                CStringID methodID = new CStringID(methodName);
                if (methodID == eventID && pMethod.IsNamedEvent())
                {
                    Debug.Check(pMethod is CNamedEvent);
                    CNamedEvent pNamedMethod = (CNamedEvent)pMethod;

                    if (pNamedMethod.IsStatic())
                    {
                        InsertEventGlobal(pNamedMethod.GetClassNameString(), pNamedMethod);
                        return pNamedMethod;
                    }

                    return pNamedMethod;
                }
            }

            return null;
        }

        /**
        bind 'agentInstanceName' to 'pAgentInstance'. 
        'agentInstanceName' should have been registered to the class of 'pAgentInstance' or its parent class.

        @sa RegisterName
        */
        public bool BindInstance(Agent pAgentInstance, string agentInstanceName)
        {
            if (string.IsNullOrEmpty(agentInstanceName))
            {
                agentInstanceName = pAgentInstance.GetType().FullName;
            }

            if (Agent.IsNameRegistered(agentInstanceName))
            {
                Debug.Check(GetInstance(agentInstanceName) == null, "the name has been bound to an instance already!");

                string className = Agent.GetRegisteredClassName(agentInstanceName);

                if (Agent.IsDerived(pAgentInstance, className))
                {
                    m_namedAgents[agentInstanceName] = pAgentInstance;

                    return true;
                }
            }
            else
            {
                Debug.Check(false);
            }

            return false;
        }

        public bool BindInstance(Agent pAgentInstance)
        {
            return BindInstance(pAgentInstance, null);
        }


        /**
        unbind 'agentInstanceName' from 'pAgentInstance'. 
        'agentInstanceName' should have been bound to 'pAgentInstance'.

        @sa RegisterName, BindInstance, CreateInstance
        */
        public bool UnbindInstance(string agentInstanceName)
        {
            Debug.Check(!string.IsNullOrEmpty(agentInstanceName));
            if (Agent.IsNameRegistered(agentInstanceName))
            {
                if (m_namedAgents.ContainsKey(agentInstanceName))
                {
                    m_namedAgents.Remove(agentInstanceName);

                    return true;
                }
            }
            else
            {
                Debug.Check(false);
            }


            return false;
        }

        public bool UnbindInstance<T>()
        {
            string agentInstanceName = typeof(T).FullName;
            return UnbindInstance(agentInstanceName);
        }

        public Agent GetInstance(string agentInstanceName)
        {
            bool bValidName = !string.IsNullOrEmpty(agentInstanceName);
            if (bValidName)
            {
                string className = null;
                GetClassNameString(agentInstanceName, ref className);

                if (m_namedAgents.ContainsKey(className))
                {
                    Agent pA = m_namedAgents[className];

                    return pA;
                }

                return null;
            }

            return null;
        }

        public bool Save(Dictionary<string, Agent.State_t> states)
        {
            foreach (KeyValuePair<string, Variables> pair in m_static_variables)
            {
                string className = pair.Key;
                Variables variables = pair.Value;

                //states.insert(std::pair<const string, State_t>(className, State_t()));
                states[className] = new Agent.State_t();

                variables.CopyTo(null, states[className].Vars);
            }

            return true;
        }

        public bool Load(Dictionary<string, Agent.State_t> states)
        {
            foreach (KeyValuePair<string, Agent.State_t> it in states)
            {
                if (m_static_variables.ContainsKey(it.Key))
                {
                    Variables variables_f = m_static_variables[it.Key];

                    it.Value.Vars.CopyTo(null, variables_f);
                }
            }

            return true;
        }
    }
}