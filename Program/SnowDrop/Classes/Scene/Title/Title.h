#pragma once
//==========================================
//
// File: Title.h
//
// タイトルシーンファイル
//
// 2016/12/21
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"cocos2d.h"

//==========================================
//
// Class: CTitle
//
// キーボード入力コントローラークラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CTitle : public cocos2d::Layer
{
public:
	/*
	* @desc コンストラクタ
	*/
	CTitle();

	/*
	* @desc デストラクタ
	*/
	~CTitle();

	/**
	* @desc		シーンの生成
	* @return	CTitleレイヤーを内包したシーンクラスインスタンス
	* @tips		静的メンバ関数
	*/
	static cocos2d::Scene* createScene();

	//create()静的メンバ関数の作成
	CREATE_FUNC(CTitle);

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
	* @desc		ゲームメインに遷移
	* @param	タイトルレイヤーのインスタンス
	* @tips		スタートボタンが押された時に呼び出される
	*/
	void callbackChangeGameMain(cocos2d::Ref* pSender);

	/*
	* @desc　ゲーム終了
	* @param タイトルレイヤーのインスタンス
	* @tips	 ゲーム終了ボタンが押された時に呼び出される
	*/
	void callbackEndGame(cocos2d::Ref* pSender);
};
//EOF