
/*
* Character.h
*
*	2016/11/07	Osumi And Harada
*
*/

/*collision(CCharacter )*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Data/Animation/Animation.h"
#include "Data/Physical/Physical.h"
#include "Data/ActionController/ActionController.h"
#include "Data/ActionController/PlayerActionController/PlayerActionController.h"
#include "Data/Collision/Collision.h"
#include "Data/Collision/CollisionArea.h"
#include "Data/Status/Status.h"

#include <stdio.h>

using namespace cocos2d;

//================================================
// �L�����N�^�[�^�C�v
//================================================
enum class CHARACTER_TYPE :int {
	NONE = -1,	//����
	PLAYER_BOY = 0,	//���N�i�v���C���[�j
	PLAYER_GIRL = 1,	//����
	ENEMY = 2,	//�G
	BULLET = 3,	//�e
	GIMMICK = 4,//�M�~�b�N
};

//================================================
// �L�����N�^�[�N���X
//		�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
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

	//�A�N�V�����f�[�^�Q
	std::vector<CAction* >* m_pActions = NULL;

	//���̃f�[�^
	CBody* m_pBody = NULL;

	//�Փ˔����ԃf�[�^�Q
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//�X�e�[�^�X�f�[�^
	CStatus* m_pStatus = NULL;

	//��ԃf�[�^
	int m_state = 0;

	//�L���t���O
	//�\���E��\���֘A
	bool m_activeFlag = false;

	//�����t���O
	//�\�����Ă����Ԃł̐����֘A
	bool m_isAlive = false;

	//��܂��ȃ^�C�v�ʁi�L�����^�C�v�j
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

	//�ׂ��ȃ^�C�v�ʁi�^�O�j
	int m_tag = 0;

protected:
	//================================================ 
	// �L�����N�^�[�Q�̊�{�I�ɃA�b�v�f�[�g����֐��̗�
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
	//================================================ 
	// �Փ˔���p�֐��̗�
	//================================================
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

//=============================================
// �L�����N�^�[�̏W����
//	�V���O���g���������Ăق��̃t�@�C���ň�����悤�ɂ��Ă�������
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

public:
	/**
	 * @desc	�L�����^�N�[�̏W�܂�̎Q�Ƃ�ݒ�
	 * @param	�ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	 */
	void set(std::vector<CCharacter*>* pCharacters);

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
};

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
class CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CCharacterPartsFactory() {}

	//�A�j���[�V�����f�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CAnimation* >* getAnimations() = 0;
	//�ړ��f�[�^�̎��̂𐶐����ĕԂ�
	virtual CMove* getMove() = 0;
	//�������Z�f�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	//�A�N�V�����f�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CAction* >* getActions() = 0;
	//���̃f�[�^�̎��̂𐶐����ĕԂ�
	virtual CBody* getBody() = 0;
	//�X�e�[�^�X�f�[�^�̎��̂𐶐����ĕԂ�
	virtual CStatus* getStatus() = 0;
	//�Փ˔����ԃf�[�^�Q�̎��̂𐶐����ĕԂ�
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
};