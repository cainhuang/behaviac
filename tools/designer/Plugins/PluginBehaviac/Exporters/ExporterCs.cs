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
using Behaviac.Design.Attributes;
using Behaviac.Design.Attachments;
using PluginBehaviac.Properties;
using PluginBehaviac.DataExporters;
using PluginBehaviac.NodeExporters;

namespace PluginBehaviac.Exporters
{
    public class ExporterCs : Behaviac.Design.Exporters.Exporter
    {
        public ExporterCs(BehaviorNode node, string outputFolder, string filename, List<string> includedFilenames = null)
            : base(node, outputFolder, filename + ".cs", includedFilenames)
        {
            _outputFolder = Path.Combine(Path.GetFullPath(_outputFolder), "behaviac_generated");
        }

        public override Behaviac.Design.FileManagers.SaveResult Export(List<BehaviorNode> behaviors, bool exportBehaviors, int exportFileCount)
        {
            string behaviorFilename = "behaviors/generated_behaviors.cs";
            string agentFolder = string.Empty;
            Behaviac.Design.FileManagers.SaveResult result = VerifyFilename(exportBehaviors, ref behaviorFilename, ref agentFolder);
            if (Behaviac.Design.FileManagers.SaveResult.Succeeded == result)
            {
                if (exportBehaviors)
                {
                    string behaviorFolder = Path.GetDirectoryName(behaviorFilename);
                    clearFolder(behaviorFolder);
                    //clearFolder(agentFolder);

                    ExportBehaviors(behaviors, behaviorFilename, exportFileCount);
                }

                ExportMembers(agentFolder);

                ExportAgents(agentFolder);

                ExportCustomizedTypes(agentFolder);
            }

            return result;
        }

        private void clearFolder(string folder)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(folder);
            if (dirInfo.Exists)
            {
                foreach (FileInfo file in dirInfo.GetFiles())
                {
                    try
                    {
                        File.SetAttributes(file.FullName, FileAttributes.Normal);
                        if (file.Extension == ".cs")
                            file.Delete();
                    }
                    catch
                    {
                    }
                }
            }
        }

        private void ExportBehaviors(List<BehaviorNode> behaviors, string filename, int exportFileCount)
        {
            using (StreamWriter file = new StreamWriter(filename))
            {
                ExportHead(file, filename);

                if (exportFileCount == 1)
                {
                    foreach (BehaviorNode behavior in behaviors)
                    {
                        ExportBody(file, behavior);
                    }
                }
                else
                {
                    foreach (BehaviorNode behavior in behaviors)
                    {
                        string behaviorFilename = behavior.RelativePath;
                        behaviorFilename = behaviorFilename.Replace("\\", "/");
                        behaviorFilename = Path.ChangeExtension(behaviorFilename, "cs");
                        behaviorFilename = Path.Combine("behaviors", behaviorFilename);

                        string agentFolder = string.Empty;

                        Behaviac.Design.FileManagers.SaveResult result = VerifyFilename(true, ref behaviorFilename, ref agentFolder);
                        if (Behaviac.Design.FileManagers.SaveResult.Succeeded == result)
                        {
                            using (StreamWriter behaviorFile = new StreamWriter(behaviorFilename))
                            {
                                ExportHead(behaviorFile, behaviorFilename);

                                ExportBody(behaviorFile, behavior);

                                ExportTail(behaviorFile);

                                behaviorFile.Close();
                            }
                        }
                    }
                }

                ExportTail(file);

                file.Close();
            }
        }

        private Behaviac.Design.FileManagers.SaveResult VerifyFilename(bool exportBehaviors, ref string behaviorFilename, ref string agentFolder)
        {
            behaviorFilename = Path.Combine(_outputFolder, behaviorFilename);
            agentFolder = Path.Combine(_outputFolder, "types");

            // get the abolute folder of the file we want to export
            string folder = Path.GetDirectoryName(behaviorFilename);
            if (!Directory.Exists(folder))
                Directory.CreateDirectory(folder);

            if (!Directory.Exists(agentFolder))
                Directory.CreateDirectory(agentFolder);

            if (exportBehaviors)
            {
                // verify it can be writable
                return Behaviac.Design.FileManagers.FileManager.MakeWritable(behaviorFilename, Resources.ExportFileWarning);
            }

            return Behaviac.Design.FileManagers.SaveResult.Succeeded;
        }

        private void ExportHead(StreamWriter file, string exportFilename)
        {
            string wsfolder = Path.GetDirectoryName(Workspace.Current.FileName);
            exportFilename = Behaviac.Design.FileManagers.FileManager.MakeRelative(wsfolder, exportFilename);
            exportFilename = exportFilename.Replace("\\", "/");

            // write comments
            file.WriteLine("// ---------------------------------------------------------------------");
            file.WriteLine("// This file is auto-generated by behaviac designer, so please don't modify it by yourself!");
            file.WriteLine("// Export file: {0}", exportFilename);
            file.WriteLine("// ---------------------------------------------------------------------\r\n");

            // write the namespaces for the game agents
            file.WriteLine("using System;");
            file.WriteLine("using System.Collections;");
            file.WriteLine("using System.Collections.Generic;");
            file.WriteLine("using System.Reflection;\r\n");

            // write namespace
            file.WriteLine("namespace behaviac\r\n{");
        }

        private string getValidFilename(string filename)
        {
            filename = filename.Replace('/', '_');
            filename = filename.Replace('-', '_');

            return filename;
        }

        private void ExportBody(StreamWriter file, BehaviorNode behavior)
        {
            behavior.PreExport();

            string filename = Path.ChangeExtension(behavior.RelativePath, "").Replace(".", "");
            filename = filename.Replace('\\', '/');

            // write comments
            file.WriteLine("\t// Source file: {0}\r\n", filename);

            string btClassName = string.Format("bt_{0}", getValidFilename(filename));
            string agentType = behavior.AgentType.AgentTypeName;

            // create the class definition of its attachments
            ExportAttachmentClass(file, btClassName, (Node)behavior);

            // create the class definition of its children
            foreach (Node child in ((Node)behavior).GetChildNodes())
                ExportNodeClass(file, btClassName, agentType, behavior, child);

            // create the bt class
            file.WriteLine("\tpublic static class {0}\r\n\t{{", btClassName);

            // export the build function
            file.WriteLine("\t\tpublic static bool build_behavior_tree(BehaviorTree bt)\r\n\t\t{");
            file.WriteLine("\t\t\tbt.SetClassNameString(\"BehaviorTree\");");
            file.WriteLine("\t\t\tbt.SetId(-1);");
            file.WriteLine("\t\t\tbt.SetName(\"{0}\");", filename);
            file.WriteLine("\t\t\tbt.IsFSM = {0};", ((Node)behavior).IsFSM ? "true" : "false");
            file.WriteLine("#if !BEHAVIAC_RELEASE");
            file.WriteLine("\t\t\tbt.SetAgentType(\"{0}\");", agentType.Replace("::", "."));
            file.WriteLine("#endif");
            if (!string.IsNullOrEmpty(((Behavior)behavior).Domains))
            {
                file.WriteLine("\t\t\tbt.SetDomains(\"{0}\");", ((Behavior)behavior).Domains);
            }
            if (((Behavior)behavior).DescriptorRefs.Count > 0)
            {
                file.WriteLine("\t\t\tbt.SetDescriptors(\"{0}\");", DesignerPropertyUtility.RetrieveExportValue(((Behavior)behavior).DescriptorRefs));
            }

            ExportPars(file, agentType, "bt", (Node)behavior, "\t\t");

            // export its attachments
            ExportAttachment(file, btClassName, agentType, "bt", (Node)behavior, "\t\t\t");

            file.WriteLine("\t\t\t// children");

            // export its children
            if (((Node)behavior).IsFSM)
            {
                file.WriteLine("\t\t\t{");
                file.WriteLine("\t\t\t\tFSM fsm = new FSM();");
                file.WriteLine("\t\t\t\tfsm.SetClassNameString(\"FSM\");");
                file.WriteLine("\t\t\t\tfsm.SetId(-1);");
                file.WriteLine("\t\t\t\tfsm.InitialId = {0};", behavior.InitialStateId);
                file.WriteLine("#if !BEHAVIAC_RELEASE");
                file.WriteLine("\t\t\t\tfsm.SetAgentType(\"{0}\");", agentType.Replace("::", "."));
                file.WriteLine("#endif");

                foreach (Node child in ((Node)behavior).FSMNodes)
                {
                    ExportNode(file, btClassName, agentType, "fsm", child, 4);
                }

                file.WriteLine("\t\t\t\tbt.AddChild(fsm);");
                file.WriteLine("\t\t\t}");
            }
            else
            {
                foreach (Node child in ((Node)behavior).GetChildNodes())
                {
                    ExportNode(file, btClassName, agentType, "bt", child, 3);
                }
            }

            file.WriteLine("\t\t\treturn true;");

            // close the build function
            file.WriteLine("\t\t}");

            // close class
            file.WriteLine("\t}\r\n");

            behavior.PostExport();
        }

        private void ExportTail(StreamWriter file)
        {
            // close namespace
            file.WriteLine("}");
        }

        private void ExportPars(StreamWriter file, string agentType, string nodeName, Node node, string indent)
        {
            if (node is Behavior)
            {
                ExportPars(file, agentType, nodeName, ((Behavior)node).LocalVars, indent);
            }
        }

        private void ExportPars(StreamWriter file, string agentType, string nodeName, List<Behaviac.Design.ParInfo> pars, string indent)
        {
            if (pars.Count > 0)
            {
                file.WriteLine("{0}\t// pars", indent);
                for (int i = 0; i < pars.Count; ++i)
                {
                    string name = pars[i].BasicName;
                    string type = DataCsExporter.GetGeneratedParType(pars[i].Type);
                    string value = pars[i].DefaultValue.Replace("\"", "\\\"");

                    file.WriteLine("{0}\t{1}.AddPar(\"{2}\", \"{3}\", \"{4}\", \"{5}\");", indent, nodeName, agentType, type, name, value);
                }
            }
        }

        private void ExportAttachmentClass(StreamWriter file, string btClassName, Node node)
        {
            foreach (Behaviac.Design.Attachments.Attachment attach in node.Attachments)
            {
                if (!attach.Enable)
                    continue;

                string nodeName = string.Format("attach{0}", attach.Id);

                AttachmentCsExporter attachmentExporter = AttachmentCsExporter.CreateInstance(attach);
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
                    if (!attach.Enable || attach.IsStartCondition)
                        continue;

                    file.WriteLine("{0}{{", indent);

                    string nodeName = string.Format("attach{0}", attach.Id);

                    // export its instance and the properties
                    AttachmentCsExporter attachmentExporter = AttachmentCsExporter.CreateInstance(attach);
                    attachmentExporter.GenerateInstance(attach, file, indent, nodeName, agentType, btClassName);

                    string isPrecondition = attach.IsPrecondition && !attach.IsTransition ? "true" : "false";
                    string isEffector = attach.IsEffector && !attach.IsTransition ? "true" : "false";
                    string isTransition = attach.IsTransition ? "true" : "false";
                    file.WriteLine("{0}\t{1}.Attach({2}, {3}, {4}, {5});", indent, parentName, nodeName, isPrecondition, isEffector, isTransition);

                    if (attach is Behaviac.Design.Attachments.Event)
                    {
                        file.WriteLine("{0}\t{1}.SetHasEvents({1}.HasEvents() | ({2} is Event));", indent, parentName, nodeName);
                    }

                    file.WriteLine("{0}}}", indent);
                }
            }
        }

        private void ExportNodeClass(StreamWriter file, string btClassName, string agentType, BehaviorNode behavior, Node node)
        {
            if (!node.Enable)
                return;

            string nodeName = string.Format("node{0}", node.Id);

            NodeCsExporter nodeExporter = NodeCsExporter.CreateInstance(node);
            nodeExporter.GenerateClass(node, file, "", nodeName, agentType, btClassName);

            ExportAttachmentClass(file, btClassName, node);

            if (!(node is ReferencedBehavior))
            {
                foreach (Node child in node.GetChildNodes())
                {
                    ExportNodeClass(file, btClassName, agentType, behavior, child);
                }
            }
        }

        private void ExportNode(StreamWriter file, string btClassName, string agentType, string parentName, Node node, int indentDepth)
        {
            if (!node.Enable)
                return;

            // generate the indent string
            string indent = string.Empty;
            for (int i = 0; i < indentDepth; ++i)
            {
                indent += '\t';
            }

            string nodeName = string.Format("node{0}", node.Id);

            // open some brackets for a better formatting in the generated code
            file.WriteLine("{0}{{", indent);

            // export its instance and the properties
            NodeCsExporter nodeExporter = NodeCsExporter.CreateInstance(node);
            nodeExporter.GenerateInstance(node, file, indent, nodeName, agentType, btClassName);

            ExportPars(file, agentType, nodeName, node, indent);

            ExportAttachment(file, btClassName, agentType, nodeName, node, indent + "\t");

            bool isAsChild = true;
            if (node.Parent != null)
            {
                BaseNode.Connector connector = node.Parent.GetConnector(node);
                if (connector != null && !connector.IsAsChild)
                {
                    isAsChild = false;
                }
            }

            if (isAsChild)
            {
                // add the node to its parent
                file.WriteLine("{0}\t{1}.AddChild({2});", indent, parentName, nodeName);
            }
            else
            {
                // add the node as its customized children
                file.WriteLine("{0}\t{1}.SetCustomCondition({2});", indent, parentName, nodeName);
            }

            // export the child nodes
            if (!node.IsFSM && !(node is ReferencedBehavior))
            {
                foreach (Node child in node.GetChildNodes())
                {
                    ExportNode(file, btClassName, agentType, nodeName, child, indentDepth + 1);
                }
            }

            file.WriteLine("{0}\t{1}.SetHasEvents({1}.HasEvents() | {2}.HasEvents());", indent, parentName, nodeName);

            // close the brackets for a better formatting in the generated code
            file.WriteLine("{0}}}", indent);
        }

        private void ExportAgents(string agentFolder)
        {
            foreach (AgentType agent in Plugin.AgentTypes)
            {
                if (!agent.IsCustomized)
                    continue;

                IList<PropertyDef> properties = agent.GetProperties();
                bool hasCustomizedProperty = false;
                foreach (PropertyDef prop in properties)
                {
                    if (prop.IsCustomized && !prop.IsPar && !prop.IsArrayElement)
                    {
                        hasCustomizedProperty = true;
                        break;
                    }
                }

                IList<MethodDef> methods = agent.GetMethods();
                bool hasCustomizedMethod = false;
                foreach (MethodDef method in methods)
                {
                    if (method.IsCustomized && !method.IsNamedEvent)
                    {
                        hasCustomizedMethod = true;
                        break;
                    }
                }

                //if (hasCustomizedProperty || hasCustomizedMethod)
                {
                    string filename = Path.Combine(agentFolder, agent.BasicClassName + ".cs");
                    Encoding utf8WithBom = new UTF8Encoding(true);

                    using (StreamWriter file = new StreamWriter(filename, false, utf8WithBom))
                    {
                        // write comments
                        file.WriteLine("// ---------------------------------------------------------------------");
                        file.WriteLine("// This agent file is auto-generated by behaviac designer, but you should");
                        file.WriteLine("// implement the methods of the agent class if necessary!");
                        file.WriteLine("// ---------------------------------------------------------------------\r\n");

                        file.WriteLine("using System.Collections.Generic;");
                        file.WriteLine();

                        string indent = "";
                        if (!string.IsNullOrEmpty(agent.Namespace))
                        {
                            indent = "\t";

                            file.WriteLine("namespace {0}", agent.Namespace);
                            file.WriteLine("{");
                        }

                        string agentDisplayName = string.IsNullOrEmpty(agent.DisplayName) ? agent.BasicClassName : agent.DisplayName;
                        string agentDescription = string.IsNullOrEmpty(agent.Description) ? "" : agent.Description;
                        file.WriteLine("{0}[behaviac.TypeMetaInfo(\"{1}\", \"{2}\")]", indent, agentDisplayName, agentDescription);
                        file.WriteLine("{0}public class {1} : {2}", indent, agent.BasicClassName, agent.Base.AgentTypeName.Replace("::", "."));
                        file.WriteLine("{0}{{", indent);

                        if (hasCustomizedProperty)
                        {
                            file.WriteLine("{0}\t// properties", indent);
                            file.WriteLine();

                            foreach (PropertyDef prop in properties)
                            {
                                if (prop.IsCustomized && !prop.IsPar && !prop.IsArrayElement)
                                {
                                    string publicStr = prop.IsPublic ? "public " : "private ";
                                    string staticStr = prop.IsStatic ? "static " : "";
                                    string propType = DataCsExporter.GetGeneratedNativeType(prop.Type);
                                    string defaultValue = DataCsExporter.GetGeneratedPropertyDefaultValue(prop, propType);
                                    if (defaultValue != null)
                                        defaultValue = " = " + defaultValue;

                                    file.WriteLine("{0}\t[behaviac.MemberMetaInfo(\"{1}\", \"{2}\")]", indent, prop.DisplayName, prop.BasicDescription);
                                    file.WriteLine("{0}\t{1}{2}{3} {4}{5};", indent, publicStr, staticStr, propType, prop.BasicName, defaultValue);
                                    file.WriteLine();
                                }
                            }
                        }

                        if (hasCustomizedMethod)
                        {
                            file.WriteLine("{0}\t// methods", indent);
                            file.WriteLine();

                            foreach (MethodDef method in methods)
                            {
                                if (method.IsCustomized && !method.IsNamedEvent)
                                {
                                    string publicStr = method.IsPublic ? "public " : "private ";
                                    string staticStr = method.IsStatic ? "static " : "";

                                    string allParams = "";
                                    foreach (MethodDef.Param param in method.Params)
                                    {
                                        if (!string.IsNullOrEmpty(allParams))
                                        {
                                            allParams += ", ";
                                        }

                                        string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);
                                        if (param.IsRef)
                                        {
                                            paramType = "ref " + paramType;
                                        }

                                        allParams += paramType + " " + param.Name;
                                    }

                                    string returnType = DataCsExporter.GetGeneratedNativeType(method.ReturnType);
                                    string returnValue = DataCsExporter.GetGeneratedDefaultValue(method.ReturnType, returnType);

                                    file.WriteLine("{0}\t[behaviac.MethodMetaInfo(\"{1}\", \"{2}\")]", indent, method.DisplayName, method.BasicDescription);
                                    file.WriteLine("{0}\t{1}{2}{3} {4}({5})", indent, publicStr, staticStr, returnType, method.BasicName, allParams);
                                    file.WriteLine("{0}\t{{", indent);
                                    file.WriteLine("{0}\t\t// Write your logic codes here.", indent);
                                    if (returnValue != null)
                                    {
                                        file.WriteLine();
                                        file.WriteLine("{0}\t\treturn {1};", indent, returnValue);
                                    }
                                    file.WriteLine("{0}\t}}", indent);
                                    file.WriteLine();
                                }
                            }
                        }

                        //end of class
                        file.WriteLine("{0}}}", indent);

                        if (!string.IsNullOrEmpty(agent.Namespace))
                        {
                            //end of namespace
                            file.WriteLine("}");
                        }

                        file.Close();
                    }
                }
            }
        }

        private void ExportCustomizedTypes(string agentFolder)
        {
            if (CustomizedTypeManager.Instance.Enums.Count > 0 || CustomizedTypeManager.Instance.Structs.Count > 0)
            {
                string filename = Path.Combine(agentFolder, "customizedtypes.cs");
                Encoding utf8WithBom = new UTF8Encoding(true);

                using (StreamWriter file = new StreamWriter(filename, false, utf8WithBom))
                {
                    // write comments
                    file.WriteLine("// ---------------------------------------------------------------------");
                    file.WriteLine("// This file is auto-generated by behaviac designer, so please don't modify it by yourself!");
                    file.WriteLine("// ---------------------------------------------------------------------\n");

                    file.WriteLine("using System.Collections;");
                    file.WriteLine("using System.Collections.Generic;");
                    file.WriteLine();

                    //file.WriteLine("namespace behaviac");
                    //file.WriteLine("{");

                    file.WriteLine("// -------------------");
                    file.WriteLine("// Customized enums");
                    file.WriteLine("// -------------------\n");

                    for (int e = 0; e < CustomizedTypeManager.Instance.Enums.Count; ++e)
                    {
                        if (e > 0)
                            file.WriteLine();

                        CustomizedEnum customizedEnum = CustomizedTypeManager.Instance.Enums[e];
                        file.WriteLine("[behaviac.TypeMetaInfo(\"{0}\", \"{1}\")]", customizedEnum.DisplayName, customizedEnum.Description);

                        file.WriteLine("public enum {0}", customizedEnum.Name);
                        file.WriteLine("{");

                        for (int m = 0; m < customizedEnum.Members.Count; ++m)
                        {
                            if (m > 0)
                                file.WriteLine();

                            CustomizedEnum.CustomizedEnumMember member = customizedEnum.Members[m];
                            if (member.DisplayName != member.Name || !string.IsNullOrEmpty(member.Description))
                                file.WriteLine("\t[behaviac.MemberMetaInfo(\"{0}\", \"{1}\")]", member.DisplayName, member.Description);

                            if (member.Value >= 0)
                                file.WriteLine("\t{0} = {1},", member.Name, member.Value);
                            else
                                file.WriteLine("\t{0},", member.Name);
                        }

                        file.WriteLine("}");
                    }

                    if (CustomizedTypeManager.Instance.Enums.Count > 0)
                        file.WriteLine();

                    file.WriteLine("// -------------------");
                    file.WriteLine("// Customized structs");
                    file.WriteLine("// -------------------\n");

                    for (int s = 0; s < CustomizedTypeManager.Instance.Structs.Count; s++)
                    {
                        if (s > 0)
                            file.WriteLine();

                        CustomizedStruct customizedStruct = CustomizedTypeManager.Instance.Structs[s];
                        file.WriteLine("[behaviac.TypeMetaInfo(\"{0}\", \"{1}\")]", customizedStruct.DisplayName, customizedStruct.Description);

                        file.WriteLine("public struct {0}", customizedStruct.Name);
                        file.WriteLine("{");

                        for (int m = 0; m < customizedStruct.Properties.Count; ++m)
                        {
                            if (m > 0)
                                file.WriteLine();

                            PropertyDef member = customizedStruct.Properties[m];
                            if (member.DisplayName != member.Name || !string.IsNullOrEmpty(member.BasicDescription))
                                file.WriteLine("\t[behaviac.MemberMetaInfo(\"{0}\", \"{1}\")]", member.DisplayName, member.BasicDescription);

                            file.WriteLine("\tpublic {0} {1};", DataCsExporter.GetGeneratedNativeType(member.NativeType), member.BasicName);
                        }

                        file.WriteLine("}");
                    }

                    //file.WriteLine("}");
                }
            }
        }

        private void ExportMembers(string agentFolder)
        {
            string filename = Path.Combine(agentFolder, "AgentProperties.cs");
            Encoding utf8WithBom = new UTF8Encoding(true);

            using (StreamWriter file = new StreamWriter(filename, false, utf8WithBom))
            {
                // write comments
                file.WriteLine("// ---------------------------------------------------------------------");
                file.WriteLine("// This file is auto-generated by behaviac designer, so please don't modify it by yourself!");
                file.WriteLine("// ---------------------------------------------------------------------\n");

                file.WriteLine("using System.Collections.Generic;");
                file.WriteLine();

                file.WriteLine("namespace behaviac");
                file.WriteLine("{");

                // AgentMeta
                file.WriteLine("\tpartial class AgentMeta");
                file.WriteLine("\t{");

                PreExportMeta(file);

                file.WriteLine();

                // registerMeta
                file.WriteLine("\t\tstatic partial void registerMeta()");
                file.WriteLine("\t\t{");

                ExportMeta(file);

                file.WriteLine();

                Plugin.AllMetaTypes.Sort();

                foreach (string type in Plugin.AllMetaTypes)
                {
                    AgentType agentType = Plugin.GetAgentType(type);
                    bool isStatic = (agentType != null) ? agentType.IsStatic : false;

                    if (!isStatic)
                    {
                        file.WriteLine("\t\t\tAgentMeta.Register<{0}>(\"{0}\");", type.Replace("::", "."));
                    }
                }

                file.WriteLine();

                //foreach (string type in Plugin.AllMetaTypes)
                //{
                //    AgentType agentType = Plugin.GetAgentType(type);
                //    if (agentType != null)
                //    {
                //        file.WriteLine("\t\t\tWorkspace.Instance.AddAgentType(typeof({0}), {1});", type.Replace("::", "."), agentType.IsInherited ? "true" : "false");
                //    }
                //}

                file.WriteLine("\t\t}");
                file.WriteLine();

                // unRegisterMeta
                file.WriteLine("\t\tstatic partial void unRegisterMeta()");
                file.WriteLine("\t\t{");

                foreach (string type in Plugin.AllMetaTypes)
                {
                    AgentType agentType = Plugin.GetAgentType(type);
                    bool isStatic = (agentType != null) ? agentType.IsStatic : false;

                    if (!isStatic)
                    {
                        file.WriteLine("\t\t\tAgentMeta.UnRegister<{0}>(\"{0}\");", type.Replace("::", "."));
                    }
                }

                file.WriteLine("\t\t}");
                file.WriteLine("\t}");
                file.WriteLine("}");
            }
        }

        private void PreExportMeta(StreamWriter file)
        {
            Dictionary<string, bool> allMethods = new Dictionary<string, bool>();

            foreach (AgentType agent in Plugin.AgentTypes)
            {
                if (agent.IsCustomized)
                    continue;

                string agentTypeName = agent.AgentTypeName.Replace("::", ".");

                IList<MethodDef> methods = agent.GetMethods();
                foreach (MethodDef method in methods)
                {
                    if (!method.IsCustomized && !method.IsNamedEvent)
                    {
                        bool hasRefParam = false;

                        foreach (MethodDef.Param param in method.Params)
                        {
                            if (param.IsRef || param.IsOut || Plugin.IsRefType(param.Type))
                            {
                                hasRefParam = true;
                                break;
                            }
                        }

                        if (hasRefParam)
                        {
                            string methodFullname = method.Name.Replace("::", "_");

                            if (allMethods.ContainsKey(methodFullname))
                            {
                                continue;
                            }
                            else
                            {
                                allMethods[methodFullname] = true;
                            }

                            string methodReturnType = DataCsExporter.GetGeneratedNativeType(method.NativeReturnType);
                            string baseClass = (methodReturnType == "void") ? "CAgentMethodVoidBase" : string.Format("CAgentMethodBase<{0}>", methodReturnType);

                            // class
                            file.WriteLine("\t\tprivate class CMethod_{0} : {1}", methodFullname, baseClass);
                            file.WriteLine("\t\t{");

                            foreach (MethodDef.Param param in method.Params)
                            {
                                if (Plugin.IsRefType(param.Type))
                                {
                                    file.WriteLine("\t\t\tIInstanceMember _{0};", param.Name);
                                }
                                else
                                {
                                    string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);
                                    file.WriteLine("\t\t\tCInstanceMember<{0}> _{1};", paramType, param.Name);
                                }
                            }

                            if (method.Params.Count > 0)
                            {
                                file.WriteLine();
                            }

                            // Constructors
                            file.WriteLine("\t\t\tpublic CMethod_{0}()", methodFullname);
                            file.WriteLine("\t\t\t{");
                            file.WriteLine("\t\t\t}");
                            file.WriteLine();

                            file.WriteLine("\t\t\tpublic CMethod_{0}(CMethod_{0} rhs) : base(rhs)", methodFullname);
                            file.WriteLine("\t\t\t{");
                            file.WriteLine("\t\t\t}");
                            file.WriteLine();

                            // Clone()
                            file.WriteLine("\t\t\tpublic override IMethod Clone()");
                            file.WriteLine("\t\t\t{");
                            file.WriteLine("\t\t\t\treturn new CMethod_{0}(this);", methodFullname);
                            file.WriteLine("\t\t\t}"); // Clone()
                            file.WriteLine();

                            // Load()
                            file.WriteLine("\t\t\tpublic override void Load(string instance, string[] paramStrs)");
                            file.WriteLine("\t\t\t{");

                            file.WriteLine("\t\t\t\tDebug.Check(paramStrs.Length == {0});", method.Params.Count);
                            file.WriteLine();
                            file.WriteLine("\t\t\t\t_instance = instance;");

                            for (int i = 0; i < method.Params.Count; ++i)
                            {
                                MethodDef.Param param = method.Params[i];
                                string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);

                                if (Plugin.IsRefType(param.Type))
                                {
                                    file.WriteLine("\t\t\t\t_{0} = AgentMeta.ParseProperty<{1}>(paramStrs[{2}]);", param.Name, paramType, i);
                                }
                                else
                                {
                                    file.WriteLine("\t\t\t\t_{0} = (CInstanceMember<{1}>)AgentMeta.ParseProperty<{1}>(paramStrs[{2}]);", param.Name, paramType, i);
                                }
                            }

                            file.WriteLine("\t\t\t}"); // Load()
                            file.WriteLine();

                            // Run()
                            file.WriteLine("\t\t\tpublic override void Run(Agent self)");
                            file.WriteLine("\t\t\t{");

                            if (method.Params.Count > 0)
                            {
                                foreach (MethodDef.Param param in method.Params)
                                {
                                    file.WriteLine("\t\t\t\tDebug.Check(_{0} != null);", param.Name);
                                }

                                file.WriteLine();
                            }

                            if (!method.IsStatic)
                            {
                                file.WriteLine("\t\t\t\tAgent agent = Utils.GetParentAgent(self, _instance);");
                                file.WriteLine();
                            }

                            string paramValues = "";
                            foreach (MethodDef.Param param in method.Params)
                            {
                                if (!string.IsNullOrEmpty(paramValues))
                                {
                                    paramValues += ", ";
                                }

                                string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);
                                string paramName = string.Format("((CInstanceMember<{0}>)_{1}).GetValue(self)", paramType, param.Name);
                                if (Plugin.IsRefType(param.Type))
                                {
                                    paramName = string.Format("({0})_{1}.GetValueObject(self)", paramType, param.Name);
                                }

                                if (param.IsRef || param.IsOut)
                                {
                                    file.WriteLine("\t\t\t\t{0} {1} = {2};", paramType, param.Name, paramName);

                                    if (method.IsPublic)
                                    {
                                        paramValues += param.IsRef ? "ref " : "out ";
                                    }

                                    paramValues += param.Name;
                                }
                                else
                                {
                                    paramValues += paramName;
                                }
                            }

                            string instanceName = method.IsStatic ? agentTypeName : string.Format("(({0})agent)", agentTypeName);

                            if (methodReturnType == "void")
                            {
                                if (method.IsPublic)
                                {
                                    file.WriteLine("\t\t\t\t{0}.{1}({2});", instanceName, method.BasicName, paramValues);
                                }
                                else
                                {
                                    file.WriteLine("\t\t\t\tobject[] paramArray = new object[] {{ {0} }};", paramValues);
                                    file.WriteLine("\t\t\t\tAgentMetaVisitor.ExecuteMethod({0}, \"{1}\", paramArray);", instanceName, method.BasicName);
                                }
                            }
                            else
                            {
                                if (method.IsPublic)
                                {
                                    file.WriteLine("\t\t\t\t_returnValue.value = {0}.{1}({2});", instanceName, method.BasicName, paramValues);
                                }
                                else
                                {
                                    file.WriteLine("\t\t\t\tobject[] paramArray = new object[] {{ {0} }};", paramValues);
                                    file.WriteLine("\t\t\t\t_returnValue.value = ({0})AgentMetaVisitor.ExecuteMethod({1}, \"{2}\", paramArray);", methodReturnType, instanceName, method.BasicName);
                                }
                            }

                            for (int i = 0; i < method.Params.Count; ++i)
                            {
                                MethodDef.Param param = method.Params[i];
                                if (param.IsRef || param.IsOut)
                                {
                                    if (method.IsPublic)
                                    {
                                        file.WriteLine("\t\t\t\t_{0}.SetValue(self, {0});", param.Name);
                                    }
                                    else
                                    {
                                        string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);
                                        file.WriteLine("\t\t\t\t_{0}.SetValue(self, ({1})paramArray[{2}]);", param.Name, paramType, i);
                                    }
                                }
                            }

                            file.WriteLine("\t\t\t}"); // Run()

                            if (method.Params.Count == 1 && methodReturnType == "behaviac.EBTStatus")
                            {
                                // GetIValue()
                                string paramType = DataCsExporter.GetGeneratedNativeType(method.Params[0].NativeType);

                                file.WriteLine();
                                file.WriteLine("\t\t\tpublic override IValue GetIValue(Agent self, IInstanceMember firstParam)");
                                file.WriteLine("\t\t\t{");
                                file.WriteLine("\t\t\t\tAgent agent = Utils.GetParentAgent(self, _instance);");
                                file.WriteLine("\t\t\t\t{0} result = ((CInstanceMember<{0}>)firstParam).GetValue(self);", paramType);

                                if (method.IsPublic)
                                {
                                    file.WriteLine("\t\t\t\t_returnValue.value = {0}.{1}(result);", instanceName, method.BasicName);
                                }
                                else
                                {
                                    file.WriteLine("\t\t\t\tobject[] paramArray = new object[] {{ result }};");
                                    file.WriteLine("\t\t\t\t_returnValue.value = ({0})AgentMetaVisitor.ExecuteMethod({1}, \"{2}\", paramArray);", methodReturnType, instanceName, method.BasicName);
                                }

                                file.WriteLine("\t\t\t\treturn _returnValue;");
                                file.WriteLine("\t\t\t}");
                            }

                            file.WriteLine("\t\t}"); // class
                            file.WriteLine();
                        }
                    }
                }
            }
        }

        private void ExportMeta(StreamWriter file)
        {
            file.WriteLine("\t\t\t// ---------------------------------------------------------------------");
            file.WriteLine("\t\t\t// properties");
            file.WriteLine("\t\t\t// ---------------------------------------------------------------------\n");

            file.WriteLine("\t\t\tAgentMeta meta;");

            foreach (AgentType agent in Plugin.AgentTypes)
            {
                if (agent.IsCustomized)
                    continue;

                string agentTypeName = agent.AgentTypeName.Replace("::", ".");
                file.WriteLine("\n\t\t\t// {0}", agentTypeName);
                file.WriteLine("\t\t\tmeta = new AgentMeta();");
                file.WriteLine("\t\t\t_agentMetas[{0}] = meta;", CRC32.CalcCRC(agentTypeName));

                IList<PropertyDef> properties = agent.GetProperties();
                foreach (PropertyDef prop in properties)
                {
                    if (!prop.IsPar)
                    {
                        string bindingProperty = "";
                        string registerName = "RegisterMemberProperty";
                        string propType = DataCsExporter.GetGeneratedNativeType(prop.NativeItemType);
                        string propItemName = prop.BasicName;
                        if (prop.IsArrayElement)
                        {
                            propItemName = propItemName.Replace("[]", "[index]");
                        }

                        if (agent.IsStatic || prop.IsMember && prop.IsStatic)
                        {
                            if (prop.IsMember)
                            {
                                string setValue = "";
                                if (!prop.IsReadonly)
                                {
                                    setValue = string.Format("{0}.{1} = value;", agentTypeName, propItemName);
                                }

                                if (prop.IsArrayElement)
                                {
                                    bindingProperty = string.Format("new CStaticMemberArrayItemProperty<{0}>(\"{1}\", delegate({0} value, int index) {{ {2} }}, delegate(int index) {{ return {3}.{4}; }})",
                                        propType, prop.BasicName, setValue, agentTypeName, propItemName);
                                }
                                else
                                {
                                    bindingProperty = string.Format("new CStaticMemberProperty<{0}>(\"{1}\", delegate({0} value) {{ {2} }}, delegate() {{ return {3}.{1}; }})",
                                        propType, prop.BasicName, setValue, agentTypeName);
                                }
                            }
                            else
                            {
                                Debug.Check(false);
                            }
                        }
                        else
                        {
                            if (prop.IsMember)
                            {
                                if (!prop.IsStatic)
                                {
                                    string setValue = "";
                                    if (!prop.IsReadonly)
                                    {
                                        setValue = string.Format("(({0})self).{1} = value;", agentTypeName, propItemName);
                                    }

                                    if (prop.IsArrayElement)
                                    {
                                        bindingProperty = string.Format("new CMemberArrayItemProperty<{0}>(\"{1}\", delegate(Agent self, {0} value, int index) {{ {2} }}, delegate(Agent self, int index) {{ return (({3})self).{4}; }})",
                                            propType, prop.BasicName, setValue, agentTypeName, propItemName);
                                    }
                                    else
                                    {
                                        bindingProperty = string.Format("new CMemberProperty<{0}>(\"{1}\", delegate(Agent self, {0} value) {{ {2} }}, delegate(Agent self) {{ return (({3})self).{1}; }})",
                                            propType, prop.BasicName, setValue, agentTypeName);
                                    }
                                }
                            }
                            else
                            {
                                registerName = prop.IsStatic ? "RegisterStaticCustomizedProperty" : "RegisterCustomizedProperty";

                                if (prop.IsArrayElement)
                                {
                                    string propName = prop.BasicName.Replace("[]", "");
                                    bindingProperty = string.Format("new CCustomizedArrayItemProperty<{0}>({1}, \"{2}\")",
                                        propType, CRC32.CalcCRC(propName), propName);
                                }
                                else
                                {
                                    bindingProperty = string.Format("new CCustomizedProperty<{0}>({1}, \"{2}\", \"{3}\")",
                                        propType, CRC32.CalcCRC(prop.BasicName), prop.BasicName, prop.DefaultValue);
                                }
                            }
                        }

                        file.WriteLine("\t\t\tmeta.{0}({1}, {2});", registerName, CRC32.CalcCRC(prop.BasicName), bindingProperty);
                    }
                }

                IList<MethodDef> methods = agent.GetMethods();
                foreach (MethodDef method in methods)
                {
                    bool hasRefParam = false;
                    foreach (MethodDef.Param param in method.Params)
                    {
                        if (param.IsRef || param.IsOut || Plugin.IsRefType(param.Type))
                        {
                            hasRefParam = true;
                            break;
                        }
                    }

                    string agentMethod = "";
                    string paramTypes = "";
                    string paramTypeValues = "";
                    string paramValues = "";

                    if (method.IsNamedEvent || !method.IsCustomized && !hasRefParam)
                    {
                        foreach (MethodDef.Param param in method.Params)
                        {
                            if (!string.IsNullOrEmpty(paramTypes))
                            {
                                paramTypes += ", ";
                            }

                            if (!string.IsNullOrEmpty(paramValues))
                            {
                                paramValues += ", ";
                            }

                            string paramType = DataCsExporter.GetGeneratedNativeType(param.NativeType);
                            paramTypes += paramType;
                            paramTypeValues += ", " + paramType + " " + param.Name;
                            paramValues += param.Name;
                        }
                    }

                    string methodReturnType = DataCsExporter.GetGeneratedNativeType(method.NativeReturnType);

                    if (method.IsNamedEvent)
                    {
                        if (!string.IsNullOrEmpty(paramTypes))
                            paramTypes = string.Format("<{0}>", paramTypes);

                        agentMethod = string.Format("new CAgentMethodVoid{0}(delegate(Agent self{1}) {{ }}) /* {2} */", paramTypes, paramTypeValues, method.BasicName);

                        file.WriteLine("\t\t\tmeta.RegisterMethod({0}, {1});", CRC32.CalcCRC(method.BasicName), agentMethod);
                    }
                    else if (!method.IsCustomized)
                    {
                        if (hasRefParam)
                        {
                            string methodFullname = method.Name.Replace("::", "_");
                            agentMethod = string.Format("new CMethod_{0}()", methodFullname);
                        }
                        else
                        {
                            if (method.IsStatic)
                            {
                                if (paramTypeValues.StartsWith(", "))
                                    paramTypeValues = paramTypeValues.Substring(2);

                                if (methodReturnType == "void")
                                {
                                    if (!string.IsNullOrEmpty(paramTypes))
                                        paramTypes = string.Format("<{0}>", paramTypes);

                                    agentMethod = string.Format("new CAgentStaticMethodVoid{0}(delegate({1}) {{ {2}.{3}({4}); }})",
                                        paramTypes, paramTypeValues, agentTypeName, method.BasicName, paramValues);
                                }
                                else
                                {
                                    if (!string.IsNullOrEmpty(paramTypes))
                                        paramTypes = ", " + paramTypes;

                                    agentMethod = string.Format("new CAgentStaticMethod<{0}{1}>(delegate({2}) {{ return {3}.{4}({5}); }})",
                                        methodReturnType, paramTypes, paramTypeValues, agentTypeName, method.BasicName, paramValues);
                                }
                            }
                            else
                            {
                                string methodStr = "";

                                if (method.IsPublic)
                                {
                                    methodStr = string.Format("(({0})self).{1}({2})", agentTypeName, method.BasicName, paramValues);
                                }
                                else
                                {
                                    paramValues = string.IsNullOrEmpty(paramValues) ? "null" : string.Format("new object[]{{ {0} }}", paramValues);
                                    methodStr = string.Format("AgentMetaVisitor.ExecuteMethod(self, \"{0}\", {1})", method.BasicName, paramValues);
                                }

                                if (methodReturnType == "void")
                                {
                                    if (!string.IsNullOrEmpty(paramTypes))
                                        paramTypes = string.Format("<{0}>", paramTypes);

                                    agentMethod = string.Format("new CAgentMethodVoid{0}(delegate(Agent self{1}) {{ {2}; }})",
                                        paramTypes, paramTypeValues, methodStr);
                                }
                                else
                                {
                                    if (!string.IsNullOrEmpty(paramTypes))
                                        paramTypes = ", " + paramTypes;

                                    if (!method.IsPublic)
                                        methodStr = string.Format("({0}){1}", methodReturnType, methodStr);

                                    agentMethod = string.Format("new CAgentMethod<{0}{1}>(delegate(Agent self{2}) {{ return {3}; }})",
                                        methodReturnType, paramTypes, paramTypeValues, methodStr);
                                }
                            }
                        }

                        file.WriteLine("\t\t\tmeta.RegisterMethod({0}, {1});", CRC32.CalcCRC(method.BasicName), agentMethod);
                    }
                }
            }
        }
    }
}
