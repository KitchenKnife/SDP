
#include "LaunchTrigger.h"
#include "Model/Character/Factory/EnemyFactory.h"
#include "Model/Character/Factory/GimmickFactory.h"
#include "Model/Character/Factory/EffectFactory.h"

//=======================================
//
//  �G�o���g���K�[
//		�G�o���f�[�^���g���K�[�Ƃ��ēG�o���Ƃ����C�x���g�����s������
//
//=======================================
//�f�X�g���N�^
CEnemyLaunchTrigger::~CEnemyLaunchTrigger() {
	//�G�o���f�[�^���폜
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	�C�x���g���s���邩�ǂ���
 * @retrun	true...�C�x���g���s��
 */
bool CEnemyLaunchTrigger::isTrigger(){
	//�G�o���f�[�^�ɒ��g���Ȃ����
	if(this->m_pLaunchdata == NULL){
		//�C�x���g���s�@�s�@��Ԃ��B
		return false;
	}
	//�C�x���g���s�@�@��Ԃ�
	return true;
}

/**
 * @desc	�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
 * @tips	�g���K�[�����ɃC�x���g�����s
 */
CCharacter* CEnemyLaunchTrigger::action(){

	//�G�𐶐�
	//�����ɏo��������|�C���g�ƓG�̃^�C�v��n��
	CCharacter* pEnemyCharacter = CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		this->m_pLaunchdata->m_type
	);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	//���������G�L�����N�^�[��Ԃ��B
	return pEnemyCharacter;
}

//=======================================
//
//  �M�~�b�N�����g���K�[
//
//=======================================
//�f�X�g���N�^
CGimmickLaunchTrigger::~CGimmickLaunchTrigger() {
	//�M�~�b�N�o���f�[�^���폜
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	�C�x���g���s���邩�ǂ���
 * @retrun	true...�C�x���g���s��
 */
bool CGimmickLaunchTrigger::isTrigger() {
	//�M�~�b�N�o���f�[�^�ɒ��g���Ȃ����
	if (this->m_pLaunchdata == NULL) {
		//�C�x���g���s�@�s�@��Ԃ�
		return false;
	}
	//�C�x���g���s�@�@��Ԃ�
	return true;
}

/**
 * @desc	�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
 * @tips	�g���K�[�����ɃC�x���g�����s
 */
CCharacter* CGimmickLaunchTrigger::action() {

	//�M�~�b�N�𐶐�
	//�����ɃM�~�b�N�̃^�C�v�Əo��������ʒu��n��
	CCharacter* pGimmickCharacter = CGimmickFactoryManager::getInstance()->create(
		(int)this->m_pLaunchdata->m_type,
		this->m_pLaunchdata->m_pos
	);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	//���������M�~�b�N��Ԃ��B
	return pGimmickCharacter;
}


//=======================================
//
//  �G�t�F�N�g�����g���K�[
//
//=======================================
//�f�X�g���N�^
CEffectLaunchTrigger::~CEffectLaunchTrigger() {
	//�G�t�F�N�g�o���f�[�^���폜
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	�C�x���g���s���邩�ǂ���
 * @retrun	true...�C�x���g���s��
 */
bool CEffectLaunchTrigger::isTrigger() {
	//�G�t�F�N�g�o���f�[�^�ɒ��g���Ȃ����
	if (this->m_pLaunchdata == NULL) {
		//�C�x���g���s�@�s�@��Ԃ�
		return false;
	}
	//�C�x���g���s�@�@��Ԃ�
	return true;
}

/**
 * @desc	�ݒ肳��Ă���G�t�F�N�g�o���f�[�^�����ɃG�t�F�N�g�𐶐�����
 * @tips	�g���K�[�����ɃC�x���g�����s
 */
CCharacter* CEffectLaunchTrigger::action() {

	//�G�t�F�N�g�̐���
	//�����ɃG�t�F�N�g�̃^�C�v�Əo��������ʒu��n��
	CCharacter* pEffectCharacter = CEffectFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		this->m_pLaunchdata->m_type
	);

	//���˂��I��������ǂ����̃t���O�𗧂Ă�
	this->m_activeFlag = false;

	//���������M�~�b�N��Ԃ��B
	return pEffectCharacter;
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

	//���L�C���X�^���X�����݂��Ȃ����
	if (CLaunchScheduler::m_pSharedScheduler == NULL) {
		//���L�C���X�^���X�𐶐�
		CLaunchScheduler::m_pSharedScheduler = new CLaunchScheduler();
	}
	//���L�C���X�^���X��Ԃ��B
	return CLaunchScheduler::m_pSharedScheduler;
}

//���L�C���X�^���X�̔j��
void CLaunchScheduler::removeInstance() {
	//���L�C���X�^���X�̍폜
	SAFE_DELETE(CLaunchScheduler::m_pSharedScheduler);
}

//�f�X�g���N�^
CLaunchScheduler::~CLaunchScheduler() {
	//���L�C���X�^���X�̍폜
	SAFE_DELETE(this->m_pLauncher);
}

/**
 * @desc	���ˑ�̐���
 * @param	���ˑ�ɐݒ肷��o���X�P�W���[���̃A�h���X
 */
void CLaunchScheduler::createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule) {
	//���ˑ䂪���݂��Ȃ����
	if (this->m_pLauncher == NULL) {
		//���ˑ�𐶐�
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}
}

/**
 * @desc	�L�����N�^�[�̏o��
 * @param	���t���郌�C���[
 */
void CLaunchScheduler::launchCharacter(cocos2d::Layer* pLayer) {

	//�X�P�W���[���Ɏ��t�����Ă���N�����ł���g���K�[�S�Ă��N������
	std::shared_ptr<CLauncher::CLaunchTriggerIterator>itr = this->m_pLauncher->iterator();
	//���̋N���\�ȏo���g���K�[�����邩�ǂ������`�F�b�N
	while (itr->hasNext() == true) {
		//�N���\�ȏo���g���K�[���擾���ďo���g���K�[�C�e���[�^�[�����֐i�߂�
		CLaunchTrigger* pTrigger = itr->next();

		//�o���g���K�[���N�����ăL�����N�^�[�𐶐����擾
		CCharacter* pChara = pTrigger->action();

		//NULL�`�F�b�N
		if(pChara != NULL){
			
			//�L�����N�^�[���L�����N�^�[�̏W���̂Ɏ��t����
			CCharacterAggregate::getInstance()->add(pChara);

			//�L�����N�^�[�����C�����C���[�Ɏ��t����
			pLayer->addChild(pChara);

			CCLOG("%d", CCharacterAggregate::getInstance()->getSize());
		}
	}
}

