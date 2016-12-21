#pragma once
#include "Model/Character/Character.h"

//================================================
// �����N���X
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerCharacterGirl :public CCharacter {
public:
	//================================================ 
	// �K�{�֐��̗�	
	//================================================
	//�R���X�g���N�^
	CPlayerCharacterGirl();

	//�f�X�g���N�^
	~CPlayerCharacterGirl();

	CREATE_FUNC(CPlayerCharacterGirl);

	//����������
	bool init()override;

	//================================================ 
	// �L�����N�^�[�N���X�̊�{�I�Ȋ֐��̗�
	//	�ȉ��̊֐��͂��ׂẴL�����N�^�[�h���N���X���ŃI�[�o�[���C�h������B
	//================================================
	//�ړ�����
	virtual void moveFunc();

	//�A�j���[�V��������
	virtual void animationFunc();

	//�Փ˔��菈��
	virtual void collisionAll();

	//��ԃ`�F�b�N
	virtual void checkState();

	//���f����
	virtual void applyFunc();

	/**
	 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	 * @param	�L�����N�^�[�̃A�h���X
	 * @return	true...�Փ˂���
	 */
	virtual bool collision(CCharacter* pChara);

	/**
	 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	 * @param	�L�����N�^�[�̃A�h���X
	 */
	virtual void hits(CCharacter* pChara);

	//================================================ 
	// CPlayerCharacterGirl�N���X��p�����o
	//================================================
	//�����̏��
	enum class GIRL_STATE {
		STAND	= 0,	//�ҋ@
	};

	//�����̏��
	int m_state = (int)GIRL_STATE::STAND;

};
