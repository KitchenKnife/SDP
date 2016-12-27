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
#include "Model\Character\Factory\CharacterFactory.h"
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

	//生成と組み立て
	virtual CDamageCharacter* createDamage() = 0;

	//移動データの設定
	virtual void settingMove(CDamageCharacter* pChara, CCharacter* pAttackChara) = 0;
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
	virtual void settingInitialize(CDamageCharacter* pChara,int activeFrame) = 0;

public:
	//デストラクタ
	virtual ~CDamageFactory() {};

	//敵の生成とセッティング
	CDamageCharacter* create(CCharacter* pAttackChara,int activeFrame) {

		//敵の生成と組み立て
		CDamageCharacter* pChara = this->createDamage();

		//移動データ設定
		this->settingMove(pChara, pAttackChara);
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
		this->settingInitialize(pChara,activeFrame);

		return pChara;
	}
};


//================================================
// 生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
class CDamageCreateFactory :public CDamageFactory {
public:

	//デストラクタ
	virtual ~CDamageCreateFactory() {}

	//生成と組み立て
	CDamageCharacter* createDamage()override;

};

//================================================
// 近接ダメージ工場
//================================================
class CNearDamageFactory :public CDamageCreateFactory {
public:
	//デストラクタ
	virtual ~CNearDamageFactory() {}

	//移動データの設定
	void settingMove(CDamageCharacter* pChara, CCharacter* pAttackChara)override;
	//画像の設定
	void settingTexture(CDamageCharacter* pChara)override;
	//アニメーション群データの設定
	void settingAnimations(CDamageCharacter* pChara)override;
	//物理演算群データの設定
	void settingPhysicals(CDamageCharacter* pChara)override;
	//アクション群データの設定
	void settingActions(CDamageCharacter* pChara)override;
	//実体データの設定
	void settingBody(CDamageCharacter* pChara)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CDamageCharacter* pChara)override;
	/**
	*	@desc 状態遷移データの設定
	*	@param 設定するキャラクター
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CDamageCharacter* pChara)override;
	//その他初期設定
	void settingInitialize(CDamageCharacter* pChara,int activeFrame)override;

};

//================================================
// ダメージ工場群を管理するクラス
//	（Singleton）
//================================================
class CDamageFactoryManager {
private:
	//コンストラクタ
	CDamageFactoryManager() {

		this->m_factories = new CNearDamageFactory();
	}

	//共有のインスタンス
	static CDamageFactoryManager* m_pDamageFactoryManager;

public:
	//デストラクタ
	~CDamageFactoryManager() {
			SAFE_DELETE(this->m_factories);
	}

	static void removeInstance() {
		SAFE_DELETE(m_pDamageFactoryManager);
	}


	//インスタンスの取得
	static CDamageFactoryManager* getInstance();

	//ダメージ工場（1種類のみ）
	CDamageFactory* m_factories;

	/**
	* @desc	キャラクターを生成
	* @param	プレイヤーのm_pMove
	* @param	存在させておくフレーム数
	* @param	出現向き
	* @return	生成したダメージキャラクター
	*/
	CDamageCharacter* create(CCharacter* pAttackChara,int activeFrame) {

		return this->m_factories->create(pAttackChara,activeFrame);
	}

};

//EOF