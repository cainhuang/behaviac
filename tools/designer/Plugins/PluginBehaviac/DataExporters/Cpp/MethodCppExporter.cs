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
    public class MethodCppExporter
    {
        public static void GenerateClassConstructor(Behaviac.Design.MethodDef method, StreamWriter stream, string indent, string var)
        {
            for (int i = 0; i < method.Params.Count; ++i)
            {
                // const value
                if (!method.Params[i].IsProperty && !method.Params[i].IsPar)
                {
                    object obj = method.Params[i].Value;
                    if (obj != null)
                    {
                        string param = var + "_p" + i;
                        Type type = obj.GetType();
                        if (Plugin.IsArrayType(type))
                        {
                            string nativeType = DataCppExporter.GetGeneratedNativeType(method.Params[i].NativeType);
                            int startIndex = nativeType.IndexOf('<');
                            int endIndex = nativeType.LastIndexOf('>');
                            string itemType = nativeType.Substring(startIndex + 1, endIndex - startIndex - 1);

                            ArrayCppExporter.GenerateCode(obj, stream, indent + "\t\t\t", itemType, param);
                        }
                        else if (Plugin.IsCustomClassType(type))
                        {
                            if (DesignerStruct.IsPureConstDatum(obj, method, method.Params[i].Name))
                            {
                                StructCppExporter.GenerateCode(obj, stream, indent + "\t\t\t", param, null, "");
                            }
                        }
                        else
                        {
                            string nativeType = DataCppExporter.GetBasicGeneratedNativeType(method.Params[i].NativeType);
                            string retStr = DataCppExporter.GenerateCode(obj, stream, string.Empty, nativeType, string.Empty, string.Empty);
                            stream.WriteLine("{0}\t\t\t{1} = {2};", indent, param, retStr);
                        }
                    }
                }
            }
        }

        public static void GenerateClassMember(Behaviac.Design.MethodDef method, StreamWriter stream, string indent, string var)
        {
            for (int i = 0; i < method.Params.Count; ++i)
            {
                // const value
                if (!method.Params[i].IsProperty && !method.Params[i].IsPar)
                {
                    string basicNativeType = DataCppExporter.GetBasicGeneratedNativeType(method.Params[i].NativeType);
                    if (DataCppExporter.IsPtr(basicNativeType) && !DataCppExporter.IsAgentPtr((basicNativeType)))
                    {
                        basicNativeType = basicNativeType.Replace("*", "");
                        basicNativeType = basicNativeType.Trim();
                    }

                    string param = var + "_p" + i;
                    stream.WriteLine("{0}\t\t{1} {2};", indent, basicNativeType, param);
                }
            }
        }

        public static string GenerateCode(Behaviac.Design.MethodDef method, StreamWriter stream, string indent, string typename, string var, string caller)
        {
            string allParamTypes = string.Empty;
            string allParams = string.Empty;

            for (int i = 0; i < method.Params.Count; ++i)
            {
                string nativeType = DataCppExporter.GetGeneratedNativeType(method.Params[i].NativeType);
                bool isPointRefType = nativeType.EndsWith("*&");
                string basicNativeType = DataCppExporter.GetBasicGeneratedNativeType(nativeType);
                string param = (string.IsNullOrEmpty(var) ? caller : var) + "_p" + i;

                string paramBasicType = basicNativeType;
                if (!isPointRefType && DataCppExporter.IsPtr(paramBasicType))
                {
                    paramBasicType = paramBasicType.Replace("*", "");
                    paramBasicType = paramBasicType.Trim();
                }
                allParamTypes += ", " + paramBasicType;

                if (method.Params[i].IsProperty) // property
                {
                    param = ParameterCppExporter.GenerateCode(method.Params[i], stream, indent, basicNativeType, string.Empty, param);

                    if (!isPointRefType && DataCppExporter.IsPtr(basicNativeType))
                    {
                        param = "*" + param;
                    }
                }
                else
                {
                    if (method.Params[i].IsPar) // par
                    {
                        ParameterCppExporter.GenerateCode(method.Params[i], stream, indent, basicNativeType, param, caller);

                        if (!isPointRefType && DataCppExporter.IsPtr(basicNativeType))
                        {
                            param = "*" + param;
                        }
                    }
                    else // const value
                    {
                        object obj = method.Params[i].Value;
                        if (obj != null)
                        {
                            Type type = obj.GetType();
                            if (Plugin.IsCustomClassType(type) && !DesignerStruct.IsPureConstDatum(obj, method, method.Params[i].Name))
                            {
                                StructCppExporter.GenerateCode(obj, stream, indent, param, method, method.Params[i].Name);
                            }
                        }

                        if (!isPointRefType && DataCppExporter.IsAgentPtr(basicNativeType))
                        {
                            param = "*" + param;
                        }
                    }
                }

                if (i > 0)
                    allParams += ", ";

                allParams += param;
            }

            string agentName = "pAgent";
            if (method.Owner != Behaviac.Design.VariableDef.kSelf)
            {
                agentName = "pAgent_" + caller;

                stream.WriteLine("{0}Agent* {1} = Agent::GetInstance(\"{2}\", pAgent->GetContextId());", indent, agentName, method.Owner);
                stream.WriteLine("{0}BEHAVIAC_ASSERT({1});", indent, agentName);
            }

            //string retStr = string.Format("(({0}*){1})->{2}({3})", method.ClassName, agentName, method.Name, allParams);
            string nativeReturnType = DataCppExporter.GetGeneratedNativeType(method.NativeReturnType);
            string retStr = string.Format("(({0}*){1})->_Execute_Method_<{2}METHOD_TYPE_{3}, {4}{5} >({6})", method.ClassName, agentName, getNamespace(method.ClassName), method.Name.Replace("::", "_"), nativeReturnType, allParamTypes, allParams);

            if (!string.IsNullOrEmpty(var))
            {
                stream.WriteLine("{0}{1} {2} = {3};", indent, nativeReturnType, var, retStr);
            }

            return retStr;
        }

        public static void PostGenerateCode(Behaviac.Design.MethodDef method, StreamWriter stream, string indent, string typename, string var, string caller)
        {
            for (int i = 0; i < method.Params.Count; ++i)
            {
                if (!method.Params[i].NativeType.StartsWith("const ") && method.Params[i].NativeType.EndsWith("&"))
                {
                    string param = (string.IsNullOrEmpty(var) ? caller : var) + "_p" + i;
                    string nativeType = DataCppExporter.GetBasicGeneratedNativeType(method.Params[i].NativeType);
                    ParameterCppExporter.PostGenerateCode(method.Params[i], stream, indent, nativeType, param, caller, method);
                }
            }
        }

        private static string getNamespace(string className)
        {
            if (!string.IsNullOrEmpty(className))
            {
                int index = className.LastIndexOf(":");
                if (index > 1)
                    return className.Substring(0, index - 1) + "::";
            }

            return string.Empty;
        }
    }
}
