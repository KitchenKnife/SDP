/*
* PlayerFactory.cpp
*
*	2016/11/25	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "PlayerFactory.h"

//================================================
// 少年キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
//アニメーション群データの生成と取得
std::vector<CAnimation* >* CPlayerBoyPartsFactory::getAnimations() {
	//アニメーション群の作成
	return new std::vector<CAnimation*>();
}

//移動データの生成と取得
CMove* CPlayerBoyPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

//物理演算群データの生成と取得
std::vector<CPhysical* >* CPlayerBoyPartsFactory::getPhysicals() {
	//物理演算群作成
	return new std::vector<CPhysical*>();
}

//アクション群データの生成と取得
std::vector<CAction* >* CPlayerBoyPartsFactory::getActions() {
	//アクション群を作成
	return new std::vector<CAction*>();
}

//実体データの生成と取得
CBody* CPlayerBoyPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

//衝突判定空間群データの生成と取得
std::vector<CCollisionArea* >* CPlayerBoyPartsFactory::getCollisionAreas() {
	//衝突判定空間群の生成
	return new std::vector<CCollisionArea*>();
}

//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
//プレイヤーの生成と設定
CPlayerCharacterBoy* CPlayerBoyFactory::create() {

	//プレイヤーの生成と組み立て
	CPlayerCharacterBoy* pChara = this->createPlayer();

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

	//そのほか初期化
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//プレイヤーの生成と組み立て
CPlayerCharacterBoy* CPlayerBoyCreateFactory::createPlayer() {

	//少年キャラクターの生成
	CPlayerCharacterBoy* pPlayerBoy = CPlayerCharacterBoy::create();

	//少年キャラクターパーツ工場を生成
	CPlayerBoyPartsFactory  factory;

	//移動の取得
	pPlayerBoy->m_pMove = factory.getMove();

	//アニメーション群の取得
	pPlayerBoy->m_pAnimations = factory.getAnimations();
	
	//物理演算群の取得
	pPlayerBoy->m_pPhysicals = factory.getPhysicals();

	//アクション群の取得
	pPlayerBoy->m_pActions = factory.getActions();
	
	//実体の取得
	pPlayerBoy->m_pBody = factory.getBody();

	//衝突判定空間群の取得
	pPlayerBoy->m_pCollisionAreas = factory.getCollisionAreas();

	return pPlayerBoy;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================

//移動データの設定
void CBasePlayerBoyFactory::settingMove(CPlayerCharacterBoy* pChara){

	//初期位置の設定
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerBoyFactory::settingTexture(CPlayerCharacterBoy* pChara){
	//テクスチャの設定
	pChara->setTexture(IMAGE_PLAYER);
	
}

void CBasePlayerBoyFactory::settingAnimations(CPlayerCharacterBoy* pChara) {
	//待機・ジャンプ。落下状態のアニメーションを設定（配列番号０）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::STAND]->addChipData(new CChip(0, 512, 256, 256));

	//左歩行状態のアニメーションを設定（配列番号１）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_LEFT]->addChipData(new CChip(0, 256, 256, 256));

	//右歩行状態のアニメーションを設定（配列番号２）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT]->addChipData(new CChip(0, 0, 256, 256));

}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//重力を設定
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//摩擦を設定
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.3f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){
	pChara->m_pActions->push_back(new CActionJump(3.0f, 4.0f));

}

void CBasePlayerBoyFactory::settingBody(CPlayerCharacterBoy* pChara){

	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//衝突判定空間の設定
void CBasePlayerBoyFactory::settingCollisionArea(CPlayerCharacterBoy* pChara) {

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
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody , 64.0f , 128.0f);

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

void CBasePlayerBoyFactory::settingInitialize(CPlayerCharacterBoy* pChara){
	//状態の設定
	pChara->m_playerState = (int)CPlayerCharacterBoy::PLAYER_STATE::STAND;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//生死フラグを立てる
	pChara->m_isAlive = true;

	//大まかなタイプ別（キャラクタータイプ）
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_BOY;

	//細かなタイプ別（タグ）
	pChara->m_tag = TAG_PLAYER_1;

	/*
	 *　計算データのままで起動すると1フレームずれが発生するので
	 *　初期化時に最後に値をSpriteに反映する
	 */
	pChara->applyFunc();

}


//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//================================================
//共有のインスタンスの実体
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = NULL;

//インスタンスの取得
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::getInstance() {

	if (CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager == NULL) {
		CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = new CPlayerBoyFactoryManager();
	}

	return CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager;
}