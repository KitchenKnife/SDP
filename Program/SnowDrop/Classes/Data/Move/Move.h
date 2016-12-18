
/*
* Move.h
*
*	2016/11/07	Osumi
*
*/
#pragma once

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"cocos2d.h"
#include"Constants.h"

using namespace cocos2d;

//=====================================
// 移動データ
//=====================================
class CMove {
public:
	//位置
	Vec2 m_pos;
	//速度
	Vec2 m_vel;
	//加速度
	Vec2 m_accele;
	//速さ
	float m_speed;

	//位置の設定
	void setPos(float xx, float yy) {
		m_pos.set(xx, yy);
	}

	//速度の設定
	void setVel(float xx, float yy) {
		m_vel.set(xx, yy);
	}

	/**
	* @desc 移動
	*/
	virtual void moveBy() {

		//速度による移動
		m_pos += m_vel;
	}
};


