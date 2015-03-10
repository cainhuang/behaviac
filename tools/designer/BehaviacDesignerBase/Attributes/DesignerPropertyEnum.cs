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
using System.Text;
using System.Globalization;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Attributes
{
    [AttributeUsage(AttributeTargets.Property)]
    public class DesignerPropertyEnum : DesignerProperty
    {
        [Flags]
        public enum AllowStyles 
        {
            None = 0, 
            Const = 1, 
            Par = 2,
            Self = 4,
            Global = 8, 
            SelfMethod = 16,
            GlobalMethod = 32,
            Attributes = Par | Self | Global,
            Method = SelfMethod | GlobalMethod,
            ConstAttributes = Const | Attributes,
            AttributesMethod = Attributes | Method,
            ConstAttributesMethod = Const | Attributes | Method
        }

        private string _dependedProperty = "";
        public string DependedProperty
        {
            get { return _dependedProperty; }
        }

        private string _dependingProperty = "";
        public string DependingProperty
        {
            get { return _dependingProperty; }
        }

        private AllowStyles _styles = AllowStyles.Self;
        public bool HasStyles(AllowStyles styles)
        {
            return (_styles & styles) == styles;
        }

        private double _minValue = double.MinValue;
        public double MinValue
        {
            get { return _minValue; }
        }

        private double _maxValue = double.MaxValue;
        public double MaxValue
        {
            get { return _maxValue; }
        }

        /// <summary>
        /// Creates a new designer attribute for handling a string value.
        /// </summary>
        /// <param name="displayName">The name shown on the node and in the property editor for the property.</param>
        /// <param name="description">The description shown in the property editor for the property.</param>
        /// <param name="category">The category shown in the property editor for the property.</param>
        /// <param name="displayMode">Defines how the property is visualised in the editor.</param>
        /// <param name="displayOrder">Defines the order the properties will be sorted in when shown in the property grid. Lower come first.</param>
        /// <param name="flags">Defines the designer flags stored for the property.</param>
        public DesignerPropertyEnum(string displayName, string description, string category, DisplayMode displayMode, int displayOrder, DesignerFlags flags, AllowStyles styles, string dependedProperty, string dependingProperty, ValueTypes filterType = ValueTypes.All, double min = double.MinValue, double max = double.MaxValue)
            : base(displayName, description, category, displayMode, displayOrder, flags, typeof(DesignerPropertyEnumEditor), null, filterType)
        {
            _styles = styles;
            _dependedProperty = dependedProperty;
            _dependingProperty = dependingProperty;
            _minValue = min;
            _maxValue = max;
        }

        public override string GetDisplayValue(object obj)
        {
            return DesignerPropertyUtility.RetrieveDisplayValue(obj, null, null);
        }

        public override string GetExportValue(object owner, object obj)
        {
            return DesignerPropertyUtility.RetrieveExportValue(obj, null, null);
        }

        public override object FromStringValue(NodeTag.DefaultObject node, object parentObject, Type type, string str)
        {
            if (type != typeof(VariableDef))
            {
                throw new Exception(Resources.ExceptionDesignerAttributeInvalidType);
            }

            if (str.Length == 0 ||
                str.Length == 2 && str == "\"\"")
            {
                return null;
            }

            if (!str.StartsWith("const"))
            {
                return this.parsePropertyVar(node, str);
            }
            else
            {
                return this.parseConstVar(node, parentObject, str);
            }

            //return null;
        }

        protected VariableDef parsePropertyVar(NodeTag.DefaultObject node, string str)
        {
            Debug.Check(!str.StartsWith("const"));

            string[] tokens = str.Split(' ');
            if (tokens.Length < 2)
                return null;

            string propertyType = string.Empty;
            string propertyName = string.Empty;
            if (tokens[0] == "static")
            {
                Debug.Check(tokens.Length == 3);

                //e.g. static int Property;
                propertyType = tokens[1];
                propertyName = tokens[2];
            }
            else
            {
                Debug.Check(tokens.Length == 2);

                //e.g. int Property;
                propertyType = tokens[0];
                propertyName = tokens[1];
            }

            VariableDef v = null;
            int pointIndex = propertyName.IndexOf('.');

            if (pointIndex > -1)
            {
                string ownerName = propertyName.Substring(0, pointIndex);
                propertyName = propertyName.Substring(pointIndex + 1, propertyName.Length - pointIndex - 1);

                AgentType agentType = node.Behavior.AgentType;
                agentType = Plugin.GetInstanceAgentType(ownerName, agentType);
                string valueType = (agentType == node.Behavior.AgentType) ? VariableDef.kSelf : agentType.ToString();

                v = setProperty(agentType, propertyName, valueType);
            }
            else
            {
                string className = Plugin.GetClassName(propertyName);

                // Assume it was World type.
                if (className != null)
                {
                    v = setProperty(Plugin.GetInstanceAgentType(className), propertyName, className);

                    if (v == null)
                    {
                        Nodes.Behavior behavior = node.Behavior as Nodes.Behavior;
                        if (behavior != null)
                        {
                            // Assume it was Agent type.
                            v = setProperty(behavior.AgentType, propertyName, VariableDef.kSelf);
                        }
                    }
                }
            }

            if (v == null)
            {
                // It should be Par type.
                v = setParameter(node, propertyType, propertyName);
            }

            return v;
        }

        protected VariableDef parseConstVar(NodeTag.DefaultObject node, object parentObject, string str)
        {
            Debug.Check(str.StartsWith("const"));

            //const Int32 1
            object propertyMemberDepended = null;
            Type objType = node.GetType();
            if (this.DependedProperty != "")
            {
                System.Reflection.PropertyInfo pi = objType.GetProperty(this.DependedProperty);

                if (pi != null)
                {
                    propertyMemberDepended = pi.GetValue(node, null);
                }
                else if (pi == null && parentObject != null)
                {
                    Type parentType = parentObject.GetType();
                    pi = parentType.GetProperty(this.DependedProperty);
                    propertyMemberDepended = pi.GetValue(parentObject, null);
                }
            }

            Type valueType = null;
            VariableDef variableDepended = propertyMemberDepended as VariableDef;
            if (variableDepended != null)
            {
                valueType = variableDepended.GetValueType();
            }
            else if (propertyMemberDepended != null)
            {
                MethodDef methodDepended = propertyMemberDepended as MethodDef;
                if (methodDepended != null)
                {
                    valueType = methodDepended.ReturnType;
                }
                else
                {
                    RightValueDef varRV = propertyMemberDepended as RightValueDef;
                    if (varRV != null)
                    {
                        valueType = varRV.ValueType;
                    }
                }
            }
            else
            {
                string[] tokens = str.Split(' ');
                Debug.Check(tokens.Length == 3);

                valueType = Plugin.GetTypeFromName(tokens[1]);
            }

            if (valueType != null)
            {
                VariableDef variable = new VariableDef(null);

                string[] tokens = str.Split(' ');
                Debug.Check(tokens.Length == 3);

                Plugin.InvokeTypeParser(valueType, tokens[2],
                    (object value) => variable.Value = value, 
                    node);

                return variable;
            }

            return null;
        }

        protected VariableDef setProperty(AgentType agentType, string propertyName, string valueType)
        {
            if (agentType != null)
            {
                IList<PropertyDef> properties = agentType.GetProperties();
                foreach (PropertyDef p in properties)
                {
                    if (p.Name == propertyName
#if BEHAVIAC_NAMESPACE_FIX
                        || p.Name.EndsWith(propertyName)
#endif
                        )
                    {
                        VariableDef v = new VariableDef(p, valueType);
                        return v;
                    }
                }
            }

            return null;
        }

        protected VariableDef setParameter(NodeTag.DefaultObject node, string propertyType, string propertyName)
        {
            List<ParInfo> allPars = new List<ParInfo>();
            ((Nodes.Node)node.Behavior).GetAllPars(ref allPars);
            if (allPars.Count > 0)
            {
                string fullname = string.Format("{0} {1}", propertyType, propertyName);
                foreach (ParInfo p in allPars)
                {
                    if (p.ToString() == fullname)
                    {
                        VariableDef v = new VariableDef(p);
                        v.SetValue(p, VariableDef.kPar);
                        return v;
                    }
                }
            }

            return null;
        }

        public override Type GetEditorType(object obj)
        {
            if (_styles == AllowStyles.Self)
                return typeof(DesignerPropertyEnumEditor);

            return typeof(DesignerPropertyComboEnumEditor);
        }
    }
}
