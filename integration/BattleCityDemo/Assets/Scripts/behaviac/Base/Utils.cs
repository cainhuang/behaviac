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

#if !BEHAVIAC_RELEASE
	#define BEHAVIAC_DEBUG
#endif

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.ComponentModel;
using System.Reflection;
using System.Diagnostics;
using UnityEngine;

namespace behaviac
{
    public struct CStringID
    {
        uint m_id;

        public CStringID(string str)
        {
            //SetId(str);
			m_id = CRC32.CalcCRC(str);
        }

        public void SetId(string str)
        {
			m_id = CRC32.CalcCRC(str);
        }

		public uint GetId()
		{
			return m_id;
		}

        public override bool Equals(System.Object obj)
        {
            // If parameter is null return false.
            if (obj == null)
            {
                return false;
            }

            // If parameter cannot be cast to Point return false.
			CStringID p = (CStringID)obj;

            // Return true if the fields match:
            return (m_id == p.m_id);
        }

        public bool Equals(CStringID p)
        {
            // If parameter is null return false:
            if (((object)p) == null)
            {
                return false;
            }

            // Return true if the fields match:
            return (m_id == p.m_id);
        }

        public override int GetHashCode()
        {
            return (int)m_id;
        }

        public static bool operator ==(CStringID a, CStringID b)
        {
            return a.m_id == b.m_id;
        }

        public static bool operator !=(CStringID a, CStringID b)
        {
            return a.m_id != b.m_id;
        }
    }

    public struct CSerializationID
    {
        public CSerializationID(string id)
        {
        }
    }

    public interface ISerializableNode
    {
        ISerializableNode newChild(CSerializationID chidlId);

        void setAttr(CSerializationID attrId, string value);

        void setAttr<VariableType>(CSerializationID attrId, VariableType value);
    }

    public struct CPropertyNode
    {
        public CPropertyNode(Agent agent, string className)
        {

        }
    }

    public class CMethodBase
    {
        behaviac.MethodMetaInfoAttribute descAttrbute_;
        private System.Reflection.MethodBase method_;

        public CMethodBase(System.Reflection.MethodBase m, behaviac.MethodMetaInfoAttribute a, string methodNameOverride)
        {
            method_ = m;
            descAttrbute_ = a;
            m_name = !string.IsNullOrEmpty(methodNameOverride) ? methodNameOverride : method_.Name;
            m_id.SetId(m_name);
        }

        protected CMethodBase(CMethodBase copy)
        {
            m_instanceName = copy.m_instanceName;
            m_parentType = copy.m_parentType;
            method_ = copy.method_;
            descAttrbute_ = copy.descAttrbute_;
            m_name = copy.m_name;
            m_id = copy.m_id;
        }

        private string m_name;

        public string Name
        {
            get
            {
                return m_name;
            }
        }

        public ParentType GetParentType()
        {
            return m_parentType;
        }

        private CStringID m_id = new CStringID();

        public CStringID GetId()
        {
            return m_id;
        }

        private string m_instanceName;

        public string GetInstanceNameString()
        {
            return m_instanceName;
        }

        private ParentType m_parentType = ParentType.PT_INVALID;

        public void SetInstanceNameString(string agentInstanceName, ParentType pt)
        {
            this.m_instanceName = agentInstanceName;
            this.m_parentType = pt;
        }

        public virtual Property CreateProperty(string defaultValue, bool bConst)
        {
            Property p = Property.Create(defaultValue, null, bConst);
            return p;
        }

        public void Load(Agent parent, List<string> paramsToken)
        {
            System.Reflection.ParameterInfo[] parameters = method_.GetParameters();

            //
            this.m_param_values = new object[parameters.Length];

            if (paramsToken.Count == parameters.Length)
            {
                this.m_params = new Param_t[parameters.Length];

                for (int i = 0; i < paramsToken.Count; ++i)
                {
                    System.Reflection.ParameterInfo para = parameters[i];

                    bool isStruct = paramsToken[i][0] == '{';

                    if (isStruct)
                    {
                        Dictionary<string, Property> props = new Dictionary<string, Property>();
                        string strT = "";
                        if (StringUtils.ParseForStruct(para.ParameterType, paramsToken[i], ref strT, props))
                        {
                            object paramValue = StringUtils.FromString(para.ParameterType, strT, false);
                            this.m_param_values[i] = paramValue;

                            this.m_params[i].paramStructMembers = props;
                        }
                    }
                    else
                    {
                        //paramsToken[i][0] = '"', then it is a string
                        bool isString = paramsToken[i][0] == '"';
                        if (isString || paramsToken[i].IndexOf(' ') == -1)
                        {
                            //" is paired
                            Debug.Check(!isString || paramsToken[i][paramsToken[i].Length - 1] == '"');
                            string paramStr = isString ? paramsToken[i].Substring(1, paramsToken[i].Length - 2) : paramsToken[i];

                            object paramValue = StringUtils.FromString(para.ParameterType, paramStr, false);
                            this.m_param_values[i] = paramValue;
                        }
                        else
                        {
                            string[] tokens = paramsToken[i].Split(' ');
                            if (tokens.Length == 2)
                            {
                                //int AgentTest::Property1
                                string typeName = tokens[0].Replace("::", ".");
                                Property paramProperty = Property.Create(typeName, tokens[1], null, false, false);
                                this.m_params[i].paramProperty = paramProperty;
                            }
                            else if (tokens.Length == 3)
                            {
                                //static int AgentTest::Property6
                                Debug.Check(tokens[0] == "static");
                                string typeName = tokens[1].Replace("::", ".");
                                Property paramProperty = Property.Create(typeName, tokens[2], null, true, false);
                                this.m_params[i].paramProperty = paramProperty;
                            }
                            else
                            {
                                Debug.Check(false);
                            }
                        }
                    }
                }
            }
            else
            {
                Debug.Check(false);
            }
        }

        public bool IsStatic()
        {
            return false;
        }

        public string GetName()
        {
            return this.m_name;
        }

        public string GetClassNameString()
        {
            if (this.IsNamedEvent())
            {
                return this.method_.DeclaringType.DeclaringType.FullName;
            }

            return this.method_.DeclaringType.FullName;
        }

        public virtual bool IsNamedEvent()
        {
            return false;
        }

        public virtual CMethodBase clone()
        {
            return new CMethodBase(this);
        }

        struct Param_t
        {
            public Property paramProperty;
            public Dictionary<string, Property> paramStructMembers;
        };

        private object[] m_param_values = null;
        private Param_t[] m_params = null;

        public object run(Agent parent, Agent parHolder)
        {
            //if there is no params, Load was not called and this.m_param_values is null
            //Debug.Check(this.m_param_values != null);

            if (this.m_params != null)
            {
                for (int i = 0; i < this.m_params.Length; ++i)
                {
                    Property property = this.m_params[i].paramProperty;
                    if (property != null)
                    {
                        this.m_param_values[i] = property.GetValue(parent, parHolder);
                    }

                    //Debug.Check(this.m_param_values[i] != null);

                    if (this.m_params[i].paramStructMembers != null)
                    {
                        Type structType = this.m_param_values[i].GetType();
                        Agent.CTagObjectDescriptor objectDesc = Agent.GetDescriptorByName(structType.FullName);

                        foreach (KeyValuePair<string, Property> pair in this.m_params[i].paramStructMembers)
                        {
                            CMemberBase member = objectDesc.GetMember(pair.Key);

                            object v = pair.Value.GetValue(parent, parHolder);

                            member.Set(this.m_param_values[i], v);
                        }
                    }
                }
            }

            object returnValue = this.method_.Invoke(parent, this.m_param_values);

            if (this.m_params != null)
            {
                for (int i = 0; i < this.m_params.Length; ++i)
                {
                    Property property = this.m_params[i].paramProperty;
                    if (property != null)
                    {
                        object value = this.m_param_values[i];
						property.SetValue(parHolder, value);
                    }

                    if (this.m_params[i].paramStructMembers != null)
                    {
                        Type structType = this.m_param_values[i].GetType();
                        Agent.CTagObjectDescriptor objectDesc = Agent.GetDescriptorByName(structType.FullName);

                        foreach (KeyValuePair<string, Property> pair in this.m_params[i].paramStructMembers)
                        {
                            CMemberBase member = objectDesc.GetMember(pair.Key);
                            object v = member.Get(this.m_param_values[i]);

							pair.Value.SetValue(parHolder, v);
                        }
                    }
                }
            }

            return returnValue;
        }

        public object run(Agent parent, Agent parHolder, object param)
        {
            Debug.Check(this.m_param_values != null && this.m_param_values.Length <= 1);
            if (this.m_param_values.Length == 1)
            {
                this.m_param_values[0] = param;
            }

            object returnValue = this.method_.Invoke(parent, this.m_param_values);

            return returnValue;
        }
    }

    public class CMemberBase
    {
        //behaviac.MemberMetaInfoAttribute descAttrbute_;
        System.Reflection.FieldInfo field_;

        public CMemberBase(System.Reflection.FieldInfo f, behaviac.MemberMetaInfoAttribute a)
        {
            field_ = f;
            //descAttrbute_ = a;
            m_id.SetId(field_.Name);

			if (a != null) 
			{
				m_range = a.Range;
			} 
			else 
			{
				m_range = 1.0f;
			}
        }

        public Type MemberType
        {
            get
            {
                return field_.FieldType;
            }
        }

        public bool ISSTATIC()
        {
            return field_.IsStatic;
        }

		private float m_range = 1.0f;
		public float GetRange()
		{
			return this.m_range;
		}

        public ParentType GetParentType()
        {
            return ParentType.PT_INVALID;
        }

        private CStringID m_id = new CStringID();

        public CStringID GetId()
        {
            return m_id;
        }

        public string GetName()
        {
            return this.field_.Name;
        }

        public string GetClassNameString()
        {
            return this.field_.DeclaringType.FullName;
        }

        private string m_instaceName;

        public string GetInstanceNameString()
        {
            return m_instaceName;
        }

        public void SetInstanceNameString(string name)
        {
            m_instaceName = name;
        }

        public virtual Property CreateProperty(string defaultValue, bool bConst)
        {
            Property p = new Property(this, bConst);

            if (!string.IsNullOrEmpty(defaultValue))
            {
                p.SetDefaultValue(defaultValue);
            }

            return p;
        }

        public virtual int GetTypeId()
        {
            return 0;
        }

        public virtual CMemberBase clone()
        {
            return null;
        }

        public virtual void Load(Agent parent, ISerializableNode node)
        {
        }

        public virtual void Save(Agent parent, ISerializableNode node)
        {
        }

        public virtual object Get(object agentFrom)
        {
            if (this.ISSTATIC())
            {
                return field_.GetValue(null);
            }
            else
            {
                return field_.GetValue(agentFrom);
            }
        }

        public void Set(object objectFrom, object v)
        {
            field_.SetValue(objectFrom, v);
        }
    }

    public class CNamedEvent : CMethodBase
    {
        public CNamedEvent(System.Reflection.MethodBase m, behaviac.EventMetaInfoAttribute a, string eventName)
            : base(m, a, eventName)
        {
        }

        private CNamedEvent(CNamedEvent copy) : base(copy)
        {
        }

        public override CMethodBase clone()
        {
            return new CNamedEvent(this);
        }

        public override bool IsNamedEvent()
        {
            return true;
        }

        bool IsFired()
        {
            return this.m_bFired;
        }

        bool        m_bFired;

        public void SetFired(Agent pAgent, bool bFired)
        {
            this.m_bFired = bFired;

            if (bFired)
            {
                pAgent.btonevent(this.Name);
            }
        }

        public void SetParam<ParamType>(Agent pAgent, ParamType param)
        {
            string eventName = string.Format("{0}::{1}::param0", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName, param);
        }

        public void SetParam<ParamType1, ParamType2>(Agent pAgent, ParamType1 param1, ParamType2 param2)
        {
            string eventName1 = string.Format("{0}::{1}::param0", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName1, param1);

            string eventName2 = string.Format("{0}::{1}::param1", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName2, param2);
        }

        public void SetParam<ParamType1, ParamType2, ParamType3>(Agent pAgent, ParamType1 param1, ParamType2 param2, ParamType3 param3)
        {
            string eventName1 = string.Format("{0}::{1}::param0", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName1, param1);

            string eventName2 = string.Format("{0}::{1}::param1", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName2, param2);

            string eventName3 = string.Format("{0}::{1}::param2", this.GetClassNameString().Replace(".", "::"), this.Name);
            pAgent.SetVariable(eventName3, param3);
        }
    }

    public enum E_VariableComparisonType
    {
        VariableComparisonType_Equal,           //( "Equal (==)" )
        VariableComparisonType_NotEqual,        //( "Not Equal (!=)" )
        VariableComparisonType_Greater,         //( "Greater (>)"  )
        VariableComparisonType_GreaterEqual,    //( "Greater Or Equal (>=)" )
        VariableComparisonType_Less,            //( "Lower (<)"  )
        VariableComparisonType_LessEqual,       //( "Lower Or Equal (<=)" )
        VariableComparisonType_And,             //( "Lower Or Equal (&&)" )
        VariableComparisonType_Or               //( "Lower Or Equal (||)" )
    }

    public class VariableComparator
    {
        public static E_VariableComparisonType ParseComparisonType(string comparionOperator)
        {
            if (comparionOperator == "Equal")
            {
                return E_VariableComparisonType.VariableComparisonType_Equal;
            }
            else if (comparionOperator == "NotEqual")
            {
                return E_VariableComparisonType.VariableComparisonType_NotEqual;
            }
            else if (comparionOperator == "Greater")
            {
                return E_VariableComparisonType.VariableComparisonType_Greater;
            }
            else if (comparionOperator == "GreaterEqual")
            {
                return E_VariableComparisonType.VariableComparisonType_GreaterEqual;
            }
            else if (comparionOperator == "Less")
            {
                return E_VariableComparisonType.VariableComparisonType_Less;
            }
            else if (comparionOperator == "LessEqual")
            {
                return E_VariableComparisonType.VariableComparisonType_LessEqual;
            }
            else
            {
                Debug.Check(false);
            }

            return E_VariableComparisonType.VariableComparisonType_Equal;
        }

        public VariableComparator(Property lhs, Property rhs)
        {
            m_lhs = lhs;
            m_rhs = rhs;
        }

        VariableComparator(VariableComparator copy)
        {
            m_lhs = copy.m_lhs;
            m_rhs = copy.m_rhs;
        }

        ~VariableComparator ()
        {
            m_lhs = null;
            m_rhs = null;
        }

        public VariableComparator clone()
        {
            return new VariableComparator(this);
        }

        public static VariableComparator Create(string typeName, Property lhs, Property rhs)
        {
            return new VariableComparator(lhs, rhs);
        }

        //virtual void Serialize( Serializer& serializer ) = 0;
        public bool Execute(Agent agentL, Agent agentR)
        {
            object lhs = this.m_lhs.GetValue(agentL);
            object rhs = this.m_rhs.GetValue(agentR);

            switch (this.m_comparisonType)
            {
                case E_VariableComparisonType.VariableComparisonType_Equal:
                    if (System.Object.ReferenceEquals(lhs, null))
                    {
                        return System.Object.ReferenceEquals(rhs, null);
                    }
                    else
                    {
                        return lhs.Equals(rhs);
                    }

                case E_VariableComparisonType.VariableComparisonType_NotEqual:
                    if (System.Object.ReferenceEquals(lhs, null))
                    {
                        return !System.Object.ReferenceEquals(rhs, null);
                    }
                    else
                    {
                        return !lhs.Equals(rhs);
                    }

                case E_VariableComparisonType.VariableComparisonType_Greater:
                    return Details.Greater(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_GreaterEqual:
                    return Details.GreaterEqual(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_Less:
                    return Details.Less(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_LessEqual:
                    return Details.LessEqual(lhs, rhs);

                default:
                    Debug.Check(false, "Unsupported comparison type");
                    break;
            }

            return false;
        }

        public bool Execute(object lhs, Agent parent, Agent agentR)
        {
            object rhs = this.m_rhs.GetValue(agentR);

            switch (this.m_comparisonType)
            {
                case E_VariableComparisonType.VariableComparisonType_Equal:
                    return lhs.Equals(rhs);

                case E_VariableComparisonType.VariableComparisonType_NotEqual:
                    return !lhs.Equals(rhs);

                case E_VariableComparisonType.VariableComparisonType_Greater:
                    return Details.Greater(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_GreaterEqual:
                    return Details.GreaterEqual(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_Less:
                    return Details.Less(lhs, rhs);

                case E_VariableComparisonType.VariableComparisonType_LessEqual:
                    return Details.LessEqual(lhs, rhs);

                default:
                    Debug.Check(false, "Unsupported comparison type");
                    break;
            }

            return false;
        }

        void SetProperty(Property lhs, Property rhs)
        {
            m_lhs = lhs;
            m_rhs = rhs;
        }

        public void SetComparisonType(E_VariableComparisonType type)
        {
            m_comparisonType = type;
        }

        E_VariableComparisonType GetComparisonType()
        {
            return m_comparisonType;
        }

        protected Property m_lhs;
        protected Property m_rhs;
        //The operator used in the comparison
        protected E_VariableComparisonType m_comparisonType;
    }

    public class CTextNode
    {
        public CTextNode(string name)
        {
        }

        public void setAttr(string attrName, string attrValue)
        {
        }
    }

    static public class Utils
    {
        public static bool IsNull(System.Object aObj)
        {
            return aObj == null || aObj.Equals(null);
        }

		public static bool IsStaticType(Type type)
		{
			return type != null && type.IsAbstract && type.IsSealed;
		}
		
		private static Dictionary<string, bool> ms_staticClasses;
		private static Dictionary<string, bool> StaticClasses
		{
			get
			{
				if (ms_staticClasses == null)
				{
					ms_staticClasses = new Dictionary<string, bool>();
				}
				return ms_staticClasses;
			}
		}

		public static void AddStaticClass(Type type)
		{
			if (Utils.IsStaticType(type))
				Utils.StaticClasses[type.FullName] = true;
		}

		public static bool IsStaticClass(string className)
		{
			return Utils.StaticClasses.ContainsKey(className);
		}

        public static bool IsDefault<T>(T obj)
        {
            return EqualityComparer<T>.Default.Equals(obj, default(T));
        }

        //public static bool IsNull(UnityEngine.Object p)
        //{
        //    bool isNull = !p;
        //    return isNull;
        //}

        public static uint MakeVariableId(string idstring)
        {
			return CRC32.CalcCRC(idstring);
        }

        public static bool IsParVar(string variableName)
        {
            int pSep = variableName.LastIndexOf(':');

            if (pSep != -1 && variableName[pSep - 1] == ':')
            {
                return false;
            }

            return true;
        }

        public static string GetNameWithoutClassName(string variableName)
        {
            int pSep = variableName.LastIndexOf(':');

            if (pSep > 0 && variableName[pSep - 1] == ':')
            {
                return variableName.Substring(pSep + 1);
            }

            return variableName;
        }

        public static int GetClassTypeNumberId<T>()
        {
            return 0;
        }

        public static void ConvertFromInteger<T>(int v, ref T ret)
        {
        }

        public static uint ConvertToInteger<T>(T v)
        {
            return 0;
        }

        public static Type GetType(string typeName)
        {
            // search base class
            Type type = Type.GetType(typeName);
            if (type != null)
            {
                return type;
            }

            // search loaded plugins
            foreach (Assembly a in AppDomain.CurrentDomain.GetAssemblies())
            {
                type = a.GetType(typeName);
                if (type != null)
                {
                    return type;
                }
            }

            // it could be a List<> type
            if (typeName.StartsWith("System.Collections.Generic.List"))
            {
                int startIndex = typeName.IndexOf("[[");
                if (startIndex > -1)
                {
                    int endIndex = typeName.IndexOf(",");
                    if (endIndex < 0)
                    {
                        endIndex = typeName.IndexOf("]]");
                    }
                    if (endIndex > startIndex)
                    {
                        string item = typeName.Substring(startIndex + 2, endIndex - startIndex - 2);
                        type = Utils.GetType(item);
                        if (type != null)
                        {
                            type = typeof(List<>).MakeGenericType(type);
                            return type;
                        }
                    }
                }
            }

            return null;
        }

        static Dictionary<string, string> ms_type_mapping = new Dictionary<string, string>()
        {
                {"Boolean"          , "bool"}, 
                {"System.Boolean"   , "bool"}, 
                {"Int32"            , "int"}, 
                {"System.Int32"     , "int"}, 
                {"UInt32"           , "uint"}, 
                {"System.UInt32"    , "uint"}, 
                {"Int16"            , "short"}, 
                {"System.Int16"     , "short"}, 
                {"UInt16"           , "ushort"}, 
                {"System.UInt16"    , "ushort"}, 
				{"Int8"             , "sbyte"}, 
				{"System.Int8"      , "sbyte"}, 
                {"SByte"            , "sbyte"}, 
				{"System.SByte"     , "sbyte"}, 
				{"UInt8"            , "ubyte"}, 
				{"System.UInt8"     , "ubyte"}, 
				{"Byte"             , "ubyte"}, 
				{"System.Byte"      , "ubyte"}, 
				{"Char"      		, "char"}, 
                {"Int64"            , "long"}, 
                {"System.Int64"     , "long"}, 
                {"UInt64"           , "ulong"}, 
                {"System.UInt64"    , "ulong"}, 
                {"Single"           , "float"}, 
                {"System.Single"    , "float"}, 
                {"Double"           , "double"}, 
                {"System.Double"    , "double"}, 
                {"String"           , "string"}, 
                {"System.String"    , "string"}, 
                {"Void"             , "void"}
        };

		private static object GetDefaultValue(Type t)
		{
			if (t.IsValueType)
			{
				return Activator.CreateInstance(t);
			}
			
			return null;
		}

		public static object GetValueFromString(Type type, string value)
		{
			if (value != null)
			{
				if (type == typeof(string) && !string.IsNullOrEmpty(value) &&
				    value.Length > 1 && value[0] == '\"' && value[value.Length-1] == '\"')
				{
					value = value.Substring(1, value.Length - 2);
				}

				try
				{
					TypeConverter converter = TypeDescriptor.GetConverter(type);
					return converter.ConvertFromString(value);
				}
				catch
				{
					if (type == typeof(bool))
					{
						bool b;
						if (bool.TryParse(value, out b))
							return b;
					}
					else if (type == typeof(int))
					{
						int i;
						if (int.TryParse(value, out i))
							return i;
					}
					else if (type == typeof(uint))
					{
						uint ui;
						if (uint.TryParse(value, out ui))
							return ui;
					}
					else if (type == typeof(short))
					{
						short s;
						if (short.TryParse(value, out s))
							return s;
					}
					else if (type == typeof(ushort))
					{
						ushort us;
						if (ushort.TryParse(value, out us))
							return us;
					}
					else if (type == typeof(char))
					{
						char c;
						if (char.TryParse(value, out c))
							return c;
					}
					else if (type == typeof(sbyte))
					{
						sbyte sb;
						if (sbyte.TryParse(value, out sb))
							return sb;
					}
					else if (type == typeof(byte))
					{
						byte b;
						if (byte.TryParse(value, out b))
							return b;
					}
					else if (type == typeof(long))
					{
						long l;
						if (long.TryParse(value, out l))
							return l;
					}
					else if (type == typeof(ulong))
					{
						ulong ul;
						if (ulong.TryParse(value, out ul))
							return ul;
					}
					else if (type == typeof(float))
					{
						float f;
						if (float.TryParse(value, out f))
							return f;
					}
					else if (type == typeof(double))
					{
						double d;
						if (double.TryParse(value, out d))
							return d;
					}
					else if (type == typeof(string))
					{
						return value;
					}
				}
			}

			return GetDefaultValue(type);
		}

        public static Type GetTypeFromName(string typeName)
        {
            if (string.IsNullOrEmpty(typeName))
            {
                return null;
            }

            switch (typeName)
            {
                case "bool":
                    return typeof(bool);
                case "int":
                    return typeof(int);
                case "uint":
                    return typeof(uint);
                case "short":
                    return typeof(short);
                case "ushort":
                    return typeof(ushort);
                case "char":
                    return typeof(char);
                case "sbyte":
                    return typeof(sbyte);
				case "ubyte":
				case "byte":
                    return typeof(byte);
                case "long":
                    return typeof(long);
                case "ulong":
                    return typeof(ulong);
                case "float":
                    return typeof(float);
                case "double":
                    return typeof(double);
                case "string":
                    return typeof(string);
            }

            return Utils.GetType(typeName);
        }

        public static string GetNativeTypeName(string typeName)
        {
            if (string.IsNullOrEmpty(typeName))
            {
                return string.Empty;
            }

            foreach (KeyValuePair<string, string> pair in ms_type_mapping)
            {
                if (pair.Key == typeName)
                {
                    return pair.Value;
                }
                else
                {
                    string refType = pair.Key + "&";
                    if (refType == typeName)
                    {
                        return pair.Value + "&";
                    }
                }
            }

            string[] types = typeName.Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries);
            return types[types.Length - 1];
        }

        public static string GetNativeTypeName(Type type)
        {
            Debug.Check(type != null);

            if (Utils.IsArrayType(type))
            {
                Type itemType = type.GetGenericArguments()[0];
                return string.Format("vector<{0}>", Utils.GetNativeTypeName(itemType));
            }

            return Utils.GetNativeTypeName(type.Name);
        }

        public static bool IsStringType(Type type)
        {
            return type == typeof(string);
        }

        public static bool IsEnumType(Type type)
        {
            return type != null && type.IsEnum;
        }

        public static bool IsArrayType(Type type)
        {
            return type != null && type.IsGenericType && type.GetGenericTypeDefinition() == typeof(List<>);
        }

        public static bool IsCustomClassType(Type type)
        {
            return type != null && !type.IsByRef && (type.IsClass || type.IsValueType) && type != typeof(void) && !type.IsEnum && !type.IsPrimitive && !IsStringType(type) && !IsArrayType(type);
        }
    }

    static public class Debug
    {
		[Conditional("BEHAVIAC_DEBUG")]
        [Conditional("UNITY_EDITOR")]
        public static void CheckEqual<T>(T l, T r)
        {
            if (!EqualityComparer<T>.Default.Equals(l, r))
            {
                Break("CheckEqualFailed");
            }
        }

		[Conditional("BEHAVIAC_DEBUG")]
        [Conditional("UNITY_EDITOR")]
        public static void Check(bool b)
        {
            if (!b)
            {
                Break("CheckFailed");
            }
        }

		[Conditional("BEHAVIAC_DEBUG")]
        [Conditional("UNITY_EDITOR")]
        public static void Check(bool b, string message)
        {
            if (!b)
            {
                Break(message);
            }
        }

		[Conditional("BEHAVIAC_DEBUG")]
        [Conditional("UNITY_EDITOR")]
        public static void Log(string message)
        {
            UnityEngine.Debug.Log(message);
        }

		[Conditional("UNITY_EDITOR")]
        public static void LogWarning(string message)
        {
            UnityEngine.Debug.LogWarning(message);
        }

		[Conditional("UNITY_EDITOR")]
        public static void LogError(string message)
        {
            UnityEngine.Debug.LogError(message);
        }

		[Conditional("BEHAVIAC_DEBUG")]
        [Conditional("UNITY_EDITOR")]
        public static void Break(string msg)
        {
            LogError(msg);

            UnityEngine.Debug.Break();
            //throw new Exception();
            //System.Diagnostics.Debug.Assert(false);
        }
    }

    #region Detail
    static public class Details
    {
        #region Impl
        class CompareValue<T> where T : struct, IComparable<T>
        {
            public static bool Greater(object lhs, object rhs)
            {
                return ((T)lhs).CompareTo((T)rhs) > 0;
            }

            public static bool GreaterEqual(object lhs, object rhs)
            {
                return ((T)lhs).CompareTo((T)rhs) >= 0;
            }

            public static bool Less(object lhs, object rhs)
            {
                return ((T)lhs).CompareTo((T)rhs) < 0;
            }

            public static bool LessEqual(object lhs, object rhs)
            {
                return ((T)lhs).CompareTo((T)rhs) <= 0;
            }
        }

        interface ICompareValue
        {
            bool Greater(object lhs, object rhs);

            bool GreaterEqual(object lhs, object rhs);

            bool Less(object lhs, object rhs);

            bool LessEqual(object lhs, object rhs);
        }

        class CompareValueInt : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((int)lhs) > ((int)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((int)lhs) >= ((int)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((int)lhs) < ((int)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((int)lhs) <= ((int)rhs);
            }
        }

        class CompareValueLong : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((long)lhs) > ((long)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((long)lhs) >= ((long)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((long)lhs) < ((long)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((long)lhs) <= ((long)rhs);
            }
        }

        class CompareValueShort : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((short)lhs) > ((short)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((short)lhs) >= ((short)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((short)lhs) < ((short)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((short)lhs) <= ((short)rhs);
            }
        }

        class CompareValueByte : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((sbyte)lhs) > ((sbyte)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((sbyte)lhs) >= ((sbyte)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((sbyte)lhs) < ((sbyte)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((sbyte)lhs) <= ((sbyte)rhs);
            }
        }

        class CompareValueFloat : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((float)lhs) > ((float)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((float)lhs) >= ((float)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((float)lhs) < ((float)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((float)lhs) <= ((float)rhs);
            }
        }

        class CompareValueUInt : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((uint)lhs) > ((uint)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((uint)lhs) >= ((uint)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((uint)lhs) < ((uint)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((uint)lhs) <= ((uint)rhs);
            }
        }

        class CompareValueULong : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((ulong)lhs) > ((ulong)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((ulong)lhs) >= ((ulong)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((ulong)lhs) < ((ulong)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((ulong)lhs) <= ((ulong)rhs);
            }
        }

        class CompareValueUShort : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((ushort)lhs) > ((ushort)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((ushort)lhs) >= ((ushort)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((ushort)lhs) < ((ushort)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((ushort)lhs) <= ((ushort)rhs);
            }
        }

        class CompareValueUByte : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((byte)lhs) > ((byte)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((byte)lhs) >= ((byte)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((byte)lhs) < ((byte)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((byte)lhs) <= ((byte)rhs);
            }
        }

        class CompareValueDouble : ICompareValue
        {
            public bool Greater(object lhs, object rhs)
            {
                return ((double)lhs) > ((double)rhs);
            }

            public bool GreaterEqual(object lhs, object rhs)
            {
                return ((double)lhs) >= ((double)rhs);
            }

            public bool Less(object lhs, object rhs)
            {
                return ((double)lhs) < ((double)rhs);
            }

            public bool LessEqual(object lhs, object rhs)
            {
                return ((double)lhs) <= ((double)rhs);
            }
        }
        ///
        interface IComputeValue
        {
            object Add(object opr1, object opr2);

            object Sub(object opr1, object opr2);

            object Mul(object opr1, object opr2);

            object Div(object opr1, object opr2);
        }

        class ComputeValueInt : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                int r = ((int)lhs) + ((int)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                int r = ((int)lhs) - ((int)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                int r = ((int)lhs) * ((int)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                int r = ((int)lhs) / ((int)rhs);
                return r;
            }
        }

        class ComputeValueLong : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                long r = ((long)lhs) + ((long)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                long r = ((long)lhs) - ((long)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                long r = ((long)lhs) * ((long)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                long r = ((long)lhs) / ((long)rhs);
                return r;
            }
        }

        class ComputeValueShort : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                short r = (short)(((short)lhs) + ((short)rhs));
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                short r = (short)(((short)lhs) - ((short)rhs));
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                short r = (short)(((short)lhs) * ((short)rhs));
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                short r = (short)(((short)lhs) / ((short)rhs));
                return r;
            }
        }

        class ComputeValueByte : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                sbyte r = (sbyte)(((sbyte)lhs) + ((sbyte)rhs));
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                sbyte r = (sbyte)(((sbyte)lhs) - ((sbyte)rhs));
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                sbyte r = (sbyte)(((sbyte)lhs) * ((sbyte)rhs));
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                sbyte r = (sbyte)(((sbyte)lhs) / ((sbyte)rhs));
                return r;
            }
        }

        class ComputeValueFloat : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                float r = ((float)lhs) + ((float)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                float r = ((float)lhs) - ((float)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                float r = ((float)lhs) * ((float)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                float r = ((float)lhs) / ((float)rhs);
                return r;
            }
        }

        class ComputeValueUInt : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                uint r = ((uint)lhs) + ((uint)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                uint r = ((uint)lhs) - ((uint)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                uint r = ((uint)lhs) * ((uint)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                uint r = ((uint)lhs) / ((uint)rhs);
                return r;
            }
        }

        class ComputeValueULong : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                ulong r = ((ulong)lhs) + ((ulong)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                ulong r = ((ulong)lhs) - ((ulong)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                ulong r = ((ulong)lhs) * ((ulong)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                ulong r = ((ulong)lhs) / ((ulong)rhs);
                return r;
            }
        }

        class ComputeValueUShort : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                ushort r = (ushort)(((ushort)lhs) + ((ushort)rhs));
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                ushort r = (ushort)(((ushort)lhs) - ((ushort)rhs));
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                ushort r = (ushort)(((ushort)lhs) * ((ushort)rhs));
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                ushort r = (ushort)(((ushort)lhs) / ((ushort)rhs));
                return r;
            }
        }

        class ComputeValueUByte : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                byte r = (byte)(((byte)lhs) + ((byte)rhs));
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                byte r = (byte)(((byte)lhs) - ((byte)rhs));
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                byte r = (byte)(((byte)lhs) * ((byte)rhs));
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                byte r = (byte)(((byte)lhs) / ((byte)rhs));
                return r;
            }
        }

        class ComputeValueDouble : IComputeValue
        {
            public object Add(object lhs, object rhs)
            {
                double r = ((double)lhs) + ((double)rhs);
                return r;
            }

            public object Sub(object lhs, object rhs)
            {
                double r = ((double)lhs) - ((double)rhs);
                return r;
            }

            public object Mul(object lhs, object rhs)
            {
                double r = ((double)lhs) * ((double)rhs);
                return r;
            }

            public object Div(object lhs, object rhs)
            {
                double r = ((double)lhs) / ((double)rhs);
                return r;
            }
        }
       
        #endregion Impl

        static Dictionary<Type, ICompareValue> ms_comparers = null;

        public static void RegisterCompareValue()
        {
            ms_comparers = new Dictionary<Type, ICompareValue>();

            ms_comparers[typeof(int)] = new CompareValueInt();
            ms_comparers[typeof(long)] = new CompareValueLong();
            ms_comparers[typeof(short)] = new CompareValueShort();
            ms_comparers[typeof(sbyte)] = new CompareValueByte();
            ms_comparers[typeof(float)] = new CompareValueFloat();

            ms_comparers[typeof(uint)] = new CompareValueUInt();
            ms_comparers[typeof(ulong)] = new CompareValueULong();
            ms_comparers[typeof(ushort)] = new CompareValueUShort();
            ms_comparers[typeof(byte)] = new CompareValueUByte();
            ms_comparers[typeof(double)] = new CompareValueDouble();
        }

        public static bool Equal(object lhs, object rhs)
        {
            return System.Object.Equals(lhs, rhs);
        }

        public static bool Greater(object lhs, object rhs)
        {
            Debug.Check(lhs != null && rhs != null);
            Type lhs_t = lhs.GetType();
            Debug.Check(lhs_t == rhs.GetType());
            Debug.Check(ms_comparers != null);
            if (ms_comparers.ContainsKey(lhs_t))
            {
                ICompareValue d = ms_comparers[lhs_t];
                return d.Greater(lhs, rhs);
            }

            return false;
        }

        public static bool GreaterEqual(object lhs, object rhs)
        {
            Debug.Check(lhs != null && rhs != null);
            Type lhs_t = lhs.GetType();
            Debug.Check(lhs_t == rhs.GetType());
            if (ms_comparers.ContainsKey(lhs_t))
            {
                ICompareValue d = ms_comparers[lhs_t];
                return d.GreaterEqual(lhs, rhs);
            }

            return false;
        }

        public static bool Less(object lhs, object rhs)
        {
            Debug.Check(lhs != null && rhs != null);
            Type lhs_t = lhs.GetType();
            Debug.Check(lhs_t == rhs.GetType());
            if (ms_comparers.ContainsKey(lhs_t))
            {
                ICompareValue d = ms_comparers[lhs_t];
                return d.Less(lhs, rhs);
            }

            return false;
        }

        public static bool LessEqual(object lhs, object rhs)
        {
            Debug.Check(lhs != null && rhs != null);
            Type lhs_t = lhs.GetType();
            Debug.Check(lhs_t == rhs.GetType());
            if (ms_comparers.ContainsKey(lhs_t))
            {
                ICompareValue d = ms_comparers[lhs_t];
                return d.LessEqual(lhs, rhs);
            }

            return false;
        }

        static Dictionary<Type, IComputeValue> ms_computers = null;

        public static void RegisterComputeValue()
        {
            ms_computers = new Dictionary<Type, IComputeValue>();

            ms_computers[typeof(int)] = new ComputeValueInt();
            ms_computers[typeof(long)] = new ComputeValueLong();
            ms_computers[typeof(short)] = new ComputeValueShort();
            ms_computers[typeof(sbyte)] = new ComputeValueByte();
            ms_computers[typeof(float)] = new ComputeValueFloat();

            ms_computers[typeof(uint)] = new ComputeValueUInt();
            ms_computers[typeof(ulong)] = new ComputeValueULong();
            ms_computers[typeof(ushort)] = new ComputeValueUShort();
            ms_computers[typeof(byte)] = new ComputeValueUByte();
            ms_computers[typeof(double)] = new ComputeValueDouble();
        }

        public static object ComputeValue(object value1, object value2, EComputeOperator opr)
        {
            Debug.Check(value1 != null && value2 != null);
            Type lhs_t = value1.GetType();
            Debug.Check(lhs_t == value2.GetType());
            Debug.Check(ms_computers != null);
            if (ms_computers.ContainsKey(lhs_t))
            {
                IComputeValue d = ms_computers[lhs_t];

                switch (opr)
                {
                    case EComputeOperator.E_ADD:
                        return d.Add(value1, value2);
                    case EComputeOperator.E_SUB:
                        return d.Sub(value1, value2);
                    case EComputeOperator.E_MUL:
                        return d.Mul(value1, value2);
                    case EComputeOperator.E_DIV:
                        return d.Div(value1, value2);
                }
            }

            return null;
        }
    }

    #endregion

    //public static class ListExtra
    //{
    //    public static void Resize<T>(this List<T> list, int sz, T c = default(T))
    //    {
    //        int cur = list.Count;
    //        if (sz < cur)
    //        {
    //            list.RemoveRange(sz, cur - sz);
    //        }
    //        else if (sz > cur)
    //        {
    //            for (int i = 0; i < sz - cur; ++i)
    //            {
    //                list.Add(c);
    //            }
    //        }
    //    }
    //}

    static public class StringUtils
    {
        ///the first char is '{', to return the paired '}'
        private static int SkipPairedBrackets(string src, int indexBracketBegin)
        {
            if (!string.IsNullOrEmpty(src) && src[indexBracketBegin] == '{')
            {
                int depth = 0;
                int pos = indexBracketBegin;
                while (pos < src.Length)
                {
                    if (src[pos] == '{')
                    {
                        depth++;
                    }
                    else if (src[pos] == '}')
                    {
                        if (--depth == 0)
                        {
                            return pos;
                        }
                    }

                    pos++;
                }
            }

            return -1;
        }

        private static object FromStringStruct(Type type, string src)
        {
            object objValue = Activator.CreateInstance(type);
            Dictionary<string, FieldInfo> structMembers = new Dictionary<string, FieldInfo>();
            FieldInfo[] fields = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static);
            for (int i = 0; i < fields.Length; ++i)
            {
                FieldInfo f = fields[i];
                if (!f.IsLiteral)
                {
                    structMembers.Add(f.Name, f);
                }
            }

            if (string.IsNullOrEmpty(src))
            {
                return objValue;
            }

            //{color=0;id=;type={bLive=false;name=0;weight=0;};}
            //the first char is '{'
            //the last char is '}'
            int posCloseBrackets = SkipPairedBrackets(src, 0);
            Debug.Check(posCloseBrackets != -1);

            //{color=0;id=;type={bLive=false;name=0;weight=0;};}
            int posBegin = 1;
            int posEnd = src.IndexOf(';', posBegin);
            while (posEnd != -1)
            {
                Debug.Check(src[posEnd] == ';');

                //the last one might be empty
                if (posEnd > posBegin)
                {
                    int posEqual = src.IndexOf('=', posBegin);
                    Debug.Check(posEqual > posBegin);

                    int length = posEqual - posBegin;
                    string memmberName = src.Substring(posBegin, length);
                    string memberValueStr;
                    char c = src[posEqual + 1];
                    if (c != '{')
                    {
                        length = posEnd - posEqual - 1;
                        memberValueStr = src.Substring(posEqual + 1, length);
                    }
                    else
                    {
                        int pStructBegin = 0;
                        pStructBegin += posEqual + 1;
                        int posCloseBrackets_ = SkipPairedBrackets(src, pStructBegin);
                        length = posCloseBrackets_ - pStructBegin + 1;

                        memberValueStr = src.Substring(posEqual + 1, length);

                        posEnd = posEqual + 1 + length;
                    }

                    if (structMembers.ContainsKey(memmberName))
                    {
                        FieldInfo memberType = structMembers[memmberName];
                        Debug.Check(memberType != null);
                        object memberValue = FromString(memberType.FieldType, memberValueStr, false);
                        memberType.SetValue(objValue, memberValue);
                    }
                }

                //skip ';'
                posBegin = posEnd + 1;

                //{color=0;id=;type={bLive=false;name=0;weight=0;};}
                posEnd = src.IndexOf(';', posBegin);
                if (posEnd > posCloseBrackets)
                {
                    break;
                }
            }

            return objValue;
        }

        private static object FromStringVector(Type type, string src)
        {
            Type vectorType = typeof(List<>).MakeGenericType(type);
            IList objVector = (IList)Activator.CreateInstance(vectorType);

            if (string.IsNullOrEmpty(src))
            {
                return objVector;
            }

            int semiColon = src.IndexOf(':');
            Debug.Check(semiColon != -1);
            string countStr = src.Substring(0, semiColon);
            int count = int.Parse(countStr);

            int b = semiColon + 1;
            int sep = b;
            if (b < src.Length && src[b] == '{')
            {
                sep = SkipPairedBrackets(src, b);
                Debug.Check(sep != -1);
            }
            sep = src.IndexOf('|', sep);
            while (sep != -1)
            {
                int len = sep - b;
                string elemStr = src.Substring(b, len);
                object elemObject = FromString(type, elemStr, false);

                objVector.Add(elemObject);

                b = sep + 1;
                if (b < src.Length && src[b] == '{')
                {
                    sep = SkipPairedBrackets(src, b);
                    Debug.Check(b != -1);
                }
                else
                {
                    sep = b;
                }

                sep = src.IndexOf('|', sep);
            }

            if (b < src.Length)
            {
                int len = src.Length - b;
                string elemStr = src.Substring(b, len);
                object elemObject = FromString(type, elemStr, false);

                objVector.Add(elemObject);
            }

            Debug.Check(objVector.Count == count);

            return objVector;
        }

        public static object FromString(Type type, string valStr, bool bStrIsArrayType /*= false*/)
        {
            if (!string.IsNullOrEmpty(valStr) && valStr == "null")
            {
                Debug.Check(type == typeof(Agent) || type.IsSubclassOf(typeof(Agent)));
                return null;
            }

            if (type.IsByRef)
            {
                type = type.GetElementType();
            }

            bool bIsArrayType = Utils.IsArrayType(type);

            object v = null;

            //customized type, struct or enum
            if (bStrIsArrayType || bIsArrayType)
            {
                if (bIsArrayType)
                {
                    Type elemType = type.GetGenericArguments()[0];
                    v = StringUtils.FromStringVector(elemType, valStr);
                }
                else
                {
                    v = StringUtils.FromStringVector(type, valStr);
                }
            }
            else if (type == typeof(behaviac.Property))
            {
                v = Condition.LoadProperty(valStr);
            }
            else if (Utils.IsCustomClassType(type))
            {
                Debug.Check(type != typeof(Agent) && !type.IsSubclassOf(typeof(Agent)));
                v = StringUtils.FromStringStruct(type, valStr);
            }
            else
            {
				v = Utils.GetValueFromString(type, valStr);
            }

            return v;
        }

        public static string ToString(object value)
        {
            string valueStr = "";
            if (value != null)
            {
                Type type = value.GetType();
                bool bIsArrayType = Utils.IsArrayType(type);

                //customized type, struct or enum
                if (bIsArrayType)
                {
                    IList list = value as IList;
                    valueStr = string.Format("{0}:", list.Count);

                    if (list.Count > 0)
                    {
                        for (int i = 0; i < list.Count - 1; ++i)
                        {
                            object e = list[i];
                            string eStr = StringUtils.ToString(e);
                            valueStr += string.Format("{0}|", eStr);
                        }

                        object eLast = list[list.Count - 1];
                        string eStrLast = StringUtils.ToString(eLast);
                        valueStr += string.Format("{0}", eStrLast);
                    }
                }
                else if (Utils.IsCustomClassType(type))
                {
                    bool bIsAgentDerived = (type == typeof(Agent) || type.IsSubclassOf(typeof(Agent)));
                    if (bIsAgentDerived)
                    {
                        valueStr = string.Format("{0:x08}", value.GetHashCode());
                    }
                    else
                    {
                        valueStr = "{";
                        FieldInfo[] fields = type.GetFields(BindingFlags.DeclaredOnly | BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance | BindingFlags.Static);
                        for (int i = 0; i < fields.Length; ++i)
                        {
                            FieldInfo f = fields[i];
                            object m = f.GetValue(value);
                            string mStr = StringUtils.ToString(m);
                            valueStr += string.Format("{0}={1};", f.Name, mStr);
                        }
                        valueStr += "}";
                    }
                }
                else
                {
                    valueStr = value.ToString();
                }
            }
            else
            {
                valueStr = "null";
            }

            
            return valueStr;
        }

        public static string FindExtension(string path)
        {
            return Path.GetExtension(path);
        }

        //public static bool IsNullOrEmpty(this string s)
        //{
        //    return string.IsNullOrEmpty(s);
        //}

        //
        public static int FirstToken(string params_, char sep, ref string token)
        {
            //const int 5
            int end = params_.IndexOf(sep);

            if (end != -1)
            {
                token = params_.Substring(0, end);
                return end;
            }

            return -1;
        }

        public static bool ParseForStruct(Type type, string str, ref string strT, Dictionary<string, Property> props)
        {
            int pB = 0;
            int i = 0;

            while (i < str.Length)
            {
                char c = str[i];
                if (c == ';' || c == '{' || c == '}')
                {
                    int p = pB;
                    while (p <= i)
                    {
                        strT += str[p++];
                    }

                    pB = i + 1;
                }
                else if (c == ' ')
                {
                    //par or property
                    string propName = "";
                    int p = pB;
                    while (str[p] != '=')
                    {
                        propName += str[p++];
                    }

                    //skip '='
                    Debug.Check(str[p] == '=');
                    p++;

                    string typeStr = "";
                    while (str[p] != ' ')
                    {
                        typeStr += str[p++];
                    }

                    bool bStatic = false;
                    if (typeStr == "static")
                    {
                        //skip ' '
                        Debug.Check(str[p] == ' ');
                        p++;

                        while (str[p] != ' ')
                        {
                            typeStr += str[p++];
                        }

                        bStatic = true;
                    }

                    string parName = "";

                    //skip ' '
                    Debug.Check(str[i] == ' ');
                    i++;

                    while (str[i] != ';')
                    {
                        parName += str[i++];
                    }

                    props[propName] = behaviac.Property.Create(typeStr, parName, null, bStatic, false);
                    ;

                    //skip ';'
                    Debug.Check(str[i] == ';');

                    pB = i + 1;
                }

                i++;
            }

            return true;
        }
    }
}