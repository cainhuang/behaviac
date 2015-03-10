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
using Behaviac.Design.Data;

namespace Behaviac.Design.Attributes
{
    public partial class DesignerParEditor : Behaviac.Design.Attributes.DesignerPropertyEditor
    {
        public DesignerParEditor()
        {
            InitializeComponent();

            this.Disposed += DesignerParEditor_Disposed;
        }

        private void DesignerParEditor_Disposed(object sender, EventArgs e)
        {
            if (_par != null)
                _par.ParameterSet -= parameter_ParameterSet;
        }

        public override void ReadOnly()
        {
            base.ReadOnly();

            if (this.propertyEditor != null)
                this.propertyEditor.ReadOnly();
        }

        public override void SetPar(ParInfo par, object obj)
        {
            if (_par != null)
                _par.ParameterSet -= parameter_ParameterSet;

            base.SetPar(par, obj);

            if (_par != null)
            {
                _par.ParameterSet -= parameter_ParameterSet;
                _par.ParameterSet += parameter_ParameterSet;

                Size size = this.Size;
                this.propertyEditor = CreateEditor(_par.Type);
                if (this.propertyEditor != null)
                {
                    this.propertyEditor.SetPar(_par, obj);
                    this.propertyEditor.ValueWasAssigned();
                    this.ValueWasAssigned();

                    this.propertyEditor.ValueWasChanged += editor_ValueWasChanged;
                    this.propertyEditor.MouseEnter += propertyEditor_MouseEnter;

                    this.Size = size;
                }
            }
        }

        public override string DisplayName
        {
            get { return Resources.Par; }
        }

        public override string Description
        {
            get { return (_par != null && !string.IsNullOrEmpty(_par.Description)) ? _par.Description : Resources.ParInfo; }
        }

        private DesignerPropertyEditor CreateEditor(Type type)
        {
            this.Controls.Clear();

            if (type == null)
                return null;

            Type editorType = Plugin.InvokeEditorType(type);
            Debug.Check(editorType != null);

            DesignerPropertyEditor editor = (DesignerPropertyEditor)editorType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[0]);
            editor.AutoSize = true;
            editor.Dock = System.Windows.Forms.DockStyle.Fill;
            editor.Location = new System.Drawing.Point(0, 0);
            editor.Margin = new System.Windows.Forms.Padding(0);
            editor.TabIndex = 1;

            this.Controls.Add(editor);

            return editor;
        }

        private void editor_ValueWasChanged(object sender, DesignerPropertyInfo property)
        {
            if (this.propertyEditor != null)
            {
                UndoManager.PreSave();

                // Don't save Undo data here.
                _par.Variable = this.propertyEditor.GetVariable();

                UndoManager.PostSave();

                // Just save Undo data here.
                OnValueChanged(_property);
            }
        }

        private void parameter_ParameterSet(Nodes.Node node, ParInfo par)
        {
            SetPar(par, node);
        }

        private void propertyEditor_MouseEnter(object sender, EventArgs e)
        {
            this.OnMouseEnter(e);
        }
    }
}
