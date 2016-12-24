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
#include "Data\Enum\EnumPlayer.h"

//================================================
// 少年キャラクターパーツクラス工場
//	（AbstractFactory）
//
//	2016/12/22
//									Author Harada
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
//
//	2016/12/22
//									Author Harada
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
//
//	2016/12/22
//									Author Harada
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
	
	//実体の取得
	pPlayerBoy->m_pBody = factory.getBody();

	//衝突判定空間群の取得
	pPlayerBoy->m_pCollisionAreas = factory.getCollisionAreas();

	return pPlayerBoy;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
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
	
	/*
	//待機・ジャンプ。落下状態のアニメーションを設定（配列番号０）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::STAND]->addChipData(new CChip(0, 512, 256, 256));

	//左歩行状態のアニメーションを設定（配列番号１）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_LEFT]->addChipData(new CChip(0, 256, 256, 256));

	//右歩行状態のアニメーションを設定（配列番号２）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT]->addChipData(new CChip(0, 0, 256, 256));
	*/

	//開始時のアニメーションの状態
	pChara->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;

	//右待機・ジャンプ。落下状態のアニメーションを設定（配列番号０）
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_RIGHT]->addChipData(new CChip(1024, 768, 256, 256));

	//左待機 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_LEFT]->addChipData(new CChip(0, 768, 256, 256));

	//右歩行 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_RIGHT]->addChipData(new CChip(0, 256, 256, 256));

	//左歩行 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_LEFT]->addChipData(new CChip(0, 512, 256, 256));

	//装備する のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::EQUIP]->addChipData(new CChip(768, 0, 256, 256));

	//装備を外す のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::UN_EQUIP]->addChipData(new CChip(0, 0, 256, 256));

	//手を掴む右向き のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(512, 1024, 256, 256));

	//手を掴む左向き のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 1024, 256, 256));
}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//重力を設定
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//摩擦を設定
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.3f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){

	//ジャンプアクションの生成
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//ジャンプ中に行うアクションを生成して取りける
	pActionIdle->push_back(new CActionJump(3.0f,4.0f));
	//ジャンプアクションをマップ配列に取り付ける
	pChara->m_mapAction.insert(std::map<int, std::vector<CAction*>*>::value_type(0, pActionIdle));


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

	//キャラクター状態
	pChara->m_state = (int)CPlayerCharacterBoy::PLAYER_STATE::STAND;

	/*
	 *　計算データのままで起動すると1フレームずれが発生するので
	 *　初期化時に最後に値をSpriteに反映する
	 */
	pChara->applyFunc();

}


//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/22
//									Author Harada
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