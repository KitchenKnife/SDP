/*
* EnemyActionDamage.h
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
// ダメージを受けた時の基底クラス(追跡優先順位は敵に合わせる)
//===================================================================
class CEnemyActionDamage :public CAction {
protected:

	//ダメージ中かどうかのフラグ	true...待機中
	bool m_isDamaging = false;

	//ダメージ開始フラグ
	bool m_isDamageStart = false;

public:
	//コンストラクタ
	CEnemyActionDamage() {}

	/*
	* @desc 開始
	*/
	void start()override {
		this->m_isDamageStart = true;
	}

	/*
	*	@desc　ダメージを受ける
	*	@param ダメージを受ける敵のアドレス
	*/
	virtual void Damage(CCharacter* pChara) = 0;


	/*
	* @desc 更新処理
	* @param ダメージを受ける敵のアドレス
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了
	*/
	void stop()override {
		this->m_isDamaging = false;
	}

	// フラグの取得
	bool getActionFlag() {
		return this->m_isDamaging;
	}
};

//===================================================================
// ダメージを受けて停止するクラス
//===================================================================
class CActionDamageStop : public CEnemyActionDamage {

	/*
	*	@desc　ダメージを受けて停止する
	*	@param ダメージを受ける敵のアドレス
	*/
	void Damage(CCharacter* pChara);
};


//===================================================================
// ダメージを受けて後ずさるクラス(後ろにズサー的な)
//===================================================================
class CActionDamageBack : public CEnemyActionDamage {

	/*
	*	@desc ダメージを受けて後ずさる
	*	@param ダメージを受ける敵のアドレス
	*/
	void Damage(CCharacter* pChara);
};

//===================================================================
// ダメージ中アニメーションだけあるクラス（移動or攻撃可能）
//===================================================================
class CActionDamageAnimationOnly : public CEnemyActionDamage {

	/*
	*	@desc　ダメージ中アニメーションのみ
	*	@param ダメージを受ける敵のアドレス
	*/
	void Damage(CCharacter* pChara);
};

//===================================================================
// ダメージも変化がないクラス（移動or攻撃可能）
//===================================================================
class CActionDamageNone : public CEnemyActionDamage {

	/*
	*	@desc　ダメージ中も見た目に変化がない
	*	@param ダメージを受ける敵のアドレス
	*/
	void Damage(CCharacter* pChara);
};