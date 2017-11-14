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
using System.Text;
using System.IO;
using System.Xml;

namespace Behaviac.Design.Exporters
{
    /// <summary>
    /// This exporter generates .cs files which generate a static variable which holds the behaviour tree.
    /// </summary>
    public class XmlToJson
    {
        public static string XmlToJSON(XmlDocument xmlDoc) {
            StringBuilder sbJSON = new StringBuilder();
            sbJSON.Append("{ ");
            XmlToJSONnode(sbJSON, xmlDoc.DocumentElement, true);
            sbJSON.Append("}");
            return sbJSON.ToString();
        }


        //  XmlToJSONnode:  Output an XmlElement, possibly as part of a higher array
        private static void XmlToJSONnode(StringBuilder sbJSON, XmlElement node, bool showNodeName) {
            if (showNodeName)
            { sbJSON.Append("\"" + SafeJSON(node.Name) + "\": "); }

            sbJSON.Append("{");
            // Build a sorted list of key-value pairs
            //  where   key is case-sensitive nodeName
            //          value is an ArrayList of string or XmlElement
            //  so that we know whether the nodeName is an array or not.
            SortedList childNodeNames = new SortedList();


            //  Add in all node attributes
            if (node.Attributes != null)
                foreach(XmlAttribute attr in node.Attributes)
                StoreChildNode(childNodeNames, attr.Name, attr.InnerText);


            //  Add in all nodes
            foreach(XmlNode cnode in node.ChildNodes) {
                if (cnode is XmlText)
                { StoreChildNode(childNodeNames, "value", cnode.InnerText); }

                else if (cnode is XmlElement)
                { StoreChildNode(childNodeNames, cnode.Name, cnode); }
            }


            // Now output all stored info
            foreach(string childname in childNodeNames.Keys) {
                ArrayList alChild = (ArrayList)childNodeNames[childname];

                if (alChild.Count == 1)
                { OutputNode(childname, alChild[0], sbJSON, true); }

                else {
                    sbJSON.Append(" \"" + SafeJSON(childname) + "\": [ ");
                    foreach(object Child in alChild)
                    OutputNode(childname, Child, sbJSON, false);
                    sbJSON.Remove(sbJSON.Length - 2, 2);
                    sbJSON.Append(" ], ");
                }
            }
            sbJSON.Remove(sbJSON.Length - 2, 2);
            sbJSON.Append(" }");
        }


        //  StoreChildNode: Store data associated with each nodeName
        //                  so that we know whether the nodeName is an array or not.
        private static void StoreChildNode(SortedList childNodeNames, string nodeName, object nodeValue) {
            // Pre-process contraction of XmlElement-s
            if (nodeValue is XmlElement) {
                // Convert  <aa></aa> into "aa":null
                //          <aa>xx</aa> into "aa":"xx"
                XmlNode cnode = (XmlNode)nodeValue;

                if (cnode.Attributes.Count == 0) {
                    XmlNodeList children = cnode.ChildNodes;

                    if (children.Count == 0)
                    { nodeValue = null; }

                    else if (children.Count == 1 && (children[0] is XmlText))
                    { nodeValue = ((XmlText)(children[0])).InnerText; }
                }
            }

            // Add nodeValue to ArrayList associated with each nodeName
            // If nodeName doesn't exist then add it
            object oValuesAL = childNodeNames[nodeName];
            ArrayList ValuesAL;

            if (oValuesAL == null) {
                ValuesAL = new ArrayList();
                childNodeNames[nodeName] = ValuesAL;

            } else
            { ValuesAL = (ArrayList)oValuesAL; }

            ValuesAL.Add(nodeValue);
        }


        private static void OutputNode(string childname, object alChild, StringBuilder sbJSON, bool showNodeName) {
            if (alChild == null) {
                if (showNodeName)
                { sbJSON.Append("\"" + SafeJSON(childname) + "\": "); }

                sbJSON.Append("null");

            } else if (alChild is string) {
                if (showNodeName)
                { sbJSON.Append("\"" + SafeJSON(childname) + "\": "); }

                string sChild = (string)alChild;
                sChild = sChild.Trim();
                sbJSON.Append("\"" + SafeJSON(sChild) + "\"");

            } else
            { XmlToJSONnode(sbJSON, (XmlElement)alChild, showNodeName); }

            sbJSON.Append(", ");
        }


        // Make a string safe for JSON
        static private string SafeJSON(string sIn) {
            //StringBuilder sbOut = new StringBuilder(sIn.Length);
            //foreach (char ch in sIn)
            //{
            //    if (Char.IsControl(ch) || ch == '\'')
            //    {
            //        int ich = (int)ch;
            //        sbOut.Append(@"\u" + ich.ToString("x4"));
            //        continue;
            //    }
            //    else if (ch == '\"' || ch == '\\' || ch == '/')
            //    {
            //        sbOut.Append('\\');
            //    }
            //    sbOut.Append(ch);
            //}
            //return sbOut.ToString();
            return sIn;
        }
    }
}