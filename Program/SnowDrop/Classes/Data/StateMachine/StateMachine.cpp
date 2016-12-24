//==========================================
//
// File: StateMachine.cpp
//
// ��ԑJ�ڃ}�V�� �t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
#include"StateMachine.h"
#include "Constants.h"


/**
* @desc �R���X�g���N�^
*/
CStateBase::CStateBase(int nextRegisterKey)
	:m_nextRegisterKey(nextRegisterKey),m_defaultNextRegisterKey(nextRegisterKey)
{

}

/**
* @desc �f�X�g���N�^
*/
CStateBase::~CStateBase(void)
{

}

/**
* @desc	�J�n����
*/
void CStateBase::start(void)
{


}

/**
* @desc �X�V����
*/
void CStateBase::update(void)
{


}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CStateBase::onChangeEvent(void)
{

}

/**
* @desc �؂�ւ���������擾
*/
bool CStateBase::isNext(void)
{ 
	return this->m_isNext;
}

/**
* @desc ���̏�Ԃ̃L�[���擾����
*/
int CStateBase::getNextKey(void)
{
	return this->m_nextRegisterKey;
}



//==========================================
//
// Class: CStateSwitch
//
// ��Ԃ̐؂�ւ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CStateSwitch::CStateSwitch(CStateBase* const pState)
	:m_pState(pState)
{

}

/**
* @desc �f�X�g���N�^
*/
CStateSwitch::~CStateSwitch()
{
	SAFE_DELETE(this->m_pState);
}


// �A�b�v�f�[�g�̑O�ɌĂ΂��

/**
* @desc �J�n����
*/
void CStateSwitch::start(void)
{
	this->m_pState->start();
}

/**
* @desc �X�V����
*/
void CStateSwitch::update(void)
{
	if (this->m_pState)
	{
		this->m_pState->update();
	}
}

/**
* @desc ���̏�Ԃɂ����邩�ǂ������擾����
* @return true...������ false...�����Ȃ�
*/
bool CStateSwitch::canNextState(void)
{
	if (this->m_pState->isNext())
	{
		this->m_pState->onChangeEvent();
		return true;
	}
	return false;
}

// ���ɍs���o�^�������O
int CStateSwitch::getNextRegisterKey(void)
{
	return this->m_pState->getNextKey();
}




//==========================================
//
// Class: CStateMachine
//
// ��ԊǗ��N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CStateMachine::CStateMachine(void) :m_pNowState()
{

}

/**
* @desc �f�X�g���N�^
*/
CStateMachine::~CStateMachine(void)
{
	//���t������ԃf�[�^���폜
	std::map<int, CStateSwitch* >::iterator itr = this->m_mapState.begin();
	while (itr != this->m_mapState.end()) {
		//�N���X�̃C���X�^���X���폜
		SAFE_DELETE(itr->second);
		//�C�e���[�^�[���X�V
		itr++;
	}
}

/**
* @desc �X�V����
*/
void CStateMachine::update(void)
{
	if (!this->m_pNowState)
	{
		return;
	}
	
	//���݂̏�Ԃ��X�V
	this->m_pNowState->update();

	//���̏�Ԃֈڂ�邩�m�F
	if (this->m_pNowState->canNextState())
	{
		std::map<int, CStateSwitch* >::iterator itr = this->m_mapState.find(this->m_pNowState->getNextRegisterKey());
		if (itr == this->m_mapState.end())
		{
			return;
		}
		//���̏�Ԃ֑J��
		this->m_pNowState = itr->second;
		//���̏�Ԃ��J�n
		this->m_pNowState->start();
	}
}

/**
* @desc ��Ԃ�o�^����
* @param �o�^����B�ꖳ��̃L�[
* @param 
*/
void CStateMachine::registerState(const int key,CStateSwitch* const pState)
{
	//��Ԃ�o�^����
	this->m_mapState.insert(std::map<int, CStateSwitch*>::value_type(key,pState));
}

/**
* @desc �ŏ�����J�n�����Ԃ�ݒ肷��
* @param �ݒ肷��L�[
*/
void CStateMachine::setStartState(const int key)
{
	std::map<int, CStateSwitch* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	
	this->m_pNowState = itr->second;
	this->m_pNowState->start();
}

/**
* @desc �o�^�������̂��폜����
* @param �폜����L�[
*/
void CStateMachine::deregistration(const int key)
{
	std::map<int, CStateSwitch* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	this->m_mapState.erase(itr);
}

/**
* @desc �S�Ă̓o�^���폜����
*/
void CStateMachine::allDeregistration(void)
{
	this->m_mapState.clear();
}
//EOF