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

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"
#include "behaviac/base/core/system.h"
#include "behaviac/base/core/thread/thread.h"

#if !BEHAVIAC_COMPILER_MSVC
#if BEHAVIAC_COMPILER_GCC_LINUX
#include <sys/syscall.h>
#include <linux/unistd.h>
#else
//
#endif

#include <sys/types.h>
#include <unistd.h>

// Crap imported by platform includes
#ifdef System
#undef System
#endif

namespace behaviac
{
    THREAD_ID_TYPE GetTID()
    {
#if BEHAVIAC_COMPILER_GCC_LINUX
		//pthread_t t = pthread_self();

		//pthread_id_np_t   tid = pthread_getthreadid_np();

		//#define __NR_gettid 224
		pid_t tid = syscall(__NR_gettid);
		//pid_t tid = gettid();

		return (THREAD_ID_TYPE)tid;
#else
		pthread_t tid = pthread_self();

#if BEHAVIAC_COMPILER_APPLE
		return (THREAD_ID_TYPE)(uintptr_t)tid;
#else
		return (THREAD_ID_TYPE)tid;
#endif
#endif
    }

    Address GetModuleID()
    {
        BEHAVIAC_ASSERT(0);
        return BEHAVIAC_PTR_TO_ADDR(0);
    }

    void Sleep(uint32_t timeMS)
    {
        BEHAVIAC_UNUSED_VAR(timeMS);
        BEHAVIAC_ASSERT(0);
    }

    void YieldCPU()
    {
        BEHAVIAC_ASSERT(0);
    }

    bool IsValidThread(uint32_t threadID)
    {
        BEHAVIAC_UNUSED_VAR(threadID);
        BEHAVIAC_ASSERT(0);
        return true;
    }

    const Char* GetExeName(Char* exeNameBuffer, uint32_t exeNameBufferSize)
    {
        BEHAVIAC_UNUSED_VAR(exeNameBuffer);
        BEHAVIAC_UNUSED_VAR(exeNameBufferSize);

        BEHAVIAC_ASSERT(0);
        return 0;
    }

    void SetExeName(const Char* exeNameBuffer)
    {
        BEHAVIAC_UNUSED_VAR(exeNameBuffer);

        BEHAVIAC_ASSERT(0);
    }

    void* MemCmpPattern(const void* buffer, uint8_t value, size_t size)
    {
        BEHAVIAC_UNUSED_VAR(buffer);
        BEHAVIAC_UNUSED_VAR(value);
        BEHAVIAC_UNUSED_VAR(size);

        BEHAVIAC_ASSERT(0);
        return 0;
    }

    void* MemCmpPatternReverse(const void* buffer, uint8_t value, size_t size)
    {
        BEHAVIAC_UNUSED_VAR(buffer);
        BEHAVIAC_UNUSED_VAR(value);
        BEHAVIAC_UNUSED_VAR(size);

        BEHAVIAC_ASSERT(0);
        return 0;
    }

    void* memcpy_ps(void* dest, const void* src, size_t num)
    {
        BEHAVIAC_UNUSED_VAR(dest);
        BEHAVIAC_UNUSED_VAR(src);
        BEHAVIAC_UNUSED_VAR(num);

        BEHAVIAC_ASSERT(0);
        return 0;
    }
}

#endif//#if !BEHAVIAC_COMPILER_MSVC
