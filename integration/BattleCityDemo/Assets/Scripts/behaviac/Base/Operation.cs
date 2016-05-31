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
using System.Linq.Expressions;

namespace behaviac
{
    public class AgentMetaVisitor
    {
        private static Dictionary<string, FieldInfo> _fields = new Dictionary<string, FieldInfo>();
        private static Dictionary<string, PropertyInfo> _properties = new Dictionary<string, PropertyInfo>();
        private static Dictionary<string, MethodInfo> _methods = new Dictionary<string, MethodInfo>();

        public static object GetProperty(behaviac.Agent agent, string property)
        {
            Type type = agent.GetType();
            string propertyName = type.FullName + property;
            if (_fields.ContainsKey(propertyName))
            {
                return _fields[propertyName].GetValue(agent);
            }

            if (_properties.ContainsKey(propertyName))
            {
                return _properties[propertyName].GetValue(agent, null);
            }

            while (type != typeof(object))
            {
                FieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                if (field != null)
                {
                    _fields[propertyName] = field;
                    return field.GetValue(agent);
                }

                PropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                if (prop != null)
                {
                    _properties[propertyName] = prop;
                    return prop.GetValue(agent, null);
                }

                type = type.BaseType;
            }
            Debug.Check(false, "No property can be found!");
            return null;
        }

        public static void SetProperty(behaviac.Agent agent, string property, object value)
        {
            Type type = agent.GetType();
            string propertyName = type.FullName + property;
            if (_fields.ContainsKey(propertyName))
            {
                _fields[propertyName].SetValue(agent, value);
                return;
            }

            if (_properties.ContainsKey(propertyName))
            {
                _properties[propertyName].SetValue(agent, value, null);
                return;
            }

            while (type != typeof(object))
            {
                FieldInfo field = type.GetField(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                if (field != null)
                {
                    _fields[propertyName] = field;
                    field.SetValue(agent, value);
                    return;
                }

                PropertyInfo prop = type.GetProperty(property, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                if (prop != null)
                {
                    _properties[propertyName] = prop;
                    prop.SetValue(agent, value, null);
                    return;
                }

                type = type.BaseType;
            }
            Debug.Check(false, "No property can be found!");
        }

        public static object ExecuteMethod(behaviac.Agent agent, string method, object[] args)
        {
            Type type = agent.GetType();
            string methodName = type.FullName + method;
            if (_methods.ContainsKey(methodName))
            {
                return _methods[methodName].Invoke(agent, args); ;
            }

            while (type != typeof(object))
            {
                MethodInfo m = type.GetMethod(method, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
                if (m != null)
                {
                    _methods[methodName] = m;
                    return m.Invoke(agent, args);
                }

                type = type.BaseType;
            }
            Debug.Check(false, "No method can be found!");
            return null;
        }
    }

    public static class ExpressionUtil
    {
        public static Func<TArg1, TResult> CreateExpression<TArg1, TResult>(
            Func<Expression, UnaryExpression> body)
        {
            ParameterExpression inp = Expression.Parameter(typeof(TArg1), "inp");
            try
            {
                return Expression.Lambda<Func<TArg1, TResult>>(body(inp), inp).Compile();
            }
            catch (Exception ex)
            {
                string msg = ex.Message;
                return delegate { throw new InvalidOperationException(msg); };
            }
        }

        public static Func<TArg1, TArg2, TResult> CreateExpression<TArg1, TArg2, TResult>(
            Func<Expression, Expression, BinaryExpression> body)
        {
            return CreateExpression<TArg1, TArg2, TResult>(body, false);
        }

        public static Func<TArg1, TArg2, TResult> CreateExpression<TArg1, TArg2, TResult>(
            Func<Expression, Expression, BinaryExpression> body, bool castArgsToResultOnFailure)
        {
            ParameterExpression lhs = Expression.Parameter(typeof(TArg1), "lhs");
            ParameterExpression rhs = Expression.Parameter(typeof(TArg2), "rhs");
            try
            {
                try
                {
                    return Expression.Lambda<Func<TArg1, TArg2, TResult>>(body(lhs, rhs), lhs, rhs).Compile();
                }
                catch (InvalidOperationException)
                {
                    if (castArgsToResultOnFailure && !(typeof(TArg1) == typeof(TResult) && typeof(TArg2) == typeof(TResult)))
                    {
                        Expression castLhs = typeof(TArg1) == typeof(TResult) ?
                                (Expression)lhs :
                                (Expression)Expression.Convert(lhs, typeof(TResult));
                        Expression castRhs = typeof(TArg2) == typeof(TResult) ?
                                (Expression)rhs :
                                (Expression)Expression.Convert(rhs, typeof(TResult));

                        return Expression.Lambda<Func<TArg1, TArg2, TResult>>(
                            body(castLhs, castRhs), lhs, rhs).Compile();
                    }
                    else
                    {
                        throw;
                    }
                }
            }
            catch (Exception ex)
            {
                string msg = ex.Message;
                return delegate { throw new InvalidOperationException(msg); };
            }
        }

        public static Func<TArg1, TArg2, bool> MakeEqualsMethod<TArg1, TArg2>()
        {
            try
            {
                Type type = typeof(TArg1);
                ParameterExpression pThis = Expression.Parameter(type, "lhs");
                ParameterExpression pThat = Expression.Parameter(type, "rhs");

                // cast to the subclass type
                UnaryExpression pCastThis = Expression.Convert(pThis, type);
                UnaryExpression pCastThat = Expression.Convert(pThat, type);

                // compound AND expression using short-circuit evaluation
                Expression last = null;
                foreach (PropertyInfo property in type.GetProperties())
                {
                    BinaryExpression equals = Expression.Equal(
                        Expression.Property(pCastThis, property),
                        Expression.Property(pCastThat, property)
                    );

                    if (last == null)
                        last = equals;
                    else
                        last = Expression.AndAlso(last, equals);
                }

                // call Object.Equals if second parameter doesn't match type
                last = Expression.Condition(
                    Expression.TypeIs(pThat, type),
                    last,
                    Expression.Equal(pThis, pThat)
                );

                // compile method
                return Expression.Lambda<Func<TArg1, TArg2, bool>>(last, pThis, pThat).Compile();
            }
            catch (Exception ex)
            {
                string msg = ex.Message;
                return delegate { throw new InvalidOperationException(msg); };
            }
        }
    }

    public static class Operator<T>
    {
        static readonly Func<T, T, T> add, subtract, multiply, divide;

        public static Func<T, T, T> Add { get { return add; } }
        public static Func<T, T, T> Subtract { get { return subtract; } }
        public static Func<T, T, T> Multiply { get { return multiply; } }
        public static Func<T, T, T> Divide { get { return divide; } }

        static readonly Func<T, T, bool> memberEqual, equal, notEqual, greaterThan, lessThan, greaterThanOrEqual, lessThanOrEqual;

        public static Func<T, T, bool> MemberEqual { get { return memberEqual; } }
        public static Func<T, T, bool> Equal { get { return equal; } }
        public static Func<T, T, bool> NotEqual { get { return notEqual; } }
        public static Func<T, T, bool> GreaterThan { get { return greaterThan; } }
        public static Func<T, T, bool> GreaterThanOrEqual { get { return greaterThanOrEqual; } }
        public static Func<T, T, bool> LessThan { get { return lessThan; } }
        public static Func<T, T, bool> LessThanOrEqual { get { return lessThanOrEqual; } }

        static Operator()
        {
            Type type = typeof(T);

            if (!Utils.IsAgentType(type) && !Utils.IsCustomClassType(type) && !Utils.IsCustomStructType(type) && !Utils.IsArrayType(type) && !Utils.IsEnumType(type) &&
                !Utils.IsStringType(type) && type != typeof(bool) && type != typeof(char))
            {
                add = ExpressionUtil.CreateExpression<T, T, T>(Expression.Add);
                subtract = ExpressionUtil.CreateExpression<T, T, T>(Expression.Subtract);
                divide = ExpressionUtil.CreateExpression<T, T, T>(Expression.Divide);
                multiply = ExpressionUtil.CreateExpression<T, T, T>(Expression.Multiply);

                greaterThan = ExpressionUtil.CreateExpression<T, T, bool>(Expression.GreaterThan);
                greaterThanOrEqual = ExpressionUtil.CreateExpression<T, T, bool>(Expression.GreaterThanOrEqual);
                lessThan = ExpressionUtil.CreateExpression<T, T, bool>(Expression.LessThan);
                lessThanOrEqual = ExpressionUtil.CreateExpression<T, T, bool>(Expression.LessThanOrEqual);
            }

            if (Utils.IsCustomStructType(type) || Utils.IsArrayType(type))
            {
                memberEqual = ExpressionUtil.MakeEqualsMethod<T, T>();
            }
            else
            {
                equal = ExpressionUtil.CreateExpression<T, T, bool>(Expression.Equal);
                notEqual = ExpressionUtil.CreateExpression<T, T, bool>(Expression.NotEqual);
            }
        }
    }

    public enum EOperatorType
    {
        E_INVALID,
        E_ASSIGN,        // =
        E_ADD,           // +
        E_SUB,           // -
        E_MUL,           // *
        E_DIV,           // /
        E_EQUAL,         // ==
        E_NOTEQUAL,      // !=
        E_GREATER,       // >
        E_GREATEREQUAL,  // >=
        E_LESS,          // <
        E_LESSEQUAL      // <=
    }

    public static class OperationUtils
    {
        public static EOperatorType ParseOperatorType(string operatorType)
        {
            switch (operatorType)
            {
                case "Invalid":         return EOperatorType.E_INVALID;
                case "Assign":          return EOperatorType.E_ASSIGN;
                case "Assignment":      return EOperatorType.E_ASSIGN;
                case "Add":             return EOperatorType.E_ADD;
                case "Sub":             return EOperatorType.E_SUB;
                case "Mul":             return EOperatorType.E_MUL;
                case "Div":             return EOperatorType.E_DIV;
                case "Equal":           return EOperatorType.E_EQUAL;
                case "NotEqual":        return EOperatorType.E_NOTEQUAL;
                case "Greater":         return EOperatorType.E_GREATER;
                case "GreaterEqual":    return EOperatorType.E_GREATEREQUAL;
                case "Less":            return EOperatorType.E_LESS;
                case "LessEqual":       return EOperatorType.E_LESSEQUAL;
            }

            Debug.Check(false);
            return EOperatorType.E_INVALID;
        }

        private static bool MemberCompare(object left, object right)
        {
            if (Object.ReferenceEquals(left, right))
                return true;

            if (left == null || right == null)
                return false;

            Type type = left.GetType();
            if (type != right.GetType())
                return false;

            if (left as ValueType != null)
                return left.Equals(right);

            if (left as IEnumerable != null)
            {
                IEnumerator rightEnumerator = (right as IEnumerable).GetEnumerator();
                rightEnumerator.Reset();
                foreach (object leftItem in left as IEnumerable)
                {
                    if (!rightEnumerator.MoveNext())
                    {
                        return false;
                    }
                    else
                    {
                        if (!MemberCompare(leftItem, rightEnumerator.Current))
                            return false;
                    }
                }
            }
            else
            {
                Debug.Check(false);
            }

            return true;
        }

        public static bool Compare<T>(T left, T right, EOperatorType comparisonType)
        {
            Type type = typeof(T);

            if (Utils.IsCustomStructType(type) || Utils.IsArrayType(type))
            {
                switch (comparisonType)
                {
                    case EOperatorType.E_EQUAL: return MemberCompare(left, right);
                    case EOperatorType.E_NOTEQUAL: return !MemberCompare(left, right);
                }

                //switch (comparisonType)
                //{
                //    case EOperatorType.E_EQUAL: return Operator<T>.MemberEqual(left, right);
                //    case EOperatorType.E_NOTEQUAL: return !Operator<T>.MemberEqual(left, right);
                //}
            }
            else if (Utils.IsStringType(type) || type == typeof(bool))
            {
                switch (comparisonType)
                {
                    case EOperatorType.E_EQUAL: return Operator<T>.Equal(left, right);
                    case EOperatorType.E_NOTEQUAL: return Operator<T>.NotEqual(left, right);
                }
            }
            else if (Utils.IsEnumType(type) || type == typeof(char))
            {
                int iLeft = Convert.ToInt32(left);
                int iRight = Convert.ToInt32(right);

                switch (comparisonType)
                {
                    case EOperatorType.E_EQUAL: return Operator<int>.Equal(iLeft, iRight);
                    case EOperatorType.E_NOTEQUAL: return Operator<int>.NotEqual(iLeft, iRight);
                    case EOperatorType.E_GREATER: return Operator<int>.GreaterThan(iLeft, iRight);
                    case EOperatorType.E_GREATEREQUAL: return Operator<int>.GreaterThanOrEqual(iLeft, iRight);
                    case EOperatorType.E_LESS: return Operator<int>.LessThan(iLeft, iRight);
                    case EOperatorType.E_LESSEQUAL: return Operator<int>.LessThanOrEqual(iLeft, iRight);
                }
            }
            else
            {
                switch (comparisonType)
                {
                    case EOperatorType.E_EQUAL: return Operator<T>.Equal(left, right);
                    case EOperatorType.E_NOTEQUAL: return Operator<T>.NotEqual(left, right);
                    case EOperatorType.E_GREATER: return Operator<T>.GreaterThan(left, right);
                    case EOperatorType.E_GREATEREQUAL: return Operator<T>.GreaterThanOrEqual(left, right);
                    case EOperatorType.E_LESS: return Operator<T>.LessThan(left, right);
                    case EOperatorType.E_LESSEQUAL: return Operator<T>.LessThanOrEqual(left, right);
                }
            }

            Debug.Check(false);
            return false;
        }

        public static T Compute<T>(T left, T right, EOperatorType computeType)
        {
            Type type = typeof(T);

            if (!Utils.IsAgentType(type) && !Utils.IsCustomClassType(type) && !Utils.IsCustomStructType(type) && !Utils.IsArrayType(type) && !Utils.IsStringType(type))
            {
                if (Utils.IsEnumType(type) || type == typeof(char))
                {
                    int iLeft = Convert.ToInt32(left);
                    int iRight = Convert.ToInt32(right);

                    switch (computeType)
                    {
                        case EOperatorType.E_ADD: return (T)(object)Operator<int>.Add(iLeft, iRight);
                        case EOperatorType.E_SUB: return (T)(object)Operator<int>.Subtract(iLeft, iRight);
                        case EOperatorType.E_MUL: return (T)(object)Operator<int>.Multiply(iLeft, iRight);
                        case EOperatorType.E_DIV: return (T)(object)Operator<int>.Divide(iLeft, iRight);
                    }
                }
                else
                {
                    switch (computeType)
                    {
                        case EOperatorType.E_ADD: return Operator<T>.Add(left, right);
                        case EOperatorType.E_SUB: return Operator<T>.Subtract(left, right);
                        case EOperatorType.E_MUL: return Operator<T>.Multiply(left, right);
                        case EOperatorType.E_DIV: return Operator<T>.Divide(left, right);
                    }
                }
            }

            Debug.Check(false);
            return left;
        }
    }

    public class ValueConverter<T>
    {
        public static bool Convert(string valueStr, out T result)
        {
            result = (T)StringUtils.FromString(typeof(T), valueStr, false);

            return true;
        }
    }
}//namespace behaviac
