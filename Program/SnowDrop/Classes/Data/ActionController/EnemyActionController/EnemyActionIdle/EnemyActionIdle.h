/*
* EnemyActionIdle.h
*
*	2016/11/22	Yamasaki
*
*/


#pragma once

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"Data/ActionController/ActionController.h"
#include"Model/Character/EnemyCharacter/EnemyCharacter.h"



//===================================================================
// 待機の基底クラス(追跡優先順位は敵に合わせる)
//===================================================================
class CEnemyActionIdle :public CAction {
protected:
	//再生する規定フレーム数
	//(ループありのアニメーションみたいにフレームを繰り返す)
	int m_frame = 0;

	//現在のフレーム
	int m_currentFrame = 0;

	//待機中かどうかのフラグ	true...待機中
	bool m_isIdlering = false;

	//待機開始フラグ
	bool m_isIdleStart = false;

public:
	//コンストラクタ
	CEnemyActionIdle() {}

	// 再生フレームの設定
	void setFrame(int frame) { this->m_frame = frame; }

	/*
	* @desc 開始
	*/
	void start()override {
		this->m_isIdleStart = true;
	}

	/*
	*	@desc　待機
	*	@param 待機する敵のアドレス
	*/
	virtual void Idle(CCharacter* pChara) = 0;


	/*
	* @desc 更新処理
	* @param 待機を行うキャラクターのアドレス
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了
	*/
	void stop()override {
		this->m_isIdlering = false;
	}

	// フラグの取得
	bool getActionFlag() {
		return this->m_isIdlering;
	}
};


//===================================================================
// 待機中アニメも移動もなしクラス
//===================================================================
class CActionIdleStop : public CEnemyActionIdle {

	/*
	*	@desc アニメも移動もなしの待機
	*	@param 待機する敵のアドレス
	*/
	void Idle(CCharacter* pChara) {

		// 速度が0でなければ初期化する
		if (pChara->m_pMove->m_vel.x != 0.0f) {

			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_vel.y = 0.0f;
		}
	}
};

//===================================================================
// 待機中うろうろするクラス
//===================================================================
class CActionIdleMove : public CEnemyActionIdle {

	/*
	*	@desc　移動 + アニメもある待機
	　	*	@param 待機する敵のアドレス
		*/
	void Idle(CCharacter* pChara);
};




//===================================================================
// 待機中アニメーションだけあるクラス
//===================================================================
class CActionIdleAnimationOnly : public CEnemyActionIdle {

	/*
	*	@desc　アニメーションのみの待機
	*	@param 待機する敵のアドレス
	*/
	void Idle(CCharacter* pChara);
};