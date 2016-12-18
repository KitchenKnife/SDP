#pragma once
/*
* EnemyActionPursuit.h
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
// 追跡の基底クラス(追跡優先順位は敵に合わせる)
//===================================================================
class CEnemyActionPursuit :public CAction {
protected:

	//追跡中かどうかのフラグ	true...追跡中
	bool m_isPursuiting = false;

	//追跡開始フラグ
	bool m_isPursuitStart = false;

public:
	//コンストラクタ
	CEnemyActionPursuit() {}

	/*
	* @desc 開始
	*/
	void start()override {
		this->m_isPursuitStart = true;
	}

	/*
	*	@desc　追跡
	*	@param 追跡する敵のアドレス
	*/
	virtual void pursuit(CCharacter* pChara) = 0;

	/*
	* @desc 更新処理
	* @param 追跡を行う敵キャラクターのアドレス
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了
	*/
	void stop()override {
		this->m_isPursuiting = false;
	}

	// フラグの取得
	bool getActionFlag() {
		return this->m_isPursuiting;
	}
};

//===================================================================
// 近いプレイヤー優先の追跡クラス
//===================================================================
class CActionPursuitNear : public CEnemyActionPursuit {
public:
	CActionPursuitNear() {}

	~CActionPursuitNear() {}
	/*
	*	@desc　追跡
	*	@param 追跡する敵のアドレス
	*/
	void pursuit(CCharacter* pChara);
};


//===================================================================
// 少女優先の追跡クラス
//===================================================================
class CActionPursuitGirlPriority : public CEnemyActionPursuit {
public:
	CActionPursuitGirlPriority() {}
	~CActionPursuitGirlPriority() {}


	/*
	*	@desc	振り子運動
	*	@param	振り子運動するキャラ
	*	@param	振り子運動の中心点
	*	@param	振り子幅
	*	@param	振り子の高さ
	*	@param	振り子の速さ（デフォルトは1）
	*/
	void swing(CCharacter* chara, cocos2d::Point pt, float width, float height, float spped = 1) {

		static float degX = 270;
		static float degY = 180;

		chara->m_pMove->m_pos.x = width* sin(degX) + pt.x;
		chara->m_pMove->m_pos.y = height * sin(degY) + pt.y;
	}

	/*
	*	@desc 少女を追跡
	*	@param 追跡する敵のアドレス
	*/
	void pursuit(CCharacter* pChara);
};

//===================================================================
// 少女のみ追跡クラス
//===================================================================
class CActionPursuitGirlOnly : public CEnemyActionPursuit {
public:
	CActionPursuitGirlOnly() {}
	~CActionPursuitGirlOnly() {}
	/*
	*	@desc　追跡
	*	@param 追跡する敵のアドレス
	*/
	void pursuit(CCharacter* pChara);
};


//===================================================================
// 近いプレイヤーの方向を向くだけの追跡クラス
//===================================================================
class CActionPursuitDirection : public CEnemyActionPursuit {
public:
	CActionPursuitDirection() {}
	~CActionPursuitDirection() {}

	/*
	*	@desc　追跡
	*	@param 追跡する敵のアドレス
	*/
	void pursuit(CCharacter* pChara);
};