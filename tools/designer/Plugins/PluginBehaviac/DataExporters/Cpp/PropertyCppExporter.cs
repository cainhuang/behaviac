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
    public class PropertyCppExporter
    {
        public static string GenerateCode(Behaviac.Design.PropertyDef property, StreamWriter stream, string indent, string typename, string var, string caller)
        {
            string agentName = getGenerateAgentName(property, var, caller);
            if (property.Owner != Behaviac.Design.VariableDef.kSelf)
            {
                stream.WriteLine("{0}Agent* {1} = Agent::GetInstance(\"{2}\", pAgent->GetContextId());", indent, agentName, property.Owner);
                stream.WriteLine("{0}BEHAVIAC_ASSERT({1});", indent, agentName);
            }

            //string retStr = string.Format("(({0}*){1})->{2}", property.ClassName, agentName, property.Name);
            string propName = property.Name.Replace("::", "_");
            string nativeType = DataCppExporter.GetGeneratedNativeType(property.NativeType);
            string retStr = string.Format("(({0}*){1})->_Get_Property_<{2}PROPERTY_TYPE_{3}, {4} >()", property.ClassName, agentName, getNamespace(property.ClassName), propName, nativeType);

            if (!string.IsNullOrEmpty(var))
            {
                if (string.IsNullOrEmpty(typename))
                {
                    stream.WriteLine("{0}{1} = {2};", indent, var, retStr);
                }
                else
                {
                    stream.WriteLine("{0}{1}& {2} = {3};", indent, DataCppExporter.GetGeneratedNativeType(property.NativeType), var, retStr);
                }
            }

            return retStr;
        }

        public static void PostGenerateCode(Behaviac.Design.PropertyDef property, StreamWriter stream, string indent, string typename, string var, string caller, string setValue = null)
        {
            string[] name = property.Name.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
            if (name.Length > 0)
            {
                string agentName = getGenerateAgentName(property, var, caller);
                string prop = setValue;
                if (setValue == null)
                {
                    //string prop = string.Format("(({0}*){1})->{2}", property.ClassName, agentName, property.Name);
                    string propName = property.Name.Replace("::", "_");
                    string nativeType = DataCppExporter.GetGeneratedNativeType(property.NativeType);
                    prop = string.Format("(({0}*){1})->_Get_Property_<{2}PROPERTY_TYPE_{3}, {4} >()", property.ClassName, agentName, getNamespace(property.ClassName), propName, nativeType);
                }

                uint id = Behaviac.Design.CRC32.CalcCRC(name[name.Length - 1]);
                stream.WriteLine("{0}BEHAVIAC_ASSERT(behaviac::MakeVariableId(\"{1}\") == {2}u);", indent, name[name.Length - 1], id);
                stream.WriteLine("{0}{1}->SetVariable(\"{2}\", {3}, {4}u);", indent, agentName, name[name.Length - 1], prop, id);
            }
        }

        private static string getNamespace(string className)
        {
            if (!string.IsNullOrEmpty(className))
            {
                int index = className.LastIndexOf(":");
                if (index > 1)
                    return className.Substring(0, index - 1) + "::";
            }

            return string.Empty;
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
    }
}
