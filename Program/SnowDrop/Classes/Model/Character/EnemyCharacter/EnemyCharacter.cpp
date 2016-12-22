
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
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"


//================================================	
//	敵キャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CEnemyCharacter::CEnemyCharacter() {}

//デストラクタ
CEnemyCharacter::~CEnemyCharacter() {}

	//アクション関数群の解放
	std::map<STATE, CAction*>::iterator actItr = this->m_pActions.begin();
	while (actItr != this->m_pActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_pActions.clear();

}

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
	/*
	for (CAction* pAction : (*m_pActions)) {
		pAction->update(this);
	}
	*/

	//アクション処理
	(this->m_pActions)[this->m_state]->update(this);

	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CEnemyCharacter::animationFunc() {

	
}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
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