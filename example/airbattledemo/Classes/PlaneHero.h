#ifndef PLANEHERO_H
#define PLANEHERO_H

#include "cocos2d.h"

USING_NS_CC;

//�ҷ��ɻ���
class PlaneHero : public Sprite
{
public:
	//������������init������г�ʼ��
	CREATE_FUNC(PlaneHero);
	bool init();

	void onEnter();

public:
	void dead(); //�ɻ��ҵ�
    Node* findAnEnemy();//find an enemy plane
    bool isWillBeCrashEnemy(Node* enemy, Point position);//test whether hero will be crash enemy at position
    Node* getEnemyInFrontOfPosition(Point position);// get Enemy in front of position
    Node* getNearestEnemy();//get the nearest enemy
    Node* getNearestEnemy(Point position);//get the nearest enemy 

    void AdjustHeroPosition(Node* hero);
    void setHeroPlaneUnderPosition(Point _targetPosition);
    //m_isAI��ʾ�Ƿ�ʹ��AI
    bool m_isAI;
    void setAI(bool value);
    //ai����
    void AIAction(float level);
    //the below method will be exoport for behaviac
    void findAnNearestEnemy();
    bool isWillBeCrashOnNearestEnemy();
    void EscapeEnemyCrash();
    bool hasEnemyInFrontCanAttack();
    void findAnEnemyAndAttack();
    void clearScreenDebugInfo();
    void enableShowScreenDebugInfo(bool value);
private:
	void beginShooting(float dt); //��ʼ�����ӵ������dt�뷢��һ��
	void removeBullet(float dt); //�Ƴ��䵽��Ļ������ӵ�
	void stopShooting(); //ֹͣ�����ӵ�

	void blowUp(); //�ɻ���ը
    
private:
    DrawNode*   draw;
    Node*       nearestEnemy;//store the nearest enemy
    Node        frontEnemy;//enemy in front of hero plane
    bool        showDebugInfo;//show debug info on screen
};

#endif

