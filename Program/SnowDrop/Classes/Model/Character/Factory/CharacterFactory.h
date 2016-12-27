#pragma once
//==========================================
//
// File: CharacterFactory.h
//
// �L�����N�^�[�H�� �w�b�_�[�t�@�C��
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "Model\Character\Character.h"


//=============================================
//
// �O���錾
//
//=============================================
class CCharacter;
class CGirlCharacter;
class CPlayerCharacterBoy;


//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//
//	2016/12/22
//									Author Harada
//================================================
class CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CCharacterPartsFactory() {}

	//�ړ��f�[�^�̎��̂𐶐����ĕԂ�
	virtual CMove* getMove() = 0;
	//�A�j���[�V�����f�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CAnimation* >* getAnimations() = 0;
	//�������Z�f�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	//���̃f�[�^�̎��̂𐶐����ĕԂ�
	virtual CBody* getBody() = 0;
	//�Փ˔����ԃf�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
	//��ԑJ�ڃf�[�^�̐����Ǝ擾
	virtual	CStateMachine*	getStateMachine(void) { return NULL; }
};