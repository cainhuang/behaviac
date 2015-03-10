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
    public class AssignmentCsExporter : NodeCsExporter
    {
        protected override bool ShouldGenerateClass(Node node)
        {
            return true;
        }

        protected override void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            base.GenerateConstructor(node, stream, indent, className);

            Assignment assignment = node as Assignment;
            Debug.Check(assignment != null);

            if (assignment.Opr != null)
            {
                RightValueCsExporter.GenerateClassConstructor(assignment.Opr, stream, indent, "opr");
            }
        }

        protected override void GenerateMember(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMember(node, stream, indent);

            Assignment assignment = node as Assignment;
            Debug.Check(assignment != null);

            if (assignment.Opr != null)
            {
                RightValueCsExporter.GenerateClassMember(assignment.Opr, stream, indent, "opr");
            }
        }

        protected override void GenerateMethod(Node node, StreamWriter stream, string indent)
        {
            base.GenerateMethod(node, stream, indent);

            Assignment assignment = node as Assignment;
            Debug.Check(assignment != null);

            stream.WriteLine("{0}\t\tprotected override EBTStatus update_impl(behaviac.Agent pAgent, behaviac.EBTStatus childStatus)", indent);
            stream.WriteLine("{0}\t\t{{", indent);
            stream.WriteLine("{0}\t\t\tEBTStatus result = EBTStatus.BT_SUCCESS;", indent);

            if (assignment.Opl != null && assignment.Opr != null)
            {
                if (assignment.Opl.IsPar)
                {
                    ParInfo par = assignment.Opl.Value as ParInfo;
                    if (par != null)
                    {
                        RightValueCsExporter.GenerateCode(assignment.Opr, stream, indent + "\t\t\t", assignment.Opr.NativeType, "opr", "opr");
                        uint id = Behaviac.Design.CRC32.CalcCRC(par.Name);
                        stream.WriteLine("{0}\t\t\tDebug.Check(behaviac.Utils.MakeVariableId(\"{1}\") == {2}u);", indent, par.Name, id);
                        stream.WriteLine("{0}\t\t\tpAgent.SetVariable(\"{1}\", opr, {2}u);", indent, par.Name, id);
                    }
                }
                else
                {
                    Debug.Check(assignment.Opl.IsProperty);
                    RightValueCsExporter.GenerateCode(assignment.Opr, stream, indent + "\t\t\t", assignment.Opr.NativeType, "opr", "opr");
                    //VariableCsExporter.GenerateCode(assignment.Opl, stream, indent + "\t\t\t", string.Empty, string.Empty, "opl", "opr");
                    VariableCsExporter.PostGenerateCode(assignment.Opl, stream, indent + "\t\t\t", assignment.Opl.NativeType, "opl", string.Empty, null, "", "opr");
                }

                if (assignment.Opr.IsMethod)
                {
                    RightValueCsExporter.PostGenerateCode(assignment.Opr, stream, indent + "\t\t\t", assignment.Opr.NativeType, "opr", string.Empty);
                }
            }

            stream.WriteLine("{0}\t\t\treturn result;", indent);
            stream.WriteLine("{0}\t\t}}", indent);
        }
    }
}
