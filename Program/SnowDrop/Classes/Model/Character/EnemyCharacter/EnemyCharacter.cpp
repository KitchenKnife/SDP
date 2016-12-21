
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
CEnemyCharacter::CEnemyCharacter() {

}

//デストラクタ
CEnemyCharacter::~CEnemyCharacter() {

	//アニメーション群の解放
	std::map<STATE, CAnimation*>::iterator animeItr = this->m_pAnimations.begin();
	while (animeItr != this->m_pAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_pAnimations.clear();

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

/*
* @desc	初期化処理
* @param　初期化位置X
* @param　初期化位置Y
*/
bool CEnemyCharacter::init(float posX, float posY) {

	//キャラクタークラスの初期化
	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}

//ターゲットの設定
void CEnemyCharacter::setTarget(CCharacter* pChara) {
	this->m_currentTarget = pChara;
}

// アクション処理
void CEnemyCharacter::actionFunc(CCharacter* pChara) {

	this->m_pAnimations[this->m_state]->update();
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

	//アニメーション
	(this->m_pAnimations)[this->m_state]->update();
}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CEnemyCharacter::checkState() {

	
	//向きを判定
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//右向きに設定
			this->setScale(-1.0, 1.0);
		}
		else {
			//左向きに設定
			this->setScale(1.0, 1.0);
		}
	}
	/*
	//状態の判定
	if (this->m_pMove->m_vel.y > 0.0f) {

		//ｙ軸の速度がプラスということはジャンプしている状態
		m_state = (int)STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//ｙ軸の速度がマイナスといことは落ちている状態
		m_state = (int)STATE::FALING;
	}
	else if ((*this->m_pActions)[(int)ACTION::ATTACK]->getActionFlag()) {
	
		// 打撃攻撃中
		m_state = (int)STATE::ATTACK;

	}
	else if (this->m_pMove->m_vel.x > 0.0f) {
		//右に歩いている
		m_state = (int)STATE::WALK_RIGHT;
	}
	else if (this->m_pMove->m_vel.x < 0.0f) {
		//左に歩いている
		m_state = (int)STATE::WALK_LEFT;
	}
	else {
		//立っている
		m_state = (int)STATE::STAND;
	}
	*/

}

//反映処理
void CEnemyCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_pAnimations[this->m_state]->getCurrentChip());

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


