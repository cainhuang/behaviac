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
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace PluginBehaviac.DataExporters
{
    public class PropertyCsExporter
    {
        public static string GenerateCode(Behaviac.Design.PropertyDef property, StreamWriter stream, string indent, string typename, string var, string caller, string setValue = null)
        {
            string agentName = getGenerateAgentName(property, var, caller);

            if (property.Owner != Behaviac.Design.VariableDef.kSelf)
            {
                stream.WriteLine("{0}behaviac.Agent {1} = behaviac.Agent.GetInstance(\"{2}\", pAgent.GetContextId());", indent, agentName, property.Owner.Replace("::", "."));
                stream.WriteLine("{0}Debug.Check({1} != null);", indent, agentName);
            }

            string prop = getProperty(property, agentName);

            if (setValue == null)
            {
                if (!string.IsNullOrEmpty(var))
                {
                    if (string.IsNullOrEmpty(typename))
                    {
                        stream.WriteLine("{0}{1} = {2};", indent, var, prop);
                    }
                    else
                    {
                        stream.WriteLine("{0}{1} {2} = {3};", indent, DataCsExporter.GetGeneratedNativeType(property.NativeType), var, prop);
                    }
                }
            }
            else
            {
                stream.WriteLine("{0}AgentExtra_Generated.SetProperty({1}, \"{2}\", {3});", indent, agentName, property.BasicName, setValue);
            }

            return prop;
        }

        public static void PostGenerateCode(Behaviac.Design.PropertyDef property, StreamWriter stream, string indent, string typename, string var, string caller, string setValue = null)
        {
            string agentName = getGenerateAgentName(property, var, caller);
            string prop = setValue;

            if (property.Owner != Behaviac.Design.VariableDef.kSelf)
            {
                stream.WriteLine("{0}behaviac.Agent {1} = behaviac.Agent.GetInstance(\"{2}\", pAgent.GetContextId());", indent, agentName, property.Owner.Replace("::", "."));
                stream.WriteLine("{0}Debug.Check({1} != null);", indent, agentName);
            }

            if (setValue != null)
            {
                stream.WriteLine("{0}AgentExtra_Generated.SetProperty({1}, \"{2}\", {3});", indent, agentName, property.BasicName, prop);
            }
            else
            {
                prop = getProperty(property, agentName);
            }

            uint id = Behaviac.Design.CRC32.CalcCRC(property.BasicName);
            stream.WriteLine("{0}Debug.Check(behaviac.Utils.MakeVariableId(\"{1}\") == {2}u);", indent, property.BasicName, id);

            stream.WriteLine("{0}{1}.SetVariable(\"{2}\", {3}, {4}u);", indent, agentName, property.BasicName, prop, id);
        }

        private static string getGenerateAgentName(Behaviac.Design.PropertyDef property, string var, string caller)
        {
            string agentName = "pAgent";
            if (property.Owner != Behaviac.Design.VariableDef.kSelf)
            {
                agentName = string.Format("pAgent_{0}", string.IsNullOrEmpty(var) ? caller : var);
                agentName = agentName.Replace(".", "_");
            }
            return agentName;
        }

        private static string getProperty(Behaviac.Design.PropertyDef property, string agentName)
        {
            if (property.IsPublic)
            {
                string className = property.ClassName.Replace("::", ".");
                if (property.IsStatic)
                {
                    return string.Format("{0}.{1}", className, property.BasicName);
                }
                else
                {
                    return string.Format("(({0}){1}).{2}", className, agentName, property.BasicName);
                }
            }

            string nativeType = DataCsExporter.GetGeneratedNativeType(property.NativeType);
            return string.Format("({0})AgentExtra_Generated.GetProperty({1}, \"{2}\")", nativeType, agentName, property.BasicName);
        }
    }
}
