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

#ifndef _ENGINESERVICES_SCRIPTSERIALISATIONHELPERS_H_
#define _ENGINESERVICES_SCRIPTSERIALISATIONHELPERS_H_
#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA
#include "behaviac/base/core/string/stringid.h"

#include "behaviac/base/string/stringutils.h"
#include "behaviac/base/entity/entityid.h"
#include "behaviac/base/script/scriptreference.h"
#include "behaviac/base/script/scriptserialisation.h"
#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/script/lua/lua.h"

#define LUA_EXPOSED_CLASS() \
    LuaRegisterClass<objectType>();
#define LUA_OBJECT_INSTANCIATOR() \
    behaviac::string luaFunctionName("Get"); \
    luaFunctionName += objectType::GetClassTypeName(); \
    LuaRegisterFunction(NULL, luaFunctionName.c_str(), GetLuaObject<objectType>);

#define GENERATE_STATIC_FUNCTION_NAME(__func) \
    behaviac::string functionName(objectType::GetClassTypeName());     \
    functionName += "_";                                        \
    functionName += #__func;

/*
#define REGISTER_MEMBER_FUNCTION_ARG4(__func, __arg1, __arg2, __arg3, __arg4) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg4<objectType,__arg1,__arg2,__arg3,__arg4,&objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_ARG3(__func, __arg1, __arg2, __arg3) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg3<objectType,__arg1,__arg2,__arg3,&objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_ARG2(__func, __arg1, __arg2) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg2<objectType,__arg1,__arg2,&objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_ARG1(__func, __arg1) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg1<objectType,__arg1,&objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_ARG0(__func) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg0<objectType, &objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_RETURN(__func, __return) { \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionReturn<objectType, __return, &objectType::__func>); }
#define REGISTER_MEMBER_FUNCTION_RETURNPTR(__func, __return) { \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionReturnPtr<objectType, __return, &objectType::__func>); }
#define REGISTER_MEMBER_FUNCTION_ARG4_RETURN(__func, __arg1, __arg2, __arg3, __arg4, __return) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg4Return<objectType,__arg1,__arg2,__arg3,__arg4,__return,&objectType::__func>);
#define REGISTER_MEMBER_FUNCTION_ARG1_RETURN(__func, __arg1, __return) { \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg1Return<objectType, __arg1, __return, &objectType::__func>); }
#define REGISTER_MEMBER_FUNCTION_ARG1_RETURNPTR(__func, __arg1, __return) { \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg1ReturnPtr<objectType, __arg1, __return, &objectType::__func>); }
*/
#define REGISTER_MEMBER_FUNCTION_ARG2VList(__func, __arg1, __arg2) { \
        LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg2vlist<objectType, __arg1, __arg2, &objectType::__func>); }
#define REGISTER_MEMBER_FUNCTION_ARG2VList_RETURN(__func, __arg1, __arg2, __return) { \
        LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg2vlistReturn<objectType, __arg1, __arg2, __return, &objectType::__func>); }
#define REGISTER_MEMBER_FUNCTION_ARG4VList_RETURN(__func, __arg1, __arg2, __arg3, __arg4, __return) { \
        LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GenericScriptFunctionArg4vlistReturn<objectType, __arg1, __arg2, __arg3, __arg4, __return, &objectType::__func>); }

/*
#define REGISTER_STATIC_MEMBER_FUNCTION_ARG2(__func, __arg1, __arg2) { \
    GENERATE_STATIC_FUNCTION_NAME(__func)                      \
    LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionArg2<__arg1, __arg2, objectType::__func>); }
#define REGISTER_STATIC_MEMBER_FUNCTION_ARG1(__func, __arg1) { \
    GENERATE_STATIC_FUNCTION_NAME(__func)                      \
    LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionArg1<__arg1, objectType::__func>); }
#define REGISTER_STATIC_MEMBER_FUNCTION_ARG0(__func) { \
    GENERATE_STATIC_FUNCTION_NAME(__func)              \
    LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionArg0<objectType::__func>); }
*/
#define REGISTER_STATIC_MEMBER_FUNCTION_RETURN(__func, __return) { \
        GENERATE_STATIC_FUNCTION_NAME(__func)               \
        LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionReturn<__return, objectType::__func>); }
#define REGISTER_STATIC_MEMBER_FUNCTION_RETURNPTR(__func, __return) { \
        GENERATE_STATIC_FUNCTION_NAME(__func)               \
        LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionReturnPtr<__return, objectType::__func>); }
#define REGISTER_STATIC_MEMBER_FUNCTION_ARG1_RETURN(__func, __arg1, __return) { \
        GENERATE_STATIC_FUNCTION_NAME(__func)               \
        LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionReturnArg1<__return, __arg1, objectType::__func>); }
#define REGISTER_STATIC_MEMBER_FUNCTION_ARG1_RETURNPTR(__func, __arg1, __return) { \
        GENERATE_STATIC_FUNCTION_NAME(__func)               \
        LuaRegisterFunction(NULL,functionName.c_str(),GenericScriptStaticFunctionReturnPtrArg1<__return, __arg1, objectType::__func>); }

template<class ObjectType>
int GetLuaObject(lua_State* lua_state)
{
    ObjectType* bindingObject = BEHAVIAC_NEW ObjectType;
    *(ObjectType**)lua_newuserdata(lua_state, sizeof(ObjectType*)) = bindingObject;
    CScriptSystem::GetInstance()->SetTag(lua_state, ObjectType::GetScriptTag());
    return 1;
}

//
// CompareArgType
//
template<class ParamType>
inline bool CompareArgType(int luaType)
{
    if (luaType == LUA_TNUMBER)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a number as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<bool>(int luaType)
{
    if (luaType == LUA_TNUMBER)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a number as the LUA argument (for bool)");
    return false;
}

template<>
inline bool CompareArgType<CScriptReferenceRef>(int luaType)
{
    if (luaType == LUA_TTABLE ||
        luaType == LUA_TFUNCTION)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a table/function as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<const char*>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<const wchar_t*>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<behaviac::string>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<CStringID>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<CPathID>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument for CPathID");
    return false;
}

template<>
inline bool CompareArgType<CNoCaseStringID>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument for CNoCaseStringID");
    return false;
}

template<>
inline bool CompareArgType<uint64_t>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string (uint64_t) as the LUA argument");
    return false;
}

template<>
inline bool CompareArgType<EntityId>(int luaType)
{
    if (luaType == LUA_TSTRING)
    {
        return true;
    }

    BEHAVIAC_LOGWARNING("Expecting a behaviac::string (uint64_t) as the LUA argument");
    return false;
}

template<class ParamType>
inline bool CompareArgs(lua_State* lua_state, int startIndex, int args)
{
    for (int i = 0; i < args; ++i)
    {
        if (!CompareArgType<ParamType>(lua_type(lua_state, startIndex + i)))
        {
            return false;
        }
    }

    return true;
}

template<>
inline bool CompareArgs<behaviac::string>(lua_State* lua_state, int startIndex, int args)
{
    for (int i = 0; i < args; ++i)
    {
        int type = lua_type(lua_state, startIndex + i);

        if (type != LUA_TSTRING &&
            type != LUA_TNUMBER)
        {
            BEHAVIAC_LOGWARNING("Expecting a behaviac::string as the LUA argument");
            return false;
        }
    }

    return true;
}


//////////////////////////////////////////////////////////////////////////
// RetrieveParam
//
template<class ParamType>
inline ParamType RetrieveParam(lua_State* lua_state, int index)
{
    return (ParamType)lua_tonumber(lua_state, index);
}

template<>
inline bool RetrieveParam<bool>(lua_State* lua_state, int index)
{
    int value = (int)lua_tonumber(lua_state, index);
    return (value == 0 ? false : true);
}

template<>
inline CScriptReferenceRef RetrieveParam<CScriptReferenceRef>(lua_State* lua_state, int index)
{
    return BEHAVIAC_NEW CScriptReference(lua_state, index);
}

template<>
inline uint64_t RetrieveParam<uint64_t>(lua_State* lua_state, int index)
{
    const char* idStr = (const char*)lua_tostring(lua_state, index);
    uint64_t id;
    sscanf(idStr, "%llu", &id);
    return id;
}

template<>
inline EntityId RetrieveParam<EntityId>(lua_State* lua_state, int index)
{
    const char* entityIdStr = (const char*)lua_tostring(lua_state, index);
    EntityId::IdType id;
    sscanf(entityIdStr, "%llu", &id);
    EntityId entityId(id);
    return entityId;
}

template<>
inline const char* RetrieveParam<const char*>(lua_State* lua_state, int index)
{
    return (const char*)lua_tostring(lua_state, index);
}

template<>
inline const wchar_t* RetrieveParam<const wchar_t*>(lua_State* lua_state, int index)
{
    return behaviac::StringUtils::Char2Wide(lua_tostring(lua_state, index)).c_str();
}

template<>
inline behaviac::string RetrieveParam<behaviac::string>(lua_State* lua_state, int index)
{
    return behaviac::string(lua_tostring(lua_state, index));
}

template<>
inline CStringID RetrieveParam<CStringID>(lua_State* lua_state, int index)
{
    return CStringID(lua_tostring(lua_state, index));
}

template<>
inline CNoCaseStringID RetrieveParam<CNoCaseStringID>(lua_State* lua_state, int index)
{
    return CNoCaseStringID(lua_tostring(lua_state, index));
}

template<>
inline CPathID RetrieveParam<CPathID>(lua_State* lua_state, int index)
{
    return CPathID(lua_tostring(lua_state, index));
}


template<class ParamType>
inline void RetrieveArgs(lua_State* lua_state, int startIndex, int args, behaviac::vector<ParamType>& argsList)
{
    for (int i = 0; i < args; ++i)
    {
        argsList.push_back(RetrieveParam<ParamType>(lua_state, startIndex + i));
    }
}

//
// RetrieveParam
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// PushLuaReturnValue
//
template<class ReturnType>
inline int PushLuaReturnValue(lua_State* L, const ReturnType& value)
{
    BEHAVIAC_LOGERROR("[PushLuaReturnValue()] - An undefined type is being returned to LUA.  Notify a programmer.");
    lua_pushnil(L);
    return 1;
}

template<>
inline int PushLuaReturnValue<double>(lua_State* L, const double& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<float>(lua_State* L, const float& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<int>(lua_State* L, const int& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<uint8_t>(lua_State* L, const uint8_t& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<uint32_t>(lua_State* L, const uint32_t& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<uint64_t>(lua_State* L, const uint64_t& value)
{
    // LUA does not support 64 bit numbers
    // convert the number to behaviac::string
    char str[1024];
	string_snprintf(str, 1024 - 1, "%llu", value);
    str[1023] = 0; // buffer overrun ensure
    lua_pushstring(L, str);
    return 1;
}

template<>
inline int PushLuaReturnValue<EntityId>(lua_State* L, const EntityId& value)
{
    // LUA does not support 64 bit numbers
    // convert the number to behaviac::string
    char str[1024];
	string_snprintf(str, 1024 - 1, "%llu", value.GetUniqueID());
    str[1023] = 0; // buffer overrun ensure
    lua_pushstring(L, str);
    return 1;
}

template<>
inline int PushLuaReturnValue<bool>(lua_State* L, const bool& value)
{
    lua_pushnumber(L, (lua_Number)value);
    return 1;
}

template<>
inline int PushLuaReturnValue<behaviac::string>(lua_State* L, const behaviac::string& value)
{
    lua_pushlstring(L, value.c_str(), value.length());
    return 1;
}

//template<>
//inline int PushLuaReturnValue<behaviac::string>(lua_State* L, const behaviac::string& value)
//{
//    lua_pushlstring(L, value.c_str(), value.size());
//    return 1;
//}

template<>
inline int PushLuaReturnValue<CStringID>(lua_State* L, const CStringID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}

template<>
inline int PushLuaReturnValue<CStringID const>(lua_State* L, const CStringID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}

template<>
inline int PushLuaReturnValue<CNoCaseStringID>(lua_State* L, const CNoCaseStringID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}
template<>
inline int PushLuaReturnValue<CNoCaseStringID const>(lua_State* L, const CNoCaseStringID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}

template<>
inline int PushLuaReturnValue<CPathID>(lua_State* L, const CPathID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}
template<>
inline int PushLuaReturnValue<CPathID const>(lua_State* L, const CPathID& value)
{
    return PushLuaReturnValue(L, value.LogStr());
}

typedef char* CharPointer;
template<>
inline int PushLuaReturnValue<CharPointer>(lua_State* L, const CharPointer& value)
{
    lua_pushlstring(L, value, strlen(value));
    return 1;
}

//typedef char const* ConstCharPointer;
//template<>
//inline int PushLuaReturnValue<ConstCharPointer>(lua_State* L, const ConstCharPointer& value)
//{
//    lua_pushlstring(L, value, strlen(value));
//    return 1;
//}

typedef IScriptObject* IScriptObjectPointer;
template<>
inline int PushLuaReturnValue<IScriptObjectPointer>(lua_State* L, const IScriptObjectPointer& value)
{
    lua_xgetref(L, value->GetRef());
    return 1;
}

template<>
inline int PushLuaReturnValue<behaviac::vector<behaviac::string> >(lua_State* L, const behaviac::vector<behaviac::string>& value)
{
    uint32_t size = value.size();
    lua_newtable(L);

    for (uint32_t i = 0; i < size; ++i)
    {
        PushLuaReturnValue(L, value[i]);
        lua_rawseti(L, -2, i + 1);
    }

    return 1;
}


template<>
inline int PushLuaReturnValue<behaviac::Vector3>(lua_State* L, const behaviac::Vector3& value)
{
    uint32_t size = 3;
    lua_newtable(L);

    for (uint32_t i = 0; i < size; ++i)
    {
        PushLuaReturnValue(L, value[i]);
        lua_rawseti(L, -2, i + 1);
    }

    return 1;
}

template<>
inline int PushLuaReturnValue<behaviac::vector<EntityId> >(lua_State* L, const behaviac::vector<EntityId>& value)
{
    uint32_t size = value.size();
    lua_newtable(L);

    for (uint32_t i = 0; i < size; ++i)
    {
        PushLuaReturnValue(L, value[i]);
        lua_rawseti(L, -2, i + 1);
    }

    return 1;
}

template<class ReturnType>
struct PushHelper
{
    static int Push(lua_State* L, const ReturnType& value)
    {
        lua_pushnil(L);
        return 1;
    }
};

template<class ReturnType>
struct PushHelper<ReturnType*>
{
    static int Push(lua_State* L, ReturnType* value)
    {
        if (value)
        {
            *(ReturnType**)lua_newuserdata(L, 4) = const_cast<ReturnType*>(value);
            CScriptSystem::GetInstance()->SetTag(L, ReturnType::GetScriptTag());
        }
        else
        {
            //BEHAVIAC_LOGERROR("Unable to return value pointer - probable error in Domino scripts - returning nil");
            lua_pushnil(L);
        }

        return 1;
    }
};

template<>
struct PushHelper<const char*>
{
    static int Push(lua_State* L, const char*& value)
    {
        lua_pushlstring(L, value, strlen(value));
        return 1;
    }
};

template<>
struct PushHelper<double>
{
    static int Push(lua_State* L, const double& value)
    {
        lua_pushnumber(L, (lua_Number)value);
        return 1;
    }
};

template<>
struct PushHelper<int>
{
    static int Push(lua_State* L, const int& value)
    {
        lua_pushnumber(L, (lua_Number)value);
        return 1;
    }
};

template<>
struct PushHelper<uint64_t>
{
    static int PushLuaReturnValue(lua_State* L, const uint64_t& value)
    {
        // LUA does not support 64 bit numbers
        // convert the number to behaviac::string
        char str[1024];
		string_snprintf(str, 1024 - 1, "%llu", value);
        str[1023] = 0; // buffer overrun ensure
        lua_pushstring(L, str);
        return 1;
    }
};

template<>
struct PushHelper<EntityId>
{
    static int Push(lua_State* L, const EntityId& value)
    {
        // LUA does not support 64 bit numbers
        // convert the number to behaviac::string
        char str[1024];
		string_snprintf(str, 1024 - 1, "%llu", value.GetUniqueID());
        str[1023] = 0; // buffer overrun ensure
        lua_pushstring(L, str);
        return 1;
    }
};

template<>
struct PushHelper<bool>
{
    static int Push(lua_State* L, const bool& value)
    {
        lua_pushnumber(L, (lua_Number)value);
        return 1;
    }
};

template<>
struct PushHelper<behaviac::string>
{
    static int Push(lua_State* L, const behaviac::string& value)
    {
        lua_pushlstring(L, value.c_str(), value.length());
        return 1;
    }
};

template<>
struct PushHelper<CStringID>
{
    static int Push(lua_State* L, const CStringID& value)
    {
        return PushHelper<behaviac::string>::Push(L, value.LogStr());
    }
};

template<>
struct PushHelper<CStringID const>
{
    static int Push(lua_State* L, const CStringID& value)
    {
        return PushHelper<behaviac::string>::Push(L, value.LogStr());
    }
};

template<>
struct PushHelper<CPathID>
{
    static int Push(lua_State* L, const CPathID& value)
    {
        return PushHelper<behaviac::string>::Push(L, value.LogStr());
    }
};

template<>
struct PushHelper<CPathID const>
{
    static int Push(lua_State* L, const CPathID& value)
    {
        return PushHelper<behaviac::string>::Push(L, value.LogStr());
    }
};

typedef char* CharPointer;
template<>
struct PushHelper<CharPointer>
{
    static int Push(lua_State* L, const CharPointer& value)
    {
        lua_pushlstring(L, value, strlen(value));
        return 1;
    }
};

typedef IScriptObject* IScriptObjectPointer;
template<>
struct PushHelper<IScriptObjectPointer>
{
    static int Push(lua_State* L, const IScriptObjectPointer& value)
    {
        return lua_xgetref(L, value->GetRef());
    }
};
//
// PushLuaReturnValue
//////////////////////////////////////////////////////////////////////////

template<class ObjectType>
int GenericScriptFunctionArg0(lua_State* lua_state, void (ObjectType::*methodPtr)())
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)();
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, void (ObjectType::*MethodPtr)()>
inline int GenericScriptFunctionArg0(lua_State* lua_state)
{
    return GenericScriptFunctionArg0(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType>
inline int GenericScriptFunctionArg1(lua_State* lua_state, void (ObjectType::*methodPtr)(ParamType))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 2 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType>(lua_type(lua_state, 2)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType>
inline int GenericScriptFunctionArg1(lua_State* lua_state, void (ObjectType::*methodPtr)(const ParamType&))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 2 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType>(lua_type(lua_state, 2)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType, void (ObjectType::*MethodPtr)(ParamType)>
inline int GenericScriptFunctionArg1(lua_State* lua_state)
{
    return GenericScriptFunctionArg1(lua_state, MethodPtr);
}


template<class ObjectType, class ParamType1, class ParamType2>
inline int GenericScriptFunctionArg2(lua_State* lua_state, void (ObjectType::*methodPtr)(ParamType1, ParamType2))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 3 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2), RetrieveParam<ParamType2>(lua_state, 3));
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, void (ObjectType::*MethodPtr)(ParamType1, ParamType2)>
inline int GenericScriptFunctionArg2(lua_State* lua_state)
{
    return GenericScriptFunctionArg2(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3>
inline int GenericScriptFunctionArg3(lua_State* lua_state, void (ObjectType::*methodPtr)(ParamType1, ParamType2, ParamType3))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 4 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 4)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                               RetrieveParam<ParamType2>(lua_state, 3),
                               RetrieveParam<ParamType3>(lua_state, 4));
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, void (ObjectType::*MethodPtr)(ParamType1, ParamType2, ParamType3)>
inline int GenericScriptFunctionArg3(lua_State* lua_state)
{
    return GenericScriptFunctionArg3(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
inline int GenericScriptFunctionArg4(lua_State* lua_state, void (ObjectType::*methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 5 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 5)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                               RetrieveParam<ParamType2>(lua_state, 3),
                               RetrieveParam<ParamType3>(lua_state, 4),
                               RetrieveParam<ParamType4>(lua_state, 5));
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, void (ObjectType::*MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4)>
inline int GenericScriptFunctionArg4(lua_State* lua_state)
{
    return GenericScriptFunctionArg4(lua_state, MethodPtr);
}

template<class ObjectType, class ReturnType>
inline int GenericScriptFunctionReturn(lua_State* lua_state, ReturnType(ObjectType::*methodPtr)())
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            ReturnType value = (self->*methodPtr)();
            return PushLuaReturnValue(lua_state, value);
        }
    }

    return 0;
}

template<class ObjectType, class ReturnType, ReturnType(ObjectType::*MethodPtr)()>
inline int GenericScriptFunctionReturn(lua_State* lua_state)
{
    return GenericScriptFunctionReturn(lua_state, MethodPtr);
}

template<class ObjectType, class ReturnType>
inline int GenericScriptFunctionReturnLuaObject(lua_State* lua_state, ReturnType * (ObjectType::*methodPtr)())
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            ReturnType* value = (self->*methodPtr)();
            *(ReturnType**)lua_newuserdata(lua_state, 4) = value;
            CScriptSystem::GetInstance()->SetTag(lua_state, ReturnType::GetScriptTag());
            return 1;
        }
    }

    return 0;
}

// this should only be used for LUA exposed objects
template<class ObjectType, class ReturnType, ReturnType* (ObjectType::*MethodPtr)()>
inline int GenericScriptFunctionReturnPtr(lua_State* lua_state)
{
    return GenericScriptFunctionReturnLuaObject(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType, class ReturnType>
inline int GenericScriptFunctionArg1Return(lua_State* lua_state, ReturnType(ObjectType::*methodPtr)(ParamType))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 2 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType>(lua_type(lua_state, 2)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
            return PushLuaReturnValue(lua_state, value);
        }
    }

    return 0;
}

template<class ObjectType, class ParamType, class ReturnType, ReturnType(ObjectType::*MethodPtr)(ParamType)>
inline int GenericScriptFunctionArg1Return(lua_State* lua_state)
{
    return GenericScriptFunctionArg1Return(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ReturnType>
inline int GenericScriptFunctionArg4Return(lua_State* lua_state, ReturnType(ObjectType::*methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 5 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 5)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                  RetrieveParam<ParamType2>(lua_state, 3),
                                                  RetrieveParam<ParamType3>(lua_state, 4),
                                                  RetrieveParam<ParamType4>(lua_state, 5));
            return PushLuaReturnValue(lua_state, value);
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ReturnType, ReturnType(ObjectType::*MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4)>
inline int GenericScriptFunctionArg4Return(lua_State* lua_state)
{
    return GenericScriptFunctionArg4Return(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType, class ReturnType>
inline int GenericScriptFunctionArg1ReturnLuaObject(lua_State* lua_state, ReturnType * (ObjectType::*methodPtr)(ParamType))
{
    int objectTag = LuaGetTag(lua_state, 1);

    if (lua_gettop(lua_state) == 2 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType>(lua_type(lua_state, 2)))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            ReturnType* value = (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
            *(ReturnType**)lua_newuserdata(lua_state, 4) = value;
            CScriptSystem::GetInstance()->SetTag(lua_state, ReturnType::GetScriptTag());
            return 1;
        }
    }

    return 0;
}

// this should only be used for LUA exposed objects
template<class ObjectType, class ParamType, class ReturnType, ReturnType* (ObjectType::*MethodPtr)(ParamType)>
inline int GenericScriptFunctionArg1ReturnPtr(lua_State* lua_state)
{
    return GenericScriptFunctionArg1ReturnLuaObject(lua_state, MethodPtr);
}


template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ReturnType>
inline int GenericScriptFunctionArg4vlistReturn(lua_State* lua_state, ReturnType(ObjectType::*methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, const behaviac::vector<behaviac::string>&))
{
    int objectTag = LuaGetTag(lua_state, 1);
    int nbArguments = lua_gettop(lua_state);

    if (nbArguments >= 5 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
        CompareArgs<behaviac::string>(lua_state, 6, nbArguments - 5))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            behaviac::vector<behaviac::string> args;
            args.reserve(nbArguments - 5);
            RetrieveArgs(lua_state, 6, nbArguments - 5, args);
            ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                  RetrieveParam<ParamType2>(lua_state, 3),
                                                  RetrieveParam<ParamType3>(lua_state, 4),
                                                  RetrieveParam<ParamType4>(lua_state, 5),
                                                  args);
            return PushLuaReturnValue(lua_state, value);
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ReturnType, ReturnType(ObjectType::*MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, const behaviac::vector<behaviac::string>&)>
inline int GenericScriptFunctionArg4vlistReturn(lua_State* lua_state)
{
    return GenericScriptFunctionArg4vlistReturn(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType1, class ParamType2>
inline int GenericScriptFunctionArg2vlist(lua_State* lua_state, void (ObjectType::*methodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&))
{
    int objectTag = LuaGetTag(lua_state, 1);
    int nbArguments = lua_gettop(lua_state);

    if (nbArguments >= 3 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgs<behaviac::string>(lua_state, 4, nbArguments - 3))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            behaviac::vector<behaviac::string> args;
            args.reserve(nbArguments - 3);
            RetrieveArgs(lua_state, 4, nbArguments - 3, args);
            (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                               RetrieveParam<ParamType2>(lua_state, 3),
                               args);
            return 1;
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, void (ObjectType::*MethodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&)>
inline int GenericScriptFunctionArg2vlist(lua_State* lua_state)
{
    return GenericScriptFunctionArg2vlist(lua_state, MethodPtr);
}

template<class ObjectType, class ParamType1, class ParamType2, class ReturnType>
inline int GenericScriptFunctionArg2vlistReturn(lua_State* lua_state, ReturnType(ObjectType::*methodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&))
{
    int objectTag = LuaGetTag(lua_state, 1);
    int nbArguments = lua_gettop(lua_state);

    if (nbArguments >= 3 &&
        CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
        CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
        CompareArgs<behaviac::string>(lua_state, 4, nbArguments - 3))
    {
        ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

        if (self)
        {
            behaviac::vector<behaviac::string> args;
            args.reserve(nbArguments - 3);
            RetrieveArgs(lua_state, 4, nbArguments - 3, args);
            ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                  RetrieveParam<ParamType2>(lua_state, 3),
                                                  args);
            return PushLuaReturnValue(lua_state, value);
        }
    }

    return 0;
}

template<class ObjectType, class ParamType1, class ParamType2, class ReturnType, ReturnType(ObjectType::*MethodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&)>
inline int GenericScriptFunctionArg2vlistReturn(lua_State* lua_state)
{
    return GenericScriptFunctionArg2vlistReturn(lua_state, MethodPtr);
}

template<class ReturnType>
inline int GenericScriptStaticFunctionReturn(lua_State* lua_state, ReturnType(methodPtr)())
{
    if (lua_gettop(lua_state) == 0)
    {
        ReturnType value = (methodPtr)();
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType>
inline int GenericScriptStaticFunctionReturn(lua_State* lua_state, ReturnType * (methodPtr)())
{
    if (lua_gettop(lua_state) == 0)
    {
        ReturnType* value = (methodPtr)();
        *(ReturnType**)lua_newuserdata(lua_state, 4) = value;
        CScriptSystem::GetInstance()->SetTag(lua_state, ReturnType::GetScriptTag());
        return 1;
    }

    return 0;
}

template<class ReturnType, ReturnType(MethodPtr)()>
inline int GenericScriptStaticFunctionReturn(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturn(lua_state, MethodPtr);
}

template<class ReturnType, ReturnType* (MethodPtr)()>
inline int GenericScriptStaticFunctionReturnPtr(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturn(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType>
inline int GenericScriptStaticFunctionReturnArg1(lua_State* lua_state, ReturnType(methodPtr)(ParamType))
{
    if (lua_gettop(lua_state) == 1 &&
        CompareArgType<ParamType>(lua_type(lua_state, 1)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType>(lua_state, 1));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType>
inline int GenericScriptStaticFunctionReturnArg1(lua_State* lua_state, ReturnType * (methodPtr)(ParamType))
{
    if (lua_gettop(lua_state) == 1 &&
        CompareArgType<ParamType>(lua_type(lua_state, 1)))
    {
        ReturnType* value = (methodPtr)(RetrieveParam<ParamType>(lua_state, 1));
        return PushHelper<ReturnType*>::Push(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType, ReturnType(MethodPtr)(ParamType)>
inline int GenericScriptStaticFunctionReturnArg1(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg1(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType, ReturnType* (MethodPtr)(ParamType)>
inline int GenericScriptStaticFunctionReturnPtrArg1(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg1(lua_state, MethodPtr);
}


template<class ReturnType, class ParamType1, class ParamType2>
inline int GenericScriptStaticFunctionReturnArg2(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2))
{
    if (lua_gettop(lua_state) == 2 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType1, class ParamType2, ReturnType(MethodPtr)(ParamType1, ParamType2)>
inline int GenericScriptStaticFunctionReturnArg2(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg2(lua_state, MethodPtr);
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3>
inline int GenericScriptStaticFunctionReturnArg3(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3))
{
    if (lua_gettop(lua_state) == 3 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3)>
inline int GenericScriptStaticFunctionReturnArg3(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg3(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
inline int GenericScriptStaticFunctionReturnArg4(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
{
    if (lua_gettop(lua_state) == 4 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4)>
inline int GenericScriptStaticFunctionReturnArg4(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg4(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
inline int GenericScriptStaticFunctionReturnArg5(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5))
{
    if (lua_gettop(lua_state) == 5 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5)>
inline int GenericScriptStaticFunctionReturnArg5(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg5(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
inline int GenericScriptStaticFunctionReturnArg6(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6))
{
    if (lua_gettop(lua_state) == 6 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType6>(lua_type(lua_state, 6)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5),
                                       RetrieveParam<ParamType6>(lua_state, 6));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6)>
inline int GenericScriptStaticFunctionReturnArg6(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg6(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7>
inline int GenericScriptStaticFunctionReturnArg7(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7))
{
    if (lua_gettop(lua_state) == 7 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType6>(lua_type(lua_state, 6)) &&
        CompareArgType<ParamType7>(lua_type(lua_state, 7)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5),
                                       RetrieveParam<ParamType6>(lua_state, 6),
                                       RetrieveParam<ParamType7>(lua_state, 7));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}


template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7)>
inline int GenericScriptStaticFunctionReturnArg7(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg7(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8>
inline int GenericScriptStaticFunctionReturnArg8(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8))
{
    if (lua_gettop(lua_state) == 8 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType6>(lua_type(lua_state, 6)) &&
        CompareArgType<ParamType7>(lua_type(lua_state, 7)) &&
        CompareArgType<ParamType8>(lua_type(lua_state, 8)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5),
                                       RetrieveParam<ParamType6>(lua_state, 6),
                                       RetrieveParam<ParamType7>(lua_state, 7),
                                       RetrieveParam<ParamType8>(lua_state, 8));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8)>
inline int GenericScriptStaticFunctionReturnArg8(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg8(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8, class ParamType9>
inline int GenericScriptStaticFunctionReturnArg9(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8, ParamType9))
{
    if (lua_gettop(lua_state) == 9 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType6>(lua_type(lua_state, 6)) &&
        CompareArgType<ParamType7>(lua_type(lua_state, 7)) &&
        CompareArgType<ParamType8>(lua_type(lua_state, 8)) &&
        CompareArgType<ParamType9>(lua_type(lua_state, 9)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5),
                                       RetrieveParam<ParamType6>(lua_state, 6),
                                       RetrieveParam<ParamType7>(lua_state, 7),
                                       RetrieveParam<ParamType8>(lua_state, 8),
                                       RetrieveParam<ParamType9>(lua_state, 9));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8, class ParamType9, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8, ParamType9)>
inline int GenericScriptStaticFunctionReturnArg9(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg9(lua_state, MethodPtr);
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8, class ParamType9, class ParamType10>
inline int GenericScriptStaticFunctionReturnArg10(lua_State* lua_state, ReturnType(methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8, ParamType9, ParamType10))
{
    if (lua_gettop(lua_state) == 10 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType6>(lua_type(lua_state, 6)) &&
        CompareArgType<ParamType7>(lua_type(lua_state, 7)) &&
        CompareArgType<ParamType8>(lua_type(lua_state, 8)) &&
        CompareArgType<ParamType9>(lua_type(lua_state, 9)) &&
        CompareArgType<ParamType10>(lua_type(lua_state, 10)))
    {
        ReturnType value = (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                                       RetrieveParam<ParamType2>(lua_state, 2),
                                       RetrieveParam<ParamType3>(lua_state, 3),
                                       RetrieveParam<ParamType4>(lua_state, 4),
                                       RetrieveParam<ParamType5>(lua_state, 5),
                                       RetrieveParam<ParamType6>(lua_state, 6),
                                       RetrieveParam<ParamType7>(lua_state, 7),
                                       RetrieveParam<ParamType8>(lua_state, 8),
                                       RetrieveParam<ParamType9>(lua_state, 9),
                                       RetrieveParam<ParamType10>(lua_state, 10));
        return PushLuaReturnValue(lua_state, value);
    }

    return 0;
}

template<class ReturnType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8, class ParamType9, class ParamType10, ReturnType(MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8, ParamType9, ParamType10)>
inline int GenericScriptStaticFunctionReturnArg10(lua_State* lua_state)
{
    return GenericScriptStaticFunctionReturnArg10(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2>
inline int GenericScriptStaticFunctionArg2vlist(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&))
{
    int nbArguments = lua_gettop(lua_state);

    if (nbArguments >= 2 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgs<behaviac::string>(lua_state, 3, nbArguments - 2))
    {
        behaviac::vector<behaviac::string> args;
        args.reserve(nbArguments - 2);
        RetrieveArgs(lua_state, 3, nbArguments - 2, args);
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                    RetrieveParam<ParamType2>(lua_state, 2),
                    args);
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, void (MethodPtr)(ParamType1, ParamType2, const behaviac::vector<behaviac::string>&)>
inline int GenericScriptStaticFunctionArg2vlist(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg2vlist(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2>
inline int GenericScriptStaticFunctionArg1vlist(lua_State* lua_state, void (methodPtr)(ParamType1, const behaviac::vector<ParamType2>&))
{
    int nbArguments = lua_gettop(lua_state);

    if (nbArguments >= 1 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgs<ParamType2>(lua_state, 2, nbArguments - 1))
    {
        behaviac::vector<ParamType2> args;
        args.reserve(nbArguments - 1);
        RetrieveArgs(lua_state, 2, nbArguments - 1, args);
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1),
                    args);
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, void (MethodPtr)(ParamType1, const behaviac::vector<ParamType2>&)>
inline int GenericScriptStaticFunctionArg1vlist(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg1vlist(lua_state, MethodPtr);
}

inline int GenericScriptStaticFunctionArg0(lua_State* lua_state, void (methodPtr)())
{
    if (lua_gettop(lua_state) == 0)
    {
        (methodPtr)();
        return 1;
    }

    return 0;
}

template<void (MethodPtr)()>
inline int GenericScriptStaticFunctionArg0(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg0(lua_state, MethodPtr);
}

template<class ParamType>
inline int GenericScriptStaticFunctionArg1(lua_State* lua_state, void (methodPtr)(ParamType))
{
    if (lua_gettop(lua_state) == 1 &&
        CompareArgType<ParamType>(lua_type(lua_state, 1)))
    {
        (methodPtr)(RetrieveParam<ParamType>(lua_state, 1));
        return 1;
    }

    return 0;
}

template<class ParamType, void (MethodPtr)(ParamType)>
inline int GenericScriptStaticFunctionArg1(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg1(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2>
inline int GenericScriptStaticFunctionArg2(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2))
{
    if (lua_gettop(lua_state) == 2 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)))
    {
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2));
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, void (MethodPtr)(ParamType1, ParamType2)>
inline int GenericScriptStaticFunctionArg2(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg2(lua_state, MethodPtr);
}


template<class ParamType1, class ParamType2, class ParamType3>
inline int GenericScriptStaticFunctionArg3(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2, ParamType3))
{
    if (lua_gettop(lua_state) == 3 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)))
    {
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2), RetrieveParam<ParamType3>(lua_state, 3));
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, class ParamType3, void (MethodPtr)(ParamType1, ParamType2, ParamType3)>
inline int GenericScriptStaticFunctionArg3(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg3(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2, class ParamType3, class ParamType4>
inline int GenericScriptStaticFunctionArg4(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
{
    if (lua_gettop(lua_state) == 4 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)))
    {
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2), RetrieveParam<ParamType3>(lua_state, 3), RetrieveParam<ParamType4>(lua_state, 4));
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, class ParamType3, class ParamType4, void (MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4)>
inline int GenericScriptStaticFunctionArg4(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg4(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
inline int GenericScriptStaticFunctionArg5(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5))
{
    if (lua_gettop(lua_state) == 5 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)))
    {
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2), RetrieveParam<ParamType3>(lua_state, 3), RetrieveParam<ParamType4>(lua_state, 4), RetrieveParam<ParamType5>(lua_state, 5));
        return 1;
    }

    return 0;
}

template<class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, void (MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5)>
inline int GenericScriptStaticFunctionArg5(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg5(lua_state, MethodPtr);
}

template<class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
inline int GenericScriptStaticFunctionArg6(lua_State* lua_state, void (methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6))
{
    if (lua_gettop(lua_state) == 6 &&
        CompareArgType<ParamType1>(lua_type(lua_state, 1)) &&
        CompareArgType<ParamType2>(lua_type(lua_state, 2)) &&
        CompareArgType<ParamType3>(lua_type(lua_state, 3)) &&
        CompareArgType<ParamType4>(lua_type(lua_state, 4)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 5)) &&
        CompareArgType<ParamType5>(lua_type(lua_state, 6)))
    {
        (methodPtr)(RetrieveParam<ParamType1>(lua_state, 1), RetrieveParam<ParamType2>(lua_state, 2), RetrieveParam<ParamType3>(lua_state, 3), RetrieveParam<ParamType4>(lua_state, 4), RetrieveParam<ParamType5>(lua_state, 5), RetrieveParam<ParamType6>(lua_state, 6));
        return 1;
    }

    return 0;
}


template<class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, void (MethodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6)>
inline int GenericScriptStaticFunctionArg6(lua_State* lua_state)
{
    return GenericScriptStaticFunctionArg6(lua_state, MethodPtr);
}


////////////////////////////////////////////////////////////////////////////////
//
#define REGISTER_MEMBER_FUNCTION(__func) \
    LuaRegisterFunction(objectType::GetClassTypeName(),#__func,GetGenericFunctionHelper(&objectType::__func).GetGenericFunctionToCall<&objectType::__func>());

/*
#define REGISTER_STATIC_MEMBER_FUNCTION(__func)     \
    GENERATE_STATIC_FUNCTION_NAME(__func)           \
    LuaRegisterFunction(NULL,functionName.c_str(),GetGenericFunctionHelper(objectType::__func).GetGenericFunctionToCall<objectType::__func>());
*/

//////////////////////////////////////////////////////////////////////////
// 0 arg
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType>
struct CallerArg0
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)())
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)();
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)() const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)();
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    static int Call(lua_State* lua_state, ReturnType * (ObjectType::* methodPtr)())
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType* value = (self->*methodPtr)();
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType>
struct CallerArg0<void, ObjectType>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)())
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)();
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)() const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)();
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType>
struct CallerArg0<ReturnType*, ObjectType>
{
    static int Call(lua_State* lua_state, ReturnType * (ObjectType::* methodPtr)())
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType* value = (self->*methodPtr)();
                return PushHelper<ReturnType*>::Push(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ReturnType>
struct CallerArg0Static
{
    // static function
    static int Call(lua_State* lua_state, ReturnType(methodPtr)())
    {
        if (lua_gettop(lua_state) == 0)
        {
            ReturnType value = (methodPtr)();
            return PushHelper<ReturnType>::Push(lua_state, value);
        }

        return 0;
    }
};

template <class ReturnType>
struct CallerArg0Static<ReturnType*>
{
    // static function
    static int Call(lua_State* lua_state, ReturnType * (methodPtr)())
    {
        if (lua_gettop(lua_state) == 0)
        {
            ReturnType* value = (methodPtr)();
            return PushHelper<ReturnType*>::Push(lua_state, value);
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)())
{
    return CallerArg0<ReturnType, ObjectType>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)() const)
{
    return CallerArg0<ReturnType, ObjectType>::Call(lua_state, methodPtr);
}

template <class ReturnType>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(*methodPtr)())
{
    return CallerArg0Static<ReturnType>::Call(lua_state, methodPtr);
}


//////////////////////////////////////////////////////////////////////////
// 1 arg
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType>
struct CallerArg1
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 2 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType>(lua_type(lua_state, 2)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 2 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType>(lua_type(lua_state, 2)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType, class ParamType>
struct CallerArg1<void, ObjectType, ParamType>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 2 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType>(lua_type(lua_state, 2)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 2 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType>(lua_type(lua_state, 2)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
                return 1;
            }
        }

        return 0;
    }
};

// For ReturnType * (TagObject *, char *, Scriptbject *)
template <class ReturnType, class ObjectType, class ParamType>
struct CallerArg1<ReturnType*, ObjectType, ParamType>
{
    static int Call(lua_State* lua_state, ReturnType * (ObjectType::* methodPtr)(ParamType))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 2 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType>(lua_type(lua_state, 2)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType* value = (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
                return PushHelper<ReturnType*>::Push(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType))
{
    return CallerArg1<ReturnType, ObjectType, ParamType>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType) const)
{
    return CallerArg1<ReturnType, ObjectType, ParamType>::Call(lua_state, methodPtr);
}


//////////////////////////////////////////////////////////////////////////
// 2 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2>
struct CallerArg2
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 3 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2), RetrieveParam<ParamType2>(lua_state, 3));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 3 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2), RetrieveParam<ParamType2>(lua_state, 3));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType, class ParamType1, class ParamType2>
struct CallerArg2<void, ObjectType, ParamType1, ParamType2>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 3 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2), RetrieveParam<ParamType2>(lua_state, 3));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 3 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2), RetrieveParam<ParamType2>(lua_state, 3));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2))
{
    return CallerArg2<ReturnType, ObjectType, ParamType1, ParamType2>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2) const)
{
    return CallerArg2<ReturnType, ObjectType, ParamType1, ParamType2>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 3 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3>
struct CallerArg3
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 4 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 4 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType, class ParamType1, class ParamType2, class ParamType3>
struct CallerArg3<void, ObjectType, ParamType1, ParamType2, ParamType3>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 4 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 4 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3))
{
    return CallerArg3<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3) const)
{
    return CallerArg3<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 4 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
struct CallerArg4
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 5 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 3 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
struct CallerArg4<void, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 5 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 5 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4))
{
    return CallerArg4<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4) const)
{
    return CallerArg4<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 5 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
struct CallerArg5
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 6 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 6 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};

template <class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
struct CallerArg5<void, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 6 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 6 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5))
{
    return CallerArg5<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5) const)
{
    return CallerArg5<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 6 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
struct CallerArg6
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 7 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 7 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};


template <class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
struct CallerArg6<void, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 7 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 7 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6))
{
    return CallerArg6<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6) const)
{
    return CallerArg6<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 7 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7>
struct CallerArg7
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 8 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7),
                                                      RetrieveParam<ParamType7>(lua_state, 8));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 8 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7),
                                                      RetrieveParam<ParamType7>(lua_state, 8));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};


template <class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7>
struct CallerArg7<void, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 8 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7),
                                   RetrieveParam<ParamType7>(lua_state, 8));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 8 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7),
                                   RetrieveParam<ParamType7>(lua_state, 8));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7))
{
    return CallerArg7<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7) const)
{
    return CallerArg7<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7>::Call(lua_state, methodPtr);
}

//////////////////////////////////////////////////////////////////////////
// 8 args
//////////////////////////////////////////////////////////////////////////
template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8>
struct CallerArg8
{
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 9 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)) &&
            CompareArgType<ParamType8>(lua_type(lua_state, 9)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7),
                                                      RetrieveParam<ParamType7>(lua_state, 8),
                                                      RetrieveParam<ParamType8>(lua_state, 9));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 9 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)) &&
            CompareArgType<ParamType8>(lua_type(lua_state, 9)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                ReturnType value = (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                                      RetrieveParam<ParamType2>(lua_state, 3),
                                                      RetrieveParam<ParamType3>(lua_state, 4),
                                                      RetrieveParam<ParamType4>(lua_state, 5),
                                                      RetrieveParam<ParamType5>(lua_state, 6),
                                                      RetrieveParam<ParamType6>(lua_state, 7),
                                                      RetrieveParam<ParamType7>(lua_state, 8),
                                                      RetrieveParam<ParamType8>(lua_state, 9));
                return PushLuaReturnValue(lua_state, value);
            }
        }

        return 0;
    }
};


template <class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8>
struct CallerArg8<void, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8>
{
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8))
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 9 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)) &&
            CompareArgType<ParamType8>(lua_type(lua_state, 9)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7),
                                   RetrieveParam<ParamType7>(lua_state, 8),
                                   RetrieveParam<ParamType8>(lua_state, 9));
                return 1;
            }
        }

        return 0;
    }
    // duplicate for const function
    static int Call(lua_State* lua_state, void (ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8) const)
    {
        int objectTag = LuaGetTag(lua_state, 1);

        if (lua_gettop(lua_state) == 9 &&
            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
            CompareArgType<ParamType1>(lua_type(lua_state, 2)) &&
            CompareArgType<ParamType2>(lua_type(lua_state, 3)) &&
            CompareArgType<ParamType3>(lua_type(lua_state, 4)) &&
            CompareArgType<ParamType4>(lua_type(lua_state, 5)) &&
            CompareArgType<ParamType5>(lua_type(lua_state, 6)) &&
            CompareArgType<ParamType6>(lua_type(lua_state, 7)) &&
            CompareArgType<ParamType7>(lua_type(lua_state, 8)) &&
            CompareArgType<ParamType8>(lua_type(lua_state, 9)))
        {
            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state, 1);

            if (self)
            {
                (self->*methodPtr)(RetrieveParam<ParamType1>(lua_state, 2),
                                   RetrieveParam<ParamType2>(lua_state, 3),
                                   RetrieveParam<ParamType3>(lua_state, 4),
                                   RetrieveParam<ParamType4>(lua_state, 5),
                                   RetrieveParam<ParamType5>(lua_state, 6),
                                   RetrieveParam<ParamType6>(lua_state, 7),
                                   RetrieveParam<ParamType7>(lua_state, 8),
                                   RetrieveParam<ParamType8>(lua_state, 9));
                return 1;
            }
        }

        return 0;
    }
};

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8))
{
    return CallerArg8<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8>::Call(lua_state, methodPtr);
}

template <class ReturnType, class ObjectType, class ParamType1, class ParamType2, class ParamType3, class ParamType4, class ParamType5, class ParamType6, class ParamType7, class ParamType8>
int GenericFunctionToCall2(lua_State* lua_state, ReturnType(ObjectType::* methodPtr)(ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8) const)
{
    return CallerArg8<ReturnType, ObjectType, ParamType1, ParamType2, ParamType3, ParamType4, ParamType5, ParamType6, ParamType7, ParamType8>::Call(lua_state, methodPtr);
}


//////////////////////////////////////////////////////////////////////////
template <class TFunctionType, TFunctionType TMFunc>
int GenericFunctionToCall(lua_State* lua_state)
{
    return GenericFunctionToCall2(lua_state, TMFunc);
}

template <class TFunctionType>
class CGenericFunctionHelper
{
public:
    template <TFunctionType TMemberFunction>
    lua_CFunction GetGenericFunctionToCall()
    {
        return GenericFunctionToCall<TFunctionType, TMemberFunction>;
    }
};

template <class TFunctionType>
CGenericFunctionHelper<TFunctionType> GetGenericFunctionHelper(TFunctionType)
{
    return CGenericFunctionHelper<TFunctionType>();
}

//
//////////////////////////////////////////////////////////////////////////


// if ever needed....
//template <class ReturnType, class ObjectType, class ParamType>
//struct CallerArg1
//{
//    static int Call(lua_State* lua_state, ReturnType (ObjectType::* methodPtr)(const ParamType &))
//    {
//        int objectTag = LuaGetTag(lua_state,1);
//        if (lua_gettop(lua_state) == 2 &&
//            CScriptObjectHierarchicalValidator::GetInstance()->ValidateTag(objectTag, ObjectType::GetScriptTag()) &&
//            CompareArgType<ParamType>(lua_type(lua_state, 2)))
//        {
//            ObjectType* self = *(ObjectType**) lua_touserdata(lua_state,1);
//            if (self)
//            {
//                (self->*methodPtr)(RetrieveParam<ParamType>(lua_state, 2));
//                return 1;
//            }
//        }
//        return 0;
//    }
//}
#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_SCRIPTSERIALISATIONHELPERS_H_
