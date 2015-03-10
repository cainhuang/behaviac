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
using System.Text;
using Behaviac.Design;
using Behaviac.Design.Attributes;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attachments;
using PluginBehaviac.Properties;

namespace PluginBehaviac.Events
{
    [NodeDesc("Attachments", NodeIcon.Event)]
    class Predicate : Behaviac.Design.Attachments.Predicate
    {
        public Predicate(Node node)
            : base(node, Resources.Predicate, Resources.PredicateDesc)
        {
        }

        public override string ExportClass
        {
            get { return "Predicate"; }
        }

        private RightValueDef _opl;
        [DesignerRightValueEnum("OperandLeft", "OperandLeftDesc", "Condition", DesignerProperty.DisplayMode.NoDisplay, 0, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.AttributesMethod, MethodType.Getter, "", "Opr")]
        public RightValueDef Opl
        {
            get { return _opl; }
            set { this._opl = value; }
        }

        private OperatorType _operator = OperatorType.Equal;
        [DesignerEnum("Operator", "OperatorDesc", "Condition", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, "")]
        public OperatorType Operator
        {
            get { return _operator; }
            set { _operator = value; }
        }

        private VariableDef _opr;
        [DesignerPropertyEnum("OperandRight", "OperandRightDesc", "Condition", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.ConstAttributes, "Opl", "")]
        public VariableDef Opr
        {
            get { return _opr; }
            set { this._opr = value; }
        }

        protected override string GeneratePropertiesLabel()
        {
            bool isFirstChild = (this.Node == null || this.Node.Attachments.Count == 0 || this.Node.Attachments[0] == this);
            string baseLabel = string.Empty;

            if (Opl != null)
                baseLabel += Opl.GetDisplayValue() + " ";

            System.Reflection.FieldInfo fi = Operator.GetType().GetField(Operator.ToString());
            Attribute[] attributes = (Attribute[])fi.GetCustomAttributes(typeof(EnumMemberDescAttribute), false);
            if (attributes.Length > 0)
                baseLabel += ((EnumMemberDescAttribute)attributes[0]).DisplayName;

            if (Opr != null)
                baseLabel += " " + Opr.GetDisplayValue();

            string propertiesLabel = string.Empty;

            if (isFirstChild)
            {
                propertiesLabel = baseLabel;
            }
            else
            {
                fi = BinaryOperator.GetType().GetField(BinaryOperator.ToString());
                attributes = (Attribute[])fi.GetCustomAttributes(typeof(EnumMemberDescAttribute), false);
                if (attributes.Length > 0)
                    propertiesLabel = ((EnumMemberDescAttribute)attributes[0]).DisplayName + "(" + baseLabel + ")";
            }

            return propertiesLabel;
        }

        public override object[] GetExcludedEnums(DesignerEnum enumAttr)
        {
            if (enumAttr != null && enumAttr.DisplayName == "Operator")
            {
                if (this.Opl != null)
                {
                    if (this.Opl.ValueType != typeof(bool))
                    {
                        //and and or are only valid for bool, so to exclude and and or when the type is not bool
                        object[] excludedOperators = new object[] { OperatorType.And, OperatorType.Or };

                        return excludedOperators;
                    }
                    else if (this.Opl.ValueType == typeof(bool))
                    {
                        object[] excludedOperators = new object[] { OperatorType.Greater, OperatorType.GreaterEqual, OperatorType.Less, OperatorType.LessEqual };

                        return excludedOperators;
                    }
                }
            }

            return null;
        }

        protected override void CloneProperties(Behaviac.Design.Attachments.Attachment newattach)
        {
            base.CloneProperties(newattach);

            Predicate prec = (Predicate)newattach;

            //prec._negate = _negate;
            if (this._opl != null)
            {
                prec._opl = (RightValueDef)this._opl.Clone();
            }

            if (this._opr != null)
            {
                prec._opr = (VariableDef)this._opr.Clone();
            }

            prec._operator = this._operator;
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<Node.ErrorCheck> result)
        {
            if (this.Opl == null || this.Opr == null)
            {
                result.Add(new Node.ErrorCheck(this.Node, this.Label, ErrorCheckLevel.Error, "Operand is not complete!"));
            }
            else if (this.Opl.ValueType != typeof(bool) &&
                (this.Operator == OperatorType.And || this.Operator == OperatorType.Or))
            {
                //and and or are only valid for bool
                result.Add(new Node.ErrorCheck(this.Node, this.Label, ErrorCheckLevel.Error, "And and Or are only valid for bool!"));
            }

            base.CheckForErrors(rootBehavior, result);
        }
	}
}
