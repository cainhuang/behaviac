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

#ifndef BEHAVIAC_BASE_CORE_CONFIG_H
#define BEHAVIAC_BASE_CORE_CONFIG_H

/**
BEHAVIAC_RELEASE	0	// development mode
BEHAVIAC_RELEASE	1	// release/retail mode

BEHAVIAC_RELEASE MUST be defined the same in lib(behaviac) and app(your game).

Please don't define BEHAVIAC_RELEASE unless you know what you are doing.
*/
#include "_config.h"

#if (defined(_DEBUG) || defined(DEBUG))
	#ifndef BEHAVIAC_RELEASE
		#define BEHAVIAC_RELEASE				0
	#endif
#else
	#ifndef BEHAVIAC_RELEASE
		#define BEHAVIAC_RELEASE				1
	#endif
#endif//

#if (defined(_DEBUG) || defined(DEBUG))
	#define _BEHAVIAC_BUILD_CONFIG_STR_ "behavaic_debug"
#else
	#define _BEHAVIAC_BUILD_CONFIG_STR_ "behavaic_ndebug"
#endif//
                     
#define _BEHAVIAC_M_STRING_CONCAT_(a, b) a # b

#ifdef BEHAVIAC_RELEASE
	#define BEHAVIAC_BUILD_CONFIG_STR _BEHAVIAC_M_STRING_CONCAT_(_BEHAVIAC_BUILD_CONFIG_STR_, "_RELEASE")
#else
	#define BEHAVIAC_BUILD_CONFIG_STR _BEHAVIAC_M_STRING_CONCAT_(_BEHAVIAC_BUILD_CONFIG_STR_, "_NRELEASE")
#endif

#if !BEHAVIAC_RELEASE
	#define BEHAVIAC_ENABLE_HOTRELOAD	1
	#define BEHAVIAC_ENABLE_PROFILING	1
#endif//BEHAVIAC_RELEASE

//please don't use the following macros in the public header files unless you know what you are doing.
//otherwise, it might be causing uncompatible layout for types
#ifndef BEHAVIAC_ENABLE_NETWORKD
	#define BEHAVIAC_ENABLE_NETWORKD	0
#endif//BEHAVIAC_ENABLE_NETWORKD

#ifndef BEHAVIAC_ENABLE_LUA
	#define BEHAVIAC_ENABLE_LUA			0
#endif//BEHAVIAC_ENABLE_LUA

#if _MSC_VER
#if BEHAVIAC_ENABLE_LUA
	#pragma warning(disable : 4244) //conversion from 'int' to 'char', possible loss of data
	#pragma warning(disable : 4702) //unreachable code
	#pragma warning(disable : 4310) //cast truncates constant value
#endif
#endif


#include "behaviac/base/core/compiler.h"
//#include "behaviac/base/core/types.h"


#endif//BEHAVIAC_BASE_CORE_CONFIG_H
