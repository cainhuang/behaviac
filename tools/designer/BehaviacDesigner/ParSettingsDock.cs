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
using System.Windows.Forms.Design;
using System.Reflection;
using Behaviac.Design.Data;
using Behaviac.Design.Nodes;
using Behaviac.Design.Properties;
using Behaviac.Design.Attributes;

namespace Behaviac.Design
{
    internal partial class ParSettingsDock : WeifenLuo.WinFormsUI.Docking.DockContent
    {
        enum SortTypes
        {
            Normal = 0,
            NameUp,
            NameDown,
            TypeUp,
            TypeDown,
            ValueUp,
            ValueDown,
            DescriptionUp,
            DescriptionDown
        }

        struct NameUpComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(x.Name, y.Name);
            }
        }

        struct NameDownComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(y.Name, x.Name);
            }
        }

        struct TypeUpComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(x.NativeType, y.NativeType);
            }
        }

        struct TypeDownComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(y.NativeType, x.NativeType);
            }
        }

        struct ValueUpComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(x.DefaultValue, y.DefaultValue);
            }
        }

        struct ValueDownComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(y.DefaultValue, x.DefaultValue);
            }
        }

        struct DescriptionUpComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(x.Description, y.Description);
            }
        }

        struct DescriptionDownComparer : IComparer<ParInfo>
        {
            public int Compare(ParInfo x, ParInfo y)
            {
                return string.Compare(y.Description, x.Description);
            }
        }

        class RowControl
        {
            private ParInfo _par;
            public ParInfo Par
            {
                get { return _par; }
                set { _par = value; }
            }

            private System.Windows.Forms.CheckBox _selectCheckBox;
            public System.Windows.Forms.CheckBox SelectCheckBox
            {
                get { return _selectCheckBox; }
                set { _selectCheckBox = value; }
            }

            private System.Windows.Forms.TextBox _nameTextBox;
            public System.Windows.Forms.TextBox NameTextBox
            {
                get { return _nameTextBox; }
                set { _nameTextBox = value; }
            }

            private System.Windows.Forms.TextBox _typeTextBox;
            public System.Windows.Forms.TextBox TypeTextBox
            {
                get { return _typeTextBox; }
                set { _typeTextBox = value; }
            }

            private DesignerPropertyEditor _defaultValueEditor;
            public DesignerPropertyEditor DefaultValueEditor
            {
                get { return _defaultValueEditor; }
                set { _defaultValueEditor = value; }
            }

            private System.Windows.Forms.TextBox _decsTextBox;
            public System.Windows.Forms.TextBox DescTextBox
            {
                get { return _decsTextBox; }
                set { _decsTextBox = value; }
            }

            public void Cleanup()
            {
                if (this._decsTextBox != null) this._decsTextBox.Dispose();
                if (this._defaultValueEditor != null) this._defaultValueEditor.Dispose();
                if (this._nameTextBox != null) this._nameTextBox.Dispose();
                if (this._selectCheckBox != null) this._selectCheckBox.Dispose();
                if (this._typeTextBox != null) this._typeTextBox.Dispose();
            }
        }

        private static ParSettingsDock _parDock = null;

        internal static void CloseAll()
        {
            if (_parDock != null)
                _parDock.Close();
        }

        internal static bool IsVisible()
        {
            return (_parDock != null) && _parDock.Visible;
        }

        internal static bool Inspect(Nodes.Node root)
        {
            if (_parDock == null)
            {
                _parDock = new ParSettingsDock();
                _parDock.Show(MainWindow.Instance.DockPanel, WeifenLuo.WinFormsUI.Docking.DockState.DockBottom);
            }
            else
            {
                _parDock.Show();
            }

            //_parDock.Clear();

            _parDock.Text = _parDock.TabText = (root == null) ? Resources.Pars : string.Format(Resources.ParsOf, root.Label);
            _parDock.setRootNode(root);

            return true;
        }

        internal static bool ReadOnly
        {
            set
            {
                if (_parDock != null)
                    _parDock.Enabled = !value;
            }
        }

        private Nodes.Node _rootNode = null;
        private bool _isParReady = false;
        private List<RowControl> _rowControls = new List<RowControl>();

        public ParSettingsDock()
        {
            InitializeComponent();

            this.TabText = this.Text;

            _parDock = this;

            ReadOnly = (Plugin.EditMode != EditModes.Design);

            this.Disposed += new EventHandler(ParSettingsDock_Disposed);
        }

        void ParSettingsDock_Disposed(object sender, EventArgs e)
        {
            this.Disposed -= ParSettingsDock_Disposed;

            Clear();
        }

        public void Clear()
        {
            foreach (RowControl r in _rowControls)
            {
                r.Cleanup();
            }

            _rowControls.Clear();
        }

        protected override void OnClosed(EventArgs e)
        {
            _parDock = null;

            base.OnClosed(e);
        }

        private void setRootNode(Nodes.Node root)
        {
            _isParReady = false;

            this.Hide();

            if (_rootNode != null)
            {
                for (int i = 0; i < _rootNode.Pars.Count; ++i)
                {
                    ParInfo parameter = _rootNode.Pars[i];
                    parameter.ParameterSet -= parameter_ParameterSet;
                }

                deleteAllRowControls();
            }

            _rootNode = root;

            if (_rootNode != null)
            {
                for (int i = 0; i < _rootNode.Pars.Count; ++i)
                {
                    ParInfo parameter = _rootNode.Pars[i];
                    parameter.ParameterSet -= parameter_ParameterSet;
                    parameter.ParameterSet += parameter_ParameterSet;

                    addRowControl(_rootNode.Pars[i]);
                }
            }

            this.Show();

            _isParReady = true;
        }

        private DesignerPropertyEditor createValueEditor(int rowIndex, Type type)
        {
            Debug.Check(rowIndex > -1 && type != null);

            RowControl rowControl = _rowControls[rowIndex];
            Type editorType = Plugin.InvokeEditorType(type);
            Debug.Check(editorType != null);

            DesignerPropertyEditor editor = (DesignerPropertyEditor)editorType.InvokeMember(string.Empty, BindingFlags.CreateInstance, null, null, new object[0]);
            editor.Dock = System.Windows.Forms.DockStyle.Fill;
            editor.Margin = new System.Windows.Forms.Padding(0);
            editor.ValueWasChanged += new DesignerPropertyEditor.ValueChanged(editor_ValueWasChanged);
            editor.SetPar(rowControl.Par, _rootNode);
            editor.ValueWasAssigned();

            if (rowControl.DefaultValueEditor != null)
                this.tableLayoutPanel.Controls.Remove(rowControl.DefaultValueEditor);
            rowControl.DefaultValueEditor = editor;
            this.tableLayoutPanel.Controls.Add(rowControl.DefaultValueEditor, 3, rowIndex + 1);

            return editor;
        }

        private int getRowIndex(CheckBox selectCheckBox, TextBox nameTextBox, TextBox typeTextBox, DesignerPropertyEditor editor, TextBox descTextBox)
        {
            for (int i = 0; i < _rowControls.Count; ++i)
            {
                if (selectCheckBox != null && _rowControls[i].SelectCheckBox == selectCheckBox ||
                    nameTextBox != null && _rowControls[i].NameTextBox == nameTextBox ||
                    typeTextBox != null && _rowControls[i].TypeTextBox == typeTextBox ||
                    editor != null && _rowControls[i].DefaultValueEditor == editor ||
                    descTextBox != null && _rowControls[i].DescTextBox == descTextBox)
                    return i;
            }

            return _rowControls.Count - 1;
        }

        private RowControl addRowControl(ParInfo par)
        {
            Debug.Check(par != null);

            RowControl rowControl = new RowControl();
            _rowControls.Add(rowControl);

            int rowIndex = _rowControls.Count;

            rowControl.Par = par;

            rowControl.SelectCheckBox = new System.Windows.Forms.CheckBox();
            rowControl.SelectCheckBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            rowControl.SelectCheckBox.ForeColor = System.Drawing.Color.LightGray;
            rowControl.SelectCheckBox.FlatAppearance.MouseDownBackColor = Color.DarkGray;
            rowControl.SelectCheckBox.FlatAppearance.MouseOverBackColor = Color.DarkGray;
            rowControl.SelectCheckBox.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.SelectCheckBox.CheckAlign = ContentAlignment.MiddleCenter;
            rowControl.SelectCheckBox.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel.Controls.Add(rowControl.SelectCheckBox, 0, rowIndex);

            rowControl.NameTextBox = new System.Windows.Forms.TextBox();
            rowControl.NameTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            rowControl.NameTextBox.ForeColor = System.Drawing.Color.LightGray;
            rowControl.NameTextBox.BorderStyle = BorderStyle.None;
            rowControl.NameTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.NameTextBox.Margin = new System.Windows.Forms.Padding(3);
            rowControl.NameTextBox.Text = par.Name;
            rowControl.NameTextBox.KeyDown += new KeyEventHandler(NameTextBox_KeyDown);
            rowControl.NameTextBox.LostFocus += new EventHandler(NameTextBox_LostFocus);
            this.tableLayoutPanel.Controls.Add(rowControl.NameTextBox, 1, rowIndex);

            rowControl.TypeTextBox = new System.Windows.Forms.TextBox();
            rowControl.TypeTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            rowControl.TypeTextBox.ForeColor = System.Drawing.Color.LightGray;
            rowControl.TypeTextBox.BorderStyle = BorderStyle.None;
            rowControl.TypeTextBox.ReadOnly = true;
            rowControl.TypeTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.TypeTextBox.Margin = new System.Windows.Forms.Padding(3);
            rowControl.TypeTextBox.Text = Plugin.GetNativeTypeName(par.Type, true);
            rowControl.TypeTextBox.MouseDoubleClick += new MouseEventHandler(TypeTextBox_MouseDoubleClick);
            this.tableLayoutPanel.Controls.Add(rowControl.TypeTextBox, 2, rowIndex);

            rowControl.DefaultValueEditor = createValueEditor(rowIndex - 1, par.Type);
            this.tableLayoutPanel.Controls.Add(rowControl.DefaultValueEditor, 3, rowIndex);

            rowControl.DescTextBox = new System.Windows.Forms.TextBox();
            rowControl.DescTextBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(65)))), ((int)(((byte)(65)))), ((int)(((byte)(65)))));
            rowControl.DescTextBox.ForeColor = System.Drawing.Color.LightGray;
            rowControl.DescTextBox.BorderStyle = BorderStyle.None;
            rowControl.NameTextBox.Height = 24;
            rowControl.DescTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            rowControl.DescTextBox.Margin = new System.Windows.Forms.Padding(3);
            rowControl.DescTextBox.Text = par.Description;
            rowControl.DescTextBox.KeyDown += new KeyEventHandler(DescTextBox_KeyDown);
            rowControl.DescTextBox.LostFocus += new EventHandler(DescTextBox_LostFocus);
            this.tableLayoutPanel.Controls.Add(rowControl.DescTextBox, 4, rowIndex);

            this.tableLayoutPanel.RowCount++;
            this.tableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));

            return rowControl;
        }

        private void deleteRowControl(int rowIndex)
        {
            RowControl rowControl = _rowControls[rowIndex];
            _rowControls.RemoveAt(rowIndex);

            rowIndex++;

            this.tableLayoutPanel.RowStyles.RemoveAt(rowIndex);

            this.tableLayoutPanel.Controls.Remove(rowControl.SelectCheckBox);
            this.tableLayoutPanel.Controls.Remove(rowControl.NameTextBox);
            this.tableLayoutPanel.Controls.Remove(rowControl.TypeTextBox);
            if (rowControl.DefaultValueEditor != null)
                this.tableLayoutPanel.Controls.Remove(rowControl.DefaultValueEditor);
            this.tableLayoutPanel.Controls.Remove(rowControl.DescTextBox);

            for (int r = rowIndex + 1; r < this.tableLayoutPanel.RowCount; ++r)
            {
                for (int c = 0; c < this.tableLayoutPanel.ColumnCount; ++c)
                {
                    Control control = this.tableLayoutPanel.GetControlFromPosition(c, r);
                    if (control != null)
                        this.tableLayoutPanel.SetRow(control, r - 1);
                }
            }

            this.tableLayoutPanel.RowCount--;
        }

        private void deleteAllRowControls()
        {
            for (int rowIndex = _rowControls.Count - 1; rowIndex >= 0; --rowIndex)
            {
                RowControl rowControl = _rowControls[rowIndex];
                _rowControls.RemoveAt(rowIndex);

                this.tableLayoutPanel.RowStyles.RemoveAt(rowIndex);

                this.tableLayoutPanel.Controls.Remove(rowControl.SelectCheckBox);
                this.tableLayoutPanel.Controls.Remove(rowControl.NameTextBox);
                this.tableLayoutPanel.Controls.Remove(rowControl.TypeTextBox);
                if (rowControl.DefaultValueEditor != null)
                    this.tableLayoutPanel.Controls.Remove(rowControl.DefaultValueEditor);
                this.tableLayoutPanel.Controls.Remove(rowControl.DescTextBox);

                rowControl.Cleanup();
            }

            this.tableLayoutPanel.RowCount = 1;
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            ParInfo par = new ParInfo(_rootNode);
            using (ParSettingsDialog parSettingsDialog = new ParSettingsDialog())
            {
                parSettingsDialog.SetPar(par, _rootNode, true);

                if (DialogResult.OK == parSettingsDialog.ShowDialog())
                {
                    par.ParameterSet -= parameter_ParameterSet;
                    par.ParameterSet += parameter_ParameterSet;

                    par.Copy(parSettingsDialog.GetPar());
                    _rootNode.Pars.Add(par);

                    _isParReady = false;
                    {
                        this.Hide();
                        addRowControl(par);
                        this.Show();
                    }
                    _isParReady = true;

                    PropertiesDock.UpdatePropertyGrids();
                    _rootNode.OnPropertyValueChanged(true);

                    UndoManager.Save((Nodes.Behavior)_rootNode);
                }
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            List<int> referredIndexes = new List<int>();
            List<int> deletedIndexes = new List<int>();
            List<Node.ErrorCheck> errorResult = new List<Node.ErrorCheck>();

            for (int rowIndex = _rowControls.Count - 1; rowIndex >= 0; --rowIndex)
            {
                RowControl rowControl = _rowControls[rowIndex];
                if (rowControl.SelectCheckBox.Checked)
                {
                    ParInfo par = _rootNode.Pars[rowIndex];

                    List<Node.ErrorCheck> result = new List<Node.ErrorCheck>();
                    Plugin.CheckPar(_rootNode, par, ref result);

                    if (result.Count > 0)
                    {
                        referredIndexes.Add(rowIndex);
                        errorResult.AddRange(result);
                    }
                    else
                    {
                        deletedIndexes.Add(rowIndex);
                    }
                }
            }

            if (referredIndexes.Count > 0)
            {
                errorResult.Reverse();
                referredIndexes.Reverse();

                string pars = string.Empty;
                for (int i = 0; i < referredIndexes.Count; ++i)
                {
                    int rowIndex = referredIndexes[i];
                    ParInfo par = _rootNode.Pars[rowIndex];

                    if (string.IsNullOrEmpty(pars))
                        pars += par.Name;
                    else
                        pars += ", " + par.Name;
                }

                Debug.Check(BehaviorTreeViewDock.LastFocused != null);
                string groupLabel = string.Format("Par(s) {0} can not be deleted, which the following nodes are using.", pars);
                BehaviorTreeViewDock.LastFocused.BehaviorTreeView.ShowErrorDialog("Par Delete Error", groupLabel, errorResult);
            }

            if (deletedIndexes.Count > 0)
            {
                for (int i = 0; i < deletedIndexes.Count; ++i)
                {
                    int rowIndex = deletedIndexes[i];
                    ParInfo par = _rootNode.Pars[rowIndex];
                    par.ParameterSet -= parameter_ParameterSet;

                    _rootNode.Pars.RemoveAt(rowIndex);

                    this.Hide();
                    deleteRowControl(rowIndex);
                    this.Show();

                    PropertiesDock.UpdatePropertyGrids();
                    _rootNode.OnPropertyValueChanged(true);
                }

                UndoManager.Save((Nodes.Behavior)_rootNode);
            }
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            for (int rowIndex = 0; rowIndex < _rowControls.Count; ++rowIndex)
            {
                RowControl rowControl = _rowControls[rowIndex];
                if (rowControl.SelectCheckBox.Checked)
                {
                    editSelectedPar(rowIndex);
                    break;
                }
            }
        }

        private void editSelectedPar(int rowIndex)
        {
            if (rowIndex < 0 || _rootNode == null)
                return;

            ParInfo par = _rootNode.Pars[rowIndex];

            List<Node.ErrorCheck> result = new List<Node.ErrorCheck>();
            Plugin.CheckPar(_rootNode, par, ref result);

            using (ParSettingsDialog parSettingsDialog = new ParSettingsDialog())
            {
                par.ParameterSet -= parameter_ParameterSet;
                parSettingsDialog.SetPar(par, _rootNode, false);

                Type preType = par.Type;
                string preName = par.Name;

                if (DialogResult.OK == parSettingsDialog.ShowDialog())
                {
                    UndoManager.PreSave();

                    ParInfo curPar = parSettingsDialog.GetPar();
                    Type curType = curPar.Type;
                    string curName = curPar.Name;

                    if (preType != curType)
                    {
                        // If this par is used by others
                        if (result.Count > 0)
                        {
                            string info = string.Format("Par {0} is used in some nodes. Are you sure change its type?", preName);
                            if (DialogResult.Cancel == MessageBox.Show(info, "Warning", MessageBoxButtons.OKCancel))
                            {
                                par.ParameterSet += parameter_ParameterSet;
                                return;
                            }
                        }

                        Plugin.ResetPar(_rootNode, par, string.Empty);
                    }
                    else if (preName != curName)
                    {
                        Plugin.ResetPar(_rootNode, par, curName);
                    }

                    par.Copy(curPar);

                    if (preType != curType)
                    {
                        RowControl rowControl = _rowControls[rowIndex];
                        rowControl.DefaultValueEditor = createValueEditor(rowIndex, curType);
                    }

                    par.ParameterSet += parameter_ParameterSet;
                    par.OnValueChanged();

                    PropertiesDock.UpdatePropertyGrids();
                    _rootNode.OnPropertyValueChanged(true);

                    UndoManager.Save((Nodes.Behavior)_rootNode);

                    UndoManager.PostSave();

                    BehaviorTreeView behaviorTreeView = BehaviorTreeViewDock.LastFocused.BehaviorTreeView;
                    if (behaviorTreeView != null)
                        behaviorTreeView.Redraw();
                }
                else
                {
                    par.ParameterSet += parameter_ParameterSet;
                }
            }
        }

        private void sortButton_Click(object sender, EventArgs e)
        {
            _sortType = (_sortType != SortTypes.NameUp) ? SortTypes.NameUp : SortTypes.NameDown;
            sortPars();
        }

        private void editor_ValueWasChanged(object sender, DesignerPropertyInfo property)
        {
            if (!_isParReady)
                return;

            UndoManager.PreSave();

            DesignerPropertyEditor editor = sender as DesignerPropertyEditor;
            int rowIndex = getRowIndex(null, null, null, editor, null);
            _rootNode.Pars[rowIndex].Variable = editor.GetVariable();

            _rootNode.OnPropertyValueChanged(true);

            UndoManager.Save((Nodes.Behavior)_rootNode);

            UndoManager.PostSave();
        }

        private void parameter_ParameterSet(Nodes.Node node, ParInfo par)
        {
            if (!_isParReady)
                return;

            RowControl rowControl = _rowControls.Find(delegate(RowControl row) { return row.Par == par; });
            if (rowControl != null)
            {
                rowControl.NameTextBox.Text = par.Name;
                rowControl.TypeTextBox.Text = Plugin.GetNativeTypeName(par.Type, true);
                rowControl.DefaultValueEditor.SetPar(par, node);
                rowControl.DescTextBox.Text = par.Description;
            }
        }

        private void setParName(TextBox nameTextBox)
        {
            int rowIndex = getRowIndex(null, nameTextBox, null, null, null);
            string newName = nameTextBox.Text.Trim();
            nameTextBox.Text = newName;
            if (!string.IsNullOrEmpty(newName) && _rootNode.Pars[rowIndex].Name != newName)
            {
                UndoManager.PreSave();

                Plugin.ResetPar(_rootNode, _rootNode.Pars[rowIndex], newName);
                _rootNode.Pars[rowIndex].Name = newName;

                PropertiesDock.UpdatePropertyGrids();
                _rootNode.OnPropertyValueChanged(true);

                UndoManager.Save((Nodes.Behavior)_rootNode);

                UndoManager.PostSave();

                BehaviorTreeView behaviorTreeView = BehaviorTreeViewDock.LastFocused.BehaviorTreeView;
                if (behaviorTreeView != null)
                    behaviorTreeView.Redraw();
            }
        }

        private void setParDesc(TextBox descTextBox)
        {
            int rowIndex = getRowIndex(null, null, null, null, descTextBox);
            if (_rootNode.Pars[rowIndex].Description != descTextBox.Text)
            {
                UndoManager.PreSave();

                _rootNode.Pars[rowIndex].Description = descTextBox.Text;

                _rootNode.OnPropertyValueChanged(true);

                UndoManager.Save((Nodes.Behavior)_rootNode);

                UndoManager.PostSave();
            }
        }

        private void NameTextBox_LostFocus(object sender, EventArgs e)
        {
            if (!_isParReady)
                return;

            TextBox nameTextBox = sender as TextBox;
            setParName(nameTextBox);
        }

        private void NameTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (!_isParReady)
                return;

            if (e.KeyCode == Keys.Enter)
            {
                TextBox nameTextBox = sender as TextBox;
                setParName(nameTextBox);
            }
        }

        private void TypeTextBox_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            System.Windows.Forms.TextBox textBox = sender as System.Windows.Forms.TextBox;
            int rowIndex = getRowIndex(null, null, textBox, null, null);

            editSelectedPar(rowIndex);
        }

        private void DescTextBox_LostFocus(object sender, EventArgs e)
        {
            if (!_isParReady)
                return;

            TextBox descTextBox = sender as TextBox;
            setParDesc(descTextBox);
        }

        private void DescTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (!_isParReady)
                return;

            if (e.KeyCode == Keys.Enter)
            {
                TextBox descTextBox = sender as TextBox;
                setParDesc(descTextBox);
            }
        }

        private SortTypes _sortType = SortTypes.Normal;

        private void sortPars()
        {
            if (_rootNode != null)
            {
                switch (_sortType)
                {
                    case SortTypes.NameUp:
                        _rootNode.Pars.Sort(new NameUpComparer());
                        break;

                    case SortTypes.NameDown:
                        _rootNode.Pars.Sort(new NameDownComparer());
                        break;

                    case SortTypes.TypeUp:
                        _rootNode.Pars.Sort(new TypeUpComparer());
                        break;

                    case SortTypes.TypeDown:
                        _rootNode.Pars.Sort(new TypeDownComparer());
                        break;

                    case SortTypes.ValueUp:
                        _rootNode.Pars.Sort(new ValueUpComparer());
                        break;

                    case SortTypes.ValueDown:
                        _rootNode.Pars.Sort(new ValueDownComparer());
                        break;

                    case SortTypes.DescriptionUp:
                        _rootNode.Pars.Sort(new DescriptionUpComparer());
                        break;

                    case SortTypes.DescriptionDown:
                        _rootNode.Pars.Sort(new DescriptionDownComparer());
                        break;
                }

                setRootNode(_rootNode);
            }
        }

        private void nameLabel_Click(object sender, EventArgs e)
        {
            _sortType = (_sortType != SortTypes.NameUp) ? SortTypes.NameUp : SortTypes.NameDown;
            sortPars();
        }

        private void typeLabel_Click(object sender, EventArgs e)
        {
            _sortType = (_sortType != SortTypes.TypeUp) ? SortTypes.TypeUp : SortTypes.TypeDown;
            sortPars();
        }

        private void defaultValueLabel_Click(object sender, EventArgs e)
        {
            //_sortType = (_sortType != SortTypes.ValueUp) ? SortTypes.ValueUp : SortTypes.ValueDown;
            //sortPars();
        }

        private void descLabel_Click(object sender, EventArgs e)
        {
            _sortType = (_sortType != SortTypes.DescriptionUp) ? SortTypes.DescriptionUp : SortTypes.DescriptionDown;
            sortPars();
        }
    }
}
