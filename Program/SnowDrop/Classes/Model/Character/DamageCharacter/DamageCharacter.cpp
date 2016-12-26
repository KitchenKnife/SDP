
/*
* DamageCharacter.cpp
*
*	2016/12/26	Yamasaki
*
*/
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "DamageCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	ダメージキャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CDamageCharacter::CDamageCharacter() {}

//デストラクタ
CDamageCharacter::~CDamageCharacter() {}



//初期化処理
bool CDamageCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}


//移動処理
void CDamageCharacter::moveFunc() {
}

//アニメーション処理
void CDamageCharacter::animationFunc() {
}

//衝突判定処理
void CDamageCharacter::collisionAll() {
}

//状態チェック
void CDamageCharacter::checkState() {
}

//反映処理
void CDamageCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	// 有効期限の更新
	this->m_activeFrame--;

	if (this->m_activeFrame < 0) {

		// 有効期限が切れたら死ぬ。
		this->m_activeFlag = false;
	}

}

/**
* @desc キャラクター1体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool CDamageCharacter::collision(CCharacter* pChara) {

	//プレイヤーと敵の矩形を生成
	CCollisionRect pEnemyCollisionRect = CCollisionRect(*this->m_pBody, this->m_pMove->m_pos);

	CCollisionRect pPlayerCollisionRect = CCollisionRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

	// 矩形と矩形の衝突判定
	return pEnemyCollisionRect.collision(&pPlayerCollisionRect);

}

/**
* @desc	他クラスから衝突判定を受けた際の処理
* @param	キャラクターのアドレス
*/
void CDamageCharacter::hits(CCharacter* pChara) {

}