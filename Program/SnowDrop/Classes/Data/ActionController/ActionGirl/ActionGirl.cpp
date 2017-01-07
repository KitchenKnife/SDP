#include "ActionGirl.h"
#include "Model/Character/Character.h"
#include "Lib\Math\CustomMath.h"

/*
 * @desc	�X�V����
 * @param	�A�N�V��������Ώۂ̃L�����N�^�[�i�����j
 */
void CGirlActionGraspHand::update(CCharacter* pChara) {
	//�v���C���[�Ə����̋��������߂�
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pPlayerChara, pChara);

	//������35�ȏ�Ȃ�
	if (distanceToGirl >= 35) {
		//�v���C���[���������E�̈ʒu�ɂ����
		if (this->m_pPlayerChara->m_pMove->m_pos.x > pChara->m_pMove->m_pos.x) {
			pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x - 35.0f, this->m_pPlayerChara->m_pMove->m_pos.y);
		}
		//���ɂ����
		else {
			pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x + 35.0f, this->m_pPlayerChara->m_pMove->m_pos.y);
		}
	}
}


//===================================================================
// �����̂��P�l�������A�N�V����
//===================================================================
/*
 * @desc	�X�V����
 * @param	�A�N�V��������Ώۂ̃L�����N�^�[�i�����j
 */
void CGirlActionHoldThePrincess::update(CCharacter* pChara) {
	
	pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x, this->m_pPlayerChara->m_pMove->m_pos.y + 30);

}