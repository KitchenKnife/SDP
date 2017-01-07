#pragma once
#include "Model/Character/Character.h"

class CPlayerCharacterBoy;

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
	//�v���C���[�i���N�j�̃A�h���X
	CPlayerCharacterBoy* m_pPlayerChara;

	//��q���\�}�[�N�̃C���X�^���X
	cocos2d::CCParticleSystemQuad* m_pActionMark = NULL;
	
	//�}�[�N�̃p�[�e�B�N�����x...1.0f�Œʏ푬�x
	int m_durationMark = 0;
	
	//�}�[�N�̃p�[�e�B�N����\������J�E���^�[
	int m_counterActionMark = 0;

	/**
	 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���o�������邩�`�F�b�N����
	 */
	void checkPlayerAndGirlActionMark(void);

	/**
	 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���o�Ă��邩�擾
	 * @author	Shinya Ueba
	 */
	void setPlayerAndGirlActionMark(void);

	/**
	 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���쐬���ăK�[���Ɏ��t����
	 * @return	true...�}�[�N���o�����Ă���B
	 * @author	Shinya Ueba
	 */
	bool getPlayerAndGirlActionMark(void);

};
