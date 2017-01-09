/*
 * Character.h
 *
 *	2016/11/07	Osumi And Harada And Shinya Ueba
 *
 */
#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/Collision/Collision.h"
#include "Data/Collision/CollisionArea.h"
#include "Data/Status/Status.h"
#include "Data/StateMachine/StateMachine.h"

//================================================
// �L�����N�^�[�^�C�v
//================================================
enum class CHARACTER_TYPE :int {
	NONE		= -1,	//����
	PLAYER_BOY	= 0,	//���N�i�v���C���[�j
	PLAYER_GIRL = 1,	//����
	ENEMY		= 2,	//�G
	BULLET		= 3,	//�e
	GIMMICK		= 4,	//�M�~�b�N
	DAMAGE		= 5,	//�_���[�W
};

//================================================
// �L�����N�^�[�N���X
//		�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
//
//	2016/12/22
//									Author Harada
//================================================
class CCharacter :public Sprite {
public:
	//================================================ 
	// �K�{�֐��̗�	
	//================================================
	//�R���X�g���N�^
	CCharacter();

	//�f�X�g���N�^
	virtual ~CCharacter();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update(float deltaTime)override;

	//================================================ 
	// �L�����N�^�[�Q�̕K�v���Q
	//================================================
	//�A�j���[�V�����f�[�^�Q
	std::vector<CAnimation* >* m_pAnimations = NULL;

	//�ړ��f�[�^
	CMove* m_pMove = NULL;

	//�������Z�f�[�^�Q
	std::vector<CPhysical* >* m_pPhysicals = NULL;

	//�A�N�V�����f�[�^�Q�}�b�v�z��
	std::map<int, std::vector<CAction*>*> m_mapAction;

	//���̃f�[�^
	CBody* m_pBody = NULL;

	//�Փ˔����ԃf�[�^�Q
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//��ԑJ�ڃf�[�^
	CStateMachine* m_pStateMachine = NULL;


	//�L���t���O
	//�\���E��\���֘A
	bool m_activeFlag = false;

	//�����t���O
	//�\�����Ă����Ԃł̐����֘A
	bool m_isAlive = false;

	//��܂��ȃ^�C�v�ʁi�L�����^�C�v�j
	int m_charaType = (int)CHARACTER_TYPE::NONE;

	//�ׂ��ȃ^�C�v�ʁi�^�O�j
	int m_tag = 0;

	//�L�����N�^�[�X�e�[�^�X
	CStatus m_status;

	//�L�����N�^�[�̏��
	int m_state = 0;

	//�L�����N�^�[�̈ړ����
	int m_stateMove = 0;

	//�L�����N�^�[�̃A�j���[�V�����̏��
	int m_animationState = 0;

	//�L�����N�^�[�̃A�N�V�����̏��
	int m_actionState = 0;

	//�U�����󂯂Ă��邩�ǂ����̃t���O
	//true...�󂯂Ă���@false...�󂯂Ă��Ȃ�
	bool m_underAttack = false;

protected:
	//================================================ 
	// �L�����N�^�[�N���X�̊�{�I�Ȋ֐��̗�
	//	�ȉ��̊֐��͂��ׂẴL�����N�^�[�h���N���X���ŃI�[�o�[���C�h������B
	//================================================
	
	//�ړ�����
	virtual void moveFunc() = 0;

	//�A�j���[�V��������
	virtual void animationFunc() = 0;

	//�Փ˔��菈��
	virtual void collisionAll() = 0;

	//��ԃ`�F�b�N
	virtual void checkState() = 0;

	//���f����
	virtual void applyFunc() = 0;

public:
	/**
	 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	 * @param	�L�����N�^�[�̃A�h���X
	 * @return	true...�Փ˂���
	 */
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	 * @param	�L�����N�^�[�̃A�h���X
	 */
	virtual void hits(CCharacter* pChara) = 0;

	/**
	*	@desc �g�o�̌���
	*	@param ��������l�i����̍U���́j
	*	@author		Shinya Ueba
	*/
	void decreaseHP(int attackPt);

	/**
	*	@desc �g�o�̑S��
	*	@author		Shinya Ueba
	*/
	void recoveryHp(void);

	/**
	*	@desc �g�o�̂P��
	*	@author		Shinya Ueba
	*/
	void cureHp(int hp);

	

	//================================================ 
	// �C�x���g�R�[���o�b�N��p�֐��̗�	
	//================================================
	/**
	 * @desc	���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	 * @param	�}�b�v�`�b�vID
	 *			��ʉ��̍ۂ�0
	 */
	virtual void collisionBottomCallback(int event) {}

	/**
	 * @desc	�Փ˂����ۂ̃C�x���g�R�[���o�b�N
	 */
	virtual void collisionTopCallback(int event) {}

	/**
	 * @desc	�Փ˂����ۂ̃C�x���g�R�[���o�b�N
	 */
	virtual void collisionRightCallback(int event) {}

	/**
	 * @desc	��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	 */
	virtual void collisionLeftCallback(int event) {}
};

//EOF