/*
* EnemyActionDamage.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionDamage.h"



//================================================
//　ダメージを受けた時のアクションクラス	
//================================================
/*
* @desc 更新処理
* @param ダメージを受けたキャラクターのアドレス
*/
/*
void CEnemyActionDamage::update(CCharacter* pChara) {

	if (this->m_isDamaging == true) {

		//追跡中
		this->Damage(pChara);

		///////
		if (pChara->m_state != (int)CEnemyCharacter::STATE::DAMAGE) {

			//再生を止める
			this->stop();
			return;
		}

	}
	else if (this->m_isDamageStart == true) {

		//追跡開始

		//追跡フラグをtrueにする
		this->m_isDamaging = true;
	}

	//追跡開始フラグを下げる
	this->m_isDamageStart = false;


}

*/

//===================================================================
// ダメージを受けて停止するクラス
//===================================================================
/*
*	@desc　ダメージを受けて停止する
*	@param ダメージを受ける敵のアドレス
*/
void CActionDamageStop::Damage(CCharacter* pChara) {

}



//===================================================================
// ダメージを受けて後ずさるクラス(後ろにズサー的な)
//===================================================================
/*
*	@desc ダメージを受けて後ずさる
*	@param ダメージを受ける敵のアドレス
*/
void CActionDamageBack::Damage(CCharacter* pChara) {

}

//===================================================================
// ダメージ中アニメーションだけあるクラス（移動or攻撃可能）
//===================================================================
/*
*	@desc　ダメージ中アニメーションのみ
*	@param ダメージを受ける敵のアドレス
*/
void CActionDamageAnimationOnly::Damage(CCharacter* pChara) {

}


//===================================================================
// ダメージも変化がないクラス（移動or攻撃可能）
//===================================================================
/*
*	@desc　ダメージ中も見た目に変化がない
*	@param ダメージを受ける敵のアドレス
*/
void CActionDamageNone::Damage(CCharacter* pChara) {

}