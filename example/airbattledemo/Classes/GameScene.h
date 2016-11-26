#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "behaviac/base/core/container/vector_t.h"
USING_NS_CC;

class PlaneEnemy;
class PlaneHero;
class NPC;
class Hero;
namespace behaviac{
    class Agent;
}
//��Ϸ��������
class GameScene : public Layer
{
    //��������Ϸ������Ϣ
public:
    enum NodeTag
    {
        HERO_TAG = 100,
        ENEMY_TAG = 101,
        HERO_BULLET_TAG = 102,
        SCORE_LABEL = 103,
        PAUSE_MENU = 104,
        AI_TAG = 105,
    };

    //��ײ�¼�bitλ
    enum ContactMaskBit
    {
        ENEMY_CONTACTMASKBIT = 0x01 || 0x02,
        HERO_BULLET_CONTACTMASKBIT = 0x01,
        HERO_CONTACTMASKBIT = 0x02
    };

    //��Ϸlevel������Խ��levelԽ��
    enum Level
    {
        LEVEL1,
        LEVEL2,
        LEVEL3,
        LEVEL4,
        LEVEL5
    };

    ////level��������ķ���
    //enum LevelUp_Score
    //{
    //       Level1Up_Score = 0,
    //	Level2Up_Score = 200,
    //	Level3Up_Score = 500,
    //	Level4Up_Score = 1000
    //};

    static const float refresh_delay[]; //ս��ˢ�¼��

public:
    static Scene* createScene();
    CREATE_FUNC(GameScene);
    bool init();

public:
    static GameScene* sharedGameLayer() { return m_gamelayer; } //��ȡ����Ϸ�㵥������

private:
    static GameScene* m_gamelayer; //��Ϸ������ĵ�������
public:
    SpriteBatchNode* getBulletBox() { return m_bulletBox; }	 //��ȡ�ӵ���Ⱦ��
    void AdjustHeroPosition(Node* hero);
    void gameover();
private:
    SpriteBatchNode *m_bulletBox; //����ӵ�����Ⱦ��

private:
    int m_level; //��ǰ��Ϸlevel
    int m_score; //��ǰ��Ϸ����

private:
    void playBackground(); //�������ƶ���Ϸ����
    void publishScore(); //�洢��Ϸ����

    void pauseButtonCallBack(Ref* pSender); //�����ͣ��ť�ص�����
    void AIButtonCallBack(Ref* pSender); //���AI��ť�ص�����

    bool dealWithContact(PhysicsContact&); //������ײ�¼��ص�����
    void hitEnemy(PlaneEnemy* enemy);
    void hitHero(PlaneHero* hero);

    void levelUp(Level level);//��������
    //��Ϸ��schedule�Ļص�����
    void testLevel(float dt); //ÿ�����һ�Σ����ݵ�ǰ����ķ���������Ϸlevel
    //����hero Plane's position
    //void setHeroPlaneUnderPosition(CCPoint _targetPosition);
    //m_isAI��ʾ�Ƿ�ʹ��AI
    bool m_isAI;
    //m_canBossRefresh��ʾ�ɷ�ˢ��boss��ÿ��dt�����ˢ��һ��
    void resetBoss(float dt);
    NPC * m_NPC;
    Hero* m_Hero;
public:
    // //create Update for behaviac
    void Update(float dt);
    static void addBehaviacAgentDeleteQueue(behaviac::Agent* pAgent);
private:
    static void cleanBehaviacAgentDeleteQueue();
private:
    /******************************************************************
    Date        : 2015-11-13 16:40:05
    Author      : Quinn Pan
    Desc        : add some behaviac into the queue , and delete it
    ******************************************************************/
    static behaviac::vector<behaviac::Agent*> m_bt_agent_delete_queue;
};

#endif

