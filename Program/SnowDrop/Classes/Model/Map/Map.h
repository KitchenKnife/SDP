/*
 * Map.h
 *
 *	2016/11/15	Osumi
 *
 */

#pragma once
//=========================================================================
//�@�ǉ��̃C���N���[�h�͂�������
//=========================================================================
#include <stdio.h>
#include "cocos2d.h"
#include"Constants.h"

class CEnemyLaunchData;
class CGimmickLaunchData;

//=========================================================================
//	�u���b�N�i�}�b�v�`�b�v�̎��j���
//		�V������ނ��o�����炱���ɑ��₵�Ă���
//=========================================================================
enum class BLOCK_TYPE :int {
	NONE			= 0,	//�����Ȃ�
	KURIBO = 101,
	MAIDEAD = 102,		//���C�h
	BAT = 103,		//�R�E����
	REDMAIDEAD = 104,		//�ԃN���{�[
	BLUEMAIDEAD = 105,

};

//=========================================================================
//	�G�̎��
//		�u���b�N�ԍ��Ɉˑ�
//=========================================================================
enum class ENEMY_TYPE :int {
	NONE		= 0,	//�����Ȃ�
	KURIBO		= 101,	//�ʏ�N���{�[
	MAIDEAD		= 102,	//���C�h
	BAT			= 103,	//�R�E����
	REDMAIDEAD	= 104,	//�ԃN���{�[
	BLUEMAIDEAD = 105,	//�N���{�[

};

//�M�~�b�N�̎��
enum class GIMMICK_TYPE :int {
	NONE = -1,
};

//=========================================================================
//	�}�b�v�N���X
//=========================================================================
class CMap :public cocos2d::TMXTiledMap {
public:
	//=========================================================================
	//	���C���[�^�C�v
	//=========================================================================
	enum class LAYER_TYPE :int {
		NOMAL			= 0,	//�ʏ�}�b�v
		LAUNCH_ENEMY	= 1,	//�G�o���p�}�b�v
		GIMMICK			= 2,    //�M�~�b�N�p�}�b�v

	};

	//=========================================================================
	//	�}�b�v�^�C�v�ɂ�郌�C���[�̖��O
	//=========================================================================
	std::vector<std::string>m_layerName{
		"normal",
		"launchenemy",
		"gimmick",
		"collision",
	};

public:

	//�R���X�g���N�^
	CMap(){
		
	}

	//����
	static CMap* create(const std::string& tmxFile) {
		CMap* pMap = new(std::nothrow)CMap();
		if (pMap->initWithTMXFile(tmxFile)) {
			pMap->autorelease();
			return pMap;
		}
		CC_SAFE_DELETE(pMap);
		return NULL;
	}

	/**
	 * @desc	�^�C����2�����z���̍��W���擾
	 * @param	���������_�Ƃ��Ĕz���̍��W�ʒu
	 */
	cocos2d::Point getTileCoord(cocos2d::Point pos);


	/**
	 * @desc	�^�C���ʒu�̎擾
	 * @param	���������_�Ƃ��đΏۂ̍��W�ʒu
	 */
	cocos2d::Point getTilePosition(cocos2d::Point pos);


	/**
	 * @desc	�I�u�W�F�N�g�ʒu�̎擾
	 * @param	���������_�Ƃ��đΏۂ̍��W�ʒu
	 * @author	Shinya Ueba
	 */
	//cocos2d::Point getObjectPosition(cocos2d::Point pos);

	/**
	 * @desc	�_�ƃ}�b�v�`�b�v�̏Փ˔���
	 * @param	�ΏۈʒuX
	 * @param	�ΏۈʒuY
	 */
	bool hitTest(float posX, float posY);

	/**
	 * @desc	�_�ƃI�u�W�F�N�g�̏Փ˔���
	 * @param	�ΏۈʒuX
	 * @param	�ΏۈʒuY
	 * @author	Shinya Ueba
	 */
	bool hitTestObject(float posX, float posY);

	/**
	 * @desc	�^�C���ԍ��m�F
	 * @param	2�����z���̈ʒuX
	 * @param	2�����z���̈ʒuY
	 * @param	���C���[�^�C�v
	 * @return	�u���b�N�̎��
	 * @tips	checkTile�Ƃ������O�ɂ��Ă�̂�
	 *  		enchant.js �ɂ̓f�t�H���g�Ń}�b�v�N���X��
	 *			checkTile�Ƃ����֐������݂����Ă���
	 *			�����@�\�������Ă���̂Ŗ��O�𓝈ꂵ�Ă���
	 */
	BLOCK_TYPE checkTile(float posX, float posY , LAYER_TYPE = LAYER_TYPE::NOMAL);
	

	/**
	 * @desc	�^�C���̕ύX
	 * @param	�ύX����}�b�v�`�b�vID(�^�C���ԍ��A�u���b�N�ԍ��A�}�b�v�`�b�v�ԍ�)
	 * @param	�_���Փ˂��Ă���^�C���A���̓_�̂����W
	 * @param	�_���Փ˂��Ă���^�C���A���̓_�̂����W
	 * @param	���C���[�^�C�v
	 * @return	true...����	
	 */
	bool changeTile(int mapChipID, float posX, float posY, LAYER_TYPE = LAYER_TYPE::NOMAL);


	/*
	 * @desc	���������̓G�o������
	 * @return	�G�̏o���f�[�^�Q
	 */
	void initCheckEnemyLaunch();

	/*
	 * @desc	�G�o������
	 * @param	���C�����C���[�̃A�h���X
	 */
	void checkEnemyLaunch(cocos2d::Point pt);

	//�G�o�����C���i�}�b�v2�����z���̃^�C���̂��ʒu�j
	//20�͉�ʒ[+1��
	int m_launchEnemyLine = WINDOW_RIGHT/TILE_SIZE;

	/*
	 * @desc	�G�o����̓G�o�����C���[�̃^�C���̍폜
	 * @param	�G�o���f�[�^
	 */
	void removeLaunchEnemy(CEnemyLaunchData* pLaunchData);

	/*
	 * @desc	�M�~�b�N�o������
	 * @param	���C�����C���[�̃A�h���X
	 */
	void checkGimmickLaunch(cocos2d::Point pt);

	//�G�o�����C���i�}�b�v2�����z���̃^�C���̂��ʒu�j
	//20�͉�ʒ[+1��
	int m_launchGimmickLine = 20;

	/*
	 * @desc	�M�~�b�N�o����̃M�~�b�N�o�����C���[�̃^�C���̍폜
	 * @param	�M�~�b�N�o���f�[�^
	 */
	void removeLaunchGimmick(CGimmickLaunchData* pLaunchData);
};

//=========================================================================
//	�}�b�v�Ǘ��N���X
//=========================================================================
class CMapManager {
private:
	//=========================================================================
	//	�V���O���g���ݒ�
	//=========================================================================

	//�R���X�g���N�^
	CMapManager();
	CMapManager(const CMapManager& customMapMgr);

	//���L�C���X�^���X
	static CMapManager* m_pSharedMapManager;

public:
	//���L�C���X�^���X�̎擾
	static CMapManager* getInstance();

	//�j��
	static void removeInstance();
	//�f�X�g���N�^
	~CMapManager();

private:
	//�}�b�v
	CMap* m_pMap = NULL;

public:
	//�}�b�v����
	CMap* createMap(const std::string& fileName_);

	//�}�b�v�擾
	CMap* getMap();

};



