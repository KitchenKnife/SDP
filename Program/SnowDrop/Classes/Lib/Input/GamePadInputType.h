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
#include"cocos2d.h"
#include<Xinput.h>
#include"InputFlag.h"

//==========================================
// ライブラリ追加
//==========================================
#pragma comment (lib, "Xinput.lib")


//==========================================
//
// Enum : GamePadInputType
//
// ゲームパッドボタン入力タイプ
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
enum class GamePadInputType : int {
	NONE = -1,
	DPAD_UP = 0,	// 方向パッド上キー
	DPAD_DOWN = 1,	// 方向パッド下キー
	DPAD_LEFT = 2,	// 方向パッド左キー
	DPAD_RIGHT = 3,	// 方向パッド右キー
	START = 4,	// STARTボタン
	BACK = 5,	// BACKボタン
	LEFT_THUMB = 6,	// 左スティックボタン
	RIGHT_THUMB = 7,	// 右スティックボタン
	LEFT_SHOULDER = 8,	// LBボタン
	RIGHT_SHOULDER = 9,	// RBボタン
	A = 10,	// Aボタン
	B = 11,	// Bボタン
	X = 12,	// Xボタン
	Y = 13,	// Yボタン
	MAX_INPUT_TYPE
};



//==========================================
//
// Class: CGamePadInputFlag
//
// ゲームパッド用入力フラグ クラス
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
class CGamePadInputFlag : public CInputFlag
{
public:

	//プレス入力
	bool m_dpad_up = false;			// 方向パッド上ボタン
	bool m_dpad_down = false;		// 方向パッド下ボタン
	bool m_dpad_left = false;		// 方向パッド左ボタン
	bool m_dpad_right = false;		// 方向パッド右ボタン
	bool m_start = false;			// STARTボタン
	bool m_back = false;			// BACKボタン
	bool m_left_thumb = false;		// 左スティックボタン
	bool m_right_thumb = false;		// 右スティックボタン
	bool m_left_shoulder = false;	// LBボタン
	bool m_right_shoulder = false;	// RBボタン
	bool m_a = false;				// Aボタン
	bool m_b = false;				// Bボタン
	bool m_x = false;				// Xボタン
	bool m_y = false;				// Yボタン
	
	//トリガー入力
	bool m_dpad_upTrigger		= false;	// 方向パッド上ボタン
	bool m_dpad_downTrigger		= false;	// 方向パッド下ボタン
	bool m_dpad_leftTrigger		= false;	// 方向パッド左ボタン
	bool m_dpad_rightTrigger	= false;	// 方向パッド右ボタン
	bool m_startTrigger			= false;	// STARTボタン
	bool m_backTrigger			= false;	// BACKボタン
	bool m_left_thumbTrigger	= false;	// 左スティックボタン
	bool m_right_thumbTrigger	= false;	// 右スティックボタン
	bool m_left_shoulderTrigger = false;	// LBボタン
	bool m_right_shoulderTrigger = false;	// RBボタン
	bool m_aTrigger				= false;	// Aボタン
	bool m_bTrigger				= false;	// Bボタン
	bool m_xTrigger				= false;	// Xボタン
	bool m_yTrigger				= false;	// Yボタン



	//アナログ入力
	BYTE  m_left_trigger = 0;		// 左トリガー
	BYTE  m_right_trigger = 0;		// 右トリガー
	SHORT m_thumb_L_X = 0;			// 左スティックX軸
	SHORT m_thumb_L_Y = 0;			// 左スティックY軸
	SHORT m_thumb_R_X = 0;			// 右スティックX軸
	SHORT m_thumb_R_Y = 0;			// 右スティックY軸

private:

	bool m_arrayTriggerLastSate[(int)GamePadInputType::MAX_INPUT_TYPE];
public:

	/**
	*	@desc	コンストラクタ
	*/
	CGamePadInputFlag(void);

	/**
	*	@desc	デストラクタ
	*/
	~CGamePadInputFlag(void);

	/**
	*	@desc	値のクリア
	*/
	void clear(void)override;

	/**
	*	@desc	ボタンのフラグを上げる ( フラグアップ )
	*	@param	ボタンーコード
	*/
	void up(int bottomType_)override;
	/**
	*	@desc	ボタンのフラグを下げる ( フラグダウン )
	*	@praram	ボタンコード
	*/
	void down(int bottomType_)override;

	/**
	*	@desc	指定したボタンが押されているかどうかを取得
	*	@param	ボタンタイプ
	*	@return	true...押されている
	*/
	bool isKeyPressed(int bottomType_)override;

	/**
	*	@desc	指定したキーがトリガー入力状態を取得
	*	@param	ボタンタイプ
	*	@return	true...押されている
	*	@tips	入力のタイプによって変化
	*/
	bool isKeyTrigger(int bottomType_) override;
};
//EOF