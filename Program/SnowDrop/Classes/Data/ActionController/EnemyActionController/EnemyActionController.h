/*
* EnemyActionController.h
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/ActionController.h"

//�G�N���X�̑O���錾
//class CEnemyCharacter;

//===================================================================
//�@�G�̓���̔h����
//===================================================================
class CEnemyAction :public CAction {
public:
	//�^�[�Q�b�g�̎��
	enum class TARGET_TYPE :int {
		NONE,
		BOY,
		GIRL,
		BOTH
	};

public:
	virtual ~CEnemyAction() {}

	/*
	* @desc 2�_�Ԃ̋��������߂鎮
	* @param �_1
	* @param �_2
	* @return �_1�Ɠ_2�̋���
	*/
	virtual float length(cocos2d::Point pt1, cocos2d::Point pt2);

	/*
	* @desc 2�̂̃L�����̋��������߂鎮
	* @param�@�L����1
	* @param�@�L����2
	* @return �L����1�ƃL����2�̋���
	*/
	virtual float lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2);

	/*
	* @desc �^�[�Q�b�g�̒T���ƑI��
	* @param �A�N�V�������s���L�����N�^�[
	* @return �^�[�Q�b�g�����܂������ǂ����@true...���܂���
	* @tips �����ƋR�m�œG�ɋ߂����̋����𓱂�
	*�@�@�@ �߂������ǐՔ͈͂ɂȂ�^�[�Q�b�g�ɐݒ�
	*/
	virtual bool seachAndSelectTarget(CCharacter* pChara);

	/*
	* @desc �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
	* @param �A�N�V�������s���L�����N�^�[
	* @param �^�[�Q�b�g�̃^�C�v
	*/
	virtual void checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type);

	/*
	* @desc �L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
	* @param �A�N�V�������s���L�����N�^�[
	* @param �ڕW�n�_�̍��W
	*/
	virtual void normalizeVel_X(CCharacter* pChara, cocos2d::Point pt);

	/*
	* @desc �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
	* @param �A�N�V�������s���L�����N�^�[
	* @param �ڕW�n�_�̍��W
	*/
	virtual void normalizeVel(CCharacter* pChara, cocos2d::Point pt);

};

//===================================================================
//�@�G�̑ҋ@����
//===================================================================
class CEnemyActionStay :public CEnemyAction {
protected:

	//�A�N�V���������ǂ��� true...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�������J�n��Ԃ��ǂ����@true...�J�n���
	bool m_isStart = false;

	//�������ׂ��^�[�Q�b�g
	TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �ǐՂ��ׂ��v���C���[�^�C�v
	*/
	CEnemyActionStay(TARGET_TYPE type);

	/*
	* @desc �J�n����
	*/
	virtual void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	virtual void update(CCharacter* pChara)override;

	/*
	* @desc �I����������
	*/
	virtual void stop() override;
};
//===================================================================
//�@�G�̎��Ԍo�߂ɂ��ҋ@����
//===================================================================
class CEnemyActionStayAtTime :public CEnemyActionStay {
private:
	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

public:

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �R���X�g���N�^
	* @param �ǐՂ��ׂ��v���C���[�^�C�v
	*/
	CEnemyActionStayAtTime(TARGET_TYPE type);

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

};

//===================================================================
//�@�G�̂��낤�듮��
//===================================================================
class CEnemyActionWondering :public CEnemyAction {
private:
	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//���낤�낷�����
	int m_vec = 1;

	//�A�N�V���������ǂ��� true...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�������J�n��Ԃ��ǂ����@true...�J�n���
	bool m_isStart = false;
	
	//�������ׂ��^�[�Q�b�g
	TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �ǐՂ��ׂ��v���C���[�^�C�v
	*/
	CEnemyActionWondering(TARGET_TYPE type);

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I����������
	*/
	void stop() override;
};

//===================================================================
//�@�G�̒ǐՓ���
//===================================================================
class CEnemyActionChase :public CEnemyAction {

private:

	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//���낤�낷�����
	int m_vec = 1;

	//�A�N�V���������ǂ��� true...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�������J�n��Ԃ��ǂ����@true...�J�n���
	bool m_isStart = false;

	//�ǐՓ�����s���G����s���邩�ǂ���
	bool m_isFlying = false;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �L�����N�^�[����Ԃ��ǂ����i�f�t�H���g��false�j
	*/
	CEnemyActionChase(bool isFlying = false);

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I����������
	*/
	void stop() override;
};

//===================================================================
//�@�G�̏o���n�_�ɖ߂铮��
//===================================================================
class CEnemyActionReturnLanchPos :public CEnemyActionStay {
private:
	//�o���ʒu
	cocos2d::Point m_launchPos;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �ǐՂ��ׂ��v���C���[�^�C�v
	*/
	CEnemyActionReturnLanchPos(TARGET_TYPE type, CCharacter* pChara);

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I����������
	*/
	void stop() override;
};