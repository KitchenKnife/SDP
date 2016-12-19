
/*
* Character.h
*
*	2016/11/07	Osumi And Harada
*
*/

/*collision(CCharacter )*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/ActionController/PlayerActionController/PlayerActionController.h"
#include "Data/Collision/Collision.h"
#include "Data/Collision/CollisionArea.h"
#include "Data/Status/Status.h"

#include <stdio.h>

using namespace cocos2d;

//================================================
// キャラクタータイプ
//================================================
enum class CHARACTER_TYPE :int {
	NONE = -1,	//無し
	PLAYER_BOY = 0,	//少年（プレイヤー）
	PLAYER_GIRL = 1,	//少女
	ENEMY = 2,	//敵
	BULLET = 3,	//弾
	GIMMICK = 4,//ギミック
};

//================================================
// キャラクタークラス
//		全てのキャラクターの雛形となる抽象クラス
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

	//アクションデータ群
	std::vector<CAction* >* m_pActions = NULL;

	//実体データ
	CBody* m_pBody = NULL;

	//衝突判定空間データ群
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//ステータスデータ
	CStatus* m_pStatus = NULL;

	//状態データ
	int m_state = 0;

	//有効フラグ
	//表示・非表示関連
	bool m_activeFlag = false;

	//生死フラグ
	//表示している状態での生死関連
	bool m_isAlive = false;

	//大まかなタイプ別（キャラタイプ）
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

	//細かなタイプ別（タグ）
	int m_tag = 0;

protected:
	//================================================ 
	// キャラクター群の基本的にアップデートする関数の列挙
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
	//================================================ 
	// 衝突判定用関数の列挙
	//================================================
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

//=============================================
// キャラクターの集合体
//	シングルトン化させてほかのファイルで扱えるようにしておくこと
//=============================================
class CCharacterAggregate {
private:
	//=============================================
	// シングルトン設定はここから
	//=============================================
	//共有インスタンス
	static CCharacterAggregate* m_pSareedAggregate;

	//コンストラクタ
	CCharacterAggregate();

public:
	//デストラクタ
	~CCharacterAggregate();

	//共有インスタンスの取得
	static CCharacterAggregate* getInstance();
	//共有インスタンスの破棄
	static void removeInstance();
	//=============================================
	// シングルトン設定はここまで
	//=============================================

private:
	//=============================================
	// Aggregate設定はここから
	//=============================================
	//キャラクターの集まり
	std::vector<CCharacter*>* m_pCharacters = NULL;

public:
	/**
	 * @desc	キャラタクーの集まりの参照を設定
	 * @param	設定するキャラクターの集まりのアドレス
	 */
	void set(std::vector<CCharacter*>* pCharacters);

	/**
	 * @desc	キャラタクーの集まりのを取得
	 * @return	キャラクターの集まり
	 */
	std::vector<CCharacter*>* get();

	/**
	 * @desc	配列番号から指定したキャラタクー１体を取得
	 * @param	添え字番号
	 * @return	キャラクター
 	 */
	CCharacter* getAt(int index);

	/**
	 * @desc	タグから指定したキャラタクー１体を取得
	 * @param	タグ
	 * @return	キャラクター
	 * @tips	存在しなければNULLを返す
	 */
	CCharacter* getAtTag(int tag);

	/**
	 * @desc	キャラクターの追加
	 * @param	追加するキャラクター
	 */
	void add(CCharacter* pCharacter);

	/**
	 * @desc	キャラタクーの集まりの取り付けられている数を取得
	 * @param	取り付けられている数
	 */
	int getSize();
};

//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
class CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CCharacterPartsFactory() {}

	//アニメーションデータ群の実体を生成して返す
	virtual std::vector<CAnimation* >* getAnimations() = 0;
	//移動データの実体を生成して返す
	virtual CMove* getMove() = 0;
	//物理演算データ群の実体を生成して返す
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	//アクションデータ群の実体を生成して返す
	virtual std::vector<CAction* >* getActions() = 0;
	//実体データの実体を生成して返す
	virtual CBody* getBody() = 0;
	//ステータスデータの実体を生成して返す
	virtual CStatus* getStatus() = 0;
	//衝突判定空間データ群の実体を生成して返す
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
};