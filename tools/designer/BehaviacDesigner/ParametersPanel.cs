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
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.Reflection;
using Behaviac.Design.Attributes;
using Behaviac.Design.Data;
using Behaviac.Design.Network;

namespace Behaviac.Design
{
    public partial class ParametersPanel : UserControl
    {
        class RowControl
        {
            private System.Windows.Forms.Label _nameLabel;
            public System.Windows.Forms.Label NameLabel
            {
                get { return _nameLabel; }
                set { _nameLabel = value; }
            }

            private System.Windows.Forms.Label _typeLabel;
            public System.Windows.Forms.Label TypeLabel
            {
                get { return _typeLabel; }
                set { _typeLabel = value; }
            }

            private DesignerPropertyEditor _valueEditor;
            public DesignerPropertyEditor ValueEditor
            {
                get { return _valueEditor; }
                set { _valueEditor = value; }
            }
        }

        private List<RowControl> _rowControls = new List<RowControl>();
        private string _agentFullname = string.Empty;

        public ParametersPanel()
        {
            InitializeComponent();
        }

        public void InspectObject(AgentType agentType, string agentFullname, Nodes.Node node)
        {
            _agentFullname = agentFullname;

            preLayout();

            deleteAllRowControls();

            if (agentType != null)
            {
                IList<PropertyDef> properties = agentType.GetProperties();
                foreach (PropertyDef p in properties)
                {
                    addRowControl(p, null);
                }
            }
            else if (node != null)
            {
                List<ParInfo> allPars = node.Pars;
                foreach (ParInfo par in allPars)
                {
                    addRowControl(null, par);
                }
            }

            postLayout();
        }

        public bool SetProperty(string valueName, string valueStr)
        {
            DesignerPropertyEditor propertyEditor = getPropertyEditor(valueName);
            if (propertyEditor == null)
                return false;

            VariableDef var = propertyEditor.GetVariable();
            if (var.Value.ToString().ToLower() != valueStr.ToLower())
            {
                Plugin.InvokeTypeParser(var.GetValueType(), valueStr, (object value) => var.Value = value, null);

                propertyEditor.ValueWasnotAssigned();

                propertyEditor.SetVariable(var, null);

                propertyEditor.ValueWasAssigned();

                return true;
            }

            return false;
        }

        private void preLayout()
        {
            this.tableLayoutPanel.SuspendLayout();
            this.SuspendLayout();
        }

        private void postLayout()
        {
            this.tableLayoutPanel.ResumeLayout();
            this.tableLayoutPanel.PerformLayout();
            this.ResumeLayout();
            this.PerformLayout();
        }

        private DesignerPropertyEditor getPropertyEditor(string propertyName)
        {
            for (int i = 0; i < _rowControls.Count; ++i)
            {
                if (_rowControls[i].NameLabel.Text == propertyName)
                    return _rowControls[i].ValueEditor;
            }

            return null;
        }

        private int getRowIndex(DesignerPropertyEditor valueEditor)
        {
            for (int i = 0; i < _rowControls.Count; ++i)
            {
                if (_rowControls[i].ValueEditor == valueEditor)
                    return i;
            }

            return -1;
        }

        private DesignerPropertyEditor createPropertyEditor(PropertyDef property, ParInfo par)
        {
            Type type = (property != null) ? property.Type : par.Variable.GetValueType();
            Type editorType = Plugin.InvokeEditorType(type);
            Debug.Check(editorType != null);

            DesignerPropertyEditor editor = (DesignerPropertyEditor)editorType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[0]);
            editor.TabStop = false;
            editor.Dock = System.Windows.Forms.DockStyle.Fill;
            editor.Margin = new System.Windows.Forms.Padding(0);
            editor.ValueWasChanged += new DesignerPropertyEditor.ValueChanged(editor_ValueWasChanged);

            VariableDef var = (par != null && par.Variable != null) ? par.Variable : new VariableDef(Plugin.DefaultValue(type));
            editor.SetVariable(var, null);

            editor.ValueWasAssigned();

            return editor;
        }

        private void addRowControl(PropertyDef property, ParInfo par)
        {
            this.tableLayoutPanel.RowCount++;
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));

            int rowIndex = _rowControls.Count + 1;
            RowControl rowControl = new RowControl();
            _rowControls.Add(rowControl);

            rowControl.NameLabel = new System.Windows.Forms.Label();
            rowControl.NameLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.NameLabel.Margin = new System.Windows.Forms.Padding(0);
            rowControl.NameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            rowControl.NameLabel.Text = (property != null) ? property.Name : par.Name;
            this.tableLayoutPanel.Controls.Add(rowControl.NameLabel, 0, rowIndex);

            rowControl.TypeLabel = new System.Windows.Forms.Label();
            rowControl.TypeLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.TypeLabel.Margin = new System.Windows.Forms.Padding(0);
            rowControl.TypeLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            rowControl.TypeLabel.Text = Plugin.GetNativeTypeName((property != null) ? property.Type.ToString() : par.TypeName);
            this.tableLayoutPanel.Controls.Add(rowControl.TypeLabel, 1, rowIndex);

            rowControl.ValueEditor = createPropertyEditor(property, par);
            rowControl.ValueEditor.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.ValueEditor.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel.Controls.Add(rowControl.ValueEditor, 2, rowIndex);
        }

        private void deleteAllRowControls()
        {
            for (int rowIndex = _rowControls.Count - 1; rowIndex >= 0; --rowIndex)
            {
                RowControl rowControl = _rowControls[rowIndex];
                _rowControls.RemoveAt(rowIndex);

                this.tableLayoutPanel.RowStyles.RemoveAt(rowIndex);

                this.tableLayoutPanel.Controls.Remove(rowControl.NameLabel);
                this.tableLayoutPanel.Controls.Remove(rowControl.TypeLabel);
                if (rowControl.ValueEditor != null)
                    this.tableLayoutPanel.Controls.Remove(rowControl.ValueEditor);
            }

            this.tableLayoutPanel.RowCount = 1;
        }

        private void editor_ValueWasChanged(object sender, DesignerPropertyInfo property)
        {
            if (string.IsNullOrEmpty(_agentFullname))
                return;

            int index = getRowIndex(sender as DesignerPropertyEditor);
            if (index > -1)
            {
                RowControl row = _rowControls[index];
                
                VariableDef var = row.ValueEditor.GetVariable();
                if (var != null && var.Value != null)
                {
                    string value = var.Value.ToString();
                    if (!string.IsNullOrEmpty(value))
                    {
                        string valueType = row.TypeLabel.Text;
                        string valueName = row.NameLabel.Text;

                        if (AgentDataPool.CurrentFrame > -1)
                            AgentDataPool.AddValue(_agentFullname, valueName, AgentDataPool.CurrentFrame, value);

                        NetworkManager.Instance.SendProperty(_agentFullname, valueType, valueName, value);
                    }
                }
            }
        }

        private void lostAnyFocus()
        {
            this.Enabled = false;
            this.Enabled = true;
        }

        private void ParametersPanel_Click(object sender, EventArgs e)
        {
            lostAnyFocus();
        }

        private void tableLayoutPanel_Click(object sender, EventArgs e)
        {
            lostAnyFocus();
        }
    }
}
