
/*
* PlayerCharacter.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//================================================
//　追加のインクルードはここから
//================================================
#include "../Character.h"
//#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include <map>


//================================================
//　クラスの前方宣言はここから
//================================================
class CPlayerFactoryManager;
class CPlayerEffect;
class CPlayerWeapon;

//================================================
// プレイヤーキャラクタークラス
//		今回は更新処理も内部で行われるので
//		入力処理も内部で行い
//		入力による移動処理というカテゴリで扱いう
//================================================
class CPlayerCharacter :public CCharacter {

public:

	//コンストラクタ
	CPlayerCharacter();

	//デストラクタ
	~CPlayerCharacter();

	//初期化処理
	bool init()override;

	//CREATE_FUNC(CPlayerCharacter);

	//================================================
	// 
	//	定数に関するコードの追加はここから
	//			
	//================================================
	
	
	//プレイヤーの状態
	enum class STATE :int {
		NONE = -1,
		STAND = 0,
		JUMPING =0,
		WALK =1,
		HIT = 2,
		FALING = 3,
		//RETURN_WEAPON ,	//納刀
		DRAWN_STAND,		//抜刀立ち
		DRAWN_WALK,			//抜刀歩き
		SLASH_ATTACK_01_1,	//斬撃1_1
		SLASH_ATTACK_01_2,	//斬撃1_2
		SLASH_ATTACK_01_3,	//斬撃1_3

		LIFT_UPING,

		WASTE,		//暇つぶし
		WASTE_ANIME_01,
		WASTE_ANIME_02,
		WASTE_ANIME_03,

	};
	
	//プレイヤーが行えるアクション
	enum class ACTION :int {
		NONE = -1,
		JUMP = 0,
		ATTACK = 1 ,

		LIFT_UP,

		WASTE,		//暇つぶし
		WASTE_ACT_01,
		WASTE_ACT_02,
		WASTE_ACT_03,

	};

	//エフェクトタイプ
	enum class EFFECT {
		NONE = -1,
		DISAPPEAR,
		DAMAGE,
	};

	//================================================
	// 
	//	メンバに関するコードの追加はここから
	//		
	//		
	//================================================

	//プレイヤーの状態
	STATE m_playerState = STATE::FALING;
	//プレイヤーのアクション状態
	ACTION m_playerAct = ACTION::NONE;

	//アニメーション群（map）
	std::map<STATE, CAnimation*> m_mapAnimations;
	//アクション群（map）
	std::map<ACTION, CAction*> m_mapActions;
	//エフェクト群（map）
	std::vector<CPlayerEffect*>* m_pEffects = NULL;

	//武器
	CPlayerWeapon* m_pWeapon = NULL;

	//手つなぎフラグ
	//true...手をつないでる
	bool m_isShakeHands = false;

	//更新処理
	virtual void update(float deltaTime)override;

	//エフェクトのプレイヤーへの取り付け
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType) = 0;

	//武器の装備
	virtual void equipWeapon() = 0;

	/**
	* @desc 手をつなげる状態かチェック
	* @param 相方（少女）の座標
	* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
	*/
	void checkSakeHands(CPlayerCharacter* pCharacter);

	//移動処理
	virtual void moveFunc()override {};

	//アニメーション処理
	virtual void animationFunc()override;

	//画面範囲外判定処理
	//virtual void endOfScreen()override;

	//状態チェック
	virtual void checkState() override {};

	//反映処理
	virtual void applyFunc() override;

	//エフェクトの更新処理
	virtual void effectUpdate();
	
	//有効フラグの確認とその後の処理
	virtual void checkActiveFlagAndFunc();

	//エフェクトの取り外し
	void removeEffect(CPlayerEffect* pEffect);

	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc 衝突判定処理
	*/
	void collisionAll()override;
	
};


//================================================
// 少年クラス
//================================================
class CPlayerBoy :public CPlayerCharacter {

private:
	//コンストラクタ
	CPlayerBoy();

	//共有インスタンス
	static CPlayerBoy* m_pBoy;

	//CREATE_FUNC(CPlayerBoy);

	//消失フラグ true...消え始メル
	//bool m_disappearFlag = false;

public:
	static CPlayerBoy* create() {
		CPlayerBoy* pRet = new(std::nothrow) CPlayerBoy();

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

	//インスタンスの取得
	static CPlayerBoy* getInstance();

	//インスタンスの破棄
	static void removeInstnace() {
		//SAFE_DELETE(CPlayerBoy::m_pBoy);
	}

	//デストラクタ
	~CPlayerBoy();

	//初期化処理
	bool init()override;

	//================================================
	// 
	//	定数に関するコードの追加はここから
	//		
	//		
	//================================================

	//発射間隔
	const static int m_disappearInterval = 60;
	//発射カウンター
	int m_disappearCounter = 0;

	

	//================================================
	// 
	//	メンバに関するコードの追加はここから
	//		
	//		
	//================================================
	//エフェクトのプレイヤーへの取り付け
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType)override;

	//武器の装備
	virtual void equipWeapon()override;

	//少女との距離
	float lengthFromGirl();

	//消失状態のチェック（カウンターのデクリメントも担当）
	void checkDisappear();

	//移動処理
	void moveFunc()override;

	//状態チェック
	virtual void checkState() override;

	//更新処理
	void update(float deltaTime)override;

	void hits(CCharacter* pChara)override{}

	/**
	* @desc 入力処理
	* @tips 移動処理で呼び出す
	*/
	void inputFunc();

	//入力受付拒否フラグ true...入力処理を受け付けない
	bool m_nonInputFlag = false;

	//二重押し防止フラグ
	bool m_spaceKeyDown = false;
	bool m_zKeyDown = false;

	/**
	* @desc 手をつなげる状態かチェック
	* @param 相方（少女）の座標
	* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
	*/
	void checkSakeHands(CPlayerCharacter* pCharacter);
	
	/**
	* @desc お互いの手を放す
	*/
	void removeHands();

	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	*		　画面下の際は0
	*/
	virtual void collisionBottomCallback(int event) {
		this->m_mapActions[ACTION::JUMP]->stop();
	}

};


//================================================
// 少女クラス
//================================================
class CPlayerGirl :public CPlayerCharacter {


private:
	//コンストラクタ
	CPlayerGirl();

	//共有インスタンス
	static CPlayerGirl* m_pGirl;

	//CREATE_FUNC(CPlayerGirl);
	

public:
	static CPlayerGirl* create() {
		CPlayerGirl* pRet = new(std::nothrow) CPlayerGirl();

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

	//インスタンスの取得
	static CPlayerGirl* getInstance();

	//インスタンスの破棄
	static void removeInstnace() {
		//SAFE_DELETE(CPlayerGirl::m_pGirl);
	}

	//デストラクタ
	~CPlayerGirl();

	//初期化処理
	bool init()override;



	//================================================
	// 
	//	定数に関するコードの追加はここから
	//		
	//		
	//================================================

	//暇つぶし行動の時間
	const int m_wasteTime = 120;
	//暇つぶしアクション中にインクリメント
	int m_wasteActCounter = 0;

	//暇つぶししてるかどうか (true...暇つぶししてる)
	bool m_wasteActFlag = false;

	//================================================
	// 
	//	メンバに関するコードの追加はここから
	//		
	//		
	//================================================

	//移動処理
	virtual void moveFunc()override;

	//状態チェック
	virtual void checkState() override;

	//更新処理
	void update(float deltaTime)override;

	//エフェクトのプレイヤーへの取り付け
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType){}

	//武器の装備
	virtual void equipWeapon(){}

	/**
	* @desc 少年に向かってい近づく処理
	* @param	少年の位置
	*/
	void closeWithBoyFunc(Point* pPos);

	/**
	* @desc 少年についていく処理
	* @param	少年の位置
	*/
	void goWithBoyFunc(Point* pPos);


	void hits(CCharacter* pChara)override{}
};

