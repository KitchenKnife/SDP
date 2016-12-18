/*
* EnemyActionIdle.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionIdle.h"



//================================================
//�ҋ@	
//================================================
/*
* @desc �X�V����
* @param �ҋ@���s���L�����N�^�[�̃A�h���X
*/
void CEnemyActionIdle::update(CCharacter* pChara) {

	if (this->m_isIdlering == true) {

		//�@�ҋ@��
		this->Idle(pChara);

		//���݂̃t���[�����K��̃t���[���ɒB������
		if ((this->m_isIdleStart == false) && (this->m_currentFrame == this->m_frame)) {

			//�Đ����~�߂�
			this->stop();
			return;
		}

	}
	else if (this->m_isIdleStart == true) {

		//�ҋ@�J�n

		//�ҋ@�t���O��true�ɂ���
		this->m_isIdlering = true;
	}

	//�ҋ@�J�n�t���O��������
	this->m_isIdleStart = false;


}

//===================================================================
// �ҋ@�����낤�낷��N���X
//===================================================================

/*
*	@desc�@�ړ� + �A�j��������ҋ@
*	@param �ҋ@����G�̃A�h���X
*/
void CActionIdleMove::Idle(CCharacter* pChara) {
	// �b���ŊǗ�����

	// 1�b�Ԃ͉E��
	if (this->m_currentFrame < 60) {

		pChara->m_pMove->m_vel.x = 1.0f;
		CCLOG("Idle MOVE!!");
	}
	// 2�b�ڂ͍���
	if (this->m_currentFrame >= 60 || this->m_currentFrame < 120) {

		pChara->m_pMove->m_vel.x = -1.0f;
	}
	// 3�b�ڂ͂���낫��낷��
	if (this->m_currentFrame >= 120 && this->m_currentFrame % 20 && pChara->m_pMove->m_vel.x > 0) {

		pChara->m_pMove->m_vel.x = -1.0f;
	}
	if (this->m_currentFrame >= 120 && this->m_currentFrame % 20 && pChara->m_pMove->m_vel.x < 0) {

		pChara->m_pMove->m_vel.x = 1.0f;
	}
}





//===================================================================
// �ҋ@���A�j���[�V������������N���X
//===================================================================
/*
*	@desc�@�A�j���[�V�����݂̂̑ҋ@
*	@param �ҋ@����G�̃A�h���X
*/
void CActionIdleAnimationOnly::Idle(CCharacter* pChara) {

}
