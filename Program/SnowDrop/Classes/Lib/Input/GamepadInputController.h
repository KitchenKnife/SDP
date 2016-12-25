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
#include"GamePadInputType.h"
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
private:
	//入力状態フラグ
	CGamePadInputFlag m_inputFlag;

public:
	/**
	* @desc コンストラクタ
	* @author Shinya Ueba
	*/
	CGamepadInputController(void);

	/**
	* @desc デストラクタ
	* @author Shinya Ueba
	*/
	virtual ~CGamepadInputController(void);

	/*
	* @desc 左移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getLeftMoveFlag(void)override;

	/*
	* @desc 右移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getRightMoveFlag(void)override;

	/*
	* @desc ジャンプ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getJumpFlag(void)override;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getAttackFlag(void)override;

	/*
	* @desc 装備入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getEquipFlag(void);

	/*
	* @desc 装備解除フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getUnEquipFlag(void);


	/*
	* @desc 手をつなぐフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getHolodHandsFlag(void)override;

	/*
	* @desc お姫様抱っこフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getHugFlag(void)override;

	/*
	* @desc	ゲーム終了フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getGameExitFlag(void)override;


	/**
	*	@desc デバッグモードフラグ取得
	*	@return true...入力あり　false...入力なし
	*/
	bool getDebugModeFlag(void)override;


	/**
	* @desc 入力フラグインスタンスの取得
	* @return　 入力フラグインスタンス
	*/
	CInputFlag* getInputFlagInstance(void)override;
};
//EOF