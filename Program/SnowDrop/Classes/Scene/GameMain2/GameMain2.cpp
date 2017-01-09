/*
* GameMain.cpp
*
*	2016/11/10	Osumi
*
*/

#include "Scene/GameMain/GameMain.h"
#include "GameMain2.h"
#include "Model/Map/Map.h"

//キャラクター集合体
#include "Model\Character\CharacterAggregate.h"

//プレイヤー工場
#include "Model/Character/Factory/PlayerFactory.h"

//少女工場
#include "Model/Character/Factory/GirlCharacterFactory.h"

//敵工場
#include "Model/Character/Factory/EnemyFactory.h"

//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
// Deback

#include "Model/Character/Factory/DamageFactory.h"
#include "Data/LaunchData/LaunchData.h"

//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

//エフェクト工場
#include "Model/Character/Factory/EffectFactory.h"

//ギミック工場
#include "Model/Character/Factory/GimmickFactory.h"

//プレイヤーの武器アクション

// 入力
#include "Lib/Input/InputManager.h"
// 乱数生成用
#include <stdlib.h>
#include <time.h>
// サウンド用
#include "Lib/Sound/AudioManager.h"

// ゲームオーバーシーン
#include "Scene/GameOver/GameOver.h"
//==================================================
// 　静的メンバ変数の実体
//==================================================

/**
*	@desc	シーンの生成
*	@return	CMain レイヤーを内包したシーンクラスインスタンス
*	@tips	静的メンバ関数
*/
cocos2d::Scene* CGameMain2::createScene() {

	// シーンの生成
	cocos2d::Scene* pScene = cocos2d::Scene::create();

	// GameMain レイヤーの生成
	CGameMain2* pLayer = CGameMain2::create();

	// CMain レイヤーをシーンに取り付ける
	pScene->addChild(pLayer, 0, TAG_GAME_MAIN);

	// 生成したシーンを返す
	return pScene;
}

/**
*	@desc	キーボードのキーを押した際のイベント
*	@param	キーコード
*	@param	イベント
*/
void CGameMain2::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyPressed(keyCode);
}

/**
*	@desc	キーボードのキーを離した際のイベント
*	@param	キーコード
*	@param	イベント
*/
void CGameMain2::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {

	// 入力管理に入力処理を委託
	CInputManager::getInstance()->onKeyReleased(keyCode);
}

// デストラクタ
CGameMain2::~CGameMain2() {

	//出撃スケジュールの削除
	if (this->m_pLaunchSchedule)
	{
		for (CLaunchTrigger* pTrigger : (*this->m_pLaunchSchedule))
		{
			SAFE_DELETE(pTrigger);
		}
	}
	//出撃スケジュールの破棄
	SAFE_DELETE(this->m_pLaunchSchedule);

	
	SAFE_DELETE(this->m_pCharacters);
}


/**
*	@desc	初期化
*	@return	true...成功	false...失敗
*/
bool CGameMain2::init() {

	// 親レイヤーの初期化
	if (CCLayerColor::initWithColor(ccc4(51, 75, 112, 255)) == false) {
		return false;
	}

	// 乱数生成
	srand((unsigned int)time(NULL));

	// キーボード入力イベント受け取り設定
	this->setKeyboardEnabled(true);

	// update 関数 ( 更新処理関数 ) 呼び出し設定
	// この部分を消したりコメントアウトすると update 関数が呼ばれなくなるので注意
	this->scheduleUpdate();

	//=========================================================================
	//
	//	ここから初期化、初期設定のコードを追加
	//
	//=========================================================================

	////キャラクターの集まりの生成
	this->m_pCharacters = new std::vector<CCharacter*>();
	//キャラクターの集まりをCCharacterAggregateに設定する
	CCharacterAggregate::getInstance()->change(this->m_pCharacters);

	//出撃スケジュールの生成
	this->m_pLaunchSchedule = new std::vector<CLaunchTrigger*>();
	//出撃スケジュールを出撃スケジューラに取り付ける
	CLaunchScheduler::getInstance()->changeLauncher(this->m_pLaunchSchedule);

	////メインレイヤーの生成と取り付け
	this->m_pMainLayer = LayerColor::create(ccc4(51, 75, 112, 255));
	this->addChild(this->m_pMainLayer);

	////UIレイヤーの生成と取り付け
	this->m_pUILayer = LayerColor::create();
	this->addChild(this->m_pUILayer, -1);

	
	//背景画像の生成と取り付け
	this->m_pBackGround = Sprite::create();
	this->m_pBackGround->setTexture(IMAGE_BACK_STAGE2_BACKGROUND);
	this->m_pBackGround->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pBackGround);

	//部屋画像の生成と取り付け
	this->m_pRoom = Sprite::create();
	this->m_pRoom->setTexture(IMAGE_BACK_STAGE2_ROOM);
	this->m_pRoom->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pRoom);

	//部屋マップの生成と取り付け
	CMap* pMap = CMapManager::getInstance()->changeMap(MAP_DATA_SAMPLE);
	pMap->setVisible(false);
	this->m_pMainLayer->addChild(pMap);


	//UI画像の生成と取り付け
	this->m_pUI = Sprite::create();
	this->m_pUI->setTexture(IMAGE_BACK_STAGE2_FRONT);
	this->m_pUI->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pUI);



	// プレイヤーの生成
	CPlayerCharacterBoy* pPlayerChara = CPlayerBoyFactoryManager::getInstance()->create((int)PLAYER_TYPE::BASE);
	////CCharacterAggregateにプレイヤーを追加
	CCharacterAggregate::getInstance()->add(pPlayerChara);
	//参照先として登録
	CCharacterAggregate::getInstance()->setPlayer(pPlayerChara);
	////取り付け
	this->m_pMainLayer->addChild(pPlayerChara);


	//// 少女の生成と取り付け
	CPlayerCharacterGirl* playerGirl = CPlayerGirlFactoryManager::getInstance()->create((int)GIRL_TYPE::BASE);
	//CCharacterAggregateにプレイヤーを追加
	CCharacterAggregate::getInstance()->add(playerGirl);
	//参照先として登録
	CCharacterAggregate::getInstance()->setGirl(playerGirl);
	playerGirl->m_pMove->m_pos.set(1200, 500);

	//取り付け
	this->m_pMainLayer->addChild(playerGirl);


	////初期画面にいる敵の生成
	CMapManager::getInstance()->getMap()->initCheckEnemyLaunch();
	////全体の拡大
	//this->setScale(SCALE_MAIN);
	////拡大に伴う画面位置の設定
	//this->setPosition((SCREEN_WIDTH*(SCALE_MAIN-1))/2, (SCREEN_HEIGHT*(SCALE_MAIN-1))/2);


	//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
	// ↓↓　デバック用　リリース時消します
	//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
	/*
	* @desc		メニューアイテムの生成　ゲーム開始ボタン
	* @param	通常の画像を設定
	* @param	押された時の画像を設定
	* @param	押された時に呼び出されるメンバ関数の設定
	*/
	cocos2d::MenuItemImage* pointerStartBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_END,
		IMAGE_TITLE_BUTTON_END,
		CC_CALLBACK_1(CGameMain2::callbackChangeGameOver, this)
	);

	//位置設定
	pointerStartBtnItem->setPosition(WINDOW_RIGHT*0.9f, WINDOW_TOP*0.1f);


	//メニューの生成とメニューアイテムの登録
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerStartBtnItem, NULL);

	//位置の初期化
	pointerMenu->setPosition(0.0f, 0.0f);
	//レイヤーにメニューを登録する
	this->addChild(pointerMenu);

	//GLProgramState* pGl = GLProgramState::getOrCreateWithGLProgram();
	this->m_pMainLayer->runAction(CCTintTo::create(1.0, 255, 0, 0));


	//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
	// デバック用↑↑　消します
	//￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣



	// BGMの再生
	int musicID = AudioEngine::play2d(SOUND_FILE_BGM_STAGE_FIRST, true, 0.0f);
	// ID設定
	CAudioManager::getInstance()->setMusicID(BGM_STAGE1, musicID);


	//=========================================================================
	//
	//	ここまでに初期化、初期設定のコードを追加
	//
	//=========================================================================

	return true;

}


/*
* @desc 画面スクロール
* @tips 今回は強制スクロールではなくキャラクターの移動による画面のスクロールとなる
*/
void CGameMain2::scroll() {

	//マップの位置を取得
	Point pt = this->m_pMainLayer->getPosition();

	//プレイヤーキャラクターの取得
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);


	//プレイヤーの位置が320.0ｆを超えたら
	if (pt.x > WINDOW_RIGHT * 3 / 5 - pPlayerChara->m_pMove->m_pos.x) {
		//原点を超えた分に設定する
		pt.x = WINDOW_RIGHT * 3 / 5 - pPlayerChara->m_pMove->m_pos.x;
	}

	if (pt.x < WINDOW_RIGHT * 1 / 3 - pPlayerChara->m_pMove->m_pos.x) {
		//原点を超えた分に設定する
		pt.x = WINDOW_RIGHT * 1 / 3 - pPlayerChara->m_pMove->m_pos.x;
	}


	//超えた分を設定する
	this->m_pMainLayer->setPosition(pt);

	//スクロールが行われたときに敵の出撃判定を行う
	CMapManager::getInstance()->getMap()->checkEnemyLaunch(this->m_pMainLayer->getPosition());

}



/**
*	@desc	更新処理
*	@param	１フレーム経過時間
*/
void CGameMain2::update(float deltaTime_) {

	//入力状態の更新処理
	CInputManager::getInstance()->update();

	// esc キーを押したらゲーム終了
	if (CInputManager::getInstance()->getInputController()->getGameExitFlag())
	{
		cocos2d::Director::getInstance()->end();
	}


	//=========================================================================
	//
	//	ここから更新処理のコードを追加
	//
	//=========================================================================
	//=========================================================================
	// サウンド フェードイン
	//=========================================================================
	CAudioManager::getInstance()->fadeIn(BGM_STAGE1);

	//=========================================================================
	//	出撃スケジューラの起動
	//=========================================================================
	//キャラクターを出現させる
	CLaunchScheduler::getInstance()->launchCharacter(this->m_pMainLayer);
	//出撃完了したトリガーを全て取り外す
	this->checkAndDelete(this->m_pLaunchSchedule);


	//=========================================================================
	//	衝突判定処理に関するコードの追加はここから
	//=========================================================================


	//=========================================================================
	//	画面のスクロール
	//=========================================================================
	this->scroll();

	//=========================================================================
	//	取り外しに関するコードの追加はここから
	//=========================================================================
	this->checkAndRemove(this->m_pCharacters);

	//=========================================================================
	//
	//	ここまでに更新処理のコードを追加
	//
	//=========================================================================
}





/**
* @desc		ゲームメインに遷移
* @param	タイトルレイヤーのインスタンス
* @tips		スタートボタンが押された時に呼び出される
*/
void CGameMain2::callbackChangeGameOver(cocos2d::Ref* pSender)
{
	// 効果音再生
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON);
	//BGM停止
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID(BGM_STAGE1));

	// 効果音再生終了後
	AudioEngine::setFinishCallback(musicID, [](int musicID, const std::string) {

		//シーンを生成する
		cocos2d::Scene* pScene = CGameOver::createScene();
		//シーンを切り替える
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}
