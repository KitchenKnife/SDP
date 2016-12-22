/*
* InputManager.h
*
*	2016/11/07	Osumi
*	2016/12/23	Shinya Ueba			
*
*/
#pragma once

#include "cocos2d.h"
#include "Constants.h"
#include "KeyboardInputController.h"
#include "GamepadInputController.h"


//コントローラータイプ
enum class CONTROLLER_TYPE : int
{
	KEYBORD = 0, //キーボード
	GAMEPAD = 1, //ゲームパッド
};



/*
 *
 *	入力管理
 *
 *	マルチタッチやコントローラーを２つにする際は CInputFlag を複数管理できるように作り替えなければならない
 *	理解出来るのであればこの部分をカスタマイズしてもかまわない
 */
class CInputManager {
private:
	// コンストラクタ
	CInputManager() ;
	CInputManager( const CInputManager& inputMgr_ ) ;
	
	// 共有インスタンス
	static CInputManager* m_sharedInputManager ;
public:
	// アクセスポイント
	static CInputManager* getInstance() ;
	// 破棄
	static void removeInstance() ;
	
	~CInputManager() ;
	
private:

	//入力コントローラーデータ群
	std::vector<CInputController* >* m_pInputControllers = NULL;
	
public:
	/**
	 *	@desc	キーコードからキータイプに変換
	 *	@param	キーコード
	 *	@return	キータイプ
	 */
	kInputType changeToInputTypeFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	
	/**
	 *	@desc	キーボードを押した際のイベント
	 *	@param	キーコード
	 *	@tips	入力管理を使用する際は入力受けつけが可能となっているノードの onKeyPressed で呼び出す
	 */
	void onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	
	/**
	 *	@desc	キーボードを離した際のイベント
	 *	@param	キーコード
	 *	@tips	入力管理を使用する際は入力受けつけが可能となっているノードの onKeyReleased で呼び出す
	 */
	void onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	

	/**
	 *	@desc	入力フラグのクリア
	 */
	void clearInputFlag(CONTROLLER_TYPE type) ;

	/**
	*	@desc	入力コントローラーの取得
	*	@param	コントローラータイプ
	*	@return	入力コントローラー
	*/
	CInputController* getInputController(CONTROLLER_TYPE type);
} ;

//EOF



