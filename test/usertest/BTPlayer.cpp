#include "BTPlayer.h"
#include <time.h>
#include <iostream>

using namespace std;
using namespace behaviac;

extern bool g_bMovePrint;
extern unsigned int g_uiRunCount;

BEGIN_PROPERTIES_DESCRIPTION(CBTPlayer)
REGISTER_PROPERTY(m_iBaseSpeed);

REGISTER_METHOD(MoveAhead).PARAM_DISPLAY_INFO(L"speed");
REGISTER_METHOD(MoveBack).PARAM_DISPLAY_INFO(L"speed");

REGISTER_METHOD(Condition);
REGISTER_METHOD(Action1);
REGISTER_METHOD(Action3);

END_PROPERTIES_DESCRIPTION()


CBTPlayer::CBTPlayer()
{
    //    SetVariable<int>("CurStep", 0);

    m_iBaseSpeed = 1;
    m_Frames = 0;
}

CBTPlayer::~CBTPlayer()
{
    m_iX = 0;
    m_iY = 0;
}

time_t CBTPlayer::GetCurTime()
{
    return time(NULL);
}

void CBTPlayer::MoveAhead(int speed)
{
    m_iX += (m_iBaseSpeed + speed);

    SetVariable<int>("CurStep", m_iX);

    int iVal = GetVariable<int>("CurStep");

    if (g_bMovePrint)
    {
        cout << "[" << GetCurTime() << "] Name:[" << GetName() << "] MoveAhead CurStep:" << iVal << " CurSpeed:" << speed << endl;
    }

    g_uiRunCount ++;
}

void CBTPlayer::MoveBack(int speed)
{
    m_iX -= (m_iBaseSpeed + speed);

    SetVariable<int>("CurStep", m_iX);

    int iVal = GetVariable<int>("CurStep");

    if (g_bMovePrint)
    {
        cout << "[" << GetCurTime() << "] Name:[" << GetName() << "] MoveBack CurStep:" << iVal << " CurSpeed:" << speed  << endl;
    }

    g_uiRunCount ++;
}

bool CBTPlayer::Condition()
{
    m_Frames = 0;
    cout << "\tCondition\n";
    return true;
}

behaviac::EBTStatus CBTPlayer::Action1()
{
    cout << "\tAction1\n";

    return behaviac::BT_SUCCESS;
}

behaviac::EBTStatus CBTPlayer::Action3()
{
    cout << "\tAction3\n";

    m_Frames++;

    if (m_Frames == 3)
    {
        return behaviac::BT_SUCCESS;
    }

    return behaviac::BT_RUNNING;
}
