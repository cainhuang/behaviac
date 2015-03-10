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
using PluginBehaviac.Properties;
using Behaviac.Design.Nodes;
using Behaviac.Design.Attributes;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("Goals", "task_icon")]
    public class Task : Behaviac.Design.Nodes.Sequence
	{
        public Task()
            : base(Resources.Task, Resources.TaskDesc)
		{
		}

        public override string ExportClass
        {
            get { return "Task"; }
        }

        public override bool AddChild(Connector connector, Node node)
        {
            if (node is Method)
            {
                return base.AddChild(connector, node);
            }
            else
            {
                Method Method = new Method();
                if (base.AddChild(connector, Method))
                {
                    Method.ResetId(false);
                    return Method.AddChild(Method.GetConnector("Action"), node);
                }
            }

            return false;
        }

        public override bool AddChild(Connector connector, Node node, int index)
        {
            if (node is Method)
            {
                return base.AddChild(connector, node, index);
            }
            else
            {
                Method Method = new Method();
                if (base.AddChild(connector, Method, index))
                {
                    Method.ResetId(false);
                    return Method.AddChild(Method.GetConnector("Action"), node);
                }
            }

            return false;
        }

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            foreach (BaseNode child in _genericChildren.Children)
            {
                if (!(child is Method))
                {
                    result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, Resources.TaskChildChildError));
                }
            }

            base.CheckForErrors(rootBehavior, result);
        }
	}
}
