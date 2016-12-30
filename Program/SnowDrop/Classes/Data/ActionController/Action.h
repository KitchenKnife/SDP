#pragma once
/*
* ActionController.h
*
*	2016/11/09	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"cocos2d.h"
#include"Constants.h"
#include "Lib/Math/Math.h"

//================================================
// 前方宣言に関するコードはここから書く
//================================================
class CCharacter;

//================================================
// アクションクラス
//================================================
class CAction {
public:
	//デストラクタ
	virtual ~CAction() {}

	//アクションを開始するたびに呼び出す
	virtual void start() = 0;

	//アクションの更新処理
	virtual void update(CCharacter* pChara) = 0;

	//アクションを終了するたびに呼び出す
	virtual void stop() = 0;


	/**
	* @desc	アクションの再起動
	* @param	再起動するキャラクター
	* @tips	標準的なアクションの再起動
	*　		ここではキャラクターは使用しない
	*/
	virtual void restart(CCharacter* pChara) {
		//アクションの停止
		this->stop();

		//アクションの開始
		this->start();

	}

};

//===================================================================
//　うろうろ動作
//===================================================================
class CActionWondering :public CAction {
private:
	

	//うろうろする方向
	int m_vec = 1;

	//アクション中かどうか true...アクション中
	bool m_inAction = false;

	//アクションが開始状態かどうか　true...開始状態
	bool m_isStart = false;

	//検索すべきターゲット
	//TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc コンストラクタ
	* @param 追跡すべきプレイヤータイプ
	*/
	CActionWondering(/*TARGET_TYPE type*/);

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了処理処理
	*/
	void stop() override;
};

//===================================================================
//　追跡アクション
//===================================================================
class CActionChase :public CAction {

private:

	//移動する方向
	int m_vec = 1;

	//アクション中かどうか true...アクション中
	bool m_inAction = false;

	//アクションが開始状態かどうか　true...開始状態
	bool m_isStart = false;

	//追跡動作を行う敵が飛行するかどうか
	bool m_isFlying = false;

public:
	/*
	* @desc コンストラクタ
	* @param キャラクターが飛ぶかどうか　false...飛ばない
	*/
	CActionChase(bool isFlying);

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了処理処理
	*/
	void stop() override;
};

//EOF