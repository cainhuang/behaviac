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
using System.Data;
using System.Drawing;
using System.Text;
using System.Reflection;
using System.Windows.Forms;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Attributes
{
    public partial class DesignerParComboEnumEditor : Behaviac.Design.Attributes.DesignerPropertyEditor
    {
        public DesignerParComboEnumEditor()
        {
            InitializeComponent();
        }

        public override void ReadOnly()
        {
            base.ReadOnly();

            this.typeComboBox.Enabled = false;
            if (this.propertyEditor != null)
                this.propertyEditor.ReadOnly();
        }

        private List<object> _values = new List<object>();

        public override void SetPar(ParInfo par, object obj)
        {
            Debug.Check(par != null);
            base.SetPar(par, obj);

            this.typeComboBox.Items.Clear();
            this.typeComboBox.Items.Add(VariableDef.kConst);
            this.typeComboBox.Items.Add(VariableDef.kEvent);

            this.typeComboBox.SelectedIndex = getComboIndex();

            //createEditor(getValueType());
        }

        public override string DisplayName
        {
            get { return (_par != null) ? _par.Name : base.DisplayName; }
        }

        private string getValueType()
        {
            return (_par == null || string.IsNullOrEmpty(_par.EventParam)) ? VariableDef.kConst : VariableDef.kEvent;
        }

        private int getComboIndex()
        {
            return (getValueType() == VariableDef.kConst) ? 0 : 1;
        }

        private Type getEditorType(string valueType)
        {
            return (valueType == VariableDef.kConst) ? typeof(DesignerParEditor) : typeof(DesignerParamEnumEditor);
        }

        private void setEditor(DesignerPropertyEditor editor, string valueType)
        {
            if (editor == null)
                return;

            if (valueType == VariableDef.kConst)
                _par.EventParam = null;

            editor.SetPar(_par, _object);
            editor.ValueWasAssigned();
        }

        private void createEditor(string valueType)
        {
            Type editorType = getEditorType(valueType);
            if (editorType == null)
                return;

            DesignerPropertyEditor editor = (DesignerPropertyEditor)editorType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[0]);
            editor.AutoSize = true;
            editor.Dock = System.Windows.Forms.DockStyle.Fill;
            editor.Location = new System.Drawing.Point(74, 1);
            editor.Margin = new System.Windows.Forms.Padding(0);
            editor.Size = new System.Drawing.Size(flowLayoutPanel.Width - this.typeComboBox.Width - 5, 20);
            editor.TabIndex = 1;

            setEditor(editor, valueType);

            if (flowLayoutPanel.Controls.Count > 1)
                flowLayoutPanel.Controls.RemoveAt(1);
            flowLayoutPanel.Controls.Add(editor);

            this.propertyEditor = editor;
            if (this.propertyEditor != null)
            {
                this.propertyEditor.MouseEnter += typeComboBox_MouseEnter;
                this.propertyEditor.DescriptionWasChanged += propertyEditor_DescriptionWasChanged;
            }
        }

        private void typeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.typeComboBox.SelectedItem != null)
            {
                createEditor((string)this.typeComboBox.SelectedItem);

                OnValueChanged(_property);
            }
        }

        private void flowLayoutPanel_Resize(object sender, EventArgs e)
        {
            if (this.propertyEditor != null)
                this.propertyEditor.Width = flowLayoutPanel.Width - this.typeComboBox.Width - 5;
        }

        private void typeComboBox_MouseEnter(object sender, EventArgs e)
        {
            this.OnMouseEnter(e);
        }

        private void propertyEditor_DescriptionWasChanged(string displayName, string description)
        {
            this.OnDescriptionChanged(displayName, description);
        }
    }
}
