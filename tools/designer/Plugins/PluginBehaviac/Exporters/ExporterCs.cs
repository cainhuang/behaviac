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
using PluginBehaviac.Properties;
using PluginBehaviac.DataExporters;
using PluginBehaviac.NodeExporters;

namespace PluginBehaviac.Exporters
{
    public class ExporterCs : Behaviac.Design.Exporters.Exporter
    {
        public ExporterCs(BehaviorNode node, string outputFolder, string filename, List<string> includedFilenames = null)
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

        private void ExportHead(StreamWriter file, string exportFilename)
        {
            string wsfolder = Path.GetDirectoryName(Workspace.Current.FileName);
            exportFilename = Behaviac.Design.FileManagers.FileManager.MakeRelative(wsfolder, exportFilename);
            exportFilename = exportFilename.Replace("\\", "/");

            // write comments
            file.WriteLine("// ---------------------------------------------------------------------");
            file.WriteLine("// This file is auto-generated, so please don't modify it by yourself!");
            file.WriteLine("// Export file: {0}", exportFilename);
            file.WriteLine("// ---------------------------------------------------------------------\r\n");

            // write the namespaces for the game agents
            file.WriteLine("using System;");
            file.WriteLine("using System.Collections;");
            file.WriteLine("using System.Collections.Generic;");
            file.WriteLine("using System.Reflection;\r\n");

            // write namespace
            file.WriteLine("namespace behaviac\r\n{");

            // write the AgentExtra_Generated class
            file.WriteLine("\tclass AgentExtra_Generated");
            file.WriteLine("\t{");
            file.WriteLine("\t\tprivate static Dictionary<string, FieldInfo> _fields = new Dictionary<string, FieldInfo>();");
            file.WriteLine("\t\tprivate static Dictionary<string, PropertyInfo> _properties = new Dictionary<string, PropertyInfo>();");
            file.WriteLine("\t\tprivate static Dictionary<string, MethodInfo> _methods = new Dictionary<string, MethodInfo>();");
            file.WriteLine();
            file.WriteLine("\t\tpublic static object GetProperty(behaviac.Agent agent, string property)");
            file.WriteLine("\t\t{");
            file.WriteLine("\t\t\tType type = agent.GetType();");
            file.WriteLine("\t\t\tstring propertyName = type.FullName + property;");
            file.WriteLine("\t\t\tif (_fields.ContainsKey(propertyName))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\treturn _fields[propertyName].GetValue(agent);");
            file.WriteLine("\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\tif (_properties.ContainsKey(propertyName))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\treturn _properties[propertyName].GetValue(agent, null);");
            file.WriteLine("\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\twhile (type != typeof(object))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\tFieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);");
            file.WriteLine("\t\t\t\tif (field != null)");
            file.WriteLine("\t\t\t\t{");
            file.WriteLine("\t\t\t\t\t_fields[propertyName] = field;");
            file.WriteLine("\t\t\t\t\treturn field.GetValue(agent);");
            file.WriteLine("\t\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\t\tPropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);");
            file.WriteLine("\t\t\t\tif (prop != null)");
            file.WriteLine("\t\t\t\t{");
            file.WriteLine("\t\t\t\t\t_properties[propertyName] = prop;");
            file.WriteLine("\t\t\t\t\treturn prop.GetValue(agent, null);");
            file.WriteLine("\t\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\t\ttype = type.BaseType;");
            file.WriteLine("\t\t\t}");
            file.WriteLine("\t\t\tDebug.Check(false, \"No property can be found!\");");
            file.WriteLine("\t\t\treturn null;");
            file.WriteLine("\t\t}\r\n");

            file.WriteLine("\t\tpublic static void SetProperty(behaviac.Agent agent, string property, object value)");
            file.WriteLine("\t\t{");
            file.WriteLine("\t\t\tType type = agent.GetType();");
            file.WriteLine("\t\t\tstring propertyName = type.FullName + property;");
            file.WriteLine("\t\t\tif (_fields.ContainsKey(propertyName))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\t_fields[propertyName].SetValue(agent, value);");
            file.WriteLine("\t\t\t\treturn;");
            file.WriteLine("\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\tif (_properties.ContainsKey(propertyName))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\t_properties[propertyName].SetValue(agent, value, null);");
            file.WriteLine("\t\t\t\treturn;");
            file.WriteLine("\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\twhile (type != typeof(object))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\tFieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);");
            file.WriteLine("\t\t\t\tif (field != null)");
            file.WriteLine("\t\t\t\t{");
            file.WriteLine("\t\t\t\t\t_fields[propertyName] = field;");
            file.WriteLine("\t\t\t\t\tfield.SetValue(agent, value);");
            file.WriteLine("\t\t\t\t\treturn;");
            file.WriteLine("\t\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\t\tPropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);");
            file.WriteLine("\t\t\t\tif (prop != null)");
            file.WriteLine("\t\t\t\t{");
            file.WriteLine("\t\t\t\t\t_properties[propertyName] = prop;");
            file.WriteLine("\t\t\t\t\tprop.SetValue(agent, value, null);");
            file.WriteLine("\t\t\t\t\treturn;");
            file.WriteLine("\t\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\t\ttype = type.BaseType;");
            file.WriteLine("\t\t\t}");
            file.WriteLine("\t\t\tDebug.Check(false, \"No property can be found!\");");
            file.WriteLine("\t\t}\r\n");

            file.WriteLine("\t\tpublic static object ExecuteMethod(behaviac.Agent agent, string method, object[] args)");
		    file.WriteLine("\t\t{");
            file.WriteLine("\t\t\tType type = agent.GetType();");
            file.WriteLine("\t\t\tstring methodName = type.FullName + method;");
            file.WriteLine("\t\t\tif (_methods.ContainsKey(methodName))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\treturn _methods[methodName].Invoke(agent, args);;");
            file.WriteLine("\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\twhile (type != typeof(object))");
            file.WriteLine("\t\t\t{");
            file.WriteLine("\t\t\t\tMethodInfo m = type.GetMethod(method, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);");
            file.WriteLine("\t\t\t\tif (m != null)");
            file.WriteLine("\t\t\t\t{");
            file.WriteLine("\t\t\t\t\t_methods[methodName] = m;");
            file.WriteLine("\t\t\t\t\treturn m.Invoke(agent, args);");
            file.WriteLine("\t\t\t\t}");
            file.WriteLine();
            file.WriteLine("\t\t\t\ttype = type.BaseType;");
            file.WriteLine("\t\t\t}");
            file.WriteLine("\t\t\tDebug.Check(false, \"No method can be found!\");");
            file.WriteLine("\t\t\treturn null;");
		    file.WriteLine("\t\t}");
            file.WriteLine("\t}\r\n");
        }

        private string getValidFilename(string filename)
        {
            filename = filename.Replace('/', '_');
            filename = filename.Replace('-', '_');

            return filename;
        }

        private void ExportBody(StreamWriter file, BehaviorNode behavior)
        {
            string filename = Path.ChangeExtension(behavior.RelativePath, "").Replace(".", "");
            filename = filename.Replace('\\', '/');

            // write comments
            file.WriteLine("\t// Source file: {0}\r\n", filename);

            string btClassName = string.Format("bt_{0}", getValidFilename(filename));
            string agentType = behavior.AgentType.AgentTypeName;

            // create the class definition of its attachments
            ExportAttachmentClass(file, btClassName, (Node)behavior);

            // create the class definition of its children
            foreach (Node child in ((Node)behavior).Children)
                ExportNodeClass(file, btClassName, agentType, behavior, child);

            // create the bt class
            file.WriteLine("\tpublic static class {0}\r\n\t{{", btClassName);

            // export the build function
            file.WriteLine("\t\tpublic static bool build_behavior_tree(BehaviorTree bt)\r\n\t\t{");
            file.WriteLine("\t\t\tbt.SetClassNameString(\"BehaviorTree\");");
            file.WriteLine("\t\t\tbt.SetId(-1);");
            file.WriteLine("\t\t\tbt.SetName(\"{0}\");", filename);
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

            ExportPars(file, "bt", (Node)behavior, "\t\t");

            // export its attachments
            ExportAttachment(file, btClassName, agentType, "bt", (Node)behavior, "\t\t\t");

            file.WriteLine("\t\t\t// children");

            // export its children
            foreach (Node child in ((Node)behavior).Children)
                ExportNode(file, btClassName, agentType, "bt", child, 3);

            file.WriteLine("\t\t\treturn true;");

            // close the build function
            file.WriteLine("\t\t}");

            // close class
            file.WriteLine("\t}\r\n");
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
                    string type = DataCsExporter.GetGeneratedParType(pars[i].Type);
                    string value = pars[i].DefaultValue.Replace("\"", "\\\"");
                    string eventParam = pars[i].EventParam;

                    file.WriteLine("{0}\t{1}.AddPar(\"{2}\", \"{3}\", \"{4}\", \"{5}\");", indent, nodeName, type, name, value, eventParam);
                }
            }
        }

        private void ExportAttachmentClass(StreamWriter file, string btClassName, Node node)
        {
            foreach (Behaviac.Design.Attachments.Attachment attach in node.Attachments)
            {
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
                    file.WriteLine("{0}{{", indent);

                    string nodeName = string.Format("attach{0}", attach.Id);

                    // export its instance and the properties
                    AttachmentCsExporter attachmentExporter = AttachmentCsExporter.CreateInstance(attach);
                    attachmentExporter.GenerateInstance(attach, file, indent, nodeName, agentType, btClassName);

                    ExportPars(file, nodeName, attach, indent);

                    file.WriteLine("{0}\t{1}.Attach({2});", indent, parentName, nodeName);
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
            string nodeName = string.Format("node{0}", node.Id);

            NodeCsExporter nodeExporter = NodeCsExporter.CreateInstance(node);
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
            {
                indent += '\t';
            }

            string nodeName = string.Format("node{0}", node.Id);

            // open some brackets for a better formatting in the generated code
            file.WriteLine("{0}{{", indent);

            // export its instance and the properties
            NodeCsExporter nodeExporter = NodeCsExporter.CreateInstance(node);
            nodeExporter.GenerateInstance(node, file, indent, nodeName, agentType, btClassName);

            ExportPars(file, nodeName, node, indent);

            ExportAttachment(file, btClassName, agentType, nodeName, node, indent + "\t");

            // add the node to its parent
            file.WriteLine("{0}\t{1}.AddChild({2});", indent, parentName, nodeName);

            // export the child nodes
            if (!(node is ReferencedBehavior))
            {
                foreach (Node child in node.Children)
                {
                    ExportNode(file, btClassName, agentType, nodeName, child, indentDepth + 1);
                }
            }

            file.WriteLine("{0}\t{1}.SetHasEvents({1}.HasEvents() | {2}.HasEvents());", indent, parentName, nodeName);

            // close the brackets for a better formatting in the generated code
            file.WriteLine("{0}}}", indent);
        }
    }
}
