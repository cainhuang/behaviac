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

#ifndef BEHAVIAC_BASE_ASSERT_H
#define BEHAVIAC_BASE_ASSERT_H

#include "behaviac/base/core/config.h"

//#include <assert.h>
//_CRTDBG_MAP_ALLOC predefined in the project files
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

#if BEHAVIAC_COMPILER_MSVC
#include <crtdbg.h>
#else
#include <assert.h>
#define _ASSERT(exp) assert(exp)
#endif//BEHAVIAC_COMPILER_MSVC

#ifdef _DEBUG
#define BEHAVIAC_ENABLE_ASSERTS	1
#endif//#ifdef _DEBUG

#if	BEHAVIAC_ENABLE_ASSERTS
namespace behaviac
{
    BEHAVIAC_API bool IsAssertEnabled();
}//namespace behaviac

// notice: do not remove zz_ at the beginning of doAssert. It's to put static variables at the end of CW debugger watches.
#define _BEHAVIAC_ASSERT_GROUP_MESSAGE_(exp, message) \
    do { \
        static bool zz_doAssert = true; \
        if (::behaviac::IsAssertEnabled() && zz_doAssert) \
        { \
            bool eval=!(exp); \
            if (eval) \
            { \
                /*assert(0);*/\
                /*_ASSERT_EXPR(0, _CRT_WIDE(message));*/\
                _ASSERT(0);\
            } \
        } \
    } while ( false )

#define BEHAVIAC_ASSERT_GROUP_MESSAGE(exp, ...) _BEHAVIAC_ASSERT_GROUP_MESSAGE_(exp, FormatString(__VA_ARGS__))

#define BEHAVIAC_DEBUGCODE(code) code
#define BEHAVIAC_VERIFYCODE(code) \
    { \
        bool __TAGVERIFYCODE_testValue = code ? true : false; \
        BEHAVIAC_ASSERT(__TAGVERIFYCODE_testValue); \
    }

#else // #ifdef BEHAVIAC_ENABLE_ASSERTS
#define BEHAVIAC_ASSERT_GROUP_MESSAGE(exp, ...)
#define BEHAVIAC_DEBUGCODE(code) void(0)
#define BEHAVIAC_VERIFYCODE(code) code
#endif // #ifdef BEHAVIAC_ENABLE_ASSERTS

#define BEHAVIAC_ASSERT(exp, ...) BEHAVIAC_ASSERT_GROUP_MESSAGE( exp, ##__VA_ARGS__ )

// declare the variable as used (to remove unused variable warning)
#define BEHAVIAC_UNUSED_VAR(var)         ((void) &var)

#define BEHAVIAC_JOIN_TOKENS(a, b)			BEHAVIAC_JOIN_TOKENS_IMPL(a, b)
#define BEHAVIAC_JOIN_TOKENS_IMPL(a,	b)	BEHAVIAC_JOIN_TOKENS_IMPL2(a, b)
#define BEHAVIAC_JOIN_TOKENS_IMPL2(a, b)	a ## b

/**
usage:
int BEHAVIAC_UNIQUE_NAME(intVar) = 0;
*/
#define BEHAVIAC_UNIQUE_NAME(name) BEHAVIAC_JOIN_TOKENS(name, __LINE__)

//#define VA_NARGS(...) VA_NARGS_II((VA_NARGS_PREFIX_ ## __VA_ARGS__ ## _VA_NARGS_POSTFIX,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0))
//#define VA_NARGS_II(__args) VA_NARGS_I __args
//#define VA_NARGS_PREFIX__VA_NARGS_POSTFIX ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,0
//#define VA_NARGS_I(__p0,__p1,__p2,__p3,__p4,__p5,__p6,__p7,__p8,__p9,__p10,__p11,__p12,__p13,__p14,__p15,__p16,__p17,__p18,__p19,__p20,__p21,__p22,__p23,__p24,__p25,__p26,__p27,__p28,__p29,__p30,__p31,__n,...) __n

#endif//BEHAVIAC_BASE_ASSERT_H
