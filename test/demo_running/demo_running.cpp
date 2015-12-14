///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Tencent is pleased to support the open source community by making behaviac available.
////
//// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
////
//// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
//// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
////
//// Unless required by applicable law or agreed to in writing, software distributed under the License is
//// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//// See the License for the specific language governing permissions and limitations under the License.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behaviac/behaviac.h"

#include "BTPlayer.h"

#include "./behaviac/exported/behaviac_generated/behaviors/generated_behaviors.h"
#include "./behaviac/exported/behaviac_generated/types/agentproperties.h"

#if BEHAVIAC_COMPILER_MSVC
#include <windows.h>
#endif

#include <iostream>

using namespace std;
using namespace behaviac;

CBTPlayer* g_player = NULL;

static void SetExePath()
{
#if BEHAVIAC_COMPILER_MSVC
    TCHAR szCurPath[_MAX_PATH];

    GetModuleFileName(NULL, szCurPath, _MAX_PATH);

    char* p = szCurPath;

    while (strchr(p, '\\'))
    {
        p = strchr(p, '\\');
        p++;
    }

    *p = '\0';

    SetCurrentDirectory(szCurPath);
#endif
}

bool InitBehavic(behaviac::Workspace::EFileFormat ff)
{
    behaviac::Config::SetSocketBlocking(false);
    behaviac::Config::SetSocketPort(8081);

    behaviac::Agent::Register<CBTPlayer>();

    behaviac::Workspace::GetInstance()->SetFilePath("../test/demo_running/behaviac/exported");
    behaviac::Workspace::GetInstance()->SetFileFormat(ff);

    behaviac::Workspace::GetInstance()->ExportMetas("../test/demo_running/behaviac/demo_running.xml");

    //behaviac::Agent::SetIdMask(kIdMask_Wolrd | kIdMask_Opponent);
    behaviac::Workspace::GetInstance()->SetDeltaFrames(1);

    return true;
}

bool InitPlayer(const char* pszTreeName)
{
    g_player = behaviac::Agent::Create<CBTPlayer>();

    bool bRet = false;
    bRet = g_player->btload(pszTreeName);
    assert(bRet);

    g_player->btsetcurrent(pszTreeName);

    return bRet;
}

void UpdateLoop()
{
	int i  = 0;
	int frames = 0;
	behaviac::EBTStatus status = behaviac::BT_RUNNING;

	while (status == behaviac::BT_RUNNING)
	{
		cout << "frame " << ++frames << std::endl;
		status = g_player->btexec();
	}
}

void CleanupPlayer()
{
    behaviac::Agent::Destroy(g_player);
}

void CleanupBehaviac()
{
    behaviac::Agent::UnRegister<CBTPlayer>();

	behaviac::Workspace::GetInstance()->Cleanup();
}

//cmdline: behaviorTreePath Count ifprint fileformat
int main(int argc, char** argv)
{
    SetExePath();

	const char* szTreeName = "demo_running";

	cout << "bt:" << szTreeName << "\n\n";

    behaviac::Workspace::EFileFormat ff = behaviac::Workspace::EFF_xml;

    InitBehavic(ff);
    InitPlayer(szTreeName);

    UpdateLoop();

    CleanupPlayer();
    CleanupBehaviac();

#if defined(BEHAVIAC_COMPILER_MSVC)
    cout << "\npress any key to exit\n";
    getchar();
#endif

    return 0;
}
