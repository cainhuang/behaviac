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
using System.Drawing;
using Behaviac.Design;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attributes;
using PluginBehaviac.Properties;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("Conditions:Leaf", NodeIcon.Condition)]
    public class Condition : Behaviac.Design.Nodes.Condition
	{
        public Condition()
            : base(Resources.Condition, Resources.ConditionDesc)
		{
		}

        public override string ExportClass
        {
            get { return "Condition"; }
        }

        public override bool HasPrefixLabel
        {
            get { return false; }
        }

        //protected bool _negate = false;
        //[DesignerBoolean("ConditionNegate", "ConditionNegateDesc", "Condition", DesignerProperty.DisplayMode.List, -10, DesignerProperty.DesignerFlags.NoFlags)]
        //public bool Negate
        //{
        //    get { return _negate; }
        //    set { _negate = value; }
        //}

        private RightValueDef _opl;
        [DesignerRightValueEnum("OperandLeft", "OperandLeftDesc", "Condition", DesignerProperty.DisplayMode.Parameter, 0, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.AttributesMethod, MethodType.Getter, "", "Opr")]
        public RightValueDef Opl
        {
            get { return _opl; }
            set { this._opl = value; }
        }

        private OperatorType _operator = OperatorType.Equal;
        [DesignerEnum("Operator", "OperatorDesc", "Condition", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, "ConditionOperaptor")]
        public OperatorType Operator
        {
            get { return _operator; }
            set { _operator = value; }
        }

        private VariableDef _opr;
        [DesignerPropertyEnum("OperandRight", "OperandRightDesc", "Condition", DesignerProperty.DisplayMode.Parameter, 2, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.ConstAttributes, "Opl", "")]
        public VariableDef Opr
        {
            get { return _opr; }
            set { this._opr = value; }
        }

        public override void ResetMembers(AgentType agentType, bool resetPar)
        {
            if (this.Opl != null && this.Opl.ShouldBeReset(agentType, resetPar))
            {
                this.Opl = null;
            }

            if (this.Opr != null && this.Opr.ShouldBeReset(agentType, resetPar))
            {
                this.Opr = null;
            }

            base.ResetMembers(agentType, resetPar);
        }

        public override string Description
        {
            get
            {
                //not ideal, for the left node list
                if (_opl == null && _opr == null)
                {
                    return base.Description;
                }

                string str = base.Description;

                if (_opl != null)
                    str += "\n" + _opl.GetExportValue();

                str += "\n" + _operator.ToString();

                if (_opr != null)
                    str += "\n" + _opr.GetExportValue();

                return str;
            }
        }

        public override object[] GetExcludedEnums(DesignerEnum enumAttr)
        {
            if (enumAttr != null && enumAttr.ExcludeTag == "ConditionOperaptor")
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

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            Condition prec = (Condition)newnode;

            //prec._negate = _negate;
            if (_opl != null)
                prec._opl = (RightValueDef)_opl.Clone();
            if (_opr != null)
                prec._opr = (VariableDef)_opr.Clone();
            prec._operator = _operator;
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (this.Opl == null || this.Opr == null || this.Opl.ToString() == "" || this.Opr.ToString() == "")
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.OperatandIsNotComplete));
            }
            else if (this.Opl.ValueType != typeof(bool) && 
                (this.Operator == OperatorType.And || this.Operator == OperatorType.Or))
            {
                //and and or are only valid for bool
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.AndOrOnlyValidForBool));
            }

            base.CheckForErrors(rootBehavior, result);
        }
	}
}
