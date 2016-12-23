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


//�R���g���[���[�^�C�v
enum class CONTROLLER_TYPE : int
{
	KEYBORD = 0, //�L�[�{�[�h
	GAMEPAD = 1, //�Q�[���p�b�h
};

//==========================================
//
// Struct: CONTROLLER_STATE
//
// �Q�[���p�b�h��ԊǗ� �\����
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================


struct CONTROLER_STATE
{
	XINPUT_STATE state;
	bool boolConnected;
};


/*
 *
 *	���͊Ǘ�
 *
 *	�}���`�^�b�`��R���g���[���[���Q�ɂ���ۂ� CInputFlag �𕡐��Ǘ��ł���悤�ɍ��ւ��Ȃ���΂Ȃ�Ȃ�
 *	�����o����̂ł���΂��̕������J�X�^�}�C�Y���Ă����܂�Ȃ�
 */
class CInputManager {
private:
	// �R���X�g���N�^
	CInputManager() ;
	CInputManager( const CInputManager& inputMgr_ ) ;
	
	// ���L�C���X�^���X
	static CInputManager* m_sharedInputManager ;


	//�Q�[���p�b�h�ő�ڑ���(����͂P)
	static const int MAX_CONTROLLERS = 1;

	//�Q�[���p�b�h��ԃf�[�^�Q
	CONTROLER_STATE m_controllers[MAX_CONTROLLERS];

	CONTROLLER_TYPE m_controllerType = CONTROLLER_TYPE::KEYBORD;

public:
	// �A�N�Z�X�|�C���g
	static CInputManager* getInstance() ;
	// �j��
	static void removeInstance() ;
	
	~CInputManager() ;
	
private:

	//���̓R���g���[���[�f�[�^�Q
	std::vector<CInputController* >* m_pInputControllers = NULL;
	
public:
	/**
	* @desc �X�V����
	*/
	void update(void);


	/**
	* @desc GamePad�̐ڑ���Ԃ̍X�V
	*/
	HRESULT updateGamePadConnectState(void);

	/**
	* @desc GamePad�̓��͏�Ԃ̍X�V
	*/
	void updateGamePadInputState(void);



	/**
	*	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
	*	@param	�L�[�R�[�h
	*	@return	�L�[�^�C�v
	*/
	void changeToInputTypeFromXInput(DWORD wBottons);


	/**
	*	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
	*	@param	�L�[�R�[�h
	*	@return	�L�[�^�C�v
	*/
	void checkPressBotton(DWORD wBottons, BYTE mask,int setType);

	/**
	 *	@desc	�L�[�R�[�h����L�[�^�C�v�ɕϊ�
	 *	@param	�L�[�R�[�h
	 *	@return	�L�[�^�C�v
	 */
	kInputType changeToInputTypeFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	
	/**
	 *	@desc	�L�[�{�[�h���������ۂ̃C�x���g
	 *	@param	�L�[�R�[�h
	 *	@tips	���͊Ǘ����g�p����ۂ͓��͎󂯂����\�ƂȂ��Ă���m�[�h�� onKeyPressed �ŌĂяo��
	 */
	void onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	
	/**
	 *	@desc	�L�[�{�[�h�𗣂����ۂ̃C�x���g
	 *	@param	�L�[�R�[�h
	 *	@tips	���͊Ǘ����g�p����ۂ͓��͎󂯂����\�ƂȂ��Ă���m�[�h�� onKeyReleased �ŌĂяo��
	 */
	void onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode_ ) ;
	

	/**
	 *	@desc	���̓t���O�̃N���A
	 */
	void clearInputFlag(void) ;


	

	/**
	*	@desc	���̓R���g���[���[�̎擾
	*	@param	�R���g���[���[�^�C�v
	*	@return	���̓R���g���[���[
	*/
	CInputController* getInputController(void);
} ;

//EOF



