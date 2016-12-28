#include "GirlCharacterFactory.h"

/*
* PlayerFactory.cpp
*
*	2016/11/25	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "GirlCharacterFactory.h"
#include "Data\StateMachine\Girl\GirlState.h"
#include "Data\Enum\EnumGirl.h"

//=====================================================
// 少年キャラクターパーツクラス工場
//	（AbstractFactory）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//アニメーション群データの生成と取得
std::vector<CAnimation* >* CPlayerGirlPartsFactory::getAnimations() {
	//アニメーション群の作成
	return new std::vector<CAnimation*>();
}

//移動データの生成と取得
CMove* CPlayerGirlPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

//物理演算群データの生成と取得
std::vector<CPhysical* >* CPlayerGirlPartsFactory::getPhysicals() {
	//物理演算群作成
	return new std::vector<CPhysical*>();
}

//実体データの生成と取得
CBody* CPlayerGirlPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

//衝突判定空間群データの生成と取得
std::vector<CCollisionArea* >* CPlayerGirlPartsFactory::getCollisionAreas() {
	//衝突判定空間群の生成
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc 状態遷移データの生成と取得
*	@return 状態遷移データ
*	@author Shinya Ueba
*/
CStateMachine*	CPlayerGirlPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}



//=====================================================
// 女の子の生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//プレイヤーの生成と設定
CPlayerCharacterGirl* CPlayerGirlFactory::create() {

	//プレイヤーの生成と組み立て
	CPlayerCharacterGirl* pChara = this->createPlayer();

	//移動データの設定
	this->settingMove(pChara);
	//テクスチャの設定
	this->settingTexture(pChara);
	//アニメーション群データの設定
	this->settingAnimations(pChara);
	//物理演算群データの設定
	this->settingPhysicals(pChara);
	//アクション群データの設定
	this->settingActions(pChara);
	//実体データの設定
	this->settingBody(pChara);
	//衝突判定空間群データの設定
	this->settingCollisionArea(pChara);
	//状態遷移データの設定
	this->settingStateMachine(pChara);
	//そのほか初期化
	this->settingInitialize(pChara);


	return pChara;
}



//=====================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//プレイヤーの生成と組み立て
CPlayerCharacterGirl* CPlayerGirlCreateFactory::createPlayer() {

	//少年キャラクターの生成
	CPlayerCharacterGirl* pPlayerGirl = CPlayerCharacterGirl::create();

	//少年キャラクターパーツ工場を生成
	CPlayerGirlPartsFactory  factory;

	//移動の取得
	pPlayerGirl->m_pMove = factory.getMove();

	//アニメーション群の取得
	pPlayerGirl->m_pAnimations = factory.getAnimations();

	//物理演算群の取得
	pPlayerGirl->m_pPhysicals = factory.getPhysicals();


	//実体の取得
	pPlayerGirl->m_pBody = factory.getBody();

	//衝突判定空間群の取得
	pPlayerGirl->m_pCollisionAreas = factory.getCollisionAreas();

	//状態遷移データの取得
	pPlayerGirl->m_pStateMachine = factory.getStateMachine();


	return pPlayerGirl;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//================================================

//移動データの設定
void CBasePlayerGirlFactory::settingMove(CPlayerCharacterGirl* pChara) {

	//初期位置の設定
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerGirlFactory::settingTexture(CPlayerCharacterGirl* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_PLAYER_GIRL);

}

void CBasePlayerGirlFactory::settingAnimations(CPlayerCharacterGirl* pChara) {

	
	//開始時のアニメーションの状態
	pChara->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;


	//右向き待機状態のアニメーションを設定（配列番号０）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::IDLE_RIGHT]->addChipData(new CChip(0, 768, 256, 256));

	//左向き待機状態のアニメーションを設定（配列番号1）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::IDLE_LEFT]->addChipData(new CChip(0, 512, 256, 256));

	//右向き歩行状態のアニメーションを設定（配列番号2）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::WALK_RIGHT]->addChipData(new CChip(0, 256, 256, 256));

	//左向き歩行状態状態のアニメーションを設定（配列番号3）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::WALK_LEFT]->addChipData(new CChip(0, 0, 256, 256));

	//右向き待機状態のアニメーションを設定（配列番号4）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false,2));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(512, 1536, 256, 256));

	//左向き待機状態のアニメーションを設定（配列番号5）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 1536, 256, 256));
	

}

void CBasePlayerGirlFactory::settingPhysicals(CPlayerCharacterGirl* pChara) {
	//重力を設定
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//摩擦を設定
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.3f));
}

void CBasePlayerGirlFactory::settingActions(CPlayerCharacterGirl* pChara) {
	

}

void CBasePlayerGirlFactory::settingBody(CPlayerCharacterGirl* pChara) {

	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//衝突判定空間の設定
void CBasePlayerGirlFactory::settingCollisionArea(CPlayerCharacterGirl* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面端領域の生成
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//画面端領域と衝突した際のイベントコールバック設定
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//画面下端領域を取り付け
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

	//マップチップ下領域の生成
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ下領域と衝突した際のイベントコールバックを設定
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//マップチップ下領域を取り付け
	pMapArea->addTerritory(pMapChipBottomTerritory);
	//マップチップ上領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//マップチップ右領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//マップチップ左領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());


	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pMapArea);

}

/**
*	@desc 状態遷移データの設定
*	@param 設定するキャラクター
*	@author Shinya Ueba
*/
void CBasePlayerGirlFactory::settingStateMachine(CPlayerCharacterGirl* pChara)
{
	//必要な状態を作成していく

//---------------------------------------------------------------------------------------------------------------------
//
// 待機状態
//
//---------------------------------------------------------------------------------------------------------------------
	//右向き
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::IDLE_RIGHT, new CGirlIdleRightState(pChara));
	//左向き
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::IDLE_LEFT, new CGirlIdleLeftState(pChara));

//---------------------------------------------------------------------------------------------------------------------
//
// 歩行状態
//
//---------------------------------------------------------------------------------------------------------------------
	//右向き
	//pChara->m_pStateMachine->registerState((int)GIRL_STATE::WALK_RIGHT, new CGirlIdleRightState(pChara));
	//左向き
	//pChara->m_pStateMachine->registerState((int)GIRL_STATE::WALK_LEFT, new CGirlIdleLeftState(pChara));


//---------------------------------------------------------------------------------------------------------------------
//
// 手を繋ぐ状態
//
//---------------------------------------------------------------------------------------------------------------------
	//右向き
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::GRASP_RIGHT, new CGirlGraspRightState(pChara));
	//左向き
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::GRASP_LEFT, new CGirlGraspLeftState(pChara));

	

	//最後に最初の状態を設定する！！！！！
	pChara->m_state = (int)GIRL_STATE::IDLE_LEFT;
	pChara->m_pStateMachine->setStartState(pChara->m_state);
}


void CBasePlayerGirlFactory::settingInitialize(CPlayerCharacterGirl* pChara) {
	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//生死フラグを立てる
	pChara->m_isAlive = true;

	//大まかなタイプ別（キャラクタータイプ）
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_GIRL;

	//細かなタイプ別（タグ）
	pChara->m_tag = TAG_PLAYER_2;

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pChara->applyFunc();

}

//================================================
// 少女キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/22
//									Author Harada
//================================================
//共有のインスタンスの実体
CPlayerGirlFactoryManager* CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager = NULL;

//インスタンスの取得
CPlayerGirlFactoryManager* CPlayerGirlFactoryManager::getInstance() {

	if (CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager == NULL) {
		CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager = new CPlayerGirlFactoryManager();
	}

	return CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager;
}

//インスタンスの破棄
void CPlayerGirlFactoryManager::removeInstance() {
	if (CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager != NULL) {
		//共有インスタンスの削除
		SAFE_DELETE(CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager);
	}
}
	