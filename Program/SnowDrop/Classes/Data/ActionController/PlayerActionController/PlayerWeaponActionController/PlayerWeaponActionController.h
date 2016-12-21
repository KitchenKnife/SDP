#pragma once

/*
* PlayerWeaponActionController.h
*
*	2016/11/27	Osumi
*
*/

#include "Data/ActionController/ActionController.h"
/*
class CPlayerWeapon;
class CPlayerBoy;
//class CPlayerCharacter;

//===================================================================
//
//	武器攻撃の抽象クラス
//　　プレイヤーの動きも担う
//
//===================================================================

class CPlayerWeaponAttack :public CAction {
public:

	//コンストラクタ
	CPlayerWeaponAttack();

	//少年のインスタンス
	CPlayerBoy* m_pBoy = NULL;// = NULL;

	//武器のインスタンス
	CPlayerWeapon* m_pWeapon = NULL;// = NULL;

	//入力受付時間
	//int m_delayTime = 50;

	//入力受付カウンター
	int m_delayCounter = 0;

	//次のアクションに移行するかどうかのフラグ
	bool m_nextActionFlag = false;

	//１個のアクションが終わったかどうか true...終わってる
	//bool m_isAttackEnd = false;

	virtual ~CPlayerWeaponAttack() {}
	//アクションを開始するたびに呼び出す
	void start()override {};
	//アクションの更新処理
	virtual void update(CCharacter* pChara) {};
	//アクションを終了するたびに呼び出す
	virtual void stop() override {};

};


class CPlayerNoneWeaponAction :public CPlayerWeaponAttack {
public:

	virtual ~CPlayerNoneWeaponAction() {}
	//アクションを開始するたびに呼び出す
	void start()override {};
	//アクションの更新処理
	virtual void update(CCharacter* pChara) override {};
	//アクションを終了するたびに呼び出す
	virtual void stop() override {};

};

//===================================================================
//	斬撃アクション＿01	
//===================================================================
class CNormalSlashAttack_01 :public CPlayerWeaponAttack {
protected:

	//基準方向
	int m_attackVec = 0;

	//持ち上げ段階
	//  0...斬撃　1-1
	//　1...斬撃　1-2
	//　2...斬撃　1-3

	int m_attackStep = 0;

	//入力受付時間
	const int m_delayTime = 20;

public:
	

	//コンストラクタ
	CNormalSlashAttack_01() {}

	/*
	* @desc 開始処理
	*
	void start()override;

	/*
	* @desc 更新処理（ジャンプ移動計算）
	* @param 対象のキャラクター
	*
	void update(CCharacter* pChara)override;

	/*
	* @desc 終了処理
	*
	void stop()override;

};




*/