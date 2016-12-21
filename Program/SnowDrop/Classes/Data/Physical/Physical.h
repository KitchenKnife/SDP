/*
 * Physical.h
 *
 *	2016/11/07	Osumi
 *
 */
#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"Data/Move/Move.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　物理演算クラス
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class CPhysical {
public:
	//デストラクタ
	virtual ~CPhysical(){}

	//更新処理
	virtual void update(CMove* pMove) = 0;
};


//=====================================
// 重力に基づいた速度計算に関するコードの追加はここから
//=====================================
class CPhysicalGravity : public CPhysical {
public:
	//デストラクタ
	virtual ~CPhysicalGravity(){}

	//重力係数
	constexpr static const float GRAVITY = -0.5f;

	//更新処理
	void update(CMove* pMove)override {

		//y軸の速度(重力計算)
		pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
	}
};


//=====================================
// 摩擦係数に基づいた速度計算に関するコードの追加はここから
//=====================================
class CPhysicalFriction : public CPhysical {
protected:
	//個々の摩擦係数
	float m_personalFriction = 0.0f;
	
	//最高速度
	float m_maxSpeed = 0.0f;

public:
	//全体の摩擦係数
	constexpr static const float FRICTION = 0.3f;

	//デフォルトコンストラクタ
	CPhysicalFriction(){}

	//コンストラクタ（各種設定）
	CPhysicalFriction(float maxSpeed,float friction)
		:m_maxSpeed(maxSpeed),m_personalFriction(friction){}

	/**
	 * @desc	最高速度と個々の摩擦係数の設定
	 * @param	最高速度
	 * @param	個々の摩擦係数
	 */
	void set(float maxSpeed, float friction) {
		m_maxSpeed = maxSpeed;
		m_personalFriction = friction;
	}

	/**
	 * @desc	更新処理（摩擦計算）
	 */
	void update(CMove* pMove)override {
		//摩擦
		float friction = 0.0f;

		//右に移動していたら
		if (pMove->m_vel.x > this->m_personalFriction) {
			friction = - this->m_personalFriction;
		}else if(pMove->m_vel.x > 0){
			//速度が摩擦係数以下になったら
			//摩擦　-　速度　＝0
			//になるようにする
			friction = -pMove->m_vel.x;
		}

		//左に移動していたら
		if (pMove->m_vel.x < -this->m_personalFriction) {
			friction = this->m_personalFriction;
		}
		else if (pMove->m_vel.x < 0) {
			//摩擦　-　速度　＝0
			friction = -pMove->m_vel.x;
		}

		//x軸の速度を計算（摩擦計算）
		pMove->m_vel.x += pMove->m_accele.x + friction;
	

		//ｘ軸の最高速度を計算
		if (pMove->m_vel.x < -this->m_maxSpeed) {
			pMove->m_vel.x = -this->m_maxSpeed;
		}else if (pMove->m_vel.x > this->m_maxSpeed) {
			pMove->m_vel.x = this->m_maxSpeed;
		}
	}
};