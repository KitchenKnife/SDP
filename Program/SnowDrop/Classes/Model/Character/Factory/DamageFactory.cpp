//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "DamageFactory.h"

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
//�f�X�g���N�^
CDamagePartsFactory::~CDamagePartsFactory() {}

//�ړ��f�[�^�̎��̂𐶐����擾
CMove* CDamagePartsFactory::getMove() {
	return new CMove();
}

//�������Z�Q�f�[�^�̎��̂𐶐����擾
std::vector<CPhysical* >* CDamagePartsFactory::getPhysicals() {
	return new std::vector<CPhysical*>();
}


//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
std::vector<CAnimation* >* CDamagePartsFactory::getAnimations() {
	return new std::vector<CAnimation*>();
}

//���̃f�[�^�̎��̂𐶐����擾
CBody* CDamagePartsFactory::getBody() {
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
std::vector<CCollisionArea* >* CDamagePartsFactory::getCollisionAreas() {
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
*	@return ��ԑJ�ڃf�[�^
*	@author Shinya Ueba
*/
CStateMachine*	CDamagePartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}

//================================================
// �p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CDamageFactoryManager* CDamageFactoryManager::m_pDamageFactoryManager = NULL;

//�C���X�^���X�̎擾
CDamageFactoryManager* CDamageFactoryManager::getInstance() {

	//���L�C���X�^���X�����݂��Ă��Ȃ����
	if (CDamageFactoryManager::m_pDamageFactoryManager == NULL) {
		//���L�C���X�^���X�𐶐�
		CDamageFactoryManager::m_pDamageFactoryManager = new CDamageFactoryManager();
	}

	//���L�̃C���X�^���X��Ԃ��B
	return CDamageFactoryManager::m_pDamageFactoryManager;
}