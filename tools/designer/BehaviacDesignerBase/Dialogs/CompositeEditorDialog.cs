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
using Behaviac.Design.Data;

namespace Behaviac.Design.Attributes
{
    public partial class CompositeEditorDialog : Form
    {
        public CompositeEditorDialog()
        {
            InitializeComponent();

            propertyGrid.PropertiesVisible(false, false);
            propertyGrid.ShowDescription(string.Empty, string.Empty);
            propertyGrid.ClearProperties();
        }

        DesignerArrayPropertyInfo _arrayProperty = null;
        DesignerStructPropertyInfo _structProperty = null;
        object _object = null;
        Nodes.Node _node = null;
        Label _selectedLabel = null;

        public void SetArrayProperty(DesignerArrayPropertyInfo arrayProperty, object obj)
        {
            Debug.Check(arrayProperty != null);

            _arrayProperty = arrayProperty;
            _object = obj;
            _node = _object as Nodes.Node;

            buildPropertyGrid();
        }

        public void SetStructProperty(DesignerStructPropertyInfo structProperty, object obj)
        {
            Debug.Check(structProperty != null);

            _structProperty = structProperty;
            _object = obj;
            _node = _object as Nodes.Node;

            buildPropertyGrid();
        }

        private void buildPropertyGrid(int selectedIndex = 0)
        {
            propertyGrid.PropertiesVisible(false, false);
            propertyGrid.ClearProperties();

            if (_arrayProperty != null)
            {
                _selectedLabel = null;

                if (_arrayProperty.ItemList.Count > 0)
                {
                    Type editorType = Plugin.InvokeEditorType(_arrayProperty.ItemType);
                    Debug.Check(editorType != null);

                    for (int index = 0; index < _arrayProperty.ItemList.Count; index++)
                    {
                        createArrayPropertyEditor(index, editorType, index == selectedIndex);
                    }

                    propertyGrid.UpdateSizes();
                    propertyGrid.PropertiesVisible(true, false);
                }
            }
            else if (_structProperty != null)
            {
                downButton.Visible = false;
                upButton.Visible = false;
                appendButton.Visible = false;
                insertButton.Visible = false;
                removeButton.Visible = false;
                //tableLayoutPanel.SetRowSpan(propertyGrid, tableLayoutPanel.RowCount - 1);
                //tableLayoutPanel.SetColumnSpan(propertyGrid, tableLayoutPanel.ColumnCount);

                Nodes.Action action = this._object as Nodes.Action;

                if (action == null)
                {
                    updateStructProperties(_structProperty.Owner);
                }
                else
                {
                    MethodDef method = action.Method;
                    if (method != null)
                    {
                        this.createParamEditor(_structProperty, action);
                    }
                }
            }
        }

        void createParamEditor(DesignerStructPropertyInfo structParam, Nodes.Action action)
        {
            MethodDef method = action.Method;
            List<MethodDef.Param> parameters = method.GetParams(structParam);
            foreach (MethodDef.Param p in parameters)
            {
                Type editorType = null;
                if (structParam.ElmentIndexInArray != -1)
                {
                    object member = p.Value;
                    editorType = p.Attribute.GetEditorType(member);
                }
                else
                {
                    editorType = typeof(DesignerParameterComboEnumEditor);
                }

                string arugmentsName = "    " + p.DisplayName;
                Label label = propertyGrid.AddProperty(arugmentsName, editorType, 
                    p.Attribute != null ? p.Attribute.HasFlags(DesignerProperty.DesignerFlags.ReadOnly) : false);
                label.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
                label.MouseEnter += label_MouseEnter;

                DesignerPropertyEditor editor = (DesignerPropertyEditor)label.Tag;
                editor.Enabled = true;
                //editor.SetRootNode(this._node);
                editor.SetParameter(p, action);
                editor.MouseEnter += new EventHandler(editor_MouseEnter);
                editor.ValueWasAssigned();
                editor.ValueWasChanged += editor_ValueWasChanged;
            }

            if (parameters.Count > 0)
            {
                propertyGrid.UpdateSizes();
                propertyGrid.PropertiesVisible(true, true);
            }
        }

        private void updateStructProperties(object owner)
        {
            IList<DesignerPropertyInfo> properties = DesignerProperty.GetDesignerProperties(_structProperty.Type, DesignerProperty.SortByDisplayOrder);

            List<string> categories = new List<string>();
            foreach (DesignerPropertyInfo property in properties)
            {
                if (!categories.Contains(property.Attribute.CategoryResourceString))
                    categories.Add(property.Attribute.CategoryResourceString);
            }
            categories.Sort();

            foreach (string category in categories)
            {
                if (categories.Count > 1)
                    propertyGrid.AddCategory(Plugin.GetResourceString(category), true);

                foreach (DesignerPropertyInfo property in properties)
                {
                    if (property.Attribute.CategoryResourceString == category)
                    {
                        object member = property.GetValue(owner);

                        Type type = property.Attribute.GetEditorType(member);
                        
                        Label label = propertyGrid.AddProperty(property.Attribute.DisplayName, type, property.Attribute.HasFlags(DesignerProperty.DesignerFlags.ReadOnly));
                        label.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
                        label.MouseEnter += new EventHandler(label_MouseEnter);

                        if (type != null)
                        {
                            DesignerPropertyEditor editor = (DesignerPropertyEditor)label.Tag;
                            editor.SetRootNode(this._node);
                            editor.SetProperty(property, owner);
                            editor.ValueWasAssigned();
                            editor.MouseEnter += editor_MouseEnter;
                            editor.ValueWasChanged += editor_ValueWasChanged;
                        }
                    }
                }
            }

            if (properties.Count > 0)
            {
                propertyGrid.UpdateSizes();
                propertyGrid.PropertiesVisible(true, true);
            }
        }

        private void label_MouseEnter(object sender, EventArgs e)
        {
            Label label = (Label)sender;
            DesignerPropertyEditor editor = (DesignerPropertyEditor)label.Tag;

            propertyGrid.ShowDescription(editor.DisplayName, editor.Description);
        }

        private void editor_MouseEnter(object sender, EventArgs e)
        {
            DesignerPropertyEditor editor = (DesignerPropertyEditor)sender;

            propertyGrid.ShowDescription(editor.DisplayName, editor.Description);
        }

        private void editor_ValueWasChanged(object sender, DesignerPropertyInfo property)
        {
            if (_node != null)
            {
                _node.OnPropertyValueChanged(true);

                UndoManager.Save(_node.Behavior);
            }

            //comment it as it disposed control and System.ObjectDisposedException might be raised
            //buildPropertyGrid();
        }

        private void selectLabel(Label label)
        {
            if (_selectedLabel != null)
            {
                _selectedLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
                _selectedLabel.ForeColor = Color.WhiteSmoke;
            }

            _selectedLabel = label;
            _selectedLabel.BackColor = Color.RoyalBlue;
            _selectedLabel.ForeColor = Color.White;
        }

        private int selectedIndex()
        {
            return (_selectedLabel != null) ? int.Parse(_selectedLabel.Text) : -1;
        }

        private void createArrayPropertyEditor(int itemIndex, Type editorType, bool isSelected)
        {
            Debug.Check(_arrayProperty != null);

            string propertyName = string.Format("{0}", itemIndex);
            Label label = propertyGrid.AddProperty(propertyName, editorType, _arrayProperty.ReadOnly);
            label.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            label.MouseClick += new MouseEventHandler(label_MouseClick);

            DesignerPropertyEditor editor = (DesignerPropertyEditor)label.Tag;
            if (Plugin.IsCustomClassType(_arrayProperty.ItemType))
            {
                editor.SetStructProperty(new DesignerStructPropertyInfo(
                    _arrayProperty.Name, _arrayProperty.ItemType, _arrayProperty.ItemList[itemIndex], itemIndex),
                    _object);
            }
            else
            {
                DesignerArrayPropertyInfo arrayProperty = new DesignerArrayPropertyInfo(_arrayProperty);
                arrayProperty.ItemIndex = itemIndex;

                editor.SetArrayProperty(arrayProperty, _object);
            }
            editor.ValueWasAssigned();
            editor.ValueWasChanged += editor_ValueWasChanged;

            if (isSelected)
                selectLabel(label);
        }

        private void label_MouseClick(object sender, MouseEventArgs e)
        {
            selectLabel((Label)sender);
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            Debug.Check(_arrayProperty != null);

            object item = Plugin.CreateInstance(_arrayProperty.ItemType);
            if (item != null)
            {
                Type editorType = Plugin.InvokeEditorType(_arrayProperty.ItemType);
                Debug.Check(editorType != null);

                int index = _arrayProperty.ItemList.Add(item);
                createArrayPropertyEditor(index, editorType, true);

                propertyGrid.UpdateSizes();
                propertyGrid.PropertiesVisible(true, false);

                if (_node != null)
                    _node.OnPropertyValueChanged(true);
            }
        }

        private void insertButton_Click(object sender, EventArgs e)
        {
            Debug.Check(_arrayProperty != null);

            int index = selectedIndex();
            if (index < 0)
                index = 0;

            object item = Plugin.CreateInstance(_arrayProperty.ItemType);
            if (item != null)
            {
                _arrayProperty.ItemList.Insert(index, item);

                buildPropertyGrid(index);

                if (_node != null)
                    _node.OnPropertyValueChanged(true);
            }
        }

        private void removeButton_Click(object sender, EventArgs e)
        {
            Debug.Check(_arrayProperty != null);

            int index = selectedIndex();
            if (index > -1)
            {
                _arrayProperty.ItemList.RemoveAt(index);

                if (index == _arrayProperty.ItemList.Count)
                    index--;

                buildPropertyGrid(index);

                if (_node != null)
                    _node.OnPropertyValueChanged(true);
            }
        }

        private void swapItems(int currentIndex, int otherIndex)
        {
            object item = _arrayProperty.ItemList[currentIndex];
            _arrayProperty.ItemList[currentIndex] = _arrayProperty.ItemList[otherIndex];
            _arrayProperty.ItemList[otherIndex] = item;

            buildPropertyGrid(otherIndex);

            if (_node != null)
                _node.OnPropertyValueChanged(true);
        }

        private void upButton_Click(object sender, EventArgs e)
        {
            Debug.Check(_arrayProperty != null);

            int index = selectedIndex();
            if (index > 0)
                swapItems(index, index - 1);
        }

        private void downButton_Click(object sender, EventArgs e)
        {
            Debug.Check(_arrayProperty != null);

            int index = selectedIndex();
            if (index > -1 && index < _arrayProperty.ItemList.Count - 1)
                swapItems(index, index + 1);
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
