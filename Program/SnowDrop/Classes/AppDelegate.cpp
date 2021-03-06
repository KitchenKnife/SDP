//==========================================
// ヘッダインクルード
//==========================================
#include "AppDelegate.h"
#include "Scene/GameMain/GameMain.h"
#include "Scene/Title/Title.h"
#include "Constants.h"
#include "cocos2d.h"
// サウンド用
#include "SimpleAudioEngine.h"
// サウンド用
#include "Lib/Sound/AudioManager.h"
//入力用
#include "Lib\Input\InputManager.h"
//計算用
#include "Lib\Math\CustomMath.h"

#include "Scene/GameMain2/GameMain2.h"
#include "Model/Map/Map.h"

//キャラクター集合体
#include "Model\Character\CharacterAggregate.h"

//プレイヤー工場
#include "Model/Character/Factory/PlayerFactory.h"

//少女工場
#include "Model/Character/Factory/GirlCharacterFactory.h"

//敵工場
#include "Model/Character/Factory/EnemyFactory.h"

#include "Model/Character/Factory/DamageFactory.h"

//エフェクト工場
#include "Model/Character/Factory/EffectFactory.h"

//ギミック工場
#include "Model/Character/Factory/GimmickFactory.h"

USING_NS_CC;

//デバイスの解像度を取得
Vec2 getScreenSize() {

	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);
	CCLOG("%d %d", rc.right, rc.bottom);
	Vec2 screenSize((int)(rc.right*1.25), (int)(rc.bottom*1.25-32));
	return screenSize;
}

//フルスクリーン 1080pに設定（1920,1080）
static cocos2d::Size designResolutionSize = cocos2d::Size(1920, 1080);
static cocos2d::Size smallResolutionSize = cocos2d::Size(640, 480);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1920, 1080);

AppDelegate::AppDelegate() {
	//getScreenSize();
}

AppDelegate::~AppDelegate() 
{

	//*************************************************************************
	//
	// ！！！！注意！！！！メモリの解放は、生成した逆順で解放すること！！！！！
	//
	//*************************************************************************


	// ダメージ工場の削除
	CDamageFactoryManager::removeInstance();

	//エフェクト工場の削除
	CEffectFactoryManager::removeInstance();


	//ギミック工場の削除
	CGimmickFactoryManager::removeInstance();

	//敵生成工場の削除
	CEnemyFactoryManager::removeInstance();

	//少女工場の削除
	CPlayerGirlFactoryManager::removeInstance();

	//プレイヤー工場の削除
	CPlayerBoyFactoryManager::removeInstance();

	// トリガー削除
	CLaunchScheduler::removeInstance();
	// キャラの削除
	CCharacterAggregate::removeInstance();

	// マップの削除
	CMapManager::removeInstance();

	//BGM停止
	CAudioManager::removeInstance();

	//入力の解放
	CInputManager::removeInstance();

	//計算の解放
	CCustomMath::removeInstance();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

#ifdef _DEBUG
		glview = GLViewImpl::createWithRect("SnowDrop", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		//glview = GLViewImpl::createWithFullScreen("SnowDrop");
		glview = GLViewImpl::createWithRect("SnowDrop", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#endif

#else
        glview = GLViewImpl::create("SnowDrop");
#endif
        director->setOpenGLView(glview);
    }


#ifdef _DEBUG
    // turn on display FPS
    director->setDisplayStats(true);
#else
	// turn off display FPS
	director->setDisplayStats(false);
#endif

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    Size frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    register_all_packages();

    // create a scene. it's an autorelease object
 	auto scene = CTitle::createScene();
	//auto scene = CGameMain::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();


	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();

}
