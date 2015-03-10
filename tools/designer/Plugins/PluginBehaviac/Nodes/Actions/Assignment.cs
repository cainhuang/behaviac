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
using Behaviac.Design.Attributes;
using PluginBehaviac.Properties;
using Behaviac.Design.Nodes;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("Actions", NodeIcon.Assignment)]
    public class Assignment : Behaviac.Design.Nodes.Node
	{
        public Assignment()
            : base(Resources.Assignment, Resources.AssignmentDesc)
		{
		}

        public override string ExportClass
        {
            get { return "Assignment"; }
        }

        public override bool HasPrefixLabel
        {
            get { return false; }
        }

        public override bool HasMiddleLabel
        {
            get { return true; }
        }

        private VariableDef _opl;
        [DesignerPropertyEnum("OperandLeft", "OperandLeftDesc", "Assignment", DesignerProperty.DisplayMode.Parameter, 0, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.Attributes, "", "Opr")]
        public VariableDef Opl
        {
            get { return _opl; }
            set { this._opl = value; }
        }

        private RightValueDef _opr;
        [DesignerRightValueEnum("OperandRight", "OperandRightDesc", "Assignment", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.ConstAttributesMethod, MethodType.Getter, "Opl", "")]
        public RightValueDef Opr
        {
            get { return _opr; }
            set { this._opr = value; }
        }

        public override string Description
        {
            get
            {
                string str = base.Description;
                if (_opl != null)
                    str += "\n" + _opl.GetExportValue();
                if (_opr != null)
                    str += "\n" + _opr.GetExportValue();

                return str;
            }
        }

        public override object[] GetExcludedEnums(DesignerEnum enumAttr)
        {
            return null;
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

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            Assignment prec = (Assignment)newnode;

            if (_opl != null)
                prec._opl = (VariableDef)_opl.Clone();

            if (_opr != null)
                prec._opr = (RightValueDef)_opr.Clone();
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (this.Opl == null || this.Opr == null || this.Opl.ToString() == "" || this.Opr.ToString() == "" || 
                this.Opl.GetValueType() != this.Opr.ValueType)
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.OperandError));
            }

            base.CheckForErrors(rootBehavior, result);
        }

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(157, 75, 39));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        public override NodeViewData CreateNodeViewData(NodeViewData parent, Behaviac.Design.Nodes.BehaviorNode rootBehavior)
        {
            NodeViewData nvd = base.CreateNodeViewData(parent, rootBehavior);
            nvd.ChangeShape(NodeShape.Rectangle);

            return nvd;
        }
	}
}
