#pragma once

//#pragmaonce//////////*+-----------------------------------------------------------------------------------------------------------------------------------------**++++++++++++++++++++-++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//プレイヤークラスの前方宣言
class CGimmickCharacter;

//================================================
// ギミックパーツ製造工場
//	（AbstractFactory）
//================================================
class CGimmickPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CGimmickPartsFactory() {}

	std::vector<CAnimation* >* getAnimations();
	CMove* getMove();
	std::vector<CPhysical* >* getPhysicals();
	CBody* getBody();
	std::vector<CCollisionArea* >* getCollisionAreas();

};


//================================================
// ギミックの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CGimmickFactory {
public:

	virtual ~CGimmickFactory() {}

	//ギミックの生成と組み立て
	//派生先によって違うギミックの生成
	virtual CGimmickCharacter* createGimmick() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt) = 0;
	//画像の設定
	virtual void settingTexture(CGimmickCharacter* pCharacter) = 0;
	//アニメーションの設定
	virtual void settingAnimations(CGimmickCharacter* pCharacter) = 0;
	//適用する物理計算の設定
	virtual void settingPhysicals(CGimmickCharacter* pCharacter) = 0;
	//アクションの設定
	virtual void settingActions(CGimmickCharacter* pCharacter) = 0;
	//衝突判定データの設定
	virtual void settingBody(CGimmickCharacter* pCharacter) = 0;
	//衝突判定空間の設定
	virtual void settingColllisionArea(CGimmickCharacter* pCharacter) = 0;
	//初期設定もろもろ
	virtual void settingInitialize(CGimmickCharacter* pCharacter) = 0;


	//ギミックの生成とセッティング
	CGimmickCharacter* create(cocos2d::Point pt) {

		//ギミックの生成と組み立て
		CGimmickCharacter* pCharacter = this->createGimmick();

		//初期位置の設定
		this->settingMove(pCharacter, pt);
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
		//衝突判定空間の設定
		this->settingColllisionArea(pCharacter);
		//初期化もろもろ
		this->settingInitialize(pCharacter);//(pCharacter, vec)

		return pCharacter;
	}

};

//================================================
// ギミックの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CGimmickCreateFactory :public CGimmickFactory {
public:

	//デストラクタ
	virtual ~CGimmickCreateFactory() {}

	//ギミックの生成と組み立て
	CGimmickCharacter* createGimmick()override;

};

//================================================
// ダメージブロックのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CDamageBlockFactory :public CGimmickCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt)override;
	//画像の設定
	void settingTexture(CGimmickCharacter* pCharacter)override;
	//アニメーションの設定
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	//適用する物理計算の設定
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	//アクションの設定
	void settingActions(CGimmickCharacter* pCharacter)override;
	//衝突判定データの設定
	void settingBody(CGimmickCharacter* pCharacter)override;
	//衝突判定空間の設定
	void settingColllisionArea(CGimmickCharacter* pCharacter)override;

	//初期設定もろもろ
	void settingInitialize(CGimmickCharacter* pCharacter)override;

};


//================================================
// パーツセッティングクラス（CBasePlayerFactory）を管理するクラス
//	（FactoryMethod）
//================================================
class CGimmickFactoryManager {
private:
	//コンストラクタ
	CGimmickFactoryManager() {
		// ギミック工場
		m_factories.push_back(new CDamageBlockFactory());

	}

	//共有のインスタンス
	static CGimmickFactoryManager* m_pGimmickFactoryManager;

public:
	//デストラクタ
	~CGimmickFactoryManager() {
		SAFE_DELETE(m_pGimmickFactoryManager);

		for (CGimmickFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//インスタンスの取得
	static CGimmickFactoryManager* getInstance();


	std::vector<CGimmickFactory*> m_factories;

	/**
	* @desc ギミック工場のcreate()を呼び出す
	* @param 弾のタイプ
	* @param 弾の発射位置
	*/
	CGimmickCharacter* create(int type, cocos2d::Point Pt) {

		return this->m_factories[type]->create(Pt);
	}

};


