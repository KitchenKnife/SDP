
#include "LaunchTrigger.h"
#include "Model/Character/Character.h"
#include "Model/Character/EnemyCharacter/EnemyFactory.h"
#include "Model/Character/GimmickFactory.h"

//=======================================
//
//  �G�o���g���K�[
//		�G�o���f�[�^���g���K�[�Ƃ��ēG�o���Ƃ����C�x���g�����s������
//
//=======================================
//�f�X�g���N�^
CEnemyLaunchTrigger::~CEnemyLaunchTrigger() {
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
* @desc		�C�x���g���s���邩�ǂ���
* @retrun	true...�C�x���g���s��
*/
bool CEnemyLaunchTrigger::isTrigger(){
	if(this->m_pLaunchdata == NULL){
		return false;
	}
	return true;
}

/**
* @desc		�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
*			�g���K�[�����ɃC�x���g�����s
*/
CCharacter* CEnemyLaunchTrigger::action(){

	//�G�𐶐�
	CCharacter* pEnemyCharacter = (CCharacter*)CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		(int)this->m_pLaunchdata->m_type
	);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	return pEnemyCharacter;
}

//=======================================
//
//  �e���˃g���K�[
//		�e���˃f�[�^���g���K�[�Ƃ��Ēe���˂Ƃ����C�x���g�����s������
//
//=======================================


//=======================================
//
//  �M�~�b�N�����g���K�[
//
//=======================================
//�f�X�g���N�^
CGimmickLaunchTrigger::~CGimmickLaunchTrigger() {
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
* @desc		�C�x���g���s���邩�ǂ���
* @retrun	true...�C�x���g���s��
*/
bool CGimmickLaunchTrigger::isTrigger() {
	if (this->m_pLaunchdata == NULL) {
		return false;
	}
	return true;
}

/**
* @desc		�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
*			�g���K�[�����ɃC�x���g�����s
*/
CCharacter* CGimmickLaunchTrigger::action() {

	//�e�𐶐�
	CCharacter* pGimmickCharacter = (CCharacter*)CGimmickFactoryManager::getInstance()->create(
		(int)this->m_pLaunchdata->m_type,
		this->m_pLaunchdata->m_pos
	);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	return pGimmickCharacter;
}

//=======================================
//
//  �o���X�P�W���[���[
//	Singleton
//
//=======================================
//���L�C���X�^���X�{��
CLaunchScheduler* CLaunchScheduler::m_pSharedScheduler = NULL;

//�R���X�g���N�^
CLaunchScheduler::CLaunchScheduler(){}

//���L�C���X�^���X�̎擾
CLaunchScheduler* CLaunchScheduler::getInstance() {

	if (CLaunchScheduler::m_pSharedScheduler == NULL) {
		CLaunchScheduler::m_pSharedScheduler = new CLaunchScheduler();
	}
	return CLaunchScheduler::m_pSharedScheduler;
}

//���L�C���X�^���X�̔j��
void CLaunchScheduler::removeInstance() {
	SAFE_DELETE(CLaunchScheduler::m_pSharedScheduler);
}

//�f�X�g���N�^
CLaunchScheduler::~CLaunchScheduler() {
	SAFE_DELETE(this->m_pLauncher);
}

/**
* @desc		���ˑ�̐���
* @param	���ˑ�ɐݒ肷��o���X�P�W���[���̃A�h���X
*/
void CLaunchScheduler::createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule) {

	if (this->m_pLauncher == NULL) {
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}

}

/**
* @desc		�L�����N�^�[�̏o��
* @param	���t���郌�C���[
*/
void CLaunchScheduler::launchCharacter(cocos2d::Layer* pLayer) {

	//�X�P�W���[���Ɏ��t�����Ă���N�����ł���g���K�[�S�Ă��N������
	std::shared_ptr<CLauncher::CLaunchTriggerIterator>itr = this->m_pLauncher->iterator();
	//���̋N���\�ȏo���g���K�[�����邩�ǂ������`�F�b�N
	while (itr->hasNext() == true) {
		//�N���\�ȏo���g���K�[���擾���ďo���g���K�[�C�e���[�^�[�����֐i�߂�
		CLaunchTrigger* pTrigger = itr->next();

		//�o���g���K�[���N��
		CCharacter* pChara = pTrigger->action();

		//NULL�`�F�b�N
		if(pChara != NULL){
			
			//�L�����N�^�[���L�����N�^�[�̏W���̂Ɏ��t����
			CCharacterAggregate::getInstance()->add(pChara);

			//�L�����N�^�[�����C�����C���[�Ɏ��t����
			pLayer->addChild(pChara);
		}

	}

}

