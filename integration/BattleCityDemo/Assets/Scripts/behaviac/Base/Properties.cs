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
using System.Collections;
using System.Collections.Generic;
using System.Reflection;

namespace behaviac
{
    public enum ParentType
    {
        PT_INVALID,
        PT_AGENT,
        PT_INSTANCE,
        PT_PAR
    };

    public class Property
    {
        public Property(CMemberBase pMemberBase, bool bIsConst)
        {
            m_memberBase = pMemberBase;
            m_variableId = 0;
            m_bValidDefaultValue = false;
            m_bIsConst = bIsConst;

            if (this.m_memberBase != null)
            {
                this.m_pt = this.m_memberBase.GetParentType();

                Debug.Check(this.m_pt == ParentType.PT_INVALID);
            }
            else
            {
                this.m_pt = ParentType.PT_PAR;
            }
        }

        protected Property(Property copy)
        {
            m_varaibleName = copy.m_varaibleName;
            m_varaibleFullName = copy.m_varaibleFullName;
            m_variableId = copy.m_variableId;
            m_refParName = copy.m_refParName;
			m_refParNameId = copy.m_refParNameId;
            m_memberBase = copy.m_memberBase;
            m_pt = copy.m_pt;
            m_instanceName = copy.m_instanceName;

            m_bValidDefaultValue = copy.m_bValidDefaultValue;
            m_defaultValue = copy.m_defaultValue;
            m_bIsConst = copy.m_bIsConst;
        }

        ~Property()
        {
//#if !BEHAVIAC_RELEASE
//            if (!string.IsNullOrEmpty(this.m_varaibleFullName))
//            {
//                if (ms_properties.ContainsKey(this.m_varaibleFullName))
//                {
//                    ms_properties.Remove(this.m_varaibleFullName);
//                }
//            }
//#ifdef 
        }

        public void SetVariableName(string variableName)
        {
            this.m_varaibleFullName = variableName;

            string nameOnly = Utils.GetNameWithoutClassName(variableName);

            this.m_variableId = Utils.MakeVariableId(nameOnly);
            this.m_varaibleName = nameOnly;
            //this.m_variableId = MakeVariableId(variableName);
            //this.m_varaibleName = variableName;
        }

        public string GetVariableName()
        {
            return this.m_varaibleName;
        }

        public string GetVariableFullName()
        {
            return this.m_varaibleFullName;
        }

        public uint GetVariableId()
        {
            return m_variableId;
        }

        public string GetClassNameString()
        {
            return m_memberBase != null ? m_memberBase.GetClassNameString() : null;
        }

        public string GetInstanceNameString()
        {
            if (!string.IsNullOrEmpty(m_instanceName))
            {
                return m_instanceName;
            }

            return m_memberBase != null ? m_memberBase.GetInstanceNameString() : null;
        }

        public void SetInstanceNameString(string agentIntanceName)
        {
            bool bValidName = !string.IsNullOrEmpty(agentIntanceName);

            if (bValidName)
            {
                Debug.Check(this.m_pt == ParentType.PT_INVALID || this.m_pt == ParentType.PT_AGENT);

                if (Agent.IsNameRegistered(agentIntanceName))
                {
                    this.m_pt = ParentType.PT_INSTANCE;
                    this.m_instanceName = agentIntanceName;
                }
                else
                {
                    //Debug.Check(strcmp(agentIntanceName, "Self") == 0);
                    this.m_pt = ParentType.PT_AGENT;
                }
            }
            else
            {
                Debug.Check(this.m_pt == ParentType.PT_PAR);
            }
        }

        public Property clone()
        {
            return new Property(this);
        }

        public void SetFrom(Agent pAgentFrom, Property from, Agent pAgentTo)
        {
            object retV = from.GetValue(pAgentFrom);

            this.SetValue(pAgentTo, retV);
        }

        public void SetDefaultInteger(int count)
        {
            this.m_bValidDefaultValue = true;

            Utils.ConvertFromInteger(count, ref this.m_defaultValue);
        }

        public uint GetDefaultInteger()
        {
            //VariableType retV = this.GetDefaultValue();

            //uint result = Utils.ConvertToInteger(retV);
            //return result;
            return 0;
        }

        public float DifferencePercentage(Property other)
        {
            //return const_cast<CMemberBase*>(this.m_memberBase).DifferencePercentage(this, other);
			object lV = this.GetDefaultValue ();
			object rV = other.GetDefaultValue ();

			float range = this.m_memberBase.GetRange ();

			float leftValue = 0.0f;
			float rightValue = 0.0f;
			if (lV.GetType () == typeof(float)) 
			{
				leftValue = (float)lV;
				rightValue = (float)rV;
			}
			else if (lV.GetType () == typeof(long)) 
			{
				leftValue = (long)lV;
				rightValue = (long)rV;
			}
			else if (lV.GetType () == typeof(int)) 
			{
				leftValue = (int)lV;
				rightValue = (int)rV;
			}
			else if (lV.GetType () == typeof(short)) 
			{
				leftValue = (short)lV;
				rightValue = (short)rV;
			}
			else if (lV.GetType () == typeof(sbyte)) 
			{
				leftValue = (sbyte)lV;
				rightValue = (sbyte)rV;
			}
			else if (lV.GetType () == typeof(ulong)) 
			{
				leftValue = (ulong)lV;
				rightValue = (ulong)rV;
			}
			else if (lV.GetType () == typeof(uint)) 
			{
				leftValue = (uint)lV;
				rightValue = (uint)rV;
			}
			else if (lV.GetType () == typeof(ushort)) 
			{
				leftValue = (ushort)lV;
				rightValue = (ushort)rV;
			}
			else if (lV.GetType () == typeof(byte)) 
			{
				leftValue = (byte)lV;
				rightValue = (byte)rV;
			}

			float d = leftValue - rightValue;
			if (d < 0.0f) 
			{
				d = -d;
			}

            return d / range;
        }

        public void Instantiate(Agent pAgent)
        {
            object v = this.GetDefaultValue();
            Debug.Check(this.m_memberBase == null);

            pAgent.Instantiate(v, this);
        }


        public void UnInstantiate(Agent pAgent)
        {
            Debug.Check(this.m_memberBase == null);

            pAgent.UnInstantiate(this.m_varaibleName);
        }

        public void UnLoad(Agent pAgent)
        {
            Debug.Check(this.m_memberBase == null);

            pAgent.UnLoad(this.m_varaibleName);
        }


        public void SetDefaultValue(Property r)
        {
            object v = r.GetDefaultValue();
            this.SetDefaultValue(v);
        }

        public void SetDefaultValue(object v)
        {
            this.m_bValidDefaultValue = true;
            this.m_defaultValue = v;
        }

        public bool SetDefaultValue(string valStr)
        {
			Type type = null;
            if (this.m_memberBase != null) 
			{
				type = this.m_memberBase.MemberType;
			} 
			else if (this.m_bValidDefaultValue) 
			{
				Debug.Check (this.m_defaultValue != null);
				type = this.m_defaultValue.GetType ();
			} 
			else 
			{
				Debug.Check(false);
			}

            this.m_defaultValue = StringUtils.FromString(type, valStr, false);

            if (this.m_defaultValue != null)
            {
                this.m_bValidDefaultValue = true;

                return true;
            }

            return false;
        }

        public bool SetDefaultValue(string valStr, Type type)
        {
            Debug.Check(this.m_memberBase == null);

            this.m_defaultValue = StringUtils.FromString(type, valStr, false);

            if (this.m_defaultValue != null)
            {
                this.m_bValidDefaultValue = true;

                return true;
            }

            return false;
        }

        object GetDefaultValue()
        {
            Debug.Check(this.m_bValidDefaultValue);

            return this.m_defaultValue;
        }

        public void SetValue(Agent parent, object v)
        {
            Debug.Check(!Object.ReferenceEquals(parent, null));
            Debug.Check(!m_bIsConst);

            string staticClassName = null;
            if (this.m_memberBase != null)
            {
#if !BEHAVIAC_RELEASE
                ParentType pt = this.m_memberBase.GetParentType();

                if (pt == ParentType.PT_INSTANCE)
                {
                    Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parent.GetContextId());
                    Debug.Check(Object.ReferenceEquals(pInstance, parent));
                }
#endif//
                if (this.m_pt == ParentType.PT_INSTANCE)
                {
                    Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parent.GetContextId());
                    parent = pInstance;
                }

                //don't update member as v is indeed the member itsef!
                //this.m_memberBase.Set(parent, v);

                if (this.m_memberBase.ISSTATIC())
                {
                    staticClassName = this.m_memberBase.GetClassNameString();
                }
            }

			parent.SetVariableRegistry(this.m_memberBase, this.m_varaibleName, v, staticClassName, this.m_variableId);
        }

        public object GetValue(Agent parent)
        {
            if (parent == null || m_bIsConst)
            {
                return this.GetDefaultValue();
            }
            else
            {
                if (this.m_memberBase != null)
                {
#if !BEHAVIAC_RELEASE
                    ParentType pt = this.m_memberBase.GetParentType();
                    if (pt == ParentType.PT_INSTANCE)
                    {
                        Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parent.GetContextId());
                        Debug.Check(Object.ReferenceEquals(pInstance, parent));
                    }
#endif//
                    if (this.m_pt == ParentType.PT_INSTANCE)
                    {
                        Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parent.GetContextId());
                        parent = pInstance;
                    }

                    object pVariable = this.m_memberBase.Get(parent);

                    return pVariable;
                }
                else
                {
                    return parent.GetVariable(this.m_varaibleName);
                }
            }
        }

        public object GetValue(Agent parent, Agent parHolder)
        {
            if (parent == null || m_bIsConst)
            {
                return this.GetDefaultValue();
            }
            else
            {
                if (this.m_memberBase != null)
                {
#if !BEHAVIAC_RELEASE
                    ParentType pt = this.m_memberBase.GetParentType();
                    if (pt == ParentType.PT_INSTANCE)
                    {
						Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parHolder.GetContextId());
						Debug.Check(Object.ReferenceEquals(pInstance, parHolder));
                    }
#endif//
                    if (this.m_pt == ParentType.PT_INSTANCE)
                    {
						Agent pInstance = Agent.GetInstance(this.GetInstanceNameString(), parHolder.GetContextId());
						parHolder = pInstance;
                    }

					object pVariable = this.m_memberBase.Get(parHolder);

                    return pVariable;
                }
                else
                {
                    return parHolder.GetVariable(this.m_varaibleName);
                }
            }
        }

        public ParentType GetParentType()
        {
            return m_pt;
        }


        public void SetRefName(string refParName)
        {
            m_refParName = refParName;
			m_refParNameId = Utils.MakeVariableId (m_refParName);
        }

        public string GetRefName()
        {
            return this.m_refParName;
        }

		public uint GetRefNameId()
		{
			return this.m_refParNameId;
		}
#if K_TYPE_CREATOR_
		template<typename T>
        static bool Register(string typeName)
        {
            PropertyCreators()[typeName] = &Creator<T>;

			return true;
        }
        template<typename T>
        static void UnRegister(string typeName)
        {
            PropertyCreators().erase(typeName);
        }

        static void RegisterBasicTypes();
        static void UnRegisterBasicTypes();
#endif//#if K_TYPE_CREATOR_

        static string ParseInstanceNameProperty(string fullName, ref string instanceName)
        {
            //Self.AgentActionTest::Action2(0)
            int pClassBegin = fullName.IndexOf('.');
            if (pClassBegin != -1)
            {
                instanceName = fullName.Substring(0, pClassBegin).Replace("::", ".");

                string propertyName = fullName.Substring(pClassBegin + 1);
                return propertyName;
            }

            return fullName;
        }

        ///create instance property, 
        ///create class scope static property
        public static Property Create(string typeName, string variableName, string value, bool bStatic, bool bConst)
        {
            if (!bConst)
            {
                string instanceName = null;
                string pPropertyName = null;

                bool bParVar = Utils.IsParVar(variableName);
                if (bParVar)
                {
                    pPropertyName = string.Format("{0}::{1}", typeName, variableName);
                }
                else
                {
                    pPropertyName = ParseInstanceNameProperty(variableName, ref instanceName);
                }

                bool bFound = false;
                if (!string.IsNullOrEmpty(pPropertyName))
                {
                    bFound = ms_properties.ContainsKey(pPropertyName);
                }

                if (!bFound)
                {
                    Property pProperty = Property.create(bParVar, bConst, typeName, pPropertyName, instanceName, value);
                    if (!string.IsNullOrEmpty(pPropertyName))
                    {
                        Debug.Check(pProperty != null);
                        ms_properties[pPropertyName] = pProperty;
                    }

                    Property pO = pProperty.clone();
                    return pO;
                }

                Property p = ms_properties[pPropertyName];

                Property pO0 = p.clone();
				if (!string.IsNullOrEmpty(value))
				{
					bool bAgentPtr = IsAgentPtr (typeName, value);

					if (!bAgentPtr)
					{
						pO0.SetDefaultValue(value);
					}
				}

                return pO0;
            }
            else
            {
                //const
                CMemberBase pMember = null;
                bool bValidName = !string.IsNullOrEmpty(variableName);
                string instanceName = null;

                string pPropertyName = variableName;
                if (bValidName)
                {
                    pPropertyName = ParseInstanceNameProperty(variableName, ref instanceName);
                    pMember = Agent.FindMemberBase(pPropertyName);
                }

                if (pMember != null)
                {
                    Property pProperty = pMember.CreateProperty(value, true);

                    return pProperty;
                }
                else
                {
                    //CMethodBase pMethod = null;
                    //if (bValidName)
                    //{
                    //    pMethod = Agent.FindMethodBase(pPropertyName);
                    //}

                    //if (pMethod != null)
                    //{
                    //    Property pProperty = pMethod.CreateProperty(value, true);

                    //    return pProperty;
                    //}

                    bool bParVar = bValidName && Utils.IsParVar(variableName);
                    Property pProperty1 = Property.create(bParVar, bConst, typeName, pPropertyName, instanceName, value);

                    return pProperty1;
                }
            }

            //return 0;
        }

        public static Property Create(string value, CMemberBase pMemberBase, bool bConst)
        {
            Property p = new Property(pMemberBase, bConst);

            //a const must have default value
            Debug.Check(!bConst || !string.IsNullOrEmpty(value));

            if (!string.IsNullOrEmpty(value))
            {
                if (p.SetDefaultValue(value))
                {
                    //
                }
                else
                {
                    //a const must have a valid default value
                    Debug.Check(!bConst);
                }
            }

            return p;
        }


        public static void DeleteFromCache(Property property_)
        {
            string pPropertyName = property_.GetVariableFullName();

            if (!string.IsNullOrEmpty(pPropertyName))
            {
                if (ms_properties.ContainsKey(pPropertyName))
                {
                    //Property pProperty = ms_properties[pPropertyName];
                    ms_properties.Remove(pPropertyName);
                }
            }
        }


        public static void Cleanup()
        {
            Debug.Check(ms_properties != null);
            ms_properties.Clear();
        }

        private static Type GetTypeFromName(string typeName)
        {
            if (typeName == "void*")
            { 
                return typeof(Agent);
            }
            
            Type type = Agent.GetTypeFromName(typeName);
            if (type == null)
            {
                typeName = typeName.Replace("::", ".");
                type = Utils.GetType(typeName);

                if (type == null)
                {
                    //typeName is not the customized struct or enums
                    //it should be the basic types
                    type = Utils.GetTypeFromName(typeName);
                }
            }

            return type;
        }


		static bool IsAgentPtr (string typeName, string valueStr)
		{
			bool bAgentPtr = false;
			//it might be par or the right value of condition/assignment
			if (!string.IsNullOrEmpty (valueStr) && valueStr == "null") {
				Debug.Check (Agent.IsAgentClassName (typeName));
				bAgentPtr = true;
			}
			return bAgentPtr;
		}

        private static Property create(bool bParVar, bool bConst, string typeName, string variableName, string instanceName, string valueStr)
        {
            bool bValidName = !string.IsNullOrEmpty(variableName);
            if (bValidName)
            {
                if (!bParVar)
                {
                    Property p = Agent.CreateProperty(typeName, variableName, valueStr);

                    if (bValidName && p != null && !bConst)
                    {
                        p.SetVariableName(variableName);
                        p.SetInstanceNameString(instanceName);
                    }

                    return p;
                }
            }

			var bAgentPtr = IsAgentPtr (typeName, valueStr);

            Property pProperty = new Property(null, bConst);
            object v = null;
            if (!bAgentPtr)
            {
                bool bArrayType = false;
                //array type
                if (typeName.StartsWith("vector<"))
                {
                    bArrayType = true;
                }

                Type type = null;
                if (bArrayType)
                {
                    int bracket0 = typeName.IndexOf('<');
                    int bracket1 = typeName.IndexOf('>');
                    int len = bracket1 - bracket0 - 1;

                    string elementType = typeName.Substring(bracket0 + 1, len);

                    type = GetTypeFromName(elementType);
                }
                else
                {
                    type = GetTypeFromName(typeName);
                }

                v = StringUtils.FromString(type, valueStr, bArrayType);
            }
            else
            {
                v = null;
            }

            pProperty.SetDefaultValue(v);

            if (bValidName && pProperty != null && !bConst)
            {
                pProperty.SetVariableName(variableName);
            }

            return pProperty;
        }

        private static Dictionary<string, Property> ms_properties = new Dictionary<string, Property>();

        protected string m_varaibleName;
        protected string m_varaibleFullName;
        protected uint m_variableId;
        protected readonly CMemberBase m_memberBase;
        protected string m_refParName;
		protected uint m_refParNameId;

        protected ParentType m_pt;
        protected string m_instanceName;

        protected object m_defaultValue;
        bool m_bValidDefaultValue;
        protected readonly bool m_bIsConst;
    };

    public class IVariable
    {
        public IVariable(CMemberBase pMember, string variableName, uint id)
        {
            m_id = id;
            m_name = variableName;
            m_property = null;
            m_pMember = pMember;
            m_instantiated = 1;
#if !BEHAVIAC_RELEASE
			m_changed = true;
#endif
        }

        public IVariable(CMemberBase pMember, Property property_)
        {
            m_property = property_;
            m_pMember = pMember;
            m_instantiated = 1;

            Debug.Check(this.m_property != null);

            this.m_name = this.m_property.GetVariableName();
            this.m_id = this.m_property.GetVariableId();
#if !BEHAVIAC_RELEASE
			m_changed = true;
#endif
        }

        public IVariable(IVariable copy)
        {
            m_id = copy.m_id;
            m_name = copy.m_name;
            m_property = copy.m_property;
            m_pMember = copy.m_pMember;
            m_instantiated = copy.m_instantiated;
			m_value = copy.m_value;

#if !BEHAVIAC_RELEASE
			m_changed = copy.m_changed;
#endif
        }

        ~IVariable()
        { }

#if !BEHAVIAC_RELEASE
        public bool IsChanged()
        {
            return m_changed;
        }
#endif
        public uint GetId()
        {
            return this.m_id;
        }

        public Property GetProperty()
        {
            return this.m_property;
        }

        public void SetProperty(Property p)
        {
            if (p != null)
            {
                Debug.Check(this.m_name == p.GetVariableName());
                Debug.Check(this.m_id == p.GetVariableId());
            }

            this.m_property = p;
        }

        public object GetValue(Agent pAgent)
        {
			if (this.m_pMember != null)
			{
				return this.m_pMember.Get(pAgent);
			}

            return this.m_value;
        }

		private static void DeepCopy(out object result, object obj)
		{
			if (obj == null)
			{
				result = obj;
				return;
			}

			Type type = obj.GetType();
			
			if (type.IsValueType || type == typeof(string))
			{
				result = obj;
				return;
			}
			else if (type.IsArray)
			{
                Type elementType = type.GetElementType(); 
				if (elementType == null)
				{
                    elementType = Type.GetType(type.FullName.Replace("[]", string.Empty));
				}

				var array = obj as Array;
				Array copied = Array.CreateInstance(elementType, array.Length);
				for (int i = 0; i < array.Length; i++)
				{
					object item;
					DeepCopy(out item, array.GetValue(i));
					copied.SetValue(item, i);
				}

				result = Convert.ChangeType(copied, type);
			}
            else if (type.IsClass)
            {
				result = obj;

				bool bIsNullValueType = Utils.IsNullValueType(type);
				if (bIsNullValueType)
                {
					result = obj;
					return;
                }

                object toret = Activator.CreateInstance(type);
                FieldInfo[] fields = type.GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
                foreach (FieldInfo field in fields)
                {
                    object fieldValue = field.GetValue(obj);
                    if (fieldValue == null)
                        continue;

					object outField;
					DeepCopy(out outField, fieldValue);
					field.SetValue(toret, outField);
                }
				result = toret;
			}
            else
            {
                //throw new ArgumentException("Unknown type");
                Debug.Check(false);

				result = obj;
            }
		}

		public void SetValue(object value, Agent pAgent)
		{
			bool bProperty = false;
			if (this.m_pMember != null)
			{
				this.m_pMember.Set(pAgent, value);
				//devlelopment version needs to update m_value even for property, as it needs to be used in the logging 
#if !BEHAVIAC_RELEASE
#else
				bProperty = true;
#endif
			}

			if (!bProperty && !(Details.Equal(this.m_value, value)))
            {
				//DeepCopy(out this.m_value, value);
				this.m_value = value;

#if !BEHAVIAC_RELEASE
                this.m_changed = true;
#endif
            }
            else
            {
                //don't clear it here, it will be cleared after being logged
                //this.m_changed = false;
            }
        }

        public void Log(Agent pAgent)
        {
            //BEHAVIAC_ASSERT(this.m_changed);

            string valueStr = StringUtils.ToString(this.m_value);
			string typeName = "";
			if (!Object.ReferenceEquals (this.m_value, null)) {
								typeName = Utils.GetNativeTypeName (this.m_value.GetType ());
						} else {
								typeName = "Agent";
						}

            string full_name = this.m_name;
            if (!Object.ReferenceEquals(pAgent, null))
            {
                CMemberBase pMember = pAgent.FindMember(this.m_name);
                if (pMember != null)
                {
                    string classFullName = pMember.GetClassNameString().Replace(".", "::");
                    full_name = string.Format("{0}::{1}", classFullName, this.m_name);
                }
            }

            LogManager.Log(pAgent, typeName, full_name, valueStr);
#if !BEHAVIAC_RELEASE
            this.m_changed = false;
#endif
        }


        public void Reset()
        {
#if !BEHAVIAC_RELEASE
            this.m_changed = false;
#endif
        }

        public IVariable clone()
        {
            IVariable pVar = new IVariable(this);
            return pVar;
        }

        public void CopyTo(Agent pAgent)
        {
            if (this.m_pMember != null)
            {
                this.m_pMember.Set(pAgent, m_value);
            }
            else
            {
                Debug.Check(true);
            }
        }

        public void Save(ISerializableNode node)
        {
            //base.Save(node);

            CSerializationID variableId = new CSerializationID("var");
            ISerializableNode varNode = node.newChild(variableId);

            CSerializationID nameId = new CSerializationID("name");
            varNode.setAttr(nameId, this.m_name);

            CSerializationID valueId = new CSerializationID("value");
            varNode.setAttr(valueId, this.m_value);
        }

        public void Load(ISerializableNode node)
        {
            //base.Load(node);
        }

        public void SetFromString(Agent pAgent, CMemberBase pMember, string valueString)
        {
            if (!string.IsNullOrEmpty(valueString))
            {
                object value = StringUtils.FromString(pMember.MemberType, valueString, false);

                if (!(Details.Equal(this.m_value, value)))
                {
                    this.m_value = value;
#if !BEHAVIAC_RELEASE
                    this.m_changed = true;
#endif
                    if (!Object.ReferenceEquals(pAgent, null))
                    {
                        //const CMemberBase* pMember = pAgent.FindMember(variableName);

                        if (pMember != null)
                        {
                            pMember.Set(pAgent, value);
                        }
                    }
                }
            }
        }

        protected uint m_id;
        protected string m_name;
        protected Property m_property;
        protected CMemberBase m_pMember;
        public byte m_instantiated;

		private object m_value;
#if !BEHAVIAC_RELEASE
		protected bool m_changed;
#endif
    };

    public class Variables
    {
        public Variables()
        {
            Debug.Check(this.m_variables.Count == 0);
        }

        ~Variables()
        {
            this.Clear();
        }

        public void Clear()
        {
            this.m_variables.Clear();
        }

        public bool IsExisting(uint varId)
        {
            return this.m_variables.ContainsKey(varId);
        }

        public void Instantiate(Property property_, object value)
        {
            Debug.Check(property_ != null);

            //string varirableName = property_.GetVariableName();
            //if (varirableName == "TempTargetEnemy")
            //{
            //    Debug.Check(true);
            //}

            uint varId = property_.GetVariableId();
            if (!this.m_variables.ContainsKey(varId))
            {
                IVariable pVar = new IVariable(null, property_);
				behaviac.Debug.Check(pVar != null);
                pVar.SetValue(value, null);
                m_variables[varId] = pVar;
            }
            else
            {
                IVariable pVar = this.m_variables[varId];
                Debug.Check(pVar.m_instantiated < 255, "dead loop?!");

                //don't update it, so the par set by outer scope can override the one in the internal
                if (pVar.m_instantiated == 0)
                {
                    pVar.SetProperty(property_);
                }
                else
                {
                    Debug.Check(pVar.GetValue(null) == null || 
                        (property_.GetValue(null) == null && Utils.IsNullValueType(pVar.GetValue(null).GetType())) ||
                        pVar.GetValue(null).GetType() == property_.GetValue(null).GetType(), 
                        "the same name par doesn't have the same type");
                }

                //use the original value, don't update it
                pVar.m_instantiated++;
            }
        }


        public void UnInstantiate(string variableName)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));

            //if (variableName == "TempTargetEnemy")
            //{
            //    Debug.Check(true);
            //}

            uint varId = Utils.MakeVariableId(variableName);

            Debug.Check(this.m_variables.ContainsKey(varId));

            if (this.m_variables.ContainsKey(varId))
            {
                IVariable pVar = this.m_variables[varId];
                Debug.Check(pVar.m_instantiated >= 1);

                //don't erase it as it might be accessed after the bt's ticking
                //this.m_variables.erase(varId);
                pVar.m_instantiated--;

                if (pVar.m_instantiated == 0)
                {
                    pVar.SetProperty(null);
                }
            }
        }


        public void UnLoad(string variableName)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));

            uint varId = Utils.MakeVariableId(variableName);

            //Debug.Check(this.m_variables.ContainsKey(varId));

            if (this.m_variables.ContainsKey(varId))
            {
                this.m_variables.Remove(varId);
            }
        }

        public void SetFromString(Agent pAgent, string variableName, string valueStr)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));

            //to skip class name
            string variableNameOnly = Utils.GetNameWithoutClassName(variableName);

            CMemberBase pMember = pAgent.FindMember(variableNameOnly);

            uint varId = Utils.MakeVariableId(variableNameOnly);

            if (this.m_variables.ContainsKey(varId))
            {
                IVariable pVar = this.m_variables[varId];

                pVar.SetFromString(pAgent, pMember, valueStr);
            }
        }

		public void Set(Agent pAgent, CMemberBase pMember, string variableName, object value, uint varId)
        {
            Debug.Check(!string.IsNullOrEmpty(variableName));

			if (varId == 0) 
			{
				varId = Utils.MakeVariableId(variableName);			
			}

            IVariable pVar = null;

            if (!this.m_variables.ContainsKey(varId))
            {
				if (pMember == null)
				{
					if (pAgent != null)
					{
						pMember = pAgent.FindMember(variableName); 
					}
					else
					{
						pMember = Agent.FindMemberBase(variableName);
					}
				}

                pVar = new IVariable(pMember, variableName, varId);
				behaviac.Debug.Check(pVar != null);
                m_variables[varId] = pVar;
            }
            else
            {
                pVar = this.m_variables[varId];
            }

			pVar.SetValue(value, pAgent);
        }

		public object Get(Agent pAgent, uint varId)
        {
			if (!this.m_variables.ContainsKey(varId))
            {
				//possible static property
				CMemberBase pMember = pAgent.FindMember(varId);
				
				if (pMember != null)
				{
					object pAddr = pMember.Get(pAgent);
					
					return pAddr;
				}

				Debug.Check(false, "a compatible property is not found");
            }
            else
            {
                //par
				IVariable pVar = this.m_variables[varId];

                {
                    Property refPropety = pVar.GetProperty();
                    if (refPropety != null)
                    {
                        string refName = refPropety.GetRefName();
                        if (!string.IsNullOrEmpty(refName))
                        {
							return this.Get(pAgent, refPropety.GetRefNameId());
                        }
                    }

					return pVar.GetValue(pAgent);
                }
            }

            return null;
        }

        public void Log(Agent pAgent, bool bForce)
        {
#if !BEHAVIAC_RELEASE
            if (Config.IsLoggingOrSocketing)
            {
                foreach (IVariable pVar in this.m_variables.Values)
                {
                    if (bForce || pVar.IsChanged())
                    {
                        pVar.Log(pAgent);
                    }
                }
            }
#endif
        }

        public void Reset()
        {
            foreach (IVariable pVar in this.m_variables.Values)
            {
                pVar.Reset();
            }
        }

        public void Unload()
        {
            this.m_variables.Clear();
        }

        public void CopyTo(Agent pAgent, Variables target)
        {
            target.m_variables.Clear();

            foreach (IVariable pVar in this.m_variables.Values)
            {
                IVariable pNew = pVar.clone();

                target.m_variables[pNew.GetId()] = pNew;
            }

            if (!Object.ReferenceEquals(pAgent, null))
            {
                foreach (IVariable pVar in target.m_variables.Values)
                {
                    pVar.CopyTo(pAgent);
                }
            }
        }

        void Save(ISerializableNode node)
        {
            CSerializationID variablesId = new CSerializationID("vars");
            ISerializableNode varsNode = node.newChild(variablesId);

            foreach (IVariable pVar in this.m_variables.Values)
            {
                pVar.Save(varsNode);
            }
        }
        void Load(ISerializableNode node)
        {

        }
        private Dictionary<uint, IVariable> m_variables = new Dictionary<uint, IVariable>();
    };
}//namespace behaviac
