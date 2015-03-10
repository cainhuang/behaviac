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
    public class NodeCsExporter : NodeExporter
    {
        public static NodeCsExporter CreateInstance(Node node)
        {
            if (node != null)
            {
                string nodeExporter = "PluginBehaviac.NodeExporters." + node.ExportClass + "CsExporter";
                Type exporterType = Type.GetType(nodeExporter);
                if (exporterType == null)
                {
                    foreach (Assembly assembly in Plugin.GetLoadedPlugins())
                    {
                        string filename = Path.GetFileNameWithoutExtension(assembly.Location);
                        nodeExporter = filename + ".NodeExporters." + node.ExportClass + "CsExporter";
                        exporterType = assembly.GetType(nodeExporter);
                        if (exporterType != null)
                        {
                            break;
                        }
                    }
                }

                if (exporterType != null)
                {
                    return (NodeCsExporter)Activator.CreateInstance(exporterType);
                }
            }

            return new NodeCsExporter();
        }

        public override void GenerateClass(Node node, StreamWriter stream, string indent, string nodeName, string agentType, string btClassName)
        {
            if (ShouldGenerateClass(node))
            {
                string className = GetGeneratedClassName(node, btClassName, nodeName);

                stream.WriteLine("{0}\tclass {1} : behaviac.{2}\r\n{0}\t{{", indent, className, node.ExportClass);

                stream.WriteLine("{0}\t\tpublic {1}()", indent, className);
                stream.WriteLine("{0}\t\t{{", indent);

                GenerateConstructor(node, stream, indent, className);

                stream.WriteLine("{0}\t\t}}", indent);

                GenerateMethod(node, stream, indent);

                GenerateMember(node, stream, indent);

                stream.WriteLine("{0}\t}}\r\n", indent);
            }
        }

        public override void GenerateInstance(Node node, StreamWriter stream, string indent, string nodeName, string agentType, string btClassName)
        {
            string className = GetGeneratedClassName(node, btClassName, nodeName);

            // create a new instance of the node
            stream.WriteLine("{0}\t{1} {2} = new {1}();", indent, className, nodeName);

            // set its basic properties
            stream.WriteLine("{0}\t{1}.SetClassNameString(\"{2}\");", indent, nodeName, node.ExportClass);
            stream.WriteLine("{0}\t{1}.SetId({2});", indent, nodeName, node.Id);
            stream.WriteLine("#if !BEHAVIAC_RELEASE");
            stream.WriteLine("{0}\t{1}.SetAgentType(\"{2}\");", indent, nodeName, agentType.Replace("::", "."));
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
            return (node.EnterAction != null && node.EnterAction.Name != "null_method") ||
                (node.ExitAction != null && node.ExitAction.Name != "null_method");
        }

        protected virtual void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            {
                MethodCsExporter.GenerateClassConstructor(node.EnterAction, stream, indent, "EnterAction");
            }

            if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            {
                MethodCsExporter.GenerateClassConstructor(node.ExitAction, stream, indent, "ExitAction");
            }
        }

        protected virtual void GenerateMember(Node node, StreamWriter stream, string indent)
        {
            if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            {
                MethodCsExporter.GenerateClassMember(node.EnterAction, stream, indent, "EnterAction");
            }

            if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            {
                MethodCsExporter.GenerateClassMember(node.ExitAction, stream, indent, "ExitAction");
            }
        }

        protected virtual void GenerateMethod(Node node, StreamWriter stream, string indent)
        {
            // enter
            if (node.EnterAction != null && node.EnterAction.Name != "null_method")
            {
                stream.WriteLine("{0}\t\tpublic override bool enteraction_impl(Agent pAgent)", indent);
                stream.WriteLine("{0}\t\t{{", indent);

                string retStr = MethodCsExporter.GenerateCode(node.EnterAction, stream, indent + "\t\t\t", node.EnterAction.NativeReturnType, string.Empty, "EnterAction");
                stream.WriteLine("{0}\t\t\t{1};", indent, retStr);

                MethodCsExporter.PostGenerateCode(node.EnterAction, stream, indent + "\t\t\t", node.EnterAction.NativeReturnType, string.Empty, "EnterAction");

                stream.WriteLine("{0}\t\t\treturn true;", indent);
                stream.WriteLine("{0}\t\t}}", indent);
            }

            // exit
            if (node.ExitAction != null && node.ExitAction.Name != "null_method")
            {
                stream.WriteLine("{0}\t\tpublic override bool exitaction_impl(Agent pAgent)", indent);
                stream.WriteLine("{0}\t\t{{", indent);

                string retStr = MethodCsExporter.GenerateCode(node.ExitAction, stream, indent + "\t\t\t", node.ExitAction.NativeReturnType, string.Empty, "ExitAction");
                stream.WriteLine("{0}\t\t\t{1};", indent, retStr);

                MethodCsExporter.PostGenerateCode(node.ExitAction, stream, indent + "\t\t\t", node.ExitAction.NativeReturnType, string.Empty, "ExitAction");

                stream.WriteLine("{0}\t\t\treturn true;", indent);
                stream.WriteLine("{0}\t\t}}", indent);
            }
        }
    }
}
