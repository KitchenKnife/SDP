/*
* PlayerWeaponFactory.cpp
*
*	2016/11/27	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"
//#include "PlayerCharacter.h"
/*

//================================================
// 武器パーツクラス工場
//	（AbstractFactory）
//================================================

CMove* CPlayerWeaponPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

CBody* CPlayerWeaponPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> CPlayerWeaponPartsFactory::getMapAnimations() {
	//アニメーションデータ群の作成
	std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> pAnimations;

	return pAnimations;
}

std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> CPlayerWeaponPartsFactory::getMapActions() {
	//行えるアクション群を作成
	std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> pActions;

	return pActions;
}

std::vector<cocos2d::Point*>* CPlayerWeaponPartsFactory::getPoints() {

	//行えるアクション群を作成
	std::vector<cocos2d::Point*>* pPoints = new std::vector<cocos2d::Point*>;

	return pPoints;
}

CStatus* CPlayerWeaponPartsFactory::getStatus() {
	// ステータスの作成
	return new CStatus();
}


std::vector<CCollisionArea* >* CPlayerWeaponPartsFactory::getCollisionAreas() {
	//	衝突判定空間の生成
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

//================================================
// 武器の生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//武器の生成と組み立て
CPlayerWeapon* CPlayerNormalWeaponCreateFactory::createWeapon() {

	CPlayerWeapon* pWeapon = CPlayerNormalWeapon::create();

	//移動用データの取得
	pWeapon->m_pMove = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMove();

	//衝突判定用データの取得
	pWeapon->m_pBody = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getBody();

	//アニメーションデータ群の取得(map)
	pWeapon->m_mapAnimations = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMapAnimations();
	//アクション群の取得(map)
	pWeapon->m_mapActions = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMapActions();
	//衝突判定基準点の取得
	pWeapon->m_pBasePoints= this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getPoints();

	//ステータスの取得
	pWeapon->m_pStatus = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getStatus();

	return pWeapon;
}

//================================================
// 武器のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================

//各々のパーツのセッティング
void CPlayerNormalWeaponFactory::settingMove(CPlayerWeapon* pWeapon) {

	//cocos2d::Point pt = CPlayerBoy::getInstance()->m_pMove->m_pos;

	//初期位置の設定
	pWeapon->m_pMove->m_pos.set(0,0);
}
void CPlayerNormalWeaponFactory::settingTexture(CPlayerWeapon* pWeapon) {
	//テクスチャの設定
	pWeapon->setTexture(IMAGE_SAMPLE_WEAPON);

}

void CPlayerNormalWeaponFactory::settingAnimations(CPlayerWeapon* pWeapon) {

	//納刀アニメーションの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::RETURN] = (new CChipNotAnimation());

	//抜刀アニメーションの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::DRAWN] = (new CChipNotAnimation());

	//斬撃01-1アニメーションの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1] = (new CChipListAnimation(6, false));

	//斬撃01-2アニメーションの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2] = (new CChipListAnimation(6, false));

	//斬撃01-3アニメーションの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_3] = (new CChipNotAnimation());


	//抜刀アニメーションに設定する為のチップデータの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::RETURN]->addChipData(new CChip(48 * 0, 54 * 0, 0, 0));

	//抜刀アニメーションに設定する為のチップデータの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::DRAWN]->addChipData(new CChip(48 * 0, 54 * 0, 48, 54));

	//斬撃01-1アニメーションに設定する為のチップデータの設定
	//1枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 0, 54 * 0, 48, 54));
	//2枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 1, 54 * 0, 48, 54));
	//3枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 2, 54 * 0, 48, 54));
	//4枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 3, 54 * 0, 48, 54));

	//斬撃01-2アニメーションに設定する為のチップデータの設定
	//1枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 0, 54 * 1, 48, 54));
	//2枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 1, 54 * 1, 48, 54));
	//3枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 2, 54 * 1, 48, 54));
	//4枚目
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 3, 54 * 1, 48, 54));


	//斬撃01-3アニメーションに設定する為のチップデータの設定
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_3]->addChipData(new CChip(48 * 3, 54 * 0, 48, 54));

}


void CPlayerNormalWeaponFactory::settingActions(CPlayerWeapon* pWeapon) {
	//なしアクションの設定
	pWeapon->m_mapActions[CPlayerWeapon::ATTACK_ACT::NONE] = (new CPlayerNoneWeaponAction());

	//斬撃01アクションの設定
	pWeapon->m_mapActions[CPlayerWeapon::ATTACK_ACT::SLASH_01] = (new CNormalSlashAttack_01());

}

void CPlayerNormalWeaponFactory::settingBody(CPlayerWeapon* pWeapon) {

	pWeapon->m_pBody->set(-20.0f, 20.0f, 20.0f, 20.0f);
}


void CPlayerNormalWeaponFactory::settingStatus(CPlayerWeapon* pWeapon) {

	pWeapon->m_pStatus->set(10, 10, 1);
}

//衝突判定の基準点を設定
void CPlayerNormalWeaponFactory::settingPoints(CPlayerWeapon* pWeapon) {

	(pWeapon->m_pBasePoints)->push_back(new cocos2d::Point(24,24));
}

void CPlayerNormalWeaponFactory::settingInitialize(CPlayerWeapon* pWeapon) {

	//攻撃アニメ
	pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::RETURN;
	//攻撃アクション
	pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;

	//武器の装備位置
	pWeapon->m_offset.set(26.0f, 4.0f);

	//有効フラグを下げる
	pWeapon->m_activeFlag = true;

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*
	pWeapon->applyFunc();

}


//================================================
// パーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CPlayerWeaponFactoryManager* CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager = NULL;

//インスタンスの取得
CPlayerWeaponFactoryManager* CPlayerWeaponFactoryManager::getInstance() {

	if (CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager == NULL) {
		CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager = new CPlayerWeaponFactoryManager();
	}

	return CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager;
}
*/