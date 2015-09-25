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
using System.IO;
using Behaviac.Design;
using Behaviac.Design.Nodes;
using PluginBehaviac.DataExporters;

namespace PluginBehaviac.NodeExporters
{
    public class ConditionCppExporter : NodeCppExporter
    {
        protected override bool ShouldGenerateClass(Node node)
        {
            return true;
        }

        protected override void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            base.GenerateConstructor(node, stream, indent, className);

            PluginBehaviac.Nodes.Condition condition = node as PluginBehaviac.Nodes.Condition;
            Debug.Check(condition != null);

            if (condition.Opl != null)
            {
                RightValueCppExporter.GenerateClassConstructor(condition.Opl, stream, indent, "opl");
            }

            if (condition.Opr != null)
            {
                VariableCppExporter.GenerateClassConstructor(condition.Opr, stream, indent, "opr");
            }
        }

        protected override void GenerateMember(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMember(node, stream, indent);

            PluginBehaviac.Nodes.Condition condition = node as PluginBehaviac.Nodes.Condition;
            Debug.Check(condition != null);

            if (condition.Opl != null)
            {
                RightValueCppExporter.GenerateClassMember(condition.Opl, stream, indent, "opl");
            }

            if (condition.Opr != null)
            {
                VariableCppExporter.GenerateClassMember(condition.Opr, stream, indent, "opr");
            }
        }

        protected override void GenerateMethod(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMethod(node, stream, indent);

            PluginBehaviac.Nodes.Condition condition = node as PluginBehaviac.Nodes.Condition;
            Debug.Check(condition != null);

            stream.WriteLine("{0}\t\tvirtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)", indent);
            stream.WriteLine("{0}\t\t{{", indent);
            stream.WriteLine("{0}\t\t\tBEHAVIAC_UNUSED_VAR(pAgent);", indent);
            stream.WriteLine("{0}\t\t\tBEHAVIAC_UNUSED_VAR(childStatus);", indent);

            string typeName = DataCppExporter.GetGeneratedNativeType(condition.Opl.ValueType);

            // opl
            RightValueCppExporter.GenerateCode(condition.Opl, stream, indent + "\t\t\t", typeName, "opl", string.Empty);
            if (condition.Opl.IsMethod)
            {
                RightValueCppExporter.PostGenerateCode(condition.Opl, stream, indent + "\t\t\t", typeName, "opl", string.Empty);
            }

            // opr
            VariableCppExporter.GenerateCode(condition.Opr, stream, indent + "\t\t\t", typeName, "opr", string.Empty);

            // Operator
            switch (condition.Operator)
            {
                case OperatorType.Equal:
                    stream.WriteLine("{0}\t\t\tbool op = Details::Equal(opl, opr);", indent);
                    break;

                case OperatorType.NotEqual:
                    stream.WriteLine("{0}\t\t\tbool op = !Details::Equal(opl, opr);", indent);
                    break;

                case OperatorType.Greater:
                    stream.WriteLine("{0}\t\t\tbool op = Details::Greater(opl, opr);", indent);
                    break;

                case OperatorType.GreaterEqual:
                    stream.WriteLine("{0}\t\t\tbool op = Details::GreaterEqual(opl, opr);", indent);
                    break;

                case OperatorType.Less:
                    stream.WriteLine("{0}\t\t\tbool op = Details::Less(opl, opr);", indent);
                    break;

                case OperatorType.LessEqual:
                    stream.WriteLine("{0}\t\t\tbool op = Details::LessEqual(opl, opr);", indent);
                    break;

                case OperatorType.And:
                    stream.WriteLine("{0}\t\t\tbool op = opl && opr;", indent);
                    break;

                case OperatorType.Or:
                    stream.WriteLine("{0}\t\t\tbool op = opl || opr;", indent);
                    break;

                default:
                    stream.WriteLine("{0}\t\t\tbool op = false;", indent);
                    break;
            }

            stream.WriteLine("{0}\t\t\treturn op ? BT_SUCCESS : BT_FAILURE;", indent);
            stream.WriteLine("{0}\t\t}}", indent);
        }
    }
}
