
/*
* EnemyCharacter.cpp
*
*	2016/11/11	Yamasaki
*
*/
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	敵キャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CEnemyCharacter::CEnemyCharacter() {}

//デストラクタ
CEnemyCharacter::~CEnemyCharacter() {}



//初期化処理
bool CEnemyCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}


//移動処理
void CEnemyCharacter::moveFunc() {
	// アクション
	for (CAction* pAction : (*m_pActions)) {
		pAction->update(this);
	}

	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CEnemyCharacter::animationFunc() {
	(*this->m_pAnimations)[this->m_state]->update();
}

//衝突判定処理
void CEnemyCharacter::collisionAll() {

	//死んでいたら飛ばす
	if (this->m_isAlive == false)
		return;

	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}

//状態チェック
void CEnemyCharacter::checkState() {
	
}

//反映処理
void CEnemyCharacter::applyFunc() {

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
bool CEnemyCharacter::collision(CCharacter* pChara) {

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
void CEnemyCharacter::hits(CCharacter* pChara) {

}