/*
* EnemyActionDamage.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionDamage.h"



//================================================
//�@�_���[�W���󂯂����̃A�N�V�����N���X	
//================================================
/*
* @desc �X�V����
* @param �_���[�W���󂯂��L�����N�^�[�̃A�h���X
*/
/*
void CEnemyActionDamage::update(CCharacter* pChara) {

	if (this->m_isDamaging == true) {

		//�ǐՒ�
		this->Damage(pChara);

		///////
		if (pChara->m_state != (int)CEnemyCharacter::STATE::DAMAGE) {

			//�Đ����~�߂�
			this->stop();
			return;
		}

	}
	else if (this->m_isDamageStart == true) {

		//�ǐՊJ�n

		//�ǐՃt���O��true�ɂ���
		this->m_isDamaging = true;
	}

	//�ǐՊJ�n�t���O��������
	this->m_isDamageStart = false;


}

*/

//===================================================================
// �_���[�W���󂯂Ē�~����N���X
//===================================================================
/*
*	@desc�@�_���[�W���󂯂Ē�~����
*	@param �_���[�W���󂯂�G�̃A�h���X
*/
void CActionDamageStop::Damage(CCharacter* pChara) {

}



//===================================================================
// �_���[�W���󂯂Čジ����N���X(���ɃY�T�[�I��)
//===================================================================
/*
*	@desc �_���[�W���󂯂Čジ����
*	@param �_���[�W���󂯂�G�̃A�h���X
*/
void CActionDamageBack::Damage(CCharacter* pChara) {

}

//===================================================================
// �_���[�W���A�j���[�V������������N���X�i�ړ�or�U���\�j
//===================================================================
/*
*	@desc�@�_���[�W���A�j���[�V�����̂�
*	@param �_���[�W���󂯂�G�̃A�h���X
*/
void CActionDamageAnimationOnly::Damage(CCharacter* pChara) {

}


//===================================================================
// �_���[�W���ω����Ȃ��N���X�i�ړ�or�U���\�j
//===================================================================
/*
*	@desc�@�_���[�W���������ڂɕω����Ȃ�
*	@param �_���[�W���󂯂�G�̃A�h���X
*/
void CActionDamageNone::Damage(CCharacter* pChara) {

}