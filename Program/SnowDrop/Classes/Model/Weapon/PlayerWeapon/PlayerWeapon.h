
/*
* PlayerWeapon.h
*
*	2016/11/26	Osumi
*
*/
#pragma once

#include "Model/Weapon/Weapon.h"
#include "cocos2d.h"
#include "Lib/Input/InputManager.h"

class CPlayerWeaponAttack;

//武器の状態
enum class PLAYER_WEAPON_STATE :int {

	NONE = -1,  //無し
	RETURN,    //納刀
	DRAWN,	   //抜刀
	ATTACK,    //攻撃

};

//================================================
//
//　プレイヤーの武器基底クラス
//
//================================================
class CPlayerWeapon :public CWeapon {
	
	

	//================================================
	//　変数
	//================================================
public:

	//二重押し防止フラグ
	bool m_zKeyDown = true;

	//武器の装備位置
	cocos2d::Point m_offset;


	//攻撃アニメ
	enum class ATTACK_ANIME :int {

		NONE = -1,		//無し
		RETURN,			//納刀
		DRAWN,			//抜刀
		SLASH_01_1,     //斬撃01_1
		SLASH_01_2,     //斬撃01_2
		SLASH_01_3,     //斬撃01_3

	};

	//攻撃アクション
	enum class ATTACK_ACT :int {

		NONE = -1,		//無し
		DRAWN,			//抜刀
		SLASH_01,       //斬撃01

	};

	//攻撃アニメ
	ATTACK_ANIME m_attackAnime = ATTACK_ANIME::RETURN;
	//攻撃アクション
	ATTACK_ACT m_attackAct = ATTACK_ACT::NONE;

	//================================================
	//　関数
	//================================================
public:

	//コンストラクタ
	CPlayerWeapon();

	//デストラクタ
	virtual ~CPlayerWeapon();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update()override;

	//状態のチェック
	virtual void checkState();

	//武器の納刀
	virtual void returnSword();

	//武器の取り付け
	virtual void addChildPlayer(CPlayerCharacter* pChara) = 0;
	
	//レイヤーからの取り外し
	void removeFromeLayer();

	//武器の状態
	//PLAYER_WEAPON_STATE m_state = PLAYER_WEAPON_STATE::RETURN;

	//アニメーションデータ群(map)
	std::map<ATTACK_ANIME, CAnimation* > m_mapAnimations;
	//行えるアクション群(map)
	std::map<ATTACK_ACT, CPlayerWeaponAttack* > m_mapActions;

protected:

	//移動処理
	virtual void moveFunc()override;

	//アニメーション処理
	virtual void animationFunc()override;

	//アクション処理
	virtual void actionFunc();

	//入力処理
	virtual void inputFunc();

public:

	//反映処理
	virtual void applyFunc()override;

	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	//virtual bool collision(CCharacter* pChara) = 0;

};

//================================================
//
//　プレイヤーの通常武器クラス
//
//================================================
class CPlayerNormalWeapon :public CPlayerWeapon {

private:

	//コンストラクタ
	CPlayerNormalWeapon();

	//共有インスタンス
	static CPlayerNormalWeapon* m_pPlayerWeapon;

public:

	//インスタンスの取得
	static CPlayerNormalWeapon* getInstance();

	//インスタンスの解放
	static void removeInstance();

	//武器のレイヤーへの取り付け
	void addChildPlayer(CPlayerCharacter* pChara)override;

	//デストラクタ
	virtual ~CPlayerNormalWeapon();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update()override;

	

	//CREATE_FUNC(CPlayerNormalWeapon);

	static CPlayerNormalWeapon* create() {
		CPlayerNormalWeapon* pRet = new(std::nothrow) CPlayerNormalWeapon();

		if (pRet && pRet->init()) {
			pRet->autorelease();
			return pRet;
		}
		else {
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

protected:

	//移動処理
	//virtual void moveFunc()override;

	//アニメーション処理
	virtual void animationFunc()override;

	//状態チェック
	//virtual void checkState()override {};

	/**
	* @desc 衝突判定処理
	*/
	void collisionAll()override {};

public:
	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override {
		return true;
	};

	void hits(CCharacter* pChara)override{}

};