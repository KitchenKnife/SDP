#pragma once
//==========================================
//
// File: GamepadInputController.h
//
// ゲームパッド入力コントローラー ファイル
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
//#include"GamePadInputType.h"
#include"InputController.h"


//==========================================
//
// Class: CGamepadInputController
//
// ゲームパッド入力コントローラークラス
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
class CGamepadInputController : public CInputController
{
//private:
//	//ゲームパッド最大接続数(今回は１)
//	static const int MAX_CONTROLLERS = 1;
//
//	//ゲームパッド状態データ群
//	//CONTROLER_STATE m_controllers[MAX_CONTROLLERS];
//
//
//	//入力状態フラグ
//	CGamePadInputFlag m_inputFlag;
//
//public:
//	/**
//	* @desc コンストラクタ
//	* @author Shinya Ueba
//	*/
//	CGamepadInputController(void);
//
//	/**
//	* @desc デストラクタ
//	* @author Shinya Ueba
//	*/
//	virtual ~CGamepadInputController(void);
//
//	/**
//	* @desc 更新処理
//	* @author Shinya Ueba
//	*/
//	void update(void);
//
//	/*
//	* @desc 左移動入力フラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getLeftMoveFlag(void)override;
//
//	/*
//	* @desc 右移動入力フラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getRightMoveFlag(void)override;
//
//	/*
//	* @desc ジャンプ入力フラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getJumpFlag(void)override;
//
//	/*
//	* @desc 攻撃入力フラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getAttackFlag(void)override;
//
//	/*
//	* @desc 手をつなぐフラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getHolodHandsFlag(void)override;
//
//	/*
//	* @desc お姫様抱っこフラグ取得
//	* @return true...入力あり　false...入力なし
//	* @author Shinya Ueba
//	*/
//	bool getHugFlag(void)override;

	/**
	* @desc 入力フラグインスタンスの取得
	* @return　 入力フラグインスタンス
	*/
	//CInputFlag* getInputFlagInstance(void)override;
};
//EOF