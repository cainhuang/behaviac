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

#ifndef BEHAVIAC_PS_THREAD__INCLUDED
#define BEHAVIAC_PS_THREAD__INCLUDED

#include "behaviac/base/core/compiler.h"

#if BEHAVIAC_COMPILER_MSVC
#define BEHAVIAC_STDCALL __stdcall
#else
#include <sys/types.h>
#include <pthread.h>
#define BEHAVIAC_STDCALL
#endif//BEHAVIAC_COMPILER_MSVC


namespace behaviac
{
	typedef unsigned int THREAD_ID_TYPE;
}

// Invalid thread Id definition
#define BEHAVIAC_INVALID_TID        0xFFFFFFFF

namespace behaviac
{
    BEHAVIAC_API THREAD_ID_TYPE GetTID();

	/// Check if the given thread ID is valid.
	BEHAVIAC_API bool IsValidThread(THREAD_ID_TYPE threadID);

    namespace thread
    {
        typedef void*		ThreadHandle;
        typedef unsigned int (BEHAVIAC_STDCALL ThreadFunction)(void* arg);

        BEHAVIAC_API bool IsThreadTerminated(behaviac::thread::ThreadHandle hThread);
        BEHAVIAC_API ThreadHandle CreateAndStartThread(thread::ThreadFunction* function, void* arg, size_t stackSize);
        BEHAVIAC_API void StopThread(ThreadHandle th);
    }//namespace thread
}//namespace behaviac

#endif //BEHAVIAC_PS_THREAD__INCLUDED
