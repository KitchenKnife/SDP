
/*
* EnemyCharacter.h
*
*	2016/11/11	Yamasaki 
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"
#include "Data/Status/Status.h"

//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CEnemyCharacter :public CCharacter {
public:

	//�R���X�g���N�^
	CEnemyCharacter();

	//�f�X�g���N�^
	virtual ~CEnemyCharacter();

	//����������
	bool init()override;


	CREATE_FUNC(CEnemyCharacter);

	//================================================
	// 
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�G�̏��(�A�j���[�V�����Ǘ�)
	enum class STATE :int {
		STAND = 0,
		JUMPING = 0,
		WALK_RIGHT = 1,
		WALK_LEFT = 2,
		FALING = 3,
		ATTACK = 4,
		PURSUIT = 5,
		IDLE = 6,
		DAMAGE = 7,

	};

	//�G���s����A�N�V����
	enum class ACTION :int {
		ATTACK = 1,
		PURSUIT = 2,
		IDLE = 3,
		DAMAGE = 4,
	};

	//================================================
	// 
	// �����o�[�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�ړ�����
	void moveFunc() override;

	//�A�j���[�V��������
	void animationFunc()override;

	//�Փ˔��菈��
	void collisionAll()override;

	//��ԃ`�F�b�N
	void checkState() override;

	//���f����
	void applyFunc() override;

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;

	void hits(CCharacter* pChara)override{}


};

