#include "PlaneHero.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

bool PlaneHero::init()
{
    Sprite::init();
    //set ai action false
    m_isAI = false;
    //��ʼ������ͼ
    initWithSpriteFrameName("hero2.png");

    draw = nullptr;
    showDebugInfo = true;
    return true;
}

void PlaneHero::onEnter()
{
    Sprite::onEnter();

    draw = DrawNode::create();
    this->getParent()->addChild(draw, 10);

    //����󣬿�ʼ�����ӵ�
    schedule(schedule_selector(PlaneHero::beginShooting), 0.5f);
    //����ӵ��Ƿ���磬�����������bulletBox
    schedule(schedule_selector(PlaneHero::removeBullet), 0.1f);
    if (m_isAI){
        //schedule(schedule_selector(PlaneHero::AIAction), 0.3f);
    }
}

/*
seek for an enemy
*/
Node* PlaneHero::findAnEnemy()
{
    auto children = this->getParent()->getChildren();
    for each (auto var in children)
    {
        //TODO: add some comditions be better
        if (var->getTag() == GameScene::ENEMY_TAG)
        {
            return var;
        }
    }
    //if don't find an enemy, return null
    return NULL;
}

/*
*test whether hero will be crash enemy at position
*/
bool PlaneHero::isWillBeCrashEnemy(Node* enemy, Point position = Vec2(-1, 0))//whether will be crash enemy on position
{
    //Point::ZERO;
    assert(this->getTag() == GameScene::HERO_TAG);
    auto hero = this;
    //auto hero = this->getParent()->getChildByTag(GameScene::HERO_TAG);
    Size heroSize = hero->getBoundingBox().size;
    if (position == Vec2(-1, 0))
    {
        position = hero->getPosition();
    }
    float width = heroSize.width + 10;
    float heigth = heroSize.height + 60;
    //���������ײ����
    Rect detectRect = Rect(position - Vec2(width / 2, heroSize.height / 2), Size(width, heigth));
    if (showDebugInfo)
    {
        //������ײ����
        draw->drawRect(detectRect.origin, Vec2(detectRect.getMaxX(), detectRect.getMaxY()), Color4F().GREEN);
    }

    //�������ĵ���
    auto nearestEnemy = getNearestEnemy(position);
    if (nearestEnemy != NULL)
    {
        return nearestEnemy->getBoundingBox().intersectsRect(detectRect);
    }
    return false;
}

/*
* get the nearest enemy
*/
Node* PlaneHero::getNearestEnemy()
{
    auto children = this->getParent()->getChildren();
    auto hero = this->getParent()->getChildByTag(GameScene::HERO_TAG);
    Point heroPosition = hero->getPosition();

    return getNearestEnemy(heroPosition);
}

Node* PlaneHero::getNearestEnemy(Point position)//get the nearest enemy
{
    auto children = this->getParent()->getChildren();
    Node* nearestEnemy = NULL;
    float minDistance = 81000000;
    float distance = 0.0;

    for each(auto var in children)
    {
        if (var->getTag() == GameScene::ENEMY_TAG)
        {
            distance = position.distanceSquared(var->getPosition());
            if (distance < minDistance)
            {
                minDistance = distance;
                nearestEnemy = var;
            }
        }

    }
    //set the nearest Enemy red color.
    if (nearestEnemy){
        nearestEnemy->setColor(Color3B(255, 0, 0));
    }
    return nearestEnemy;
}


/******************************************************************
Function    : void PlaneHero::AdjustHeroPosition(Node* hero = NULL)
Date        : 2015-11-18 10:05:06
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : if the hero's position above 40% of screen's height or below 20% of screen's heigth, then should adjust hero's screen position
******************************************************************/
void PlaneHero::AdjustHeroPosition(Node* hero = NULL)
{
    if (hero == NULL)
    {
        //hero = getChildByTag(GameScene::HERO_TAG);
        assert(this->getTag() == GameScene::HERO_TAG);
        hero = this;
    }
    auto enemy = getEnemyInFrontOfPosition(hero->getPosition());
    auto winHeight = CCDirector::getInstance()->getWinSize().height;
    if (enemy && enemy->getPosition().y > winHeight*0.4 && hero->getPosition().y < winHeight*0.1)
    {
        auto nearEnemy = getNearestEnemy(Vec2(hero->getPosition().x, winHeight*0.1));
        if (isWillBeCrashEnemy(nearEnemy))
        {
            return;
        }
        hero->setPosition(Vec2(hero->getPosition().x, winHeight*0.1));
    }
}

/**
* set Hero's Plane position under target's position
* not a  wonderful method, have some no agrorithm in it
* some time it will make hero's plane crash enemy and destory the hero
*/
void PlaneHero::setHeroPlaneUnderPosition(Point targetPosition)
{
    //auto hero = (PlaneHero*)(this->getParent()->getChildByTag(GameScene::HERO_TAG));
    assert(this->getTag() == GameScene::HERO_TAG);
    auto hero = this;
    if (hero == nullptr) return;
    Point point = Vec2(targetPosition.x, hero->getPosition().y);
    auto enemy = getNearestEnemy(point);

    if (isWillBeCrashEnemy(enemy, point))
    {
        //�����λ�ý��ᷢ����ײ���Ͳ�����
        return;
    }
    //set hero's position
    hero->setPosition(point);
}

void PlaneHero::setAI(bool value){
    m_isAI = value;
    if (draw != nullptr)
    {
        draw->clear();
    }
    //if (m_isAI){
    //    schedule(schedule_selector(PlaneHero::AIAction), 0.3f);
    //}
    //else{
    //    unschedule(schedule_selector(PlaneHero::AIAction));
    //}
}


/******************************************************************
Function    : void PlaneHero::AIAction(float level)
Date        : 2015-11-18 10:20:26
Author      : Quinn Pan
Parameter   :
Return      :
Desc        :  AI action ,make hero plane attack enemy automatic
******************************************************************/
void PlaneHero::AIAction(float level)
{
    //draw->clear();
    //assert(this->getTag() == GameScene::HERO_TAG);
    ////auto hero = (PlaneHero*)this->getParent()->getChildByTag(GameScene::HERO_TAG);
    //auto hero = this;
    //if (hero == NULL)
    //{
    //    return;
    //}
    ////������ײ
    ////����һ���Գ����Լ��ľ��ΰ�Χ�Լ���Ȼ������ײ�������ײ���ƶ���
    ////����һ�����صĿ�ȣ�����������ˣ������Ч���ή��
    ////����һ����ײ����

    //auto nearestEnemy = getNearestEnemy();//get the nearest enemy {findAnNearestEnemy}
    //if (nearestEnemy != NULL && isWillBeCrashEnemy(nearestEnemy))//the enemy is not null and will be crash on the hero plane {isWillbeCrashEnemy }
    //{
    //    //{EscapeEnemyCrash}
    //    auto enemyPosition = nearestEnemy->getPosition();
    //    auto heroPosition = hero->getPosition();

    //    //���ҵ���
    //    if (enemyPosition.x > heroPosition.x)
    //    {
    //        heroPosition.x = enemyPosition.x - (nearestEnemy->getBoundingBox().size.width + hero->getBoundingBox().size.width) / 2 - 6;
    //        hero->setPosition(heroPosition);
    //    }
    //    else if (enemyPosition.x < heroPosition.x)
    //    {
    //        heroPosition.x = enemyPosition.x + (nearestEnemy->getBoundingBox().size.width + hero->getBoundingBox().size.width) / 2 + 6;
    //        hero->setPosition(heroPosition);
    //    }
    //    else //hero �� enemy����ͬһ��ֱ��ֱ����
    //    {
    //        //���������ǰ�����ģ����к�·������
    //        if (heroPosition.y > 0 && enemyPosition.y > heroPosition.y)
    //        {
    //            heroPosition.y = heroPosition.y - 10;
    //            hero->setPosition(heroPosition);
    //        }
    //        else //���²����µ�λ��
    //        {
    //            setHeroPlaneUnderPosition(heroPosition);
    //        }

    //    }
    //}

    //if (getEnemyInFrontOfPosition(hero->getPosition()) == NULL)// if no enemy in front of hero, then search for an enemy {AttackFrontEnemy}
    //{
    //    //find an enemy and set the hero plane under the enemey{findAnEnemeyAndAttack}
    //    auto enemy = findAnEnemy();
    //    if (enemy)
    //    {
    //        setHeroPlaneUnderPosition(enemy->getPosition());
    //    }
    //}
    ////adjust plane's position {AdjustHeroScreenPosition}
    //AdjustHeroPosition();

}

/******************************************************************
Function    : void PlaneHero::findAnNearestEnemy()
Date        : 2015-11-18 10:28:29
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : find an nearest enemy
******************************************************************/
void PlaneHero::findAnNearestEnemy()
{
    if (draw)
    {
        draw->clear();
    }
    assert(this->getTag() == GameScene::HERO_TAG);
    //auto hero = (PlaneHero*)this->getParent()->getChildByTag(GameScene::HERO_TAG);
    auto hero = this;

    nearestEnemy = getNearestEnemy();//get the nearest enemy {findAnNearestEnemy}
}

/******************************************************************
Function    : bool PlaneHero::isWillBeCrashOnNearestEnemy()
Date        : 2015-11-18 10:30:08
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : tell whether the hero will be crash on the nearest enemy
******************************************************************/
bool PlaneHero::isWillBeCrashOnNearestEnemy()
{
    if (nearestEnemy != NULL && isWillBeCrashEnemy(nearestEnemy))//the enemy is not null and will be crash on the hero plane {isWillbeCrashEnemy }
    {
        return true;
    }
    return false;
}

/******************************************************************
Function    : void PlaneHero::EscapeEnemyCrash()
Date        : 2015-11-18 10:32:23
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : escape enemy's crash
******************************************************************/
void PlaneHero::EscapeEnemyCrash()
{
    //{EscapeEnemyCrash}
    auto hero = this;
    auto enemyPosition = nearestEnemy->getPosition();
    auto heroPosition = hero->getPosition();

    //���ҵ���
    if (enemyPosition.x > heroPosition.x)
    {
        heroPosition.x = enemyPosition.x - (nearestEnemy->getBoundingBox().size.width + hero->getBoundingBox().size.width) / 2 - 6;
        hero->setPosition(heroPosition);
    }
    else if (enemyPosition.x < heroPosition.x)
    {
        heroPosition.x = enemyPosition.x + (nearestEnemy->getBoundingBox().size.width + hero->getBoundingBox().size.width) / 2 + 6;
        hero->setPosition(heroPosition);
    }
    else //hero �� enemy����ͬһ��ֱ��ֱ����
    {
        //���������ǰ�����ģ����к�·������
        if (heroPosition.y > 0 && enemyPosition.y > heroPosition.y)
        {
            heroPosition.y = heroPosition.y - 10;
            hero->setPosition(heroPosition);
        }
        else //���²����µ�λ��
        {
            setHeroPlaneUnderPosition(heroPosition);
        }

    }
}

/******************************************************************
Function    : bool PlaneHero::hasEnemyInFrontCanAttack()
Date        : 2015-11-18 10:34:33
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : whether the hero has Enemy can attack
******************************************************************/
bool PlaneHero::hasEnemyInFrontCanAttack()
{
    if (getEnemyInFrontOfPosition(this->getPosition()) == NULL)
    {
        return false;
    }
    return true;
}

/******************************************************************
Function    : void PlaneHero::findAnEnemyAndAttack()
Date        : 2015-11-18 10:40:05
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : search for an enemy and attack
******************************************************************/
void PlaneHero::findAnEnemyAndAttack()
{
    //find an enemy and set the hero plane under the enemey{findAnEnemeyAndAttack}
    auto enemy = findAnEnemy();
    if (enemy)
    {
        setHeroPlaneUnderPosition(enemy->getPosition());
    }
}

/******************************************************************
Function    : void PlaneHero::clearScreenDebugInfo()
Date        : 2015-11-18 14:57:50
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : clear screen debug info
******************************************************************/
void PlaneHero::clearScreenDebugInfo()
{
    if (draw != nullptr)
    {
        draw->clear();
    }
}

/******************************************************************
Function    : void PlaneHero::enableShowScreenDebugInfo(bool value)
Date        : 2015-11-18 15:07:40
Author      : Quinn Pan
Parameter   :
Return      :
Desc        : enable to show debug info on screen
******************************************************************/
void PlaneHero::enableShowScreenDebugInfo(bool value)
{
    this->showDebugInfo = value;
}

/**
get first enemy in front of position
*/
cocos2d::Node* PlaneHero::getEnemyInFrontOfPosition(Point position)
{
    ////use Raycast to check if enemy in front of hero

    //Vec2 pointStart = position + Vec2(0, 60);
    //Vec2 pointEnd(position.x, Director::getInstance()->getVisibleSize().height);
    //Vec2 point3 = pointEnd;

    ////draw->drawLine(position, pointEnd, Color4F().ORANGE);
    //float friction = 1.0f;
    //PhysicsRayCastCallbackFunc func = [&point3, &friction](PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data)->bool
    //{
    //    if (friction > info.fraction)
    //    {
    //        point3 = info.contact;
    //        friction = info.fraction;
    //    }

    //    return true;
    //};
    //auto parent = this->getParent()->getParent();
    //auto scene = (Scene*)parent;
    //if (scene)
    //{
    //    scene->getPhysicsWorld()->rayCast(func, pointStart, pointEnd, nullptr);
    //    draw->drawSegment(pointStart, point3, 1, Color4F().BLUE);
    //    if (pointEnd != point3)
    //    {
    //        draw->drawDot(point3, 2, Color4F().RED);
    //    }
    //}

    //CCScene::getPhysicsWorld();
    //getPhysicsWorld()->rayCast(func, point1, point2, nullptr);

    auto children = this->getParent()->getChildren();
    //����һ����Ļ�߶ȣ�0.2��ľ��Σ�����һ��ֱ�߽�����ײ���.
    //λ�÷���(position.x-0.1,0)��
    Point placePoint = Point(position.x - 0.001f, 0);
    Rect detectRect = Rect(placePoint,
        Size(0.002f, CCDirector::getInstance()->getOpenGLView()->getFrameSize().height)
        );
    if (showDebugInfo)
    {
        draw->drawRect(placePoint, Size(0.002f, CCDirector::getInstance()->getOpenGLView()->getFrameSize().height), Color4F().GREEN);
    }
    for each (auto var in children)
    {
        if (var->getTag() == GameScene::ENEMY_TAG)
        {
            //��⵱ǰ����������ײ�����ǰ���Ƿ�������
            bool isInFront = var->getBoundingBox().intersectsRect(detectRect);
            if (isInFront){
                //set enemy in front of heroPlane yellow color
                var->setColor(Color3B(255, 255, 0));
                return var;
            }
        }
    }
    //if no enemy in front of position then return NULL 
    return NULL;
}

/**
*@desc: the dead method
*/
void PlaneHero::dead()
{
    getPhysicsBody()->setContactTestBitmask(0x0); ////������ײ��־λ�����ٷ�����ײ�¼�
    blowUp();
}

/**
*@desc: blowup hero plane
*/
void PlaneHero::blowUp()
{
    this->stopShooting();
    SimpleAudioEngine::getInstance()->playEffect("sound/hero_down.mp3");

    //������������
    auto animation = Animation::create();
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n1.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n2.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n3.png"));
    animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n4.png"));
    animation->setDelayPerUnit(0.2f);
    animation->setRestoreOriginalFrame(true);

    auto blowUp = Animate::create(animation);

    //��ը��������Ϸ
    auto gameoverCall = CallFunc::create([this]() {
        //log("call gameover!");
        removeFromParent();
        GameScene::sharedGameLayer()->gameover();
    });

    this->runAction(Sequence::create(blowUp, gameoverCall, nullptr));
}

/**
* begin shooting
* @param dt not used
*/
void PlaneHero::beginShooting(float dt)
{
    SimpleAudioEngine::getInstance()->playEffect("sound/shoot.wav");

    //log("a bullet shoot!");
    //����һ���ӵ������뵽GameLayer���ӵ���Ⱦ����
    auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");
    bullet->setPosition(Vec2(getPositionX(), getPositionY() + getContentSize().height / 2));
    auto bulletBox = GameScene::sharedGameLayer()->getBulletBox();

    bulletBox->addChild(bullet, 0, GameScene::HERO_BULLET_TAG);

    //���ӵ���һ��body����һ����ʼ�ٶȣ������䵽����������
    auto body = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0, 0, 0));
    body->setVelocity(Vect(0, 500));
    body->setContactTestBitmask(GameScene::ContactMaskBit::HERO_BULLET_CONTACTMASKBIT);
    body->setCollisionBitmask(0x0); //��������ײģ�⣬��Ϊ����Ҫ��

    bullet->setPhysicsBody(body);
}

/**
* @desc: remove bullet which out of scene
* @param: dt unused
*/
void PlaneHero::removeBullet(float dt)
{
    //����ÿһ���ӵ����ѳ����ɾ��
    auto bulletBox = GameScene::sharedGameLayer()->getBulletBox();
    auto vec = bulletBox->getChildren();
    for (auto &bullet : vec)
    {
        auto posInNode = bullet->getPosition();
        //����bullet����bulletBox��ģ������ϵ�����Ҫת������������ϵ����������ӵ���Ⱦ����ԭ�����Ǳ�Ҫ
        auto posInWorld = bulletBox->convertToWorldSpace(posInNode);
        if (posInWorld.y > Director::getInstance()->getVisibleSize().height)
        {
            bulletBox->removeChild(bullet, true);
            //log("a bullet remove!");
        }
    }
}

/**
* @desc stop shooting
*/
void PlaneHero::stopShooting()
{
    unschedule(schedule_selector(PlaneHero::beginShooting));
}
