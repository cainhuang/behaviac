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

#ifndef _ENGINESERVICES_SCRIPTMARSHAL_H_
#define _ENGINESERVICES_SCRIPTMARSHAL_H_

#include "tag/math/vector2.h"
#include "tag/math/vector3.h"
#include "tag/math/vector4.h"
#include "tag/math/matrix44.h"
#include "tag/math/quaternion.h"
#include "tag/math/aabb3.h"

#include "behaviac/base/base.h"

#if BEHAVIAC_ENABLE_LUA

#include "behaviac/base/dynamictype.h"
#include "behaviac/base/entity/entityid.h"
#include "behaviac/base/script/scriptmarshaltype.h"
#include "behaviac/base/script/scriptreference.h"
#include "behaviac/base/script/scriptsystem.h"
#include "behaviac/base/script/scriptutils.h"

#include "behaviac/base/script/lua/lua.h"

class BEHAVIAC_API CScriptMarshal
{
public:
    static void Init(lua_State* L)
    {
        lua_newtable(L);    // pointer pool table.
        lua_newtable(L);    // meta table of pointer pool.
        // The pointer pool has weak values, so that when the userdata representing the pointer is collected, it disappears from the pool as well.
        lua_pushstring(L, "v");
        lua_setfield(L, -2, "__mode");
        lua_setmetatable(L, -2);
        s_pointerTable = lua_ref(L, true);
    }
    static int s_pointerTable;

public:
#define SCRIPT_MARSHAL_GET(type, check, convertFrom) \
    inline static bool GetData(lua_State* L, int idx, type& data)\
    {\
        if (!check(L, idx))\
            return false;\
        \
        convertFrom;\
        return true;\
    }
#define SCRIPT_MARSHAL_SET(type, convertTo) inline static void PushData(lua_State* L, type data) { convertTo; }

#define SCRIPT_MARSHAL(type, check, convertFrom, convertTo) \
    SCRIPT_MARSHAL_GET(type, check, convertFrom)\
    SCRIPT_MARSHAL_SET(type, convertTo)

#define SCRIPT_MARSHAL_REF(type, check, convertFrom, convertTo) \
    SCRIPT_MARSHAL_GET(type, check, convertFrom)\
    SCRIPT_MARSHAL_SET(const type&, convertTo)

public:
#define SCRIPT_MARSHAL_NUMBER(type) SCRIPT_MARSHAL(type, lua_isnumber, data = (type)lua_tonumber(L, idx), lua_pushnumber(L, (lua_Number)data));
    // Basic C types.
    SCRIPT_MARSHAL_NUMBER(char);
    SCRIPT_MARSHAL_NUMBER(short);
    SCRIPT_MARSHAL_NUMBER(long);
    SCRIPT_MARSHAL_NUMBER(int);
    SCRIPT_MARSHAL_NUMBER(unsigned char);
    SCRIPT_MARSHAL_NUMBER(unsigned short);
    SCRIPT_MARSHAL_NUMBER(unsigned long);
    SCRIPT_MARSHAL_NUMBER(unsigned int);
    SCRIPT_MARSHAL_NUMBER(float);
    SCRIPT_MARSHAL_NUMBER(double);
    SCRIPT_MARSHAL(bool, lua_isboolean, data = lua_toboolean(L, idx) != 0, lua_pushboolean(L, data ? 1 : 0));
    SCRIPT_MARSHAL(const char*, lua_isstring, data = lua_tostring(L, idx), lua_pushstring(L, data));
    SCRIPT_MARSHAL_REF(behaviac::string, lua_isstring, data = lua_tostring(L, idx), lua_pushstring(L, data.c_str()));

public:
    // Basic behaviac types.
    SCRIPT_MARSHAL(CStringID, lua_islightuserdata, data = CStringID((CStringID::IDType)lua_touserdata(L, idx)), lua_pushlightuserdata(L, (void*)data.GetUniqueID()));
    SCRIPT_MARSHAL(CPathID, lua_islightuserdata, data = CPathID((CPathID::IDType)lua_touserdata(L, idx)), lua_pushlightuserdata(L, (void*)data.GetUniqueID()));
    SCRIPT_MARSHAL(uint64_t, lua_isuserdata, data = *(uint64_t*)lua_touserdata(L, idx), *(uint64_t*)lua_newuserdata(L, sizeof(uint64_t)) = data);
    SCRIPT_MARSHAL(EntityId, lua_isuserdata, data = EntityId(*(EntityId::IdType*)lua_touserdata(L, idx)), *(EntityId::IdType*)lua_newuserdata(L, sizeof(EntityId::IdType)) = data.GetUniqueID());

public:
    // Vectors
    template <typename T> inline static bool GetData(lua_State* L, int idx, behaviac::vector<T>& data)
    {
        if (!lua_istable(L, idx))
        {
            return false;
        }

        data.clear();
        int iter = 0;

        for (;;)
        {
            lua_rawgeti(L, idx, iter);
            T element;
            bool result = GetData(L, -1, element);
            lua_pop(L, 1);

            if (result)
            {
                data.push_back(element);
            }
            else
            {
                return false;
            }

            iter++;
        }

        //return true;
    }

    template <typename T> inline static void PushData(lua_State* L, const behaviac::vector<T>& data)
    {
        lua_newtable(L);

        for (int i = 0; i < (int)data.size(); i++)
        {
            PushData(L, data[i]);
            lua_rawseti(L, -2, i);
        }
    }

public:
    // Array helper
    template <typename T> inline static bool GetDataArray(lua_State* L, int idx, T& data, int N)
    {
        if (!lua_istable(L, idx))
        {
            return false;
        }

        for (int i = 0; i < N; i++)
        {
            lua_rawgeti(L, idx, i);
            bool result = GetData(L, -1, data[i]);
            lua_pop(L, 1);

            if (!result)
            {
                return false;
            }
        }

        return true;
    }

    template <typename T> inline static void PushDataArray(lua_State* L, const T& data, int N)
    {
        lua_createtable(L, N, 0);

        for (int i = 0; i < N; i++)
        {
            PushData(L, data[i]);
            lua_rawseti(L, -2, i);
        }
    }


    template <typename T> inline static bool GetDataArrayQuat(lua_State* L, int idx, T& data, int N)
    {
        if (!lua_istable(L, idx))
        {
            return false;
        }

        for (int i = 0; i < N; i++)
        {
            lua_rawgeti(L, idx, i);
            bool result = GetData(L, -1, data.f[i]);
            lua_pop(L, 1);

            if (!result)
            {
                return false;
            }
        }

        return true;
    }

    template <typename T> inline static void PushDataArrayQuat(lua_State* L, const T& data, int N)
    {
        lua_createtable(L, N, 0);

        for (int i = 0; i < N; i++)
        {
            PushData(L, data.f[i]);
            lua_rawseti(L, -2, i);
        }
    }
public:
    // behaviac::Vector2/3/4
    template <typename T> inline static bool GetData(lua_State* L, int idx, behaviac::GenericVector<T>& data)
    {
        return GetDataArray(L, idx, data, T::N);
    }
    template <typename T> inline static void PushData(lua_State* L, const behaviac::GenericVector<T>& data)
    {
        PushDataArray(L, data, T::N);
    }

    // behaviac::Quaternion
    inline static bool GetData(lua_State* L, int idx, behaviac::Quaternion& data)
    {
        return GetDataArrayQuat(L, idx, data, 4);
    }
    inline static void PushData(lua_State* L, const behaviac::Quaternion& data)
    {
        PushDataArrayQuat(L, data, 4);
    }

    // behaviac::Aabb3
    inline static bool GetData(lua_State* L, int idx, behaviac::Aabb3& data)
    {
        if (!lua_istable(L, idx))
        {
            return false;
        }

        for (int i = 0; i < 3; i++)
        {
            lua_rawgeti(L, idx, i);
            bool result = GetData(L, -1, data.minimum[i]);
            lua_pop(L, 1);

            if (!result)
            {
                return false;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            lua_rawgeti(L, idx, i + 3);
            bool result = GetData(L, -1, data.maximum[i]);
            lua_pop(L, 1);

            if (!result)
            {
                return false;
            }
        }

        return true;
    }

    inline static void PushData(lua_State* L, const behaviac::Aabb3& data)
    {
        lua_createtable(L, 6, 0);

        for (int i = 0; i < 3; i++)
        {
            PushData(L, data.minimum[i]);
            lua_rawseti(L, -2, i);
        }

        for (int i = 0; i < 3; i++)
        {
            PushData(L, data.maximum[i]);
            lua_rawseti(L, -2, i + 3);
        }
    }

    // behaviac::Matrix44
    inline static bool GetData(lua_State* L, int idx, behaviac::Matrix44& data)
    {
        return GetDataArray(L, idx, data.f, 16);
    }
    inline static void PushData(lua_State* L, const behaviac::Matrix44& data)
    {
        PushDataArray(L, data.f, 16);
    }

public:
    // Script stuff
    inline static bool GetData(lua_State* L, int idx, ScriptReferenceId& reference)
    {
        if (lua_isnil(L, idx))
        {
            reference = 0;
        }
        else
        {
            lua_pushvalue(L, idx);
            reference = lua_ref(L, true);
        }

        return true;
    }
    inline static void PushData(lua_State* L, const ScriptReferenceId& reference)
    {
        if (reference != 0)
        {
            lua_getref(L, reference);
        }
        else
        {
            lua_pushnil(L);
        }
    }

    // Object tables
public:
    static void PushTable(lua_State* L, IScriptMarshalTableSave* data)
    {
        lua_newtable(L);
        data->SaveScriptTable(L);
    }

    struct ScriptMarshalAsTable
    {
        ScriptMarshalAsTable(IScriptMarshalTableSave* table) : table(table) {}
        IScriptMarshalTableSave* table;
    };
    template <class T> static void PushData(lua_State* L, ScriptMarshalAsTable data)
    {
        PushTable(L, data.table);
    }

    template <class T> static void SetField(lua_State* L, int idx, T data, const char* field)
    {
        if (idx < 0)
        {
            idx--;
        }

        PushData(L, data);
        lua_setfield(L, idx, field);
    }

    // Object pointers
public:
    // Structure containing information about an object holder.
    struct HolderInfo
    {
        void (*createHolder)(CScriptMarshalDynamicObjectHolder*);
        int size;
        int metatable;

        template <class T> void CreateHolderInfo()
        {
            createHolder = &CreateHolder<T>;
            size = sizeof(T);
            metatable = T::GetScriptTable();
        }
        template <class T> static void CreateHolder(CScriptMarshalDynamicObjectHolder* holder)
        {
            new(holder) typename T::ObjectHolder;
        }
    };
    typedef behaviac::map<CStringID, HolderInfo> HolderMap;
    static HolderMap s_holderInfos;

    // GC method invoked from Lua for object holders.
    template <class T> static int DeleteObjectHolder(lua_State* L)
    {
        ((T*)lua_touserdata(L, -1))->~T();
        return 0;
    }

    static CScriptMarshalDynamicObjectHolder* GetObjectHolder(lua_State* L, int idx)
    {
        if (!lua_isuserdata(L, idx))
        {
            return false;
        }

        if (!lua_getmetatable(L, idx))
        {
            return false;
        }

        // TODO: Make sure we have a way of validating this metatable.
        lua_pop(L, 1);
        return (CScriptMarshalDynamicObjectHolder*)lua_touserdata(L, idx);
    }

    template <class T> static bool GetData(lua_State* L, int idx, T*& data)
    {
        CScriptMarshalDynamicObjectHolder* holder = GetObjectHolder(L, idx);

        if (holder == NULL)
        {
            return false;
        }

        return holder->GetData(data);
    }

    static void PushData(lua_State* L, CDynamicType* data)
    {
        lua_getref(L, s_pointerTable);
        // Try to find a userdata for that pointer.
        lua_pushlightuserdata(L, data);
        lua_rawget(L, -2);

        // That pointer already has a userdata marshalled. So we just use that one.
        if (!lua_isnil(L, -1))
        {
            BEHAVIAC_ASSERT(lua_isuserdata(L, -1)); // Well looks like somebody else is using the registry with lightuserdata keys. Baddddd....
            // Check if the userdata truly corresponds to what we were expecting.
            CScriptMarshalDynamicObjectHolder* holder = GetObjectHolder(L, -1);

            if (holder != NULL && holder->Validate(data))
            {
                lua_remove(L, -2); // Get rid of the pointer pool table, keep the userdata on stack.
                return;
            }

            // It's not valid! Pop the invalid userdata from stack, remove the reference from the pointer table pool and proceed to create a new userdata.
            lua_pop(L, 1);
            lua_pushlightuserdata(L, data);
            lua_pushnil(L);
            lua_rawset(L, -3);
        }
        else
        {
            // Get rid of nil.
            lua_pop(L, 1);
        }

        // Find the most derived exposed type of the object we're pushing.
        HolderInfo* holderInfo = NULL;
        const CDynamicType::SHierarchyInfo* hierarchy = data->GetHierarchyInfo();

        for (int i = hierarchy->m_hierarchyLevel - 1; i >= 0; i--)
        {
            const CStringID& objectType = hierarchy->m_hierarchy[i];
            HolderMap::iterator holderIter = s_holderInfos.find(objectType);

            if (holderIter != s_holderInfos.end())
            {
                holderInfo = &(*holderIter).second;
                break;
            }
        }

        // This object is not part of our exposed types. We can't marshal this, so push nil instead.
        if (holderInfo == NULL)
        {
            lua_pop(L, 1); // Pop pointer pool table.
            lua_pushnil(L);
            return;
        }

        // Create a new object holder as a userdata, to represent the object we're pushing.
        CScriptMarshalDynamicObjectHolder* holder = (CScriptMarshalDynamicObjectHolder*)lua_newuserdata(L, holderInfo->size);
        holderInfo->createHolder(holder);

        if (!holder->SetData(data))
        {
            lua_pop(L, 2); // Pop failed UD and the pointer pool table.
            lua_pushnil(L);
            return;
        }

        // Keep userdata in pointer pool.
        lua_pushlightuserdata(L, data);
        lua_pushvalue(L, -2);
        lua_rawset(L, -4);
        // Get rid of the pointer pool table.
        lua_remove(L, -2);
        // Setup metatable of userdata.
        lua_getref(L, holderInfo->metatable);
        lua_setmetatable(L, -2);
    }


public:
    // Marshal lua -> C++ function call.

    // Error handler when marshaling is incorrect. This function must always return or longjmp!
#define SCRIPTMARSHAL_FUNCTION_ERROR { BEHAVIAC_ASSERT(0, "Invalid engine function call"); lua_pushstring(L, "Invalid engine function call"); lua_error(L); };

#define _EMPTY_SEPARATOR
#define _EMPTY1(x)
#define _COMMA_SEPARATOR ,
#define _TEMPLATE(x) template<x>
#define _TEMPLATEARGS(x) <x>

    // This is a set of macros that will execute a given macro "x" an arbitrary number of times, providing the iteration number as a parameter to it.
    // The "y" parameter is a separator to put between each macro call. This can be _EMPTY when no separator is needed, or _COMMA for putting commas in between.
#define _REC0(x,y)
#define _REC1(x,y) _REC0(x,y) x(1)
#define _REC2(x,y) _REC1(x,y) y##_SEPARATOR x(2)
#define _REC3(x,y) _REC2(x,y) y##_SEPARATOR x(3)
#define _REC4(x,y) _REC3(x,y) y##_SEPARATOR x(4)
#define _REC5(x,y) _REC4(x,y) y##_SEPARATOR x(5)
#define _REC6(x,y) _REC5(x,y) y##_SEPARATOR x(6)
#define _REC7(x,y) _REC6(x,y) y##_SEPARATOR x(7)
#define _REC8(x,y) _REC7(x,y) y##_SEPARATOR x(8)

    // Holds a parameter regardless of its type qualifiers.
    template <class T> struct ParamHolder
    {
        bool Get(lua_State* L, int& offset)
        {
            if (CScriptMarshal::GetData(L, offset, data))
            {
                offset++;
                return true;
            }

            return false;
        }
        T data;
    };
    template <class T> struct ParamHolder<T&> : public ParamHolder<T> {};
    template <class T> struct ParamHolder<const T> : public ParamHolder<T> {};
    template <class T> struct ParamHolder<const T&> : public ParamHolder<T> {};

    // These macros are for recursively defining an arbitrary number of parameters with its separate distinct type, and marshal them from the script environment.
#define SCRIPTMARSHAL_PARAM_TEMPLATE(idx) class ParamType##idx
#define SCRIPTMARSHAL_PARAM_DEF(idx) ParamType##idx
#define SCRIPTMARSHAL_PARAM_REF(idx) param##idx
#define SCRIPTMARSHAL_PARAM_DEF_REF(idx) SCRIPTMARSHAL_PARAM_DEF(idx) SCRIPTMARSHAL_PARAM_REF(idx)
#define SCRIPTMARSHAL_PARAM_REF_DATA(idx) SCRIPTMARSHAL_PARAM_REF(idx).data
#define SCRIPTMARSHAL_PARAM_GET(idx) ParamHolder<ParamType##idx> param##idx; error |= !param##idx.Get(L, offset);
#define SCRIPTMARSHAL_PARAM_PUSH(idx) PushData(L, param##idx);

    // - This defines a set of structures, where each of them contains a Call function which will be called from the script environment.
    //
    // - Each possible number of parameters is covered by its own distinct structure. (StaticHandler0, StaticHandler1, StaticHandler2, etc.)
    //
    // - Each structure is templated depending of the type of each parameter and the return type of the function.
    //
    // - This template is then used to template the Call function with the function prototype itself,
    //   so that we know at compile-time the exact C++ function to call for that script function.
    //
    // - In order to pass the return value back to the script environment, a distinction must be made between void and other functions.
    //   * void is not a type we can pass to another function, so in these cases we just call the function and quit after.
    //   * In the other cases, we push the return value of the function back to the script.
    //
    // - This distinction is done by appending Void to the structure name (e.g. StaticHandlerVoid0) in the case of a void return.
    //   The correct structure to use is determined by overloading the GetFunctionHandler function.
    //   NOTE: It would have been possible to merge StaticHandler and StaticHandlerVoid through template specialization,
    //         but this was made impossible due to a nasty VC++ compiler bug.
    //         Find more info here: http://connect.microsoft.com/VisualStudio/feedback/ViewFeedback.aspx?FeedbackID=362170
    //         So I did the specialization on GetFunctionHandler instead.
    //
    // - The same reasoning was applied for const method pointers (e.g. MethodHandler0 vs MethodHandlerConst0)
#define SCRIPTMARSHAL_STATIC_HANDLER(idx, rec, sep, voidTemplate, voidTemplateArgs) \
    template <class ReturnType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)> struct StaticHandler##idx\
    {\
        template <ReturnType (*Function)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA))> static int Call(lua_State* L)\
        {\
            bool error = false;\
            {\
                int offset = 1;\
                rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
                if (!error)\
                    PushData(L, Function(rec(SCRIPTMARSHAL_PARAM_REF_DATA, _COMMA)));\
            }\
            if (error) SCRIPTMARSHAL_FUNCTION_ERROR;\
            return 1;\
        }\
    };\
    template <class ReturnType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static StaticHandler##idx<ReturnType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)> GetFunctionHandler(ReturnType (*Method)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)))\
    {\
        return StaticHandler##idx<ReturnType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)>();\
    }\
    voidTemplate(rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)) struct StaticHandlerVoid##idx\
    {\
        template <void (*Function)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA))> static int Call(lua_State* L)\
        {\
            bool error = false;\
            {\
                int offset = 1;\
                rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
                if (!error)\
                    Function(rec(SCRIPTMARSHAL_PARAM_REF_DATA, _COMMA));\
            }\
            if (error) SCRIPTMARSHAL_FUNCTION_ERROR;\
            return 0;\
        };\
    };\
    voidTemplate(rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA))\
    static StaticHandlerVoid##idx voidTemplateArgs(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) GetFunctionHandler(void (*Method)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)))\
    {\
        return StaticHandlerVoid##idx voidTemplateArgs(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA))();\
    }

#define SCRIPTMARSHAL_METHOD_HANDLER(idx, rec, sep, isConst)\
    template <class ReturnType, class ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)> struct MethodHandler##idx\
    {\
        template <ReturnType (ObjectType::*Function)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst> static int Call(lua_State* L)\
        {\
            bool error = false;\
            {\
                int offset = 1;\
                ParamHolder<ObjectType*> object; error |= !object.Get(L, offset);\
                rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
                if (!error)\
                    PushData(L, ((object.data)->*Function)(rec(SCRIPTMARSHAL_PARAM_REF_DATA, _COMMA)));\
            }\
            if (error) SCRIPTMARSHAL_FUNCTION_ERROR;\
            return 1;\
        };\
    };\
    template <class ReturnType, class ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static MethodHandler##idx<ReturnType, ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)> GetFunctionHandler(ReturnType (ObjectType::*Method)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst)\
    {\
        return MethodHandler##idx<ReturnType, ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)>();\
    }\
    template <class ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)> struct MethodHandlerVoid##idx\
    {\
        template <void (ObjectType::*Function)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst> static int Call(lua_State* L)\
        {\
            bool error = false;\
            {\
                int offset = 1;\
                ParamHolder<ObjectType*> object; error |= !object.Get(L, offset);\
                rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
                if (!error)\
                    ((object.data)->*Function)(rec(SCRIPTMARSHAL_PARAM_REF_DATA, _COMMA));\
            }\
            if (error) SCRIPTMARSHAL_FUNCTION_ERROR;\
            return 0;\
        }\
    };\
    template <class ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static MethodHandlerVoid##idx<ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)> GetFunctionHandler(void (ObjectType::*Method)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst)\
    {\
        return MethodHandlerVoid##idx<ObjectType sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)>();\
    }

#define SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS(idx, rec, sep, voidTemplate, voidTemplateArgs)\
    SCRIPTMARSHAL_STATIC_HANDLER(idx, rec, sep, voidTemplate, voidTemplateArgs)\
    SCRIPTMARSHAL_METHOD_HANDLER(idx, rec, sep, _EMPTY_SEPARATOR)\
    SCRIPTMARSHAL_METHOD_HANDLER(Const##idx, rec, sep, const)

#define SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_NOPARAM(idx, rec) SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS(idx, rec, _EMPTY, _EMPTY1, _EMPTY1)
#define SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(idx, rec) SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS(idx, rec, _COMMA, _TEMPLATE, _TEMPLATEARGS)

    // Defines for any function with X parameters.
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_NOPARAM(0, _REC0)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(1, _REC1)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(2, _REC2)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(3, _REC3)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(4, _REC4)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(5, _REC5)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(6, _REC6)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(7, _REC7)
    SCRIPTMARSHAL_DECLARE_FUNCTION_HANDLERS_PARAM(8, _REC8)

#define SCRIPTMARSHAL_PUSHFUNCTION(L, type) lua_pushcclosure(L, CScriptMarshal::GetFunctionHandler(type).Call<type>, 0);

public:
    // Marshal C++ -> lua function call.
#define SCRIPTMARSHAL_FUNCTION_CALLER(idx, rec, sep, voidTemplate)\
    template <class ReturnValue sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)> static bool CallFunction(lua_State* L sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF_REF, _COMMA), ReturnValue& returnValue)\
    {\
        bool result = false;\
        CScriptSystem::GetInstance()->PushErrorHandler(L);\
        lua_pushvalue(L, -2);\
        rec(SCRIPTMARSHAL_PARAM_PUSH, _EMPTY);\
        int callResult = lua_pcall(L, idx, 1, -idx-2);\
        if (callResult != 0)\
            CScriptSystem::GetInstance()->HandleErrorCode(L, callResult);\
        else\
        {\
            result = GetData(L, -1, returnValue);\
            lua_pop(L, 1);\
        }\
        lua_pop(L, 2);\
        return result;\
    }\
    voidTemplate(rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)) static bool CallFunctionVoid(lua_State* L sep##_SEPARATOR rec(SCRIPTMARSHAL_PARAM_DEF_REF, _COMMA))\
    {\
        bool result = false;\
        CScriptSystem::GetInstance()->PushErrorHandler(L);\
        lua_pushvalue(L, -2);\
        rec(SCRIPTMARSHAL_PARAM_PUSH, _EMPTY);\
        int callResult = lua_pcall(L, idx, 0, -idx-2);\
        if (callResult != 0)\
            CScriptSystem::GetInstance()->HandleErrorCode(L, callResult);\
        else\
            result = true;\
        lua_pop(L, 2);\
        return result;\
    }

#define SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_NOPARAM(idx, rec) SCRIPTMARSHAL_FUNCTION_CALLER(idx, rec, _EMPTY, _EMPTY1)
#define SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(idx, rec) SCRIPTMARSHAL_FUNCTION_CALLER(idx, rec, _COMMA, _TEMPLATE)

    // Defines for any function with X parameters.
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_NOPARAM(0, _REC0)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(1, _REC1)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(2, _REC2)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(3, _REC3)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(4, _REC4)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(5, _REC5)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(6, _REC6)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(7, _REC7)
    SCRIPTMARSHAL_DECLARE_FUNCTION_CALLERS_PARAM(8, _REC8)

public:
    // Object type exposition.

    // More details about the type declaration can be found in ScriptMarshalType.h
    // This is for the run-time exposition of the declared type.

    // This initializes a type to be exposed to the script environment with the given name.
    template <class ObjectType> static void ExposeSelfType(const char* name)
    {
        lua_State* L = GetScriptState();
        // These two tables will be kept on the stack for the registration macros.
        lua_newtable(L); // meta table
        lua_newtable(L); // index table
        // Immediately reference the index table in the meta table.
        lua_pushvalue(L, -2);
        lua_pushvalue(L, -2);
        lua_setfield(L, -2, "__index");
        // Keep a reference to the meta table as the script tag.
        ObjectType::SetScriptTable(lua_ref(L, true));

        // Setup metatable for garbage collection if the object type requires it.
        if (ObjectType::ObjectHolder::IsGarbageCollected())
        {
            lua_pushcfunction(L, &DeleteObjectHolder< typename ObjectType::ObjectHolder >);
            lua_setfield(L, -3, "__gc");
        }

        // Also keep a reference to the meta table in the registry as the type name.
        lua_pushvalue(L, -2);
        lua_setfield(L, LUA_REGISTRYINDEX, name);
        // Construct a holder info to keep track for this exposed type.
        HolderInfo info;
        info.CreateHolderInfo<ObjectType>();
        s_holderInfos.insert(eastl::pair<CStringID, HolderInfo>(ObjectType::GetClassTypeId(), info));
    }

    // This function assumes ExposeType has already been called!
    template <class Parent> static void ExposeParentType()
    {
        lua_State* L = GetScriptState();
        BEHAVIAC_ASSERT(lua_gettop(L) == 2 && lua_istable(L, 1) && lua_istable(L, 2));

        if (Parent::GetScriptTable() > 0)
        {
            // Stack becomes: meta, index, parent.meta, parent.index
            lua_getref(L, Parent::GetScriptTable());
            lua_getfield(L, -1, "__index");
            // Copy content of parent's index table to the current index table.
            lua_pushvalue(L, -3);
            CScriptUtils::CloneTable(L, -2, false);
            // Pop index table duplicate and parent's index table.
            lua_pop(L, 2);
            // Set parent's meta table to index 0 of current meta table (index 0 = parent reference).
            lua_rawseti(L, -3, 0);
        }

        BEHAVIAC_ASSERT(lua_gettop(L) == 2);
    }

    struct ExposeParentCaller
    {
        template <class Parent> inline static void Call()
        {
            ExposeParentType<Parent>();
        }
    };

    template <class T> static void ExposeType(const char* name)
    {
        // Expose type
        ExposeSelfType<T>(name);
        // Expose parent
        T::CallParent(ExposeParentCaller());
    }

#define SCRIPTMARSHAL_EXPOSE(objectType, exposeFunction)\
    lua_State* L = GetScriptState();\
    SCRIPT_STACK_GUARD(L);\
    exposeFunction;\
    typedef objectType scriptType;

#define SCRIPTMARSHAL_EXPOSE_TYPE_AS(objectType, name) SCRIPTMARSHAL_EXPOSE(objectType, CScriptMarshal::ExposeType<objectType>(name));
#define SCRIPTMARSHAL_EXPOSE_STATICTYPE_AS(objectType, name) SCRIPTMARSHAL_EXPOSE(objectType, CScriptMarshal::ExposeSelfType<objectType>(name));

#define SCRIPTMARSHAL_EXPOSE_TYPE(objectType) SCRIPTMARSHAL_EXPOSE_TYPE_AS(objectType, objectType::GetClassTypeName())
#define SCRIPTMARSHAL_EXPOSE_STATICTYPE(objectType) SCRIPTMARSHAL_EXPOSE_STATICTYPE_AS(objectType, objectType::GetClassTypeName())


    // Function exposition inside a type.
#define SCRIPTMARSHAL_REGISTER_FUNCTION_AS(function, name)\
    SCRIPTMARSHAL_PUSHFUNCTION(L, &scriptType::function);\
    lua_setfield(L, -2, name);

#define SCRIPTMARSHAL_REGISTER_FUNCTION(function) SCRIPTMARSHAL_REGISTER_FUNCTION_AS(function, #function)
};

template <>
struct CScriptMarshal::ParamHolder<lua_State*>
{
    bool Get(lua_State* L, int& offset)
    {
        data = L;
        return true;
    }
    lua_State* data;
};

template <>
inline void CScriptMarshal::ExposeParentType<CDynamicType>()
{
    // Don't do anything, CDynamicType is never exposed!
}


// Below implements something similar to what was in ScriptSerialisationHelpers.h, however this does not support static functions, so I prefered another approach.
/*#define SCRIPTMARSHAL_STATICFUNCTION_HANDLER(rec, sep) \
    template <class ReturnType sep rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static int FunctionHandler(lua_State* L, ReturnType (* functionPtr)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)))\
    {\
        bool error = false;\
        rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
        if (!error)\
            return 0;\
        PushData(L, functionPtr(rec(SCRIPTMARSHAL_PARAM_REF, _COMMA)));\
        return 1;\
    }\
    template <rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static int FunctionHandler(lua_State* L, void (* functionPtr)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)))\
    {\
        bool error = false;\
        rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
        if (!error)\
            functionPtr(rec(SCRIPTMARSHAL_PARAM_REF, _COMMA));\
        return 0;\
    }

#define SCRIPTMARSHAL_MEMBERFUNCTION_HANDLER(rec, sep, isConst) \
    template<class ReturnType, class ObjectType sep rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static int FunctionHandler(lua_State* L, ReturnType (ObjectType::* methodPtr)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst)\
    {\
        bool error = false;\
        ObjectType* object;\
        rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
        if (!error)\
            return 0;\
        PushData(L, (object->*methodPtr)(rec(SCRIPTMARSHAL_PARAM_REF, _COMMA)));\
        return 1;\
    }\
    template<class ObjectType sep rec(SCRIPTMARSHAL_PARAM_TEMPLATE, _COMMA)>\
    static int FunctionHandler(lua_State* L, void (ObjectType::* methodPtr)(rec(SCRIPTMARSHAL_PARAM_DEF, _COMMA)) isConst)\
    {\
        bool error = false;\
        ObjectType* object;\
        rec(SCRIPTMARSHAL_PARAM_GET, _EMPTY)\
        if (!error)\
            (object->*methodPtr)(rec(SCRIPTMARSHAL_PARAM_REF, _COMMA));\
        return 0;\
    }

#define SCRIPTMARSHAL_FUNCTION_HANDLER(rec, sep)\
    SCRIPTMARSHAL_STATICFUNCTION_HANDLER(rec, sep)\
    SCRIPTMARSHAL_MEMBERFUNCTION_HANDLER(rec, sep, _EMPTY)\
    SCRIPTMARSHAL_MEMBERFUNCTION_HANDLER(rec, sep, const)

#define SCRIPTMARSHAL_FUNCTION_HANDLER_NOPARAM(rec) SCRIPTMARSHAL_FUNCTION_HANDLER(rec, _EMPTY)
#define SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(rec) SCRIPTMARSHAL_FUNCTION_HANDLER(rec, _COMMA)

    // Defines for any function with X parameters.
    SCRIPTMARSHAL_FUNCTION_HANDLER_NOPARAM(_REC0)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC1)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC2)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC3)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC4)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC5)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC6)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC7)
    SCRIPTMARSHAL_FUNCTION_HANDLER_PARAM(_REC8)

    template <class FunctionType, FunctionType Function> static int Call(lua_State* L) { return FunctionHandler(L, Function); }

    template <class FunctionType>
    struct FunctionThunk
    {
        template <FunctionType Function> lua_CFunction GetFunction() { return CScriptMarshal::Call<FunctionType, Function>; }
    };

    template <class FunctionType> static inline FunctionThunk<FunctionType> GetFunctionThunk(FunctionType) { return FunctionThunk<FunctionType>(); }
#define SCRIPTMARSHAL_PUSHFUNCTION(L, type) lua_pushcclosure(L, CScriptMarshal::GetFunctionThunk(type).GetFunction<type>(), 0);*/
#endif//#if BEHAVIAC_ENABLE_LUA

#endif
