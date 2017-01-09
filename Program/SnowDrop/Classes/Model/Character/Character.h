/*
 * Character.h
 *
 *	2016/11/07	Osumi And Harada And Shinya Ueba
 *
 */
#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/Collision/Collision.h"
#include "Data/Collision/CollisionArea.h"
#include "Data/Status/Status.h"
#include "Data/StateMachine/StateMachine.h"

//================================================
// キャラクタータイプ
//================================================
enum class CHARACTER_TYPE :int {
	NONE		= -1,	//無し
	PLAYER_BOY	= 0,	//少年（プレイヤー）
	PLAYER_GIRL = 1,	//少女
	ENEMY		= 2,	//敵
	BULLET		= 3,	//弾
	GIMMICK		= 4,	//ギミック
	DAMAGE		= 5,	//ダメージ
};

//================================================
// キャラクタークラス
//		全てのキャラクターの雛形となる抽象クラス
//
//	2016/12/22
//									Author Harada
//================================================
class CCharacter :public Sprite {
public:
	//================================================ 
	// 必須関数の列挙	
	//================================================
	//コンストラクタ
	CCharacter();

	//デストラクタ
	virtual ~CCharacter();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update(float deltaTime)override;

	//================================================ 
	// キャラクター群の必要情報群
	//================================================
	//アニメーションデータ群
	std::vector<CAnimation* >* m_pAnimations = NULL;

	//移動データ
	CMove* m_pMove = NULL;

	//物理演算データ群
	std::vector<CPhysical* >* m_pPhysicals = NULL;

	//アクションデータ群マップ配列
	std::map<int, std::vector<CAction*>*> m_mapAction;

	//実体データ
	CBody* m_pBody = NULL;

	//衝突判定空間データ群
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//状態遷移データ
	CStateMachine* m_pStateMachine = NULL;


	//有効フラグ
	//表示・非表示関連
	bool m_activeFlag = false;

	//生死フラグ
	//表示している状態での生死関連
	bool m_isAlive = false;

	//大まかなタイプ別（キャラタイプ）
	int m_charaType = (int)CHARACTER_TYPE::NONE;

	//細かなタイプ別（タグ）
	int m_tag = 0;

	//キャラクターステータス
	CStatus m_status;

	//キャラクターの状態
	int m_state = 0;

	//キャラクターの移動状態
	int m_stateMove = 0;

	//キャラクターのアニメーションの状態
	int m_animationState = 0;

	//キャラクターのアクションの状態
	int m_actionState = 0;

	//攻撃を受けているかどうかのフラグ
	//true...受けている　false...受けていない
	bool m_underAttack = false;

protected:
	//================================================ 
	// キャラクタークラスの基本的な関数の列挙
	//	以下の関数はすべてのキャラクター派生クラス内でオーバーライドさせる。
	//================================================
	
	//移動処理
	virtual void moveFunc() = 0;

	//アニメーション処理
	virtual void animationFunc() = 0;

	//衝突判定処理
	virtual void collisionAll() = 0;

	//状態チェック
	virtual void checkState() = 0;

	//反映処理
	virtual void applyFunc() = 0;

public:
	/**
	 * @desc	キャラクター1体との衝突判定処理
	 * @param	キャラクターのアドレス
	 * @return	true...衝突した
	 */
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	 * @desc	他クラスから衝突判定を受けた際の処理
	 * @param	キャラクターのアドレス
	 */
	virtual void hits(CCharacter* pChara) = 0;

	/**
	*	@desc ＨＰの減少
	*	@param 減少する値（相手の攻撃力）
	*	@author		Shinya Ueba
	*/
	void decreaseHP(int attackPt);

	/**
	*	@desc ＨＰの全回復
	*	@author		Shinya Ueba
	*/
	void recoveryHp(void);

	/**
	*	@desc ＨＰの１回復
	*	@author		Shinya Ueba
	*/
	void cureHp(int hp);

	

	//================================================ 
	// イベントコールバック専用関数の列挙	
	//================================================
	/**
	 * @desc	下領域と衝突した際のイベントコールバック
	 * @param	マップチップID
	 *			画面下の際は0
	 */
	virtual void collisionBottomCallback(int event) {}

	/**
	 * @desc	衝突した際のイベントコールバック
	 */
	virtual void collisionTopCallback(int event) {}

	/**
	 * @desc	衝突した際のイベントコールバック
	 */
	virtual void collisionRightCallback(int event) {}

	/**
	 * @desc	画面端領域と衝突した際のイベントコールバック
	 */
	virtual void collisionLeftCallback(int event) {}
};

//EOF