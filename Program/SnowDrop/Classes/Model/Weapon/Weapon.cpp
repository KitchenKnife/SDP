
/*
* weapon.cpp
*
*	2016/11/26	Osumi
*
*/

#include "Model/Weapon/Weapon.h"

//================================================
//
//　武器の抽象クラス
//
//================================================

//コンストラクタ
CWeapon::CWeapon(){}

//デストラクタ
CWeapon::~CWeapon(){

	for (cocos2d::Point* pPoint : (*m_pBasePoints)) {
		SAFE_DELETE(pPoint);
	}
	SAFE_DELETE(this->m_pBasePoints);

	SAFE_DELETE(this->m_pBody);


	
}

//初期化処理
bool CWeapon::init() {

	if (Sprite::init() == false) {
		CCLOG("Characterの初期化に失敗");
		return false;
	}

	//update()メンバ関数の呼び出し
	//this->scheduleUpdate();
	return true;
}

//更新処理
void CWeapon::update() {

	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//反映処理
	this->applyFunc();

	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	//this->collision(CCharacter* pChara);

}