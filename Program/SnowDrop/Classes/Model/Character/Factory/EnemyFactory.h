/*
 * EnemyFactory.h
 *
 *	2016/12/21	Yamasaki And Harada
 *	
 */

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"
#include <map>

//================================================
// キャラクターパーツ製造工場
//	（AbstractFactory）
//================================================
class CEnemeyPartsFactory :public CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CEnemeyPartsFactory();

	//アニメーション群データの実体を生成し取得
	virtual std::vector<CAnimation* >* getAnimations()override;
	//移動データの実体を生成し取得
	virtual CMove* getMove()override;
	//物理演算群データの実体を生成し取得
	virtual std::vector<CPhysical* >* getPhysicals()override;
	//アクション群データの実体を生成し取得
	virtual std::vector<CAction* >* getActions()override;
	//実体データの実体を生成し取得
	virtual CBody* getBody()override;
	//衝突判定空間群データの実体を生成し取得
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;

};


//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CEnemyFactory {
protected:

	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy() = 0;

	//移動データの設定
	virtual void settingMove(CEnemyCharacter* pChara ,float x,float y) = 0;
	//画像の設定
	virtual void settingTexture(CEnemyCharacter* pChara) = 0;
	//アニメーション群データの設定
	virtual void settingAnimations(CEnemyCharacter* pChara) = 0;
	//物理演算群データの設定
	virtual void settingPhysicals(CEnemyCharacter* pChara) = 0;
	//アクション群データの設定
	virtual void settingActions(CEnemyCharacter* pChara) = 0;
	//実体データの設定
	virtual void settingBody(CEnemyCharacter* pChara) = 0;
	//衝突判定空間群データの設定
	virtual void settingCollisionArea(CEnemyCharacter* pChara) = 0;

	//その他　初期設定
	virtual void settingInitialize(CEnemyCharacter* pChara) = 0;

public:
	//デストラクタ
	virtual ~CEnemyFactory() {};

	//敵の生成とセッティング
	CEnemyCharacter* create(float posX,float posY) {

		//敵の生成と組み立て
		CEnemyCharacter* pChara = this->createEnemy();

		//移動データ設定
		this->settingMove(pChara,posX,posY);
		//画像の設定
		this->settingTexture(pChara);
		//アニメーション群データの設定
		this->settingAnimations(pChara);
		//物理演算群データの設定
		this->settingPhysicals(pChara);
		//アクション群データの設定
		this->settingActions(pChara);
		//実体データの設定
		this->settingBody(pChara);
		//衝突判定空間群データの設定
		this->settingCollisionArea(pChara);
		//その他初期化
		this->settingInitialize(pChara);

		return pChara;
	}
};

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CEnemyCreateFactory :public CEnemyFactory {
public:
	//デストラクタ
	virtual ~CEnemyCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy()override {

		// 敵生成
		CEnemyCharacter* pEnemy = CEnemyCharacter::create();
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();
		
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
	//デストラクタ
	virtual ~CMaideadFactory(){}

	//移動データの設定
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//画像の設定
	void settingTexture(CEnemyCharacter* pChara)override;
	//アニメーション群データの設定
	void settingAnimations(CEnemyCharacter* pChara)override;
	//物理演算群データの設定
	void settingPhysicals(CEnemyCharacter* pChara)override;
	//アクション群データの設定
	void settingActions(CEnemyCharacter* pChara)override;
	//実体データの設定
	void settingBody(CEnemyCharacter* pChara)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};


//================================================
//　コウモリ工場
//================================================
class CBatFactory :public CEnemyCreateFactory {
public:
	//デストラクタ
	~CBatFactory(){}
	
	//移動データの設定
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//画像の設定
	void settingTexture(CEnemyCharacter* pChara)override;
	//アニメーション群データの設定
	void settingAnimations(CEnemyCharacter* pChara)override;
	//物理演算群データの設定
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//アクション群データの設定
	void settingActions(CEnemyCharacter* pChara)override;
	//実体データの設定
	void settingBody(CEnemyCharacter* pChara)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
// 敵工場群を管理するクラス
//	（Singleton）
//================================================
class CEnemyFactoryManager {
private:
	//コンストラクタ
	CEnemyFactoryManager() {
		//メイド生成工場を生成し [key : MAIDEAD] に取り付ける
		m_factories[ENEMY_TYPE::MAIDEAD] = new CMaideadFactory();

		//コウモリ生成工場を生成し [key : BAT] に取り付ける
		m_factories[ENEMY_TYPE::BAT] = new CBatFactory();
	}

	//共有のインスタンス
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//デストラクタ
	~CEnemyFactoryManager() {
		//共有インスタンスの削除
		SAFE_DELETE(m_pEnemyFactoryManager);

		//取り付けた工場群を削除
		std::map<ENEMY_TYPE, CEnemyFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//クラスのインスタンスを削除
			SAFE_DELETE(itr->second);
			//イテレーターを更新
			itr++;
		}
	}


	//インスタンスの取得
	static CEnemyFactoryManager* getInstance();

	//敵工場群
	std::map<ENEMY_TYPE, CEnemyFactory*> m_factories;

	/**
	 * @desc	敵キャラクターを生成
	 * @param	出撃させる位置
	 * @param	敵のタイプ
	 * @return	生成した敵キャラクター
	 */
	CEnemyCharacter* create(Point pos, ENEMY_TYPE type) {
		//敵のタイプを key として敵を生成して返す
		return this->m_factories[type]->create(pos.x, pos.y);
	}

};

