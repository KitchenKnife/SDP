/*
* MouseKingCharacter.cpp
*
*	2017/01/09	Shinya Ueba
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "MouseKingCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	�G�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CMouseKingCharacter::CMouseKingCharacter() 
{
	//����������
	ZeroMemory(this->m_pHenchmans, sizeof(this->m_pHenchmans));
}

//�f�X�g���N�^
CMouseKingCharacter::~CMouseKingCharacter() 
{


}

//EOF