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
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.IO;
using System.Text;
using System.Windows.Forms;
using Behaviac.Design.Nodes;
using Behaviac.Design.Data;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    public partial class NodeTreeList : UserControl
    {
        private int _defaultIconCount = 0;
        private Timer toolTipTimer = new Timer();
        private TreeNode toolTipNode = null;

        public NodeTreeList()
        {
            InitializeComponent();

            _defaultIconCount = this.imageList.Images.Count;

            this.toolTipTimer.Interval = 1000;
            this.toolTipTimer.Tick += new EventHandler(toolTipTimer_Tick);
        }

        internal TreeView TreeView
        {
            get { return this.treeView; }
        }

        internal ImageList ImageList
        {
            get { return this.imageList; }
        }

        internal void Clear()
        {
            this.treeView.Nodes.Clear();

            for (int i = _defaultIconCount; i < this.imageList.Images.Count; ++i)
            {
                this.imageList.Images.RemoveAt(i);
                --i;
            }
        }

        internal void SetNodeList()
        {
            bool isDesignMode = (Plugin.EditMode == EditModes.Design);
            this.debugLabel.Visible = !isDesignMode;
            this.cancelButton.Visible = !isDesignMode;

            AgentInstancePool.AddInstanceHandler -= AgentInstancePool_AddInstanceHandler;

            if (!isDesignMode)
            {
                this.treeView.Nodes.Clear();
                setAgentTreeNode(this.treeView.Nodes);

                AgentInstancePool.AddInstanceHandler += AgentInstancePool_AddInstanceHandler;

                Plugin.DebugAgentHandler -= DebugAgentInstance_SetHandler;
                Plugin.DebugAgentHandler += DebugAgentInstance_SetHandler;
            }
        }

        private void DebugAgentInstance_SetHandler(string agentName)
        {
            if (string.IsNullOrEmpty(agentName))
                this.debugLabel.Text = Resources.DebugOperation;
            else
                this.debugLabel.Text = agentName;
        }

        private void setAgentTreeNode(TreeNodeCollection treeNodes)
        {
            foreach (AgentType agent in Plugin.AgentTypes)
            {
                if (!agent.IsInherited)
                {
                    string agentType = agent.ToString();
                    List<string> instances = AgentInstancePool.GetInstances(agentType);
                    if (instances != null && instances.Count > 0)
                    {
                        TreeNode agentTreeNode = treeNodes.Add(agentType, agentType, (int)NodeIcon.FolderClosed, (int)NodeIcon.FolderClosed);
                        foreach (string instance in instances)
                        {
                            agentTreeNode.Nodes.Add(agentType + "#" + instance, instance, (int)NodeIcon.FlagRed, (int)NodeIcon.FlagRed);
                        }
                    }
                }
            }
        }

        private void AgentInstancePool_AddInstanceHandler(string agentType, string agentName)
        {
            TreeNode agentTreeNode = this.treeView.Nodes[agentType];
            if (agentTreeNode == null)
                agentTreeNode = this.treeView.Nodes.Add(agentType, agentType, (int)NodeIcon.FolderClosed, (int)NodeIcon.FolderClosed);

            agentTreeNode.Nodes.Insert(agentTreeNode.GetNodeCount(false), agentType + "#" + agentName, agentName, (int)NodeIcon.FlagRed, (int)NodeIcon.FlagRed);
            agentTreeNode.Expand();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design)
                return;

            Plugin.DebugAgentInstance = string.Empty;
        }

        private bool isFoldNode(TreeNode treeNode)
        {
            return (treeNode != null && treeNode.ImageIndex == (int)NodeIcon.FolderClosed);
        }

        private void treeView_MouseUp(object sender, MouseEventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design || e.Button != MouseButtons.Right)
                return;

            TreeNode treeNode = this.treeView.SelectedNode;
            if (treeNode == null || isFoldNode(treeNode))
                return;

            this.parMenuItem.Visible = !Plugin.IsInstanceName(treeNode.Name);
            this.contextMenuStrip.Show(this, new Point(e.X, e.Y));
        }

        private void treeView_DoubleClick(object sender, EventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design)
                return;

            TreeNode treeNode = this.treeView.SelectedNode;
            if (treeNode == null)
                return;

            if (!isFoldNode(treeNode))
            {
                //this.debugLabel.Text = "Debug : " + treeNode.Text;
                Plugin.DebugAgentInstance = treeNode.Name;

                if (treeNode.Text != treeNode.Name)
                    ShowInstancePar();

                ShowInstanceProperty();
            }
        }

        private void expandButton_Click(object sender, EventArgs e)
        {
            this.treeView.ExpandAll();
        }

        private void collapseButton_Click(object sender, EventArgs e)
        {
            this.treeView.CollapseAll();
        }

        private void debugMenuItem_Click(object sender, EventArgs e)
        {
            if (Plugin.EditMode == EditModes.Design)
                return;

            treeView_DoubleClick(sender, e);
        }

        public void ShowInstancePar()
        {
            if (Plugin.EditMode == EditModes.Design)
                return;

            TreeNode treeNode = this.treeView.SelectedNode;
            if (treeNode == null)
                return;

            ParametersDock.Inspect(treeNode.Name, true);
        }

        public void ShowInstanceProperty()
        {
            if (Plugin.EditMode == EditModes.Design)
                return;

            TreeNode treeNode = this.treeView.SelectedNode;
            if (treeNode == null)
                return;

            ParametersDock.Inspect(treeNode.Name, false);
        }

        private void parMenuItem_Click(object sender, EventArgs e)
        {
            ShowInstancePar();
        }

        private void parameterMenuItem_Click(object sender, EventArgs e)
        {
            ShowInstanceProperty();
        }

        /// <summary>
        /// Handles when a tree node is dragged from the node explorer
        /// </summary>
        private void treeView_ItemDrag(object sender, ItemDragEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                TreeNode node = (TreeNode)e.Item;
                if (node.Tag is NodeTag)
                {
                    NodeTag nodetag = (NodeTag)node.Tag;
                    if (nodetag.Type == NodeTagType.Node || nodetag.Type == NodeTagType.Attachment)
                        DoDragDrop(e.Item, DragDropEffects.Move);
                }
            }
        }

        private void toolTipTimer_Tick(object sender, EventArgs e)
        {
            this.toolTipTimer.Stop();

            if (this.toolTipNode != null)
            {
                Point mousePos = this.treeView.PointToClient(Control.MousePosition);

                // Show the ToolTip if the mouse is still over the same node.
                if (this.toolTipNode.Bounds.Contains(mousePos))
                    this.toolTip.Show(this.toolTipNode.ToolTipText, this, mousePos);
            }
        }

        private void treeView_NodeMouseHover(object sender, TreeNodeMouseHoverEventArgs e)
        {
            this.toolTipTimer.Stop();
            this.toolTip.Hide(this);

            this.toolTipNode = e.Node;
            this.toolTipTimer.Start();
        }

        private void treeView_MouseLeave(object sender, EventArgs e)
        {
            this.toolTipNode = null;
            this.toolTipTimer.Stop();
            this.toolTip.Hide(this);
        }
    }
}
