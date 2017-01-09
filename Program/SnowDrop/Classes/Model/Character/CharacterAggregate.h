#pragma once
//==========================================
//
// File: CharacterAggregate.h
//
// �L�����N�^�[�̏W���� �w�b�_�[�t�@�C��
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "Model\Character\PlayerCharacter\PlayerCharacter.h"
#include "Model\Character\GirlCharacter\GirlCharacter.h"



//=============================================
// �L�����N�^�[�̏W����
//	�V���O���g���������Ăق��̃t�@�C���ň�����悤�ɂ��Ă�������
//
//	2016/12/22
//									Author Harada
//=============================================
class CCharacterAggregate {
private:
	//=============================================
	// �V���O���g���ݒ�͂�������
	//=============================================
	//���L�C���X�^���X
	static CCharacterAggregate* m_pSareedAggregate;

	//�R���X�g���N�^
	CCharacterAggregate();

public:
	//�f�X�g���N�^
	~CCharacterAggregate();

	//���L�C���X�^���X�̎擾
	static CCharacterAggregate* getInstance();
	//���L�C���X�^���X�̔j��
	static void removeInstance();
	//=============================================
	// �V���O���g���ݒ�͂����܂�
	//=============================================

private:
	//=============================================
	// Aggregate�ݒ�͂�������
	//=============================================
	//�L�����N�^�[�̏W�܂�
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//�v���C���[
	CPlayerCharacterBoy* m_pPlayer = NULL;

	//�K�[��
	CPlayerCharacterGirl* m_pGirl = NULL;

public:
	/**
	* @desc	�L�����^�N�[�̏W�܂�̎Q�Ƃ�ݒ�
	* @param	�ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	*/
	void set(std::vector<CCharacter*>* pCharacters);
	/**
	* @desc	�L�����^�N�[�̏W�܂�̎Q�Ƃ�ύX
	* @param	�ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	*/
	void change(std::vector<CCharacter*>* pCharacters);


	/**
	* @desc	�L�����^�N�[�̏W�܂�̂��擾
	* @return	�L�����N�^�[�̏W�܂�
	*/
	std::vector<CCharacter*>* get();

	/**
	* @desc	�z��ԍ�����w�肵���L�����^�N�[�P�̂��擾
	* @param	�Y�����ԍ�
	* @return	�L�����N�^�[
	*/
	CCharacter* getAt(int index);

	/**
	* @desc	�^�O����w�肵���L�����^�N�[�P�̂��擾
	* @param	�^�O
	* @return	�L�����N�^�[
	* @tips	���݂��Ȃ����NULL��Ԃ�
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc	�L�����N�^�[�̒ǉ�
	* @param	�ǉ�����L�����N�^�[
	*/
	void add(CCharacter* pCharacter);

	/**
	* @desc	�L�����^�N�[�̏W�܂�̎��t�����Ă��鐔���擾
	* @param	���t�����Ă��鐔
	*/
	int getSize();

	/**
	* @desc �v���C���[�L�����N�^�[��ݒ�
	*/
	void setPlayer(CPlayerCharacterBoy* const pPlayer);

	/**
	* @desc	�v���C���[�L�����N�^�[���擾
	* @param �v���C���[�L�����N�^�[
	*/
	CPlayerCharacterBoy* getPlayer(void);


	/**
	* @desc	�K�[���L�����N�^�[��ݒ�
	* @param �K�[���̃C���X�^���X
	*/
	void setGirl(CPlayerCharacterGirl* const pGirl);

	/**
	* @desc	�K�[���L�����N�^�[���擾
	* @return �K�[���̃C���X�^���X
	*/
	CPlayerCharacterGirl* getGirl(void);
};

