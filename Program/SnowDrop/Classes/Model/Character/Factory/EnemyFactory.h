
/*
* EnemyFactory.h
*
*	2016/12/21	Yamasaki
*	test
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Map/Map.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"

//================================================
// キャラクターパーツ製造工場
//	（AbstractFactory）
//================================================
class CEnemeyPartsFactory :public CCharacterPartsFactory {
public:

	virtual ~CEnemeyPartsFactory() {}

	virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove();
	virtual std::vector<CPhysical* >* getPhysicals();
	virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody();
	virtual std::vector<CCollisionArea* >* getCollisionAreas();

};


//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CEnemyFactory {
protected:

	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy() = 0;

	//各々のパーツのセッティング
	//移動用データの設定
	virtual void settingMove(CEnemyCharacter* pCharacter ,float x,float y) = 0;
	//画像の設定
	virtual void settingTexture(CEnemyCharacter* pCharacter) = 0;
	//アニメーションの設定
	virtual void settingAnimations(CEnemyCharacter* pCharacter) = 0;
	//適用する物理計算の設定
	virtual void settingPhysicals(CEnemyCharacter* pCharacter) = 0;
	//アクションの設定
	virtual void settingActions(CEnemyCharacter* pCharacter) = 0;
	//衝突判定データの設定
	virtual void settingBody(CEnemyCharacter* pCharacter) = 0;
	//衝突判定空間
	virtual void settingCollisionArea(CEnemyCharacter* pCharacter) = 0;

	

	//初期設定もろもろ
	virtual void settingInitialize(CEnemyCharacter* pCharacter) = 0;

public:

	//敵の生成とセッティング
	CEnemyCharacter* create(float posX,float posY) {

		//敵の生成と組み立て
		CEnemyCharacter* pCharacter = this->createEnemy();

		//初期位置の設定
		this->settingMove(pCharacter,posX,posY);
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
		//初期化もろもろ
		this->settingInitialize(pCharacter);

		return pCharacter;
	}

	virtual ~CEnemyFactory() {};

};

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CEnemyCreateFactory :public CEnemyFactory {
public:
	virtual ~CEnemyCreateFactory() {}

protected:
	virtual CEnemyCharacter* createEnemy()override {

		// 敵生成
		CEnemyCharacter* pEnemy = CEnemyCharacter::create();
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pActions = pEnemyPartsFactory.getActions();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//　敵返す
		return pEnemy;
	}
};

//================================================
// メイデッド工場
//================================================
class CMaideadFactory :public CEnemyCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CEnemyCharacter* pCharacter , float posX, float posY)override;
	//画像の設定
	void settingTexture(CEnemyCharacter* pCharacter)override;
	//アニメーションの設定
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	//適用する物理計算の設定
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//アクションの設定
	void settingActions(CEnemyCharacter* pCharacter)override;
	//衝突判定データの設定
	void settingBody(CEnemyCharacter* pCharacter)override;
	//衝突判定空間
	void settingCollisionArea(CEnemyCharacter* pCharacter)override;



	//初期設定もろもろ
	void settingInitialize(CEnemyCharacter* pCharacter)override;

};


//================================================
//　コウモリ工場
//================================================
class CBatFactory :public CEnemyCreateFactory {
public:

	//各々のパーツのセッティング
	//移動用データの設定
	void settingMove(CEnemyCharacter* pCharacter , float posX, float posY)override;
	//画像の設定
	void settingTexture(CEnemyCharacter* pCharacter)override;
	//アニメーションの設定
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	//適用する物理計算の設定
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//アクションの設定
	void settingActions(CEnemyCharacter* pCharacter)override;
	//衝突判定データの設定
	void settingBody(CEnemyCharacter* pCharacter)override;
	//衝突判定空間
	void settingCollisionArea(CEnemyCharacter* pCharacter)override;



	//初期設定もろもろ
	void settingInitialize(CEnemyCharacter* pCharacter)override;

};

//================================================
// パーツセッティングクラス（CBaseEnemyFactory）を管理するクラス
//	（FactoryMethod）
//================================================
//敵の種族タイプ
enum ENEMY_RACE_TYPE :int{
	MAIDEAD = 0,			// メイド
	BAT		= 1,			// コウモリ
	MALICE	= 2,			// マリス
};

class CEnemyFactoryManager {
private:
	//コンストラクタ
	CEnemyFactoryManager() {

		m_factories.push_back(new CMaideadFactory());
		m_factories.push_back(new CBatFactory());
	}

	//共有のインスタンス
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//デストラクタ
	~CEnemyFactoryManager() {
		SAFE_DELETE(m_pEnemyFactoryManager);

		for (CEnemyFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}

		this->m_factories.clear();
	}


	//インスタンスの取得
	static CEnemyFactoryManager* getInstance();

	//敵工場群
	std::vector<CEnemyFactory*> m_factories;


	//敵工場のcreate()を呼び出す
	CEnemyCharacter* create(Point pos, int type) {

			return this->m_factories[type]->create(pos.x, pos.y);
	}

};

