#pragma once
#include "Model/Character/Character.h"

class CPlayerCharacterBoy;

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
	//プレイヤー（少年）のアドレス
	CPlayerCharacterBoy* m_pPlayerChara;

	//手繋ぎ可能マークのインスタンス
	cocos2d::CCParticleSystemQuad* m_pActionMark = NULL;
	
	//マークのパーティクル速度...1.0fで通常速度
	int m_durationMark = 0;
	
	//マークのパーティクルを表示するカウンター
	int m_counterActionMark = 0;

	/**
	 * @desc	プレイヤーと少女のアクション可能マークを出現させるかチェックする
	 */
	void checkPlayerAndGirlActionMark(void);

	/**
	 * @desc	プレイヤーと少女のアクション可能マークが出ているか取得
	 * @author	Shinya Ueba
	 */
	void setPlayerAndGirlActionMark(void);

	/**
	 * @desc	プレイヤーと少女のアクション可能マークを作成してガールに取り付ける
	 * @return	true...マークが出現している。
	 * @author	Shinya Ueba
	 */
	bool getPlayerAndGirlActionMark(void);

};
