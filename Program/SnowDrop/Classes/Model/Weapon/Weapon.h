
/*
* weapon.h
*
*	2016/11/26	Osumi
*
*/
#pragma once

#include "Model/Character/PlayerCharacter.h"
#include "cocos2d.h"

//================================================
//
//　武器の抽象クラス
//
//================================================
class CWeapon :public CCharacter {
public:

	//コンストラクタ
	CWeapon();

	//デストラクタ
	virtual ~CWeapon();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update();

	//アニメーションデータ群
	//std::vector<CAnimation* >* m_pAnimations = NULL;

	//行えるアクション群
	//std::vector<CAction* >* m_pActions = NULL;

	//移動データ
	//CMove* m_pMove = NULL;

	//実体の基準点
	std::vector<cocos2d::Point*>* m_pBasePoints = NULL ;

	//実体データ群
	//std::vector<CBody* >* m_pBodies = NULL;
	//CBody* m_pBody = NULL;

	// ステータス
	//CStatus* m_pStatus = NULL;

	//有効フラグ
	//bool m_activeFlag = false;

protected:

	//移動処理
	//virtual void moveFunc() = 0;

	//アニメーション処理
	//virtual void animationFunc() = 0;

	//状態チェック
	//virtual void checkState() = 0;

	//反映処理
	//virtual void applyFunc() = 0;

public:
	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	//virtual bool collision(CCharacter* pChara) = 0;

};