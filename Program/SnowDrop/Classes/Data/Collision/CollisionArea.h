#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "cocos2d.h"
#include "Constants.h"
#include "Collision.h"

//=====================================
// �O���錾
//=====================================
class CCharacter;

//=====================================
// �̈�^�C�v
//=====================================
enum class TERRITORY_TYPE :int {
	LEFT,
	TOP,
	RIGHT,
	BOTTOM,
};

//=====================================
// �Փˊ�_
//=====================================
class CCollisionBasePoint {
public:
	//�̈�^�C�v
	TERRITORY_TYPE m_type;
	//��_
	cocos2d::Point m_pt;

	//�R���X�g���N�^
	CCollisionBasePoint(TERRITORY_TYPE type, cocos2d::Point pt) 
		:m_type(type), m_pt(pt){}
};

//=====================================
//
// �Փ˔���̈�
//
//=====================================
class CCollisionTerritory {
public:
	//�̈�^�C�v
	TERRITORY_TYPE m_type;

	//�R���X�g���N�^
	CCollisionTerritory(TERRITORY_TYPE type):m_type(type) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritory() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt) = 0;

public:
	//�C�x���g�R�[���o�b�N
	//void (CCharacter::*�^��)�iint event�jtypedef
	//typedef���N���X���ɋL�q���邱�Ƃ�
	//�N���X�����ɗL����typedef�ƂȂ�
	typedef void(CCharacter::*EventCallback)(int event);

	//�����Ł@*EventCallback�@�́@�߂�l��void�A������int�@�̊֐��̃A�h���X���i�[�ł���֐��|�C���^���Ӗ�����B
	//�����́@�ϐ�event�́@����C�x���g�̃R�[���o�b�N�Ƃ������Ƃ��킩��₷�����邽�߂̒P�Ȃ閼�O�Ȃ̂Ł@event���̂ɈӖ��͂Ȃ�

protected:
	//�C�x���g�R�[���o�b�N
	EventCallback m_pEventCallBack = NULL;
public:
	/**
	 * @desc	�C�x���g�R�[���o�b�N�̐ݒ�
	 * @param	�ݒ肷��R�[���o�b�N�C�x���g
	 * @tips	�̈�𐶐����A���������̈��
	 *�@�@�@	�C�x���g�R�[���o�b�N�i�����o�֐��|�C���^�j��ݒ肷�邱�ƂŁ@
	 *�@�@�@�@	���̗̈�C�x���g�����������Ƃ���
	 *�@�@�@�@	�o�^���������o�֐��|�C���^���Ăяo�����
	 */
	void setEventCallback(EventCallback pEventCallback) {
		this->m_pEventCallBack = pEventCallback;
	}

	/**
	 * @desc	�C�x���g�R�[���o�b�N�̌Ăяo��
	 * @param	�Ăт����C���X�^���X
	 * @param	�C�x���g
	 *�@�@�@	�}�b�v�����Ղ̍ۂ̓}�b�v�`�b�vID���C�x���g�Ƃ��ēn����
	 *�@�@�@	��ʒ[�Ȃǂ̓C�x���g�͑��݂��Ȃ��̂�
	 *�@�@�@	�f�t�H���g�l�Ƃ���0��ݒ肵�Ă���
	 * @tips	�̈�̃C�x���g�̔������ɂ��̃����o�֐����Ăяo�����Ƃ�
	 *�@�@�@	�o�^���������o�֐����Ăяo�����@
	 */
	void callEventCallback(CCharacter* pChara, int event = 0);

};

//=====================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryEndOfScreenBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryEndOfScreenBottom():CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryEndOfScreenBottom() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;

};
//=====================================
// ��ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryEndOfScreenTop :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryEndOfScreenTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryEndOfScreenTop() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// �E�ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryEndOfScreenRight :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryEndOfScreenRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryEndOfScreenRight() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryEndOfScreenLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryEndOfScreenLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryEndOfScreenLeft() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//=====================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryOutOfScreenBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryOutOfScreenBottom() :CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryOutOfScreenBottom() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;

};
//=====================================
// ��ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryOutOfScreenTop :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryOutOfScreenTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryOutOfScreenTop() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// �E�ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryOutOfScreenRight :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryOutOfScreenRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryOutOfScreenRight() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryOutOfScreenLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryOutOfScreenLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryOutOfScreenLeft() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//=====================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryMapChipBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryMapChipBottom():CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryMapChipBottom() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// ��ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryMapChipTop :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryMapChipTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryMapChipTop() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// �E�ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryMapChipRight :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryMapChipRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryMapChipRight() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
class CCollisionTerritoryMapChipLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	�R���X�g���N�^
	 *			�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	 *			�ݒ肵�Ă���
	 */
	CCollisionTerritoryMapChipLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//�f�X�g���N�^
	virtual ~CCollisionTerritoryMapChipLeft() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @param	��_
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};





//====================================================================
//
//	Class: CCollisionTerritoryMapObjectBottom
//	
//	���ɂ���}�b�v�I�u�W�F�N�g�̈�Ƃ̏Փ˔���
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================
class CCollisionTerritoryMapObjectBottom :public CCollisionTerritory {
public:
	/**
	* @desc �R���X�g���N�^
	*		�̈�^�C�v�̐ݒ���������q��TERRITORY_TYPE::BOTTOM��
	*		�ݒ肵�Ă���
	*/
	CCollisionTerritoryMapObjectBottom();

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CCollisionTerritoryMapObjectBottom();

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏۂ̃L�����N�^�[
	* @param ��_
	*/
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//=====================================
//
// �Փ˔�����
//
//=====================================
class CCollisionArea {
protected:
	//�Փˊ�_�Q
	std::vector<CCollisionBasePoint*>* m_pBasePoints = NULL;

	//�Փ˔���Q
	std::vector<CCollisionTerritory*>* m_pTerritories = NULL;


public:
	//�R���X�g���N�^
	CCollisionArea(){
		//�Փˊ�_�Q�̐���
		this->m_pBasePoints = new std::vector<CCollisionBasePoint*>();

		//�Փ˔���Q�̐���
		this->m_pTerritories = new std::vector<CCollisionTerritory*>();
	}

	//�f�X�g���N�^
	virtual ~CCollisionArea(){

		//�Փˊ�_�Q�̉��
		for (CCollisionBasePoint* pBasePoint : (*this->m_pBasePoints)) {

			SAFE_DELETE(pBasePoint);
		}
		SAFE_DELETE(this->m_pBasePoints);

		//�Փ˔���Q�̉��
		for(CCollisionTerritory* pTerritory: (*this->m_pTerritories)){

			SAFE_DELETE(pTerritory);
		}
		SAFE_DELETE(this->m_pTerritories);
	}

	/**
	 * @desc	�Փˊ�_�̒ǉ�
	 * @param	�Փˊ�_
	 */
	void addBasePoint(CCollisionBasePoint* pBasePoints) {
		this->m_pBasePoints->push_back(pBasePoints);
	}

	/**
	 * @desc	�Փ˔���̈�̒ǉ�
	 * @param	�Փ˔���̈�
	 */
	void addTerritory(CCollisionTerritory* pTerritory) {
		this->m_pTerritories->push_back(pTerritory);
	}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 * @tips	���t���[���Ăяo��
	 */
	virtual void collision(CCharacter* pChara) = 0;

};

//=====================================
// ��ʒ[�Ƃ̏Փ˔�����
//=====================================
class CCollsionAreaEndOfScreen : public CCollisionArea {
public:
	//�f�t�H���g�R���X�g���N�^
	CCollsionAreaEndOfScreen();

	//�R���X�g���N�^
	CCollsionAreaEndOfScreen(CBody* pBody);

	//�f�X�g���N�^
	~CCollsionAreaEndOfScreen(){}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 */
	void collision(CCharacter* pChara)override;

};

//=====================================
// ��ʏ�ɂ���S�Ẵ}�b�v�`�b�v�Ƃ̏Փ˔�����
//�@�܂�}�b�v�`�b�v�Ƃ̏Փ˔�����
//=====================================
class CCollsionAreaMap : public CCollisionArea {
public:
	//�f�t�H���g�R���X�g���N�^
	CCollsionAreaMap();

	//�R���X�g���N�^
	CCollsionAreaMap(CBody* pBody, float width, float height);

	//�f�X�g���N�^
	~CCollsionAreaMap() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 */
	void collision(CCharacter* pChara)override;

};


//====================================================================
//
//	Class: CCollsionAreaMapObject
//	
//	��ʏ�ɂ���S�Ẵ}�b�v�I�u�W�F�N�g�Ƃ̏Փ˔�����
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================
class CCollsionAreaMapObject : public CCollisionArea {
public:
	
	/**
	* @desc �R���X�g���N�^
	*/
	CCollsionAreaMapObject(void);

	/**
	* @desc �f�X�g���N�^
	*/
	~CCollsionAreaMapObject(void);

	/**
	* @desc �Փ˔���
	* @param �ՓˑΏۂ̃L�����N�^�[
	*/
	void collision(CCharacter* pChara)override;

};


//=====================================
// ��ʊO�Ƃ̏Փ˔�����
//=====================================
class CCollsionAreaOutOfScreen : public CCollisionArea {
public:
	//�f�t�H���g�R���X�g���N�^
	CCollsionAreaOutOfScreen();

	//�R���X�g���N�^
	CCollsionAreaOutOfScreen(CBody* pBody);

	//�f�X�g���N�^
	~CCollsionAreaOutOfScreen() {}

	/**
	 * @desc	�Փ˔���
	 * @param	�ՓˑΏۂ̃L�����N�^�[
	 */
	void collision(CCharacter* pChara)override;

};
