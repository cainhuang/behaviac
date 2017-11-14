#include "AppDelegate.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::createWithRect("AirBattleDemo", Rect(0, 0, 540, 960)); //����PC�˵��豸�ֱ��ʣ������������ƶ������д�����Ч��
        director->setOpenGLView(glview);
    }

	glview->setDesignResolutionSize(540, 960, ResolutionPolicy::SHOW_ALL); //������Ϸ�ֱ��ʣ���δ�����ƶ��豸��Ļ��

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

    auto scene = GameScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
