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

namespace Behaviac.Design.Attributes
{
    public partial class DesignerParEnumEditor : Behaviac.Design.Attributes.DesignerPropertyEditor
    {
        public DesignerParEnumEditor()
        {
            InitializeComponent();
        }

        public override void ReadOnly()
        {
            base.ReadOnly();
            comboBox.Enabled = false;
        }

        List<ParInfo> _pars = new List<ParInfo>();

        public override void SetVariable(VariableDef value, object obj)
        {
            base.SetVariable(value, obj);

            string selectionName = "";
            if (value != null)
            {
                ParInfo par = value.Value as ParInfo;
                if (par != null)
                    selectionName = par.Name;
            }

            setComboBox(selectionName);
        }

        public override void SetParameter(MethodDef.Param param, object obj)
        {
            base.SetParameter(param, obj);

            if (param.IsFromStruct && (param.Type == typeof(VariableDef)))
            {
                VariableDef v = param.Value as VariableDef;
                FilterType = v.GetValueType();
            }
            else
            {
                FilterType = param.Type;
            }

            string[] tokens = param.Value.ToString().Split(' ');
            setComboBox(tokens[tokens.Length-1]);
        }

        private List<ParInfo> getPars()
        {
            List<ParInfo> pars = new List<ParInfo>();
            Nodes.Node node = _object as Nodes.Node;
            Attachments.Attachment attach = _object as Attachments.Attachment;

            if (node != null || attach != null || this._root != null)
            {
                Behaviac.Design.Nodes.BehaviorNode bn = (node != null ? node.Behavior : null);
                if (bn == null)
                {
                    bn = (attach != null ? attach.Behavior : null);
                }
                if (bn == null && this._root != null)
                {
                    bn = this._root.Behavior;
                }

                List<ParInfo> allPars = new List<ParInfo>();
                ((Nodes.Node)bn).GetAllPars(ref allPars);
                foreach (ParInfo par in allPars)
                {
                    if (!string.IsNullOrEmpty(par.Name))
                    {
                        if (Plugin.IsCompatibleType(FilterType, par.Type))
                            pars.Add(par);
                    }
                }
            }

            return pars;
        }

        private void setComboBox(string selectionName)
        {
            _pars = getPars();
            comboBox.Items.Clear();

            foreach (ParInfo par in _pars)
            {
                if (par.Name == selectionName)
                {
                    _pars.Clear();
                    _pars.Add(par);

                    comboBox.Items.Add(par.Name);
                    break;
                }
            }

            comboBox.Text = selectionName;
        }

        private void comboBox_DropDown(object sender, EventArgs e)
        {
            _pars = getPars();

            if (_pars.Count > 0)
            {
                if (string.IsNullOrEmpty(comboBox.Text))
                {
                    foreach (ParInfo par in _pars)
                    {
                        if (!comboBox.Items.Contains(par.Name))
                            comboBox.Items.Add(par.Name);
                    }
                }
                else
                {
                    int index = -1;
                    for (int i = 0; i < _pars.Count; ++i)
                    {
                        if (comboBox.Text == _pars[i].Name)
                        {
                            index = i;
                            break;
                        }
                    }

                    if (index > -1)
                    {
                        for (int i = index - 1; i >= 0; --i)
                        {
                            if (!comboBox.Items.Contains(_pars[i].Name))
                                comboBox.Items.Insert(0, _pars[i].Name);
                        }

                        for (int i = index + 1; i < _pars.Count; ++i)
                        {
                            if (!comboBox.Items.Contains(_pars[i].Name))
                                comboBox.Items.Add(_pars[i].Name);
                        }
                    }
                }
            }
        }

        private void comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox.SelectedIndex < 0 || !_valueWasAssigned)
                return;

            if (_variable != null)
            {
                _variable.SetValue(_pars[comboBox.SelectedIndex], VariableDef.kPar);
            }
            else if (_param != null)
            {
                _param.Value = _pars[comboBox.SelectedIndex];
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

            ParInfo par = _pars[e.Index];
            string description = !string.IsNullOrEmpty(par.Description) ? par.Description : par.ToString();
            this.OnDescriptionChanged(Resources.CategoryPar, description);
        }

        private void DesignerParEnumEditor_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Control.ModifierKeys == Keys.Shift || Control.ModifierKeys == Keys.Control || Control.ModifierKeys == Keys.Alt)
                e.Handled = true;
        }
    }
}
