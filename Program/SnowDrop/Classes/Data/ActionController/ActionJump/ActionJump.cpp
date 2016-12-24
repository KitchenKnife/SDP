/**
*
* ActionController.cpp
*
*	2016 / 11 / 07	Osumi
*
*/
#include "ActionJump.h"
#include "Model/Character/Character.h"

/*
* @desc	更新処理（ジャンプ移動計算）
* @param	ジャンプする対象のキャラクター
* @tips	上キーが押されたらこの関数を呼び出す
*/
void  CActionJump::update(CCharacter* pChara) {

	if (this->m_isJumping == true) {

		//ジャンプ中

		//ジャンプブーストを減らしていく
		this->m_currentBoost--;

		//ジャンプブーストが0より小さい場合
		if ((this->m_isJumpStart == false) || (this->m_currentBoost < 0)) {

			//加速度を0にする
			pChara->m_pMove->m_accele.y = 0.0f;
		}

	}
	else if (this->m_isJumpStart == true) {

		//ジャンプ開始

		//y軸の加速度に値を設定
		pChara->m_pMove->m_accele.y = this->m_accele;
		//何フレーム、加速度を適用させるか設定
		this->m_currentBoost = this->m_boost;
		//ジャンプフラグをtrueにする
		this->m_isJumping = true;
	}

	//ジャンプ開始フラグを下げる
	this->m_isJumpStart = false;
}

/**
* @desc	アクションの再起動
* @param	再起動するキャラクター
* @tips	キャラクターのY成分のリセット
*/
void CActionJump::restart(CCharacter* pChara) {

	//Y成分の速度と加速度のリセっト
	pChara->m_pMove->m_vel.y = 0.0f;
	pChara->m_pMove->m_accele.y = 0.0f;

	//アクションの停止
	this->stop();

	//アクションの開始
	this->start();
}