/*
* PlayerFactory.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//#include "Character.h"
#include "PlayerCharacter.h"

class CPlayerWeapon;
class CCollisionArea;
//クラスの前方宣言

//================================================
// キャラクターパーツ製造工場
//	（AbstractFactory）
//================================================
class CPlayerPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CPlayerPartsFactory() {}

	//virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove();//override;
	virtual std::vector<CPhysical* >* getPhysicals();//override;
	//virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody();//override;
	std::vector<CCollisionArea* >* getCollisionAreas();

	virtual std::map<CPlayerCharacter::STATE, CAnimation*> getMapAnimations();
	virtual std::map<CPlayerCharacter::ACTION, CAction*> getMapActions();
	virtual std::vector<CPlayerEffect*>* getEffects();
	virtual CPlayerWeapon* getWeapon();

	virtual CStatus* getStatus();
	
};


//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CPlayerFactory  {
public:

	//パーツ製造工場群
	std::vector<CPlayerPartsFactory*>partsFactories{
		new CPlayerPartsFactory(),
		new CPlayerPartsFactory(),
	};

	~CPlayerFactory() {
		//パーツ製造工場群の解放
		for (CPlayerPartsFactory* pPartsfactory: partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//プレイヤーの生成と組み立て
	//派生先によって違うプレイヤーの生成
	virtual CPlayerCharacter* createPlayer() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CPlayerCharacter* pCharacter) = 0;

	//画像の設定
	virtual void settingTexture(CPlayerCharacter* pCharacter) = 0;

	//アニメーションの設定
	virtual void settingAnimations(CPlayerCharacter* pCharacter) = 0;

	//適用する物理計算の設定
	virtual void settingPhysicals(CPlayerCharacter* pCharacter) = 0;

	//アクションの設定
	virtual void settingActions(CPlayerCharacter* pCharacter) = 0;

	//衝突判定データの設定
	virtual void settingBody(CPlayerCharacter* pCharacter) = 0;
	//衝突判定空間
	virtual void settingCollisionArea(CPlayerCharacter* pCharacter) = 0;

	//ステータスの設定
	virtual void settingStatus(CPlayerCharacter* pCharacter) = 0;

	//エフェクトの設定
	virtual void settingEffects(CPlayerCharacter* pCharacter) = 0;

	//武器の設定
	virtual void settingWeapon(CPlayerCharacter* pCharacter) = 0;


	//初期設定もろもろ
	virtual void settingInitialize(CPlayerCharacter* pCharacter) = 0;

	
	//プレイヤーの生成とセッティング
	CPlayerCharacter* create() {

		//プレイヤーの生成と組み立て
		CPlayerCharacter* pCharacter = this->createPlayer();

		//初期位置の設定
		this->settingMove(pCharacter);
		//テクスチャの設定
		this->settingTexture(pCharacter);
		//アニメーションの設定
		this->settingAnimations(pCharacter);
		//適用する物理計算の設定
		this->settingPhysicals(pCharacter);
		//アクションの設定
		this->settingActions(pCharacter);
		//衝突判定用データの設定
		this->settingBody(pCharacter);
		//衝突判定空間
		this->settingCollisionArea(pCharacter);
		//エフェクトの設定
		this->settingEffects(pCharacter);
		//ステータスの設定
		this->settingStatus(pCharacter);
		//武器の設定
		this->settingWeapon(pCharacter);

		//初期化もろもろ
		this->settingInitialize(pCharacter);
		

		return pCharacter;
	}

};

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerBoyCreateFactory :public CPlayerFactory {
public:

	//プレイヤーの生成と組み立て
	CPlayerCharacter* createPlayer()override;

};

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerBoyFactory :public CPlayerBoyCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerCharacter* pCharacter)override;
	//画像の設定
	void settingTexture(CPlayerCharacter* pCharacter)override;
	//アニメーションの設定
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	//適用する物理計算の設定
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	//アクションの設定
	void settingActions(CPlayerCharacter* pCharacter)override;
	//衝突判定データの設定
	void settingBody(CPlayerCharacter* pCharacter)override;
	//衝突判定空間
	void settingCollisionArea(CPlayerCharacter* pCharacter)override;
	//ステータスの設定
	void settingStatus(CPlayerCharacter* pCharacter)override;
	//エフェクトの設定
	void settingEffects(CPlayerCharacter* pCharacter)override;
	//武器の設定
	void settingWeapon(CPlayerCharacter* pCharacter)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerCharacter* pCharacter)override;

};

//================================================
// 女の子の生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerGirlCreateFactory :public CPlayerFactory {
public:

	//プレイヤーの生成と組み立て
	CPlayerCharacter* createPlayer()override;

};

//================================================
// 女の子のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerGirlFactory :public CPlayerGirlCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerCharacter* pCharacter)override;
	//画像の設定
	void settingTexture(CPlayerCharacter* pCharacter)override;
	//アニメーションの設定
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	//適用する物理計算の設定
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	//アクションの設定
	void settingActions(CPlayerCharacter* pCharacter)override;
	//衝突判定データの設定
	void settingBody(CPlayerCharacter* pCharacter)override;
	//衝突判定空間
	void settingCollisionArea(CPlayerCharacter* pCharacter)override;
	//ステータスの設定
	void settingStatus(CPlayerCharacter* pCharacter)override;
	//エフェクトの設定
	void settingEffects(CPlayerCharacter* pCharacter)override;
	//武器の設定
	void settingWeapon(CPlayerCharacter* pCharacter)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerCharacter* pCharacter)override;

};

//================================================
// パーツセッティングクラス（CBasePlayerFactory）を管理するクラス
//	（FactoryMethod）
//================================================
//プレイヤーの種類
enum PLAYER_TYPE :int {
	NONE = -1,
	BOY = 0,
	GIRL = 1,
};

class CPlayerFactoryManager {
private:
	//コンストラクタ
	CPlayerFactoryManager(){
		// プレイヤー基本工場
		m_factories.push_back(new CPlayerBoyFactory() );
		m_factories.push_back(new CPlayerGirlFactory());
	}

	//共有のインスタンス
	static CPlayerFactoryManager* m_pPlayerFactoryManager;
	
public:
	//デストラクタ
	~CPlayerFactoryManager() {
		SAFE_DELETE(m_pPlayerFactoryManager);

		for (CPlayerFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//インスタンスの取得
	static CPlayerFactoryManager* getInstance();

	//プレイヤー工場群
	std::vector<CPlayerFactory*> m_factories;
	

	//プレイヤー工場のcreate()を呼び出す
	CPlayerCharacter* create( int type ) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create();
	}

};

