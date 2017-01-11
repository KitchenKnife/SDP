/*
* MouseKingCharacter.cpp
*
*	2017/01/09	Shinya Ueba
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "MouseCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	�G�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CMouseCharacter::CMouseCharacter(CMouseKingCharacter* pMaster,int positionType)
	:m_pMaster(pMaster),m_positionType(positionType)
{

}

//�f�X�g���N�^
CMouseCharacter::~CMouseCharacter()
{


}

/**
* @desc �U�����߃t���O��ݒ�
* @param true...�U��������@false...�U�������Ȃ�
*/
void CMouseCharacter::setAttackOrder(bool flag)
{
	this->m_attackOrder = flag;
}


/**
* @desc �U�����߃t���O���擾
* @param true...�U��������@false...�U�������Ȃ�
*/
bool CMouseCharacter::getAttackOrder(void)
{
	return this->m_attackOrder;
}


//EOF