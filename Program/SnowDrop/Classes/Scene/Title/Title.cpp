//==========================================
//
// File: Title.cpp
//
// タイトルシーンファイル
//
// 2016/12/21
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"Title.h"
#include"Constants.h"
#include "Scene\GameMain\GameMain.h"
#include "Lib/Sound/AudioManager.h"
using namespace experimental;

/*
* @desc コンストラクタ
*/
CTitle::CTitle()
{

}

/*
* @desc デストラクタ
*/
CTitle::~CTitle()
{

}

/**
* @desc 初期化
* @return true...成功 false...失敗
*/
bool CTitle::init()
{
	//基底レイヤーの初期化
	if (Layer::init() == false)
	{
		return false;
	}

	//update関数(更新処理関数)呼び出し設定
	this->scheduleUpdate();

	//タイトル背景の生成と取り付け
	cocos2d::Sprite* pointerBackGround = cocos2d::Sprite::create(IMAGE_TITLE);
	//初期位置の設定
	pointerBackGround->setPosition(810.0f, 540.0f);
	//拡縮サイズを設定
	pointerBackGround->setScale(0.5,0.5);
	
	//レイヤーに取り付け
	this->addChild(pointerBackGround);

	/*
	* @desc		メニューアイテムの生成　ゲーム開始ボタン
	* @param	通常の画像を設定
	* @param	押された時の画像を設定
	* @param	押された時に呼び出されるメンバ関数の設定
	*/
	cocos2d::MenuItemImage* pointerStartBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_START,
		IMAGE_TITLE_BUTTON_START,
		CC_CALLBACK_1(CTitle::callbackChangeGameMain, this)
	);

	//位置設定
	pointerStartBtnItem->setPosition(WINDOW_RIGHT*0.5f, WINDOW_TOP*0.4f);
	
	
	/*
	* @desc		メニューアイテムの生成　ゲーム終了ボタン
	* @param	通常の画像を設定
	* @param	押された時の画像を設定
	* @param	押された時に呼び出されるメンバ関数の設定
	*/
	cocos2d::MenuItemImage* pointerEndBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_END,
		IMAGE_TITLE_BUTTON_END,
		CC_CALLBACK_1(CTitle::callbackEndGame, this)
	);

	//位置設定
	pointerEndBtnItem->setPosition(WINDOW_RIGHT*0.5f, WINDOW_TOP*0.2f);


	//メニューの生成とメニューアイテムの登録
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerStartBtnItem, pointerEndBtnItem, NULL);

	//位置の初期化
	pointerMenu->setPosition(0.0f, 0.0f);
	//レイヤーにメニューを登録する
	this->addChild(pointerMenu);


	// タイトルBGMの再生
	int musicID = AudioEngine::play2d(SOUND_FILE_BGM_TITLE, true,0.0f);
	// ID設定
	CAudioManager::getInstance()->setMusicID("TitleBGM", musicID);
	
	
	return true;
}
/**
* @desc		シーンの生成
* @return	CTitleレイヤーを内包したシーンクラスインスタンス
* @tips		静的メンバ関数
*/
cocos2d::Scene* CTitle::createScene()
{
	//シーンの生成
	cocos2d::Scene* pScene = cocos2d::Scene::create();

	//CTitleレイヤーの生成
	CTitle* pLayer = CTitle::create();

	//CTitleレイヤーをシーンに取り付ける
	pScene->addChild(pLayer);

	//生成したシーンを返す
	return pScene;
}

/**
* @desc  更新処理
* @param 経過時間
*/
void CTitle::update(float deltaTime)
{
	//==============================================================================
	//
	// ここに更新処理のコードを追加していく
	//
	//==============================================================================
	CAudioManager::getInstance()->fadeIn("Title");



}

/**
* @desc		ゲームメインに遷移
* @param	タイトルレイヤーのインスタンス
* @tips		スタートボタンが押された時に呼び出される
*/
void CTitle::callbackChangeGameMain(cocos2d::Ref* pSender)
{
	// 効果音再生
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON);
	//BGM停止
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID("Title"));

	// 効果音再生終了後
	AudioEngine::setFinishCallback(musicID, [](int musicID,const std::string) {
		

		//シーンを生成する
		cocos2d::Scene* pScene = CGameMain::createScene();
		//シーンを切り替える
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}

/*
* @desc　ゲーム終了
* @param タイトルレイヤーのインスタンス
* @tips	 ゲーム終了ボタンが押された時に呼び出される
*/
void CTitle::callbackEndGame(cocos2d::Ref* pSender)
{
	cocos2d::Director::getInstance()->end();
}







//EOF