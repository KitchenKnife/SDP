



//================================================
//追跡	
//================================================


/*
* EnemyActionPursuit.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionPursuit.h"
#include<cmath>


/*
* @desc 更新処理
* @param 追跡を行うキャラクターのアドレス
*/
void CEnemyActionPursuit::update(CCharacter* pChara) {

	if (this->m_isPursuiting == true) {

		//追跡中
		this->pursuit(pChara);

		// キャラにたどり着いたら
		if (pChara->collision(CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1)) || 
			pChara->collision(CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2))) {


			// 速度を0にする
			pChara->m_pMove->m_vel.set(0.0f, 0.0f);

			// ここにトリガー取り付け

			(*pChara->m_pActions)[(int)CEnemyCharacter::ACTION::ATTACK]->start();

			//再生を止める
			this->stop();
			return;
		}

	}
	else if (this->m_isPursuitStart == true) {

		//追跡開始

		//追跡フラグをtrueにする
		this->m_isPursuiting = true;
	}

	//追跡開始フラグを下げる
	this->m_isPursuitStart = false;


}



//===================================================================
// 近いプレイヤー優先の追跡クラス
//===================================================================
/*
*	@desc　近いプレイヤー優先の追跡
*	@param 追跡する敵のアドレス
*/
void CActionPursuitNear::pursuit(CCharacter* pChara) {


	// 敵とプレイヤーの距離を測る
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	Vec2 BoyPos = pBoy->m_pMove->m_pos - pChara->m_pMove->m_pos;
	Vec2 GirlPos = pGirl->m_pMove->m_pos - pChara->m_pMove->m_pos;

	// 敵とプレイヤーの距離を正規化
	float BoyVec = std::sqrtf(BoyPos.x * BoyPos.x + BoyPos.y * BoyPos.y);
	float GirlVec = std::sqrtf(GirlPos.x * GirlPos.x + GirlPos.y * GirlPos.y);

	//騎士が近ければ
	if (BoyVec < GirlVec) {

		// 騎士までの追跡移動量の計算
		Vec2 pursuitVelBoy;
		pursuitVelBoy.x = BoyPos.x / BoyVec;
		pursuitVelBoy.y = BoyPos.y / BoyVec;

		// 設定
		pChara->m_pMove->m_vel = pursuitVelBoy;

	}
	// 少女の方が近ければ
	else {

		// 少女までの追跡移動量の計算
		Vec2 pursuitVelGirl;
		pursuitVelGirl.x = BoyPos.x / BoyVec;
		pursuitVelGirl.y = BoyPos.y / BoyVec;

		// 設定
		pChara->m_pMove->m_vel = pursuitVelGirl;

	}
}


//===================================================================
// 少女優先の追跡クラス
//===================================================================

/*
*	@desc　追跡
*	@param 追跡する敵のアドレス
*/
void CActionPursuitGirlPriority::pursuit(CCharacter* pChara) {


	// 攻撃されたら騎士を狙う（HPが減っていたら）
	if (pChara->m_pStatus->getmaxHp() > pChara->m_pStatus->getHp()) {

		// 騎士の真上


		//this->swing(pChara,)

		// 設定
//		pChara->m_pMove->m_vel = ;
	}
	else {


		// 設定
		//pChara->m_pMove->m_vel = pursuitVelGirl;
	}

}

//===================================================================
// 少女のみ追跡クラス
//===================================================================

/*
*	@desc　追跡
*	@param 追跡する敵のアドレス
*/
void CActionPursuitGirlOnly::pursuit(CCharacter* pChara) {

	// 敵とプレイヤーの距離を測る
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
	Vec2 GirlPos = pGirl->m_pMove->m_pos - pChara->m_pMove->m_pos;

	// 敵とプレイヤーの距離を正規化
	float GirlVec = std::sqrtf(GirlPos.x * GirlPos.x + GirlPos.y * GirlPos.y);

	// 少女までの追跡移動量１を出す
	Vec2 pursuitVelGirl;
	pursuitVelGirl.x = GirlPos.x / GirlVec;
	pursuitVelGirl.y = GirlPos.y / GirlVec;

	// 敵の速度に合わせて設定する
	pursuitVelGirl.x = pursuitVelGirl.x * pChara->m_pStatus->getSpeed();
	pursuitVelGirl.y = pursuitVelGirl.y * pChara->m_pStatus->getSpeed();

	// 設定
	pChara->m_pMove->m_vel = pursuitVelGirl;

}


//===================================================================
// 近いプレイヤーの方向を向くだけの追跡クラス
//===================================================================
void CActionPursuitDirection::pursuit(CCharacter* pChara) {

		// 敵とプレイヤーの距離を測る
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
	

		float BoyVec = pBoy->m_pMove->m_pos.x * pBoy->m_pMove->m_pos.x + pBoy->m_pMove->m_pos.y * pBoy->m_pMove->m_pos.y;
		float GirlVec = pGirl->m_pMove->m_pos.x *  pGirl->m_pMove->m_pos.x + pGirl->m_pMove->m_pos.y *  pGirl->m_pMove->m_pos.y;


		//騎士が近ければ
		if (BoyVec < GirlVec) {

			pChara->m_pMove->m_vel.x = 0.0f;

			// 敵の左側に騎士
			if (pBoy->m_pMove->m_pos.x < 0) {
				//左向きに設定
				pChara->setScale(1.0f, 1.0f);
			}

			// 敵の右側に騎士
			else if (pBoy->m_pMove->m_pos.x > 0) {

				//右向きに設定
				pChara->setScale(-1.0f, 1.0f);
			}
		}

		// 少女の方が近ければ
		else {

			// 敵の左側に少女
			if (pGirl->m_pMove->m_pos.x < 0) {
				//左向きに設定
				pChara->setScale(1.0f, 1.0f);
			}

			// 敵の右側に少女
			else if (pGirl->m_pMove->m_pos.x > 0) {
				//右向きに設定
				pChara->setScale(-1.0f, 1.0f);
			}
		}

	
}