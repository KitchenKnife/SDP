/*
 * Character.cpp
 *
 *	2016/11/07	Osumi
 *
 */
#include "Character.h"

//================================================
// �L�����N�^�[�N���X
//		�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
//
//	2016/12/22
//									Author Harada
//================================================
//�R���X�g���N�^
CCharacter::CCharacter() {}

//�f�X�g���N�^

/**
*	@desc �f�X�g���N�^
*	@autor	Osumi
*	@autor	Harada
*	@autor	Shinya Ueba
*/
CCharacter::~CCharacter() {

	//��ԑJ�ڃf�[�^�̍폜
	SAFE_DELETE(this->m_pStateMachine);

	//���̃f�[�^�̍폜
	SAFE_DELETE(this->m_pBody);

	//�A�N�V�����Q�f�[�^�̍폜
	std::map<int, std::vector<CAction*>* >::iterator itr = this->m_mapAction.begin();
	while (itr != this->m_mapAction.end()) {

		if (itr->second)
		{
			std::vector<CAction*>* pActions = itr->second;

			for (CAction* pAction : *pActions)
			{
				SAFE_DELETE(pAction);
			}
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
		}
		//�C�e���[�^�[���X�V
		itr++;
	}

	//�������Z�Q�f�[�^�̍폜
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		SAFE_DELETE(pPhysical);
	}
	SAFE_DELETE(this->m_pPhysicals);

	//�ړ��f�[�^�̍폜
	SAFE_DELETE(this->m_pMove);


	//�A�j���[�V�����f�[�^�Q�̍폜
	for (CAnimation* pAnimation: (*m_pAnimations)) {
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);
}

//����������
bool CCharacter::init() {
	//�X�v���C�g�̏�����
	if (Sprite::init() == false) {
		//�������Ɏ��s�����ꍇ
		CCLOG("Sprite�̏������Ɏ��s");
		return false;
	}
	//�ʂɍX�V�������N��������B
	this->scheduleUpdate();

	//�������ɐ��������ꍇ
	return true;
}

//�X�V����
void CCharacter::update(float deltaTime) {


	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//�Փ˔���
	this->collisionAll();

	//��ԃ`�F�b�N
	this->checkState();

	//���f����
	this->applyFunc();
}

