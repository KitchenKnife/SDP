/*
* Animation.cpp
*
*	2016/11/07	Osumi
*
*/
#include "Animation.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Model/Character/CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"


//========================================================================
// プレイヤー専用連撃アニメーション
//========================================================================
int CPlayerAttackAnimation::update() {
	//現在のアニメーションを終了したか確認
	if (this->m_pAnimations[this->m_nowLine]->isEnd()) {
		//終了していたら
		
		//プレイヤーの取得
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();
		
		//プレイヤーの連撃フラグが立っていたら
		if (pBoy->m_chainAttackFlag) {
			//現在の再生するアニメーションを更新
			this->m_nowLine++;

			pBoy->m_chainAttackFlag = false;

			//もし再生するアニメーションがなければ
			if (this->m_nowLine >= this->m_line) {
				//このアニメーション全体の終了フラグを立てる
				this->m_isEnd = true;

				return -1;
			}

			//次回のアニメーションが存在していれば
			//ダメージキャラクターを出す
			(*pBoy->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();
		}
		//連撃フラグを降りていたら
		else {
			//このアニメーション全体の終了フラグを立てる。
			this->m_isEnd = true;

			return -1;
		}
	}

	//現在のアニメーションを更新して返す。
	return this->m_pAnimations[this->m_nowLine]->update();
}