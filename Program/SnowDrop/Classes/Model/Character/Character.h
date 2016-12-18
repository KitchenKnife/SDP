
/*
* Character.h
*
*	2016/11/07	Osumi
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
//using namespace std;

//================================================
// �L�����N�^�[�^�C�v
//================================================
enum class CHARACTER_TYPE :int {
	NONE = -1,//����
	PLAYER = 0,//�v���C���[
	ENEMY = 1,//�G
	BULLET = 2,//�e
	GIMMICK = 3,//�M�~�b�N
};

//================================================
// �L�����N�^�[�N���X
//		�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
//================================================
class CCharacter :public Sprite {
public:

	//�R���X�g���N�^
	CCharacter();

	//�f�X�g���N�^
	virtual ~CCharacter();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update(float deltaTime)override;

	//�A�j���[�V�����f�[�^�Q
	std::vector<CAnimation* >* m_pAnimations = NULL;

	//�ړ��f�[�^
	CMove* m_pMove = NULL;

	//�K�p�����镨�����Z�Q
	std::vector<CPhysical* >* m_pPhysicals = NULL;

	//�s����A�N�V�����Q
	std::vector<CAction* >* m_pActions = NULL;

	//���̃f�[�^
	CBody* m_pBody = NULL;

	//�Փ˔����ԌQ
	std::vector<CCollisionArea*>* m_pCollisionAreas = NULL;

	//��ԁi�h����ɂ���ă^�C�v���ω�����j
	int m_state = 0;

	// �X�e�[�^�X
	CStatus* m_pStatus = NULL;

	//�L���t���O
	bool m_activeFlag = false;

	//�����Ă邩����ł邩�̃t���O
	//true...�����Ă���@false...����ł���
	bool m_isAlive = false;

	//�^�O
	int m_tag = 0;

	//�L�����N�^�[�^�C�v
	CHARACTER_TYPE m_charaType = CHARACTER_TYPE::NONE;

protected:

	//�ړ�����
	virtual void moveFunc() = 0;

	//�A�j���[�V��������
	virtual void animationFunc() = 0;

	//��ʔ͈͒[���菈��
//	virtual void endOfScreen() = 0;

	//��ԃ`�F�b�N
	virtual void checkState() = 0;

	//���f����
	virtual void applyFunc() = 0;

public:
	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	virtual bool collision(CCharacter* pChara) = 0;

	/**
	* @desc �Փ˔��菈��
	*/
	virtual void collisionAll() = 0;

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	*		�@��ʉ��̍ۂ�0
	*/
	virtual void collisionBottomCallback(int event) {}

	/**
	* @desc �Փ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	virtual void collisionTopCallback(int event) {}

	/**
	* @desc �Փ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	virtual void collisionRightCallback(int event) {}

	/**
	* @desc ��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	virtual void collisionLeftCallback(int event) {}

	//================================================
	// 
	//�@�����܂łɃ����o�Ɋւ���R�[�h��ǉ�
	//		
	//================================================
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
	//�L�����N�^�[�̏W�܂�
	std::vector<CCharacter*>* m_pCharacters = NULL;

public:
	/**
	* @desc �L�����^�N�[�̏W�܂�̎Q�Ƃ�ݒ�
	* @param �ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
	*/
	void set(std::vector<CCharacter*>* pCharacters);

	/**
	* @desc �L�����^�N�[�̏W�܂�̂��擾
	* @return �L�����N�^�[�̏W�܂�
	*/
	std::vector<CCharacter*>* get();

	/**
	* @desc �L�����^�N�[�P�̂��擾
	* @param  �Y�����ԍ�
	* @return �L�����N�^�[
	*/
	CCharacter* getAt(int index);

	/**
	* @desc �L�����^�N�[�P�̂��擾
	* @param  �^�O
	* @return �L�����N�^�[
	*�@�@�@�@�@���݂��Ȃ����NULL��Ԃ�
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc �L�����^�N�[�̒ǉ�
	* @param  �ǉ�����L�����N�^�[
	*/
	void add(CCharacter* pCharacter);

	/**
	* @desc �L�����^�N�[�̏W�܂�̎��t�����Ă��鐔���擾
	* @param  ���t�����Ă��鐔
	*/
	int getSize();

};

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
class CCharacterPartsFactory {
public:

	virtual ~CCharacterPartsFactory() {}

	virtual std::vector<CAnimation* >* getAnimations() = 0;
	virtual CMove* getMove() = 0;
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	virtual std::vector<CAction* >* getActions() = 0;
	virtual CBody* getBody() = 0;
	virtual CStatus* getStatus() = 0;
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
};