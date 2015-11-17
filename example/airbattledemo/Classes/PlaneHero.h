#ifndef PLANEHERO_H
#define PLANEHERO_H

#include "cocos2d.h"

USING_NS_CC;

//我方飞机类
class PlaneHero : public Sprite
{
public:
	//工厂方法，在init里面进行初始化
	CREATE_FUNC(PlaneHero);
	bool init();

	void onEnter();

public:
	void dead(); //飞机挂掉
    Node* findAnEnemy();//find an enemy plane
    bool isWillBeCrashEnemy(Node* enemy, Point position);//test whether hero will be crash enemy at position
    Node* getEnemyInFrontOfPosition(Point position);// get Enemy in front of position
    Node* getNearestEnemy();//get the nearest enemy
    Node* getNearestEnemy(Point position);//get the nearest enemy 

    void AdjustHeroPosition(Node* hero);
    void setHeroPlaneUnderPosition(Point _targetPosition);
    //m_isAI表示是否使用AI
    bool m_isAI;
    void setAI(bool value);
    //ai动作
    void AIAction(float level);
private:
	void beginShooting(float dt); //开始发射子弹，间隔dt秒发射一发
	void removeBullet(float dt); //移除射到屏幕外面的子弹
	void stopShooting(); //停止发射子弹

	void blowUp(); //飞机爆炸
    
    DrawNode * draw;
};

#endif

