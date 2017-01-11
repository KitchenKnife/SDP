#pragma once
/*
* MouseKingCharacter.h
*
*	2017/01/09	Shinya Ueba
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "../EnemyCharacter.h"
#include "Model/Map/Map.h"

//������������������������������������������������
//�@�O���錾
//������������������������������������������������
class CMouseCharacter;

//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CMouseKingCharacter :public CEnemyCharacter {
public:
	static const int MAX_HENCHMANS = 2;

	//�R���X�g���N�^
	CMouseKingCharacter();

	//�f�X�g���N�^
	virtual ~CMouseKingCharacter();

	CREATE_FUNC(CMouseKingCharacter);


	CMouseCharacter* m_pHenchmans[MAX_HENCHMANS];
};