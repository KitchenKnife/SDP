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
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"

//================================================
// 少年キャラクターパーツ製造工場
//	（AbstractFactory）
//================================================
class CPlayerBoyPartsFactory :public CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CPlayerBoyPartsFactory() {}

	//アニメーション群データの生成と取得
	virtual std::vector<CAnimation*>* getAnimations()override;
	//移動データの生成と取得
	virtual CMove* getMove()override;
	//物理演算群データの生成と取得
	virtual std::vector<CPhysical*>* getPhysicals()override;
	//アクション群データの生成と取得
	virtual std::vector<CAction*>* getActions()override;
	//実体データの生成と取得
	virtual CBody* getBody()override;
	//衝突判定空間群データの生成と取得
	virtual std::vector<CCollisionArea*>* getCollisionAreas()override;
};


//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CPlayerBoyFactory {
public:
	//デストラクタ
	~CPlayerBoyFactory() {}

	//プレイヤーの生成と組み立て
	//派生先によって違うプレイヤーの生成
	virtual CPlayerCharacterBoy* createPlayer() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CPlayerCharacterBoy* pChara) = 0;

	//画像の設定
	virtual void settingTexture(CPlayerCharacterBoy* pChara) = 0;

	//アニメーションの設定
	virtual void settingAnimations(CPlayerCharacterBoy* pChara) = 0;

	//適用する物理計算の設定
	virtual void settingPhysicals(CPlayerCharacterBoy* pChara) = 0;

	//アクションの設定
	virtual void settingActions(CPlayerCharacterBoy* pChara) = 0;

	//実体データの設定
	virtual void settingBody(CPlayerCharacterBoy* pChara) = 0;

	//衝突判定空間
	virtual void settingCollisionArea(CPlayerCharacterBoy* pChara) = 0;

	//その他：初期設定
	virtual void settingInitialize(CPlayerCharacterBoy* pChara) = 0;

	
	//プレイヤーの生成とセッティング
	CPlayerCharacterBoy* create();
};

//================================================
// 少年キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CPlayerBoyCreateFactory :public CPlayerBoyFactory {
public:
	//デストラクタ
	~CPlayerBoyCreateFactory(){}

	//プレイヤーの生成と組み立て
	CPlayerCharacterBoy* createPlayer()override;

};

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
class CBasePlayerBoyFactory :public CPlayerBoyCreateFactory {
public:
	//デストラクタ
	~CBasePlayerBoyFactory(){}

	//移動データの設定
	void settingMove(CPlayerCharacterBoy* pChara)override;
	//画像の設定
	void settingTexture(CPlayerCharacterBoy* pChara)override;
	//アニメーション群データの設定
	void settingAnimations(CPlayerCharacterBoy* pChara)override;
	//物理演算群データの設定
	void settingPhysicals(CPlayerCharacterBoy* pChara)override;
	//アクション群データの設定
	void settingActions(CPlayerCharacterBoy* pChara)override;
	//実体データの設定
	void settingBody(CPlayerCharacterBoy* pChara)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CPlayerCharacterBoy* pChara)override;

	//その他初期設定
	void settingInitialize(CPlayerCharacterBoy* pCharacter)override;

};


//少年の種類
enum class PLAYER_TYPE :int {
	BASE	= 0,	//基本
};

//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//================================================
class CPlayerBoyFactoryManager {
private:
	//コンストラクタ
	CPlayerBoyFactoryManager(){
		//基本少年キャラクターの工場
		m_factories.push_back(new CBasePlayerBoyFactory());
	}

	//共有のインスタンス
	static CPlayerBoyFactoryManager* m_pPlayerBoyFactoryManager;
	
public:
	//デストラクタ
	~CPlayerBoyFactoryManager() {
		SAFE_DELETE(m_pPlayerBoyFactoryManager);

		for (CPlayerBoyFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//インスタンスの取得
	static CPlayerBoyFactoryManager* getInstance();

	//プレイヤー工場群
	std::vector<CPlayerBoyFactory*> m_factories;
	

	//プレイヤー工場のcreate()を呼び出す
	CPlayerCharacterBoy* create( int type ) {

		return this->m_factories[type]->create();
	}

};

