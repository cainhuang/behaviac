#include "PlaneHero.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

bool PlaneHero::init()
{
	Sprite::init();
    //set ai action false
    m_isAI = false;
	//初始化纹理图
	initWithSpriteFrameName("hero2.png");

    draw = nullptr;

	return true;
}

void PlaneHero::onEnter()
{
	Sprite::onEnter();

    draw = DrawNode::create();
    this->getParent()->addChild(draw, 10);

	//进入后，开始发射子弹
	schedule(schedule_selector(PlaneHero::beginShooting), 0.5f);
	//检查子弹是否出界，出界则清除出bulletBox
	schedule(schedule_selector(PlaneHero::removeBullet), 0.1f);
    if (m_isAI){
        schedule(schedule_selector(PlaneHero::AIAction), 0.3f);
    }
}

/*
seek for an enemy
*/
Node* PlaneHero::findAnEnemy()
{
    auto children =this->getParent()->getChildren();
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
    //构建检测碰撞矩阵
    Rect detectRect = Rect(position - Vec2(width / 2, heroSize.height / 2), Size(width, heigth));

    //画出碰撞矩阵
    draw->drawRect(detectRect.origin, Vec2(detectRect.getMaxX(), detectRect.getMaxY()), Color4F().RED);

    //获得最近的敌人
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

/*adjust hero position*/
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
    if (enemy && enemy->getPosition().y>winHeight*0.4 && hero->getPosition().y<winHeight*0.1)
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
        //如果新位置将会发生碰撞，就不设置
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
    if (m_isAI){
        schedule(schedule_selector(PlaneHero::AIAction), 0.3f);
    }
    else{
        unschedule(schedule_selector(PlaneHero::AIAction));
    }
   

}

//AI 动作
/**
*   AI action ,let heroplane attack enemy automatic
*/
void PlaneHero::AIAction(float level){
    draw->clear();
    assert(this->getTag() == GameScene::HERO_TAG);
    //auto hero = (PlaneHero*)this->getParent()->getChildByTag(GameScene::HERO_TAG);
    auto hero = this;
    if (hero == NULL)
    {
        return;
    }
    //避免碰撞
    //先用一个略长于自己的矩形包围自己，然后检测碰撞，如果碰撞就移动。
    //最多加一个像素的宽度，如果宽度提高了，程序的效果会降低
    //构建一个碰撞矩形
    Size heroSize = hero->getBoundingBox().size;

    auto nearestEnemy = getNearestEnemy();
    if (nearestEnemy != NULL && isWillBeCrashEnemy(nearestEnemy))
    {
        auto enemyPosition = nearestEnemy->getPosition();
        auto heroPosition = hero->getPosition();

        //左右调整
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
        else //hero 和 enemy处于同一垂直的直线上
        {
            //如果敌人在前面来的，且有后路可以退
            if (heroPosition.y > 0 && enemyPosition.y > heroPosition.y)
            {
                heroPosition.y = heroPosition.y - 10;
                hero->setPosition(heroPosition);
            }
            else //重新查找新的位置
            {
                setHeroPlaneUnderPosition(heroPosition);
            }

        }
    }
    if (getEnemyInFrontOfPosition(hero->getPosition()) == NULL)
    {
        auto enemy = findAnEnemy();
        if (enemy)
        {
            setHeroPlaneUnderPosition(enemy->getPosition());
        }
    }
    //adjust plane's position
    AdjustHeroPosition();

}

/**
get first enemy in front of position
*/
cocos2d::Node* PlaneHero::getEnemyInFrontOfPosition(Point position)
{
    //use Raycast to check if enemy in front of hero

    Vec2 pointStart = position + Vec2(0, 60);
    Vec2 pointEnd(position.x, Director::getInstance()->getVisibleSize().height);
    Vec2 point3 = pointEnd;

    //draw->drawLine(position, pointEnd, Color4F().ORANGE);
    float friction = 1.0f;
    PhysicsRayCastCallbackFunc func = [&point3, &friction](PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data)->bool
    {
        if (friction > info.fraction)
        {
            point3 = info.contact;
            friction = info.fraction;
        }

        return true;
    };
    auto parent = this->getParent()->getParent();
    auto scene = (Scene*)parent;
    if (scene)
    {
        scene->getPhysicsWorld()->rayCast(func, pointStart, pointEnd, nullptr);
        draw->drawSegment(pointStart, point3, 1, Color4F().BLUE);
        if (pointEnd != point3)
        {
            draw->drawDot(point3, 2, Color4F().RED);
        }
    }

    //CCScene::getPhysicsWorld();
    //getPhysicsWorld()->rayCast(func, point1, point2, nullptr);

    auto children = this->getParent()->getChildren();
    //创建一个屏幕高度，0.2宽的矩形，当做一条直线进行碰撞检测.
    //位置放在(position.x-0.1,0)处
    Point placePoint = Point(position.x - 0.001f, 0);
    Rect detectRect = Rect(placePoint,
        Size(0.002f, CCDirector::getInstance()->getOpenGLView()->getFrameSize().height)
        );
    draw->drawRect(placePoint, Size(0.002f, CCDirector::getInstance()->getOpenGLView()->getFrameSize().height), Color4F().GREEN);
    for each (auto var in children)
    {
        if (var->getTag() == GameScene::ENEMY_TAG)
        {
            //检测当前物体会否发生碰撞来检测前面是否有物体
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
	getPhysicsBody()->setContactTestBitmask(0x0); ////设置碰撞标志位，不再发生碰撞事件
	blowUp();
}

/**
*@desc: blowup hero plane
*/
void PlaneHero::blowUp()
{
	this->stopShooting();
	SimpleAudioEngine::getInstance()->playEffect("sound/hero_down.mp3");

	//加载死亡动画
	auto animation = Animation::create();
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n1.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n2.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n3.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n4.png"));
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);

	auto blowUp = Animate::create(animation);
	
	//爆炸完后结束游戏
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
	//创建一颗子弹，加入到GameLayer的子弹渲染器中
	auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");
	bullet->setPosition(Vec2(getPositionX(), getPositionY() + getContentSize().height / 2));
	auto bulletBox = GameScene::sharedGameLayer()->getBulletBox();
	
	bulletBox->addChild(bullet, 0, GameScene::HERO_BULLET_TAG);

	//给子弹套一个body，加一个初始速度，让其射到物理世界中
	auto body = PhysicsBody::createBox(bullet->getContentSize(), PhysicsMaterial(0, 0, 0));
	body->setVelocity(Vect(0, 500)); 
	body->setContactTestBitmask(GameScene::ContactMaskBit::HERO_BULLET_CONTACTMASKBIT);
	body->setCollisionBitmask(0x0); //不进行碰撞模拟，因为不需要。

	bullet->setPhysicsBody(body);
}

/**
* @desc: remove bullet which out of scene
* @param: dt unused
*/
void PlaneHero::removeBullet(float dt)
{
	//遍历每一颗子弹，把出界的删除
	auto bulletBox = GameScene::sharedGameLayer()->getBulletBox();
	auto vec = bulletBox->getChildren();
	for (auto &bullet : vec)
	{
		auto posInNode = bullet->getPosition();
		//由于bullet处于bulletBox的模型坐标系，因此要转化成世界坐标系，不过如果子弹渲染器在原点则不是必要
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
