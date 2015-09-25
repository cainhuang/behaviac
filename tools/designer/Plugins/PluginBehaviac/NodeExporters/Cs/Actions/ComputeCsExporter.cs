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
using PluginBehaviac.Nodes;
using PluginBehaviac.DataExporters;

namespace PluginBehaviac.NodeExporters
{
    public class ComputeCsExporter : NodeCsExporter
    {
        protected override bool ShouldGenerateClass(Node node)
        {
            return true;
        }

        protected override void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            base.GenerateConstructor(node, stream, indent, className);

            Compute compute = node as Compute;
            Debug.Check(compute != null);

            if (compute.Opr1 != null)
            {
                RightValueCsExporter.GenerateClassConstructor(compute.Opr1, stream, indent, "opr1");
            }

            if (compute.Opr2 != null)
            {
                RightValueCsExporter.GenerateClassConstructor(compute.Opr2, stream, indent, "opr2");
            }
        }

        protected override void GenerateMember(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMember(node, stream, indent);

            Compute compute = node as Compute;
            Debug.Check(compute != null);

            if (compute.Opr1 != null)
            {
                RightValueCsExporter.GenerateClassMember(compute.Opr1, stream, indent, "opr1");
            }

            if (compute.Opr2 != null)
            {
                RightValueCsExporter.GenerateClassMember(compute.Opr2, stream, indent, "opr2");
            }
        }

        protected override void GenerateMethod(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMethod(node, stream, indent);

            Compute compute = node as Compute;
            Debug.Check(compute != null);

            stream.WriteLine("{0}\t\tprotected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)", indent);
            stream.WriteLine("{0}\t\t{{", indent);
            stream.WriteLine("{0}\t\t\tEBTStatus result = EBTStatus.BT_SUCCESS;", indent);

            if (compute.Opl != null && compute.Opr1 != null && compute.Opr2 != null)
            {
                RightValueCsExporter.GenerateCode(compute.Opr1, stream, indent + "\t\t\t", compute.Opr1.NativeType, "opr1", "opr1");
                RightValueCsExporter.GenerateCode(compute.Opr2, stream, indent + "\t\t\t", compute.Opr2.NativeType, "opr2", "opr2");

                string oprStr = string.Empty;
                switch (compute.Operator)
                {
                    case ComputeOperator.Add:
                        oprStr = "opr1 + opr2";
                        break;

                    case ComputeOperator.Sub:
                        oprStr = "opr1 - opr2";
                        break;

                    case ComputeOperator.Mul:
                        oprStr = "opr1 * opr2";
                        break;

                    case ComputeOperator.Div:
                        oprStr = "opr1 / opr2";
                        break;

                    default:
                        Debug.Check(false, "The operator is wrong!");
                        break;
                }

                string basicType = DataCsExporter.GetGeneratedNativeType(compute.Opl.NativeType);
                stream.WriteLine("{0}\t\t\t{1} opr = ({1})({2});", indent, basicType, oprStr);

                if (compute.Opl.IsPar)
                {
                    ParInfo par = compute.Opl.Value as ParInfo;
                    if (par != null)
                    {
                        uint id = Behaviac.Design.CRC32.CalcCRC(par.Name);
                        string typename = DataCsExporter.GetGeneratedNativeType(par.NativeType);
                        stream.WriteLine("{0}\t\t\tDebug.Check(behaviac.Utils.MakeVariableId(\"{1}\") == {2}u);", indent, par.Name, id);
                        stream.WriteLine("{0}\t\t\tpAgent.SetVariable<{1}>(\"{2}\", opr, {3}u);", indent, typename, par.Name, id);
                    }
                }
                else
                {
                    //VariableCsExporter.GenerateCode(compute.Opl, stream, indent + "\t\t\t", string.Empty, string.Empty, "opl", "opr");
                    VariableCsExporter.PostGenerateCode(compute.Opl, stream, indent + "\t\t\t", compute.Opl.NativeType, "opl", string.Empty, null, "", "opr");
                }

                if (compute.Opr1.IsMethod)
                {
                    RightValueCsExporter.PostGenerateCode(compute.Opr1, stream, indent + "\t\t\t", compute.Opr1.NativeType, "opr1", string.Empty);
                }

                if (compute.Opr2.IsMethod)
                {
                    RightValueCsExporter.PostGenerateCode(compute.Opr2, stream, indent + "\t\t\t", compute.Opr2.NativeType, "opr2", string.Empty);
                }
            }

            stream.WriteLine("{0}\t\t\treturn result;", indent);
            stream.WriteLine("{0}\t\t}}", indent);
        }
    }
}
