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
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Character\EnemyCharacter\Marionette\MarionetteCharacter.h"
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
	//実体データの実体を生成し取得
	virtual CBody* getBody()override;
	//衝突判定空間群データの実体を生成し取得
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;
	/**
	*	@desc 状態遷移データの生成と取得
	*	@return 状態遷移データ
	*	@author Shinya Ueba
	*/
	virtual	CStateMachine*	getStateMachine(void)override;


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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CEnemyCharacter* pChara) = 0;
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
		//状態遷移マシンの設定
		this->settingStateMachine(pChara);
		//その他初期化
		this->settingInitialize(pChara);

		return pChara;
	}
};

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
template <class Ty>
class CEnemyCreateFactory :public CEnemyFactory {
public:
	//デストラクタ
	virtual ~CEnemyCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy()override {

		// 敵生成
		CEnemyCharacter* pEnemy = Ty::create();
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();
		
		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//状態データの生成と取得
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//　敵返す
		return pEnemy;
	}
};

//================================================
// メイデッド工場
//================================================
template<class Ty>
class CMaideadFactory :public CEnemyCreateFactory<Ty> {
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

	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;

	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};


//================================================
//　コウモリ工場
//================================================
template <class Ty>
class CBatFactory :public CEnemyCreateFactory<Ty> {
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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//　マリス工場
//================================================
template <class Ty>
class CMaliceFactory :public CEnemyCreateFactory<Ty> {
public:
	//デストラクタ
	~CMaliceFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//　NutCracker工場
//================================================
template <class Ty>
class CNutCrackerFactory :public CEnemyCreateFactory<Ty> {
public:
	//デストラクタ
	~CNutCrackerFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//　Baron工場
//================================================
template <class Ty>
class CBaronFactory :public CEnemyCreateFactory<Ty> {
public:
	//デストラクタ
	~CBaronFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};



//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CMouseKingCreateFactory :public CEnemyFactory {
public:
	//デストラクタ
	virtual ~CMouseKingCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy()override {

		// 敵生成
		CMouseKingCharacter* pEnemy = CMouseKingCharacter::create();
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//状態データの生成と取得
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//　敵返す
		return pEnemy;
	}
};


//================================================
//　MouseKing工場
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMouseKingFactory :public CMouseKingCreateFactory 
{
public:
	//デストラクタ
	~CMouseKingFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//================================================
class CMouseEnemyFactory: public CEnemyFactory 
{
protected:
	//敵の生成と組み立て
	virtual CMouseCharacter* createEnemy(CMouseKingCharacter* pMaster,int positionType) = 0;
public:
	//デストラクタ
	virtual ~CMouseEnemyFactory() {};

	//敵の生成とセッティング
	CMouseCharacter* create(float posX, float posY,CMouseKingCharacter* pMaster,int positionType) {

		//敵の生成と組み立て
		CMouseCharacter* pChara = this->createEnemy(pMaster,positionType);

		//移動データ設定
		this->settingMove(pChara, posX, posY);
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
		//状態遷移マシンの設定
		this->settingStateMachine(pChara);
		//その他初期化
		this->settingInitialize(pChara);

		return pChara;
	}
};


//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CMouseCreateFactory :public CMouseEnemyFactory {
public:
	//デストラクタ
	virtual ~CMouseCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy()override {
		return NULL;
	}

	//敵の生成と組み立て
	CMouseCharacter* createEnemy(CMouseKingCharacter* pMaster, int positionType){

		// 敵生成
		CMouseCharacter* pEnemy = CMouseCharacter::create(pMaster,positionType);
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//状態データの生成と取得
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//　敵返す
		return pEnemy;
	}
};

//================================================
//　Mouse工場
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMouseFactory :public CMouseCreateFactory
{
public:
	//デストラクタ
	~CMouseFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CEnemyCharacter* pChara)override;

};



//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CMarionetteCreateFactory :public CEnemyFactory {
public:
	//デストラクタ
	virtual ~CMarionetteCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CEnemyCharacter* createEnemy()override {

		// 敵生成
		CMarionetteCharacter* pEnemy = CMarionetteCharacter::create();
		// 敵パーツ工場生成
		CEnemeyPartsFactory pEnemyPartsFactory;

		// パーツの設定
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//状態データの生成と取得
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//　敵返す
		return pEnemy;
	}
};


//================================================
//　Marionette工場
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMarionetteFactory :public CMarionetteCreateFactory
{
public:
	//デストラクタ
	~CMarionetteFactory() {}

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
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
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
		m_factories[ENEMY_TYPE::MAIDEAD] = new CMaideadFactory<CEnemyCharacter>();

		//コウモリ生成工場を生成し [key : BAT] に取り付ける
		m_factories[ENEMY_TYPE::BAT] = new CBatFactory<CEnemyCharacter>();

		//コウモリ生成工場を生成し [key : BAT] に取り付ける
		m_factories[ENEMY_TYPE::MALICE] = new CMaliceFactory<CEnemyCharacter>();

		//NutCracker生成工場を生成し [key : NutCracker] に取り付ける
		m_factories[ENEMY_TYPE::NUTCRACKER] = new CNutCrackerFactory<CEnemyCharacter>();

		//Baron生成工場を生成し [key : Baron] に取り付ける
		m_factories[ENEMY_TYPE::BARON] = new CBaronFactory<CEnemyCharacter>();

		//MouseKing生成工場を生成し [key : NutCracker] に取り付ける
		m_factories[ENEMY_TYPE::MOUSEKING] = new CMouseKingFactory();

		//Marionette生成工場を生成し [key : Marionette] に取り付ける
		m_factories[ENEMY_TYPE::MARIONETTE ] = new CMarionetteFactory();
	}

	//共有のインスタンス
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//デストラクタ
	~CEnemyFactoryManager() {

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

	//インスタンスの破棄
	static void removeInstance();

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

//EOF