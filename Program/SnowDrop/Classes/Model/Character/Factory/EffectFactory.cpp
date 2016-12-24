//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EffectFactory.h"

//================================================
// ���N�L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//
//	2016/12/23
//									Author Harada
//================================================
//�A�j���[�V�����Q�f�[�^�̐����Ǝ擾
std::vector<CAnimation* >* CEffectPaartsFactory::getAnimations() {
	//�A�j���[�V�����Q�̍쐬
	return new std::vector<CAnimation*>();
}

//�ړ��f�[�^�̐����Ǝ擾
CMove* CEffectPaartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

//�������Z�Q�f�[�^�̐����Ǝ擾
std::vector<CPhysical* >* CEffectPaartsFactory::getPhysicals() {
	//�������Z�Q�쐬
	return new std::vector<CPhysical*>();
}

//�A�N�V�����Q�f�[�^�̐����Ǝ擾
std::vector<CAction* >* CEffectPaartsFactory::getActions() {
	//�A�N�V�����Q���쐬
	return new std::vector<CAction*>();
}

//���̃f�[�^�̐����Ǝ擾
CBody* CEffectPaartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̐����Ǝ擾
std::vector<CCollisionArea* >* CEffectPaartsFactory::getCollisionAreas() {
	//�Փ˔����ԌQ�̐���
	return new std::vector<CCollisionArea*>();
}

//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================
//�G�t�F�N�g�̐����Ɛݒ�
CEffect* CEffectFactory::create(cocos2d::Point pos) {

	//�G�t�F�N�g�̐����Ƒg�ݗ���
	CEffect* pChara = this->createPlayer();

	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pChara, pos);
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

	//���̂ق�������
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================
//�G�t�F�N�g�̐����Ƒg�ݗ���
CEffect* CEffectCreateFactory::createPlayer() {

	//���N�L�����N�^�[�̐���
	CEffect* pEffe = CEffect::create();

	//�G�t�F�N�g�p�[�c�H��𐶐�
	CEffectPaartsFactory  factory;

	//�ړ��f�[�^�̎��̂̎擾
	pEffe->m_pMove = factory.getMove();

	//�A�j���[�V�����Q�f�[�^�̎��̂̎擾
	pEffe->m_pAnimations = factory.getAnimations();

	//�������Z�Q�f�[�^�̎��̂̎擾
	pEffe->m_pPhysicals = factory.getPhysicals();

	//�A�N�V�����Q�f�[�^�̎��̂̎擾
	pEffe->m_pActions = factory.getActions();

	//���̃f�[�^�̎��̂̎擾
	pEffe->m_pBody = factory.getBody();

	//�Փ˔����ԌQ�f�[�^�̎��̂̎擾
	pEffe->m_pCollisionAreas = factory.getCollisionAreas();

	return pEffe;
}

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================

//�ړ��f�[�^�̐ݒ�
void CBaseEffectFactory::settingMove(CEffect* pChara, cocos2d::Point pos) {
	
}

//�摜�̐ݒ�
void CBaseEffectFactory::settingTexture(CEffect* pChara) {

}

//�A�j���[�V�����Q�f�[�^�̐ݒ�
void CBaseEffectFactory::settingAnimations(CEffect* pChara) {

}

//�������Z�Q�f�[�^�̐ݒ�
void CBaseEffectFactory::settingPhysicals(CEffect* pChara) {

}

//�A�N�V�����Q�f�[�^�̐ݒ�
void CBaseEffectFactory::settingActions(CEffect* pChara) {
	
}

//���̃f�[�^�̐ݒ�
void CBaseEffectFactory::settingBody(CEffect* pChara) {

}

//�Փ˔����ԌQ�f�[�^�̐ݒ�
void CBaseEffectFactory::settingCollisionArea(CEffect* pChara) {


}

//���̑������ݒ�
void CBaseEffectFactory::settingInitialize(CEffect* pChara) {

}


//================================================
// ���N�L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/22
//									Author Harada
//================================================
//���L�C���X�^���X�̎���
CEffectFactoryManager* CEffectFactoryManager::m_pEffectFactoryManager = NULL;

//���L�C���X�^���X�̎擾
CEffectFactoryManager* CEffectFactoryManager::getInstance() {
	//���L�C���X�^���X�̎��̂����݂��Ȃ����
	if (CEffectFactoryManager::m_pEffectFactoryManager == NULL) {
		//���L�C���X�^���X�̎��̂𐶐�
		CEffectFactoryManager::m_pEffectFactoryManager = new CEffectFactoryManager();
	}
	//���L�C���X�^���X��Ԃ��B
	return CEffectFactoryManager::m_pEffectFactoryManager;
}