#include "hero.h"
#include "PlaneHero.h"
#include "GameScene.h"
USING_NS_CC;

BEGIN_PROPERTIES_DESCRIPTION(Hero)
{
    REGISTER_PROPERTY(m_isAI);

    //REGISTER_METHOD(findAnEnemy);
    //REGISTER_METHOD(isWillBeCrashEnemy).PARAM_DISPLAY_INFO(L"Enemy").PARAM_DISPLAY_INFO(L"position");
    //REGISTER_METHOD(getEnemyInFrontOfPosition).PARAM_DISPLAY_INFO(L"position");

    //REGISTER_METHOD(AdjustHeroPosition).PARAM_DISPLAY_INFO(L"hero");
    //REGISTER_METHOD(setHeroPlaneUnderPosition).PARAM_DISPLAY_INFO(L"_targetPosition");
    
}
END_PROPERTIES_DESCRIPTION()

Hero::Hero()
{
    m_plane = PlaneHero::create();
}

Hero::~Hero()
{

}

void  Hero::dead(){
    //·É»ú¹Òµô
}

Node* Hero::findAnEnemy()//find an enemy plane
{
    return m_plane->findAnEnemy();
}

bool  Hero::isWillBeCrashEnemy(Node* enemy, Point position)//test whether hero will be crash enemy at position
{
    return m_plane->isWillBeCrashEnemy(enemy, position);
}

Node* Hero::getEnemyInFrontOfPosition(Point position)// get Enemy in front of position
{
    return m_plane->getEnemyInFrontOfPosition(position);
}

Node* Hero::getNearestEnemy()//get the nearest enemy
{
    return m_plane->getNearestEnemy();
}

Node* Hero::getNearestEnemy(Point position)//get the nearest enemy 
{
    return m_plane->getNearestEnemy(position);
}

void  Hero::AdjustHeroPosition(Node* hero)
{
    return m_plane->AdjustHeroPosition(hero);
}

void  Hero::setHeroPlaneUnderPosition(Point targetPosition)
{
    return m_plane->setHeroPlaneUnderPosition(targetPosition);
}

void  Hero::setAI(bool value)
{
    return m_plane->setAI(value);
}

//AI action
void  Hero::AIAction(float level)
{
    return m_plane->AIAction(level);
}

PlaneHero* Hero::getPlane()
{
    //assert(this->m_plane->getTag() == GameScene::HERO_TAG);
    return m_plane;
}

void Hero::setPlane(PlaneHero* heroPlane)
{
    assert(heroPlane->getTag() == GameScene::HERO_TAG);
    this->m_plane = heroPlane;
}