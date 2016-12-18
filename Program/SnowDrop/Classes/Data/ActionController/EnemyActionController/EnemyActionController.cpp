/*
* ActionController.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionController.h"
#include "Model/Character/Character.h"


//================================================
//	�Ō��U��	
//================================================


/*
* @desc �X�V����
* @param �U�����s���L�����N�^�[�̃A�h���X
*/
void CActionBlowAttack::update(CCharacter* pChara) {

	if (this->m_isBlowAttacking == true) {

		//�Ō��U����

		//�t���[���𑫂��Ă���
		this->m_currentFrame++;

		//���݂̃t���[�����K��̃t���[���ɒB������
		if ((this->m_isBlowAttackStart == false) && (this->m_currentFrame == this->m_frame)) {

			//�Đ����~�߂�
			this->stop();
			return;
		}

	}
	else if (this->m_isBlowAttackStart == true) {

		//�Ō��U���J�n
		m_currentFrame = 0;

		// HP�̔��f
		
		this->blowHit(this->m_pStatus->getAttackPt(), pChara->m_pStatus);

		//�Ō��U���t���O��true�ɂ���
		this->m_isBlowAttacking = true;
	}

	//�Ō��U���J�n�t���O��������
	this->m_isBlowAttackStart = false;


}