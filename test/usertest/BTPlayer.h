/***************************************************************************
 *
 * Copyright (C) 2015 tencent.com, Inc. All Rights Reserved
 * Team Group  : SGMobile Project, Server Development Team
 *
 **************************************************************************/

/**
 * @file  BTPlayer.h
 * @author  erictu@tencent.com
 * @date  2015-10-12 15:53:28
 * @brief  请在这里添加功能说明
 *
 **/

#ifndef _BTPLAYER_H_
#define _BTPLAYER_H_
#include "behaviac/behaviac.h"

#include <time.h>

using namespace behaviac;





class CBTPlayer: public Agent
{
public:
    DECLARE_BEHAVIAC_AGENT(CBTPlayer, Agent);


    CBTPlayer();
    virtual ~CBTPlayer();

    time_t GetCurTime();

    void MoveAhead(int speed);
    void MoveBack(int speed);

    bool Condition();
    behaviac::EBTStatus Action1();
    EBTStatus Action3();

private:
    int                 m_iX;
    int                 m_iY;
    unsigned int        m_iBaseSpeed;

    int					m_Frames;
};

#endif  ///_BTPLAYER_H_

