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

namespace PluginBehaviac.NodeExporters
{
    public class ReferencedBehaviorCppExporter : NodeCppExporter
    {
        protected override bool ShouldGenerateClass(Node node)
        {
            ReferencedBehavior referencedBehavior = node as ReferencedBehavior;
            return (referencedBehavior != null);
        }

        protected override void GenerateConstructor(Node node, StreamWriter stream, string indent, string className)
        {
            base.GenerateConstructor(node, stream, indent, className);

            ReferencedBehavior referencedBehavior = node as ReferencedBehavior;
            if (referencedBehavior == null)
                return;

            stream.WriteLine("{0}\t\t\tm_referencedBehaviorPath = \"{1}\";", indent, referencedBehavior.ReferenceFilename);
            stream.WriteLine("{0}\t\t\tbool result = Workspace::GetInstance()->Load(this->m_referencedBehaviorPath.c_str());", indent);
            stream.WriteLine("{0}\t\t\tBEHAVIAC_ASSERT(result);", indent);

            if (referencedBehavior.Task != null)
            {
                stream.WriteLine("{0}\t\t\tm_taskMethod = (CTaskMethod*)Action::LoadMethod(\"{1}\");", indent, referencedBehavior.Task.GetExportValue());
                stream.WriteLine("{0}\t\t\tBEHAVIAC_ASSERT(m_taskMethod);", indent);
            }
        }
    }
}
