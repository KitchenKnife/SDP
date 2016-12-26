#pragma once
#include "Model/Character/GirlCharacter/GirlCharacter.h"

//=============================================================
// 少女キャラクターパーツ製造工場
//	（AbstractFactory）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//============================================================
class CPlayerGirlPartsFactory :public CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CPlayerGirlPartsFactory() {}

	//アニメーション群データの生成と取得
	virtual std::vector<CAnimation*>* getAnimations()override;
	//移動データの生成と取得
	virtual CMove* getMove()override;
	//物理演算群データの生成と取得
	virtual std::vector<CPhysical*>* getPhysicals()override;
	//実体データの生成と取得
	virtual CBody* getBody()override;
	//衝突判定空間群データの生成と取得
	virtual std::vector<CCollisionArea*>* getCollisionAreas()override;
	/**
	*	@desc 状態遷移データの生成と取得
	*	@return 状態遷移データ
	*	@author Shinya Ueba
	*/
	virtual	CStateMachine*	getStateMachine(void)override;

};


//=====================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author Shinya Ueba
//=====================================================
class CPlayerGirlFactory {
public:
	//デストラクタ
	virtual ~CPlayerGirlFactory() {}

	//プレイヤーの生成と組み立て
	//派生先によって違うプレイヤーの生成
	virtual CPlayerCharacterGirl* createPlayer() = 0;

	//移動用データの設定
	virtual void settingMove(CPlayerCharacterGirl* pChara) = 0;

	//画像の設定
	virtual void settingTexture(CPlayerCharacterGirl* pChara) = 0;

	//アニメーションの設定
	virtual void settingAnimations(CPlayerCharacterGirl* pChara) = 0;

	//適用する物理計算の設定
	virtual void settingPhysicals(CPlayerCharacterGirl* pChara) = 0;

	//アクションの設定
	virtual void settingActions(CPlayerCharacterGirl* pChara) = 0;

	//実体データの設定
	virtual void settingBody(CPlayerCharacterGirl* pChara) = 0;

	//衝突判定空間
	virtual void settingCollisionArea(CPlayerCharacterGirl* pChara) = 0;

	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CPlayerCharacterGirl* pChara) = 0;

	//その他：初期設定
	virtual void settingInitialize(CPlayerCharacterGirl* pChara) = 0;


	//プレイヤーの生成とセッティング
	CPlayerCharacterGirl* create();
};


//================================================
// 女の子の生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerGirlCreateFactory :public CPlayerGirlFactory {
public:

	//デストラクタ
	virtual ~CPlayerGirlCreateFactory() {}

	//プレイヤーの生成と組み立て
	CPlayerCharacterGirl* createPlayer()override;

};

//====================================================
// 女の子のパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author Shinya Ueba
//====================================================
class CBasePlayerGirlFactory :public CPlayerGirlCreateFactory {
public:

	//各々のパーツのセッティング
	//移動データの設定
	void settingMove(CPlayerCharacterGirl* pCharacter)override;
	//画像の設定
	void settingTexture(CPlayerCharacterGirl* pCharacter)override;
	//アニメーション群データの設定
	void settingAnimations(CPlayerCharacterGirl* pCharacter)override;
	//物理演算群データの設定
	void settingPhysicals(CPlayerCharacterGirl* pCharacter)override;
	//アクション群データの設定
	void settingActions(CPlayerCharacterGirl* pCharacter)override;
	//実体データの設定
	void settingBody(CPlayerCharacterGirl* pCharacter)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CPlayerCharacterGirl* pCharacter)override;
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CPlayerCharacterGirl* pChara)override;



	//その他初期設定
	void settingInitialize(CPlayerCharacterGirl* pCharacter)override;
};

//少年の種類
enum class GIRL_TYPE :int {
	BASE = 0,	//基本
};

//================================================
// 少女キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerGirlFactoryManager {
private:
	//コンストラクタ
	CPlayerGirlFactoryManager() {
		//基本少年キャラクターの工場
		this->m_factories.push_back(new CBasePlayerGirlFactory());
	}

	//共有のインスタンス
	static CPlayerGirlFactoryManager* m_pPlayerGirlFactoryManager;

public:
	//デストラクタ
	~CPlayerGirlFactoryManager() {
		SAFE_DELETE(m_pPlayerGirlFactoryManager);

		for (CPlayerGirlFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//インスタンスの破棄
	static void removeInstance();

	//インスタンスの取得
	static CPlayerGirlFactoryManager* getInstance();

	//プレイヤー工場群
	std::vector<CPlayerGirlFactory*> m_factories;


	//プレイヤー工場のcreate()を呼び出す
	CPlayerCharacterGirl* create(int type) {

		return this->m_factories[type]->create();
	}

};
