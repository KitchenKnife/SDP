#pragma once
////==========================================
////
//// File: GamepadInputController.h
////
//// ゲームパッド入力コントローラー ファイル
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//
////==========================================
//// ヘッダインクルード
////==========================================
//#include<Xinput.h>
//
////==========================================
//// ライブラリ追加
////==========================================
//#pragma comment (lib, "XInput.lib")
//
//
//
////==========================================
////
//// Struct: CONTROLLER_STATE
////
//// ゲームパッド状態管理 構造体
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//
///*
//struct CONTROLER_STATE
//{
//	XINPUT_STATE state;
//	bool bConnected;
//};*/
//
//
//
////==========================================
////
//// Enum : GamePadInputType
////
//// ゲームパッドボタン入力タイプ
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//enum class GamePadInputType : int {
//	NONE = -1,
//	DPAD_UP = 0,	// 方向パッド上キー
//	DPAD_DOWN = 1,	// 方向パッド下キー
//	DPAD_LEFT = 2,	// 方向パッド左キー
//	DPAD_RIGHT = 3,	// 方向パッド右キー
//	START = 4,	// STARTボタン
//	BACK = 5,	// BACKボタン
//	LEFT_THUMB = 6,	// 左スティックボタン
//	RIGHT_THUMB = 7,	// 右スティックボタン
//	LEFT_SHOULDER = 8,	// LBボタン
//	RIGHT_SHOULDER = 9,	// RBボタン
//	A = 10,	// Aボタン
//	B = 11,	// Bボタン
//	X = 12,	// Xボタン
//	Y = 13,	// Yボタン	
//};
//
//
//
////==========================================
////
//// Class: CGamePadInputFlag
////
//// ゲームパッド用入力フラグ クラス
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//class CGamePadInputFlag {
//public:
//	bool m_dpad_up = false;	// 方向パッド上ボタン
//	bool m_dpad_down = false;	// 方向パッド下ボタン
//	bool m_dpad_left = false;	// 方向パッド左ボタン
//	bool m_dpad_right = false;	// 方向パッド右ボタン
//	bool m_start = false;	// STARTボタン
//	bool m_back = false;	// BACKボタン
//	bool m_left_thumb = false;	// 左スティックボタン
//	bool m_right_thumb = false;	// 右スティックボタン
//	bool m_left_shoulder = false;	// LBボタン
//	bool m_right_shoulder = false;	// RBボタン
//	bool m_a = false;	// Aボタン
//	bool m_b = false;	// Bボタン
//	bool m_x = false;	// Xボタン
//	bool m_y = false;	// Yボタン
//	BYTE  m_left_trigger = 0;		// 左トリガー
//	BYTE  m_right_trigger = 0;		// 右トリガー
//	SHORT m_thumb_L_X = 0;		// 左スティックX軸
//	SHORT m_thumb_L_Y = 0;		// 左スティックY軸
//	SHORT m_thumb_R_X = 0;		// 右スティックX軸
//	SHORT m_thumb_R_Y = 0;		// 右スティックY軸
//
//								/**
//								*	@desc	値のクリア
//								*/
//	virtual void clear();
//
//	/**
//	*	@desc	ボタンのフラグを上げる ( フラグアップ )
//	*	@param	ボタンーコード
//	*/
//	virtual void up(GamePadInputType bottomType_);
//	/**
//	*	@desc	ボタンのフラグを下げる ( フラグダウン )
//	*	@praram	ボタンコード
//	*/
//	virtual void down(GamePadInputType bottomType_);
//
//	/**
//	*	@desc	指定したボタンが押されているかどうかを取得
//	*	@param	ボタンタイプ
//	*	@return	true...押されている
//	*/
//	virtual bool isBottomPressed(GamePadInputType bottomType_);
//};
//EOF