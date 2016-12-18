/*
* ActionController.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionAttack.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


//================================================
//打撃攻撃	
//================================================


/*
* @desc 更新処理
* @param 攻撃を行うキャラクターのアドレス
*/
void CEnemyActionAttack::update(CCharacter* pChara) {


	//騎士の取得
	CCharacter* pKnightChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	//少女の取得
	CCharacter* pGirlChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	if (this->m_isAttacking == true) {

		//攻撃中
		this->attack(pChara);

		//フレームを足していく 
		this->m_currentFrame++;

		//衝突していなければ
		if (!(pChara->collision(pKnightChara)) || !(pChara->collision(pGirlChara))) {

			//再生を止める
			this->stop();
			return;
		}

	}
	else if (this->m_isAttackStart == true) {

		//設定された秒数攻撃開始
		m_currentFrame = 0;

		//打撃攻撃フラグをtrueにする
		this->m_isAttacking = true;
	}

	//打撃攻撃開始フラグを下げる
	this->m_isAttackStart = false;


}

//======================================
// BOSS1 腕回し
//======================================
void CEnemyBOSS1Attack::attack(CCharacter* pChara) {
	
	pChara->m_state = (int)CEnemyCharacter::STATE::ATTACK;

	// 3回中何回当たったか確認
	if (this->m_currentFrame % 60 == 0) {
		//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
		CCLOG("BOSS ATTACK!!");
		//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
	}

}

//======================================
// BOSS1 クエイク
//======================================
void CEnemyBOSS1AttackQuake::attack(CCharacter* pChara) {

	// プレイヤーが攻撃範囲内なら攻撃する

	//騎士の取得
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	if (pChara->collision(pPlayerChara) == true) {

		// 3回中何回当たったか確認
		if (this->m_currentFrame % 60 == 0) {
			//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
			CCLOG("BOSS Quake!!");
			//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
		}
	}

}