
#include "Data/Effect/Effect.h"

/*
 * Effect.cpp
 *
 *	2016/11/25	Osumi
 *
 */

//================================================
// 
// �G�t�F�N�g�̊��N���X
//
//	2016/12/22
//									Author Harada
//
//================================================
//�R���X�g���N�^
CEffect::CEffect(){}

//�f�X�g���N�^
CEffect::~CEffect() {
	//
	SAFE_DELETE(this->m_pAnimations);

	SAFE_DELETE(this->m_pMove);
}
//����������
bool CEffect::init(){

	if (Sprite::init() == false) {
		CCLOG("�X�v���C�g�N���X�̏������Ɏ��s");
		return false;
	}

	//�G�t�F�N�g�̍X�V�����͓Ǝ��ōs���悤�ɂ���B
	this->scheduleUpdate();

	return true;
}

//�X�V����
void CEffect::update(float delta) {

	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//���f����
	this->applyFunc();
}

/**
 * @desc	�ړ�����
 * @tips	��������ȓ��������������ꍇ�͂��̃N���X���p������
 *			�I�[�o�[���C�h������
 */
void CEffect::moveFunc() {
	//�����Ȃ��B
}

//�A�j���[�V��������
void CEffect::animationFunc() {

	//�A�j���[�V�����X�V
	this->m_pAnimations->update();

	//�A�j���[�V�����̏I���t���O���m�F
	if (this->m_pAnimations->isEnd()) {
		//�I�����Ă���΃A�N�e�B�u�t���O�� false �ɕύX
		this->m_activeFlag = false;
	}
}

//���f����
void CEffect::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect(this->m_pAnimations->getCurrentChip());

}



//=============================================
// �G�t�F�N�g�W����
//=============================================
//���L�C���X�^���X�̖{��
CEffectAggregate* CEffectAggregate::m_pSareedAggregate = NULL;

//�R���X�g���N�^
CEffectAggregate::CEffectAggregate() {}

//�f�X�g���N�^
CEffectAggregate::~CEffectAggregate() {}

//���L�C���X�^���X�̎擾
CEffectAggregate* CEffectAggregate::getInstance() {

	if (CEffectAggregate::m_pSareedAggregate == NULL) {
		CEffectAggregate::m_pSareedAggregate = new CEffectAggregate();
	}

	return CEffectAggregate::m_pSareedAggregate;
}

//���L�C���X�^���X�̔j��
void CEffectAggregate::removeInstance() {
	SAFE_DELETE(CEffectAggregate::m_pSareedAggregate);
}

/**
 * @desc	�G�t�F�N�g�̏W�܂�̎Q�Ƃ�ݒ� 
 * @param	�ݒ肷��G�t�F�N�g�̏W�܂�̃A�h���X
 */
void CEffectAggregate::set(std::vector<CEffect*>* pCharacters) {
	//���ɐݒ肳��Ă�����ݒ肵�Ȃ��悤�ɂ��Ă���
	if (this->m_pEffects != NULL)
		return;

	//�ݒ肳��Ă��Ȃ���Έ����̃G�t�F�N�g�Q�̃A�h���X��o�^����
	this->m_pEffects = pCharacters;
}

/**
 * @desc	�G�t�F�N�g�̏W�܂�̂��擾
 * @return	�G�t�F�N�g�̏W�܂�
 */
std::vector<CEffect*>* CEffectAggregate::get() {
	//�G�t�F�N�g�Q�̃A�h���X��Ԃ�
	return this->m_pEffects;
}

/**
 * @desc	�z��ԍ�����w�肵���G�t�F�N�g�P���擾
 * @param	�Y�����ԍ�
 * @return	�G�t�F�N�g
 */
CEffect* CEffectAggregate::getAt(int index) {

	//�ő吔�ȏ�Ȃ�NULL��Ԃ��悤�ɐݒ肵�Ă���
	if (this->m_pEffects->size() <= index) {
		return NULL;
	}

	//�ő吔�ȉ��Ȃ炻�̎w�肳�ꂽ�G�t�F�N�g��Ԃ�
	return (*this->m_pEffects)[index];
}

/**
 * @desc	�G�t�F�N�g�̒ǉ�
 * @param	�ǉ�����G�t�F�N�g
 */
void CEffectAggregate::add(CEffect* pEffe) {
	this->m_pEffects->push_back(pEffe);
}

/**
 * @desc	�G�t�F�N�g�̏W�܂�̎��t�����Ă��鐔���擾
 * @param	���t�����Ă��鐔
 */
int CEffectAggregate::getSize() {
	return (int)this->m_pEffects->size();
}