#pragma once
/*
* PlayerEffectFactory.h
*
*	2016/11/25	Osumi
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Data/Effect/PlayerEffect/PlayerEffect.h"

//クラスの前方宣言

//================================================
// エッフェクトパーツ製造工場
//	（AbstractFactory）
//================================================
class CPlayerEffactPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CPlayerEffactPartsFactory() {}
	virtual CMove* getMove();//override;
	//std::vector<CAnimation*> getMapAnimations();
	//CAnimation* getAnimation();
};


//================================================
// エフェクトの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CPlayerEffectFactory {
public:

	//パーツ製造工場群
	std::vector<CPlayerEffactPartsFactory*>partsFactories{
		new CPlayerEffactPartsFactory(),
		new CPlayerEffactPartsFactory(),
	};

	~CPlayerEffectFactory() {
		//パーツ製造工場群の解放
		for (CPlayerEffactPartsFactory* pPartsfactory : partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//プレイヤーの生成と組み立て
	//派生先によって違うプレイヤーの生成
	virtual CPlayerEffect* createEffect() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CPlayerEffect* pEffct, cocos2d::Point pt) = 0;
	//画像の設定
	virtual void settingTexture(CPlayerEffect* pEffct) = 0;
	//アニメーションの設定
	virtual void settingAnimations(CPlayerEffect* pEffct) = 0;

	//初期設定もろもろ
	virtual void settingInitialize(CPlayerEffect* pEffct) = 0;


	//プレイヤーの生成とセッティング
	CPlayerEffect* create(cocos2d::Point pt) {

		//プレイヤーの生成と組み立て
		CPlayerEffect* pCharacter = this->createEffect();

		//初期位置の設定
		this->settingMove(pCharacter,pt);
		//テクスチャの設定
		this->settingTexture(pCharacter);
		//アニメーションの設定
		this->settingAnimations(pCharacter);

		//初期化もろもろ
		this->settingInitialize(pCharacter);


		return pCharacter;
	}

};

//================================================
// エフェクトの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CDisappearEffectCreateFactory :public CPlayerEffectFactory {
public:

	//エフェクトの生成と組み立て
	virtual CPlayerEffect* createEffect()override;

};

//================================================
// エフェクトのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CDisappearEffectFactory :public CDisappearEffectCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerEffect* pEffct, cocos2d::Point pt)override;
	//画像の設定
	void settingTexture(CPlayerEffect* pEffct)override;
	//アニメーションの設定
	void settingAnimations(CPlayerEffect* pEffct)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerEffect* pEffct)override;

};

/*
//================================================
// エフェクトの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CDisappearEffectCreateFactory :public CPlayerEffectFactory {
public:

	//エフェクトの生成と組み立て
	virtual CPlayerEffect* createEffect()override;

};

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CDisappearEffectFactory :public CDisappearEffectCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CPlayerEffect* pEffct)override;
	//画像の設定
	void settingTexture(CPlayerEffect* pEffct)override;
	//アニメーションの設定
	void settingAnimations(CPlayerEffect* pEffct)override;

	//初期設定もろもろ
	void settingInitialize(CPlayerEffect* pEffct)override;

};
*/

//================================================
// パーツセッティングクラス（CBasePlayerFactory）を管理するクラス
//	（FactoryMethod）
//================================================

class CPlayerEffectFactoryManager {
private:
	//コンストラクタ
	CPlayerEffectFactoryManager() {
		// プレイヤー基本工場
		m_factories.push_back(new CDisappearEffectFactory());
		m_factories.push_back(new CDisappearEffectFactory());
	}

	//共有のインスタンス
	static CPlayerEffectFactoryManager* m_pPlayerEffectFactoryManager;

public:
	//デストラクタ
	~CPlayerEffectFactoryManager() {
		SAFE_DELETE(m_pPlayerEffectFactoryManager);

		for (CPlayerEffectFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//インスタンスの取得
	static CPlayerEffectFactoryManager* getInstance();

	//エフェクト工場群
	std::vector<CPlayerEffectFactory*> m_factories;

	//エフェクト工場のcreate()を呼び出す
	CPlayerEffect* create(int type,cocos2d::Point pt) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create(pt);
	}

};

