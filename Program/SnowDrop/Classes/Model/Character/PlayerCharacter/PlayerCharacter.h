
/*
* PlayerCharacter.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//================================================
//�@�ǉ��̃C���N���[�h�͂�������
//================================================
#include "Model/Character/Character.h"

//================================================
// ���N�N���X
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerCharacterBoy :public CCharacter {
public:
	//================================================ 
	// �K�{�֐��̗�	
	//================================================
	//�R���X�g���N�^
	CPlayerCharacterBoy();

	//�f�X�g���N�^
	~CPlayerCharacterBoy();

	CREATE_FUNC(CPlayerCharacterBoy);

	//����������
	bool init()override;

	//================================================ 
	// �L�����N�^�[�N���X�̃I�[�o�[���C�h������֐��Q
	//================================================

	/**
	*	@desc �p���L�����N�^�[�ʂ̍X�V����
	*	@author Shinya Ueba
	*/
	virtual void updatePersonal(void)override;

	//�ړ�����
	virtual void moveFunc();

	//�A�j���[�V��������
	virtual void animationFunc();

	//�Փ˔��菈��
	virtual void collisionAll();

	//��ԃ`�F�b�N
	virtual void checkState();

	//���f����
	virtual void applyFunc();

	/**
	 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	 * @param	�L�����N�^�[�̃A�h���X
	 * @return	true...�Փ˂���
	 */
	virtual bool collision(CCharacter* pChara);

	/**
	 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	 * @param	�L�����N�^�[�̃A�h���X
	 */
	virtual void hits(CCharacter* pChara);

	//================================================ 
	// �C�x���g�R�[���o�b�N��p�֐��̗�	
	//================================================
	/**
	 * @desc	���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	 * @param	�}�b�v�`�b�vID
	 *			��ʉ��̍ۂ�0
	 */
	virtual void collisionBottomCallback(int event)override {
		//�W�����v���~������B
		(*this->m_pActions)[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP]->stop();
	}

	//================================================ 
	// CPlayerCharacterBoy�N���X��p�����o
	//================================================
	//�v���C���[�̃A�j���[�V�����̏��
	enum class PLAYER_STATE : int {
		STAND		= 0,	//�ҋ@
		JUMP		= 0,	//�W�����v
		FALLING		= 0,	//����
		WALK_LEFT	= 1,	//�����s
		WALK_RIGHT	= 2,	//�E���s
	};

	//���݂̃v���C���[�̏��
	int m_playerState;

	//�v���C���[�̍s��
	enum class PLAYER_ACTION : int {
		JUMP		= 0,	//�W�����v
	};

	/**
	 * @desc	���͏���
	 * @tips	�ړ������ŌĂяo��
	 */
	void inputFunc();

};