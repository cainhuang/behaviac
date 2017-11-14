#ifndef PLANEENEMY_H
#define PLANEENEMY_H

#include "cocos2d.h"

USING_NS_CC;
class Enemy;
//�з��ɻ���
class PlaneEnemy : public Sprite
{
public:
	enum EnemyPlaneType
	{
		Enemy1,
		Enemy2,
		Enemy3,
		Enemy4
	}; //ս������

	enum EnemyPlaneVec
	{
		Enemy1_Vec = 150,
		Enemy2_Vec = 100,
		Enemy3_Vec = 50,
		Enemy4_Vec = 50
	}; //ս���ٶ�

	enum EnemyLife
	{
		Enemy1_Life = 1,
		Enemy2_Life = 2,
		Enemy3_Life = 5,
		Enemy4_Life = 8
	}; //ս������

	enum Enemy_Points
	{
		Enemy1_Points = 10,
		Enemy2_Points = 20,
		Enemy3_Points = 50,
		Enemy4_Points = 80
	}; //ս������

    Enemy* myAgent;
public:
	//�Զ��幤������������enemy�кܶ��֣�����enemy�����ͳ�ʼ������init������г�ʼ��
	static PlaneEnemy* createWithEnemyType(int planetype);
	bool init(int planetype);

	void onEnter();

	void getHurt(); //�ɻ�������һ��
	bool isLive() { return m_live; }; 
	int getPoints() { return m_points; }
	int getType() { return m_planeType; }
    void setSpeed(float speed);
    float getSpeed();
private:
	void initEnemyBlowUpFrames(int planetype); //���ر�ը����ͼ��
	void moveOn(float dt); //schedule�ص���ÿdt���ƶ�һ�ξ���
	void blowUp(); //�ɻ���ը
    
private:
	int m_velocity; //ս���ٶ�
	int m_life; //ս����ǰ����
	int m_points; //ս����ֵ
	int m_planeType; //�л�����
	bool m_live; //�ɻ��Ƿ���ŵı�־

	Vector<SpriteFrame*> m_blowframes; //��ű�ը������֡
};

#endif

