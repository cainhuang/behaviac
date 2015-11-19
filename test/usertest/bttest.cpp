#include "behaviac/behaviac.h"

#include "BTPlayer.h"

#include "./behaviac/exported/behaviac_generated/behaviors/generated_behaviors.h"
#include "./behaviac/exported/behaviac_generated/types/agentproperties.h"

#if BEHAVIAC_COMPILER_MSVC
#include <windows.h>
#endif

#include <time.h>
#include <iostream>

using namespace std;
using namespace behaviac;


CBTPlayer* g_player = NULL;
CBTPlayer* g_player1 = NULL;

bool g_bMovePrint = true;
unsigned int g_uiRunCount = 0;


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

    behaviac::Agent::RegisterInstanceName<CBTPlayer>("player1");

    behaviac::Workspace::GetInstance()->SetFilePath("../test/usertest/behaviac/exported");
    behaviac::Workspace::GetInstance()->SetFileFormat(ff);

    behaviac::Workspace::GetInstance()->ExportMetas("../test/usertest/behaviac/btest.xml");

    //behaviac::Agent::SetIdMask(kIdMask_Wolrd | kIdMask_Opponent);
    behaviac::Workspace::GetInstance()->SetDeltaFrames(1);

    //printf("game starting...\n");

    return true;
}


bool InitPlayer(const char* pszTreeName)
{
    g_player = behaviac::Agent::Create<CBTPlayer>();
    g_player1 = behaviac::Agent::Create<CBTPlayer>("player1");

    bool bRet = false;
    bRet = g_player->btload(pszTreeName);
    assert(bRet);

    g_player->btsetcurrent(pszTreeName);

    bRet = g_player1->btload(pszTreeName);
    assert(bRet);

    g_player1->btsetcurrent(pszTreeName);


    return bRet;
}

void CleanupPlayer()
{
    behaviac::Agent::Destroy(g_player);
    behaviac::Agent::Destroy(g_player1);
}

void CleanupBehaviac()
{
    behaviac::Agent::UnRegisterInstanceName<CBTPlayer>("player1");

    behaviac::Agent::UnRegister<CBTPlayer>();

	behaviac::Workspace::GetInstance()->Cleanup();
}

//cmdline: behaviorTreePath Count ifprint fileformat
int main(int argc, char** argv)
{
    SetExePath();

    cout << "usage: btPath [loopCout] [0|1] [xml|cpp|bson]\n\n";

	const char* szTreeName = "demo_running";
	if (argc > 1)
	{
		szTreeName = argv[1];
	}

	cout << "bt:" << szTreeName << "\n\n";

    int iCount = argc > 2 ? atoi(argv[2]) : 0;
    g_bMovePrint = argc > 3 && atoi(argv[3]) != 0 ? true : false;

    const char* ffParam = argc > 4 ? argv[4] : "xml";

    behaviac::Workspace::EFileFormat ff = behaviac::Workspace::EFF_xml;

    if (behaviac::StringUtils::StrEqualNoCase(ffParam, "xml"))
    {
        ff = behaviac::Workspace::EFF_xml;
    }
    else if (behaviac::StringUtils::StrEqualNoCase(ffParam, "bson"))
    {
        ff = behaviac::Workspace::EFF_bson;
    }
    else if (behaviac::StringUtils::StrEqualNoCase(ffParam, "cpp"))
    {
        ff = behaviac::Workspace::EFF_cpp;
    }
    else
    {
        BEHAVIAC_ASSERT(false);
        cout << "unrecognized file format " << ffParam << std::endl;
    }


    InitBehavic(ff);
    InitPlayer(szTreeName);

    //if (iCount > 0)
    //{
    //	cout << "initialized successfully,  executing...\n";
    //}

    clock_t start = clock();

    int i  = 0;

    if (iCount == 0)
    {
        int frames = 0;
        behaviac::EBTStatus status = behaviac::BT_RUNNING;

        while (status == behaviac::BT_RUNNING)
        {
            cout << "frame " << ++frames << std::endl;
            status = g_player->btexec();
        }
    }
    else
    {
        while (i++ < iCount)
        {
            behaviac::Workspace::GetInstance()->Update();
        };
    }

    clock_t finish = clock();

    if (iCount > 0)
    {
        float duration = (float)(finish - start) / CLOCKS_PER_SEC;

        cout << "format " << ffParam << " duration(seconds):" << duration << " RunCount:" << g_uiRunCount << endl;
    }

    CleanupPlayer();
    CleanupBehaviac();

#if defined(BEHAVIAC_COMPILER_MSVC)
    cout << "\npress any key to exit\n";
    getchar();
#endif

    return 0;
}




