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
	EQUIP_RIGHT			= 10,	//��������		�E����
	EQUIP_LEFT			= 11,	//��������		������
	UN_EQUIP_RIGHT		= 12,	//�������O��	�E����	
	UN_EQUIP_LEFT		= 13,	//�������O��	������
	GRASP_RIGHT			= 14,	//���͂ށ@�E����
	GRASP_LEFT			= 15,	//���͂ށ@������
	GRASP_IDLE_RIGHT	= 16,	//���݂͂Ȃ���ҋ@�@	�E����
	GRASP_IDLE_LEFT		= 17,	//���݂͂Ȃ���ҋ@	������
	GRASP_WALK_RIGHT	= 18,	//���݂͂Ȃ�������@	�E����
	GRASP_WALK_LEFT		= 19,	//���݂͂Ȃ������	������
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
	EQUIP_RIGHT			= 14,	//��������		�E����
	EQUIP_LEFT			= 15,	//��������		������
	UN_EQUIP_RIGHT		= 16,	//�������O��	�E����	
	UN_EQUIP_LEFT		= 17,	//�������O��	������
	GRASP_RIGHT			= 18,	//���͂ށ@�E����
	GRASP_LEFT			= 19,	//���͂ށ@������
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
	WANDERING = 2,
	//	CHASE = 3,
};

/********************************************************************
*
*
* ��������܂�
*
*
********************************************************************/
//EOF