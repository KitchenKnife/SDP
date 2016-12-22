//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "GimmickFactory.h"
#include "Model/Character/GimmickCharacter/GimmickCharacter.h"

//パーツ製造工場群
std::vector<CGimmickPartsFactory*>partsFactories{
	new CGimmickPartsFactory(),
};

//================================================
// ギミックパーツクラス工場
//	（AbstractFactory）
//================================================

std::vector<CAnimation* >* CGimmickPartsFactory::getAnimations() {
	//アニメーションデータ群の作成
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;

	return pAnimations;
}

CMove* CGimmickPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

std::vector<CPhysical* >* CGimmickPartsFactory::getPhysicals() {
	//適用させる物理演算作成
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;


	return pPhysicals;
}

std::vector<CAction* >* CGimmickPartsFactory::getActions() {
	//行えるアクション群を作成
	std::vector<CAction* >* pActions = new std::vector<CAction*>;

	return pActions;
}

CBody* CGimmickPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}


std::vector<CCollisionArea* >* CGimmickPartsFactory::getCollisionAreas() {
	//	衝突判定空間の生成
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}



//================================================
// ギミックの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//ギミックの生成と組み立て
CGimmickCharacter* CGimmickCreateFactory::createGimmick() {

	CGimmickCharacter* pGimmick = CGimmickCharacter::create();

	//移動用データの取得
	pGimmick->m_pMove = partsFactories[0]->getMove();
	//アニメーションデータ群の取得
	pGimmick->m_pAnimations = partsFactories[0]->getAnimations();
	//適用する物理演算群の取得
	pGimmick->m_pPhysicals = partsFactories[0]->getPhysicals();
	//アクション群の取得
	pGimmick->m_pActions = partsFactories[0]->getActions();
	//衝突判定用データの取得
	pGimmick->m_pBody = partsFactories[0]->getBody();
	//衝突判定空間群の取得
	pGimmick->m_pCollisionAreas = partsFactories[0]->getCollisionAreas();

	return pGimmick;
}

//================================================
// ダメージブロックのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CDamageBlockFactory::settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt) {

	//初期位置の設定
	pCharacter->m_pMove->m_pos.set(pt.x, pt.y);

	//初期位置の設定
	//pCharacter->m_pMove->m_vel.set(4.0f, 0.0f);
}
void CDamageBlockFactory::settingTexture(CGimmickCharacter* pCharacter) {
	//テクスチャの設定
	//pCharacter->setTexture(IMAGE_NORMAL_BULLET);

}

void CDamageBlockFactory::settingAnimations(CGimmickCharacter* pCharacter) {

	//直立アニメーションの設定
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pCharacter->m_pAnimations)[/*(int)CBulletCharacter::STATE::LAUNCHED*/0]->addChipData(new CChip(0, 0, 16, 16));

}

void CDamageBlockFactory::settingPhysicals(CGimmickCharacter* pCharacter) {
	//重力演算の設定
	//pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());
	//摩擦演算の設定
	//pCharacter->m_pPhysicals->push_back(new CPhysicalFriction(6.0f));
}

void CDamageBlockFactory::settingActions(CGimmickCharacter* pCharacter) {

	//pCharacter->m_pActions->push_back(new CActionMoveStraight(2.0f));
	//CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[0];

	//pAction->set(3.0f, 4);
}

void CDamageBlockFactory::settingBody(CGimmickCharacter* pCharacter) {

	pCharacter->m_pBody->set(-8.0f, 8.0f, 8.0f, -8.0f);
}

//衝突判定空間の設定
void CDamageBlockFactory::settingColllisionArea(CGimmickCharacter* pCharacter) {


	//画面　外　衝突空間の生成
	//同時に画面　外　の衝突空間に衝突を行う下の基準点を設定
	CCollisionArea* pOutOfScreenArea = new CCollsionAreaOutOfScreen(pCharacter->m_pBody);

	//画面左　外　領域の生成
	CCollisionTerritory* pEndOfScreenLeftTerritory = new CCollisionTerritoryOutOfScreenLeft();
	//画面左　外　領域と衝突した際のイベントコールバック設定
	pEndOfScreenLeftTerritory->setEventCallback(&CCharacter::collisionLeftCallback);

	//画面右　外　領域の生成
	CCollisionTerritory* pEndOfScreenRightTerritory = new CCollisionTerritoryOutOfScreenRight();
	//画面右　外　領域と衝突した際のイベントコールバック設定
	pEndOfScreenRightTerritory->setEventCallback(&CCharacter::collisionRightCallback);

	//画面端の衝突判定空間に領域を設定
	//画面左　外　領域を設定
	pOutOfScreenArea->addTerritory(pEndOfScreenLeftTerritory);
	//画面右　外　の領域を設定
	pOutOfScreenArea->addTerritory(pEndOfScreenRightTerritory);

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pOutOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap();

	//マップチップ衝突空間に領域を設定
	//マップチップ領域を設定
	CCollisionTerritory* pBottomMapTerritory = (new CCollisionTerritoryMapChipBottom);
	pBottomMapTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	CCollisionTerritory* pTopMapTerritory = (new CCollisionTerritoryMapChipTop);
	pTopMapTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	CCollisionTerritory* pRightMapTerritory = (new CCollisionTerritoryMapChipRight);
	pRightMapTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	CCollisionTerritory* pLeftMapTerritory = (new CCollisionTerritoryMapChipLeft);
	pLeftMapTerritory->setEventCallback(&CCharacter::collisionLeftCallback);

	pMapArea->addTerritory(pBottomMapTerritory);
	pMapArea->addTerritory(pTopMapTerritory);
	pMapArea->addTerritory(pRightMapTerritory);
	pMapArea->addTerritory(pLeftMapTerritory);

	//基準点の設定
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(4, -8)));
	//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-4, -8)));

	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(4, 8)));
	//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-4, 8)));

	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, 4)));
	//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, -4)));

	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, 4)));
	//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, -4)));

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);


}

void CDamageBlockFactory::settingInitialize(CGimmickCharacter* pCharacter) {

	//状態の設定
	//pCharacter->m_state = 0;

	//発射方向を設定
	//pCharacter->m_shotVector = vec;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pCharacter->applyFunc();

}

//================================================
// ギミックパーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CGimmickFactoryManager* CGimmickFactoryManager::m_pGimmickFactoryManager = NULL;


//インスタンスの取得
CGimmickFactoryManager* CGimmickFactoryManager::getInstance() {

	if (CGimmickFactoryManager::m_pGimmickFactoryManager == NULL) {
		CGimmickFactoryManager::m_pGimmickFactoryManager = new CGimmickFactoryManager;
	}
	return CGimmickFactoryManager::m_pGimmickFactoryManager;
}