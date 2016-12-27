
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
//�@�O���錾
//================================================
class CPlayerCharacterGirl;

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


	/**
	* @desc ����Ȃ����Ԃ��`�F�b�N
	* @param �����i�����j
	* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
	* @author Osumi
	* @author Shinya Ueba
	*/
	void checkHoldHands(CPlayerCharacterGirl* pGirl);


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
		//(*this->m_mapAction[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP])[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP]->stop();
	}

	//================================================ 
	// CPlayerCharacterBoy�N���X��p�����o
	//================================================

	/**
	 * @desc	���͏���
	 * @tips	�ړ������ŌĂяo��
	 */
	void inputFunc();

private:
	//����Ȃ����Ƃ��\���ǂ��� true...�\ false ����
	bool m_enableHoldHands = false;

};