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
CMouseCharacter::CMouseCharacter(CMouseKingCharacter* pMaster)
	:m_pMaster(pMaster)
{

}

//�f�X�g���N�^
CMouseCharacter::~CMouseCharacter()
{


}

//EOF