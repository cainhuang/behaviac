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
using Behaviac.Design.Nodes;
using PluginBehaviac.Properties;
using Behaviac.Design.Attributes;

namespace PluginBehaviac.Nodes
{
    [NodeDesc("Decorators", NodeIcon.Time)]
    public class DecoratorTime : Decorator
	{
        public DecoratorTime()
            : base(Resources.DecoratorTime, Resources.DecoratorTimeDesc)
		{
		}

        public override string ExportClass
        {
            get { return "DecoratorTime"; }
        }

        protected VariableDef _time = new VariableDef((int)0);
        [DesignerPropertyEnum("DecoratorTime", "DecoratorTimeDesc", "CategoryBasic", DesignerProperty.DisplayMode.Parameter, 0, DesignerProperty.DesignerFlags.NoFlags, DesignerPropertyEnum.AllowStyles.ConstAttributes, "", "")]
        public VariableDef Time
        {
            get { return _time; }
            set { this._time = value; }
        }

        protected override void CloneProperties(Node newnode)
        {
            base.CloneProperties(newnode);

            DecoratorTime dec = (DecoratorTime)newnode;
            if (_time != null)
                dec._time = (VariableDef)_time.Clone();
        }

        public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)
        {
            Type valueType = this._time.GetValueType();

            string typeName = Plugin.GetNativeTypeName(valueType.FullName);

            if (Plugin.IsIntergerNumberType(typeName))
            { }
            else
            {
                result.Add(new Node.ErrorCheck(this, ErrorCheckLevel.Error, "Time should be an integer number type!"));
            }

            base.CheckForErrors(rootBehavior, result);
        }
	}
}
