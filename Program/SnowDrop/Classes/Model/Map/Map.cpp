
/*
* Map.cpp
*
*	2016/11/13	Osumi
*
*/

#include "Map.h"
#include "Constants.h"
#include "Data/Collision/Collision.h"
#include "Data/LaunchData/LaunchData.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

using namespace cocos2d;

//=========================================================================
//	�}�b�v�N���X
//=========================================================================
/**
* @desc	�^�C����2�����z���̍��W���擾
* @param �Ώۈʒu
*/
Point CMap::getTileCoord(Point pos) {

	//�}�b�v�̌��_�ʒu
	Point pt = this->getPosition();

	//�}�b�v�^�C���T�C�Y
	Size tileSize = this->getTileSize();

	//�}�b�v�̔z��T�C�Y
	Size mapSize = this->getMapSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = ((mapSize.height*tileSize.height) - pos.y) / tileSize.height;

	//���㌴�_�̏ꍇ
	//int y =(pos_.y + this->getPosition().y)/this->getTileSize().height;

	return Point(x,y);
}

/**
* @desc		�^�C���ʒu�̎擾
* @param	�Ώۈʒu
*/
Point CMap::getTilePosition(cocos2d::Point pos) {

	//�}�b�v�̌��_�ʒu
	Point pt = this->getPosition();

	//�}�b�v�^�C���T�C�Y
	Size tileSize = this->getTileSize();

	int x = (pos.x + pt.x)/tileSize.width;
	int y = (pos.y + pt.y) /tileSize.height;

	return Point(x*tileSize.width, y*tileSize.height);

}


/**
* @desc	�_�ƃ}�b�v�`�b�v�̏Փ˔���
* @param �ΏۈʒuX
* @param �ΏۈʒuY
*/
bool CMap::hitTest(float posX, float posY) {

	//�Ώۂ̏Փ˔���̓_
	CCollisionPoint cpt(Point(posX, posY));

	//�_�ƏՓ˂��Ă���}�b�v�`�b�v�̌��_�i�����̓_�j���擾
	Point basePoint = this->getTilePosition(Point(posX, posY));

	//�}�b�v�`�b�v�̈ʒu�i�}�b�v�`�b�v�̒��S�ʒu�j
	Point tilePos = Point(basePoint.x + 16.0f, basePoint.y + 16.0f);

	//(-16,16,16,-16)
	CCollisionRect crect(CBody(-16, 16, 16, -16),tilePos);

	//collision���g�p���Ĕ���
	return cpt.collision(&crect);

}

/**
* @desc	�_�ƃI�u�W�F�N�g�̏Փ˔���
* @param �ΏۈʒuX
* @param �ΏۈʒuY
* @author Shinya Ueba
*/
bool CMap::hitTestObject(float posX, float posY)
{
	//�Ώۂ̏Փ˔���̓_
	CCollisionPoint cpt(Point(posX, posY));

	cocos2d::CCTMXObjectGroup* pointerTiledMapObjectGroup = this->getObjectGroup(this->m_layerName[3]);
	if (!pointerTiledMapObjectGroup)
	{
		return false;
	}

	auto arrayAutoObjects = pointerTiledMapObjectGroup->getObjects();

	for (auto autoObject : arrayAutoObjects)
	{
		// object�ɐݒ肳��Ă���v���p�e�B�Ȃǂ��擾
		cocos2d::ValueMap valueMapObjectInfomation = autoObject.asValueMap();

		cocos2d::Vec2 vec2MapPosition = this->getPosition();
		cocos2d::Vec2 vec2ObjectPosition;
		vec2ObjectPosition.x = valueMapObjectInfomation["x"].asFloat() + vec2MapPosition.x + this->getTileSize().width * 0.5f;
		vec2ObjectPosition.y = valueMapObjectInfomation["y"].asFloat() + vec2MapPosition.y + this->getTileSize().height * 0.5f;
		
		CCollisionRect crectObject(CBody(	valueMapObjectInfomation["width"].asFloat() * -0.5,
									valueMapObjectInfomation["height"].asFloat() * 0.5,
									valueMapObjectInfomation["width"].asFloat() * 0.5,
									valueMapObjectInfomation["height"].asFloat() * -0.5),
									vec2ObjectPosition);
		
		cocos2d::log("X:%f,Y%f", vec2ObjectPosition.x, vec2ObjectPosition.y);

		//collision���g�p���Ĕ���
		if (cpt.collision(&crectObject))
		{
			
			return true;
		}
	}
	return false;
}


/**
* @desc		�^�C���ԍ��m�F
* @param	�_���Փ˂��Ă���^�C���A���̓_�̂����W
* @param	�_���Փ˂��Ă���^�C���A���̓_�̂����W
* @param	���C���[�^�C�v
* @return	�u���b�N�̃^�C�v
*/
BLOCK_TYPE CMap::checkTile(float posX, float posY, LAYER_TYPE layerType) {

	//���C���[���擾
	TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//�^�C����2�����z���̍��W���擾
	Point tileCoord = this->getTileCoord(Point( posX, posY));

	//�}�b�v�̔z��T�C�Y
	Size mapSize = this->getMapSize();

	//�^�C����2�����z���̍��W��0�����A�܂��̓}�b�v�T�C�Y���傫���ꍇ
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false) {

		return BLOCK_TYPE::NONE;
	}

	//�}�b�v�f�[�^�̎擾
	return (BLOCK_TYPE)pLayer->getTileGIDAt(tileCoord);

}

/**
* @desc	�^�C���̕ύX
* @param  �ύX����}�b�v�`�b�vID
* @param  �_���Փ˂��Ă���^�C���A���̓_�̂����W
* @param  �_���Փ˂��Ă���^�C���A���̓_�̂����W
* @param	���C���[�^�C�v
* @return true...����
*/
bool CMap::changeTile(int mapChipID, float posX, float posY, LAYER_TYPE layerType) {

	//���C���[���擾
	TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//�^�C����2�����z���̍��W���擾
	Point tileCoord = this->getTileCoord(Point(posX, posY));

	//�}�b�v�̔z��T�C�Y
	Size mapSize = this->getMapSize();

	//////
	//�^�C����2�����z���̍��W��0�����A�܂��̓}�b�v�T�C�Y���傫���ꍇ
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false) {

		return false;
	}

	//�}�b�v�`�b�v�f�[�^�̔��f
	pLayer->setTileGID(mapChipID,tileCoord);

	return true;

}

/*
* @desc	���������̓G�o������
* @return	�G�̃^�C�v
*/
void CMap::initCheckEnemyLaunch() {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//�}�b�v�`�b�v�̃T�C�Y���擾�i32,32�j
	Size tileSize = pMap->getTileSize();

	//�G�̏o���f�[�^�Q
	std::vector<CEnemyLaunchData*>* pLaunchDatas = new std::vector<CEnemyLaunchData*>;

	//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
	for (float chackPosX = tileSize.width * 0.5f; chackPosX< WINDOW_RIGHT; chackPosX += tileSize.width){
	//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
		for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height) {

			//�`�F�b�N����^�C���̍��W��ݒ�ix�͌Œ��y���W���`�F�b�N���Ă����j
			Point tilePos(chackPosX, y);

			//����x���W��2�����z���̂��ʒu�ɂ���S�Ẵ^�C�����擾
			//���̃^�C���̃^�C���^�C�v�i���G�^�C�v�j���擾
			ENEMY_TYPE eneType = (ENEMY_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//�G�̃^�C�v��NONE����Ȃ�������o��
			if (eneType != ENEMY_TYPE::NONE) {

				//�G�o���f�[�^���쐬
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(eneType, tilePos);

				//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
				CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

				//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//�G�o���^�C���̍폜
				CMapManager::getInstance()->getMap()->removeLaunchEnemy(pLaunchData);
				
			}
		}
	}
	
	
}


/*
* @desc	�G�o������
* @param	���C�����C���[�̈ʒu
* @return	�G�̃^�C�v
*/
void CMap::checkEnemyLaunch(cocos2d::Point pt) {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//���C���[�̂��ʒu�ɉ�ʂ̉E�T�C�Y���𑫂����Ƃ�
	//�\������Ă����ʂ̉E�[�̈ʒu���擾�ł���
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//�}�b�v�`�b�v�̃T�C�Y���擾�i32,32�j
	Size tileSize = pMap->getTileSize();

	//�^�C����2�����z���̍��W���擾�i�����W�݂̂��`�F�b�N�j
	Point tileCoord = pMap->getTileCoord(Point(checkPosX, 0.0f));

	//���ݎQ�ƒ��̓G�o�����C��
	if (m_launchEnemyLine == tileCoord.x) {

		//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
		for (float y = tileSize.height * 0.5f; y< WINDOW_TOP; y+=tileSize.height) {

			//�`�F�b�N����^�C���̍��W��ݒ�ix�͌Œ��y���W���`�F�b�N���Ă����j
			Point tilePos(checkPosX, y);

			//����x���W��2�����z���̂��ʒu�ɂ���S�Ẵ^�C�����擾
			//���̃^�C���̃^�C���^�C�v�i���G�^�C�v�j���擾
			ENEMY_TYPE eneType = (ENEMY_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//�G�̃^�C�v��NONE����Ȃ�������o��
			if (eneType != ENEMY_TYPE::NONE) {

				//�G�o���f�[�^���쐬
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(eneType, tilePos);

				//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
				CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

				//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//�G�o���^�C���̍폜
				CMapManager::getInstance()->getMap()->removeLaunchEnemy(pLaunchData);
				
			}

		}
		//�G�o�����C���̍X�V
		m_launchEnemyLine++;
	}
}


/*
* @desc	�G�o����̓G�o�����C���[�̃^�C���̍폜
* @param	�G�o���f�[�^
*/
void CMap::removeLaunchEnemy(CEnemyLaunchData* pLaunchData) {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//�o�������ꏊ�̓G�o�����C���[�̃}�b�v�`�b�v�^�C�v��ENEMY::NONE�ɂ���
	pMap->changeTile(
		(int)ENEMY_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_ENEMY
	);

}


/*
* @desc	�M�~�b�N�o������
* @param	���C�����C���[�̃A�h���X
*/
void CMap::checkGimmickLaunch(cocos2d::Point pt) {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//���C���[�̂��ʒu�ɉ�ʂ̉E�T�C�Y���𑫂����Ƃ�
	//�\������Ă����ʂ̉E�[�̈ʒu���擾�ł���
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//�}�b�v�`�b�v�̃T�C�Y���擾�i32,32�j
	Size tileSize = pMap->getTileSize();

	//�^�C����2�����z���̍��W���擾�i�����W�݂̂��`�F�b�N�j
	Point tileCoord = pMap->getTileCoord(Point(checkPosX, 0.0f));

	//���ݎQ�ƒ��̓G�o�����C��
	if (this->m_launchGimmickLine == tileCoord.x) {

		//�����珇�Ƀ^�C���T�C�Y���Â^�C�����`�F�b�N���Ă���
		for (float y = tileSize.height*0.5f; y < WINDOW_TOP; y += tileSize.height) {

			//�`�F�b�N����^�C���̍��W��ݒ�ix�͌Œ��y���W���`�F�b�N���Ă����j
			Point tilePos(checkPosX, y);

			//����x���W��2�����z���̂��ʒu�ɂ���S�Ẵ^�C�����擾
			//���̃^�C���̃^�C���^�C�v�i���G�^�C�v�j���擾
			GIMMICK_TYPE gimType = (GIMMICK_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::GIMMICK);

			//�G�̃^�C�v��NONE����Ȃ�������o��
			if (gimType != GIMMICK_TYPE::NONE) {

				//�G�o���f�[�^���쐬
				CGimmickLaunchData* pLaunchData = new CGimmickLaunchData(gimType, tilePos);

				//�o���g���K�[�𐶐����A�G�o���f�[�^��ݒ�
				CGimmickLaunchTrigger* pTrigger = new CGimmickLaunchTrigger(pLaunchData);

				//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//�G�o���^�C���̍폜
				CMapManager::getInstance()->getMap()->removeLaunchGimmick(pLaunchData);

			}

		}
		//�G�o�����C���̍X�V
		this->m_launchGimmickLine++;
	}
}

/*
* @desc	�M�~�b�N�o����̃M�~�b�N�o�����C���[�̃^�C���̍폜
* @param	�M�~�b�N�o���f�[�^
*/
void CMap::removeLaunchGimmick(CGimmickLaunchData* pLaunchData) {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//�o�������ꏊ�̓G�o�����C���[�̃}�b�v�`�b�v�^�C�v��ENEMY::NONE�ɂ���
	pMap->changeTile(
		(int)GIMMICK_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::GIMMICK
	);
}

//=========================================================================
//	�}�b�v�Ǘ��N���X
//=========================================================================
//���L�C���X�^���X�{��
CMapManager*  CMapManager::m_pSharedMapManager = NULL;

//�R���X�g���N�^
CMapManager::CMapManager(){}
CMapManager::CMapManager(const CMapManager& customMapMgr) {

}

//���L�C���X�^���X�̎擾
CMapManager* CMapManager::getInstance(){
	if (CMapManager::m_pSharedMapManager == NULL) {
		CMapManager::m_pSharedMapManager = new CMapManager();
	}
	return CMapManager::m_pSharedMapManager;
}


//�f�X�g���N�^
CMapManager::~CMapManager(){}

//�j��
void CMapManager::removeInstance() {
	if (CMapManager::m_pSharedMapManager != NULL) {
		SAFE_DELETE(CMapManager::m_pSharedMapManager);
	}
}
	

//�}�b�v����
CMap* CMapManager::createMap(const std::string& fileName_) {

	//�}�b�v�N���X�̐���
	this->m_pMap = CMap::create(fileName_);

	if (this->m_pMap == NULL) {
		CCLOG("�}�b�v�̐����Ɏ��s���܂����I�I�I");
		return NULL;
	}

	//�����ݒ�̈ʒu
	this->m_pMap->setPosition(0.0f, 0.0f);


	//���t�����Ă邷�ׂẴ^�C���̃G�C���A�X�̃f�t�H���g���A���`�G�C���A�X�ɐݒ�
	//������h�~
	for (const auto& child:this->m_pMap->getChildren()) {
		static_cast<cocos2d::SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
	}


	return this->m_pMap;
}

//�}�b�v�̎擾
CMap* CMapManager::getMap() {
	return this->m_pMap;
}
