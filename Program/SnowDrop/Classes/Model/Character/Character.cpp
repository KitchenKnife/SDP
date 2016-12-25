/*
 * Character.cpp
 *
 *	2016/11/07	Osumi
 *
 */
#include "Character.h"

//================================================
// �L�����N�^�[�N���X
//		�S�ẴL�����N�^�[�̐��`�ƂȂ钊�ۃN���X
//
//	2016/12/22
//									Author Harada
//================================================
//�R���X�g���N�^
CCharacter::CCharacter() {}

//�f�X�g���N�^

/**
*	@desc �f�X�g���N�^
*	@autor	Osumi
*	@autor	Harada
*	@autor	Shinya Ueba
*/
CCharacter::~CCharacter() {

	//��ԑJ�ڃf�[�^�̍폜
	SAFE_DELETE(this->m_pStateMachine);

	//���̃f�[�^�̍폜
	SAFE_DELETE(this->m_pBody);

	//�A�N�V�����Q�f�[�^�̍폜
	std::map<int, std::vector<CAction*>* >::iterator itr = this->m_mapAction.begin();
	while (itr != this->m_mapAction.end()) {

		if (itr->second)
		{
			std::vector<CAction*>* pActions = itr->second;

			for (CAction* pAction : *pActions)
			{
				SAFE_DELETE(pAction);
			}
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
		}
		//�C�e���[�^�[���X�V
		itr++;
	}

	//�������Z�Q�f�[�^�̍폜
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		SAFE_DELETE(pPhysical);
	}
	SAFE_DELETE(this->m_pPhysicals);

	//�ړ��f�[�^�̍폜
	SAFE_DELETE(this->m_pMove);


	//�A�j���[�V�����f�[�^�Q�̍폜
	for (CAnimation* pAnimation: (*m_pAnimations)) {
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);
}

//����������
bool CCharacter::init() {
	//�X�v���C�g�̏�����
	if (Sprite::init() == false) {
		//�������Ɏ��s�����ꍇ
		CCLOG("Sprite�̏������Ɏ��s");
		return false;
	}
	//�ʂɍX�V�������N��������B
	this->scheduleUpdate();

	//�������ɐ��������ꍇ
	return true;
}

//�X�V����
void CCharacter::update(float deltaTime) {


	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//�Փ˔���
	this->collisionAll();

	//��ԃ`�F�b�N
	this->checkState();

	//���f����
	this->applyFunc();
}

//=============================================
// �L�����N�^�[�̏W����
//	�V���O���g���������Ăق��̃t�@�C���ň�����悤�ɂ��Ă�������
//
//	2016/12/22
//									Author Harada
//=============================================
//���L�C���X�^���X�̖{��
CCharacterAggregate* CCharacterAggregate::m_pSareedAggregate = NULL;

//�R���X�g���N�^
CCharacterAggregate::CCharacterAggregate() {}

//�f�X�g���N�^
CCharacterAggregate::~CCharacterAggregate() {

	// �L�����̉��
	for (CCharacter* pChara : (*this->m_pCharacters)) {
		SAFE_DELETE(pChara);
		}
	SAFE_DELETE(this->m_pCharacters);

}

//���L�C���X�^���X�̎擾
CCharacterAggregate* CCharacterAggregate::getInstance() {

	if (CCharacterAggregate::m_pSareedAggregate == NULL) {
		CCharacterAggregate::m_pSareedAggregate = new CCharacterAggregate();
	}

	return CCharacterAggregate::m_pSareedAggregate;
}

//���L�C���X�^���X�̔j��
void CCharacterAggregate::removeInstance() {
	SAFE_DELETE(CCharacterAggregate::m_pSareedAggregate);
}

/**
 * @desc	�L�����^�N�[�̏W�܂�̎Q�Ƃ�ݒ�
 * @param	�ݒ肷��L�����N�^�[�̏W�܂�̃A�h���X
 */
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters) {
	//���ɐݒ肳��Ă�����ݒ肵�Ȃ��悤�ɂ��Ă���
	if (this->m_pCharacters != NULL)
		return;

	//�ݒ肳��Ă��Ȃ���Έ����̃L�����N�^�[�Q�̃A�h���X��o�^����
	this->m_pCharacters = pCharacters;
}

/**
 * @desc	�L�����^�N�[�̏W�܂�̂��擾
 * @return	�L�����N�^�[�̏W�܂�
 */
std::vector<CCharacter*>* CCharacterAggregate::get() {
	//�L�����N�^�[�Q�̃A�h���X��Ԃ�
	return this->m_pCharacters;
}

/**
 * @desc	�z��ԍ�����w�肵���L�����^�N�[�P�̂��擾
 * @param	�Y�����ԍ�
 * @return	�L�����N�^�[
 */
CCharacter* CCharacterAggregate::getAt(int index) {

	//�ő吔�ȏ�Ȃ�NULL��Ԃ��悤�ɐݒ肵�Ă���
	if (this->m_pCharacters->size() <= index) {
		return NULL;
	}

	//�ő吔�ȉ��Ȃ炻�̎w�肳�ꂽ�L�����N�^�[��Ԃ�
	return (*this->m_pCharacters)[index];
}

/**
 * @desc	�^�O����w�肵���L�����^�N�[�P�̂��擾
 * @param	�^�O
 * @return	�L�����N�^�[
 * @tips	���݂��Ȃ����NULL��Ԃ�
 */
CCharacter* CCharacterAggregate::getAtTag(int tag) {
	//�w�肳�ꂽ�^�O��ۗL����L�����N�^�[�����邩��������B
	for (CCharacter* pChara : (*this->m_pCharacters)) {
		//�����w�肳�ꂽ�L�����N�^�[������΂��̃L�����N�^�[��Ԃ�
		if (pChara->m_tag == tag) {
			return pChara;
		}
	}
	//���݂��Ȃ����NULL��Ԃ�
	return NULL;
}

/**
 * @desc	�L�����^�N�[�̒ǉ�
 * @param	�ǉ�����L�����N�^�[
 */
void CCharacterAggregate::add(CCharacter* pCharacter) {
	this->m_pCharacters->push_back(pCharacter);
}

/**
 * @desc	�L�����^�N�[�̏W�܂�̎��t�����Ă��鐔���擾
 * @param	���t�����Ă��鐔
 */
int CCharacterAggregate::getSize() {
	return (int)this->m_pCharacters->size();
}