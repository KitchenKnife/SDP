
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
#include "Data/ActionController/ActionController.h"
#include "Model/Character/CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"


//================================================	
//	ダメージキャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CDamageCharacter::CDamageCharacter() {
	this->m_charaType = (int)CHARACTER_TYPE::DAMAGE;

}

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

	//ダメージキャラクターは常に所有者の画像右端に着いていくように移動する。
	//this->m_pMove->m_pos.set(this->m_pChara->m_pMove->m_pos.x + this->m_pBody->m_right, this->m_pChara->m_pMove->m_pos.y);

	// アクション
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
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
	if (this->m_pChara->m_charaType == (int)CHARACTER_TYPE::PLAYER_BOY) {
		std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();

		for (CCharacter* pChara : (*pCharacters)) {
			if (pChara->m_charaType == (int)CHARACTER_TYPE::ENEMY ||
				pChara->m_charaType == (int)CHARACTER_TYPE::DAMAGE)
			{
				//生きていたら
				if (pChara->m_isAlive)
				{
					if (this->collision(pChara)) {
						//攻撃力分のダメージを与える
						pChara->decreaseHP(this->m_status.getAttackPt());
						//攻撃を受けている状態フラグを上げる
						pChara->m_underAttack = true;
					}
				}
			}
		}
	}

	//ダメージを出したのが敵だったら
	if (this->m_pChara->m_charaType == (int)CHARACTER_TYPE::ENEMY) {

		CPlayerCharacterBoy* pTarget = CCharacterAggregate::getInstance()->getPlayer();
		if (pTarget->m_isAlive)
		{
			if (this->collision(pTarget)) {
				//攻撃力分のダメージを与える
			//	pTarget->decreaseHP(this->m_status.getAttackPt());
				//攻撃を受けている状態フラグを上げる
				pTarget->m_underAttack = true;

				if (this->m_pMove->m_pos.x < pTarget->m_pMove->m_pos.x) {
					pTarget->m_underAttackDirection = (int)PLAYER_UNDER_ATTACK_DIRECTION::LEFT;
				}
				else {
					pTarget->m_underAttackDirection = (int)PLAYER_UNDER_ATTACK_DIRECTION::RIGHT;
				}

				
			}
		}
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
	this->setTextureRect((*this->m_pAnimations)[this->m_animationState]->getCurrentChip());


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

	//ダメージキャラクターと敵の矩形を生成
	CCollisionRect damageCollisionRect = CCollisionRect(*this->m_pBody, this->m_pMove->m_pos);

	CCollisionRect enemyCollisionRect = CCollisionRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

	// 矩形と矩形の衝突判定
	return damageCollisionRect.collision(&enemyCollisionRect);

}

/**
* @desc	他クラスから衝突判定を受けた際の処理
* @param	キャラクターのアドレス
*/
void CDamageCharacter::hits(CCharacter* pChara) {

}