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
using Behaviac.Design.Attachments;
using PluginBehaviac.DataExporters;

namespace PluginBehaviac.NodeExporters
{
    public class PredicateCsExporter : AttachmentCsExporter
    {
        protected override bool ShouldGenerateClass()
        {
            return true;
        }

        protected override void GenerateMethod(Behaviac.Design.Attachments.Attachment attachment, StreamWriter stream, string indent)
        {
            base.GenerateMethod(attachment, stream, indent);

            PluginBehaviac.Events.Predicate predicate = attachment as PluginBehaviac.Events.Predicate;
            Debug.Check(predicate != null);

            stream.WriteLine("{0}\t\tprotected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)", indent);
            stream.WriteLine("{0}\t\t{{", indent);
            stream.WriteLine("{0}\t\t\tEBTStatus result = EBTStatus.BT_FAILURE;", indent);

            // BinaryOperator
            switch (predicate.BinaryOperator)
            {
                case BinaryOperator.And:
                    stream.WriteLine("{0}\t\t\tthis.m_bAnd = true;", indent);
                    break;

                case BinaryOperator.Or:
                default:
                    stream.WriteLine("{0}\t\t\tthis.m_bAnd = false;", indent);
                    break;
            }

            string typeName = Plugin.GetNativeTypeName(predicate.Opl.ValueType);

            // opl
            RightValueCsExporter.GenerateCode(predicate.Opl, stream, indent + "\t\t\t", typeName, "opl", string.Empty);

            // opr
            VariableCsExporter.GenerateCode(predicate.Opr, stream, indent + "\t\t\t", typeName, "opr", string.Empty);

            // Operator
            switch (predicate.Operator)
            {
                case OperatorType.Equal:
                    stream.WriteLine("{0}\t\t\tbool op = opl == opr;", indent);
                    break;

                case OperatorType.NotEqual:
                    stream.WriteLine("{0}\t\t\tbool op = opl != opr;", indent);
                    break;

                case OperatorType.Greater:
                    stream.WriteLine("{0}\t\t\tbool op = opl > opr;", indent);
                    break;

                case OperatorType.GreaterEqual:
                    stream.WriteLine("{0}\t\t\tbool op = opl >= opr;", indent);
                    break;

                case OperatorType.Less:
                    stream.WriteLine("{0}\t\t\tbool op = opl < opr;", indent);
                    break;

                case OperatorType.LessEqual:
                    stream.WriteLine("{0}\t\t\tbool op = opl <= opr;", indent);
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
            stream.WriteLine("{0}\t\t\tif (op)", indent);
            stream.WriteLine("{0}\t\t\t\tresult = EBTStatus.BT_SUCCESS;", indent);

            stream.WriteLine("{0}\t\t\treturn result;", indent);
            stream.WriteLine("{0}\t\t}}", indent);
        }
    }
}
