/*
* EnemyActionController.h
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/ActionController.h"

/*
//===================================================================
//�@�G�̓���̔h����
//===================================================================
class CEnemyAction :public CAction {
public:
	virtual ~CEnemyAction() {}
	//�A�N�V�������J�n���邽�тɌĂяo��
	void start()override {};
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) override {};
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() override {};
};

//===================================================================
//�@�G�̂��낤�듮��
//===================================================================
class CEnemyActionWondering :public CEnemyAction {
protected:

	//���̃A�N�V�����N���X�̃X�e�C�g�^�C�v
	//CPlayerCharacter::STATE m_stateType;

	//const int m_waitTime = 30;
	int m_waitCounter = 0;

	/*
	* 0.�ړ���������̐ݒ�
	* 1.�����ɉ����Ĉړ�
	* 2.�����~�܂�
	* 3.�����ɉ����Ĉړ�
	*
	int m_actionStep = 0;

	int m_vec = 1;

public:
	//�R���X�g���N�^
	CEnemyActionWondering();

	/*
	* @desc �ɂԂ�����
	*
	void start()override;

	/*
	* @desc �X�V����
	*
	void update(CCharacter* pChara);

};
*/