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
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Behaviac.Design.Data
{
    public class ExpandedNodePool
    {
        // <filename, <fullId, isExpaned>>
        private static Dictionary<string, Dictionary<string, bool>> _expandedNodeDict = new Dictionary<string, Dictionary<string, bool>>();

        public static void Clear()
        {
            _expandedNodeDict.Clear();
        }

        public static bool HasSetExpandedNodes(NodeViewData nvd)
        {
            Debug.Check(nvd != null && nvd.Node != null);

            Nodes.BehaviorNode behavior = nvd.Node.Behavior;
            string filename = (behavior != null) && !string.IsNullOrEmpty(behavior.Filename) ? behavior.RelativePath : string.Empty;

            if (!string.IsNullOrEmpty(filename) && _expandedNodeDict.ContainsKey(filename))
            {
                return true;
            }

            return false;
        }

        public static bool IsExpandedNode(NodeViewData nvd)
        {
            Debug.Check(nvd != null && nvd.Node != null);

            bool defaultExpanded = !(nvd.Node is Nodes.ReferencedBehavior);
            if (defaultExpanded)
            {
                foreach (NodeViewData child in nvd.Children)
                {
                    if (!child.CanBeExpanded())
                    {
                        defaultExpanded = false;
                        break;
                    }
                }
            }

            Nodes.BehaviorNode behavior = nvd.Node.Behavior;
            string filename = (behavior != null) && !string.IsNullOrEmpty(behavior.Filename) ? behavior.RelativePath : string.Empty;

            if (!string.IsNullOrEmpty(filename) && _expandedNodeDict.ContainsKey(filename))
            {
                Dictionary<string, bool> expandedNodes = _expandedNodeDict[filename];

                string id = nvd.Node.Id.ToString();
                if (!expandedNodes.ContainsKey(id))
                    return defaultExpanded;

                return expandedNodes[id];
            }
            else
            {
                defaultExpanded = true;
            }

            return defaultExpanded;
        }

        public static bool SetExpandedNode(NodeViewData nvd, bool isExpanded)
        {
            Debug.Check(nvd != null && nvd.Node != null);

            Nodes.BehaviorNode behavior = nvd.Node.Behavior;
            if (behavior != null && !string.IsNullOrEmpty(behavior.Filename))
                return SetExpandedNode(behavior.RelativePath, nvd.Node.Id.ToString(), isExpanded);

            return false;
        }

        public static bool SetExpandedNode(string relativePath, string fullId, bool isExpanded)
        {
            if (!string.IsNullOrEmpty(relativePath))
            {
                if (!_expandedNodeDict.ContainsKey(relativePath))
                    _expandedNodeDict[relativePath] = new Dictionary<string, bool>();

                Dictionary<string, bool> expandedNodes = _expandedNodeDict[relativePath];
                expandedNodes[fullId] = isExpanded;

                return true;
            }

            return false;
        }

        public static void Serialize(Stream stream, BinaryFormatter formatter)
        {
            formatter.Serialize(stream, _expandedNodeDict);
        }

        public static void Deserialize(Stream stream, BinaryFormatter formatter)
        {
            Clear();

            try
            {
                Dictionary<string, Dictionary<string, bool>> nodes = formatter.Deserialize(stream) as Dictionary<string, Dictionary<string, bool>>;
                if (nodes != null)
                    _expandedNodeDict = nodes;
            }
            catch (Exception)
            {
            }
        }
    }
}
