#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "../Character.h"


//================================================
// 
// ギミッククラス
//			
//================================================
class CGimmickCharacter :public CCharacter {
public:

	//コンストラクタ
	CGimmickCharacter();

	//デストラクタ
	virtual ~CGimmickCharacter();

	//初期化処理
	bool init()override;

	/**
	* @desc CREATE_FUNCマクロの中身をそのままもってきただけ
	* @tips		前回は敵出撃データという敵専用のクラスが存在していたので
	*			このクラスに直書きしても問題なかったが
	*　　　　　 今回はマップの情報による出現位置の決定という項目が必要になる。
	*　　　　　 マップをシングルトン化したので直書きしても問題ないように思われるが
	*　　　　　 このタイミングでこの場所のマップのタイルの位置情報が必要になる。
	*　　　　　最終的に必要になるのは位置だけだ。
	*　　　　　なので生成と同時に位置を取得したい。
	*　　　　　だがしかし、cocos2dｘの機能である自動でdeleteの機能も使いたい
	*　　　　　なので、create静的メンバ関数をカスタマイズする。
	*/
	//CREATE_FUNC(CEnemyCharacter);

	static CGimmickCharacter* create() {
		CGimmickCharacter* pRet = new(std::nothrow) CGimmickCharacter();

		if (pRet && pRet->init()) {
			pRet->autorelease();
			return pRet;
		}
		else {
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}


	//================================================
	// 
	// メンバーに関するコードの追加はここから
	//		
	//		
	//================================================

	//移動処理
	void moveFunc() override;

	//アニメーション処理
	void animationFunc()override;

	//空間との衝突判定処理
	void collisionAll()override;


	//状態チェック
	void checkState() override;

	//反映処理
	void applyFunc() override;

	void hits(CCharacter* pChara)override{}

	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc 下領域と衝突した際のイベントコールバック
	* @param マップチップID
	*		　画面下の際は0
	*/
	void collisionBottomCallback(int event)override {};

	/**
	* @desc 衝突した際のイベントコールバック
	*/
	void collisionTopCallback(int event)override {};

	/**
	* @desc 衝突した際のイベントコールバック
	*/
	void collisionRightCallback(int event)override {};

	/**
	* @desc 画面端領域と衝突した際のイベントコールバック
	*/
	void collisionLeftCallback(int event)override {};

	/**
	* @desc 衝突してきた後の処理
	* @param 衝突してきたキャラクター
	*/
	//void hits(CCharacter* pChara)override;

	//プレイヤーとの衝突判定後の処理
	void hitsPlayerCharacter(CCharacter* pChara);

	//プレイヤー以外との衝突判定後の処理
	void hitsNotPlayerCharacter(CCharacter* pChara);

};


