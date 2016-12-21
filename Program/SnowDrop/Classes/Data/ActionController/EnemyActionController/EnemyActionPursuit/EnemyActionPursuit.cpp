



//================================================
//�ǐ�	
//================================================


/*
* EnemyActionPursuit.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionPursuit.h"
#include<cmath>


/*
* @desc �X�V����
* @param �ǐՂ��s���L�����N�^�[�̃A�h���X
*/
void CEnemyActionPursuit::update(CCharacter* pChara) {

	if (this->m_isPursuiting == true) {

		//�ǐՒ�
		this->pursuit(pChara);

		// �L�����ɂ��ǂ蒅������
		if (pChara->collision(CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1)) || 
			pChara->collision(CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2))) {


			// ���x��0�ɂ���
			pChara->m_pMove->m_vel.set(0.0f, 0.0f);

			// �����Ƀg���K�[���t��

			//(*pChara->m_pActions)[(int)CEnemyCharacter::ACTION::ATTACK]->start();

			//�Đ����~�߂�
			this->stop();
			return;
		}

	}
	else if (this->m_isPursuitStart == true) {

		//�ǐՊJ�n

		//�ǐՃt���O��true�ɂ���
		this->m_isPursuiting = true;
	}

	//�ǐՊJ�n�t���O��������
	this->m_isPursuitStart = false;


}



//===================================================================
// �߂��v���C���[�D��̒ǐՃN���X
//===================================================================
/*
*	@desc�@�߂��v���C���[�D��̒ǐ�
*	@param �ǐՂ���G�̃A�h���X
*/
void CActionPursuitNear::pursuit(CCharacter* pChara) {


	// �G�ƃv���C���[�̋����𑪂�
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	Vec2 BoyPos = pBoy->m_pMove->m_pos - pChara->m_pMove->m_pos;
	Vec2 GirlPos = pGirl->m_pMove->m_pos - pChara->m_pMove->m_pos;

	// �G�ƃv���C���[�̋����𐳋K��
	float BoyVec = std::sqrtf(BoyPos.x * BoyPos.x + BoyPos.y * BoyPos.y);
	float GirlVec = std::sqrtf(GirlPos.x * GirlPos.x + GirlPos.y * GirlPos.y);

	//�R�m���߂����
	if (BoyVec < GirlVec) {

		// �R�m�܂ł̒ǐՈړ��ʂ̌v�Z
		Vec2 pursuitVelBoy;
		pursuitVelBoy.x = BoyPos.x / BoyVec;
		pursuitVelBoy.y = BoyPos.y / BoyVec;

		// �ݒ�
		pChara->m_pMove->m_vel = pursuitVelBoy;

	}
	// �����̕����߂����
	else {

		// �����܂ł̒ǐՈړ��ʂ̌v�Z
		Vec2 pursuitVelGirl;
		pursuitVelGirl.x = BoyPos.x / BoyVec;
		pursuitVelGirl.y = BoyPos.y / BoyVec;

		// �ݒ�
		pChara->m_pMove->m_vel = pursuitVelGirl;

	}
}


//===================================================================
// �����D��̒ǐՃN���X
//===================================================================

/*
*	@desc�@�ǐ�
*	@param �ǐՂ���G�̃A�h���X
*/
void CActionPursuitGirlPriority::pursuit(CCharacter* pChara) {


	// �U�����ꂽ��R�m��_���iHP�������Ă�����j
	if (pChara->m_pStatus->getmaxHp() > pChara->m_pStatus->getHp()) {

		// �R�m
		CCharacter* pPlayerBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

		// �R�m�̐^��̓V��𒆐S�_�Ƃ���
		cocos2d::Point pt(pPlayerBoy->m_pMove->m_pos.x, WINDOW_TOP);

		// �ǐՂ���G�ƋR�m�̋��� = �U��q�̕����������߂�
		float width = std::sqrt(pPlayerBoy->m_pMove->m_pos.x * pPlayerBoy->m_pMove->m_pos.x + pChara->m_pMove->m_pos.x * pChara->m_pMove->m_pos.x);
		float height = std::sqrt(pPlayerBoy->m_pMove->m_pos.y * pPlayerBoy->m_pMove->m_pos.y + pChara->m_pMove->m_pos.y * pChara->m_pMove->m_pos.y);

		// �U��q�^�����s��
		this->swing(pChara, pt, width, height);

	}
	else {

		// ����
		CCharacter* pPlayerGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

		// �����̐^��̓V��𒆐S�_�Ƃ���
		cocos2d::Point pt(pPlayerGirl->m_pMove->m_pos.x, WINDOW_TOP);

		// �ǐՂ���G�Ə����̋��� = �U��q�̕����������߂�
		float width = std::sqrt(pPlayerGirl->m_pMove->m_pos.x * pPlayerGirl->m_pMove->m_pos.x + pChara->m_pMove->m_pos.x * pChara->m_pMove->m_pos.x);
		float height = std::sqrt(pPlayerGirl->m_pMove->m_pos.y * pPlayerGirl->m_pMove->m_pos.y + pChara->m_pMove->m_pos.y * pChara->m_pMove->m_pos.y);

		// �U��q�^�����s��
		this->swing(pChara, pt, width, height);

	}

}

//===================================================================
// �����̂ݒǐՃN���X
//===================================================================

/*
*	@desc�@�ǐ�
*	@param �ǐՂ���G�̃A�h���X
*/
void CActionPursuitGirlOnly::pursuit(CCharacter* pChara) {

	// �G�ƃv���C���[�̋����𑪂�
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
	Vec2 GirlPos = pGirl->m_pMove->m_pos - pChara->m_pMove->m_pos;

	// �G�ƃv���C���[�̋����𐳋K��
	float GirlVec = std::sqrtf(GirlPos.x * GirlPos.x + GirlPos.y * GirlPos.y);

	// �����܂ł̒ǐՈړ��ʂP���o��
	Vec2 pursuitVelGirl;
	pursuitVelGirl.x = GirlPos.x / GirlVec;
	pursuitVelGirl.y = GirlPos.y / GirlVec;

	// �G�̑��x�ɍ��킹�Đݒ肷��
	pursuitVelGirl.x = pursuitVelGirl.x * pChara->m_pStatus->getSpeed();
	pursuitVelGirl.y = pursuitVelGirl.y * pChara->m_pStatus->getSpeed();

	// �ݒ�
	pChara->m_pMove->m_vel = pursuitVelGirl;

}


//===================================================================
// �߂��v���C���[�̕��������������̒ǐՃN���X
//===================================================================
void CActionPursuitDirection::pursuit(CCharacter* pChara) {

		// �G�ƃv���C���[�̋����𑪂�
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
	

		float BoyVec = pBoy->m_pMove->m_pos.x * pBoy->m_pMove->m_pos.x + pBoy->m_pMove->m_pos.y * pBoy->m_pMove->m_pos.y;
		float GirlVec = pGirl->m_pMove->m_pos.x *  pGirl->m_pMove->m_pos.x + pGirl->m_pMove->m_pos.y *  pGirl->m_pMove->m_pos.y;


		//�R�m���߂����
		if (BoyVec < GirlVec) {

			pChara->m_pMove->m_vel.x = 0.0f;

			// �G�̍����ɋR�m
			if (pBoy->m_pMove->m_pos.x < 0) {
				//�������ɐݒ�
				pChara->setScale(1.0f, 1.0f);
			}

			// �G�̉E���ɋR�m
			else if (pBoy->m_pMove->m_pos.x > 0) {

				//�E�����ɐݒ�
				pChara->setScale(-1.0f, 1.0f);
			}
		}

		// �����̕����߂����
		else {

			// �G�̍����ɏ���
			if (pGirl->m_pMove->m_pos.x < 0) {
				//�������ɐݒ�
				pChara->setScale(1.0f, 1.0f);
			}

			// �G�̉E���ɏ���
			else if (pGirl->m_pMove->m_pos.x > 0) {
				//�E�����ɐݒ�
				pChara->setScale(-1.0f, 1.0f);
			}
		}

	
}