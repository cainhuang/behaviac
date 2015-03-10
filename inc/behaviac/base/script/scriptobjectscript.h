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

#ifndef _ENGINESERVICES_SCRIPTOBJECTSCRIPT_H_
#define _ENGINESERVICES_SCRIPTOBJECTSCRIPT_H_

#include "behaviac/base/base.h"
#if BEHAVIAC_ENABLE_LUA

#include "behaviac/base/script/_scriptableex.h"
/*! This class implements script-functions for exposing the scripting system functionalities

	REMARKS:
	After initialization of the script-object it will be globally accessable through scripts using the namespace "Script".

	Example:
		Script.LoadScript("engine/scripts/common.lua")

	IMPLEMENTATIONS NOTES:
	These function will never be called from C-Code. They're script-exclusive.
*/

class BEHAVIAC_API CScriptObjectScript :
    public _ScriptableEx<CScriptObjectScript>
{
public:
    BEHAVIAC_DECLARE_MEMORY_OPERATORS(CScriptObjectScript)

    CScriptObjectScript();
    virtual ~CScriptObjectScript();
    void Init();
    static void InitializeTemplate();

    int LoadScript(CFunctionHandler* pH);
    int ReloadScripts(CFunctionHandler* pH);
    int ReloadScript(CFunctionHandler* pH);
    int UnloadScript(CFunctionHandler* pH);
#if !defined(_DEBUG) && defined(DEBUG_RESID)
    int DumpLoadedScripts(CFunctionHandler* pH);
#endif
};
#endif//#if BEHAVIAC_ENABLE_LUA


#endif // #ifndef _ENGINESERVICES_SCRIPTOBJECTSCRIPT_H_
