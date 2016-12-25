#pragma once
//==========================================
//
// File: GameOver.h
//
//	ゲームオーバーシーンファイル
//
// 2016/12/21
//						Author Koyuki Yamasaki
//
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"cocos2d.h"

//==========================================
//
// Class: CGameOver
//
// キーボード入力コントローラークラス
//
// 2016/12/18
//						Author Koyuki Yamasaki
//==========================================
class CGameOver : public cocos2d::Layer
{
public:
	/*
	* @desc コンストラクタ
	*/
	CGameOver();

	/*
	* @desc デストラクタ
	*/
	~CGameOver();

	/**
	* @desc		シーンの生成
	* @return	CTitleレイヤーを内包したシーンクラスインスタンス
	* @tips		静的メンバ関数
	*/
	static cocos2d::Scene* createScene();

	//create()静的メンバ関数の作成
	CREATE_FUNC(CGameOver);

	/**
	* @desc 初期化
	* @return true...成功 false...失敗
	*/
	bool init() override;

	/**
	* @desc  更新処理
	* @param 経過時間
	*/
	void update(float deltaTime) override;

	/**
	* @desc		タイトルに遷移
	* @param	タイトルレイヤーのインスタンス
	* @tips		スタートボタンが押された時に呼び出される
	*/
	void callbackChangeTitle(cocos2d::Ref* pSender);

};






//EOF