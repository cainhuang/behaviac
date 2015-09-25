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
using System.Text;
using System.Windows.Forms;
using Behaviac.Design.Data;
using Behaviac.Design.Nodes;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    internal class UIUtilities
    {
        /// <summary>
        /// Show the behavior tree view.
        /// </summary>
        /// <param name="behaviorFilename">The behavior filename in the workspace folder.</param>
        public static BehaviorTreeView ShowBehaviorTree(string behaviorFilename)
        {
            if (string.IsNullOrEmpty(behaviorFilename))
                return null;

            if (!Path.IsPathRooted(behaviorFilename))
                behaviorFilename = FileManagers.FileManager.GetFullPath(behaviorFilename);

            if (!File.Exists(behaviorFilename))
                return null;

            BehaviorNode behavior = BehaviorManager.Instance.GetBehavior(behaviorFilename);
            if (behavior == null)
                behavior = BehaviorManager.Instance.LoadBehavior(behaviorFilename);

            if (behavior is Node)
            {
                BehaviorTreeList behaviorTreeList = BehaviorManager.Instance as BehaviorTreeList;
                if (behaviorTreeList != null)
                    behaviorTreeList.ShowNode(behavior as Node);
            }

            return BehaviorTreeViewDock.GetBehaviorTreeView(behavior);
        }

        /// <summary>
        /// Show the behavior tree view with highlights.
        /// </summary>
        /// <param name="agentFullname">The fullname of an agent instance, as the format of "agnetType::instanceName".</param>
        /// <param name="frame">The current frame when connecting or playing.</param>
        public static BehaviorNode ShowBehaviorTree(string agentFullname, int frame, List<string> highlightNodeIds, List<string> updatedNodeIds, HighlightBreakPoint highlightBreakPoint, Dictionary<string, FrameStatePool.NodeProfileInfos.ProfileInfo> profileInfos)
        {
            string behaviorFilename = (highlightBreakPoint != null) ? highlightBreakPoint.BehaviorFilename : FrameStatePool.GetBehaviorFilename(agentFullname, frame);
            if (!string.IsNullOrEmpty(behaviorFilename))
            {
                BehaviorTreeView behaviorTreeView = ShowBehaviorTree(behaviorFilename);
                if (behaviorTreeView != null)
                {
                    if (!Settings.Default.ShowProfilingInfo)
                        profileInfos = null;

                    behaviorTreeView.SetHighlights(highlightNodeIds, updatedNodeIds, highlightBreakPoint, profileInfos);
                    //behaviorTreeView.Focus();

                    return behaviorTreeView.RootNode;
                }
            }

            return null;
        }

        /// <summary>
        /// Sort the treeview by name and child count.
        /// </summary>
        /// <param name="nodes">All child tree nodes.</param>
        public static void SortTreeview(TreeNodeCollection nodes)
        {
            if (nodes.Count == 0)
                return;

            List<TreeNode> leaves = new List<TreeNode>();
            List<TreeNode> branches = new List<TreeNode>();

            foreach (TreeNode node in nodes)
            {
                if (node.GetNodeCount(false) > 0)
                {
                    branches.Add(node);
                    SortTreeview(node.Nodes);
                }
                else
                {
                    leaves.Add(node);
                }
            }

            nodes.Clear();

            if (leaves.Count > 0)
            {
                TreeNode[] leafArray = new TreeNode[leaves.Count];
                leaves.CopyTo(leafArray, 0);

                Comparison<TreeNode> compare = delegate(TreeNode tx, TreeNode ty)
                {
                    if (tx.Text.Length != ty.Text.Length)
                        return tx.Text.Length - ty.Text.Length;

                    return string.Compare(tx.Text, ty.Text);
                };

                Array.Sort<TreeNode>(leafArray, compare);

                nodes.AddRange(leafArray);
            }

            foreach (TreeNode node in branches)
            {
                nodes.Add(node);
            }
        }
    }
}
