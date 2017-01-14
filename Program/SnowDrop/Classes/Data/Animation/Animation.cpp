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
	//�A�j���[�V�������I�����Ă��Ȃ���΃J�E���^�[�̍X�V���s��
	if (this->m_isEnd == false && this->changeLineFlag == false) {

		this->m_counter++;

		//�J�E���^�[�̐����A�j���[�V���������閇���ȏ�ɂȂ�����J�E���^�[�����Z�b�g����
		if (this->m_counter >= this->m_interval*this->m_number) {

			//���[�v����Ȃ�
			if (this->m_isLoop == true) {

				//�J�E���^�[�����Z�b�g
				this->m_counter = 0;
			}
			else {

				//�A�j���[�V�������I���������ǂ����̃t���O�ɑ΂���true������
				this->changeLineFlag = true;

				//���[�v���Ȃ��A�j���[�V�����ɑ΂��Ă͔�яo���J�E���^�[���f�N�������g����
				this->m_counter--;
			}
		}
	}
	//�A�j���[�V�������I��
	else if(this->m_isEnd == false && this->changeLineFlag == true)
	{
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();

		//�v���C���[�̘A���t���O�������Ă��邩�m�F
		if (pBoy->m_chainAttackFlag == true) {
			//���݂̃`�b�v���C�����X�V
			this->m_nowLine++;

			//���݂̃`�b�v���C�����i�[���Ă��郉�C�����������Ȃ�
			if (this->m_nowLine < this->m_line)
			{
				this->changeLineFlag = false;

				this->m_counter = 0;

				(*pBoy->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();
			}
			//����ȏ�Đ��ł��郉�C�����Ȃ����
			else
			{
				//�A�j���[�V�����I���t���O�𗧂Ă�
				this->m_isEnd = true;
			}

			pBoy->m_chainAttackFlag = false;
		}
		//�v���C���[�̘A���t���O�������Ă��Ȃ����
		else
		{
			//�A�j���[�V�����I���t���O�𗧂Ă�
			this->m_isEnd = true;
		}
		
	}

	//�\������t���[����
	m_currentFrame = this->m_counter / this->m_interval;

	//�X�V�������݂̃t���[�����ꉞ�Ԃ��B
	return m_currentFrame;
}