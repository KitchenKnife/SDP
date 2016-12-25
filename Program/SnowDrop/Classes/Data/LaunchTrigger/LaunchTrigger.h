#pragma once

#include <stdio.h>
#include <memory>
#include "cocos2d.h"
#include "Constants.h"
#include "Data/LaunchData/LaunchData.h"

//=======================================
//  �O���錾
//=======================================
class CCharacter;

//=======================================
//
//  �o���g���K�[
//
//=======================================
class CLaunchTrigger {

public:
	//�L���t���O�@false...�o���X�P�W���[��������O��
	bool m_activeFlag = false;

	//�R���X�g���N�^
	CLaunchTrigger() {
		this->m_activeFlag = true;
	}

	//�f�X�g���N�^
	virtual ~CLaunchTrigger() {}

	/**
	 * @desc	���˂��I��������ǂ���
	 * @retrun	true...���˂����@false...���˂��Ă��Ȃ�
	 * @tips	���˂��I��������ǂ����͔h���N���X�ɂ����
	 *			�t���O���ω�����ꍇ�����݂���
	 */
	virtual bool isLaunched() {
		return this->m_activeFlag;
	}

	/**
	 * @desc	�ݒ肳��Ă���g���K�[���C�x���g���s���邩�ǂ���
	 * @retrun	true...�C�x���g���s���\
	 * @tips	�C�x���g�̎��s�\�����͔h���N���X�ɂ���ĕω�����
	 */
	virtual bool isTrigger() = 0;

	/**
	 * @desc	�g���K�[�C�x���g�̎��s
	 * @tips	�����ł̃g���K�[�C�x���g�̓L�����N�^�[�̐���
	 */
	virtual CCharacter* action() = 0;

};

//=======================================
//
//  �G�o���g���K�[
//		�G�o���f�[�^���g���K�[�Ƃ��ēG�o���Ƃ����C�x���g�����s������
//
//=======================================
class CEnemyLaunchTrigger :public CLaunchTrigger{
private:
	//�G�o���f�[�^
	CEnemyLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	�R���X�g���N�^
	 * @param	�G�o���f�[�^
	 * @tips	�G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
	 */
	CEnemyLaunchTrigger(CEnemyLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//�f�X�g���N�^
	virtual ~CEnemyLaunchTrigger();

	/**
	 * @desc	�C�x���g���s���邩�ǂ���
	 * @retrun	true...�C�x���g���s��
	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
	 * @tups	�g���K�[�����ɃC�x���g�����s
	 */
	virtual CCharacter* action()override;

};

//=======================================
//
//  �M�~�b�N�����g���K�[
//
//=======================================
class CGimmickLaunchTrigger :public CLaunchTrigger {
private:
	//�e�o���f�[�^
	CGimmickLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	�R���X�g���N�^
	 * @param	�G�o���f�[�^
	 * @tips	�G�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
	 */
	CGimmickLaunchTrigger(CGimmickLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//�f�X�g���N�^
	virtual ~CGimmickLaunchTrigger();

	/**
	 * @desc	�C�x���g���s���邩�ǂ���
	 * @retrun	true...�C�x���g���s��
 	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
	 * @tips	�g���K�[�����ɃC�x���g�����s
	 */
	virtual CCharacter* action()override;

};


//=======================================
//
//  �G�t�F�N�g�����g���K�[
//
//=======================================
class CEffectLaunchTrigger :public CLaunchTrigger {
private:
	//�G�t�F�N�g�o���f�[�^
	CEffectLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	�R���X�g���N�^
	 * @param	�G�t�F�N�g�o���f�[�^
	 * @tips	�G�t�F�N�g�o���f�[�^���g���K�[�Ƃ��Đݒ肷��
	 */
	CEffectLaunchTrigger(CEffectLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//�f�X�g���N�^
	virtual ~CEffectLaunchTrigger();

	/**
	 * @desc	�C�x���g���s���邩�ǂ���
	 * @retrun	true...�C�x���g���s��
	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	�ݒ肳��Ă���G�o���f�[�^�����ɓG�𐶐�����
	 * @tips	�g���K�[�����ɃC�x���g�����s
	 */
	virtual CCharacter* action()override;

};

//=======================================
//
//  ���ˑ�
//		�o���X�P�W���[���̎Q�Ƃ�ݒ肵��
//		�o���X�P�W���[���Ɏ��t�����Ă���o���g���K�[�̏��Ԓʂ��
//		�C�x���g�����s���Ă����B
//		�܂���t����ꂽ���Ԓʂ�ɏo�����s�Ȃ��Ă����B
//
//		Aggregate
//
//=======================================
class CLauncher {
public:
	//�o���X�P�W���[���̎Q�Ɓi�܂肱�̃N���X�Ő�����j�����s��Ȃ��j
	//1�t���[���ɏo��������g���K�[�C�x���g�̏W�܂�
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	/**
	 * @desc	�R���X�g���N�^
	 * @param	�o���X�P�W���[���̃A�h���X
	 */
	CLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule)
		:m_pLaunchSchedule(pLaunchSchedule){}

	//�f�X�g���N�^
	~CLauncher(){}

	/**
	 * @desc	�g���K�[�̒ǉ�
	 * @param	�ǉ�����g���K�[
	 */
	void add(CLaunchTrigger* pLaunchTrigger) {
		this->m_pLaunchSchedule->push_back(pLaunchTrigger);
	}

	/**
	 * @desc	�o���X�P�W���[���̃T�C�Y���擾
	 * @return	���t�����Ă��鐔
	 */
	int getSize() {
		return (int)this->m_pLaunchSchedule->size();
	}

	/**
	 * @desc	�L�����^�N�[�P�̂��擾
	 * @param	�Y�����ԍ�
	 * @return	�L�����N�^�[
	 */
	CLaunchTrigger* getAt(int index) {
		//�ő吔�ȏ�Ȃ�NULL��Ԃ��悤�ɐݒ肵�Ă���
		if (this->getSize() <= index) {
			return NULL;
		}

		return (*this->m_pLaunchSchedule)[index];
	}


	//=======================================
	//
	//  �o���g���K�[�C�e���[�^�[
	//		���ˑ�Ɏ��t�����Ă���g���K�[�𔭎ˉ\������ׂāA
	//		���ˉ\�Ȃ�1���o�������邽�߂̃N���X
	//		Aggregate�̒��Ɏ���
	//
	//		Iterator
	//
	//=======================================
	class CLaunchTriggerIterator {
	public:
		//���ˑ�
		CLauncher* m_pLaucher = NULL;

		//���ݎQ�ƒ��̔ԍ�
		int m_triggerCount = 0;

		//�R���X�g���N�^
		CLaunchTriggerIterator(CLauncher* pLaucher) 
			:m_pLaucher(pLaucher){}


		/**
		 * @desc	���̏o�������邩�ǂ������ׂ�
		 * @tips	�������͏o���g���K�[���N���\���ǂ������ׂ�
		 */
		bool hasNext(){
		
			//�g���K�[�C�x���g�̏W�܂�̃T�C�Y�𒲂ׂ�
			if (this->m_pLaucher->getSize() <= this->m_triggerCount) {
				return false;
			}

			//�o���g���K�[���N���\���ǂ����𒲂ׂ�
			if (this->m_pLaucher->getAt(this->m_triggerCount)->isTrigger() == false) {
				//�N���łȂ��ꍇ�͓Y�����ԍ������ɐi�߂�
				this->m_triggerCount++;
				//�����`�F�b�N
				return this->hasNext();
			}
		
			return true;
		}

		/**
		 * @desc	���݂̏o���g���K�[���擾���Y�����ԍ������ɐi�߂�
		 */
		CLaunchTrigger* next() {

			CLaunchTrigger* pTrigger = this->m_pLaucher->getAt(this->m_triggerCount);
				this->m_triggerCount++;
				return pTrigger;
		}
	};

	/**
	 * @desc	�o���g���K�[�C�e���[�^�[�̐���
	 * @param	�o���g���K�[�C�e���[�^�[
	 */
	std::shared_ptr<CLaunchTriggerIterator> iterator() {
		return std::shared_ptr<CLaunchTriggerIterator>(new CLaunchTriggerIterator(this));
	}

};

//=======================================
//
//  �o���X�P�W���[���[
//	Singleton
//
//=======================================
class CLaunchScheduler {

	//===========================================================
	//�@��������̒񋟂́@�V���O���g���@�i���j�ł�
	//===========================================================
private:
	//���L�C���X�^���X
	static CLaunchScheduler* m_pSharedScheduler;

	//�R���X�g���N�^
	CLaunchScheduler();

public:
	//���L�C���X�^���X�̎擾
	static CLaunchScheduler* getInstance();

	//���@���C���X�^���X�̔j��
	static void removeInstance();

	//�f�X�g���N�^
	~CLaunchScheduler();

	//===========================================================
	//�@�����܂ł̒񋟂́@�V���O���g���@�i���j�̂ł���
	//===========================================================
	
public:
	//���ˑ�
	CLauncher* m_pLauncher = NULL;

	/**
	 * @desc	���ˑ�̐���
	 * @param	���ˑ�ɐݒ肷��o���X�P�W���[���̃A�h���X
	 */
	void createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule);

	/**
	 * @desc	�L�����N�^�[�̏o��
	 * @param	���t���郌�C���[
	 */
	void launchCharacter(cocos2d::Layer* pLayer);

};

