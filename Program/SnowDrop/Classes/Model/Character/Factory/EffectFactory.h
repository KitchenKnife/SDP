#pragma once
#include "Data/Effect/Effect.h"

//================================================
// エフェクトパーツ製造工場
//	（AbstractFactory）
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectPaartsFactory :public CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CEffectPaartsFactory() {}

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
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectFactory {
public:
	//デストラクタ
	virtual ~CEffectFactory() {}

	//エフェクトの生成と組み立て
	virtual CEffect* createPlayer() = 0;

	//移動用データの設定
	virtual void settingMove(CEffect* pChara, cocos2d::Point pos) = 0;

	//画像の設定
	virtual void settingTexture(CEffect* pChara) = 0;

	//アニメーションの設定
	virtual void settingAnimations(CEffect* pChara) = 0;

	//適用する物理計算の設定
	virtual void settingPhysicals(CEffect* pChara) = 0;

	//アクションの設定
	virtual void settingActions(CEffect* pChara) = 0;

	//実体データの設定
	virtual void settingBody(CEffect* pChara) = 0;

	//衝突判定空間
	virtual void settingCollisionArea(CEffect* pChara) = 0;

	//その他：初期設定
	virtual void settingInitialize(CEffect* pChara) = 0;


	//エフェクトの生成と設定
	CEffect* create(cocos2d::Point pos);
};

//================================================
// 少年キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectCreateFactory :public CEffectFactory {
public:
	//デストラクタ
	virtual ~CEffectCreateFactory() {}

	//エフェクトの生成と組み立て
	CEffect* createPlayer()override;

};

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/23
//									Author Harada
//================================================
class CBaseEffectFactory :public CEffectCreateFactory {
public:
	//デストラクタ
	~CBaseEffectFactory() {}

	//移動データの設定
	void settingMove(CEffect* pChara, cocos2d::Point pos)override;
	//画像の設定
	void settingTexture(CEffect* pChara)override;
	//アニメーション群データの設定
	void settingAnimations(CEffect* pChara)override;
	//物理演算群データの設定
	void settingPhysicals(CEffect* pChara)override;
	//アクション群データの設定
	void settingActions(CEffect* pChara)override;
	//実体データの設定
	void settingBody(CEffect* pChara)override;
	//衝突判定空間群データの設定
	void settingCollisionArea(CEffect* pChara)override;

	//その他初期設定
	void settingInitialize(CEffect* pCharacter)override;

};

//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectFactoryManager {
private:
	//コンストラクタ
	CEffectFactoryManager() {
		//基本エフェクトの生成工場を生成して取り付ける
		m_factories.push_back(new CBaseEffectFactory());
	}

	//共有インスタンス
	static CEffectFactoryManager* m_pEffectFactoryManager;

public:
	//デストラクタ
	~CEffectFactoryManager() {
		//共有インスタンスの削除
		SAFE_DELETE(m_pEffectFactoryManager);

		//エフェクト工場群の削除
		for (CEffectFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//共有インスタンスの取得
	static CEffectFactoryManager* getInstance();

	//エフェクト工場群
	std::vector<CEffectFactory*> m_factories;


	/**
	 * @desc	エフェクトの生成
	 * @param	出現させる位置
	 * @param	エフェクトタイプ
	 * @return	生成したエフェクト（キャラクター）
	 */
	CEffect* create(cocos2d::Point pos, EFFECT_TYPE type) {
		//エフェクトタイプを int 型にキャストして対応する工場のcreateを呼び出し、エフェクトを生成する。
		return this->m_factories[(int)type]->create(pos);
	}

};

