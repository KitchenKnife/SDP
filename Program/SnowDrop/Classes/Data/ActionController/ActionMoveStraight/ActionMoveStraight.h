#pragma once
//==========================================
//
// File: ActionMoveStraight.h
//
// アクション　直線移動 ヘッダーファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../Action.h"


//==========================================
//
// Class: ActionMoveStraight
//
// アクション　直線移動		クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CActionMoveStraight : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionMoveStraight();



	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};
//EOF