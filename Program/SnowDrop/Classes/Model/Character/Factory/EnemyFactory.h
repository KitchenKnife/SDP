/*
 * EnemyFactory.h
 *
 *	2016/12/21	Yamasaki And Harada
 *	
 */

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Character\EnemyCharacter\Marionette\MarionetteCharacter.h"
#include <map>

//================================================
// �L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CEnemeyPartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CEnemeyPartsFactory();

	//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CAnimation* >* getAnimations()override;
	//�ړ��f�[�^�̎��̂𐶐����擾
	virtual CMove* getMove()override;
	//�������Z�Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CPhysical* >* getPhysicals()override;
	//���̃f�[�^�̎��̂𐶐����擾
	virtual CBody* getBody()override;
	//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
	*	@return ��ԑJ�ڃf�[�^
	*	@author Shinya Ueba
	*/
	virtual	CStateMachine*	getStateMachine(void)override;


};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CEnemyFactory {
protected:

	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy() = 0;

	//�ړ��f�[�^�̐ݒ�
	virtual void settingMove(CEnemyCharacter* pChara ,float x,float y) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CEnemyCharacter* pChara) = 0;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	virtual void settingAnimations(CEnemyCharacter* pChara) = 0;
	//�������Z�Q�f�[�^�̐ݒ�
	virtual void settingPhysicals(CEnemyCharacter* pChara) = 0;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	virtual void settingActions(CEnemyCharacter* pChara) = 0;
	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CEnemyCharacter* pChara) = 0;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	virtual void settingCollisionArea(CEnemyCharacter* pChara) = 0;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CEnemyCharacter* pChara) = 0;
	//���̑��@�����ݒ�
	virtual void settingInitialize(CEnemyCharacter* pChara) = 0;

public:
	//�f�X�g���N�^
	virtual ~CEnemyFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CEnemyCharacter* create(float posX,float posY) {

		//�G�̐����Ƒg�ݗ���
		CEnemyCharacter* pChara = this->createEnemy();

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara,posX,posY);
		//�摜�̐ݒ�
		this->settingTexture(pChara);
		//�A�j���[�V�����Q�f�[�^�̐ݒ�
		this->settingAnimations(pChara);
		//�������Z�Q�f�[�^�̐ݒ�
		this->settingPhysicals(pChara);
		//�A�N�V�����Q�f�[�^�̐ݒ�
		this->settingActions(pChara);
		//���̃f�[�^�̐ݒ�
		this->settingBody(pChara);
		//�Փ˔����ԌQ�f�[�^�̐ݒ�
		this->settingCollisionArea(pChara);
		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pChara);
		//���̑�������
		this->settingInitialize(pChara);

		return pChara;
	}
};

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
template <class Ty>
class CEnemyCreateFactory :public CEnemyFactory {
public:
	//�f�X�g���N�^
	virtual ~CEnemyCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy()override {

		// �G����
		CEnemyCharacter* pEnemy = Ty::create();
		// �G�p�[�c�H�ꐶ��
		CEnemeyPartsFactory pEnemyPartsFactory;

		// �p�[�c�̐ݒ�
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();
		
		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//��ԃf�[�^�̐����Ǝ擾
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//�@�G�Ԃ�
		return pEnemy;
	}
};

//================================================
// ���C�f�b�h�H��
//================================================
template<class Ty>
class CMaideadFactory :public CEnemyCreateFactory<Ty> {
public:
	//�f�X�g���N�^
	virtual ~CMaideadFactory(){}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;

	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;

	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};


//================================================
//�@�R�E�����H��
//================================================
template <class Ty>
class CBatFactory :public CEnemyCreateFactory<Ty> {
public:
	//�f�X�g���N�^
	~CBatFactory(){}
	
	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//�@�}���X�H��
//================================================
template <class Ty>
class CMaliceFactory :public CEnemyCreateFactory<Ty> {
public:
	//�f�X�g���N�^
	~CMaliceFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//�@NutCracker�H��
//================================================
template <class Ty>
class CNutCrackerFactory :public CEnemyCreateFactory<Ty> {
public:
	//�f�X�g���N�^
	~CNutCrackerFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
//�@Baron�H��
//================================================
template <class Ty>
class CBaronFactory :public CEnemyCreateFactory<Ty> {
public:
	//�f�X�g���N�^
	~CBaronFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};



//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CMouseKingCreateFactory :public CEnemyFactory {
public:
	//�f�X�g���N�^
	virtual ~CMouseKingCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy()override {

		// �G����
		CMouseKingCharacter* pEnemy = CMouseKingCharacter::create();
		// �G�p�[�c�H�ꐶ��
		CEnemeyPartsFactory pEnemyPartsFactory;

		// �p�[�c�̐ݒ�
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//��ԃf�[�^�̐����Ǝ擾
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//�@�G�Ԃ�
		return pEnemy;
	}
};


//================================================
//�@MouseKing�H��
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMouseKingFactory :public CMouseKingCreateFactory 
{
public:
	//�f�X�g���N�^
	~CMouseKingFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CMouseEnemyFactory: public CEnemyFactory 
{
protected:
	//�G�̐����Ƒg�ݗ���
	virtual CMouseCharacter* createEnemy(CMouseKingCharacter* pMaster,int positionType) = 0;
public:
	//�f�X�g���N�^
	virtual ~CMouseEnemyFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CMouseCharacter* create(float posX, float posY,CMouseKingCharacter* pMaster,int positionType) {

		//�G�̐����Ƒg�ݗ���
		CMouseCharacter* pChara = this->createEnemy(pMaster,positionType);

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara, posX, posY);
		//�摜�̐ݒ�
		this->settingTexture(pChara);
		//�A�j���[�V�����Q�f�[�^�̐ݒ�
		this->settingAnimations(pChara);
		//�������Z�Q�f�[�^�̐ݒ�
		this->settingPhysicals(pChara);
		//�A�N�V�����Q�f�[�^�̐ݒ�
		this->settingActions(pChara);
		//���̃f�[�^�̐ݒ�
		this->settingBody(pChara);
		//�Փ˔����ԌQ�f�[�^�̐ݒ�
		this->settingCollisionArea(pChara);
		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pChara);
		//���̑�������
		this->settingInitialize(pChara);

		return pChara;
	}
};


//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CMouseCreateFactory :public CMouseEnemyFactory {
public:
	//�f�X�g���N�^
	virtual ~CMouseCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy()override {
		return NULL;
	}

	//�G�̐����Ƒg�ݗ���
	CMouseCharacter* createEnemy(CMouseKingCharacter* pMaster, int positionType){

		// �G����
		CMouseCharacter* pEnemy = CMouseCharacter::create(pMaster,positionType);
		// �G�p�[�c�H�ꐶ��
		CEnemeyPartsFactory pEnemyPartsFactory;

		// �p�[�c�̐ݒ�
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//��ԃf�[�^�̐����Ǝ擾
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//�@�G�Ԃ�
		return pEnemy;
	}
};

//================================================
//�@Mouse�H��
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMouseFactory :public CMouseCreateFactory
{
public:
	//�f�X�g���N�^
	~CMouseFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};



//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CMarionetteCreateFactory :public CEnemyFactory {
public:
	//�f�X�g���N�^
	virtual ~CMarionetteCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy()override {

		// �G����
		CMarionetteCharacter* pEnemy = CMarionetteCharacter::create();
		// �G�p�[�c�H�ꐶ��
		CEnemeyPartsFactory pEnemyPartsFactory;

		// �p�[�c�̐ݒ�
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();

		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//��ԃf�[�^�̐����Ǝ擾
		pEnemy->m_pStateMachine = pEnemyPartsFactory.getStateMachine();

		//�@�G�Ԃ�
		return pEnemy;
	}
};


//================================================
//�@Marionette�H��
//	2017/01/11	Autor Shinya Ueba
//================================================
class CMarionetteFactory :public CMarionetteCreateFactory
{
public:
	//�f�X�g���N�^
	~CMarionetteFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};


//================================================
// �G�H��Q���Ǘ�����N���X
//	�iSingleton�j
//================================================
class CEnemyFactoryManager {
private:
	//�R���X�g���N�^
	CEnemyFactoryManager() {
		//���C�h�����H��𐶐��� [key : MAIDEAD] �Ɏ��t����
		m_factories[ENEMY_TYPE::MAIDEAD] = new CMaideadFactory<CEnemyCharacter>();

		//�R�E���������H��𐶐��� [key : BAT] �Ɏ��t����
		m_factories[ENEMY_TYPE::BAT] = new CBatFactory<CEnemyCharacter>();

		//�R�E���������H��𐶐��� [key : BAT] �Ɏ��t����
		m_factories[ENEMY_TYPE::MALICE] = new CMaliceFactory<CEnemyCharacter>();

		//NutCracker�����H��𐶐��� [key : NutCracker] �Ɏ��t����
		m_factories[ENEMY_TYPE::NUTCRACKER] = new CNutCrackerFactory<CEnemyCharacter>();

		//Baron�����H��𐶐��� [key : Baron] �Ɏ��t����
		m_factories[ENEMY_TYPE::BARON] = new CBaronFactory<CEnemyCharacter>();

		//MouseKing�����H��𐶐��� [key : NutCracker] �Ɏ��t����
		m_factories[ENEMY_TYPE::MOUSEKING] = new CMouseKingFactory();

		//Marionette�����H��𐶐��� [key : Marionette] �Ɏ��t����
		m_factories[ENEMY_TYPE::MARIONETTE ] = new CMarionetteFactory();
	}

	//���L�̃C���X�^���X
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//�f�X�g���N�^
	~CEnemyFactoryManager() {

		//���t�����H��Q���폜
		std::map<ENEMY_TYPE, CEnemyFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
			//�C�e���[�^�[���X�V
			itr++;
		}
	}


	//�C���X�^���X�̎擾
	static CEnemyFactoryManager* getInstance();

	//�C���X�^���X�̔j��
	static void removeInstance();

	//�G�H��Q
	std::map<ENEMY_TYPE, CEnemyFactory*> m_factories;

	/**
	 * @desc	�G�L�����N�^�[�𐶐�
	 * @param	�o��������ʒu
	 * @param	�G�̃^�C�v
	 * @return	���������G�L�����N�^�[
	 */
	CEnemyCharacter* create(Point pos, ENEMY_TYPE type) {
		//�G�̃^�C�v�� key �Ƃ��ēG�𐶐����ĕԂ�
		return this->m_factories[type]->create(pos.x, pos.y);
	}

};

//EOF