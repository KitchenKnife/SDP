/*
* ActionController.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionController.h"
#include "Model/Character/Character.h"


//================================================
//	打撃攻撃	
//================================================


/*
* @desc 更新処理
* @param 攻撃を行うキャラクターのアドレス
*/
void CActionBlowAttack::update(CCharacter* pChara) {

	if (this->m_isBlowAttacking == true) {

		//打撃攻撃中

		//フレームを足していく
		this->m_currentFrame++;

		//現在のフレームが規定のフレームに達したら
		if ((this->m_isBlowAttackStart == false) && (this->m_currentFrame == this->m_frame)) {

			//再生を止める
			this->stop();
			return;
		}

	}
	else if (this->m_isBlowAttackStart == true) {

		//打撃攻撃開始
		m_currentFrame = 0;

		// HPの反映
		
		this->blowHit(this->m_pStatus->getAttackPt(), pChara->m_pStatus);

		//打撃攻撃フラグをtrueにする
		this->m_isBlowAttacking = true;
	}

	//打撃攻撃開始フラグを下げる
	this->m_isBlowAttackStart = false;


}