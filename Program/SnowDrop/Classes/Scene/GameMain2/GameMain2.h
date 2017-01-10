/*
* GameMain.h
*
*	2016/11/10	Yamasaki
*
*/

#pragma once

//=========================================================================
//	�ǉ��̃C���N���[�h�͂�������
//=========================================================================
#include "Data/LaunchTrigger/LaunchTrigger.h"
#include "cocos2d.h"
#include "Constants.h"
#include <vector>

/*
*	�Q�[�����C�����C���[
*
*		�Q�[���̃��C���ƂȂ郌�C���[
*		���߂͂��̕����ɑS�Ă������Ă���
*
*/
class CGameMain2 : public cocos2d::CCLayerColor
{
public:
	//=========================================================================
	//	��������͗����o����܂ł͕ύX�֎~
	//=========================================================================

	// �f�X�g���N�^
	~CGameMain2();

	/**
	*	@desc	�V�[���̐���
	*	@return	CMain ���C���[�������V�[���N���X�C���X�^���X
	*	@tips	�ÓI�����o�֐�
	*/
	static cocos2d::Scene* createScene();

	/*
	*	@desc	�V�[���������ɏ������֐�������
	*			�������֐����s���� NULL ��Ԃ�
	*/
	CREATE_FUNC(CGameMain2);

	/**
	*	@desc	�L�[�{�[�h�̃L�[���������ۂ̃C�x���g
	*	@param	�L�[�R�[�h
	*	@param	�C�x���g
	*/
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;

	/**
	*	@desc	�L�[�{�[�h�̃L�[�𗣂����ۂ̃C�x���g
	*	@param	�L�[�R�[�h
	*	@param	�C�x���g
	*/
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) override;

	/**
	*	@desc	������
	*	@return	true...����	false...���s
	*/
	virtual bool init() override;

	/*
	* @desc ��ʃX�N���[��
	* @tips ����͋����X�N���[���ł͂Ȃ��L�����N�^�[�̈ړ��ɂ���ʂ̃X�N���[���ƂȂ�
	*/
	void scroll();

	/**
	*	@desc	�X�V����
	*	@param	�o�ߎ���
	*/
	virtual void update(float deltaTime_) override;

	/**
	* @desc		�^�C�g���ɑJ��
	* @param	�^�C�g�����C���[�̃C���X�^���X
	* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackChangeGameOver(cocos2d::Ref* pSender);

	//=========================================================================
	//	�����܂ł͗����o����܂ł͕ύX�֎~
	//=========================================================================

public:

	//=========================================================================
	//	�����o�錾
	//		�Q�[�����C�����Ŏg�p���郁���o�͂����ȍ~�ɋL�q���Ă���
	//=========================================================================

	//���C�����C���[
	LayerColor* m_pMainLayer = NULL;

	//UI���C���[
	LayerColor* m_pUILayer = NULL;

	//�L�����N�^�[�̏W�܂�
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//�o���X�P�W���[��
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	//�w�i
	cocos2d::Sprite* m_pBackGround = NULL;
	cocos2d::Sprite* m_pRoom = NULL;
	cocos2d::Sprite* m_pUI = NULL;

	// �M�~�b�N

	/**
	*	@desc	�`�F�b�N�Ǝ��O������ ( �P�� )
	*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[������O��
	*/
	template <typename Ty>
	void checkAndRemove(Ty* pChara) {

		if (pChara->m_activeFlag == false) {
			pChara->removeFromParent();
		}
	}

	/**
	*	@desc	�`�F�b�N�Ǝ��O������ ( ���� )
	*	@tips	�L���t���O�� false �̃C���X�^���X�����C���[�� std::vector ������O��
	*/
	template <typename Ty>
	void checkAndRemove(std::vector<Ty*>* pCharas) {

		// ���[�J���ϐ��̌^�̃e���v���[�g�����̎w��Ƃ���
		// �e���v���[�g�������w�肷��ꍇ�� typename �w������Ȃ���΂Ȃ�Ȃ�
		typename std::vector<Ty*>::iterator itr = pCharas->begin();
		while (itr != pCharas->end()) {

			if ((*itr)->m_activeFlag == false) {

				(*itr)->removeFromParent();
				itr = pCharas->erase(itr);

			}
			else {
				itr++;
			}
		}
	}

	/**
	*	@desc	�`�F�b�N�Ɖ�� ( ���� )
	*	@tips	�L���t���O�� false �̃C���X�^���X����������C���[�� std::vector ������O��
	*/
	template <typename Ty>
	void checkAndDelete(std::vector<Ty*>* pVector) {

		// ���[�J���ϐ��̌^�̃e���v���[�g�����̎w��Ƃ���
		// �e���v���[�g�������w�肷��ꍇ�� typename �w������Ȃ���΂Ȃ�Ȃ�
		typename std::vector<Ty*>::iterator itr = pVector->begin();
		while (itr != pVector->end()) {

			if ((*itr)->m_activeFlag == false) {
				SAFE_DELETE((*itr));
				itr = pVector->erase(itr);
			}
			else {
				itr++;
			}
		}
	}



};


