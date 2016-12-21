/*
* ActionController.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionAttack.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


//================================================
//�Ō��U��	
//================================================


/*
* @desc �X�V����
* @param �U�����s���L�����N�^�[�̃A�h���X
*/
void CEnemyActionAttack::update(CCharacter* pChara) {


	//�R�m�̎擾
	CCharacter* pKnightChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	//�����̎擾
	CCharacter* pGirlChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	if (this->m_isAttacking == true) {

		//�U����
		this->attack(pChara);

		//�t���[���𑫂��Ă��� 
		this->m_currentFrame++;

		//�Փ˂��Ă��Ȃ����
		if (!(pChara->collision(pKnightChara)) || !(pChara->collision(pGirlChara))) {

			//�Đ����~�߂�
			this->stop();
			return;
		}

	}
	else if (this->m_isAttackStart == true) {

		//�ݒ肳�ꂽ�b���U���J�n
		m_currentFrame = 0;

		//�Ō��U���t���O��true�ɂ���
		this->m_isAttacking = true;
	}

	//�Ō��U���J�n�t���O��������
	this->m_isAttackStart = false;


}

//======================================
// BOSS1 �r��
//======================================
void CEnemyBOSS1Attack::attack(CCharacter* pChara) {
	
	//pChara->m_state = (int)CEnemyCharacter::STATE::ATTACK;

	// 3�񒆉��񓖂��������m�F
	if (this->m_currentFrame % 60 == 0) {
		//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
		CCLOG("BOSS ATTACK!!");
		//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
	}

}

//======================================
// BOSS1 �N�G�C�N
//======================================
void CEnemyBOSS1AttackQuake::attack(CCharacter* pChara) {

	// �v���C���[���U���͈͓��Ȃ�U������

	//�R�m�̎擾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	if (pChara->collision(pPlayerChara) == true) {

		// 3�񒆉��񓖂��������m�F
		if (this->m_currentFrame % 60 == 0) {
			//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
			CCLOG("BOSS Quake!!");
			//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
		}
	}

}