#pragma once
/*
* EnemyActionPursuit.h
*
*	2016/11/22	Yamasaki
*
*/


#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"Data/ActionController/ActionController.h"
#include"Model/Character/EnemyCharacter/EnemyCharacter.h"



//===================================================================
// �ǐՂ̊��N���X(�ǐ՗D�揇�ʂ͓G�ɍ��킹��)
//===================================================================
class CEnemyActionPursuit :public CAction {
protected:

	//�ǐՒ����ǂ����̃t���O	true...�ǐՒ�
	bool m_isPursuiting = false;

	//�ǐՊJ�n�t���O
	bool m_isPursuitStart = false;

public:
	//�R���X�g���N�^
	CEnemyActionPursuit() {}

	/*
	* @desc �J�n
	*/
	void start()override {
		this->m_isPursuitStart = true;
	}

	/*
	*	@desc�@�ǐ�
	*	@param �ǐՂ���G�̃A�h���X
	*/
	virtual void pursuit(CCharacter* pChara) = 0;

	/*
	* @desc �X�V����
	* @param �ǐՂ��s���G�L�����N�^�[�̃A�h���X
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I��
	*/
	void stop()override {
		this->m_isPursuiting = false;
	}

	// �t���O�̎擾
	bool getActionFlag() {
		return this->m_isPursuiting;
	}
};

//===================================================================
// �߂��v���C���[�D��̒ǐՃN���X
//===================================================================
class CActionPursuitNear : public CEnemyActionPursuit {
public:
	CActionPursuitNear() {}

	~CActionPursuitNear() {}
	/*
	*	@desc�@�ǐ�
	*	@param �ǐՂ���G�̃A�h���X
	*/
	void pursuit(CCharacter* pChara);
};


//===================================================================
// �����D��̒ǐՃN���X
//===================================================================
class CActionPursuitGirlPriority : public CEnemyActionPursuit {
public:
	CActionPursuitGirlPriority() {}
	~CActionPursuitGirlPriority() {}


	/*
	*	@desc	�U��q�^��
	*	@param	�U��q�^������L����
	*	@param	�U��q�^���̒��S�_
	*	@param	�U��q��
	*	@param	�U��q�̍���
	*	@param	�U��q�̑����i�f�t�H���g��1�j
	*/
	void swing(CCharacter* chara, cocos2d::Point pt, float width, float height, float spped = 1) {

		static float degX = 270;
		static float degY = 180;

		chara->m_pMove->m_pos.x = width* sin(degX) + pt.x;
		chara->m_pMove->m_pos.y = height * sin(degY) + pt.y;
	}

	/*
	*	@desc ������ǐ�
	*	@param �ǐՂ���G�̃A�h���X
	*/
	void pursuit(CCharacter* pChara);
};

//===================================================================
// �����̂ݒǐՃN���X
//===================================================================
class CActionPursuitGirlOnly : public CEnemyActionPursuit {
public:
	CActionPursuitGirlOnly() {}
	~CActionPursuitGirlOnly() {}
	/*
	*	@desc�@�ǐ�
	*	@param �ǐՂ���G�̃A�h���X
	*/
	void pursuit(CCharacter* pChara);
};


//===================================================================
// �߂��v���C���[�̕��������������̒ǐՃN���X
//===================================================================
class CActionPursuitDirection : public CEnemyActionPursuit {
public:
	CActionPursuitDirection() {}
	~CActionPursuitDirection() {}

	/*
	*	@desc�@�ǐ�
	*	@param �ǐՂ���G�̃A�h���X
	*/
	void pursuit(CCharacter* pChara);
};