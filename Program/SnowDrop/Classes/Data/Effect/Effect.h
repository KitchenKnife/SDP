#pragma once
/*
 * Effect.h
 *
 *	2016/11/25	Osumi
 *
 */

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Data/Animation/Animation.h"
#include "Data/Move/Move.h"

//================================================
// �G�t�F�N�g�̊��N���X
//
//	2016/12/22
//									Author Harada
//================================================
class CEffect :public Sprite {
public:
	//================================================
	// �K�{�֐��̗�
	//================================================
	//�R���X�g���N�^
	CEffect(){}

	//�f�X�g���N�^
	virtual ~CEffect(){}

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update(float delta)override;

	CREATE_FUNC(CEffect);

	//================================================
	// �G�t�F�N�g���N���X�̊�b�����o
	//================================================
	//�A�j���[�V�����f�[�^
    CAnimation* m_pAnimations = NULL;

	//�ړ��f�[�^
	CMove* m_pMove = NULL;

	//�L���t���O
	bool m_activeFlag = true;

protected:

	//�ړ�����
	virtual void moveFunc();

	//�A�j���[�V��������
	virtual void animationFunc();

	//���f����
	virtual void applyFunc();
};

//================================================
// �w�肵���L�����N�^�[�ɒǐ�����G�t�F�N�g�̊��N���X
//================================================
class CEffectFollowCharacter : public CEffect {
	
};


//=============================================
// �G�t�F�N�g�̏W����
//=============================================
class CEffectAggregate {
private:
	//=============================================
	// �V���O���g���ݒ�
	//=============================================
	//���L�C���X�^���X
	static CEffectAggregate* m_pSareedAggregate;

	//�R���X�g���N�^
	CEffectAggregate(){}

public:
	//�f�X�g���N�^
	~CEffectAggregate();

	//���L�C���X�^���X�̎擾
	static CEffectAggregate* getInstance();
	//���L�C���X�^���X�̔j��
	static void removeInstance();

private:
	//=============================================
	// Aggregate�ݒ�
	//=============================================
	//�L�����N�^�[�̏W�܂�
	std::vector<CEffect*>* m_pEffects = NULL;

public:
	/**
	 * @desc	�L�����^�N�[�̏W�܂�̎Q�Ƃ�ݒ�
	 * @param	�ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	 */
	void set(std::vector<CEffect*>* pCharacters);

	/**
	 * @desc	�L�����^�N�[�̏W�܂�̂��擾
	 * @return	�L�����N�^�[�̏W�܂�
	 */
	std::vector<CEffect*>* get();

	/**
 	 * @desc	�z��ԍ�����w�肵���L�����^�N�[�P�̂��擾
	 * @param	�Y�����ԍ�
	 * @return	�L�����N�^�[
	 */
	CEffect* getAt(int index);

	/**
	 * @desc	�^�O����w�肵���L�����^�N�[�P�̂��擾
	 * @param	�^�O
	 * @return	�L�����N�^�[
	 * @tips	���݂��Ȃ����NULL��Ԃ�
	 */
	CEffect* getAtTag(int tag);

	/**
	 * @desc	�L�����N�^�[�̒ǉ�
	 * @param	�ǉ�����L�����N�^�[
	 */
	void add(CEffect* pCharacter);

	/**
	 * @desc	�L�����^�N�[�̏W�܂�̎��t�����Ă��鐔���擾
	 * @param	���t�����Ă��鐔
	 */
	int getSize();
};