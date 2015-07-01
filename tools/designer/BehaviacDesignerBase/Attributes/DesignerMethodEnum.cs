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
using System.Globalization;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Attributes
{
    [Flags]
    public enum MethodType
    {
        None = 0, 

        //all the methods
        Method = 1,

        //getter is the method who returns something
        Getter = 2,

        //getter is the method who returns something plus the name event
        Event = 4,

        AllowNullMethod = 8,

        Status = 16
    }

    [AttributeUsage(AttributeTargets.Property)]
    public class DesignerMethodEnum : DesignerProperty
    {
        private MethodType _methodType;
        public MethodType MethodType
        {
            get
            {
                return this._methodType;
            }
        }

        private ValueTypes _methodReturnType;
        public ValueTypes MethodReturnType
        {
            get
            {
                return this._methodReturnType;
            }
        }
        
        /// <summary>
        /// Creates a new designer attribute for handling a string value.
        /// </summary>
        /// <param name="displayName">The name shown on the node and in the property editor for the property.</param>
        /// <param name="description">The description shown in the property editor for the property.</param>
        /// <param name="category">The category shown in the property editor for the property.</param>
        /// <param name="displayMode">Defines how the property is visualised in the editor.</param>
        /// <param name="displayOrder">Defines the order the properties will be sorted in when shown in the property grid. Lower come first.</param>
        /// <param name="flags">Defines the designer flags stored for the property.</param>
        public DesignerMethodEnum(string displayName, string description, string category, DisplayMode displayMode, int displayOrder, DesignerFlags flags, MethodType methodType, ValueTypes methodReturnType = ValueTypes.All, string linkedToProperty = "")
            : base(displayName, description, category, displayMode, displayOrder, flags, typeof(DesignerMethodComboEnumEditor), linkedToProperty)
        {
            _methodType = methodType;
            _methodReturnType = methodReturnType;
        }

        public override string GetDisplayValue(object obj)
        {
            if (obj == null)
                return string.Empty;

            MethodDef methodDef = obj as MethodDef;
            Debug.Check(methodDef != null);

            return methodDef.GetDisplayValue();
        }

        public override string GetExportValue(object owner, object obj)
        {
            if (obj == null)
                return "\"\"";

            MethodDef methodDef = obj as MethodDef;
            Debug.Check(methodDef != null);

            return methodDef.GetExportValue();
        }

        public override object FromStringValue(NodeTag.DefaultObject node, object parentObject, Type type, string str)
        {
            if (type != typeof(MethodDef))
                throw new Exception(Resources.ExceptionDesignerAttributeInvalidType);

            Nodes.Behavior behavior = node.Behavior as Nodes.Behavior;
            if (behavior != null && behavior.AgentType != null)
            {
                MethodDef method = parseMethodString(node, behavior.AgentType, this.MethodType, str);
                if (method == null)
                {
                    string className = Plugin.GetClassName(str);
                    method = parseMethodString(node, Plugin.GetInstanceAgentType(className), this.MethodType, str);
                }

                return method;
            }

            return null;
        }

        public static MethodDef parseMethodString(NodeTag.DefaultObject node, AgentType agentType, MethodType methodType, string str)
        {
            try
            {
                if (agentType != null)
                {
                    int pos = str.IndexOf('(');
                    if (pos < 0)
                        return null;

                    string ownerName = agentType.ToString();
                    int pointIndex = str.IndexOf('.');
                    if (pointIndex > -1 && pointIndex < pos)
                    {
                        ownerName = str.Substring(0, pointIndex);
                        str = str.Substring(pointIndex + 1, str.Length - pointIndex - 1);
                        agentType = Plugin.GetInstanceAgentType(ownerName, agentType);
                        //if (agentType == node.Behavior.AgentType)
                        //    ownerName = VariableDef.kSelf;
                        pos = str.IndexOf('(');
                    }

                    IList<MethodDef> actions = agentType.GetMethods(methodType);
                    string actionName = str.Substring(0, pos);
                    foreach (MethodDef actionTypeIt in actions)
                    {
                        if (actionTypeIt.Name == actionName
#if BEHAVIAC_NAMESPACE_FIX
                        || actionTypeIt.Name.EndsWith(actionName)
#endif
)
                        {
                            MethodDef method = new MethodDef(actionTypeIt);
                            method.Owner = ownerName;

                            List<string> paras = parseParams(str.Substring(pos + 1, str.Length - pos - 2));
                            //Debug.Check((paras.Count == actionTypeIt.Params.Count));

                            //if (paras.Count == actionTypeIt.Params.Count)
                            {
                                for (int i = 0; i < paras.Count; ++i)
                                {
                                    string param = paras[i];
                                    string[] tokens = null;
                                    if (param[0] == '\"')
                                    {
                                        param = param.Substring(1, param.Length - 2);
                                    }
                                    else if (param[0] == '{')
                                    {
                                        //struct

                                        //to set it as action.Method is used in the following parsing
                                        Nodes.Action action = node as Nodes.Action;
                                        if (action != null)
                                        {
                                            action.Method = method;
                                        }
                                    }
                                    else
                                    {
                                        tokens = param.Split(' ');
                                    }

                                    if (i < method.Params.Count)
                                    {
                                        MethodDef.Param par = method.Params[i];

                                        if (tokens != null && tokens.Length > 1)
                                        {
                                            //par
                                            VariableDef var = setParameter(node, tokens[tokens.Length - 1]);
                                            if (var != null)
                                                par.Value = var;
                                            //else
                                            //    throw new Exception(string.Format(Resources.ExceptionDesignerAttributeIllegalFloatValue, str));
                                        }
                                        else
                                        {
                                            bool bOk = Plugin.InvokeTypeParser(par.Type, param, (object value) => par.Value = value, node, par.Name);
                                            if (!bOk)
                                                throw new Exception(string.Format(Resources.ExceptionDesignerAttributeIllegalFloatValue, str));
                                        }
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }

                            return method;
                        }
                    }
                }
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(str, Resources.LoadError, System.Windows.Forms.MessageBoxButtons.OK);
            }

            return null;
        }

        //suppose params are seprated by ','
        static private List<string> parseParams(string tsrc)
	    {
            List<string> paras = new List<string>();
		    int tsrcLen = (int)tsrc.Length;
		    int startIndex = 0;
		    int index = 0;
		    int quoteDepth = 0;

		    for (; index < tsrcLen; ++index)
		    {
			    if (tsrc[index] == '"')
			    {
				    quoteDepth++;

                    //if (quoteDepth == 1)
                    //{
                    //    startIndex = index;
                    //}

				    if ((quoteDepth & 0x1) == 0)
				    {
					    //closing quote
					    quoteDepth -= 2;
					    Debug.Check(quoteDepth >= 0);
				    }
			    }
			    else if (quoteDepth == 0 && tsrc[index] == ',')
			    {
				    //skip ',' inside quotes, like "count, count"
				    int lengthTemp = index - startIndex;
                    string strTemp = tsrc.Substring(startIndex, lengthTemp);
                    paras.Add(strTemp);
				    startIndex = index + 1;
			    }
		    }//end for

		    // the last param
            if (index > startIndex)
		    {
                string strTemp = tsrc.Substring(startIndex, index - startIndex);
                paras.Add(strTemp);
		    }

            return paras;
	    }

        static private VariableDef createVariable(AgentType agentType, string instacneName, string propertyName)
        {
            agentType = Plugin.GetInstanceAgentType(instacneName, agentType);
            if (agentType != null)
            {
                IList<PropertyDef> properties = agentType.GetProperties();
                foreach (PropertyDef p in properties)
                {
                    if (p.Name == propertyName
#if BEHAVIAC_NAMESPACE_FIX
                        || p.Name.EndsWith(propertyName)
#endif
                        )
                        return new VariableDef(p, instacneName);
                }
            }

            return null;
        }

        static public VariableDef setParameter(NodeTag.DefaultObject node, string propertyName)
        {
            Behaviac.Design.Nodes.Behavior behavior = node.Behavior as Behaviac.Design.Nodes.Behavior;

            string instance = Plugin.GetInstanceName(propertyName);
            if (!string.IsNullOrEmpty(instance))
            {
                propertyName = propertyName.Substring(instance.Length + 1, propertyName.Length - instance.Length - 1);
                VariableDef var = createVariable(behavior.AgentType, instance, propertyName);
                if (var != null)
                    return var;
            }

            // Try to find the Par parameter with the name.
            List<ParInfo> allPars = new List<ParInfo>();
            ((Nodes.Node)behavior).GetAllPars(ref allPars);
            if (allPars.Count > 0)
            {
                foreach (ParInfo p in allPars)
                {
                    if (p.Name == propertyName
#if BEHAVIAC_NAMESPACE_FIX
                        || p.Name.EndsWith(propertyName)
#endif
                        )
                    {
                        VariableDef var = new VariableDef(p);
                        var.SetValue(p, VariableDef.kPar);
                        return var;
                    }
                }
            }

            // Try to find the Agent property with the name.
            if (behavior != null && behavior.AgentType != null)
            {
                IList<PropertyDef> properties = behavior.AgentType.GetProperties();
                foreach (PropertyDef p in properties)
                {
                    if (p.Name == propertyName
#if BEHAVIAC_NAMESPACE_FIX                        
                        || p.Name.EndsWith(propertyName)
#endif
                        )
                        return new VariableDef(p, VariableDef.kSelf);
                }
            }

            // Try to find the World property with the name.
            string instacneName = Plugin.GetClassName(propertyName);
            if (!string.IsNullOrEmpty(instacneName) && Plugin.GetInstanceAgentType(instacneName) != null)
            {
                IList<PropertyDef> properties = Plugin.GetInstanceAgentType(instacneName).GetProperties();
                foreach (PropertyDef p in properties)
                {
                    if (p.Name == propertyName
#if BEHAVIAC_NAMESPACE_FIX
                        || p.Name.EndsWith(propertyName)
#endif
                        )
                        return new VariableDef(p, instacneName);
                }
            }
        
            return null;
        }
    }
}
