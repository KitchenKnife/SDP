/*
* DamageFactory.h
*
*	2016/12/21	Yamasaki And Harada
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/DamageCharacter/DamageCharacter.h"
#include <map>

//================================================
// キャラクターパーツ製造工場
//	（AbstractFactory）
//================================================
class CDamagePartsFactory :public CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CDamagePartsFactory();

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
class CDamageFactory {
protected:

	//敵の生成と組み立て
	virtual CDamageCharacter* createDamage() = 0;

	//移動データの設定
	virtual void settingMove(CDamageCharacter* pChara, float x, float y) = 0;
	//画像の設定
	virtual void settingTexture(CDamageCharacter* pChara) = 0;
	//アニメーション群データの設定
	virtual void settingAnimations(CDamageCharacter* pChara) = 0;
	//物理演算群データの設定
	virtual void settingPhysicals(CDamageCharacter* pChara) = 0;
	//アクション群データの設定
	virtual void settingActions(CDamageCharacter* pChara) = 0;
	//実体データの設定
	virtual void settingBody(CDamageCharacter* pChara) = 0;
	//衝突判定空間群データの設定
	virtual void settingCollisionArea(CDamageCharacter* pChara) = 0;
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CDamageCharacter* pChara) = 0;
	//その他　初期設定
	virtual void settingInitialize(CDamageCharacter* pChara) = 0;

public:
	//デストラクタ
	virtual ~CDamageFactory() {};

	//敵の生成とセッティング
	CDamageCharacter* create(float posX, float posY) {

		//敵の生成と組み立て
		CDamageCharacter* pChara = this->createDamage();

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
template <class Ty>
class CDamageCreateFactory :public CDamageFactory {
public:
	//デストラクタ
	virtual ~CDamageCreateFactory() {}

protected:
	//敵の生成と組み立て
	virtual CDamageCharacter* createDamage()override {

		// 敵生成
		CDamageCharacter* pDamage = Ty::create();
		// 敵パーツ工場生成
		CDamagePartsFactory pDamagePartsFactory;

		// パーツの設定
		pDamage->m_pMove = pDamagePartsFactory.getMove();
		pDamage->m_pAnimations = pDamagePartsFactory.getAnimations();

		pDamage->m_pPhysicals = pDamagePartsFactory.getPhysicals();
		pDamage->m_pBody = pDamagePartsFactory.getBody();
		pDamage->m_pCollisionAreas = pDamagePartsFactory.getCollisionAreas();

		//状態データの生成と取得
		pDamage->m_pStateMachine = pDamagePartsFactory.getStateMachine();

		//　敵返す
		return pDamage;
	}
};

//================================================
// 敵工場群を管理するクラス
//	（Singleton）
//================================================
class CDamageFactoryManager {
private:
	//コンストラクタ
	CDamageFactoryManager() {
	}

	//共有のインスタンス
	static CDamageFactoryManager* m_pDamageFactoryManager;

public:
	//デストラクタ
	~CDamageFactoryManager() {
		//共有インスタンスの削除
		SAFE_DELETE(m_pDamageFactoryManager);

		//取り付けた工場群を削除
		std::map<ENEMY_TYPE, CDamageFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//クラスのインスタンスを削除
			SAFE_DELETE(itr->second);
			//イテレーターを更新
			itr++;
		}
	}


	//インスタンスの取得
	static CDamageFactoryManager* getInstance();

	//敵工場群
	std::map<ENEMY_TYPE, CDamageFactory*> m_factories;

	/**
	* @desc	敵キャラクターを生成
	* @param	出撃させる位置
	* @param	敵のタイプ
	* @return	生成した敵キャラクター
	*/
	CDamageCharacter* create(Point pos, ENEMY_TYPE type) {
		//敵のタイプを key として敵を生成して返す
		return this->m_factories[type]->create(pos.x, pos.y);
	}

};

//EOF