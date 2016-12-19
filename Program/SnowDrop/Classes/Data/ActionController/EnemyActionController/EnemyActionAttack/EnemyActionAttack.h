/*
* EnemyActionAttack.h
*
*	2016/11/07	Yamasaki
*
*/


#pragma once

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"Data/ActionController/ActionController.h"
#include "Model/Character/Factory/EnemyFactory.h"

//===================================================================
// コウモリ用　アクション管理クラス
//===================================================================
class CBatActionManager : public CAction {
private:
	// 開始
	bool m_isStart = false;

	bool m_inAction = false;


	virtual ~CBatActionManager() {}
	/*
	*	@desc アクションを開始するたびに呼び出す
	*	@param	変更したいステータスがある場合に使う
	*/
	virtual void start() {
		this->m_isStart = true;
	}

	//アクションの更新処理
	virtual void update(CCharacter* pChara) {



	}
	//アクションを終了するたびに呼び出す
	virtual void stop() {

	}

	// アクションフラグの取得
	virtual bool getActionFlag() {

	}
};


//===================================================================
// 攻撃
//		攻撃に関する処理を行う
//===================================================================
class CEnemyActionAttack :public CAction {
protected:

	//攻撃を再生する規定フレーム数
	int m_frame = 180;

	//現在のフレーム
	int m_currentFrame = 0;


	//攻撃中かどうかのフラグ	true...攻撃中
	bool m_isAttacking = false;

	//攻撃開始フラグ
	bool m_isAttackStart = false;

public:
	//コンストラクタ
	CEnemyActionAttack() {}
	// デストラクタ
	~CEnemyActionAttack(){}

	// フレーム設定
	void setFrame(int frame) { this->m_frame = frame; }


	/*
	* @desc 開始
	* @param	攻撃されるキャラクターのステータス
	*/
	void start()override {

		//開始
		this->m_isAttackStart = true;

	}

	/*
	*	@desc 攻撃方法
	*	@param 攻撃するキャラクター
	*/
	virtual void attack(CCharacter* pChara) = 0;


	/*
	* @desc 更新処理
	* @param 攻撃を行うキャラクターのアドレス
	*/
	void update(CCharacter* pChara);



	/*
	* @desc 終了
	*/
	void stop()override {

		//ジャンプ中フラグを下す
		this->m_isAttacking = false;
	}



	// フラグの取得
	bool getActionFlag() {
		return this->m_isAttacking;
	}
};

//======================================
// 打撃
//======================================
class CEnemyBrowAttack : public CEnemyActionAttack {

public:

	~CEnemyBrowAttack(){}


	void attack(CCharacter* pChara) {

		pChara->m_pStatus->decreaseHP(1);
	}
};

//======================================
// 遠距離
//======================================
class CEnemyAttack : public CEnemyActionAttack {

public:
	~CEnemyAttack(){}


	void attack(CCharacter* pChara) {}
};

//======================================
// BOSS1 腕回し
//======================================
class CEnemyBOSS1Attack : public CEnemyActionAttack {

public:

	~CEnemyBOSS1Attack(){}

	void attack(CCharacter* pChara);
};


//======================================
// BOSS1 クエイク
//======================================
class CEnemyBOSS1AttackQuake : public CEnemyActionAttack {

public:

	~CEnemyBOSS1AttackQuake(){}
	void attack(CCharacter* pChara);
};