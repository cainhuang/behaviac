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

#ifndef BEHAVIAC_SHARED_H_
#define BEHAVIAC_SHARED_H_

#include "behaviac/base/base.h"
#include "behaviac/base/core/system.h"

#include "behaviac/base/workspace.h"

#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/agent/agent.h"
#include "behaviac/world/world.h"

#include "behaviac/base/file/filemanager.h"
#include "behaviac/base/file/file.h"

namespace behaviac
{
	void CleanupTickingMutex();

	const char* VersionString()
	{
		return BEHAVIAC_VERSION_STRING;
	}
	
	bool Start(const char* versionString)
	{
		behaviac::SetMainThread();

        const char* verStr = behaviac::VersionString();

        if (strcmp(verStr, versionString) != 0)
        {
            BEHAVIAC_LOG2(BEHAVIAC_LOG_ERROR, "[behaviac]Behaviac Start Failed, Your Version %s while DLL Version %s\n", verStr, versionString);
			BEHAVIAC_ASSERT(0, "[behaviac]Behaviac Start Failed, Your Version %s while DLL Version %s\n", verStr, versionString);
			BEHAVIAC_LOGERROR("[behaviac]Behaviac Start Failed, Your Version %s while DLL Version %s\n, Please Make sure Debug/Release or Header/Lib are compatible\n", verStr, versionString);

            return false;
        }

		behaviac::Workspace::RegisterBasicNodes();

		return true;
	}

	void Stop()
	{
		Workspace::UnLoadAll();
		Workspace::UnRegisterBasicNodes();
		Workspace::Cleanup();

		BehaviorNode::Cleanup();

		CleanupTickingMutex();

		//Agent::Cleanup();
		//Variables::Cleanup();
		Property::Cleanup();
		Condition::Cleanup();
		CStringID::Cleanup();
		LogManager::DestroyInstance();

		CFileManager::Cleanup();

		Context::Cleanup();
	}

	static behaviac::THREAD_ID_TYPE gs_mainTheadId;

	void SetMainThread()
	{
		gs_mainTheadId = behaviac::GetTID();
	}

	bool IsMainThread()
	{
		behaviac::THREAD_ID_TYPE currentThreadId = behaviac::GetTID();
		return currentThreadId == gs_mainTheadId;
	}

	static BreakpointPromptHandler_fn gs_BreakpointPromptHandler = 0;
	void SetBreakpointPromptHandler(BreakpointPromptHandler_fn fn)
	{
		gs_BreakpointPromptHandler = fn;
	}

	BreakpointPromptHandler_fn GetBreakpointPromptHandler()
	{
		return gs_BreakpointPromptHandler;
	}
	
}//namespace behaviac

#endif // BEHAVIAC_SHARED_H_
