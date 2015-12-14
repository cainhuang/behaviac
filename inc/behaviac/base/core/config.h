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


#if BEHAVIAC_COMPILER_MSVC
//warning C4275: non dll-interface class 'stdext::exception' used as base for dll-interface class 'std::bad_cast'
#pragma warning(disable : 4275)

//warning C4530: C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc
#pragma warning(disable : 4530)

//warning C4251: 'behaviac::VariableRegistry::m_proxyHolders' : class 'behaviac::vector<T>' needs to have dll-interface to be used
//by clients of class 'behaviac::VariableRegistry'
#pragma warning(disable : 4251)

//unreferenced formal parameter
#pragma warning(disable : 4100)

#pragma warning(disable : 4127) // conditional expression is constant

//warning C4702: unreachable code
#pragma warning(disable : 4702)

#endif//BEHAVIAC_COMPILER_MSVC

//please don't use the following macros in the public header files unless you know what you are doing.
//otherwise, it might be causing uncompatible layout for types

#define BEHAVIAC_ENABLE_NETWORKD		0

#if (defined(_DEBUG) || defined(DEBUG))
//developement version
#else
#ifndef BEHAVIAC_RELEASE
#define BEHAVIAC_RELEASE	1
#endif//BEHAVIAC_RELEASE
#endif//

#if !defined(BEHAVIAC_RELEASE)
#define BEHAVIAC_ENABLE_HOTRELOAD	1
#define BEHAVIAC_ENABLE_PROFILING	1
#endif//BEHAVIAC_RELEASE

#endif//BEHAVIAC_BASE_CORE_CONFIG_H
