
/*
* PlayerWeapon.cpp
*
*	2016/12/1	Osumi
*
*/

#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
/*
//================================================
//
//　プレイヤーの武器基底クラス
//
//================================================

//コンストラクタ
CPlayerWeapon::CPlayerWeapon() {

}

//デストラクタ
CPlayerWeapon::~CPlayerWeapon() {

	//アニメーション群の解放
	std::map<ATTACK_ANIME, CAnimation*>::iterator animeItr = this->m_mapAnimations.begin();
	while (animeItr != this->m_mapAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_mapAnimations.clear();

	//アニメーション群の解放
	std::map<ATTACK_ACT, CPlayerWeaponAttack*>::iterator actItr = this->m_mapActions.begin();
	while (actItr != this->m_mapActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_mapActions.clear();

}

//初期化処理
bool CPlayerWeapon::init() {

	if (CWeapon::init() == false) {
		CCLOG("武器の抽象クラスの初期化に失敗");
		return false;
	}

	//ベクターのアニメーション群の生成
	this->m_pAnimations = new std::vector<CAnimation*>;

	//ベクターのアクション群の生成
	this->m_pActions = new std::vector<CAction*>;

	return true;
}

//更新処理
void CPlayerWeapon::update() {

	//移動処理
	this->moveFunc();

	//状態のチェック
	this->checkState();

	//アニメーション処理
	this->animationFunc();

	//アクション処理
	this->actionFunc();

	//反映処理
	this->applyFunc();

}

//状態のチェック
void CPlayerWeapon::checkState() {

	if (this->m_attackAnime == ATTACK_ANIME::RETURN) {
		//this->m_activeFlag = false;
		//this->setVisible(false);

	}else{ 
		//this->m_activeFlag = true;
		//this->setVisible(true);
	}
	
	//有効フラグに応じて可視化
	this->setVisible(this->m_activeFlag);

}

//武器の納刀
void CPlayerWeapon::returnSword() {

	this->m_attackAnime = ATTACK_ANIME::RETURN;
	this->m_attackAct = ATTACK_ACT::NONE;

	CPlayerBoy* pBoy = CPlayerBoy::getInstance();
	pBoy->m_playerAct = CPlayerCharacter::ACTION::NONE;
	pBoy->m_playerState = CPlayerCharacter::STATE::STAND;
}

//レイヤーからの取り外し
void CPlayerWeapon::removeFromeLayer() {
	this->removeFromParent();
}

//移動処理
void CPlayerWeapon::moveFunc() {

	//入力処理
	this->inputFunc();
	//プレイヤーキャラクターの取得
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	CBody* pBody = pPlayerChara->m_pBody;

	//移動計算(プレイヤー基準の座標)
	this->m_pMove->setPos((pBody->m_right)+this->m_offset.x, -(pBody->m_bottom)+this->m_offset.y);

}

//アニメーション処理
void  CPlayerWeapon::animationFunc() {
	
	//有効フラグが下りてたらここで処理を止める
	if (this->m_activeFlag == false) {
		return;
	}

	//プレイヤーアニメーション
	(this->m_mapAnimations)[m_attackAnime]->update();

}

//アクション処理
void CPlayerWeapon::actionFunc() {

	//有効フラグが下りてたらここで処理を止める
	if (this->m_activeFlag == false) {
		return;
	}

	//状態に応じたアクション
	(this->m_mapActions)[m_attackAct]->update(CPlayerBoy::getInstance());

}

//反映処理
void  CPlayerWeapon::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//有効フラグが下りてたらここで処理を止める
	if (this->m_activeFlag == false) {
		return;
	}

	//チップデータを反映
	this->setTextureRect(this->m_mapAnimations[m_attackAnime]->getCurrentChip());
	
}




//入力処理
void  CPlayerWeapon::inputFunc() {

	CPlayerBoy* pBoy = CPlayerBoy::getInstance();

	if (inputflag.m_z == true) {
		if (this->m_zKeyDown == false) {

			this->m_zKeyDown = true;

			if (this->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::RETURN) {

				this->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;
				this->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;//::DRAWN;

			}
			else if (this->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::DRAWN) {

				this->m_mapActions[CPlayerWeapon::ATTACK_ACT::SLASH_01]->start();

				this->m_attackAct = CPlayerWeapon::ATTACK_ACT::SLASH_01;
				this->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_1;

				CPlayerBoy::getInstance()->m_playerAct = CPlayerCharacter::ACTION::ATTACK;
				CPlayerBoy::getInstance()->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_1;

			}
			else {
				this->m_mapActions[this->m_attackAct]->m_nextActionFlag = true;
			}

		}
	}
	else {
		this->m_zKeyDown = false;

	}


}

//================================================
//
//　プレイヤーの通常武器クラス
//
//================================================

//共有インスタンス
CPlayerNormalWeapon* CPlayerNormalWeapon::m_pPlayerWeapon = NULL;

//インスタンスの取得
CPlayerNormalWeapon* CPlayerNormalWeapon::getInstance() {

	if (CPlayerNormalWeapon::m_pPlayerWeapon == NULL) {
		//CPlayerNormalWeapon::m_pPlayerWeapon = (CPlayerNormalWeapon*)CPlayerWeaponFactoryManager::getInstance()->create(WEAPON_TYPE::NORMAL);
		CPlayerNormalWeapon::m_pPlayerWeapon = (CPlayerNormalWeapon*)CCharacterAggregate::getInstance()->getAtTag(TAG_WEAPON_1);
	}

	return CPlayerNormalWeapon::m_pPlayerWeapon;
}

//インスタンスの解放
void CPlayerNormalWeapon::removeInstance() {

	SAFE_DELETE(CPlayerNormalWeapon::m_pPlayerWeapon);
}

//武器のレイヤーへの取り付け
void CPlayerNormalWeapon::addChildPlayer(CPlayerCharacter* pChara) {
	pChara->addChild(this);
	
}

//コンストラクタ
CPlayerNormalWeapon::CPlayerNormalWeapon(){}

//デストラクタ
CPlayerNormalWeapon::~CPlayerNormalWeapon(){}

//初期化処理
bool CPlayerNormalWeapon::init() {

	if (CPlayerWeapon::init() == false) {
		CCLOG("プレイヤー武器クラスの初期化に失敗");
		return false;
	}

	return true;
}

//更新処理
void CPlayerNormalWeapon::update() {

	CPlayerWeapon::update();

}

//アニメーション処理
void CPlayerNormalWeapon::animationFunc() {


	if (this->m_mapActions[this->m_attackAct]->m_delayCounter > 0 )
		return;

	CPlayerWeapon::animationFunc();

}
*/