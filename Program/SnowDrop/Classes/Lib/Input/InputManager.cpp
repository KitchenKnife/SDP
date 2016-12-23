/*
* InputManager.cpp
*
*	2016/11/07	Osumi
*
*/

#include "InputManager.h"



/*
 *
 *	���͊Ǘ�
 *
 */
// ���L�C���X�^���X�{��
CInputManager* CInputManager::m_sharedInputManager = NULL ;

CInputManager::CInputManager() {

	//���̓R���g���[���[�f�[�^�Q�̐���
	this->m_pInputControllers = new std::vector<CInputController*>();
	//�L�[�{�[�h���̓R���g���[���[�̐����Ǝ��t��
	this->m_pInputControllers->push_back(new CKeyboardInputController());
	//�Q�[���p�b�h���̓R���g���[���[�̐����Ǝ��t��
	this->m_pInputControllers->push_back(new CGamepadInputController());

}

CInputManager::CInputManager( const CInputManager& inputMgr_ ) {}

// �A�N�Z�X�|�C���g
std::mutex inputmanager_singleton_mtx_;
CInputManager* CInputManager::getInstance() {
	std::lock_guard<std::mutex> lock( inputmanager_singleton_mtx_ ) ;
	if ( CInputManager::m_sharedInputManager == NULL ) {
		CInputManager::m_sharedInputManager = new CInputManager() ;
	}
	return CInputManager::m_sharedInputManager ;
}


// �f�X�g���N�^
CInputManager::~CInputManager()
{
	//���̓R���g���[���[�̍폜
	for (CInputController* pController : (*this->m_pInputControllers)) {
		SAFE_DELETE(pController);
	}
	SAFE_DELETE(this->m_pInputControllers);
}

void CInputManager::removeInstance() {

	SAFE_DELETE( CInputManager::m_sharedInputManager ) ;
}


/**
* @desc �X�V����
*/
void CInputManager::update(void)
{
	//�Q�[���p�b�h�̐ڑ���Ԃ̍X�V
	this->updateGamePadConnectState();
	//�Q�[���p�b�h�̓��͏�Ԃ̍X�V
	this->updateGamePadInputState();
}

/**
* @desc GamePad�̐ڑ���Ԃ̍X�V
*/
HRESULT CInputManager::updateGamePadConnectState(void)
{
	DWORD dwResult;
	for (DWORD i = 0; i < MAX_CONTROLLERS; i++)
	{
		//�Q�[���p�b�h�̐ڑ���Ԃ��擾
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
* @desc GamePad�̓��͏�Ԃ̍X�V
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
*	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
*	@param	�L�[�R�[�h
*	@return	�L�[�^�C�v
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
*	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
*	@param	�L�[�R�[�h
*	@return	�L�[�^�C�v
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
 *	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
 *	@param	�L�[�R�[�h
 *	@return	�L�[�^�C�v
 */
kInputType CInputManager::changeToInputTypeFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode_ ) {

	// �G�X�P�[�v�L�[���ǂ�������
	if ( cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE == keyCode_ )
	{
		// �G�X�P�[�v�L�[��Ԃ�
		return kInputType::ESC ;
	}
	// �X�y�[�X�L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_SPACE == keyCode_ )
	{
		// �X�y�[�X�L�[��Ԃ�
		return kInputType::SPACE ;
	}
	// ����L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode_ )
	{
		// ����L�[��Ԃ�
		return kInputType::UP ;
	}
	// �����L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode_ )
	{
		// �����L�[��Ԃ�
		return kInputType::DOWN ;
	}
	// �����L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode_ )
	{
		// �����L�[��Ԃ�
		return kInputType::LEFT ;
	}
	// �E���L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode_ )
	{
		// �E���L�[��Ԃ�
		return kInputType::RIGHT ;
	}
	// Z �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_Z == keyCode_ )
	{
		// Z �L�[��Ԃ�
		return kInputType::Z ;
	}
	// X �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_X == keyCode_ )
	{
		// X �L�[��Ԃ�
		return kInputType::X ;
	}
	// C �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_C == keyCode_ )
	{
		// C �L�[��Ԃ�
		return kInputType::C ;
	}
	// A �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_A == keyCode_ )
	{
		// A �L�[��Ԃ�
		return kInputType::A ;
	}
	// S �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_S == keyCode_ )
	{
		// S �L�[��Ԃ�
		return kInputType::S ;
	}
	// D �L�[���ǂ�������
	else if ( cocos2d::EventKeyboard::KeyCode::KEY_D == keyCode_ )
	{
		// D �L�[��Ԃ�
		return kInputType::D ;
	}
	
	// �G���[
	return kInputType::NONE ;
}

/**
 *	@desc	�L�[�{�[�h���������ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 */
void CInputManager::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
	if ((*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]) {

		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]->getInputFlagInstance();
		pointerInputFlag->up((int)this->changeToInputTypeFromKeyCode(keyCode_));;
	}
}

/**
 *	@desc	�L�[�{�[�h�𗣂����ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 */
void CInputManager::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
	if ((*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]) {

		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)CONTROLLER_TYPE::KEYBORD]->getInputFlagInstance();
		pointerInputFlag->down((int) this->changeToInputTypeFromKeyCode( keyCode_ ) ) ;
	}
}


/**
 *	@desc	���̓t���O�̃N���A
 */
void CInputManager::clearInputFlag(void) {
	if ((*this->m_pInputControllers)[(int)this->m_controllerType]) {
		
		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)this->m_controllerType]->getInputFlagInstance();
		pointerInputFlag->clear() ;
	}
}

/**
*	@desc	���̓R���g���[���[�̎擾
*	@param	�R���g���[���[�^�C�v
*	@return	���̓R���g���[���[
*/
CInputController* CInputManager::getInputController(void)
{
	return (*this->m_pInputControllers)[(int)this->m_controllerType];
}