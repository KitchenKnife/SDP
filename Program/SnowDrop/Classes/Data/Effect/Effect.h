#pragma once
/*
 * Effect.h
 *
 *	2016/11/25	Osumi
 *
 */

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Data/Animation/Animation.h"
#include "Data/Move/Move.h"

//================================================
// エフェクトの基底クラス
//
//	2016/12/22
//									Author Harada
//================================================
class CEffect :public Sprite {
public:
	//================================================
	// 必須関数の列挙
	//================================================
	//コンストラクタ
	CEffect(){}

	//デストラクタ
	virtual ~CEffect(){}

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update(float delta)override;

	CREATE_FUNC(CEffect);

	//================================================
	// エフェクト基底クラスの基礎メンバ
	//================================================
	//アニメーションデータ
    CAnimation* m_pAnimations = NULL;

	//移動データ
	CMove* m_pMove = NULL;

	//有効フラグ
	bool m_activeFlag = true;

protected:

	//移動処理
	virtual void moveFunc();

	//アニメーション処理
	virtual void animationFunc();

	//反映処理
	virtual void applyFunc();
};

//================================================
// 指定したキャラクターに追随するエフェクトの基底クラス
//================================================
class CEffectFollowCharacter : public CEffect {
	
};


//=============================================
// エフェクトの集合体
//=============================================
class CEffectAggregate {
private:
	//=============================================
	// シングルトン設定
	//=============================================
	//共有インスタンス
	static CEffectAggregate* m_pSareedAggregate;

	//コンストラクタ
	CEffectAggregate(){}

public:
	//デストラクタ
	~CEffectAggregate();

	//共有インスタンスの取得
	static CEffectAggregate* getInstance();
	//共有インスタンスの破棄
	static void removeInstance();

private:
	//=============================================
	// Aggregate設定
	//=============================================
	//キャラクターの集まり
	std::vector<CEffect*>* m_pEffects = NULL;

public:
	/**
	 * @desc	キャラタクーの集まりの参照を設定
	 * @param	設定するキャラクターの集まりのアドレス
	 */
	void set(std::vector<CEffect*>* pCharacters);

	/**
	 * @desc	キャラタクーの集まりのを取得
	 * @return	キャラクターの集まり
	 */
	std::vector<CEffect*>* get();

	/**
 	 * @desc	配列番号から指定したキャラタクー１体を取得
	 * @param	添え字番号
	 * @return	キャラクター
	 */
	CEffect* getAt(int index);

	/**
	 * @desc	タグから指定したキャラタクー１体を取得
	 * @param	タグ
	 * @return	キャラクター
	 * @tips	存在しなければNULLを返す
	 */
	CEffect* getAtTag(int tag);

	/**
	 * @desc	キャラクターの追加
	 * @param	追加するキャラクター
	 */
	void add(CEffect* pCharacter);

	/**
	 * @desc	キャラタクーの集まりの取り付けられている数を取得
	 * @param	取り付けられている数
	 */
	int getSize();
};