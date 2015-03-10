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
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using Behaviac.Design.Data;
using Behaviac.Design.Properties;
using Behaviac.Design.Attributes;

namespace Behaviac.Design
{
    internal partial class MetaStoreDock : Form
    {
        private enum MemberType
        {
            Method = 0,
            Property,
            Both
        }

        private static MetaStoreDock _metaStoreDock = null;

        List<MethodDef> _methods = new List<MethodDef>();
        List<PropertyDef> _properties = new List<PropertyDef>();

        internal static void Inspect()
        {
            if (_metaStoreDock == null)
            {
                _metaStoreDock = new MetaStoreDock();
            }

            _metaStoreDock.initialize();
            _metaStoreDock.Show();
        }

        internal static bool IsVisible()
        {
            return _metaStoreDock != null && _metaStoreDock.Visible;
        }

        public MetaStoreDock()
        {
            InitializeComponent();

            _metaStoreDock = this;
        }

        private void MetaStoreDock_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.Hide();

            e.Cancel = true;
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void initialize()
        {
            this.Text = Resources.MetaStore;
            if (BehaviorTreeViewDock.LastFocused != null)
                this.Text += " - " + BehaviorTreeViewDock.LastFocused.Text;

            // If the instance is Self or null, all members should be updated.
            if (this.instanceComboBox.SelectedIndex <= 0)
            {
                this.instanceComboBox.Items.Clear();
                this.memberTypeComboBox.Items.Clear();

                // set all class names
                this.instanceComboBox.Items.Add(VariableDef.kSelf);
                foreach (Plugin.InstanceName_t instanceName in Plugin.InstanceNames)
                {
                    this.instanceComboBox.Items.Add(instanceName.displayName_);
                }

                this.instanceComboBox.SelectedIndex = 0;

                // set all member types
                foreach (string mt in Enum.GetNames(typeof(MemberType)))
                {
                    this.memberTypeComboBox.Items.Add(mt);
                }

                this.memberTypeComboBox.SelectedIndex = 0;
            }
        }

        private void setMembers()
        {
            _methods.Clear();
            _properties.Clear();
            this.memberListBox.Items.Clear();

            if (this.instanceComboBox.SelectedIndex > -1 && this.memberTypeComboBox.SelectedIndex > -1)
            {
                AgentType agentType = null;

                // self
                if (this.instanceComboBox.SelectedIndex == 0)
                {
                    BehaviorTreeView focusedView = (BehaviorTreeViewDock.LastFocused != null) ? BehaviorTreeViewDock.LastFocused.BehaviorTreeView : null;
                    if (focusedView != null && focusedView.RootNode != null)
                    {
                        agentType = focusedView.RootNode.AgentType;
                    }
                }
                // global
                else
                {
                    agentType = Plugin.InstanceNames[this.instanceComboBox.SelectedIndex - 1].agentType_;
                }

                if (agentType != null)
                {
                    string filter = !string.IsNullOrEmpty(memberFilterTextBox.Text) ? memberFilterTextBox.Text.ToLowerInvariant() : string.Empty;

                    // method
                    if (this.memberTypeComboBox.SelectedIndex == 0 || this.memberTypeComboBox.SelectedIndex == 2)
                    {
                        IList<MethodDef> methods = agentType.GetMethods(MethodType.Method);
                        foreach (MethodDef m in methods)
                        {
                            string methodName = m.DisplayName.ToLowerInvariant();
                            if (memberFilterCheckBox.Checked && methodName.StartsWith(filter) ||
                                !memberFilterCheckBox.Checked && methodName.Contains(filter))
                            {
                                _methods.Add(m);
                                this.memberListBox.Items.Add(m.DisplayName + "()");
                            }
                        }
                    }

                    // property
                    if (this.memberTypeComboBox.SelectedIndex == 1 || this.memberTypeComboBox.SelectedIndex == 2)
                    {
                        IList<PropertyDef> properties = agentType.GetProperties();
                        foreach (PropertyDef p in properties)
                        {
                            string propName = p.DisplayName.ToLowerInvariant();
                            if (memberFilterCheckBox.Checked && propName.StartsWith(filter) ||
                                !memberFilterCheckBox.Checked && propName.Contains(filter))
                            {
                                _properties.Add(p);
                                this.memberListBox.Items.Add(p.DisplayName);
                            }
                        }
                    }
                }
            }

            this.memberCountLabel.Text = this.memberListBox.Items.Count.ToString();
        }

        private void instanceComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            setMembers();
        }

        private void memberTypeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            setMembers();
        }

        private void memberFilterTextBox_TextChanged(object sender, EventArgs e)
        {
            setMembers();
        }

        private void memberFilterCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            setMembers();
        }

        private void setDescription()
        {
            int index = memberListBox.SelectedIndex;
            if (index > -1)
            {
                if (_methods.Count > 0 && index < _methods.Count)
                {
                    memberDescLabel.Text = _methods[index].Description;
                }
                else if (_properties.Count > 0)
                {
                    index -= _methods.Count;
                    if (index > -1 && index < _properties.Count)
                        memberDescLabel.Text = _properties[index].Description;
                }
            }
        }

        private void memberListBox_MouseDown(object sender, MouseEventArgs e)
        {
            setDescription();

            if (memberListBox.SelectedItem != null)
            {
                string dragItem = (string)memberListBox.SelectedItem;
                if (dragItem.EndsWith("()"))
                {
                    dragItem = dragItem.Substring(0, dragItem.Length - 2);
                }

                memberListBox.DoDragDrop(dragItem, DragDropEffects.Move);
            }
        }

        private void memberListBox_KeyDown(object sender, KeyEventArgs e)
        {
            setDescription();
        }
    }
}
