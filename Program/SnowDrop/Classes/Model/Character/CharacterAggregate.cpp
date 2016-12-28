//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "Model\Character\CharacterAggregate.h"

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
		//�e�̃��C���[������O��
		pChara->removeFromParent();
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

/**
* @desc �v���C���[�L�����N�^�[��ݒ�
*/
void CCharacterAggregate::setPlayer(CPlayerCharacterBoy* const pPlayer)
{
	this->m_pPlayer = pPlayer;
}

/**
* @desc	�K�[���L�����N�^�[���擾
*/
CPlayerCharacterBoy* CCharacterAggregate::getPlayer(void)
{
	return this->m_pPlayer;
}


/**
* @desc	�K�[���L�����N�^�[��ݒ�
*/
void CCharacterAggregate::setGirl(CPlayerCharacterGirl* const pGirl)
{
	this->m_pGirl = pGirl;
}

/**
* @desc	�K�[���L�����N�^�[���擾
*/
CPlayerCharacterGirl* CCharacterAggregate::getGirl(void)
{
	return this->m_pGirl;
}