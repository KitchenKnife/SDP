/*
* InputManager.cpp
*
*	2016/11/07	Osumi
*
*/

#include "InputManager.h"



/*
 *
 *	入力管理
 *
 */
// 共有インスタンス本体
CInputManager* CInputManager::m_sharedInputManager = NULL ;

CInputManager::CInputManager() {

	// 入力フラグの生成と設定
	//this->setInputFlag( new CKeyboardInputFlag() ) ;

	//入力コントローラーデータ群の生成
	this->m_pInputControllers = new std::vector<CInputController*>();
	//キーボード入力コントローラーの生成と取り付け
	this->m_pInputControllers->push_back(new CKeyboardInputController());
	//ゲームパッド入力コントローラーの生成と取り付け
	//this->m_pInputControllers->push_back(new CGamepadInputController());

}

CInputManager::CInputManager( const CInputManager& inputMgr_ ) {}

// アクセスポイント
std::mutex inputmanager_singleton_mtx_;
CInputManager* CInputManager::getInstance() {
	std::lock_guard<std::mutex> lock( inputmanager_singleton_mtx_ ) ;
	if ( CInputManager::m_sharedInputManager == NULL ) {
		CInputManager::m_sharedInputManager = new CInputManager() ;
	}
	return CInputManager::m_sharedInputManager ;
}


// デストラクタ
CInputManager::~CInputManager()
{
	//入力コントローラーの削除
	for (CInputController* pController : (*this->m_pInputControllers)) {
		SAFE_DELETE(pController);
	}
	SAFE_DELETE(this->m_pInputControllers);
}

void CInputManager::removeInstance() {

	SAFE_DELETE( CInputManager::m_sharedInputManager ) ;
}


/**
 *	@desc	キーコードからキータイプに変換
 *	@param	キーコード
 *	@return	キータイプ
 */
kInputType CInputManager::changeToInputTypeFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode_ ) {

	// エスケープキーかどうか判定
	if ( cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE == keyCode_ )
	{
		// エスケープキーを返す
		return kInputType::ESC ;
	}
	// スペースキーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_SPACE == keyCode_ )
	{
		// スペースキーを返す
		return kInputType::SPACE ;
	}
	// 上矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode_ )
	{
		// 上矢印キーを返す
		return kInputType::UP ;
	}
	// 下矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode_ )
	{
		// 下矢印キーを返す
		return kInputType::DOWN ;
	}
	// 左矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode_ )
	{
		// 左矢印キーを返す
		return kInputType::LEFT ;
	}
	// 右矢印キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode_ )
	{
		// 右矢印キーを返す
		return kInputType::RIGHT ;
	}
	// Z キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_Z == keyCode_ )
	{
		// Z キーを返す
		return kInputType::Z ;
	}
	// X キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_X == keyCode_ )
	{
		// X キーを返す
		return kInputType::X ;
	}
	// C キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_C == keyCode_ )
	{
		// C キーを返す
		return kInputType::C ;
	}
	// A キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_A == keyCode_ )
	{
		// A キーを返す
		return kInputType::A ;
	}
	// S キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_S == keyCode_ )
	{
		// S キーを返す
		return kInputType::S ;
	}
	// D キーかどうか判定
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_D == keyCode_ )
	{
		// D キーを返す
		return kInputType::D ;
	}
	
	// エラー
	return kInputType::NONE ;
}

/**
 *	@desc	キーボードを押した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
	if ((*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]) {

		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]->getInputFlagInstance();
		pointerInputFlag->up((int)this->changeToInputTypeFromKeyCode(keyCode_));;
	}
}

/**
 *	@desc	キーボードを離した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
	if ((*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]) {

		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]->getInputFlagInstance();
		pointerInputFlag->down((int) this->changeToInputTypeFromKeyCode( keyCode_ ) ) ;
	}
}


/**
 *	@desc	入力フラグのクリア
 */
void CInputManager::clearInputFlag(CONTROLLER_TYPE type) {
	if ((*this->m_pInputControllers)[(int)type]) {
		
		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)type]->getInputFlagInstance();
		pointerInputFlag->clear() ;
	}
}

/**
*	@desc	入力コントローラーの取得
*	@param	コントローラータイプ
*	@return	入力コントローラー
*/
CInputController* CInputManager::getInputController(CONTROLLER_TYPE type)
{
	return (*this->m_pInputControllers)[(int)type];
}