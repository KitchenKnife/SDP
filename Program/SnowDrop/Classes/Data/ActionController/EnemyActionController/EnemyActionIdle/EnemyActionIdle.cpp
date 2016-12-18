/*
* EnemyActionIdle.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionIdle.h"



//================================================
//待機	
//================================================
/*
* @desc 更新処理
* @param 待機を行うキャラクターのアドレス
*/
void CEnemyActionIdle::update(CCharacter* pChara) {

	if (this->m_isIdlering == true) {

		//　待機中
		this->Idle(pChara);

		//現在のフレームが規定のフレームに達したら
		if ((this->m_isIdleStart == false) && (this->m_currentFrame == this->m_frame)) {

			//再生を止める
			this->stop();
			return;
		}

	}
	else if (this->m_isIdleStart == true) {

		//待機開始

		//待機フラグをtrueにする
		this->m_isIdlering = true;
	}

	//待機開始フラグを下げる
	this->m_isIdleStart = false;


}

//===================================================================
// 待機中うろうろするクラス
//===================================================================

/*
*	@desc　移動 + アニメもある待機
*	@param 待機する敵のアドレス
*/
void CActionIdleMove::Idle(CCharacter* pChara) {
	// 秒数で管理する

	// 1秒間は右へ
	if (this->m_currentFrame < 60) {

		pChara->m_pMove->m_vel.x = 1.0f;
		CCLOG("Idle MOVE!!");
	}
	// 2秒目は左へ
	if (this->m_currentFrame >= 60 || this->m_currentFrame < 120) {

		pChara->m_pMove->m_vel.x = -1.0f;
	}
	// 3秒目はきょろきょろする
	if (this->m_currentFrame >= 120 && this->m_currentFrame % 20 && pChara->m_pMove->m_vel.x > 0) {

		pChara->m_pMove->m_vel.x = -1.0f;
	}
	if (this->m_currentFrame >= 120 && this->m_currentFrame % 20 && pChara->m_pMove->m_vel.x < 0) {

		pChara->m_pMove->m_vel.x = 1.0f;
	}
}





//===================================================================
// 待機中アニメーションだけあるクラス
//===================================================================
/*
*	@desc　アニメーションのみの待機
*	@param 待機する敵のアドレス
*/
void CActionIdleAnimationOnly::Idle(CCharacter* pChara) {

}
