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
	//アニメーションが終了していなければカウンターの更新を行う
	if (this->m_isEnd == false && this->changeLineFlag == false) {

		this->m_counter++;

		//カウンターの数がアニメーションさせる枚数以上になったらカウンターをリセットする
		if (this->m_counter >= this->m_interval*this->m_number) {

			//ループするなら
			if (this->m_isLoop == true) {

				//カウンターをリセット
				this->m_counter = 0;
			}
			else {

				//アニメーションが終了したかどうかのフラグに対してtrueを入れる
				this->changeLineFlag = true;

				//ループしないアニメーションに対しては飛び出たカウンターをデクリメントする
				this->m_counter--;
			}
		}
	}
	//アニメーションが終了
	else if(this->m_isEnd == false && this->changeLineFlag == true)
	{
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();

		//プレイヤーの連撃フラグが立っているか確認
		if (pBoy->m_chainAttackFlag == true) {
			//現在のチップラインを更新
			this->m_nowLine++;

			//現在のチップラインが格納しているライン数よりも下なら
			if (this->m_nowLine < this->m_line)
			{
				this->changeLineFlag = false;

				this->m_counter = 0;

				(*pBoy->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();
			}
			//これ以上再生できるラインがなければ
			else
			{
				//アニメーション終了フラグを立てる
				this->m_isEnd = true;
			}

			pBoy->m_chainAttackFlag = false;
		}
		//プレイヤーの連撃フラグが立っていなければ
		else
		{
			//アニメーション終了フラグを立てる
			this->m_isEnd = true;
		}
		
	}

	//表示するフレーム数
	m_currentFrame = this->m_counter / this->m_interval;

	//更新した現在のフレームを一応返す。
	return m_currentFrame;
}