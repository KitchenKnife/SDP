#pragma once

/*
* PlayerWeaponFactory.h
*
*	2016/11/27	Osumi
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
/*
//クラスの前方宣言

//================================================
// 武器パーツ製造工場
//	（AbstractFactory）
//================================================
class CPlayerWeaponPartsFactory /*:public CCharacterPartsFactory*{
public:

	virtual ~CPlayerWeaponPartsFactory() {}

	//virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove();//override;
	//virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody();//override;
	virtual std::vector<cocos2d::Point*>* getPoints();
	virtual std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> getMapAnimations();
	virtual std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> getMapActions();
	virtual CStatus* getStatus();
	virtual std::vector<CCollisionArea* >* getCollisionAreas();

};


//================================================
// 武器の生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CPlayerWeaponFactory {
public:

	//パーツ製造工場群
	std::vector<CPlayerWeaponPartsFactory*>partsFactories{
		new CPlayerWeaponPartsFactory(),
		new CPlayerWeaponPartsFactory(),
	};

	~CPlayerWeaponFactory() {
		//パーツ製造工場群の解放
		for (CPlayerWeaponPartsFactory* pPartsfactory : partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//プレイヤーの生成と組み立て
	//派生先によって違うプレイヤーの生成
	virtual CPlayerWeapon* createWeapon() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CPlayerWeapon* pWeapon) = 0;
	//画像の設定
	virtual void settingTexture(CPlayerWeapon* pWeapon) = 0;
	//アニメーションの設定
	virtual void settingAnimations(CPlayerWeapon* pWeapon) = 0;
	//アクションの設定
	virtual void settingActions(CPlayerWeapon* pWeapon) = 0;
	//衝突判定データの設定
	virtual void settingBody(CPlayerWeapon* pWeapon) = 0;
	//衝突判定の基準点を設定
	virtual void settingPoints(CPlayerWeapon* pWeapon) = 0;
	//ステータスの設定
	virtual void settingStatus(CPlayerWeapon* pWeapon) = 0;


	//初期設定もろもろ
	virtual void settingInitialize(CPlayerWeapon* pWeapon) = 0;


	//プレイヤーの生成とセッティング
	CPlayerWeapon* create() {

		//プレイヤーの生成と組み立て
		CPlayerWeapon* pWeapon = this->createWeapon();

		//初期位置の設定
		this->settingMove(pWeapon);
		//テクスチャの設定
		this->settingTexture(pWeapon);
		//アニメーションの設定
		this->settingAnimations(pWeapon);
		//アクションの設定
		this->settingActions(pWeapon);
		//衝突判定用データの設定
		this->settingBody(pWeapon);
		//衝突判定の基準点を設定
		this->settingPoints(pWeapon);
		//ステータスの設定
		this->settingStatus(pWeapon);

		//初期化もろもろ
		this->settingInitialize(pWeapon);


		return pWeapon;
	}

};

//================================================
// 武器の生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerNormalWeaponCreateFactory :public CPlayerWeaponFactory {
public:

	//プレイヤーの生成と組み立て
	CPlayerWeapon* createWeapon()override;

};

//================================================
// 武器のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerNormalWeaponFactory :public CPlayerNormalWeaponCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerWeapon* pWeapon)override;
	//画像の設定
	void settingTexture(CPlayerWeapon* pWeapon)override;
	//アニメーションの設定
	void settingAnimations(CPlayerWeapon* pWeapon)override;
	//アクションの設定
	void settingActions(CPlayerWeapon* pWeapon)override;
	//衝突判定データの設定
	void settingBody(CPlayerWeapon* pWeapon)override;
	//衝突判定の基準点を設定
	void settingPoints(CPlayerWeapon* pWeapon)override;
	//ステータスの設定
	void settingStatus(CPlayerWeapon* pWeapon)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerWeapon* pWeapon)override;

};

/*
//================================================
// 武器の生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerNormalWeaponCreateFactory :public CPlayerWeaponFactory {
public:

	//プレイヤーの生成と組み立て
	CPlayerWeapon* createWeapon()override;

};

//================================================
// 武器のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerNormalWeaponFactory :public CPlayerNormalWeaponCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerWeapon* pWeapon)override;
	//画像の設定
	void settingTexture(CPlayerWeapon* pWeapon)override;
	//アニメーションの設定
	void settingAnimations(CPlayerWeapon* pWeapon)override;
	//アクションの設定
	void settingActions(CPlayerWeapon* pWeapon)override;
	//衝突判定データの設定
	void settingBody(CPlayerWeapon* pWeapon)override;
	//衝突判定の基準点を設定
	void settingPoints(CPlayerWeapon* pWeapon)override;
	//ステータスの設定
	void settingStatus(CPlayerWeapon* pWeapon)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerWeapon* pWeapon)override;

};
*

//================================================
// パーツセッティングクラス（CBasePlayerFactory）を管理するクラス
//	（FactoryMethod）
//================================================
//武器の種類
enum WEAPON_TYPE :int {
//	NONE = -1,
	NORMAL = 0,
	LARGE_SWORD = 1,
};

class CPlayerWeaponFactoryManager {
private:
	//コンストラクタ
	CPlayerWeaponFactoryManager() {
		// プレイヤー基本工場
		m_factories.push_back(new CPlayerNormalWeaponFactory());
		//m_factories.push_back(new CPlayerGirlFactory());
	}

	//共有のインスタンス
	static CPlayerWeaponFactoryManager* m_pPlayerWeaponFactoryManager;

public:
	//デストラクタ
	~CPlayerWeaponFactoryManager() {
		SAFE_DELETE(m_pPlayerWeaponFactoryManager);

		for (CPlayerWeaponFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//インスタンスの取得
	static CPlayerWeaponFactoryManager* getInstance();

	//プレイヤー工場群
	std::vector<CPlayerWeaponFactory*> m_factories;



	//プレイヤー工場のcreate()を呼び出す
	CPlayerWeapon* create(int type) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create();
	}

};

*/
