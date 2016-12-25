#pragma once
//==========================================
//
// File: InputFlag.h
//
// 入力フラグ基底クラス ヘッダファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
//
// File: InputFlag.h
//
// 入力フラグ基底クラス ヘッダファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CInputFlag
{
public:
	/**
	* @desc コンストラクタ
	*/
	CInputFlag(void);

	/**
	* @desc デストラクタ
	*/
	virtual ~CInputFlag(void);

	/**
	*	@desc	値のクリア
	*/
	virtual void clear()=0;

	/**
	*	@desc	入力のフラグを上げる ( フラグアップ )
	*	@param	コード
	*/
	virtual void up(int Type_) = 0;
	/**
	*	@desc	入力のフラグを下げる ( フラグダウン )
	*	@praram	キーコード
	*/
	virtual void down(int Type_) = 0;

	/**
	*	@desc	指定したキーが押されているかどうかを取得
	*	@param	キータイプ
	*	@return	true...押されている
	*	@tips	入力のタイプによって変化
	*			キーボードタイプでは使用する必要はない
	*/
	virtual bool isKeyPressed(int Type_) = 0;

	/**
	*	@desc	指定したキーがトリガー入力状態を取得
	*	@param	キータイプ
	*	@return	true...押されている
	*	@tips	入力のタイプによって変化
	*/
	virtual bool isKeyTrigger(int keyType_)=0;
};