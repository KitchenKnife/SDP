#pragma once
/*
* MarionetteCharacter.h
*
*	2017/01/12	Shinya Ueba
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "../EnemyCharacter.h"
#include "Model/Map/Map.h"

//������������������������������������������������
//�@�O���錾
//������������������������������������������������

//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CMarionetteCharacter :public CEnemyCharacter {
public:

	//�R���X�g���N�^
	CMarionetteCharacter();

	//�f�X�g���N�^
	virtual ~CMarionetteCharacter();

	CREATE_FUNC(CMarionetteCharacter);

};

//EOF