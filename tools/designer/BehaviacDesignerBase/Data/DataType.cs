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
using System.Reflection;
using Behaviac.Design.Attributes;
using Behaviac.Design.Properties;

namespace Behaviac.Design
{
    public enum Language { System = 0, English, Chinese };

    [Flags]
    public enum ValueTypes
    {
        //return bool
        Bool = 1,

        //return byte, short, int, long
        Int = 2,

        //return float, double
        Float = 4,

        //all types
        All = Bool | Int | Float
    }


    public interface ISerializableData
    {
        string GetDisplayValue();
        string GetExportValue();
    }


    public class MethodDef : ICloneable, ISerializableData
    {
        public class Param
        {
            private ParameterInfo _paramInfo;

            public string Name
            {
                get 
                {
                    if (_paramInfo != null)
                    {
                        return _paramInfo.Name;
                    }

                    Debug.Check(this._bParamFromStruct);

                    return this._property.Property.Name;
                }
            }

            public Type Type
            {
                get 
                {
                    if (_paramInfo != null)
                    {
                        return _paramInfo.ParameterType;
                    }

                    if (_bParamFromStruct)
                    {
                        ParInfo par = this._value as ParInfo;
                        if (par != null)
                        {
                            return par.Type;
                        }

                        return this._property.Property.PropertyType;
                    }

                    if (this._value != null)
                    {
                        return this._value.GetType();
                    }

                    return null;
                }
            }

            private object _value;
            public object Value
            {
                get { return _value; }
                set 
                { 
                    _value = value;
                    if (_bParamFromStruct && _value != null)
                    {
                        //_property.Property.SetValue(_value, _object, null);
                        if ((_value is VariableDef) || (_value is ParInfo))
                        {
                            //do nothing
                        }
                        else
                        {
                            string valueStr = _value.ToString();
                            _property.SetValueFromString(_object, valueStr, null);
                        }
                    }
                }
            }

            private DesignerProperty _attribute;
            public DesignerProperty Attribute
            {
                get { return _attribute; }
            }

            private string _nativeType;
            public string NativeType
            {
                get { return _nativeType; }
            }

            private string _displayName;
            public string DisplayName
            {
                get { return _displayName; }
            }

            private string _description;
            public string Description
            {
                get { return _description; }
            }

            private bool _bParamFromStruct;
            public bool IsFromStruct
            { 
                get { return this._bParamFromStruct; }
            }

            private DesignerPropertyInfo _property;
            private object _object = null;
            public Param(DesignerPropertyInfo property, object obj)
            {
                _paramInfo = null;
                _property = property;
                _object = obj;
                _value = property.GetValue(obj);
                _nativeType = (_value != null) ? Plugin.GetNativeTypeName(_value.GetType()) : string.Empty;
                DesignerProperty pattr = property.Attribute;
                _displayName = pattr.DisplayName;
                _description = pattr.Description;
                _attribute = pattr;

                _bParamFromStruct = true;
            }

            public Param(string category, ParameterInfo pi, object v, string nativeType, string displayName, string description, float rangeMin, float rangeMax)
            {
                _paramInfo = pi;
                _value = v;
                _nativeType = nativeType;
                _displayName = displayName;
                _description = description;

                if (_paramInfo != null)
                {
                    DesignerProperty attr = null;

                    DesignerProperty[] attributes = (DesignerProperty[])_paramInfo.GetCustomAttributes(typeof(DesignerProperty), false);
                    if (attributes.Length > 0)
                        attr = attributes[0];

                    if (attr != null)
                        _attribute = attr;
                    else if (_paramInfo.ParameterType.IsEnum)
                        _attribute = new DesignerEnum(_paramInfo.Name, "", category, DesignerProperty.DisplayMode.Parameter, 0, DesignerProperty.DesignerFlags.NoFlags, "");
                    else
                    {
                        _attribute = Plugin.InvokeTypeCreateDesignerProperty(category, _paramInfo.Name, _paramInfo.ParameterType, rangeMin, rangeMax);
                    }
                }
            }

            public Param(Param other)
            {
                _paramInfo = other._paramInfo;
                _attribute = other._attribute;
                _nativeType = other._nativeType;
                _displayName = other._displayName;
                _description = other._description;
                _value = Plugin.CloneValue(other._value);
            }

            public string GetDisplayValue(object obj)
            {
                return _attribute.GetDisplayValue(this._value);
            }

            public string GetExportValue(object obj)
            {
                Debug.Check(_bParamFromStruct);

                ParInfo par = this._value as ParInfo;
                if (par != null)
                {
                    return par.GetExportValue();
                }

                VariableDef var = this._value as VariableDef;
                if (var != null)
                {
                    return var.GetExportValue();
                }

                object o = obj;
                //if (o == null)
                //{
                //    o = this._object;
                //}

                //if (o != null && this._bParamFromStruct)
                //{
                //    object m = this._property.GetValue(o);

                //    return this._attribute.GetExportValue(o, m);
                //}

                return this._attribute.GetExportValue(o, this._value);
            }

            public bool IsPar
            {
                get
                {
                    if (this._value is ParInfo)
                        return true;

                    VariableDef v = this._value as VariableDef;
                    return (v != null) ? v.IsPar : false;
                }
            }

            public bool IsProperty
            {
                get
                {
                    VariableDef v = this._value as VariableDef;
                    return (v != null) ? v.IsProperty : false;
                }
            }

            public bool IsPureConstDatum
            {
                get
                {
                    ParInfo par = this._value as ParInfo;
                    if (par != null)
                        return false;

                    VariableDef v = this._value as VariableDef;
                    if (v != null)
                        return v.IsConst;

                    return true;
                }
            }
        }

        public MethodDef(AgentType agentType, bool isPublic, bool isStatic, string owner, string name, string displayName, string description, string nativeReturnType, Type returnType, bool isNamedEvent, bool isActionMethodOnly, List<Param> pars)
        {
            _agentType = agentType;
            _isPublic = isPublic;
            _isStatic = isStatic;
            _owner = owner;
            _name = name;
            _displayName = displayName;
            _description = description;
            _nativeReturnType = nativeReturnType;
            _returnType = returnType;
            _isNamedEvent = isNamedEvent;
            _isActionMethodOnly = isActionMethodOnly;
            _params = pars;
        }

        public MethodDef(MethodDef other)
        {
            _agentType = other._agentType;
            _isPublic = other._isPublic;
            _isStatic = other._isStatic;
            _owner = other._owner;
            _name = other._name;
            _displayName = other._displayName;
            _description = other._description;
            _nativeReturnType = other._nativeReturnType;
            _returnType = other._returnType;
            _isNamedEvent = other._isNamedEvent;
            _isActionMethodOnly = other._isActionMethodOnly;

            _params = new List<Param>();
            foreach (Param param in other.Params)
                _params.Add(new Param(param));
        }

        public object Clone()
        {
            return new MethodDef(this);
        }

        AgentType _agentType = null;
        public AgentType AgentType
        {
            get { return _agentType; }
        }

        bool _isPublic = false;
        public bool IsPublic
        {
            get { return _isPublic; }
        }

        bool _isStatic = false;
        public bool IsStatic
        {
            get { return _isStatic; }
        }

        private string _owner = string.Empty;
        public string Owner
        {
            get { return _owner; }
            set { _owner = value; }
        }

        private string _name = string.Empty;
        public string Name
        {
            get { return _name; }
        }

        public string BasicName
        {
            get
            {
                if (!string.IsNullOrEmpty(_name))
                {
                    string[] name = _name.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                    if (name.Length > 0)
                        return name[name.Length - 1];
                }

                return string.Empty;
            }
        }

        public string ClassName
        {
            get
            {
                if (!string.IsNullOrEmpty(_name))
                {
                    int index = _name.LastIndexOf(":");
                    return (index != -1) ? _name.Substring(0, index - 1) : _name;
                }

                return _owner;
            }
        }

        private string _nativeReturnType = "void";
        public string NativeReturnType
        {
            get { return _nativeReturnType; }
        }

        private string _displayName = string.Empty;
        public string DisplayName
        {
            get
            {
                if (Plugin.UseBasicDisplayName && !string.IsNullOrEmpty(_displayName))
                {
                    string[] name = _displayName.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                    if (name.Length > 0)
                    {
                        if (name.Length > 1 && Plugin.IsInstanceName(name[0]))
                            return _displayName;

                        return name[name.Length - 1];
                    }
                }

                return _displayName;
            }
        }

        public string FullDisplayName
        {
            get { return _displayName; }
        }

        private string _description = string.Empty;
        public string Description
        {
            get { return _description; }
        }

        private Type _returnType;
        public Type ReturnType
        {
            get { return _returnType; }
        }

        private List<Param> _params;
        public List<Param> Params
        {
            get { return _params; }
        }

        private bool _isNamedEvent = false;
        public bool IsNamedEvent
        {
            get { return _isNamedEvent; }
        }

        private bool _isActionMethodOnly = false;
        public bool IsActionMethodOnly
        {
            get { return _isActionMethodOnly; }
        }

        abstract class StructParamBase_t
        {
            public abstract List<Param> GetParams(int index);
            public abstract void AddParam(int index, Param param);
        }

        class StructParam_t : StructParamBase_t
        {
            public Type type;
            private List<Param> ps;

            public StructParam_t()
            {
                type = null;
                this.ps = new List<Param>();
            }

            public override List<Param> GetParams(int index)
            {
                Debug.Check(index == -1);
                return this.ps;
            }

            public override void AddParam(int index, Param param)
            {
                Debug.Check(index == -1);
                this.ps.Add(param);
            }
        };

        class StructArrayParam_t : StructParamBase_t
        {
            private Dictionary<int, List<Param>> ps;

            public StructArrayParam_t()
            {
                ps = new Dictionary<int,List<Param>>();
            }

            public override List<Param> GetParams(int index)
            {
                Debug.Check(index != -1);
                if (this.ps.ContainsKey(index))
                {
                    return this.ps[index];
                }

                return null;
            }

            public override void AddParam(int index, Param param)
            {
                Debug.Check(index != -1);
                if (!this.ps.ContainsKey(index))
                {
                    this.ps[index] = new List<Param>();
                }

                this.ps[index].Add(param);
            }
        };

        private Dictionary<string, StructParamBase_t> _structParams = new Dictionary<string, StructParamBase_t>();
        public List<Param> GetParams(DesignerStructPropertyInfo structParam)
        {
            if (_structParams.ContainsKey(structParam.Name))
            {
                List<Param> ps = _structParams[structParam.Name].GetParams(structParam.ElmentIndexInArray);
                if (ps != null)
                {
                    return ps;
                }
            }
            else
            {
                if (structParam.ElmentIndexInArray == -1)
                {
                    _structParams[structParam.Name] = new StructParam_t();
                }
                else
                {
                    _structParams[structParam.Name] = new StructArrayParam_t();
                }

            }
            
            IList<DesignerPropertyInfo> properties = DesignerProperty.GetDesignerProperties(structParam.Type, DesignerProperty.SortByDisplayOrder);
            foreach (DesignerPropertyInfo property in properties)
            {
                Param v = new Param(property, structParam.Owner);
                _structParams[structParam.Name].AddParam(structParam.ElmentIndexInArray, v);
            }

            return _structParams[structParam.Name].GetParams(structParam.ElmentIndexInArray);
        }

        public Param GetParam(string paramName, DesignerPropertyInfo param, int indexInArray = -1)
        {
            if (_structParams.ContainsKey(paramName))
            {
                List<Param> ps = _structParams[paramName].GetParams(indexInArray);
                if (ps != null)
                {
                    foreach (Param p in ps)
                    {
                        if (p.Name == param.Property.Name && p.Type == param.Property.PropertyType)
                        {
                            return p;
                        }
                    }
                }
                else
                {
                    Debug.Check(true);
                }
            }

            return null;
        }

        public Param GetParam(string paramName, Type strutType, object obj, DesignerPropertyInfo param)
        {
            int indexInArray = -1;

            if (!_structParams.ContainsKey(paramName))
            {
                StructParam_t ps0 = new StructParam_t();
                _structParams[paramName] = ps0;
                ps0.type = obj.GetType();

                IList<DesignerPropertyInfo> properties = DesignerProperty.GetDesignerProperties(strutType, DesignerProperty.SortByDisplayOrder);
                foreach (DesignerPropertyInfo property in properties)
                {
                    object member = property.GetValue(obj);

                    Param v = new Param(property, obj);
                    _structParams[paramName].AddParam(-1, v);
                }
            }

            StructParam_t ps1 = _structParams[paramName] as StructParam_t;
            Debug.Check(ps1 != null);

            if (ps1.type == obj.GetType())
            {
                List<Param> ps = _structParams[paramName].GetParams(indexInArray);
                if (ps != null)
                {
                    foreach (Param p in ps)
                    {
                        if (p.Name == param.Property.Name && p.Type == param.Property.PropertyType)
                        {
                            return p;
                        }
                    }
                }
                else
                {
                    Debug.Check(true);
                }
            }

            return null;
        }
#if USE_NOOP
        private static MethodDef _noop = null;
        public static MethodDef Noop
        {
            get
            {
                if (_noop == null)
                {
                    _noop = new MethodDef("", typeof(void), new List<Param>());
                }

                return _noop;
            }
        }
#endif//#if USE_NOOP

        public bool CheckPar(ParInfo par)
        {
            foreach (MethodDef.Param param in this.Params)
            {
                if (param.Value is VariableDef)
                {
                    VariableDef var = param.Value as VariableDef;
                    return var.CheckPar(par);
                }
                else if (param.Value is ParInfo)
                {
                    if (par.GetExportValue() == ((ParInfo)(param.Value)).GetExportValue())
                        return true;
                }
            }

            return false;
        }

        public bool ResetPar(ParInfo par, string name)
        {
            foreach (MethodDef.Param param in this.Params)
            {
                if (param.Value is VariableDef)
                {
                    VariableDef var = param.Value as VariableDef;
                    return var.ResetPar(par, name);
                }
                else if (param.Value is ParInfo)
                {
                    if (par != null && par.GetExportValue() == ((ParInfo)(param.Value)).GetExportValue())
                    {
                        // If the name is empty, it means clearing the par.
                        if (string.IsNullOrEmpty(name))
                            param.Value = null;
                        else
                            ((ParInfo)(param.Value)).Name = name;

                        return true;
                    }
                }
            }

            return false;
        }

        public bool ShouldBeReset(AgentType agentType, bool resetPar)
        {
            foreach (MethodDef.Param param in this.Params)
            {
                if (param.Value is VariableDef)
                {
                    VariableDef var = param.Value as VariableDef;
                    if (var.ShouldBeReset(agentType, resetPar))
                    {
                        param.Value = Plugin.DefaultValue(param.Type);
                    }
                }
                else if (resetPar && param.Value is ParInfo)
                {
                    param.Value = Plugin.DefaultValue(param.Type);
                }
            }

            return (this.Owner == VariableDef.kSelf &&
                !Plugin.IsAgentDerived(this.AgentType.AgentTypeName, agentType.AgentTypeName));
        }

        public override string ToString()
        {
            return this.Name;
        }

        public string GetDisplayValue()
        {
            return getStringValue(true);
        }

        public string GetExportValue()
        {
            return getStringValue(false);
        }

        private string getStringValue(bool isDisplay)
        {
#if USE_NOOP
            if (MethodDef != MethodDef.Noop)
#endif
            {
                string str = null;
                if (isDisplay)
                {
                    if (this.Owner != VariableDef.kSelf)
                    {
                        str = Plugin.GetInstanceDisplayName(this.Owner) + "." + this.DisplayName;
                    }
                    else
                    {
                        str = this.DisplayName;
                    }
                }
                else
                {
                    str = this.Owner + "." + this.Name;
                }

                str += "(";

                for (int i = 0; i < this.Params.Count; ++i)
                {
                    if (i > 0)
                        str += ",";

                    object para = this.Params[i].Value;
                    str += isDisplay ? DesignerPropertyUtility.RetrieveDisplayValue(para, this, this.Params[i].Name) : DesignerPropertyUtility.RetrieveExportValue(para, this, this.Params[i].Name);
                }
                str += ")";

                return str;
            }
#if USE_NOOP
            return string.Empty;
#endif
        }
    }


    public class PropertyDef : ISerializableData
    {
        public PropertyDef(AgentType agentType, FieldInfo pi, bool isStatic, bool isPublic, string owner, string name, string nativeType, string displayName, string description)
        {
            _agentType = agentType;
            _propertyInfo = pi;
            _isStatic = isStatic;
            _isPublic = isPublic;
            _owner = owner;
            _name = name;
            _nativeType = nativeType;
            _displayName = displayName;
            _description = description;
        }

        public PropertyDef(PropertyDef other)
        {
            _agentType = other._agentType;
            _propertyInfo = other._propertyInfo;
            _isStatic = other._isStatic;
            _isPublic = other._isPublic;
            _owner = other._owner;
            _name = other._name;
            _nativeType = other._nativeType;
            _displayName = other._displayName;
            _description = other._description;
        }

        AgentType _agentType = null;
        public AgentType AgentType
        {
            get { return _agentType; }
        }

        private FieldInfo _propertyInfo;
        public Type Type
        {
            get { return _propertyInfo.FieldType; }
        }

        bool _isStatic = false;
        public bool IsStatic
        {
            get { return _isStatic; }
        }

        bool _isPublic = false;
        public bool IsPublic
        {
            get { return _isPublic; }
        }

        private string _owner = string.Empty;
        public string Owner
        {
            get { return _owner; }
            set { _owner = value; }
        }

        private string _name = string.Empty;
        public string Name
        {
            get { return _name; }
        }

        public string BasicName
        {
            get
            {
                if (!string.IsNullOrEmpty(_name))
                {
                    string[] name = _name.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                    if (name.Length > 0)
                        return name[name.Length - 1];
                }

                return string.Empty;
            }
        }

        public string ClassName
        {
            get
            {
                if (!string.IsNullOrEmpty(_name))
                {
                    int index = _name.LastIndexOf(":");
                    return (index != -1) ? _name.Substring(0, index - 1) : _name;
                }

                return _owner;
            }
        }

        private string _nativeType;
        public string NativeType
        {
            get { return _nativeType; }
        }

        private string _displayName = string.Empty;
        public string DisplayName
        {
            get
            {
                if (Plugin.UseBasicDisplayName && !string.IsNullOrEmpty(_displayName))
                {
                    string[] name = _displayName.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                    if (name.Length > 0)
                    {
                        if (name.Length > 1 && Plugin.IsInstanceName(name[0]))
                            return _displayName;

                        return name[name.Length - 1];
                    }
                }

                return _displayName;
            }
        }

        public string FullDisplayName
        {
            get { return _displayName; }
        }

        private string _description = string.Empty;
        public string Description
        {
            get { return _description; }
        }

        public string GetDisplayValue()
        {
            string owner = (!string.IsNullOrEmpty(this.Owner) && this.Owner != VariableDef.kSelf) ? (this.Owner + ".") : "";
            return owner + this.DisplayName;
        }

        public string GetExportValue()
        {
            return this.Owner + "." + this.Name;
        }

        public override string ToString()
        {
            return this.Name;
        }

        public bool ShouldBeReset(AgentType agentType, bool resetPar)
        {
            return (this.Owner == VariableDef.kSelf &&
                !Plugin.IsAgentDerived(this.AgentType.AgentTypeName, agentType.AgentTypeName));
        }
    }


    public class VariableDef : ICloneable, ISerializableData
    {
        public static string kConst = "Const";
        public static string kGlobal = "Global";
        public static string kPar = "Par";
        public static string kSelf = "Self";
        public static string kMethod = "::Method";
        public static string kSelfMethod = kSelf + kMethod;
        public static string kEvent = "Event";

        private string _valueClass;
        public string ValueClass
        {
            get { return _valueClass; }
            set
            {
                _valueClass = value;
                if (_property != null && _valueClass == VariableDef.kSelf)
                {
                    _property.Owner = VariableDef.kSelf;
                }
            }
        }

        public bool IsConst
        {
            get { return _valueClass == kConst; }
        }
        public bool IsPar
        {
            get { return _valueClass == kPar; }
        }
        public bool IsProperty
        {
            get { return _valueClass != kConst && _valueClass != kPar && _property != null; }
        }

        public object Clone()
        {
            return new VariableDef(this);
        }

        public VariableDef(VariableDef other)
        {
            if (other == null)
            {
                Value = null;
            }
            else
            {
                _property = (other._property != null) ? new PropertyDef(other._property) : null;
                _value = Plugin.CloneValue(other._value);
                ValueClass = other._valueClass;
            }
        }

        public VariableDef(object value)
        {
            Value = value;
        }

        public VariableDef(PropertyDef property, string valueType)
        {
            SetProperty(property, valueType);
        }

        public VariableDef(object value, string valueType)
        {
            _value = value;
            _valueClass = valueType;
        }

        private object _value = null;
        public object Value
        {
            get { return _value; }
            set
            {
                _value = value;
                ValueClass = VariableDef.kConst;
            }
        }

        public void SetValue(object value, string valueType)
        {
            Debug.Check(value != null && (valueType == kConst || valueType == kPar));
            _value = value;
            ValueClass = valueType;
        }

        private PropertyDef _property = null;
        public PropertyDef Property
        {
            get { return _property; }
        }

        public void SetProperty(PropertyDef property, string valueType)
        {
            _property = property;
            ValueClass = valueType;
        }

        public string NativeType
        {
            get
            {
                if (_valueClass == kConst || _valueClass == kPar)
                    return Plugin.GetNativeTypeName(this.GetValueType());

                if (_property != null)
                    return _property.NativeType;

                return string.Empty;
            }
        }

        public string DisplayName
        {
            get
            {
                if (_valueClass == kConst)
                    return Resources.Const;

                if (_valueClass == kPar)
                    return Resources.Par;

                if (_property != null)
                    return _property.DisplayName;

                return string.Empty;
            }
        }

        public string Description
        {
            get
            {
                if (_valueClass == kConst)
                    return Resources.Const;

                if (_valueClass == kPar)
                    return Resources.ParInfo;

                if (_property != null)
                    return _property.Description;

                return string.Empty;
            }
        }

        public Type GetValueType()
        {
            if (_valueClass == kConst || _valueClass == kPar)
            {
                if (_value != null)
                {
                    ParInfo parInfo = _value as ParInfo;
                    if (parInfo != null)
                    {
                        VariableDef var = parInfo.Variable;
                        if (var != null)
                            return var.GetValueType();
                    }
                    else
                    {
                        return _value.GetType();
                    }
                }
            }
            else if (_property != null)
            {
                return _property.Type;
            }

            return null;
        }

        public override string ToString()
        {
            return GetExportValue();
        }

        public string GetDisplayValue()
        {
            string str = string.Empty;
            if (_valueClass == kConst)
            {
                if (_value != null)
                    str = DesignerPropertyUtility.RetrieveDisplayValue(_value, null, null);
            }
            else if (_valueClass == kPar)
            {
                if (_value != null)
                    str = DesignerPropertyUtility.RetrieveDisplayValue(_value, null, null);
            }
            else if (_property != null)
            {
                str = DesignerPropertyUtility.RetrieveDisplayValue(_property, null, null);
            }

            return str;
        }

        public string GetExportValue()
        {
            string str = string.Empty;
            if (_valueClass == kConst)
            {
                if (_value != null)
                    str = string.Format("const {0} {1}", Plugin.GetNativeTypeName(_value.GetType()), DesignerPropertyUtility.RetrieveExportValue(_value, null, null));
            }
            else if (_valueClass == kPar)
            {
                if (_value != null)
                    str = DesignerPropertyUtility.RetrieveExportValue(_value, null, null);
            }
            else if (_property != null)
            {
                str = string.Format("{0} {1}", Plugin.GetNativeTypeName(_property.Type), DesignerPropertyUtility.RetrieveExportValue(_property, null, null));
                if (_property.IsStatic)
                    str = str.Insert(0, "static ");
            }

            return str;
        }

        public string GetRawValue()
        {
            if (_valueClass == kConst && _value != null)
                return DesignerPropertyUtility.RetrieveExportValue(_value, null, null);

            return GetDisplayValue();
        }

        private bool IsGlobalType()
        {
            return _valueClass != kConst && _valueClass != kPar && _valueClass != kSelf && _valueClass != kSelfMethod;
        }

        public bool CheckPar(ParInfo par)
        {
            if (_valueClass == kPar && _value is ParInfo)
            {
                if (par.GetExportValue() == ((ParInfo)(_value)).GetExportValue())
                    return true;
            }

            return false;
        }

        public bool ResetPar(ParInfo par, string name)
        {
            if (_valueClass == kPar && _value is ParInfo)
            {
                if (par != null && par.GetExportValue() == ((ParInfo)(_value)).GetExportValue())
                {
                    // If the name is empty, it means clearing the par.
                    if (string.IsNullOrEmpty(name))
                        _value = null;
                    else
                        ((ParInfo)(_value)).Name = name;

                    return true;
                }
            }

            return false;
        }

        public bool ShouldBeReset(AgentType agentType, bool resetPar)
        {
            if (this.IsPar)
            {
                return false;
            }
            else if (this.IsProperty && this.Property != null)
            {
                return this.Property.ShouldBeReset(agentType, resetPar);
            }

            return false;
        }
    }


    public class RightValueDef : ICloneable, ISerializableData
    {
        private VariableDef m_var = null;
        private MethodDef m_method = null;

        public object Clone()
        {
            RightValueDef clone = new RightValueDef(Var);

            if (m_var != null)
                clone.m_var = (VariableDef)m_var.Clone();

            if (m_method != null)
                clone.m_method = (MethodDef)m_method.Clone();

            clone.ValueClass = _valueClass;

            return clone;
        }

        public RightValueDef(VariableDef var)
        {
            m_var = var;
            if (m_var != null)
                _valueClass = m_var.ValueClass;
        }

        public RightValueDef(MethodDef method, string valueClass)
        {
            m_method = method;
            _valueClass = valueClass;
        }

        public VariableDef Var
        {
            get { return m_var; }
        }

        public MethodDef Method
        {
            get { return m_method; }
        }

        public Type ValueType
        {
            get
            {
                if (m_var != null)
                    return m_var.GetValueType();

                if (m_method != null)
                    return m_method.ReturnType;

                return null;
            }
        }

        private string _valueClass;
        public string ValueClass
        {
            get { return _valueClass; }
            set
            {
                _valueClass = value;
                if (m_var != null)
                    m_var.ValueClass = _valueClass;
            }
        }

        public bool IsMethod
        {
            get
            {
                if (!string.IsNullOrEmpty(_valueClass))
                {
                    int pos = _valueClass.IndexOf(VariableDef.kMethod);
                    if (pos != -1)
                    {
                        return true;
                    }
                }

                return false;
            }
        }

        public string ValueClassReal
        {
            get
            {
                if (!string.IsNullOrEmpty(_valueClass))
                {
                    int pos = this._valueClass.IndexOf(VariableDef.kMethod);
                    if (pos != -1)
                    {
                        string type = _valueClass.Substring(0, pos);
                        return type;
                    }
                }

                //not a method
                return _valueClass;
            }
        }

        public string NativeType
        {
            get
            {
                if (m_var != null)
                    return m_var.NativeType;

                if (m_method != null)
                    return m_method.NativeReturnType;

                return string.Empty;
            }
        }

        public string DisplayName
        {
            get
            {
                if (m_var != null)
                    return m_var.DisplayName;

                if (m_method != null)
                    return m_method.DisplayName;

                return string.Empty;
            }
        }

        public string Description
        {
            get
            {
                if (m_var != null)
                    return m_var.Description;

                if (m_method != null)
                    return m_method.Description;

                return string.Empty;
            }
        }

        public override string ToString()
        {
            return GetExportValue();
        }

        public string GetDisplayValue()
        {
            if (m_var != null)
                return DesignerPropertyUtility.RetrieveDisplayValue(m_var, null, null);

            if (m_method != null)
                return DesignerPropertyUtility.RetrieveDisplayValue(m_method, null, null);

            return string.Empty;
        }

        public string GetExportValue()
        {
            if (m_var != null)
                return DesignerPropertyUtility.RetrieveExportValue(m_var, null, null);

            if (m_method != null)
                return DesignerPropertyUtility.RetrieveExportValue(m_method, null, null);

            return string.Empty;
        }

        public bool CheckPar(ParInfo par)
        {
            if (m_var != null)
            {
                return m_var.CheckPar(par);
            }
            else if (m_method != null)
            {
                return m_method.CheckPar(par);
            }

            return false;
        }

        public bool ResetPar(ParInfo par, string name)
        {
            if (m_var != null)
                return m_var.ResetPar(par, name);

            if (m_method != null)
                return m_method.ResetPar(par, name);

            return false;
        }

        public bool ShouldBeReset(AgentType agentType, bool resetPar)
        {
            if (this.IsMethod && this.Method != null)
            {
                return this.Method.ShouldBeReset(agentType, resetPar);
            }
            else if (this.Var != null)
            {
                return this.Var.ShouldBeReset(agentType, resetPar);
            }

            return false;
        }
    }


    public class ParInfo : ISerializableData
    {
        public delegate void ParameterSettingDelegate(Nodes.Node node, ParInfo parameter);
        public event ParameterSettingDelegate ParameterSet;

        public ParInfo(Nodes.Node node)
        {
            _node = node;
        }

        public ParInfo(ParInfo other)
        {
            Copy(other);
        }

        public void Copy(ParInfo other)
        {
            _node = other._node;
            _name = other._name;
            _eventParam = other._eventParam;
            _typeName = other._typeName;
            _description = other._description;
            if (other._variable != null)
                _variable = (VariableDef)other._variable.Clone();
        }

        public ParInfo Clone(Nodes.Node node = null)
        {
            ParInfo par = new ParInfo(this);
            if (node != null)
                par._node = node;

            return par;
        }

        public void OnValueChanged()
        {
            if (ParameterSet != null)
                ParameterSet(_node, this);
        }

        private Nodes.Node _node = null;
        public Nodes.Node Node
        {
            set
            {
                _node = value;
                OnValueChanged();
            }
        }

        private string _name = string.Empty;
        public string Name
        {
            get { return _name; }
            set
            {
                _name = value;
                OnValueChanged();
            }
        }

        private string _typeName = string.Empty;
        public string TypeName
        {
            get { return _typeName; }
            set
            {
                _typeName = value;
                OnValueChanged();
            }
        }

        public string NativeType
        {
            get { return Plugin.GetNativeTypeName(this.Type); }
        }

        private string _description = string.Empty;
        public string Description
        {
            get { return _description; }
            set
            {
                _description = value;
                OnValueChanged();
            }
        }

        public Type Type
        {
            get { return (_variable != null) ? _variable.GetValueType() : null; }
        }

        private VariableDef _variable = null;
        public VariableDef Variable
        {
            get { return _variable; }
            set
            {
                _variable = value;
                OnValueChanged();
            }
        }

        public string DefaultValue
        {
            get
            {
                if (Variable == null)
                    return string.Empty;

                string defaultValue = Variable.GetRawValue();

                // "string" - > string
                if (Plugin.IsStringType(this.Type))
                    defaultValue = defaultValue.Substring(1, defaultValue.Length - 2);

                return defaultValue;
            }
        }

        private string _eventParam = null;
        public string EventParam
        {
            get { return _eventParam; }
            set
            {
                _eventParam = value;
                OnValueChanged();
            }
        }

        public override string ToString()
        {
            return GetExportValue();
        }

        public string GetDisplayValue()
        {
            return Name;
        }

        public string GetExportValue()
        {
            if (Type != null)
                return string.Format("{0} {1}", Plugin.GetNativeTypeName(Type), Name);

            return string.Empty;
        }
    }
}
