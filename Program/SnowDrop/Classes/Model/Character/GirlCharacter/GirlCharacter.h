#pragma once
#include "Model/Character/Character.h"

//================================================
// 少女クラス
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerCharacterGirl :public CCharacter {
public:
	//================================================ 
	// 必須関数の列挙	
	//================================================
	//コンストラクタ
	CPlayerCharacterGirl();

	//デストラクタ
	~CPlayerCharacterGirl();

	CREATE_FUNC(CPlayerCharacterGirl);

	//初期化処理
	bool init()override;

	//================================================ 
	// キャラクタークラスの基本的な関数の列挙
	//	以下の関数はすべてのキャラクター派生クラス内でオーバーライドさせる。
	//================================================
	//移動処理
	virtual void moveFunc();

	//アニメーション処理
	virtual void animationFunc();

	//衝突判定処理
	virtual void collisionAll();

	//状態チェック
	virtual void checkState();

	//反映処理
	virtual void applyFunc();

	/**
	 * @desc	キャラクター1体との衝突判定処理
	 * @param	キャラクターのアドレス
	 * @return	true...衝突した
	 */
	virtual bool collision(CCharacter* pChara);

	/**
	 * @desc	他クラスから衝突判定を受けた際の処理
	 * @param	キャラクターのアドレス
	 */
	virtual void hits(CCharacter* pChara);

	//================================================ 
	// CPlayerCharacterGirlクラス専用メンバ
	//================================================
	//少女の状態
	enum class GIRL_STATE {
		STAND	= 0,	//待機
	};

	//少女の状態
	int m_state = (int)GIRL_STATE::STAND;

};
