#pragma once
//==========================================
//
// File: EnumDamage.h
//
// �G�@���@�񋓌^			�w�b�_�[�t�@�C��
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

/********************************************************************
*
*
* �_���[�W Smoke�@�̗񋓌^ ��������
*
*
********************************************************************/


//---------------------------------------------------------
// Enum Class: SMOKE_STATE { int }
//
// �_���[�W Smoke�@�̏�Ԃ��
//
//
//---------------------------------------------------------
enum class DAMAGE_SMOKE_STATE :int
{
	ATTACK = 0,			//�U�����
	DEAD = 1,			//���S���
};

enum class DAMAGE_SMOKE_ANIMATION_STATE :int
{
	ATTACK = 0,			//�U�����
	DEAD = 1,			//���S���
};

enum class DAMAGE_SMOKE_ACTION_STATE :int
{
	ATTACK = 0,			//�U�����
};

/********************************************************************
*
*
* ��������܂�
*
*
********************************************************************/

//EOF