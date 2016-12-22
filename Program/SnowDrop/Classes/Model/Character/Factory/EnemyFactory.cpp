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

std::vector<CAnimation* >* CEnemeyPartsFactory::getAnimations() {
	//アニメーションデータ群の作成
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;

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


std::vector<CAction* >* CEnemeyPartsFactory::getActions() {
	//行えるアクション群を作成
	std::vector<CAction* >* pActions = new std::vector<CAction*>();

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


//================================================
// メイド工場
//================================================
void CBaseEnemyFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(posX,posY);
	// 初期速度
	pCharacter->m_pMove->m_vel.set(-1.0f, 0.0f);

}
void CBaseEnemyFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_ENEMY);

}

void CBaseEnemyFactory::settingAnimations(CEnemyCharacter* pCharacter) {


	//直立アニメーションの設定
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 0, 64, 64));

}

void CBaseEnemyFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

	// 歩行キャラには重力つける
	pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());

}

void CBaseEnemyFactory::settingActions(CEnemyCharacter* pCharacter) {

}

void CBaseEnemyFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
void CBaseEnemyFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

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
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(64 - i * 16 , -32)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(64 - i * 16, 32)));

		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32,64 - i * 16)));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32,64 - i * 16)));
	}

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}



void CBaseEnemyFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//状態の設定
	//pCharacter->m_state = (int)CEnemyCharacter::STATE::FALING;

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
// 飛行キャラのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CBatFactory::settingMove(CEnemyCharacter* pCharacter,float x, float y) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(x, y);

}
void CBatFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_BAT);

}

void CBatFactory::settingAnimations(CEnemyCharacter* pCharacter) {

	//直立アニメーションの設定
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 64, 64, 64));

}

void CBatFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

}

void CBatFactory::settingActions(CEnemyCharacter* pCharacter) {
	


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



void CBatFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//状態の設定
	//pCharacter->m_state = (int)CEnemyCharacter::STATE::STAND;

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