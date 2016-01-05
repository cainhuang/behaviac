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

#include "behaviac/base/core/staticassert.h"
#include "behaviac/base/core/compiler.h"

#include "behaviac/base/core/types.h"

//please don't use the following macros in the public header files unless you know what you are doing.
//otherwise, it might be causing uncompatible layout for types

#define BEHAVIAC_ENABLE_NETWORKD		0

#if (defined(_DEBUG) || defined(DEBUG))
	#define _BEHAVIAC_VERSION_STR_ "behavaic_debug"
#else
	#define _BEHAVIAC_VERSION_STR_ "behavaic_ndebug"

	//use _DEBUG or DEBUG, don't directly define BEHAVIAC_RELEASE in the make or project file
	#ifndef BEHAVIAC_RELEASE
		#define BEHAVIAC_RELEASE	1
	#endif//BEHAVIAC_RELEASE
#endif//
                     
#define _BEHAVIAC_M_STRING_CONCAT_(a, b) a # b

#ifdef BEHAVIAC_RELEASE
	#define BEHAVIAC_VERSION_STR _BEHAVIAC_M_STRING_CONCAT_(_BEHAVIAC_VERSION_STR_, "_RELEASE")
#else
	#define BEHAVIAC_VERSION_STR _BEHAVIAC_M_STRING_CONCAT_(_BEHAVIAC_VERSION_STR_, "_NRELEASE")
#endif

#if !defined(BEHAVIAC_RELEASE)
#define BEHAVIAC_ENABLE_HOTRELOAD	1
#define BEHAVIAC_ENABLE_PROFILING	1
#endif//BEHAVIAC_RELEASE

#endif//BEHAVIAC_BASE_CORE_CONFIG_H
