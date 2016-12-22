/*
* InputManager.h
*
*	2016/11/07	Osumi
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
public:
	// �A�N�Z�X�|�C���g
	static CInputManager* getInstance() ;
	// �j��
	static void removeInstance() ;
	
	~CInputManager() ;
	
private:
	// ���̓t���O
	CKeyboardInputFlag* m_pInputFlag = NULL ;

	//���̓R���g���[���[�f�[�^�Q
	std::vector<CInputController* >* m_pInputControllers = NULL;
	
public:
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
	 *	@desc	���̓t���O�̐ݒ�
	 *	@param	���̓t���O
	 */
	void setInputFlag( CKeyboardInputFlag* pInputFlag_ ) ;
	
	/**
	 *	@desc	���̓t���O�̍폜
	 */
	void removeInputFlag() ;
	
	/**
	 *	@desc	���̓t���O�̃N���A
	 */
	void clearInputFlag() ;
	
	/**
	 *	@desc	���̓t���O�̎擾
	 *	@return	���̓t���O
	 */
	CKeyboardInputFlag* getInputFlag() ;
} ;


// ���̓t���O�}�N��
#define inputflag (*CInputManager::getInstance()->getInputFlag())

//EOF



