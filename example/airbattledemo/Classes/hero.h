#pragma once
#include "behaviac/agent/agent.h"
#include "behaviac/agent/registermacros.h"
#include "cocos2d.h"
USING_NS_CC;
class PlaneHero;
class Hero :
    public behaviac::Agent
{
public:
    DECLARE_BEHAVIAC_OBJECT(Hero, behaviac::Agent);

    Hero();
    ~Hero();
    void dead(); //飞机挂掉
    Node* findAnEnemy();//find an enemy plane
    bool isWillBeCrashEnemy(Node* enemy, Point position);//test whether hero will be crash enemy at position

    Node* getEnemyInFrontOfPosition(Point position);// get Enemy in front of position
    Node* getNearestEnemy();//get the nearest enemy
    Node* getNearestEnemy(Point position);//get the nearest enemy 

    void AdjustHeroPosition(Node* hero);
    void setHeroPlaneUnderPosition(Point targetPosition);
    //m_isAI表示是否使用AI
    bool m_isAI;
    void setAI(bool value);
    //ai动作
    void AIAction(float level);
private:
    Node* nearestEnemy;
    PlaneHero* m_plane;

public:

    PlaneHero* getPlane();

    void setPlane(PlaneHero* heroPlane);
};