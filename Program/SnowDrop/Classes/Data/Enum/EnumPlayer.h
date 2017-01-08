#pragma once
//==========================================
//
// File: EnumPlayer.h
//
// �v���C���[�@���@�񋓌^			�w�b�_�[�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================



/********************************************************************
*
*
* �v���C���[�@�̗񋓌^ ��������
*
*
********************************************************************/

//---------------------------------------------------------
// Enum Class: PLAYER_AND_GIRL_STATE { int }
//
// �v���C���[�@�Ɓ@�����@�̏�Ԃ��
//
//
//---------------------------------------------------------
enum class PLAYER_AND_GIRL_STATE :int
{
	FREE				= 0,	//�����ƂȂɂ����Ă��Ȃ����
	GRAPS_HANDS			= 1,	//�����Ǝ�������Ă�����
	HOLD_THE_PRINCESS	= 2,	//���������P�l���������Ă�����

};

//---------------------------------------------------------
// Enum Class: PLAYER_SWORD_STATE { int }
//
// �v���C���[�̓��̏�Ԃ��
//
//
//---------------------------------------------------------
enum class PLAYER_AND_GIRL_STATE :int
{
	RETURN	= 0,	//�[�����
	DRAWN	= 1,	//�������

};

//---------------------------------------------------------
// Enum Class: PLAYER_STATE { int }
//
// �v���C���[�@�̏�Ԃ��
//
//
//---------------------------------------------------------
enum class PLAYER_STATE :int
{
	IDLE_RIGHT			= 0,	//�E�ҋ@���
	IDLE_LEFT			= 1,	//���ҋ@���
	WALK_RIGHT			= 2,	//�E���s
	WALK_LEFT			= 3,	//�����s
	JUMP_RIGHT			= 4,	//�E�����W�����v
	JUMP_LEFT			= 5,	//�������W�����v
	FALL_RIGHT			= 6,	//�E��������
	FALL_LEFT			= 7,	//����������
	ATTACK_RIGHT		= 8,	//�E�����U��
	ATTACK_LEFT			= 9,	//�������U��
	JUMP_ATTACK_RIGHT	= 10,	//�W�����v�U��	�E����	
	JUMP_ATTACK_LEFT	= 11,	//�W�����v�U��	������
	EQUIP_RIGHT			= 12,	//��������		�E����
	EQUIP_LEFT			= 13,	//��������		������
	UN_EQUIP_RIGHT		= 14,	//�������O��	�E����	
	UN_EQUIP_LEFT		= 15,	//�������O��	������
	GRASP_RIGHT			= 16,	//���͂ށE�����@�E����
	GRASP_LEFT			= 17,	//���͂ށE�����@������
	HOLD_RIGHT			= 18,	//���P�l������	�E����
	HOLD_LEFT			= 19,	//���P�l������	������
};

//---------------------------------------------------------
// Enum Class: PLAYER_ANIMATION_STATE { int }
//
// �v���C���[�@�A�j���[�V�����̏�Ԃ��
//
//
//---------------------------------------------------------
enum class PLAYER_ANIMATION_STATE :int
{
	IDLE_RIGHT			= 0,	//�E�ҋ@���
	IDLE_LEFT			= 1,	//���ҋ@���
	WALK_RIGHT			= 2,	//�E���s
	WALK_LEFT			= 3,	//�����s
	JUMP_RIGHT			= 4,	//�E�����W�����v
	JUMP_LEFT			= 5,	//�������W�����v
	FALL_RIGHT			= 6,	//�E��������
	FALL_LEFT			= 7,	//����������
	FIRST_ATTACK_RIGHT	= 8,	//�E�����U���i�P���ځj
	SECOND_ATTACK_RIGHT	= 9,	//�E�����U���i�Q���ځj
	THURD_ATTACK_RIGHT	= 10,	//�E�����U���i�R���ځj
	FIRST_ATTACK_LEFT	= 11,	//�������U���i�P���ځj
	SECOND_ATTACK_LEFT	= 12,	//�������U���i�Q���ځj
	THURD_ATTACK_LEFT	= 13,	//�������U���i�R���ځj
	JUMP_ATTACK_RIGHT	= 14,	//�E�����W�����v�U��
	JUMP_ATTACK_LEFT	= 15,	//�������W�����v�U��
	EQUIP_RIGHT			= 16,	//��������		�E����
	EQUIP_LEFT			= 17,	//��������		������
	UN_EQUIP_RIGHT		= 18,	//�������O��	�E����	
	UN_EQUIP_LEFT		= 19,	//�������O��	������
	GRASP_RIGHT			= 20,	//���͂ށ@�E����
	GRASP_LEFT			= 21,	//���͂ށ@������
	GRAPS_ATTACK_RIGHT	= 22,	//���͂񂾏�Ԃł̍U��	�E����
	GRAPS_ATTACK_LEFT	= 23,	//���͂񂾏�Ԃł̍U��	������
	HOLD_RIGHT			= 24,	//���P�l������	�E����
	HOLD_LEFT			= 25,	//���P�l������	������
};

//---------------------------------------------------------
// Enum Class: PLAYER_ACTION_STATE { int }
//
// �v���C���[�@�A�N�V�����̏�Ԃ��
//
//
//---------------------------------------------------------
enum class PLAYER_ACTION_STATE :int
{
	IDLE = 0,//�ҋ@���
	JUMP = 1,//�W�����v
};

/********************************************************************
*
*
* ��������܂�
*
*
********************************************************************/
//EOF