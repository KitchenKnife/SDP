//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyFactory.h"
#include "../EnemyCharacter/EnemyCharacter.h"
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"
#include "Data/ActionController/EnemyActionController/EnemyActionPursuit/EnemyActionPursuit.h"
#include "Data/ActionController/EnemyActionController/EnemyActionAttack/EnemyActionAttack.h"



//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================

std::map<CEnemyCharacter::STATE, CAnimation*> CEnemeyPartsFactory::getAnimations() {
	//アニメーションデータ群の作成
	std::map<CEnemyCharacter::STATE, CAnimation*> pAnimations;

	return pAnimations;
}

CMove* CEnemeyPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}


std::vector<CPhysical* >* CEnemeyPartsFactory::getPhysicals() {
	//適用させる物理演算作成
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;

	return pPhysicals;
}


std::map<CEnemyCharacter::STATE, CAction*> CEnemeyPartsFactory::getActions(){
	//行えるアクション群を作成
	std::map<CEnemyCharacter::STATE, CAction*> pActions;

	return pActions;
}

CBody* CEnemeyPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

std::vector<CCollisionArea* >* CEnemeyPartsFactory::getCollisionAreas() {
	//	衝突判定空間の生成
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

CStatus* CEnemeyPartsFactory::getStatus() {
	// ステータスの作成
	return new CStatus();
}

//================================================
// メイデッド工場
//================================================
void CMaideadFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(posX,posY);
	// 初期速度
	pCharacter->m_pMove->m_vel.set(-1.0f, 0.0f);
}
void CMaideadFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_MEIDEAD);
}

void CMaideadFactory::settingAnimations(CEnemyCharacter* pCharacter) {


	//直立アニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY] = (new CChipNotAnimation());
	//さまようアニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING] = (new CChipAnimation(5, 2 ,true));
	//追跡アニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE] = (new CChipAnimation(5, 2, true));


	//直立アニメーションに設定する為のチップデータの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY]->addChipData(new CChip(0, 0, 64, 64));
	//さまようアニメーションのチップデータ設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(0, 0, 64, 64));
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(64, 0, 64, 64));
	//追跡アニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(0, 0, 64, 64));
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(64, 0, 64, 64));
	
	
}

void CMaideadFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

	// 歩行キャラには重力つける
	pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());

}

void CMaideadFactory::settingActions(CEnemyCharacter* pCharacter) {
	// 攻撃の設定
	
	//時間による待機アクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::STAY] = (new CEnemyActionStayAtTime(CEnemyAction::TARGET_TYPE::BOTH));
	//さまよいアクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::WANDERING] = (new CEnemyActionWondering(CEnemyAction::TARGET_TYPE::BOTH));
	//追跡アクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::CHASE] = (new CEnemyActionChase());
}

void CMaideadFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
	
}

//衝突判定空間の設定
void CMaideadFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

	//画面端衝突空間の生成
	//同時に画面端の衝突空間に衝突を行う下の基準点を設定
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);
	//画面端領域の生成
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//画面端領域と衝突した際のイベントコールバック設定
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//画面端の衝突判定空間に領域を設定
	//画面端の領域を設定
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap();
	//マップチップ領域と衝突した際のイベントコールバックを設定
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//下のマップチップ領域と衝突した際のイベントコールバックを設定
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//マップチップ衝突空間に領域を設定
	//マップチップ領域を設定
	pMapArea->addTerritory(pMapChipBottomTerritory);
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//基準点の設定
	for (int i = 1; i < 4; i++) {
		//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(32 - i *4 , -32)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(32 - i * 4, 32)));

		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32,32 - i *4)));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32,32 - i *4)));
	}

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CMaideadFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
	pCharacter->m_pStatus->setSpeed(2.0);
}


void CMaideadFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//状態の設定
	pCharacter->m_state = CEnemyCharacter::STATE::WANDERING;

	//プレイヤーを感知、追跡する範囲
	pCharacter->m_chaseRange = 360;

	//現在の優先攻撃対象(メイデッドは近い方)
	//pCharacter->m_currentTarget = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//攻撃範囲
	pCharacter->m_attackRange = 60;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;
	pCharacter->m_isAlive = true;
	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pCharacter->applyFunc();

}

//================================================
// コウモリ工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CBatFactory::settingMove(CEnemyCharacter* pCharacter,float x, float y) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(x, y);
	// 初期速度
	pCharacter->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CBatFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_BAT);

}

void CBatFactory::settingAnimations(CEnemyCharacter* pCharacter) {

	//直立アニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY] = (new CChipNotAnimation());
	//さまようアニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING] = (new CChipAnimation(7, 6, true));
	//追跡アニメーションの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE] = (new CChipAnimation(7, 6, true));


	//直立アニメーションに設定する為のチップデータの設定
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY]->addChipData(new CChip(64*0, 62.7*2, 64, 62.7));

	//さまようアニメーションのチップデータ設定
	for (int i = 0; i<6; i++) {
		pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(64 * i, 62.7 * 0, 64, 62.7));
	}
	//追跡アニメーションの設定
	for (int i = 0; i<6; i++) {
		pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(64 * i, 62.7 * 0, 64, 62.7));
	}

}

void CBatFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

}

void CBatFactory::settingActions(CEnemyCharacter* pCharacter) {
	// 攻撃の設定

	//待機アクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::STAY] = (new CEnemyActionStay(CEnemyAction::TARGET_TYPE::GIRL));
	//さまよいアクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::WANDERING] = (new CEnemyActionReturnLanchPos(CEnemyAction::TARGET_TYPE::GIRL, pCharacter));
	//追跡アクションの設定
	pCharacter->m_pActions[CEnemyCharacter::STATE::CHASE] = (new CEnemyActionChase(true));
}

void CBatFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
void CBatFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

	//画面端衝突空間の生成
	//同時に画面端の衝突空間に衝突を行う下の基準点を設定
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);
	//画面端領域の生成
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//画面端領域と衝突した際のイベントコールバック設定
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//画面端の衝突判定空間に領域を設定
	//画面端の領域を設定
	//pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//画面左端領域の生成と取り付け
	//pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap();
	//マップチップ領域と衝突した際のイベントコールバックを設定
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//下のマップチップ領域と衝突した際のイベントコールバックを設定
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//マップチップ衝突空間に領域を設定
	//マップチップ領域を設定
	//pMapArea->addTerritory(pMapChipBottomTerritory);
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//基準点の設定
	for (int i = 0; i < 9; i++) {
		//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(8 * i - (32), -32)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8 * i - (32), 32)));
	}

	for (int i = 0; i < 9; i++) {
		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 8 * i - (32))));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 8 * i - (132))));
	}

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CBatFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
	pCharacter->m_pStatus->setSpeed(1.8f);
}


void CBatFactory::settingInitialize(CEnemyCharacter* pCharacter) {

	//状態の設定
	pCharacter->m_state = CEnemyCharacter::STATE::STAY;

	//プレイヤーを感知、追跡する範囲
	pCharacter->m_chaseRange = 350;

	//現在の優先攻撃対象
	pCharacter->m_currentTarget = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//攻撃範囲
	pCharacter->m_attackRange = 70;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;
	pCharacter->m_isAlive = true;
	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pCharacter->applyFunc();

}

//================================================
// パーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CEnemyFactoryManager* CEnemyFactoryManager::m_pEnemyFactoryManager = NULL;

//インスタンスの取得
CEnemyFactoryManager* CEnemyFactoryManager::getInstance() {

	if (CEnemyFactoryManager::m_pEnemyFactoryManager == NULL) {
		CEnemyFactoryManager::m_pEnemyFactoryManager = new CEnemyFactoryManager();
	}

	return CEnemyFactoryManager::m_pEnemyFactoryManager;
}