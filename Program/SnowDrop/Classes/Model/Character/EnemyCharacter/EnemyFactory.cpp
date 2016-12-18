//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyFactory.h"
#include "EnemyCharacter.h"
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"



//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================

std::vector<CAnimation* >* CEnemeyPartsFactory::getAnimations() {
	//アニメーションデータ群の作成
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;

	//直立アニメーションの設定
	pAnimations->push_back(new CChipNotAnimation());
	//歩行アニメーションの設定
	pAnimations->push_back(new CChipListAnimation(10, true));
	//ダメージを受け時のアニメーション設定
	pAnimations->push_back(new CChipNotAnimation());
	//落ちているときのアニメーション
	pAnimations->push_back(new CChipNotAnimation());
	//打撃攻撃中のアニメーション
	pAnimations->push_back(new CChipListAnimation(60, false));

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
	std::vector<CAction* >* pActions = new std::vector<CAction*>;
	//ジャンプアクションの設定
	pActions->push_back(new CActionJump());
	//打撃攻撃アクションの設定
	pActions->push_back(new CActionBlowAttack());

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
// メイドの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
CEnemyCharacter* CMaideadCreateFactory::createEnemy() {

	//CCharacter* pEnemy = new CEnemyCharacter();
	CEnemyCharacter* pEnemy = CEnemyCharacter::create();

	//移動用データの取得
	pEnemy->m_pMove = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getMove();
	//アニメーションデータ群の取得
	pEnemy->m_pAnimations = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getAnimations();
	//適用する物理演算群の取得
	pEnemy->m_pPhysicals = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getPhysicals();
	//アクション群の取得
	pEnemy->m_pActions = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getActions();

	if (pEnemy->m_pActions == NULL) {
		CCLOG("");
	}

	//衝突判定用データの取得
	pEnemy->m_pBody = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getBody();
	//衝突判定の取得
	pEnemy->m_pCollisionAreas = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getCollisionAreas();
	//ステータスの取得
	pEnemy->m_pStatus = this->partsFactories[(int)ENEMY_RACE_TYPE::MAIDEAD]->getStatus();

	return pEnemy;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================

//各々のパーツのセッティング
void CBaseEnemyFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(posX,posY);

	// 初期速度の設定(左移動)
	pCharacter->m_pMove->m_vel.set(-1, 0);
}
void CBaseEnemyFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_ENEMY);

}

void CBaseEnemyFactory::settingAnimations(CEnemyCharacter* pCharacter) {

	//直立アニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 0, 64, 64));

	//歩行アニメーションに設定する1枚目のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::WALK]->addChipData(new CChip(0, 0, 64, 64));
	//歩行アニメーションに設定する2枚目のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::WALK]->addChipData(new CChip(64, 0, 64, 64));

	//ダメージを受けた時のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::HIT]->addChipData(new CChip(128, 0, 64, 64));

	//落ちている時のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::FALING]->addChipData(new CChip(128, 0, 64, 64));

	//打撃攻撃中のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::ATTACK]->addChipData(new CChip(128, 0, 64, 64));
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::ATTACK]->addChipData(new CChip(192, 0, 64, 64));

}

void CBaseEnemyFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

	// 歩行キャラには重力つける
	pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());

}

void CBaseEnemyFactory::settingActions(CEnemyCharacter* pCharacter) {

	// ｼﾞｬﾝﾌﾟ設定
	CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[(int)CEnemyCharacter::ACTION::JUMP];
	pAction->set(3.0f, 4);
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

void CBaseEnemyFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
}


void CBaseEnemyFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//状態の設定
	pCharacter->m_state = (int)CEnemyCharacter::STATE::FALING;

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
// 飛行キャラ生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//飛行キャラ生成と組み立て
CEnemyCharacter* CFlyCreateFactory::createEnemy() {

	CEnemyCharacter* pEnemy = CEnemyCharacter::create();

	//移動用データの取得
	pEnemy->m_pMove = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getMove();
	//アニメーションデータ群の取得
	pEnemy->m_pAnimations = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getAnimations();
	//適用する物理演算群の取得
	pEnemy->m_pPhysicals = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getPhysicals();
	//アクション群の取得
	pEnemy->m_pActions = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getActions();
	//衝突判定用データの取得
	pEnemy->m_pBody = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getBody();
		
	//ステータスの取得
	pEnemy->m_pStatus = this->partsFactories[(int)ENEMY_RACE_TYPE::BAT]->getStatus();


	return pEnemy;

}

//================================================
// 飛行キャラのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CFlyFactory::settingMove(CEnemyCharacter* pCharacter,float x, float y) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(x, y);

	// 初期速度の設定
	pCharacter->m_pMove->m_vel.set(-10.0f, 0.0f);

}
void CFlyFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_ENEMY);

}

void CFlyFactory::settingAnimations(CEnemyCharacter* pCharacter) {

	//直立アニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 64, 64, 64));

	//歩行アニメーションに設定する1枚目のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::WALK]->addChipData(new CChip(0, 64, 64, 64));
	//歩行アニメーションに設定する2枚目のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::WALK]->addChipData(new CChip(64, 64, 64, 64));

	//ダメージを受けた時のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::HIT]->addChipData(new CChip(128, 64, 64, 64));

	//落ちている時のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::FALING]->addChipData(new CChip(192, 64, 64, 64));

	//打撃攻撃中のアニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::ATTACK]->addChipData(new CChip(128, 64, 64, 64));
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::ATTACK]->addChipData(new CChip(192, 64, 64, 64));

}

void CFlyFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

}

void CFlyFactory::settingActions(CEnemyCharacter* pCharacter) {
	// ｼﾞｬﾝﾌﾟ設定
	CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[(int)CEnemyCharacter::ACTION::JUMP];
	pAction->set(3.0f, 4);

}

void CFlyFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
void CFlyFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

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

void CFlyFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
}


void CFlyFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//状態の設定
	pCharacter->m_state = (int)CEnemyCharacter::STATE::STAND;

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