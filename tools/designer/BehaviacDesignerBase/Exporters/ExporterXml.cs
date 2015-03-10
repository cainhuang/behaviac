////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009, Daniel Kollmann
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this list of conditions
//   and the following disclaimer.
//
// - Redistributions in binary form must reproduce the above copyright notice, this list of
//   conditions and the following disclaimer in the documentation and/or other materials provided
//   with the distribution.
//
// - Neither the name of Daniel Kollmann nor the names of its contributors may be used to endorse
//   or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The above software in this distribution may have been modified by THL A29 Limited ("Tencent Modifications").
//
// All Tencent Modifications are Copyright (C) 2015 THL A29 Limited.
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
    public class ExporterXml : Behaviac.Design.Exporters.Exporter
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

        public ExporterXml(BehaviorNode node, string outputFolder, string filename)
            : base(node, outputFolder, filename + ".xml")
        {
        }

        /// <summary>
        /// Exports a behaviour to the given file.
        /// </summary>
        /// <param name="file">The file we want to export to.</param>
        /// <param name="behavior">The behaviour we want to export.</param>
        protected void ExportBehavior(XmlWriter file, BehaviorNode behavior)
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

            file.WriteAttributeString("name", behaviorName);
            //file.WriteAttributeString("event", b.EventName);
            file.WriteAttributeString("agenttype", b.AgentType.AgentTypeName);
            file.WriteAttributeString("version", b.Version.ToString());

            this.ExportProperties(file, b);

            this.ExportParameters(file, (Node)behavior);

            this.ExportAttachments(file, b);
#if QUERY_EANBLED
            //after ExportProperties as DescritorRefs are exported as property
            this.ExportDescritorRefs(file, b);
#endif//#if QUERY_EANBLED

            // export the children
            foreach (Node child in ((Node)behavior).Children)
            {
                this.ExportNode(file, behavior, (Node)behavior, child);
            }

            file.WriteEndElement();
        }

        private void ExportParameters(XmlWriter file, Node node)
        {
            if (node.Pars.Count == 0)
                return;

            file.WriteStartElement("pars");

            for (int i = 0; i < node.Pars.Count; ++i)
            {
                //if (node.Pars[i].Name == "par0_char_0")
                //{
                //    Debug.Check(true);
                //}

                string parType = Plugin.GetNativeTypeName(node.Pars[i].Type);

                file.WriteStartElement("par");

                file.WriteAttributeString("name", node.Pars[i].Name);
                file.WriteAttributeString("type", parType);
                file.WriteAttributeString("value", node.Pars[i].DefaultValue);

                file.WriteEndElement();
            }

            file.WriteEndElement();
        }

        private void ExportParameters(XmlWriter file, Attachments.Attachment attachment)
        {
            Attachments.Event evt = attachment as Attachments.Event;

            if (evt == null || evt.Pars.Count == 0)
                return;

            file.WriteStartElement("pars");

            for (int i = 0; i < evt.Pars.Count; ++i)
            {
                file.WriteStartElement("par");

                file.WriteAttributeString("name", evt.Pars[i].Name);
                file.WriteAttributeString("type", Plugin.GetNativeTypeName(evt.Pars[i].Type));
                file.WriteAttributeString("value", evt.Pars[i].DefaultValue);
                if (!string.IsNullOrEmpty(evt.Pars[i].EventParam))
                    file.WriteAttributeString("eventParam", evt.Pars[i].EventParam);

                file.WriteEndElement();
            }

            file.WriteEndElement();
        }


#if QUERY_EANBLED
        private void ExportDescritorRefs(XmlWriter file, Behavior b)
        {
            if (b.DescriptorRefs.Count == 0)
                return;

            file.WriteStartElement("property");

            string propValue = DesignerArray.RetrieveExportValue(b.DescriptorRefs);
            file.WriteAttributeString("DescriptorRefs", propValue);

            file.WriteEndElement();
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
        protected void ExportNode(XmlWriter file, BehaviorNode behavior, Node parent, Node node)
        {
            if (!node.Enable)
                return;

            file.WriteStartElement("node");

            file.WriteAttributeString("class", node.ExportClass);
            file.WriteAttributeString("version", node.Version.ToString());
            file.WriteAttributeString("id", node.Id.ToString());

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
        private void ExportProperties(XmlWriter file, Node n)
        {
            IList<DesignerPropertyInfo> properties = n.GetDesignerProperties();

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
                        file.WriteStartElement("property");
                        file.WriteAttributeString(p.Property.Name, propValue);
                        file.WriteEndElement();
                    }
                }
            }
        }

        private void ExportProperties(XmlWriter file, Attachments.Attachment a)
        {
            IList<DesignerPropertyInfo> properties = a.GetDesignerProperties();
            foreach (DesignerPropertyInfo p in properties)
            {
                // we skip properties which are not marked to be exported
                if (p.Attribute.HasFlags(DesignerProperty.DesignerFlags.NoExport))
                    continue;

                // create the code which assigns the value to the node's property
                //file.Write(string.Format("{0}\t{1}.{2} = {3};\r\n", indent, nodeName, properties[p].Property.Name, properties[p].GetExportValue(node)));
                file.WriteStartElement("property");
                file.WriteAttributeString(p.Property.Name, p.GetExportValue(a));
                file.WriteEndElement();
            }
        }


        protected void ExportAttachments(XmlWriter file, Node node)
        {
            //file.WriteStartElement("attachments");

            foreach (Attachments.Attachment a in node.Attachments)
            {
                file.WriteStartElement("attachment");

                Type type = a.GetType();
                file.WriteAttributeString("class", a.ExportClass);
                file.WriteAttributeString("id", a.Id.ToString());

                this.ExportProperties(file, a);
                this.ExportParameters(file, a);

                file.WriteEndElement();
            }

            //file.WriteEndElement();
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

            // export to the file
            using (StreamWriter file = new StreamWriter(filename))
            {
                XmlWriterSettings ws = new XmlWriterSettings();
                ws.Indent = true;
                //ws.OmitXmlDeclaration = true;

                using (XmlWriter xmlWrtier = XmlWriter.Create(file, ws))
                {
                    xmlWrtier.WriteStartDocument();
                    ExportBehavior(xmlWrtier, _node);
                    xmlWrtier.WriteEndDocument();
                }

                file.Close();
            }

            return FileManagers.SaveResult.Succeeded;
        }
    }
}
