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
using System.Drawing;
using Behaviac.Design.Attachments;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Nodes
{
    /// <summary>
    /// This node represents an action which can be attached to the behaviour tree.
    /// </summary>
    public class Action : Node
    {
        public Action(string label, string description)
            : base(label, description)
        {
        }

        private MethodDef _method = null;
        [DesignerMethodEnum("AgentMethod", "AgentMethodDesc", "Action", DesignerProperty.DisplayMode.Parameter, 1, DesignerProperty.DesignerFlags.NoFlags, MethodType.Method)]
        public MethodDef Method
        {
            get { return _method; }
            set { this._method = value; }
        }

        private EBTStatus _methodResultOption = EBTStatus.BT_INVALID;
        [DesignerEnum("StatusOption", "StatusOptionDesc", "Action", DesignerProperty.DisplayMode.NoDisplay, 2, DesignerProperty.DesignerFlags.NoFlags, "")]
        public EBTStatus ResultOption
        {
            get { return _methodResultOption; }
            set { _methodResultOption = value; }
        }

        private MethodDef _methodResultFunctor = null;
        [DesignerMethodEnum("StatusFunctor", "StatusFunctorDesc", "Action", DesignerProperty.DisplayMode.NoDisplay, 3, DesignerProperty.DesignerFlags.NoFlags, MethodType.Status, ValueTypes.All, "Method")]
        public MethodDef ResultFunctor
        {
            get { return _methodResultFunctor; }
            set { this._methodResultFunctor = value; }
        }

        private EBTStatus _preconditionFailedResult = EBTStatus.BT_FAILURE;
        [DesignerEnum("PreconditionFailResult", "PreconditionFailResultDesc", "Action", DesignerProperty.DisplayMode.NoDisplay, 4, DesignerProperty.DesignerFlags.NoFlags, "PreconditionFailResult")]
        public EBTStatus PreconditionFailResult
        {
            get { return _preconditionFailedResult; }
            set { _preconditionFailedResult = value; }
        }

        public override string Description
        {
            get
            {
                string str = base.Description;
                if (_method != null)
                    str += '\n' + _method.GetExportValue();

                return str;
            }
        }

        public override void ResetMembers(AgentType agentType, bool resetPar)
        {
            if (this.Method != null && this.Method.ShouldBeReset(agentType, resetPar))
            {
                this.Method = null;
            }

            if (this.ResultFunctor != null && this.ResultFunctor.ShouldBeReset(agentType, resetPar))
            {
                this.ResultFunctor = null;
            }

            base.ResetMembers(agentType, resetPar);
        }

        public override object[] GetExcludedEnums(DesignerEnum enumAttr)
        {
            if (enumAttr != null && enumAttr.ExcludeTag == "PreconditionFailResult")
            {
                //only success/failture are valid
                object[] status = new object[] { EBTStatus.BT_INVALID, EBTStatus.BT_RUNNING};

                return status;
            }

            return null;
        }
        
        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            Action right = (Action)newnode;

            if (_method != null)
                right._method = (MethodDef)_method.Clone();

            right._methodResultOption = _methodResultOption;

            if (_methodResultFunctor != null)
                right._methodResultFunctor = (MethodDef)_methodResultFunctor.Clone();
        }

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(157, 75, 39));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        public override NodeViewData CreateNodeViewData(NodeViewData parent, BehaviorNode rootBehavior)
        {
            NodeViewData nvd = base.CreateNodeViewData(parent, rootBehavior);
            nvd.ChangeShape(NodeShape.Rectangle);

            return nvd;
        }

        private static bool ms_NoResultTreatAsError = true;
        public static bool NoResultTreatAsError
        {
            set
            {
                ms_NoResultTreatAsError = value;
            }
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (this.Method == null
#if USE_NOOP
                || this.Method == MethodDef.Noop
#endif//#if USE_NOOP
)
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.NoMethod));
            }
            else
            {
                bool isParamCompleted = true;
                foreach (MethodDef.Param param in this.Method.Params)
                {
                    if (param.Value == null)
                    {
                        isParamCompleted = false;
                        break;
                    }
                }
                if (!isParamCompleted)
                {
                    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.NoParam));
                }

                if (this.Method.NativeReturnType != "behaviac::EBTStatus")
                {
                    if (EBTStatus.BT_INVALID == this.ResultOption)
                    {
                        if (this.ResultFunctor == null)
                        {
                            ErrorCheckLevel checkLevel = ms_NoResultTreatAsError ? ErrorCheckLevel.Error : ErrorCheckLevel.Warning;
                            result.Add(new Node.ErrorCheck(this, checkLevel, Resources.NoResultFunctor));
                        }
                        else if (!Plugin.IsMatchedStatusMethod(this.Method, this.ResultFunctor))
                        {
                            result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.WrongResultFunctor));
                        }
                    }
                }
            }

            base.CheckForErrors(rootBehavior, result);
        }
    }
}
