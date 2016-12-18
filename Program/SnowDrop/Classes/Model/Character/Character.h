
/*
* Character.h
*
*	2016/11/07	Osumi
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
//using namespace std;

//================================================
// キャラクタータイプ
//================================================
enum class CHARACTER_TYPE :int {
	NONE = -1,//無し
	PLAYER = 0,//プレイヤー
	ENEMY = 1,//敵
	BULLET = 2,//弾
	GIMMICK = 3,//ギミック
};

//================================================
// キャラクタークラス
//		全てのキャラクターの雛形となる抽象クラス
//================================================
class CCharacter :public Sprite {
public:

	//コンストラクタ
	CCharacter();

	//デストラクタ
	virtual ~CCharacter();

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update(float deltaTime)override;

	//アニメーションデータ群
	std::vector<CAnimation* >* m_pAnimations = NULL;

	//移動データ
	CMove* m_pMove = NULL;

	//適用させる物理演算群
	std::vector<CPhysical* >* m_pPhysicals = NULL;

	//行えるアクション群
	std::vector<CAction* >* m_pActions = NULL;

	//実体データ
	CBody* m_pBody = NULL;

	//衝突判定空間群
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//状態（派生先によってタイプが変化する）
	int m_state = 0;

	// ステータス
	CStatus* m_pStatus = NULL;

	//有効フラグ
	bool m_activeFlag = false;

	//生きてるか死んでるかのフラグ
	//true...生きている　false...死んでいる
	bool m_isAlive = false;

	//タグ
	int m_tag = 0;

	//キャラクタータイプ
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

protected:

	//移動処理
	virtual void moveFunc() = 0;

	//アニメーション処理
	virtual void animationFunc() = 0;

	//画面範囲端判定処理
//	virtual void endOfScreen() = 0;

	//状態チェック
	virtual void checkState() = 0;

	//反映処理
	virtual void applyFunc() = 0;

public:
	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	* @desc 衝突判定処理
	*/
	virtual void collisionAll() = 0;

	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	*		　画面下の際は0
	*/
	virtual void collisionBottomCallback(int event) {}

	/**
	* @desc 衝突した際のイベントコールバック
	*/
	virtual void collisionTopCallback(int event) {}

	/**
	* @desc 衝突した際のイベントコールバック
	*/
	virtual void collisionRightCallback(int event) {}

	/**
	* @desc 画面端領域と衝突した際のイベントコールバック
	*/
	virtual void collisionLeftCallback(int event) {}

	//================================================
	// 
	//　ここまでにメンバに関するコードを追加
	//		
	//================================================
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
	//キャラクターの集まり
	std::vector<CCharacter*>* m_pCharacters = NULL;

public:
	/**
	* @desc キャラタクーの集まりの参照を設定
	* @param 設定するキャラクターの集まりのアドレス
	*/
	void set(std::vector<CCharacter*>* pCharacters);

	/**
	* @desc キャラタクーの集まりのを取得
	* @return キャラクターの集まり
	*/
	std::vector<CCharacter*>* get();

	/**
	* @desc キャラタクー１体を取得
	* @param  添え字番号
	* @return キャラクター
	*/
	CCharacter* getAt(int index);

	/**
	* @desc キャラタクー１体を取得
	* @param  タグ
	* @return キャラクター
	*　　　　　存在しなければNULLを返す
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc キャラタクーの追加
	* @param  追加するキャラクター
	*/
	void add(CCharacter* pCharacter);

	/**
	* @desc キャラタクーの集まりの取り付けられている数を取得
	* @param  取り付けられている数
	*/
	int getSize();

};

//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
class CCharacterPartsFactory {
public:

	virtual ~CCharacterPartsFactory() {}

	virtual std::vector<CAnimation* >* getAnimations() = 0;
	virtual CMove* getMove() = 0;
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	virtual std::vector<CAction* >* getActions() = 0;
	virtual CBody* getBody() = 0;
	virtual CStatus* getStatus() = 0;
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
};