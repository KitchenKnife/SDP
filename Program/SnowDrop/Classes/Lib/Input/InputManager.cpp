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

	// ���̓t���O�̐����Ɛݒ�
	//this->setInputFlag( new CKeyboardInputFlag() ) ;

	//���̓R���g���[���[�f�[�^�Q�̐���
	this->m_pInputControllers = new std::vector<CInputController*>();
	//�L�[�{�[�h���̓R���g���[���[�̐����Ǝ��t��
	this->m_pInputControllers->push_back(new CKeyboardInputController());
	//�Q�[���p�b�h���̓R���g���[���[�̐����Ǝ��t��
	//this->m_pInputControllers->push_back(new CGamepadInputController());

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
void CInputManager::clearInputFlag(CONTROLLER_TYPE type) {
	if ((*this->m_pInputControllers)[(int)type]) {
		
		CInputFlag* pointerInputFlag = (*this->m_pInputControllers)[(int)type]->getInputFlagInstance();
		pointerInputFlag->clear() ;
	}
}

/**
*	@desc	���̓R���g���[���[�̎擾
*	@param	�R���g���[���[�^�C�v
*	@return	���̓R���g���[���[
*/
CInputController* CInputManager::getInputController(CONTROLLER_TYPE type)
{
	return (*this->m_pInputControllers)[(int)type];
}