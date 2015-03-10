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
using System.Xml;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Exporters
{
    /// <summary>
    /// This exporter generates .cs files which generate a static variable which holds the behaviour tree.
    /// </summary>
    public class ExporterBson : Behaviac.Design.Exporters.Exporter
    {
        protected static string __usedNamespace = "Behaviac.Behaviors";

        /// <summary>
        /// The namespace the behaviours will be exported to.
        /// </summary>
        public static string UsedNamespace
        {
            get { return __usedNamespace; }
            set { __usedNamespace = value; }
        }

        public ExporterBson(BehaviorNode node, string outputFolder, string filename)
            : base(node, outputFolder, filename + ".bson.bytes")
        {
        }

        /// <summary>
        /// Exports a behaviour to the given file.
        /// </summary>
        /// <param name="file">The file we want to export to.</param>
        /// <param name="behavior">The behaviour we want to export.</param>
        protected void ExportBehavior(BsonSerializer file, BehaviorNode behavior)
        {
            file.WriteComment("EXPORTED BY TOOL, DON'T MODIFY IT!");
            file.WriteComment("Source File: " + behavior.MakeRelative(behavior.FileManager.Filename));

            file.WriteStartElement("behavior");

            Behavior b = behavior as Behavior;
            Debug.Check(b != null);
            Debug.Check(b.Id == -1);

            //'\\' ->'/'
            string behaviorName = b.MakeRelative(b.Filename);
            behaviorName = behaviorName.Replace('\\', '/');
            int pos = behaviorName.IndexOf(".xml");
            if (pos != -1)
            {
                behaviorName = behaviorName.Remove(pos);
            }

            file.WriteString(behaviorName);
            file.WriteString(b.AgentType.AgentTypeName);
            file.WriteString(b.Version.ToString());

            this.ExportProperties(file, b);

            this.ExportParameters(file, (Node)behavior);

            this.ExportAttachments(file, b);

            // export the children
            foreach (Node child in ((Node)behavior).Children)
            {
                this.ExportNode(file, behavior, (Node)behavior, child);
            }

            file.WriteEndElement();
        }

        private void ExportParameters(BsonSerializer file, Node node)
        {
            if (node.Pars.Count == 0)
                return;

            file.WriteStartElement("pars");

            for (int i = 0; i < node.Pars.Count; ++i)
            {
                string parType = Plugin.GetNativeTypeName(node.Pars[i].Type);

                file.WriteStartElement("par");

                file.WriteString(node.Pars[i].Name);
                file.WriteString(parType);
                file.WriteString(node.Pars[i].DefaultValue);

                file.WriteEndElement();
            }

            file.WriteEndElement();
        }

        private void ExportParameters(BsonSerializer file, Attachments.Attachment attachment)
        {
            Attachments.Event evt = attachment as Attachments.Event;

            if (evt == null || evt.Pars.Count == 0)
                return;

            file.WriteStartElement("pars");

            for (int i = 0; i < evt.Pars.Count; ++i)
            {
                file.WriteStartElement("par");

                file.WriteString(evt.Pars[i].Name);
                file.WriteString(Plugin.GetNativeTypeName(evt.Pars[i].Type));
                file.WriteString(evt.Pars[i].DefaultValue);

                if (!string.IsNullOrEmpty(evt.Pars[i].EventParam))
                {
                    file.WriteString(evt.Pars[i].EventParam);
                }

                file.WriteEndElement();
            }

            file.WriteEndElement();
        }


#if QUERY_EANBLED
        private void ExportDescritorRefs(BsonSerializer file, Behavior b)
        {
            if (b.DescriptorRefs.Count == 0)
                return;

            string propValue = DesignerArray.RetrieveExportValue(b.DescriptorRefs);
            file.WriteAttributeString("DescriptorRefs", propValue);
        }
#endif//#endif//#if QUERY_EANBLED

        /// <summary>
        /// Exports a node to the given file.
        /// </summary>
        /// <param name="file">The file we want to export to.</param>
        /// <param name="namspace">The namespace of the behaviour we are currently exporting.</param>
        /// <param name="behavior">The behaviour we are currently exporting.</param>
        /// <param name="parentName">The name of the variable of the node which is the parent of this node.</param>
        /// <param name="node">The node we want to export.</param>
        /// <param name="indentDepth">The indent of the ocde we are exporting.</param>
        /// <param name="nodeID">The current id used for generating the variables for the nodes.</param>
        protected void ExportNode(BsonSerializer file, BehaviorNode behavior, Node parent, Node node)
        {
            if (!node.Enable)
                return;

            file.WriteStartElement("node");

            file.WriteString(node.ExportClass);
            file.WriteString(node.Version.ToString());
            file.WriteString(node.Id.ToString());

            //// we have to handle a referenced behaviour differently
            //if (node is ReferencedBehaviorNode)
            //{
            //    // generate the namespace and name of the behaviour we are referencing
            //    string refRelativeFilename = behavior.MakeRelative(((ReferencedBehaviorNode)node).ReferenceFilename);
            //    string refBehaviorName = Path.GetFileNameWithoutExtension(((ReferencedBehaviorNode)node).ReferenceFilename.Replace(" ", string.Empty));

            //    file.WriteStartElement("property");
            //    file.WriteAttributeString("referencefilename", refBehaviorName);
            //    file.WriteEndElement();
            //}
            //else
            {
                // export the properties
                this.ExportProperties(file, node);

                this.ExportParameters(file, node);

                this.ExportAttachments(file, node);

                // add the node to its parent
                //file.Write(string.Format("{0}\t{1}.AddChild({1}.GetConnector(\"{2}\"), {3});\r\n", indent, parentName, node.ParentConnector.Identifier, nodeName));

                if (!(node is ReferencedBehavior))
                {
                    // export the child nodes
                    foreach (Node child in node.Children)
                    {
                        this.ExportNode(file, behavior, node, child);
                    }
                }
            }

            file.WriteEndElement();
        }

        /// <summary>
        /// Exports all the properties of a ode and assigns them.
        /// </summary>
        /// <param name="file">The file we are exporting to.</param>
        /// <param name="nodeName">The name of the node we are setting the properties for.</param>
        /// <param name="node">The node whose properties we are exporting.</param>
        /// <param name="indent">The indent for the currently generated code.</param>
        private void ExportProperties(BsonSerializer file, Node n)
        {
            IList<DesignerPropertyInfo> properties = n.GetDesignerProperties();

            file.WriteStartElement("properties");

            foreach (DesignerPropertyInfo p in properties)
            {
                // we skip properties which are not marked to be exported
                if (p.Attribute.HasFlags(DesignerProperty.DesignerFlags.NoExport))
                    continue;

                bool bDo = true;
                if (p.Attribute.HasFlags(DesignerProperty.DesignerFlags.BeValid))
                {
                    object obj = p.Property.GetValue(n, null);

                    if (obj == null || obj.ToString() == "null_method")
                    {
                        bDo = false;
                    }
                }

                if (bDo)
                {

                    // create the code which assigns the value to the node's property
                    //file.Write(string.Format("{0}\t{1}.{2} = {3};\r\n", indent, nodeName, properties[p].Property.Name, properties[p].GetExportValue(node)));
                    string propValue = p.GetExportValue(n);
                    if (propValue != string.Empty && propValue != "\"\"")
                    {
                        WriteProperty(file, p, n);
                    }
                }
            }

#if QUERY_EANBLED
            Behavior b = n as Behavior;
            if (b != null)
            {
                this.ExportDescritorRefs(file, b);
            }
#endif

            file.WriteEndElement();
        }


        private void ExportProperties(BsonSerializer file, Attachments.Attachment a)
        {
            file.WriteStartElement("properties");
            IList<DesignerPropertyInfo> properties = a.GetDesignerProperties();
            foreach (DesignerPropertyInfo p in properties)
            {
                // we skip properties which are not marked to be exported
                if (p.Attribute.HasFlags(DesignerProperty.DesignerFlags.NoExport))
                    continue;

                WriteProperty(file, p, a);
            }
            file.WriteEndElement();
        }


        protected void ExportAttachments(BsonSerializer file, Node node)
        {
            if (node.Attachments.Count > 0)
            {
                file.WriteStartElement("attachments");

                foreach (Attachments.Attachment a in node.Attachments)
                {
                    file.WriteStartElement("attachment");

                    Type type = a.GetType();

                    file.WriteString(a.ExportClass);
                    file.WriteString(a.Id.ToString());

                    this.ExportProperties(file, a);
                    this.ExportParameters(file, a);

                    file.WriteEndElement();
                }

                file.WriteEndElement();
            }
        }

        static private void WritePar(BsonSerializer file, string valueName, ParInfo par)
        {
            //WriteParValue(file, valueName, par);
            WriteParString(file, valueName, par);
        }

        static private void WriteParString(BsonSerializer file, string valueName, ParInfo par)
        {
            string parStr = par.DefaultValue;
            //file.WriteAttribute(valueName, parStr);
            file.WriteString(parStr);
        }

        static private void WriteParValue(BsonSerializer file, string valueName, ParInfo par)
        {
            string parStr = par.DefaultValue;

            object v = null;

            Type valueType = par.Type;

            if (valueType != null && Plugin.InvokeTypeParser(valueType, parStr, (object value) => v = value, null))
            {
                //file.WriteAttribute(valueName, v);
                file.Write(v);
            }
        }

        static private void WriteProperty(BsonSerializer file, DesignerPropertyInfo property, object o)
        {
            //WritePropertyValue(file, property, o);
            WritePropertyString(file, property, o);
        }

        static private void WritePropertyString(BsonSerializer file, DesignerPropertyInfo property, object o)
        {
            string str = property.GetExportValue(o);

            file.WriteAttributeString(property.Property.Name, str);
        }

        static private void WritePropertyValue(BsonSerializer file, DesignerPropertyInfo property, object o)
        {
            string str = property.GetExportValue(o);
            string[] tokens = str.Split(' ');
            string valueString = null;
            if (tokens.Length == 3 && tokens[0] == "const")
            {
                valueString = tokens[2];
            }
            else if (tokens.Length == 1)
            {
                valueString = str;
            }

            bool bW = false;
            if (valueString != null)
            {
                object obj = property.Property.GetValue(o, null);

                object v = null;

                Type valueType = null;
                VariableDef varType = obj as VariableDef;
                if (varType != null)
                {
                    valueType = varType.GetValueType();
                }
                else
                {
                    RightValueDef rvarType = obj as RightValueDef;
                    if (rvarType != null)
                    {
                        if (rvarType.Method == null)
                        {
                            valueType = rvarType.ValueType;
                        }
                    }
                    else
                    {
                        MethodDef mType = obj as MethodDef;
                        if (mType != null)
                        {
                            Debug.Check(true);
                        }
                        else
                        {
                            valueType = obj.GetType();
                        }
                    }
                }

                if (valueType != null && Plugin.InvokeTypeParser(valueType, valueString, (object value) => v = value, null))
                {
                    file.WriteAttribute(property.Property.Name, v);
                    bW = true;
                }
            }

            if (!bW)
            {
                file.WriteAttributeString(property.Property.Name, str);
            }
        }

        /// <summary>
        /// Export the assigned node to the assigned file.
        /// </summary>
        /// <returns>Returns the result when the behaviour is exported.</returns>
        public override FileManagers.SaveResult Export()
        {
            string filename = Path.Combine(_outputFolder, _filename);
            FileManagers.SaveResult result = FileManagers.FileManager.MakeWritable(filename, Resources.ExportFileWarning);
            if (FileManagers.SaveResult.Succeeded != result)
                return result;

            // get the abolute folder of the file we want toexport
            string folder = Path.GetDirectoryName(filename);
            if (!Directory.Exists(folder))
                Directory.CreateDirectory(folder);

            using (var ms = new MemoryStream())
            using (var writer = new BinaryWriter(ms))
            {
                //BsonSerializer.Serialize(writer, _node);
                BsonSerializer serializer = BsonSerializer.CreateSerialize(writer);
                serializer.WriteStartDocument();
                ExportBehavior(serializer, _node);
                serializer.WriteEndDocument();


                // export to the file
                using (FileStream fs = File.Create(filename))
                {
                    //BinaryFormatter formatter = new BinaryFormatter();
                    //formatter.Serialize(file, d);

                    using (BinaryWriter w = new BinaryWriter(fs))
                    {
                        byte[] d = ms.ToArray();

                        w.Write(d);
                        fs.Close();
                    }
                }

                //ms.Position = 0;

                //using (var reader = new BinaryReader(ms))
                //{
                //    Nodes.BehaviorNode b = BsonDeserializer.Deserializer<Nodes.BehaviorNode>(reader);
                //}
            }

            return FileManagers.SaveResult.Succeeded;
        }
    }
}
