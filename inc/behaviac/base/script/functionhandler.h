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

#ifndef _ENGINESERVICES_FUNCTIONHANDLER_H_
#define _ENGINESERVICES_FUNCTIONHANDLER_H_

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA
#include "tag/math/vector3.h"

#include "behaviac/base/entity/entityid.h"

struct lua_State;
struct IScriptObject;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------
// Name: enum ScriptVarType
// Desc: WARNING: svtScriptVarTypeCnt must not exceed 15, which is the maximum value
// because it will be packed into 4 bits when writing to file.
//----------------------------------------------------------------------------------------
enum ScriptVarType
{
    svtNull = 0,
    svtString,
    svtNumber,
    svtFunction,
    svtObject,
    svtUserData,
    svtScriptVarTypeCnt,
    svtScriptVarTypeMax	= 0x0F
};


//----------------------------------------------------------------------------------------
// Name: enum EScriptVarPacked
// Desc: Codes for ScriptVarType packed value to write and read from files
//----------------------------------------------------------------------------------------
enum EScriptVarPacked
{
    eScriptVarPacked_False		= 0x00,
    eScriptVarPacked_True		= 0x10,
    eScriptVarPacked_TypeMask	= 0x0F
};


/*! IFunctionHandler implementation
	@see IFunctionHandler
*/
struct	HSCRIPTFUNCTION;
class   CScriptUserData;

class BEHAVIAC_API CFunctionHandler
{
public:
    CFunctionHandler();
    virtual ~CFunctionHandler();

public:
    void __Attach(void* hScript);
    void* GetThis();

    int GetFunctionID();
    int GetParamCount()	const;

    template <class T>
    bool	GetParamGeneric(int nIdx, T& n) const
    {
        int	val;

        if	(!GetParam(nIdx, val))
        {
            return	false;
        }

        n = (T)val;
        return	true;
    }
    bool GetParam(int nIdx, int& n)	const;
    bool GetParam(int nIdx, unsigned int& n)	const;
    bool GetParam(int nIdx, float& f)	const;
    bool GetParam(int nIdx, const char*& s)	const;
    bool GetParam(int nIdx, char*& s)	const;
    bool GetParam(int nIdx, bool& b)	const;
    bool GetParam(int nIdx, IScriptObject* pObj)	const;
    bool GetParam(int nIdx, HSCRIPTFUNCTION& hFunc)	const;
    bool GetParam(int nIdx, CDynamicType*& ud)	const;
    bool GetParam(int nIdx, EntityId& entityId)	const;

    ScriptVarType GetParamType(int nIdx) const;
    int EndFunction(int nRetVal);
    int EndFunction(float fRetVal);
    int EndFunction(const char* fRetVal);
    int EndFunction(bool bRetVal);
    int EndFunction(IScriptObject* pObj);
    int EndFunction(HSCRIPTFUNCTION hFunc);
    int EndFunction(CDynamicType* ud);
    int EndFunction(EntityId id);
    int EndFunction();
    int EndFunctionNull();

private:
    lua_State* m_pLS;
};

#endif//#if BEHAVIAC_ENABLE_LUA

#endif // #ifndef _ENGINESERVICES_FUNCTIONHANDLER_H_
