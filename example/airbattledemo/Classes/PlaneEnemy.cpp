#include "PlaneEnemy.h" 
#include "SimpleAudioEngine.h"
#include "enemy.h"
using namespace CocosDenshion;

PlaneEnemy* PlaneEnemy::createWithEnemyType(int planetype)
{
	//�Զ���һ���������������ݴ����ս�����ͣ���ʼ���з�ս��
	auto plane = new PlaneEnemy();
	if (plane && plane->init(planetype))
	{
		plane->autorelease();
		return plane;
	}
	else
	{
		CC_SAFE_DELETE(plane);
		return nullptr;
	}
}
/*
�л����ݳ�ʼ��
*/
bool PlaneEnemy::init(int planetype)
{
	Sprite::init();

	m_planeType = planetype;
	m_live = true;
	
	//��ʼ������ͼ��ս���ٶȣ���������ֵ
	String framename;
	switch (planetype)
	{
	case EnemyPlaneType::Enemy1:
		framename = "enemy1.png";
		m_velocity = random(0.5, 1.5) * Enemy1_Vec; //����һ������ٶ�
		m_life = Enemy1_Life;
		m_points = Enemy1_Points;
		break;
	case EnemyPlaneType::Enemy2:
		framename = "enemy2.png";
		m_velocity = random(0.5, 1.5) * Enemy2_Vec;
		m_life = Enemy2_Life;
		m_points = Enemy2_Points;
		break;
	case EnemyPlaneType::Enemy3:
		framename = "enemy3_n1.png";
		m_velocity =  random(0.5, 1.5) * Enemy3_Vec;
		m_life = Enemy3_Life;
		m_points = Enemy3_Points;
		break;
	case EnemyPlaneType::Enemy4:
		framename = "enemy3_n2.png";
		m_velocity = random(0.5, 1.5) * Enemy4_Vec;
		m_life = Enemy4_Life;
		m_points = Enemy4_Points;
		break;
	}
	initWithSpriteFrameName(framename.getCString());

	//���ص��˱�ը����֡����
	initEnemyBlowUpFrames(planetype);

	return true;
}

void PlaneEnemy::onEnter()
{
	Sprite::onEnter();

	schedule(schedule_selector(PlaneEnemy::moveOn)); //ս������󣬿�ʼ�ƶ�
}
/*
��ӱ�ը���¼�
*/
void PlaneEnemy::blowUp()
{
	//����ս�����Ͳ�����Ч
	switch (m_planeType)
	{
	case Enemy1:
		SimpleAudioEngine::getInstance()->playEffect("sound/enemy1_down.wav");
		break;
	case Enemy2:
		SimpleAudioEngine::getInstance()->playEffect("sound/enemy2_down.wav");
		break;
	case Enemy3:
		SimpleAudioEngine::getInstance()->playEffect("sound/enemy3_down.wav");
		break;
	case Enemy4:
		SimpleAudioEngine::getInstance()->playEffect("sound/enemy3_down.wav");
		break;
	}

	//������������
	auto animation = Animation::createWithSpriteFrames(m_blowframes);
	animation->setDelayPerUnit(0.2);
	animation->setRestoreOriginalFrame(true);
	auto blowUp = Animate::create(animation);

	//��ը������
	auto clear = CallFunc::create([this]() {
        //set the agent's m_plane is null
        
		removeFromParent();
		//log("enemy cleared!");
	});
    //���������ָ���Լ���ָ��ȥ��
    this->myAgent->setPlane(nullptr);

	this->runAction(Sequence::create(blowUp, clear, nullptr));
}

//set the PlaneEnemy's speed
void PlaneEnemy::setSpeed(float speed)
{
    this->m_velocity = (int)speed;
}

/*get the PlaneEnemy's speed*/
float PlaneEnemy::getSpeed()
{
    return this->m_velocity;
}


void PlaneEnemy::getHurt()
{
	m_life--;
	if (m_life <= 0)
	{
		m_live = false;
		getPhysicsBody()->setContactTestBitmask(0x0); ////������ײ��־λ�����ٷ�����ײ�¼�
		blowUp(); //���ű�ը����
		return;
	}
	else if (m_planeType != Enemy1) //����ս��û�����˶���
	{
		//�������˶���
		SpriteFrame *hurt = nullptr;
		SpriteFrame *old = nullptr;
		switch (m_planeType)
		{
		case Enemy2:
			hurt = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_hit.png");
			old = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2.png");
			break;
		case Enemy3:
			hurt = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_hit.png");
			old = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png");
			break;
		case Enemy4:
			hurt = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_hit.png");
			old = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png");
			break;
		}

		auto setHurtImg = CallFunc::create([this, hurt](){
			this->setSpriteFrame(hurt);
		});

		auto setOldImg = CallFunc::create([this, old](){
			this->setSpriteFrame(old);
		});

		auto hurtAction = Sequence::create(setHurtImg, DelayTime::create(0.2), setOldImg, nullptr);

		this->stopAllActions();
		this->runAction(hurtAction);
	}
}
/*
��ʼ��ÿһ��ս����ը��Ч��
*/
void PlaneEnemy::initEnemyBlowUpFrames(int planetype)
{
	if (planetype == EnemyPlaneType::Enemy1)
	{
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down1.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down2.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down3.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down4.png"));
	}
	
	else if (planetype == EnemyPlaneType::Enemy2)
	{
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down1.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down2.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down3.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down4.png"));
	}

	else
	{
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down1.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down2.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down3.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down4.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down5.png"));
		m_blowframes.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down6.png"));
	}
}

void PlaneEnemy::moveOn(float dt)
{
	//log("enemy moveon!");
    m_velocity =(int) this->myAgent->speed;
	//�����н��ٶȣ������ƶ���һ�����磬�����ȥ
	this->setPositionY(getPositionY() - dt * m_velocity);
	if (getPositionY() < -this->getContentSize().height / 2)
	{
		removeFromParent();
		//log("enemy out!");
	}
}