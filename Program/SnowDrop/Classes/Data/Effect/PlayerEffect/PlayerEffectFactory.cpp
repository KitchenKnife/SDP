/*
* PlayerEffectFactory.h
*
*	2016/11/25	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Data/Effect/PlayerEffect/PlayerEffectFactory.h"

//================================================
// �G�t�F�N�g�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================

CMove* CPlayerEffactPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}
/*
CAnimation* CPlayerEffactPartsFactory::getAnimation() {

	//�A�j���[�V�����f�[�^�̍쐬
	CAnimation* pAnimation = new CChipListAnimation();

	return pAnimation;
}
*/


//================================================
// �G�t�F�N�g�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̐����Ƒg�ݗ���
CPlayerEffect* CDisappearEffectCreateFactory::createEffect() {

	CPlayerEffect* pEffect = CBoyDisappearEffect::create();

	//�ړ��p�f�[�^�̎擾
	pEffect->m_pMove = this->partsFactories[(int)CPlayerCharacter::EFFECT::DISAPPEAR]->getMove();

	return pEffect;
}

//================================================
// �G�t�F�N�g�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================

//�e�X�̃p�[�c�̃Z�b�e�B���O
void CDisappearEffectFactory::settingMove(CPlayerEffect* pEffct, cocos2d::Point pt) {

	//�����ʒu�̐ݒ�
	pEffct->m_pMove->m_pos.set(pt.x, pt.y);

	//�������x�̐ݒ�
	pEffct->m_pMove->setVel(0.0f, 3.0f);

}
void CDisappearEffectFactory::settingTexture(CPlayerEffect* pEffct) {
	//�e�N�X�`���̐ݒ�
	pEffct->setTexture(IMAGE_DIAPPEAR_EFFECT);

}

void CDisappearEffectFactory::settingAnimations(CPlayerEffect* pEffct) {

	//�����A�j���[�V�����̐ݒ�
	pEffct->m_pAnimationDatas = (new CChipListAnimation(10, false));

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	//1����
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 0, 256 * 1, 96, 96));
	//2����
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 1, 256 * 1, 96, 96));
	//3����
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 2, 256 * 1, 96, 96));
	//4����
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 3, 256 * 1, 96, 96));

}


void CDisappearEffectFactory::settingInitialize(CPlayerEffect* pEffct) {

	//�L���t���O�𗧂Ă�
	pEffct->m_activeFlag = true;

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pEffct->applyFunc();
}


//================================================
// �p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CPlayerEffectFactoryManager* CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager = NULL;

//�C���X�^���X�̎擾
CPlayerEffectFactoryManager* CPlayerEffectFactoryManager::getInstance() {

	if (CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager == NULL) {
		CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager = new CPlayerEffectFactoryManager();
	}

	return CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager;
}
