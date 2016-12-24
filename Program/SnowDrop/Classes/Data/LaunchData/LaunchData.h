/*
* EnemyLaunchData.h
*
*	2016/11/07	Osumi
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Map/Map.h"

using namespace cocos2d;

//=========================================================================
//　敵出撃データ
//=========================================================================
class CEnemyLaunchData {
public:
	//敵のタイプ
	ENEMY_TYPE m_type;
	//出撃位置
	Point m_pos;

	//コンストラクタ
	CEnemyLaunchData(ENEMY_TYPE type, Point pos)
		:m_type(type),m_pos(pos){}

};

//=========================================================================
//　ギミック出撃データ
//=========================================================================
class CGimmickLaunchData {
public:
	//弾のタイプ
	GIMMICK_TYPE m_type;
	//発射位置
	cocos2d::Point m_pos;

	//コンストラクタ
	CGimmickLaunchData(GIMMICK_TYPE type, cocos2d::Point pos) {

		this->m_type = type;
		this->m_pos = pos;
		
	}

};


//=========================================================================
//　エフェクト出撃データ
//=========================================================================
class CEffectLaunchData {
public:
	//エフェクトのタイプ
	EFFECT_TYPE m_type;
	//出現位置
	cocos2d::Point m_pos;

	//コンストラクタ
	CEffectLaunchData(EFFECT_TYPE type, cocos2d::Point pos) {

		this->m_type = type;
		this->m_pos = pos;

	}

};