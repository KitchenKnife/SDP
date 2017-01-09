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
#include "Model\Character\DamageCharacter\DamageCharacter.h"

using namespace cocos2d;

// 前方宣言
class CCharacter;
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

//=========================================================================
//　ダメージ出撃データ
//=========================================================================
class CDamageLaunchData {
public:
	//攻撃を行うキャラクター（ダメージを出現させるキャラ）
	CCharacter* m_pChara;

	//出現させる位置
	cocos2d::Point m_pos;

	// 何フレーム存在させるか
	int m_activeFrame;

	//ダメージタイプ
	DAMAGE_TYPE m_type;

	//コンストラクタ
	CDamageLaunchData(CCharacter* pChara,cocos2d::Point pos,int activeFrame, DAMAGE_TYPE type = DAMAGE_TYPE::NONE)
		:m_pChara(pChara) ,m_pos(pos) ,m_activeFrame(activeFrame),m_type(type){}

};