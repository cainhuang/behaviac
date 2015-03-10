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
using PluginBehaviac.Properties;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attributes;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("Goals", "method_icon")]
    public class Method : Behaviac.Design.Nodes.Node
	{
        protected ConnectorSingle _Precondition;
        protected ConnectorSingle _Action;
        protected ConnectorSingle _Effector;


        public Method()
            : base(Resources.Method, Resources.MethodDesc)
		{
            _Precondition = new ConnectorSingle(_children, Resources.MethodPrecondition, "Precondition");
            _Action = new ConnectorSingle(_children, Resources.MethodAction, "Action");
            _Effector = new ConnectorSingle(_children, Resources.MethodEffector, "Effector");
		}

        private readonly static Brush __defaultBackgroundBrush = new SolidBrush(Color.FromArgb(79, 129, 189));
        protected override Brush DefaultBackgroundBrush
        {
            get { return __defaultBackgroundBrush; }
        }

        public override string ExportClass
        {
            get { return "Method"; }
        }

        protected override bool CanBeAdoptedBy(BaseNode parent)
        {
            return (parent is Task);
        }

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            if (_Precondition.Child == null)
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, Resources.NoPreconditionError));
            }

            if (_Action.Child == null)
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, Resources.NoActionError));
            }

            //if (_Effector.Child == null)
            //{
            //    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Warning, Resources.NoEffectorError));
            //}

            if (!(this.Parent is Task))
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.MethodParentError));
            }

            base.CheckForErrors(rootBehavior, result);
        }
	}
}
