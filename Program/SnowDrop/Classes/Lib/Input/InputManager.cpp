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

	//入力コントローラーデータ群の生成
	this->m_pInputControllers = new std::vector<CInputController*>();
	//キーボード入力コントローラーの生成と取り付け
	this->m_pInputControllers->push_back(new CKeyboardInputController());
	//ゲームパッド入力コントローラーの生成と取り付け
	this->m_pInputControllers->push_back(new CGamepadInputController());

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
* @desc 更新処理
*/
void CInputManager::update(void)
{
	//ゲームパッドの接続状態の更新
	this->updateGamePadConnectState();
	//ゲームパッドの入力状態の更新
	this->updateGamePadInputState();
}

/**
* @desc GamePadの接続状態の更新
*/
HRESULT CInputManager::updateGamePadConnectState(void)
{
	DWORD dwResult;
	for (DWORD i = 0; i < MAX_CONTROLLERS; i++)
	{
		//ゲームパッドの接続状態を取得
		dwResult = XInputGetState(i, &this->m_controllers[i].state);

		if (dwResult == ERROR_SUCCESS)
		{
			this->m_controllers[i].boolConnected = true;
			this->m_controllerType = CONTROLLER_TYPE::GAMEPAD;
		}
		else
		{
			this->m_controllers[i].boolConnected = false;
		
			this->m_controllerType = CONTROLLER_TYPE::KEYBORD;
		}
	}
	return S_OK;
}

/**
* @desc GamePadの入力状態の更新
*/
void CInputManager::updateGamePadInputState(void)
{
	for (DWORD i = 0; i < MAX_CONTROLLERS; i++)
	{
		if (this->m_controllers[i].boolConnected)
		{
			WORD wButtons = this->m_controllers[i].state.Gamepad.wButtons;
			/*
			if (g_bDeadZoneOn)
			{
				// Zero value if thumbsticks are within the dead zone
				if ((g_Controllers[i].state.Gamepad.sThumbLX < INPUT_DEADZONE &&
					g_Controllers[i].state.Gamepad.sThumbLX > -INPUT_DEADZONE) &&
					(g_Controllers[i].state.Gamepad.sThumbLY < INPUT_DEADZONE &&
						g_Controllers[i].state.Gamepad.sThumbLY > -INPUT_DEADZONE))
				{
					g_Controllers[i].state.Gamepad.sThumbLX = 0;
					g_Controllers[i].state.Gamepad.sThumbLY = 0;
				}

				if ((g_Controllers[i].state.Gamepad.sThumbRX < INPUT_DEADZONE &&
					g_Controllers[i].state.Gamepad.sThumbRX > -INPUT_DEADZONE) &&
					(g_Controllers[i].state.Gamepad.sThumbRY < INPUT_DEADZONE &&
						g_Controllers[i].state.Gamepad.sThumbRY > -INPUT_DEADZONE))
				{
					g_Controllers[i].state.Gamepad.sThumbRX = 0;
					g_Controllers[i].state.Gamepad.sThumbRY = 0;
				}
			}
			*/

			this->changeToInputTypeFromXInput(wButtons);
		}
	}
}


/**
*	@desc	キーコードからキータイプに変換
*	@param	キーコード
*	@return	キータイプ
*/
void CInputManager::changeToInputTypeFromXInput(DWORD wBottons)
{
	checkPressBotton(wBottons, XINPUT_GAMEPAD_DPAD_UP,(int)GamePadInputType::DPAD_UP);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_DPAD_DOWN, (int)GamePadInputType::DPAD_DOWN);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_DPAD_LEFT, (int)GamePadInputType::DPAD_LEFT);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_DPAD_RIGHT, (int)GamePadInputType::DPAD_RIGHT);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_START, (int)GamePadInputType::START);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_BACK, (int)GamePadInputType::BACK);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_LEFT_THUMB, (int)GamePadInputType::LEFT_THUMB);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_RIGHT_THUMB, (int)GamePadInputType::RIGHT_THUMB);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_LEFT_SHOULDER, (int)GamePadInputType::LEFT_SHOULDER);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_RIGHT_SHOULDER, (int)GamePadInputType::RIGHT_SHOULDER);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_A, (int)GamePadInputType::A);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_B, (int)GamePadInputType::B);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_X, (int)GamePadInputType::X);
	checkPressBotton(wBottons, XINPUT_GAMEPAD_Y, (int)GamePadInputType::Y);

}

/**
*	@desc	キーコードからキータイプに変換
*	@param	キーコード
*	@return	キータイプ
*/
void CInputManager::checkPressBotton(DWORD wBottons, DWORD mask,int setType)
{

	cocos2d::log("INPUT%ld", (wBottons));
	cocos2d::log("BYTE%ld", (mask));
	//cocos2d::log("%ld", (wBottons & mask));

	CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)CONTROLLER_TYPE::GAMEPAD]->getInputFlagInstance();
	if (wBottons & mask)
	{
		
		cocos2d::log("HEY");
		pointerInputFlag->up(setType);
	}
	else
	{
		pointerInputFlag->down(setType);
	}
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
void CInputManager::clearInputFlag(void) {
	if ((*this->m_pInputControllers)[(int)this->m_controllerType]) {
		
		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)this->m_controllerType]->getInputFlagInstance();
		pointerInputFlag->clear() ;
	}
}

/**
*	@desc	入力コントローラーの取得
*	@param	コントローラータイプ
*	@return	入力コントローラー
*/
CInputController* CInputManager::getInputController(void)
{
	return (*this->m_pInputControllers)[(int)this->m_controllerType];
}