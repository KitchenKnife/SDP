#pragma once
#include <math.h>
#include <stdio.h>
#include "cocos2d.h"
#include "Constants.h"

//=================================
//　前方宣言
//=================================
class CCharacter;
class CEnemyCharacter;

//-------------------------------------------------------
//  math.h  演算クラスファイル
//  12/27
//		Author	Keita Osumi
//------------------------------------------------------
//演算クラス
class CCustomMath {
private:
	//コンストラクタ
	CCustomMath();

	//共有インスタンス
	static CCustomMath* m_pSharedCustomMath;

public:
	//デストラクタ
	~CCustomMath();

	//ターゲットの種類
	enum class TARGET_TYPE :int {
		NONE,
		BOY,
		GIRL,
		BOTH
	};

	//インスタンスの取得
	static CCustomMath* getInstance();

	//インスタンスの破棄
	static void removeInstance();

	/*
	* @desc 2点間の距離を求める式
	* @param 点1
	* @param 点2
	* @return 点1と点2の距離
	*/
	virtual float length(cocos2d::Point pt1, cocos2d::Point pt2);

	/*
	* @desc 2体のキャラの距離を求める式
	* @param　キャラ1
	* @param　キャラ2
	* @return キャラ1とキャラ2の距離
	*/
	virtual float lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2);

	/*
	* @desc ターゲットの探索と選択
	* @param アクションを行うキャラクター
	* @return ターゲットが決まったかどうか　true...決まった
	* @tips 少女と騎士で敵に近い方の距離を導き
	*　　　 近い方が追跡範囲にならターゲットに設定
	*/
	virtual bool seachAndSelectTarget(CCharacter* pChara);

	/*
	* @desc ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
	* @param アクションを行うキャラクター
	* @param ターゲットのタイプ
	*/
	virtual void checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type);

	/*
	* @desc キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
	* @param アクションを行うキャラクター
	* @param 目標地点の座標
	*/
	virtual void normalizeVel_X(CCharacter* pChara, cocos2d::Point pt);

	/*
	* @desc 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
	* @param アクションを行うキャラクター
	* @param 目標地点の座標
	*/
	virtual void normalizeVel(CCharacter* pChara, cocos2d::Point pt);

};

//インスタンスの取得のマクロ
#define customMath (CCustomMath::getInstance())

