/*
* Animation.cpp
*
*	2016/11/07	Osumi
*
*/
#include "Animation.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Model/Character/CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"


//========================================================================
// �v���C���[��p�A���A�j���[�V����
//========================================================================
int CPlayerAttackAnimation::update() {
	//���݂̃A�j���[�V�������I���������m�F
	if (this->m_pAnimations[this->m_nowLine]->isEnd()) {
		//�I�����Ă�����
		
		//�v���C���[�̎擾
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();
		
		//�v���C���[�̘A���t���O�������Ă�����
		if (pBoy->m_chainAttackFlag) {
			//���݂̍Đ�����A�j���[�V�������X�V
			this->m_nowLine++;

			pBoy->m_chainAttackFlag = false;

			//�����Đ�����A�j���[�V�������Ȃ����
			if (this->m_nowLine >= this->m_line) {
				//���̃A�j���[�V�����S�̂̏I���t���O�𗧂Ă�
				this->m_isEnd = true;

				return -1;
			}

			//����̃A�j���[�V���������݂��Ă����
			//�_���[�W�L�����N�^�[���o��
			(*pBoy->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();
		}
		//�A���t���O���~��Ă�����
		else {
			//���̃A�j���[�V�����S�̂̏I���t���O�𗧂Ă�B
			this->m_isEnd = true;

			return -1;
		}
	}

	//���݂̃A�j���[�V�������X�V���ĕԂ��B
	return this->m_pAnimations[this->m_nowLine]->update();
}