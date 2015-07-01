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
    public class Condition : ConditionBase
    {
        public static bool Register<T>(string typeName)
        {
            return true;
        }

        public static void UnRegister<T>(string typeName)
        {
        }

        public static void RegisterBasicTypes()
        {
        }

        public static void UnRegisterBasicTypes()
        {
        }

        public Condition()
        {
        }

        ~Condition()
        {
            m_opl = null;
            m_opr = null;
            m_opl_m = null;
            m_comparator = null;
        }

        public static VariableComparator Create(string typeName, string comparionOperator, Property lhs, Property rhs)
        {
            E_VariableComparisonType comparisonType = VariableComparator.ParseComparisonType(comparionOperator);

            //bool bAgentPtr = false;
            //it might be par or the right value of condition/assignment
            if (Agent.IsAgentClassName(typeName))
            {
                //bAgentPtr = true;
                typeName = "void*";
            }

            VariableComparator pComparator = VariableComparator.Create(typeName, lhs, rhs);
            pComparator.SetComparisonType(comparisonType);

            return pComparator;
        }

        public static Property LoadLeft(string value, ref string propertyName, string constValue)
        {
            Property opl = null;

            if (!string.IsNullOrEmpty(value))
            {
                string[] tokens = value.Split(' ');

                if (tokens != null && tokens.Length == 2)
                {
                    //int AgentTest::Property1
                    string typeName = tokens[0].Replace("::", ".");
                    propertyName = tokens[1];
                    opl = Property.Create(typeName, tokens[1], constValue, false, false);
                }
                else
                {
                    //static int AgentTest::Property6
                    Debug.Check(tokens[0] == "static");
                    string typeName = tokens[1].Replace("::", ".");
                    propertyName = tokens[2];
                    opl = Property.Create(typeName, tokens[2], constValue, true, false);
                }
            }

            return opl;
        }

        public static Property LoadRight(string value, string propertyName, ref string typeName)
        {
            Property opr = null;
            if (!string.IsNullOrEmpty(value))
            {
                if (value.StartsWith("const"))
                {
                    //const Int32 0
                    const int kConstLength = 5;
                    string strRemaining = value.Substring(kConstLength + 1);
                    int p = StringUtils.FirstToken(strRemaining, ' ', ref typeName);

                    typeName = typeName.Replace("::", ".");

                    string strVale = strRemaining.Substring(p + 1);
                    opr = Property.Create(typeName, propertyName, strVale, false, true);
                }
                else
                {
                    string[] tokens = value.Split(' ');

                    if (tokens[0] == "static")
                    {
                        //static int Property1
                        Debug.Check(tokens.Length == 3);
                        typeName = tokens[1].Replace("::", ".");
                        opr = Property.Create(typeName, tokens[2], null, true, false);
                    }
                    else
                    {
                        //int Property1
                        Debug.Check(tokens.Length == 2);
                        typeName = tokens[0].Replace("::", ".");
                        opr = Property.Create(typeName, tokens[1], null, false, false);
                    }
                }
            }

            return opr;
        }

        public static Property ParseProperty(string value, ref string typeName)
        {
            Property opr = null;
            List<string> tokens = StringUtils.SplitTokens(value);

            if (tokens[0] == "static")
            {
                //static int Property1
                typeName = tokens[1].Replace("::", ".");
                if (tokens.Count == 3)
                {
                    opr = Property.Create(typeName, tokens[2], null, true, false);
                }
                else
                {
                    Debug.Check(tokens.Count == 4);
                    opr = Property.Create(typeName, tokens[2], tokens[3], true, false);
                }
            }
            else
            {
                //int Property1
                typeName = tokens[0].Replace("::", ".");
                if (tokens.Count == 2)
                {
                    opr = Property.Create(typeName, tokens[1], null, false, false);
                }
                else
                {
                    opr = Property.Create(typeName, tokens[1], tokens[2], false, false);
                }
            }

            return opr;
        }

        public static Property LoadProperty(string value)
        {
            string propertyName = null;
            string typeName = null;

            return LoadRight(value, propertyName, ref typeName);
        }

        protected override void load(int version, string agentType, List<property_t> properties)
        {
            base.load(version, agentType, properties);

            string typeName = null;
            string propertyName = null;
            string comparatorName = null;

            foreach (property_t p in properties)
            {
                if (p.name == "Operator")
                {
                    comparatorName = p.value;
                }
                else if (p.name == "Opl")
                {
                    int pParenthesis = p.value.IndexOf('(');
                    if (pParenthesis == -1)
                    {
                        this.m_opl = LoadLeft(p.value, ref propertyName, null);
                    }
                    else
                    {
                        //method
                        this.m_opl_m = Action.LoadMethod(p.value);
                    }
                }
                else if (p.name == "Opr")
                {
                    this.m_opr = Condition.LoadRight(p.value, propertyName, ref typeName);
                }
                else
                {
                    //Debug.Check(0, "unrecognised property %s", p.name);
                }
            }

            if (!string.IsNullOrEmpty(comparatorName) && (this.m_opl != null || this.m_opl_m != null) && this.m_opr != null)
            {
                this.m_comparator = Condition.Create(typeName, comparatorName, this.m_opl, this.m_opr);
            }
        }

        public override bool IsValid(Agent pAgent, BehaviorTask pTask)
        {
            if (!(pTask.GetNode() is Condition))
            {
                return false;
            }

            return base.IsValid(pAgent, pTask);
        }

        public bool Evaluate(Agent pAgent)
        {
            if (this.m_comparator != null)
            {
                bool bResult = Condition.DoCompare(pAgent, this.m_comparator, this.m_opl, this.m_opl_m, this.m_opr, null);

                return bResult;
            }
            else
            {
                EBTStatus childStatus = EBTStatus.BT_INVALID;
                EBTStatus result = this.update_impl(pAgent, childStatus);
                return result == EBTStatus.BT_SUCCESS;
            }
        }


        protected override BehaviorTask createTask()
        {
            ConditionTask pTask = new ConditionTask();

            return pTask;
        }

        public static bool DoCompare(Agent pAgent, VariableComparator comparator, Property opl, CMethodBase opl_m, Property opr, CMethodBase opr_m)
        {
            bool bResult = false;
            if (opl != null)
            {
                Agent agent_left = opl.GetParentAgent(pAgent);
                Agent agent_right = opr != null ? opr.GetParentAgent(pAgent) : opr_m.GetParentAgent(pAgent);

                bResult = comparator.Execute(agent_left, agent_right);
            }
            else if (opl_m != null)
            {
                Agent agent_left = opl_m.GetParentAgent(pAgent);

                object returnValue = opl_m.Invoke(agent_left, pAgent);

                Agent agent_right = opr != null ? opr.GetParentAgent(pAgent) : opr_m.GetParentAgent(pAgent);

                bResult = comparator.Execute(returnValue, agent_left, agent_right);
            }

            return bResult;
        }


        protected Property m_opl;
        Property m_opr;
        CMethodBase m_opl_m;
        VariableComparator m_comparator;

        class ConditionTask : ConditionBaseTask
        {
            public ConditionTask()
            {
            }

            ~ConditionTask()
            {
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

            protected override bool onenter(Agent pAgent)
            {
                return true;
            }
            protected override void onexit(Agent pAgent, EBTStatus s)
            {
            }

            protected override EBTStatus update(Agent pAgent, EBTStatus childStatus)
            {
                Debug.Check(childStatus == EBTStatus.BT_RUNNING);

                Debug.Check(this.GetNode() is Condition);
                Condition pConditionNode = (Condition)(this.GetNode());

                bool ret = pConditionNode.Evaluate(pAgent);

                return ret ? EBTStatus.BT_SUCCESS : EBTStatus.BT_FAILURE;
            }


        }
    }
}