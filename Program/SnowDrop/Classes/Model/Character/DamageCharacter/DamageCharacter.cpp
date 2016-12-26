
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
	// アクション
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}

	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CDamageCharacter::animationFunc() {
	(*this->m_pAnimations)[this->m_animationState]->update();
}

//衝突判定処理
void CDamageCharacter::collisionAll() {

	//死んでいたら飛ばす
	if (this->m_isAlive == false)
		return;

	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}

//状態チェック
void CDamageCharacter::checkState() {
	if (this->m_pStateMachine)
	{
		//状態遷移マシンの更新
		this->m_pStateMachine->update();
	}
}

//反映処理
void CDamageCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

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