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
using Behaviac.Design;
using Behaviac.Design.Nodes;
using PluginBehaviac.Properties;
using PluginBehaviac.NodeExporters;
using PluginBehaviac.DataExporters;
using Behaviac.Design.Attributes;

namespace PluginBehaviac.Exporters
{
    public class ExporterCpp : Behaviac.Design.Exporters.Exporter
    {
        public ExporterCpp(BehaviorNode node, string outputFolder, string filename, List<string> includedFilenames = null)
            : base(node, outputFolder, filename, includedFilenames)
        {
            _outputFolder = Path.GetFullPath(_outputFolder);
            _filename = _filename.Replace('\\', '/');
        }

        public override Behaviac.Design.FileManagers.SaveResult Export()
        {
            string filename = string.Empty;
            Behaviac.Design.FileManagers.SaveResult result = VerifyFilename(out filename);
            if (Behaviac.Design.FileManagers.SaveResult.Succeeded == result)
            {
                // export to the file
                using (StreamWriter file = new StreamWriter(filename))
                {
                    ExportBehavior(file, _node, filename);
                    file.Close();
                }
            }

            return result;
        }

        public override Behaviac.Design.FileManagers.SaveResult Export(List<BehaviorNode> behaviors)
        {
            string filename = string.Empty;
            Behaviac.Design.FileManagers.SaveResult result = VerifyFilename(out filename);
            if (Behaviac.Design.FileManagers.SaveResult.Succeeded == result)
            {
                using (StreamWriter file = new StreamWriter(filename))
                {
                    ExportBehaviors(file, behaviors, filename);
                    file.Close();
                }
            }

            return result;
        }

        private void ExportBehavior(StreamWriter file, BehaviorNode behavior, string filename)
        {
            ExportHead(file, filename);

            ExportBody(file, behavior);

            ExportTail(file);
        }

        private void ExportBehaviors(StreamWriter file, List<BehaviorNode> behaviors, string filename)
        {
            ExportHead(file, filename);

            foreach (BehaviorNode behavior in behaviors)
            {
                ExportBody(file, behavior);
            }

            ExportTail(file);
        }

        private Behaviac.Design.FileManagers.SaveResult VerifyFilename(out string filename)
        {
            filename = Path.Combine(_outputFolder, _filename);

            // get the abolute folder of the file we want to export
            string folder = Path.GetDirectoryName(filename);
            if (!Directory.Exists(folder))
                Directory.CreateDirectory(folder);

            // verify it can be writable
            return Behaviac.Design.FileManagers.FileManager.MakeWritable(filename, Resources.ExportFileWarning);
        }

        private List<string> GetNamespaces(string ns)
        {
            List<string> namespaces = new List<string>();
            int startIndex = 0;

            for (int i = 0; i < ns.Length; ++i)
            {
                if (ns[i] == ':')
                {
                    Debug.Check(ns[i + 1] == ':');

                    namespaces.Add(ns.Substring(startIndex, i - startIndex));
                    startIndex = i + 2;
                    ++i;
                }
            }

            namespaces.Add(ns.Substring(startIndex, ns.Length - startIndex));

            return namespaces;
        }

        private string WriteNamespacesHead(StreamWriter file, List<string> namespaces)
        {
            string indent = string.Empty;
            for (int i = 0; i < namespaces.Count; ++i)
            {
                file.WriteLine("{0}namespace {1}", indent, namespaces[i]);
                file.WriteLine("{0}{{", indent);
                indent += '\t';
            }

            return indent;
        }

        private void WriteNamespacesTail(StreamWriter file, List<string> namespaces)
        {
            for (int i = 0; i < namespaces.Count; ++i)
            {
                string indent = string.Empty;
                for (int k = i + 1; k < namespaces.Count; ++k)
                {
                    indent += '\t';
                }

                file.WriteLine("{0}}}\r\n", indent);
            }
        }

        private void ExportHead(StreamWriter file, string exportFilename)
        {
            string wsfolder = Path.GetDirectoryName(Workspace.Current.FileName);
            exportFilename = Behaviac.Design.FileManagers.FileManager.MakeRelative(wsfolder, exportFilename);
            exportFilename = exportFilename.Replace("\\", "/");

            // write comments
            file.WriteLine("// ---------------------------------------------------------------------");
            file.WriteLine("/* This file is auto-generated, so please don't modify it by yourself!");
            file.WriteLine("Usage: include it in a certain cpp accordingly(RELATIVE_PATH is the path where it is generated):\n");
            file.WriteLine("      #include \"RELATIVE_PATH/generated_behaviors.cpp\"\n*/\n");
            file.WriteLine("// Export file: {0}", exportFilename);
            file.WriteLine("// ---------------------------------------------------------------------\r\n");

            // write included behaviac files
            file.WriteLine("// You should set the include path of the behaviac lib in your project\r\n// for using the following header files :");
            file.WriteLine("#include \"behaviac/behaviortree/behaviortree.h\"\r\n");

            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/action.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/assignment.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/compute.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/noop.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/wait.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/waitforsignal.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/actions/waitframes.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/compositestochastic.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/ifelse.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/parallel.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/query.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/referencebehavior.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/selector.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/selectorloop.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/selectorprobability.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/selectorstochastic.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/sequence.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/sequencestochastic.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/composites/withprecondition.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/and.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/conditionbase.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/condition.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/false.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/or.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/conditions/true.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratoralwaysfailure.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratoralwaysrunning.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratoralwayssuccess.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorcount.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorcountlimit.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorfailureuntil.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorframes.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorlog.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorloop.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorloopuntil.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratornot.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorsuccessuntil.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratortime.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/nodes/decorators/decoratorweight.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/attachments/event.h\"");
            file.WriteLine("#include \"behaviac/behaviortree/attachments/predicate.h\"\r\n");

            // write included files for the game agents
            if (this.IncludedFilenames != null)
            {
                file.WriteLine("// You should set the agent header files of your game\r\n// when exporting cpp files in the behaviac editor:");
                foreach (string filename in this.IncludedFilenames)
                {
                    file.WriteLine("#include \"{0}\"", filename);
                }
                file.WriteLine("");
            }

            // write the namespaces for the game agents
            file.WriteLine("using namespace behaviac;\r\n");

            // write property and method handlers
            file.WriteLine("// Agent property and method handlers\r\n");

            foreach (AgentType agenType in Plugin.AgentTypes)
            {
                List<string> namespaces = new List<string>();
                string ns = agenType.Namespace;

                if (!string.IsNullOrEmpty(ns))
                {
                    foreach (PropertyDef property in agenType.GetProperties())
                    {
                        if (property.ClassName == agenType.AgentTypeName)
                        {
                            namespaces = GetNamespaces(ns);
                            break;
                        }
                    }
                }

                if (namespaces.Count == 0 && !string.IsNullOrEmpty(ns))
                {
                    foreach (MethodDef method in agenType.GetMethods())
                    {
                        if (method.ClassName == agenType.AgentTypeName)
                        {
                            namespaces = GetNamespaces(ns);
                            break;
                        }
                    }
                }

                string indent = WriteNamespacesHead(file, namespaces);

                foreach (PropertyDef property in agenType.GetProperties())
                {
                    if (property.ClassName == agenType.AgentTypeName)
                    {
                        string propName = property.Name.Replace("::", "_");
                        string nativeType = DataCppExporter.GetBasicGeneratedNativeType(property.NativeType);

                        file.WriteLine("{0}struct PROPERTY_TYPE_{1} {{ }};", indent, propName);
                        file.WriteLine("{0}template<> BEHAVIAC_FORCEINLINE {1}& {2}::_Get_Property_<PROPERTY_TYPE_{3}>()", indent, nativeType, agenType.BasicClassName, propName);
                        file.WriteLine("{0}{{", indent);
                        if (property.IsStatic)
                        {
                            file.WriteLine("{0}\tunsigned char* pc = (unsigned char*)(&{1});", indent, property.Name);
                        }
                        else
                        {
                            file.WriteLine("{0}\tunsigned char* pc = (unsigned char*)this;", indent);
                            file.WriteLine("{0}\tpc += (int)offsetof({1}, {2});", indent, property.ClassName, property.Name);
                        }
                        file.WriteLine("{0}\treturn *(reinterpret_cast<{1}*>(pc));", indent, nativeType);
                        file.WriteLine("{0}}}\r\n", indent);
                    }
                }

                foreach (MethodDef method in agenType.GetMethods())
                {
                    if (method.ClassName == agenType.AgentTypeName)
                    {
                        string paramStrDef = string.Empty;
                        string paramStr = string.Empty;
                        for (int i = 0; i < method.Params.Count; ++i)
                        {
                            string basicNativeType = DataCppExporter.GetBasicGeneratedNativeType(method.Params[i].NativeType, false);
                            string  refStr = string.Empty;
                            if (basicNativeType != "char*" && basicNativeType != "char *")
                            {
                                if (basicNativeType.EndsWith("*"))
                                {
                                    refStr = "&";

                                    basicNativeType = basicNativeType.Remove(basicNativeType.Length - 1);
                                }
                                basicNativeType = basicNativeType.Trim();
                            }

                            if (i > 0)
                            {
                                paramStrDef += ", ";
                                paramStr += ", ";
                            }

                            string refConstStr = "&";
                            if (basicNativeType.EndsWith("&"))
                            {
                                refConstStr = string.Empty;
                            }

                            paramStrDef += string.Format("{0}{1} p{2}", basicNativeType, refConstStr, i);
                            paramStr += string.Format("{0}p{1}", refStr, i);
                        }

                        string methodName = method.Name.Replace("::", "_");
                        string nativeReturnType = DataCppExporter.GetGeneratedNativeType(method.NativeReturnType);
                        file.WriteLine("{0}struct METHOD_TYPE_{1} {{ }};", indent, methodName);
                        file.WriteLine("{0}template<> BEHAVIAC_FORCEINLINE {1} {2}::_Execute_Method_<METHOD_TYPE_{3}>({4})", indent, nativeReturnType, agenType.BasicClassName, methodName, paramStrDef);
                        file.WriteLine("{0}{{", indent);

                        string ret = (method.NativeReturnType == "void") ? string.Empty : "return ";
                        file.WriteLine("{0}\t{1}this->{2}({3});", indent, ret, method.Name, paramStr);

                        file.WriteLine("{0}}}\r\n", indent);
                    }
                }

                WriteNamespacesTail(file, namespaces);
            }

            // create namespace
            file.WriteLine("namespace behaviac\r\n{");
        }

        private void ExportBody(StreamWriter file, BehaviorNode behavior)
        {
            string filename = Path.ChangeExtension(behavior.RelativePath, "").Replace(".", "");
            filename = filename.Replace('\\', '/');

            // write comments
            file.WriteLine("\t// Source file: {0}\r\n", filename);

            string btClassName = string.Format("bt_{0}", filename.Replace('/', '_'));
            string agentType = behavior.AgentType.AgentTypeName;

            // create the class definition of its attachments
            ExportAttachmentClass(file, btClassName, (Node)behavior);

            // create the class definition of its children
            foreach (Node child in ((Node)behavior).Children)
                ExportNodeClass(file, btClassName, agentType, behavior, child);

            // export the create function
            file.WriteLine("\tBEHAVIAC_API bool Create_{0}(BehaviorTree* pBT)\r\n\t{{", btClassName);

            file.WriteLine("\t\tpBT->SetClassNameString(\"BehaviorTree\");");
            file.WriteLine("\t\tpBT->SetId(-1);");
            file.WriteLine("\t\tpBT->SetName(\"{0}\");", filename);
            file.WriteLine("#if !defined(BEHAVIAC_RELEASE)");
            file.WriteLine("\t\tpBT->SetAgentType(\"{0}\");", agentType);
            file.WriteLine("#endif");
            if (!string.IsNullOrEmpty(((Behavior)behavior).Domains))
            {
                file.WriteLine("\t\tpBT->SetDomains(\"{0}\");", ((Behavior)behavior).Domains);
            }
            if (((Behavior)behavior).DescriptorRefs.Count > 0)
            {
                file.WriteLine("\t\tpBT->SetDescriptors(\"{0}\");", DesignerPropertyUtility.RetrieveExportValue(((Behavior)behavior).DescriptorRefs));
            }

            ExportPars(file, "pBT", (Node)behavior, "\t");

            // export its attachments
            ExportAttachment(file, btClassName, agentType, "pBT", (Node)behavior, "\t\t");

            file.WriteLine("\t\t// children");

            // export its children
            foreach (Node child in ((Node)behavior).Children)
                ExportNode(file, btClassName, agentType, "pBT", child, 2);

            file.WriteLine("\t\treturn true;");
            file.WriteLine("\t}\r\n");

            // export the register class and its instance
            file.WriteLine("\tstruct Register_{0}\r\n\t{{", btClassName);
            file.WriteLine("\t\tRegister_{0}()\r\n\t\t{{", btClassName);
            file.WriteLine("\t\t\tWorkspace::RegisterBehaviorTreeCreator(\"{0}\", Create_{1});", filename, btClassName);
            file.WriteLine("\t\t}\r\n\t};\r\n");

            file.WriteLine("\tstatic Register_{0} register_{0};\n", btClassName);
        }

        private void ExportTail(StreamWriter file)
        {
            // close namespace
            file.WriteLine("}");
        }

        private void ExportPars(StreamWriter file, string nodeName, Node node, string indent)
        {
            ExportPars(file, nodeName, node.Pars, indent);
        }

        private void ExportPars(StreamWriter file, string nodeName, Behaviac.Design.Attachments.Attachment attachment, string indent)
        {
            Behaviac.Design.Attachments.Event evt = attachment as Behaviac.Design.Attachments.Event;
            if (evt != null)
            {
                ExportPars(file, nodeName, evt.Pars, indent);
            }
        }

        private void ExportPars(StreamWriter file, string nodeName, List<Behaviac.Design.ParInfo> pars, string indent)
        {
            if (pars.Count > 0)
            {
                file.WriteLine("{0}\t// pars", indent);
                for (int i = 0; i < pars.Count; ++i)
                {
                    string name = pars[i].Name;
                    string type = Plugin.GetNativeTypeName(pars[i].Type);
                    string value = pars[i].DefaultValue.Replace("\"", "\\\"");
                    string eventParam = pars[i].EventParam;

                    file.WriteLine("{0}\t{1}->AddPar(\"{2}\", \"{3}\", \"{4}\", \"{5}\");", indent, nodeName, type, name, value, eventParam);
                }
            }
        }

        private void ExportAttachmentClass(StreamWriter file, string btClassName, Node node)
        {
            foreach (Behaviac.Design.Attachments.Attachment attach in node.Attachments)
            {
                string nodeName = string.Format("attach{0}", attach.Id);

                AttachmentCppExporter attachmentExporter = AttachmentCppExporter.CreateInstance(attach);
                attachmentExporter.GenerateClass(attach, file, "", nodeName, btClassName);
            }
        }

        private void ExportAttachment(StreamWriter file, string btClassName, string agentType, string parentName, Node node, string indent)
        {
            if (node.Attachments.Count > 0)
            {
                file.WriteLine("{0}// attachments", indent);
                foreach (Behaviac.Design.Attachments.Attachment attach in node.Attachments)
                {
                    file.WriteLine("{0}{{", indent);

                    string nodeName = string.Format("attach{0}", attach.Id);

                    // export its instance and the properties
                    AttachmentCppExporter attachmentExporter = AttachmentCppExporter.CreateInstance(attach);
                    attachmentExporter.GenerateInstance(attach, file, indent, nodeName, agentType, btClassName);

                    ExportPars(file, nodeName, attach, indent);

                    file.WriteLine("{0}\t{1}->Attach({2});", indent, parentName, nodeName);
                    file.WriteLine("{0}\t{1}->SetHasEvents({1}->HasEvents() | (Event::DynamicCast({2}) != 0));", indent, parentName, nodeName);
                    file.WriteLine("{0}}}", indent);
                }
            }
        }

        private void ExportNodeClass(StreamWriter file, string btClassName, string agentType, BehaviorNode behavior, Node node)
        {
            string nodeName = string.Format("node{0}", node.Id);

            NodeCppExporter nodeExporter = NodeCppExporter.CreateInstance(node);
            nodeExporter.GenerateClass(node, file, "", nodeName, agentType, btClassName);

            ExportAttachmentClass(file, btClassName, node);

            if (!(node is ReferencedBehavior))
            {
                foreach (Node child in node.Children)
                {
                    ExportNodeClass(file, btClassName, agentType, behavior, child);
                }
            }
        }

        private void ExportNode(StreamWriter file, string btClassName, string agentType, string parentName, Node node, int indentDepth)
        {
            // generate the indent string
            string indent = string.Empty;
            for (int i = 0; i < indentDepth; ++i)
                indent += '\t';

            string nodeName = string.Format("node{0}", node.Id);

            // open some brackets for a better formatting in the generated code
            file.WriteLine("{0}{{", indent);

            // export its instance and the properties
            NodeCppExporter nodeExporter = NodeCppExporter.CreateInstance(node);
            nodeExporter.GenerateInstance(node, file, indent, nodeName, agentType, btClassName);

            ExportPars(file, nodeName, node, indent);

            ExportAttachment(file, btClassName, agentType, nodeName, node, indent + "\t");

            // add the node to its parent
            file.WriteLine("{0}\t{1}->AddChild({2});", indent, parentName, nodeName);

            // export the child nodes
            if (!(node is ReferencedBehavior))
            {
                foreach (Node child in node.Children)
                {
                    ExportNode(file, btClassName, agentType, nodeName, child, indentDepth + 1);
                }
            }

            file.WriteLine("{0}\t{1}->SetHasEvents({1}->HasEvents() | {2}->HasEvents());", indent, parentName, nodeName);

            // close the brackets for a better formatting in the generated code
            file.WriteLine("{0}}}", indent);
        }
    }
}
