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
using System.Windows.Forms;
using Behaviac.Design.Properties;
using Behaviac.Design.Attachments;

namespace Behaviac.Design.Attributes
{
    public partial class DesignerParamEnumEditor : Behaviac.Design.Attributes.DesignerPropertyEditor
    {
        public DesignerParamEnumEditor()
        {
            InitializeComponent();
        }

        public override void ReadOnly()
        {
            base.ReadOnly();
            comboBox.Enabled = false;
        }

        private MethodDef _method = null;
        List<MethodDef.Param> _params = new List<MethodDef.Param>();

        public override void SetPar(ParInfo par, object obj)
        {
            base.SetPar(par, obj);

            if (_object != null && _object is Event)
            {
                Event e = _object as Event;
                _method = e.EventName;

                setComboBox();
            }
        }

        private void setComboBox()
        {
            _params.Clear();
            comboBox.Items.Clear();

            if (_method != null && _par != null)
            {
                string selectedParam = string.Empty;
                if (!string.IsNullOrEmpty(_par.EventParam))
                {
                    string[] param = _par.EventParam.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                    selectedParam = param[param.Length - 1];
                }

                foreach (MethodDef.Param param in _method.Params)
                {
                    if (param.Type == _par.Type)
                    {
                        _params.Add(param);
                        comboBox.Items.Add(param.DisplayName);

                        if (param.Name == selectedParam)
                            comboBox.Text = param.DisplayName;
                    }
                }
            }
        }

        private void comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox.SelectedIndex < 0 || !_valueWasAssigned)
                return;

            if (_method != null && _par != null && comboBox.SelectedIndex > -1 && _params.Count > comboBox.SelectedIndex)
            {
                _par.EventParam = _method.Name + "::" + _params[comboBox.SelectedIndex].Name;
            }

            OnValueChanged(_property);

            this.RereshProperty(true, _property);
        }

        private void comboBox_MouseEnter(object sender, EventArgs e)
        {
            this.OnMouseEnter(e);
        }

        private void comboBox_DrawItem(object sender, DrawItemEventArgs e)
        {
            if (e.Index < 0)
                return;

            e.DrawBackground();
            e.Graphics.DrawString(comboBox.Items[e.Index].ToString(), e.Font, System.Drawing.Brushes.LightGray, e.Bounds);
            e.DrawFocusRectangle();

            MethodDef.Param param = _params[e.Index];
            this.OnDescriptionChanged(this.DisplayName, param.Description);
        }

        private void DesignerParamEnumEditor_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Control.ModifierKeys == Keys.Shift || Control.ModifierKeys == Keys.Control || Control.ModifierKeys == Keys.Alt)
                e.Handled = true;
        }
    }
}
