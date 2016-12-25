#pragma once
//==========================================
//
// File: KeyboardInputType.h
//
// キーボード入力タイプ ファイル
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"InputFlag.h"


/*
*	入力タイプ
*/
enum class kInputType : int {
	NONE = -1,
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	ESC = 4,
	SPACE = 5,
	Z = 6,
	X = 7,
	C = 8,
	A = 9,
	S = 10,
	D = 11,
};

/*
*	キーボード用入力フラグ
*/
class CKeyboardInputFlag :public CInputFlag{
public:
	bool m_up = false;		// 上キー
	bool m_down = false;	// 下キー
	bool m_left = false;	// 左キー
	bool m_right = false;	// 右キー
	bool m_esc = false;	// ESC キー
	bool m_space = false;	// スペースキー

	bool m_z = false;		// z キー
	bool m_x = false;		// x キー
	bool m_c = false;		// c キー

	bool m_a = false;		// a キー
	bool m_s = false;		// s キー
	bool m_d = false;		// d キー

	/**
	*	@desc	値のクリア
	*/
	virtual void clear(void)override;

	/**
	*	@desc	キーのフラグを上げる ( フラグアップ )
	*	@param	キーコード
	*/
	virtual void up(int keyType_)override;
	/**
	*	@desc	キーのフラグを下げる ( フラグダウン )
	*	@praram	キーコード
	*/
	virtual void down(int keyType_)override;

	/**
	*	@desc	指定したキーが押されているかどうかを取得
	*	@param	キータイプ
	*	@return	true...押されている
	*	@tips	入力のタイプによって変化
	*			キーボードタイプでは使用する必要はない
	*/
	virtual bool isKeyPressed(int keyType_)override;
};
//EOF