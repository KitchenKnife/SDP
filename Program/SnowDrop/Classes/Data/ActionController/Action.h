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


//EOF