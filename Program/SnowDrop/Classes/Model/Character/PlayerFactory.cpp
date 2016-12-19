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
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/Collision/CollisionArea.h"

//#include "PlayerCharacter.h"

//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
/*
std::vector<CAnimation* >* CPlayerPartsFactory::getAnimations() {
	//アニメーションデータ群の作成
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;


	return pAnimations;
}
*/

CMove* CPlayerPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

std::vector<CPhysical* >* CPlayerPartsFactory::getPhysicals() {
	//適用させる物理演算作成
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;
	//重力演算の設定
	pPhysicals->push_back(new CPhysicalGravity());
	//摩擦演算の設定
	pPhysicals->push_back(new CPhysicalFriction());

	return pPhysicals;
}

/*
std::vector<CAction* >* CPlayerPartsFactory::getActions() {
	//行えるアクション群を作成
	std::vector<CAction* >* pActions = new std::vector<CAction*>;
	
	//ジャンプアクションの設定
	pActions->push_back(new CActionJump());
	//斬撃01アクションの追加
	//pActions->push_back(new CPlayerSlashAtack());
	

	return pActions;
}
*/

CBody* CPlayerPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

std::vector<CCollisionArea* >* CPlayerPartsFactory::getCollisionAreas() {
	//	衝突判定空間の生成
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

std::map<CPlayerCharacter::STATE, CAnimation*> CPlayerPartsFactory::getMapAnimations(){
	//アニメーションデータ群の作成
	std::map<CPlayerCharacter::STATE, CAnimation*> pAnimations;

	return pAnimations;
}

std::map<CPlayerCharacter::ACTION, CAction*> CPlayerPartsFactory::getMapActions(){
	//行えるアクション群を作成
	std::map<CPlayerCharacter::ACTION, CAction*> pActions;

	return pActions;
}

std::vector<CPlayerEffect*>* CPlayerPartsFactory::getEffects() {
	//エフェクト群を作成
	std::vector<CPlayerEffect*>* pEffects = new std::vector<CPlayerEffect*>;

	return pEffects;
}

CPlayerWeapon* CPlayerPartsFactory::getWeapon() {
	//武器の生成
	CPlayerWeapon* pWeapon = NULL; //CPlayerNormalWeapon::getInstance();

	return pWeapon;
}

CStatus* CPlayerPartsFactory::getStatus() {
	// ステータスの作成
	return new CStatus();
}

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//プレイヤーの生成と組み立て
CPlayerCharacter* CPlayerBoyCreateFactory::createPlayer() {

	CPlayerCharacter* pPlayer = CPlayerBoy::create();

	//移動用データの取得
	pPlayer->m_pMove = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMove();
	//アニメーションデータ群の取得
	//pPlayer->m_pAnimations = this->partsFactories[(int)PLAYER_TYPE::BOY]->getAnimations();
	//適用する物理演算群の取得
	pPlayer->m_pPhysicals = this->partsFactories[(int)PLAYER_TYPE::BOY]->getPhysicals();
	//アクション群の取得
	//pPlayer->m_pActions = this->partsFactories[(int)PLAYER_TYPE::BOY]->getActions();
	//衝突判定用データの取得
	pPlayer->m_pBody = this->partsFactories[(int)PLAYER_TYPE::BOY]->getBody();
	pPlayer->m_pCollisionAreas = this->partsFactories[(int)PLAYER_TYPE::BOY]->getCollisionAreas();

	//アニメーションデータ群の取得(map)
	pPlayer->m_mapAnimations = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMapAnimations();
	//アクション群の取得(map)
	pPlayer->m_mapActions = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMapActions();
	//エフェクトデータの取得
	pPlayer->m_pEffects = this->partsFactories[(int)PLAYER_TYPE::BOY]->getEffects();
	//武器データの取得
	//pPlayer->m_pWeapon = this->partsFactories[(int)PLAYER_TYPE::BOY]->getWeapon();

	//ステータスの取得
	pPlayer->m_pStatus = this->partsFactories[(int)PLAYER_TYPE::BOY]->getStatus();

	return pPlayer;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================

//各々のパーツのセッティング
void CPlayerBoyFactory::settingMove(CPlayerCharacter* pCharacter){

	//初期位置の設定
	//pCharacter->m_pMove->m_pos.set(320.0f, 32.0f);
	pCharacter->m_pMove->m_pos.set(900, WINDOW_RIGHT / 2.0f);
}
void CPlayerBoyFactory::settingTexture(CPlayerCharacter* pCharacter){
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_PLAYER);
	
}

void CPlayerBoyFactory::settingAnimations(CPlayerCharacter* pCharacter) {

	//直立アニメーションの設定
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::STAND] = (new CChipNotAnimation());
	//歩行アニメーションの設定
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WALK] = (new CChipListAnimation(10, true));
	//ダメージを受け時のアニメーション設定
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::HIT] = (new CChipNotAnimation());
	//落ちているときのアニメーション
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::FALING] = (new CChipNotAnimation());
	//持ち上げるときのアニメーション
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING] = (new CChipListAnimation(15, true));


	//抜刀たち
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::DRAWN_STAND] = (new CChipNotAnimation());

	//攻撃アニメーション1-1
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_1] = (new CChipListAnimation(8, false));
	//攻撃アニメーション1-2
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_2] = (new CChipListAnimation(8, false));
	//攻撃アニメーション1-3
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_3] = (new CChipNotAnimation());


	//直立アニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::STAND]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//歩行アニメーションに設定する1枚目のチップデータの設定
	for (int i = 0; i < 7; i++) {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WALK]->addChipData(new CChip(256 * i, 256 * 0, 256, 256));
	}

	//ダメージを受けた時のアニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::HIT]->addChipData(new CChip(256 * 2, 256 * 4, 256, 256));

	//落ちている時のアニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::FALING]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//持ち上げるときのアニメーション
	for (int i = 2; i < 5; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * i, 256 * 0, 256, 256));
	}
	

	//抜刀たち
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::DRAWN_STAND]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//攻撃アニメーション1-1
	for (int i = 2; i < 6; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_1]->addChipData(new CChip(256 * i, 256 * 2, 256, 256));
	}
	
	//攻撃アニメーション1-2
	for (int i = 2; i < 6; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_2]->addChipData(new CChip(256 * i, 256 * 2, 256, 256));
	}
	
	//攻撃アニメーション1-3
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_3]->addChipData(new CChip(256 * 5, 256 * 0, 256, 256));

}

void CPlayerBoyFactory::settingPhysicals(CPlayerCharacter* pCharacter){
	
	//最高速度と摩擦の設定
	CPhysicalFriction* pFriction = (CPhysicalFriction*)(*pCharacter->m_pPhysicals)[1];
	pFriction->set(4.0f, 0.3f);
}

void CPlayerBoyFactory::settingActions(CPlayerCharacter* pCharacter){
	//なしアクションの設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::NONE] = (new CPlayerNoneAction());

	//持ち上げアクションの設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::LIFT_UP] = (new CPlayerLiftUpAction());

	//ジャンプアクションの設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::JUMP] = (new CActionJump());
	CActionJump* pAction = (CActionJump*)(pCharacter->m_mapActions)[CPlayerCharacter::ACTION::JUMP];
	//加速度とブーストの設定
	pAction->set(3.0f, 4);

	//アタックアクションの設定
	//（使われることはない）
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::ATTACK] = (new CPlayerNoneAction());

}

void CPlayerBoyFactory::settingBody(CPlayerCharacter* pCharacter){

	pCharacter->m_pBody->set(-60.0f, 128.0f, 60.0f, -128.0f);
}

//衝突判定空間の設定
void CPlayerBoyFactory::settingCollisionArea(CPlayerCharacter* pCharacter) {

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
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16*i - (64), -128)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16*i - (64), 128)));
	}

	for (int i = 0; i < 17; i++) {
		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(64, 16*i - (128))));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-64, 16*i - (128))));
	}

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);
	
}


void CPlayerBoyFactory::settingStatus(CPlayerCharacter* pCharacter) {

	pCharacter->m_pStatus->set(10, 10, 1);
}

//エフェクトの設定
void CPlayerBoyFactory::settingEffects(CPlayerCharacter* pCharacter) {
	//無しエフェクト

}

//武器の設定
void CPlayerBoyFactory::settingWeapon(CPlayerCharacter* pCharacter) {
	//今のところ無し

}


void CPlayerBoyFactory::settingInitialize(CPlayerCharacter* pCharacter){
	//状態の設定
	pCharacter->m_playerState = CPlayerCharacter::STATE::FALING;

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
// 女の子の生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//プレイヤーの生成と組み立て
CPlayerCharacter* CPlayerGirlCreateFactory::createPlayer() {

	CPlayerCharacter* pPlayer = CPlayerGirl::create();

	//移動用データの取得
	pPlayer->m_pMove = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMove();
	//アニメーションデータ群の取得
	//pPlayer->m_pAnimations = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getAnimations();
	//適用する物理演算群の取得
	pPlayer->m_pPhysicals = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getPhysicals();
	//アクション群の取得
	//pPlayer->m_pActions = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getActions();
	//衝突判定用データの取得
	pPlayer->m_pBody = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getBody();
	pPlayer->m_pCollisionAreas = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getCollisionAreas();

	//アニメーションデータ群の取得(map)
	pPlayer->m_mapAnimations = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMapAnimations();
	//アクション群の取得(map)
	pPlayer->m_mapActions = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMapActions();
	//エフェクトデータの取得（map）
	pPlayer->m_pEffects = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getEffects();

	//※武器の取得は行わない

	//ステータスの取得
	pPlayer->m_pStatus = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getStatus();

	return pPlayer;

}

//================================================
// 女の子のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CPlayerGirlFactory::settingMove(CPlayerCharacter* pCharacter) {

	//初期位置の設定
	//pCharacter->m_pMove->m_pos.set(288.0f, 128.0f);
	pCharacter->m_pMove->m_pos.set(980, WINDOW_RIGHT / 2.0f);
}
void CPlayerGirlFactory::settingTexture(CPlayerCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_PLAYER_GIRL);
	
}

void CPlayerGirlFactory::settingAnimations(CPlayerCharacter* pCharacter) {
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_01] = (new CChipListAnimation(20, true));
	//直立アニメーションの設定（暇状態）
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE] = (new CChipNotAnimation());
	//歩行アニメーションの設定
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WALK] = (new CChipListAnimation(8, true));
	//ダメージを受け時のアニメーション設定
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::HIT] = (new CChipNotAnimation());
	//落ちているときのアニメーション
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::FALING] = (new CChipNotAnimation());
	//持ち上げるときのアニメーション
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING] = (new CChipListAnimation(15, true));
	//暇つぶしアニメ-ション（１）
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_01] = (new CChipListAnimation(8, true));
	//暇つぶしアニメ-ション（２）※歩くモーションと同じ
	//pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_02] = (new CChipListAnimation(10, true));


	//直立アニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WASTE]->addChipData(new CChip(256 * 0, 256 * 3, 256 * 1, 256 * 1));

	//歩行アニメーションに設定する1枚目のチップデータの設定
	for (int i = 0; i <7; i++)  /* 7枚 */ {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WALK]->addChipData(new CChip(256 * i, 256 * 1, 256 * 1, 256 * 1));

	}

	//ダメージを受けた時のアニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::HIT]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));

	//落ちている時のアニメーションに設定する為のチップデータの設定
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::FALING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));

	//持ち上げるときのアニメーション
	//1枚目
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));
	//2枚目
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));
	//3枚目
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));


	//暇つぶしアニメーション（１）に設定するチップデータの設定
	for (int i = 0; i < 6; i++)  /* 6枚 */ {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WASTE_ANIME_01]->addChipData(new CChip(256 * i, 256 * 3, 256 * 1, 256 * 1));
		
	}

}

void CPlayerGirlFactory::settingPhysicals(CPlayerCharacter* pCharacter) {
	//最高速度と摩擦の設定
	CPhysicalFriction* pFriction = (CPhysicalFriction*)(*pCharacter->m_pPhysicals)[1];
	pFriction->set(6.0f, 0.3f);
}

void CPlayerGirlFactory::settingActions(CPlayerCharacter* pCharacter) {

	//なしアクションの設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::NONE] = (new CPlayerNoneAction());
	
	//ジャンプアクションの設定
	//pCharacter->m_mapActions[CPlayerCharacter::ACTION::JUMP] = (new CActionJump());
	//CActionJump* pAction = (CActionJump*)(pCharacter->m_mapActions)[CPlayerCharacter::ACTION::JUMP];
	//加速度とブーストの設定
	//pAction->set(3.0f, 4);

	//暇つぶしアクションの設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE] = (new CGirlBaseWasteTimeAction());

	//暇つぶしアクション（１）の設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE_ACT_01] = (new CGirlWasteAction_01());
	//暇つぶしアクション（２）の設定
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE_ACT_02] = (new CGirlWasteAction_02());


}

void CPlayerGirlFactory::settingBody(CPlayerCharacter* pCharacter) {

	pCharacter->m_pBody->set(-60.0f, 128.0f, 60.0f, -128.0f);
}

//衝突判定空間の設定
void CPlayerGirlFactory::settingCollisionArea(CPlayerCharacter* pCharacter) {

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
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16 * i - (64), -128)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16 * i - (64), 128)));
	}

	for (int i = 0; i < 17; i++) {
		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(64, 16 * i - (128))));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-64, 16 * i - (128))));
	}

	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CPlayerGirlFactory::settingStatus(CPlayerCharacter* pCharacter) {

	pCharacter->m_pStatus->set(10, 10, 1);
}

//エフェクトの設定
void CPlayerGirlFactory::settingEffects(CPlayerCharacter* pCharacter) {
	//無しエフェクト
	

}

//武器の設定
void CPlayerGirlFactory::settingWeapon(CPlayerCharacter* pCharacter) {
	//今のところ無し

}

void CPlayerGirlFactory::settingInitialize(CPlayerCharacter* pCharacter) {
	//状態の設定
	pCharacter->m_playerState = CPlayerCharacter::STATE::FALING;

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
CPlayerFactoryManager* CPlayerFactoryManager::m_pPlayerFactoryManager = NULL;

//インスタンスの取得
CPlayerFactoryManager* CPlayerFactoryManager::getInstance() {

	if (CPlayerFactoryManager::m_pPlayerFactoryManager == NULL) {
		CPlayerFactoryManager::m_pPlayerFactoryManager = new CPlayerFactoryManager();
	}

	return CPlayerFactoryManager::m_pPlayerFactoryManager;
}