#pragma once

#include "Data/Effect/Effect.h"

class CPlayerCharacter;

//==========================================
//
//  プレイヤーのエフェクトの基底クラス
//
//==========================================

class CPlayerEffect :public CEffect {

public:

	//コンストラクタ
	CPlayerEffect() {}

	//デストラクタ
	virtual ~CPlayerEffect() {}

	//初期化処理
	virtual bool init()override;

	//エフェクトのレイヤーへの取り付け
	virtual void jointToLayer(cocos2d::Layer* pLayer) {
		pLayer->addChild(this);
	}

protected:

	//移動処理
	virtual void moveFunc()override {}

	//================================================
	// 
	//　ここまでにメンバに関するコードを追加
	//		
	//================================================
};

//==========================================
//
//  消失エフェクトクラス
//
//==========================================
class CBoyDisappearEffect :public CPlayerEffect {
public:

	CREATE_FUNC(CBoyDisappearEffect);

	//コンストラクタ
	CBoyDisappearEffect() {}

	//デストラクタ
	virtual ~CBoyDisappearEffect() {}

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update()override {

		//アニメーションが終わってたら、有効フラグを下げる
		if (this->m_pAnimationDatas->isEnd() == true) {
			this->m_activeFlag = false;
		}

		CEffect::update();
	}

protected:

	//移動処理
	virtual void moveFunc()override {
		//移動計算
		this->m_pMove->moveBy();
	};

	//================================================
	// 
	//　ここまでにメンバに関するコードを追加
	//		
	//================================================
};

//==========================================
//
//  少年のダメージエフェクトクラス
//
//==========================================
class CBoyDamageEffect :public CPlayerEffect {
public:

	CREATE_FUNC(CBoyDamageEffect);

	//コンストラクタ
	CBoyDamageEffect() {}

	//デストラクタ
	virtual ~CBoyDamageEffect() {}

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update()override {

		CEffect::update();
	}

	//アニメーションデータ
	//CAnimation* m_pAnimationDatas = NULL;
	//移動データ
	//CMove* m_pMove = NULL;
	//有効フラグ
	//bool m_activeFlag = false;

	//エフェクトのレイヤーへの取り付け
	//void jointToLayer(cocos2d::Layer* pLayer);

protected:

	//移動処理
	virtual void moveFunc()override {
		//移動計算
		this->m_pMove->moveBy();
	};

	//アニメーション処理
	//virtual void animationFunc()override {}
	//反映処理
	//virtual void applyFunc()override {}

	//================================================
	// 
	//　ここまでにメンバに関するコードを追加
	//		
	//================================================
};