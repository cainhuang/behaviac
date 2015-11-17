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
using System.Reflection;
using Behaviac.Design.Nodes;
using PluginBehaviac.DataExporters;

namespace PluginBehaviac.NodeExporters
{
    public class NodeCppExporter : NodeExporter
    {
        public static NodeCppExporter CreateInstance(Node node)
        {
            if (node != null)
            {
                Type exporterType = getExporterType(node.GetType());
                if (exporterType != null)
                    return (NodeCppExporter)Activator.CreateInstance(exporterType);
            }

            return new NodeCppExporter();
        }

        private static Type getExporterType(Type nodeType)
        {
            if (nodeType != null)
            {
                while (nodeType != typeof(Node))
                {
                    string nodeExporter = "PluginBehaviac.NodeExporters." + nodeType.Name + "CppExporter";
                    Type exporterType = Type.GetType(nodeExporter);
                    if (exporterType != null)
                        return exporterType;

                    foreach (Assembly assembly in Plugin.GetLoadedPlugins())
                    {
                        string filename = Path.GetFileNameWithoutExtension(assembly.Location);
                        nodeExporter = filename + ".NodeExporters." + nodeType.Name + "CppExporter";
                        exporterType = assembly.GetType(nodeExporter);
                        if (exporterType != null)
                            return exporterType;
                    }

                    nodeType = nodeType.BaseType;
                }
            }

            return null;
        }

        public override void GenerateClass(Node node, StreamWriter stream, string indent, string nodeName, string agentType, string btClassName)
        {
            if (ShouldGenerateClass(node))
            {
                string className = GetGeneratedClassName(node, btClassName, nodeName);

                stream.WriteLine("{0}\tclass {1} : public {2}\r\n{0}\t{{", indent, className, node.ExportClass);
                stream.WriteLine("{0}\tpublic:\r\n{0}\t\tBEHAVIAC_DECLARE_DYNAMIC_TYPE({1}, {2});", indent, className, node.ExportClass);

                stream.WriteLine("{0}\t\t{1}()", indent, className);
                stream.WriteLine("{0}\t\t{{", indent);

                GenerateConstructor(node, stream, indent, className);

                stream.WriteLine("{0}\t\t}}", indent);

                GenerateMethod(node, stream, indent);

                GenerateMember(node, stream, indent);

                stream.WriteLine("{0}\t}};\r\n", indent);
            }
        }

        public override void GenerateInstance(Node node, StreamWriter stream, string indent, string nodeName, string agentType, string btClassName)
        {
            string className = GetGeneratedClassName(node, btClassName, nodeName);

            // create a new instance of the node
            stream.WriteLine("{0}\t{1}* {2} = BEHAVIAC_NEW {1};", indent, className, nodeName);

            // set its basic properties
            stream.WriteLine("{0}\t{1}->SetClassNameString(\"{2}\");", indent, nodeName, node.ExportClass);
            stream.WriteLine("{0}\t{1}->SetId({2});", indent, nodeName, node.Id);
            stream.WriteLine("#if !defined(BEHAVIAC_RELEASE)");
            stream.WriteLine("{0}\t{1}->SetAgentType(\"{2}\");", indent, nodeName, agentType);
            stream.WriteLine("#endif");
        }

        protected string GetGeneratedClassName(Node node, string btClassName, string nodeName)
        {
            if (ShouldGenerateClass(node))
            {
                return string.Format("{0}_{1}_{2}", node.ExportClass, btClassName, nodeName);
            }

            return node.ExportClass;
        }

        protected virtual bool ShouldGenerateClass(Node node)
        {
            //return (node.EnterAction != null && node.EnterAction.Name != "null_method") ||
            //    (node.ExitAction != null && node.ExitAction.Name != "null_method");
            return false;
        }

        protected virtual void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            //if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            //{
            //    MethodCppExporter.GenerateClassConstructor(node.EnterAction, stream, indent, "EnterAction");
            //}

            //if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            //{
            //    MethodCppExporter.GenerateClassConstructor(node.ExitAction, stream, indent, "ExitAction");
            //}
        }

        protected virtual void GenerateMember(Node node, StreamWriter stream, string indent)
        {
            //if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            //{
            //    MethodCppExporter.GenerateClassMember(node.EnterAction, stream, indent, "EnterAction");
            //}

            //if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            //{
            //    MethodCppExporter.GenerateClassMember(node.ExitAction, stream, indent, "ExitAction");
            //}
        }

        protected virtual void GenerateMethod(Node node, StreamWriter stream, string indent)
        {
            stream.WriteLine("{0}\tprotected:", indent);

            //// enter
            //if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            //{
            //    stream.WriteLine("{0}\t\tvirtual bool enteraction_impl(Agent* pAgent)", indent);
            //    stream.WriteLine("{0}\t\t{{", indent);
            //    stream.WriteLine("{0}\t\t\tBEHAVIAC_UNUSED_VAR(pAgent);", indent);

            //    string retStr = MethodCppExporter.GenerateCode(node.EnterAction, stream, indent + "\t\t\t", node.EnterAction.NativeReturnType, string.Empty, "EnterAction");
            //    stream.WriteLine("{0}\t\t\t{1};", indent, retStr);

            //    MethodCppExporter.PostGenerateCode(node.EnterAction, stream, indent + "\t\t\t", node.EnterAction.NativeReturnType, string.Empty, "EnterAction");

            //    stream.WriteLine("{0}\t\t\treturn true;", indent);
            //    stream.WriteLine("{0}\t\t}}", indent);
            //}

            //// exit
            //if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            //{
            //    stream.WriteLine("{0}\t\tvirtual bool exitaction_impl(Agent* pAgent)", indent);
            //    stream.WriteLine("{0}\t\t{{", indent);
            //    stream.WriteLine("{0}\t\t\tBEHAVIAC_UNUSED_VAR(pAgent);", indent);

            //    string retStr = MethodCppExporter.GenerateCode(node.ExitAction, stream, indent + "\t\t\t", node.ExitAction.NativeReturnType, string.Empty, "ExitAction");
            //    stream.WriteLine("{0}\t\t\t{1};", indent, retStr);

            //    MethodCppExporter.PostGenerateCode(node.ExitAction, stream, indent + "\t\t\t", node.ExitAction.NativeReturnType, string.Empty, "ExitAction");

            //    stream.WriteLine("{0}\t\t\treturn true;", indent);
            //    stream.WriteLine("{0}\t\t}}", indent);
            //}
        }
    }
}
