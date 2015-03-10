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
using Behaviac.Design.Attributes;

namespace PluginBehaviac.DataExporters
{
    public class ParInfoCsExporter
    {
        public static string GenerateCode(Behaviac.Design.ParInfo par, StreamWriter stream, string indent, string typename, string var, string caller)
        {
            bool shouldDefineType = true;
            if (string.IsNullOrEmpty(typename))
            {
                shouldDefineType = false;
                typename = par.NativeType;
            }

            typename = DataCsExporter.GetGeneratedNativeType(typename);

            uint id = Behaviac.Design.CRC32.CalcCRC(par.Name);
            stream.WriteLine("{0}Debug.Check(behaviac.Utils.MakeVariableId(\"{1}\") == {2}u);", indent, par.Name, id);

            string retStr = string.Format("({0})pAgent.GetVariable({1}u)", typename, id);

            if (!string.IsNullOrEmpty(var))
            {
                if (shouldDefineType)
                    stream.WriteLine("{0}{1} {2} = {3};", indent, typename, var, retStr);
                else
                    stream.WriteLine("{0}{1} = {2};", indent, var, retStr);
            }

            return retStr;
        }

        public static void PostGenerateCode(Behaviac.Design.ParInfo par, StreamWriter stream, string indent, string typename, string var, string caller)
        {
            uint id = Behaviac.Design.CRC32.CalcCRC(par.Name);
            stream.WriteLine("{0}Debug.Check(behaviac.Utils.MakeVariableId(\"{1}\") == {2}u);", indent, par.Name, id);
            stream.WriteLine("{0}pAgent.SetVariable(\"{1}\", {2}, {3}u);", indent, par.Name, var, id);
        }
    }
}
