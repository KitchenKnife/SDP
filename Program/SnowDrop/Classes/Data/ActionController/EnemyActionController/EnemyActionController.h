/*
* EnemyActionController.h
*
*	2016/11/07	Yamasaki
*
*/


#pragma once

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"Data/ActionController/ActionController.h"

//class CCharacter;

//===================================================================
// 打撃攻撃
//		打撃攻撃に関する処理を行い内部処理としてＨＰデータに対して変更を加える
//===================================================================
class CEnemyAction :public CAction {


public:
	//コンストラクタ
	CEnemyAction() {}

	/*
	* @desc 開始
	*/
	virtual void start()override {
		CCLOG("this function is brank!!!!");
	};

	/*
	* @desc 開始
	* @param	攻撃されるキャラクターのステータス
	*/
	virtual void start(CStatus* pStatus , CCharacter* pChara =NULL ) = 0;

	/*
	* @desc 終了
	*/
	//void stop()override;



	// フラグの取得
	//virtual bool getActionFlag() = 0;
};

//===================================================================
// 打撃攻撃
//		打撃攻撃に関する処理を行い内部処理としてＨＰデータに対して変更を加える
//===================================================================
class CActionBlowAttack :public CEnemyAction {
protected:

	//攻撃を再生する規定フレーム数
	int m_frame = 180;

	//現在のフレーム
	int m_currentFrame = 0;

	//打撃攻撃中かどうかのフラグ	true...打撃攻撃中
	bool m_isBlowAttacking = false;

	//打撃攻撃開始フラグ
	bool m_isBlowAttackStart = false;

	// 攻撃されるキャラクターのステータスを保管する
	CStatus* m_pStatus;

	// 攻撃するキャラクターのアドレス
	CCharacter* m_pChara;

public:

	

	//コンストラクタ
	CActionBlowAttack() {}

	/*
	* @desc 打撃攻撃
	* @param 攻撃力
	* @param 攻撃されるキャラのステータス
	*/
	void blowHit(int attackPt, CStatus* pStatus) {

		// HP減少処理
		pStatus->decreaseHP(attackPt);

	}

	//void start()override{};
	/*
	* @desc 開始
	* @param	攻撃されるキャラクターのステータス
	*/
	void start(CStatus* pStatus, CCharacter* pChara = NULL)override{

		//ジャンプ開始
		this->m_isBlowAttackStart = true;

		// ステータス保管
		this->m_pStatus = pStatus;

		// 攻撃力を保管
		this->m_pChara = pChara;

	}
	

	/*
	* @desc 更新処理
	* @param 攻撃を行うキャラクターのアドレス
	* @param 攻撃されるキャラクターのステータス
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了
	*/
	void stop()override {

		//ジャンプ中フラグを下す
		this->m_isBlowAttacking = false;
	}



	// フラグの取得
	bool getActionFlag() override{
		return this->m_isBlowAttacking;
	}
};
