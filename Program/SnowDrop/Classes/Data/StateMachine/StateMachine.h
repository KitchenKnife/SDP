#pragma once
//==========================================
//
// File: StateMachine.h
//
// ��ԑJ�ڃ}�V�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include <map>

//==========================================
//
// Class: CStateBase
//
// ��ԑJ�� ���N���X  
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateBase
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CStateBase(void);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CStateBase(void);

	/**
	* @desc	�J�n����
	*/
	virtual void start(void) = 0;

	/**
	* @desc �X�V����
	*/
	virtual void update(void) = 0;

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	virtual void onChangeEvent(void) = 0;

	/**
	* @desc �؂�ւ���������擾
	*/
	bool isNext(void);

protected:
	// ���ɍs�����߂̏���
	bool m_isNext = false;
};

//==========================================
//
// Class: CStateSwitch
//
// ��Ԃ̐؂�ւ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateSwitch
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CStateSwitch(CStateBase* const pState, const int nextRegisterKey);

	/**
	* @desc �f�X�g���N�^
	*/
	~CStateSwitch();


	// �A�b�v�f�[�g�̑O�ɌĂ΂��
	
	/**
	* @desc �J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ���̏�Ԃɂ����邩�ǂ������擾����
	* @return true...������ false...�����Ȃ�
	*/
	bool canNextState(void);

public:
	// ���ɍs���o�^�������O
	const int m_nextRegisterKey;

private:
	// �e�N���X
	CStateBase* m_pState = NULL;
};


//==========================================
//
// Class: CStateMachine
//
// ��ԊǗ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateMachine
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CStateMachine(void);

	/**
	* @desc �f�X�g���N�^
	*/
	~CStateMachine(void);

	/**
	* @desc �X�V����
	*/
	void update(void);
	
	/**
	* @desc ��Ԃ�o�^����
	* @param �o�^����B�ꖳ��̃L�[
	* @param 
	*/
	void registerState(const int key, CStateSwitch* const pState);
	
	// �ŏ�����n�߂��Ԃ�ݒ�
	
	/**
	* @desc �ŏ�����J�n�����Ԃ�ݒ肷��
	* @param�@�ݒ肷��L�[
	*/
	void setStartState(const int key);

	// �o�^�������̂��폜����
	
	/**
	* @desc �o�^�������̂��폜����
	* @param �폜����L�[
	*/
	void deregistration(const int key);

	/**
	* @desc �S�Ă̓o�^���폜����
	*/
	void allDeregistration(void);

private:
	//��Ԋi�[�p�}�b�v
	std::map<int, CStateSwitch* > m_mapState;
	//���݂̏��
	CStateSwitch* m_pNowState = NULL;
};
//EOF