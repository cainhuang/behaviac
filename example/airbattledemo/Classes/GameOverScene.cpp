#include "GameOverScene.h"
#include "GameScene.h"

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameOverScene::init()
{
	Layer::init();

	log("game over!");

	auto winSize = Director::getInstance()->getWinSize();

	//��ӱ���
	auto bg = Sprite::createWithSpriteFrameName("gameover.png");
	bg->setScaleX(winSize.width / bg->getContentSize().width);
	bg->setScaleY(winSize.height / bg->getContentSize().height);
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	addChild(bg);

	//������Ϸ��ť
	auto backlabel = Label::createWithTTF("Try again", "fonts/Marker Felt.ttf", 36);
	backlabel->setColor(Color3B::BLACK);
	auto backItem = MenuItemLabel::create(backlabel);
	backItem->setTarget(this, menu_selector(GameOverScene::onBackItemCallback));
	backItem->setPosition(Vec2(winSize.width / 2 - backItem->getContentSize().width / 2 - 15, -winSize.height / 2 + backItem->getContentSize().height / 2 + 10)); //λ�����½�
	auto menu = Menu::create(backItem, nullptr);
	addChild(menu);

	//��ʾ���η�����λ���м�
	auto score = UserDefault::getInstance()->getStringForKey("LastScore");

	auto labelscore = Label::createWithTTF(score, "fonts/Marker Felt.ttf", 36);
	labelscore->setColor(Color3B::BLACK);
	labelscore->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 50));
	addChild(labelscore);
	
	//��ʾ��ѷ�����λ������
	auto bestscore = UserDefault::getInstance()->getStringForKey("BestScore");

	auto labelbestscore = Label::createWithSystemFont(bestscore, "Arial", 36);
	labelbestscore->setColor(Color3B::BLACK);
	labelbestscore->setPosition(Vec2(labelbestscore->getContentSize().width / 2 + 50, winSize.height - labelbestscore->getContentSize().height / 2 - 80));
	addChild(labelbestscore);

	return true;
}

void GameOverScene::onBackItemCallback(Ref*)
{
	//������Ϸ
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}
