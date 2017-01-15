/*
 * Animation.h
 *
 *	2016/11/07	Osumi
 *
 */
#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"cocos2d.h"
#include"Constants.h"

//=====================================
// �`�b�v�f�[�^�N���X
//�@�@�@�@�摜��1�����̈ʒu�ƃT�C�Y�̃f�[�^
//=====================================
typedef cocos2d::Rect CChip;

class CPlayerCharacterBoy;

//=====================================
// �A�j���[�V�����N���X
//		���̃N���X�ɂ̓`�b�v�̏��͑��݂��Ȃ�
//		�A�j���[�V�����Ԋu�Ɩ��������Ƃ�
//		���݂̃t���[�������v�Z���邾���̃N���X
//=====================================
class CAnimation {
protected:
	//�J�E���^�[
	int m_counter = 0;

	//�؂�ւ��Ԋu�i�p���p������̑��x�ɂȂ�j
	int m_interval = 0;

	//�A�j���[�V��������
	int m_number = 0;

	//���݂̃t���[��
	int m_currentFrame = 0;

	//�t���[���̊J�n
	int m_startFrame = 0;

	//���[�v���邩�ǂ����̃t���O
	//true...���[�v����
	bool m_isLoop = false;

	//�A�j���[�V�������I���������ǂ����̃t���O
	//true...�I������
	bool m_isEnd = false;

public:
	//�f�t�H���g�R���X�g���N�^
	CAnimation(){}

	//�R���X�g���N�^
	CAnimation(int interval, int number,bool isLoop = false, int startFrame = 0) :
		m_interval(interval), m_number(number), m_startFrame(startFrame), m_isLoop(isLoop) {}

	//�f�X�g���N�^
	virtual ~CAnimation() {}

	/**
	 * @desc	���݂̃t���[���̎擾
	 * @return	���݂̃t���[��
	 */
	virtual int getCurrentFrame() {
		return this->m_currentFrame;
	}

	/**
	 * @desc	�A�j���[�V�����I���t���O�̎擾
	 * @return	true...�I�����܂����B
	 */
	virtual bool isEnd() {
		return this->m_isEnd;
	}

	/**
	* @desc	�A�j���[�V���������Z�b�g����
	* @atuhr	Shinya Ueba
	*/
	virtual void reset(void) {
		this->m_counter = 0;
		this->m_currentFrame = 0;
		this->m_isEnd = false;
	}

	
	/**
	 * @desc	�A�j���[�V�����̍X�V����
	 * @return	�\������t���[�����i-1���������܂��s���Ă��Ȃ��j
	 */
	virtual int update() {

		//�A�j���[�V�������I�����Ă��Ȃ���΃J�E���^�[�̍X�V���s��
		if (this->m_isEnd ==false) {

			this->m_counter++;

			//�J�E���^�[�̐����A�j���[�V���������閇���ȏ�ɂȂ�����J�E���^�[�����Z�b�g����
			if (this->m_counter >= this->m_interval*this->m_number) {

				//���[�v����Ȃ�
				if (this->m_isLoop == true) {

					//�J�E���^�[�����Z�b�g
					this->m_counter = 0;
				}
				else {

					//�A�j���[�V�������I���������ǂ����̃t���O�ɑ΂���true������
					this->m_isEnd = true;

					//���[�v���Ȃ��A�j���[�V�����ɑ΂��Ă͔�яo���J�E���^�[���f�N�������g����
					this->m_counter --;
				}
			}
		}

		//�\������t���[����
		m_currentFrame = this->m_counter / this->m_interval;

		//�X�V�������݂̃t���[�����ꉞ�Ԃ��B
		return m_currentFrame;
	}

	/**
	 * @desc	�`�b�v�f�[�^�̒ǉ�
	 * @para	�`�b�v�f�[�^
	 */
	virtual void addChipData(CChip* pChip) = 0;

	/**
	 * @desc	���݃t���[���̃`�b�v���擾����
	 * @return	���݂̃t���[���`�b�v
	 */
	virtual CChip getCurrentChip() = 0;

};

//========================================================================
// �`�b�v�A�j���[�V�����N���X
//		�A�j���[�V��������摜�����ɕ���ł�ꍇ�݂̂Ɍ���
//		�A�j���[�V�����N���X�����Ɍ��݂̃t���[������؂���ׂ��摜���擾
//========================================================================
class CChipAnimation : public CAnimation {
protected:
	//�Q�Ƃ���`�b�v�f�[�^
	CChip* m_pChip = NULL;

public:
	CChipAnimation(int interval, int number, bool isLoop = false, int startFrame = 0) :
		CAnimation(interval, number, isLoop, startFrame) {}

	virtual ~CChipAnimation() {}

	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	void addChipData(CChip* pChip) override{
	
		this->m_pChip = pChip;
	}

	/**
	* @desc ���݃t���[���̃`�b�v���擾����
	* @return ���݂̃t���[���`�b�v
	*/
	virtual CChip getCurrentChip() override {
		CChip chip
		(
			this->m_pChip->size.width * (this->m_currentFrame + this->m_startFrame),
			this->m_pChip->origin.y,
			this->m_pChip->size.width,
			this->m_pChip->size.height
		);

		return chip;
	}

};


//========================================================================
// �`�b�v�m�b�g�A�j���[�V�����N���X
//		�`�b�v�N���X���A�j���[�V�����N���X�ɓ��������̂�
//�@�@�@�A�j���[�V����������1���G�̉摜�̕\�����s�����߂̃L�����N�^�[��
//�@�@�@�������邱�Ƃ�����ɂȂ�B
//�@�@�@�������CChipAnimation������if�����g������
//�@�@�@1���G���g�p����N���X�̂݃`�b�v�f�[�^�N���X������������ł��悢�̂���
//		����͏�Ԃɂ���Ă��摜�𕡐��������肵�Ă���̂�
//		CAnimation�̔h���N���X�Ƃ��đ��݂����M�戵���₷��
//		�Ȃ̂ŃA�j���[�V�������Ȃ��A�j���[�V�����N���X��1�p�ӂ��Ă�������
//		�X�}�[�g�ŊJ�����₷���Ȃ�B
//========================================================================
class CChipNotAnimation :public CChipAnimation {
public:
	CChipNotAnimation(int startFrame = 0):CChipAnimation(0,0,false,startFrame){}
	~CChipNotAnimation(){}

	/**
	* @desc �X�V�����͍s�킸�Ԃ��l�͕K��1�ɂȂ�
	*/
	int update()override { return 1; }

	/**
	* @desc ���݃t���[���̃`�b�v���擾����
	* @return ���݂̃t���[���`�b�v
	*/
	virtual CChip getCurrentChip() override {

		return (*this->m_pChip);
	}

};

//========================================================================
// �`�b�v���X�g�A�j���[�V�����N���X
//		�摜��������x�o���o���ɕ���ł��Ă��Ή��\����
//�@�@�@�`�b�v�f�[�^�̃T�C�Y�͓��ꂳ��Ȃ���΂Ȃ�Ȃ�
//�@�@�@�`�b�v�f�[�^�̃T�C�Y�����ꂳ��Ȃ��ꍇ�͂���ɉ��������S�ʒu��
//�@�@�@�v�Z���Ȃ���΂Ȃ�Ȃ��Ƃ������Ƃ��l�����邱��
//�@�@�@�A�j���[�V�����N���X�����Ɍ��݂̃t���[���̃`�b�v�f�[�^�����X�g����擾
//========================================================================
class CChipListAnimation : public CAnimation {
protected:
	//�A�j���[�V����������`�b�v�f�[�^�̃��X�g
	std::vector<CChip*>m_chipList;

public:
	CChipListAnimation(int interval, bool isLoop = false,int startFrame = 0) :CAnimation(interval, 0, isLoop, startFrame) {}

	~CChipListAnimation() {
		//�`�b�v�̉��
		std::vector<CChip*>::iterator itr = this->m_chipList.begin();
		while (itr != this->m_chipList.end()) {
			SAFE_DELETE((*itr));
			itr++;
		}

	}

	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	void addChipData(CChip* pChip) override {

		//�`�b�v�f�[�^��ǉ�����
		this->m_chipList.push_back(pChip);

		//�`�b�v�f�[�^���X�V������A�j���[�V�����̍ő吔���X�V����
		this->m_number = this->m_chipList.size();
	}

	/**
	* @desc ���݃t���[���̃`�b�v���擾����
	* @return ���݂̃t���[���`�b�v
	*/
	virtual CChip getCurrentChip() override {
		//�Y�����Z�q�Ŏ擾�����f�[�^���̂�CChip*�Ȃ̂ł��̒��g��Ԃ��B
		return *(this->m_chipList[this->m_currentFrame]);
	}

};

//========================================================================
// �v���C���[��p�A���A�j���[�V����
//========================================================================
class CPlayerAttackAnimation : public CAnimation {
protected:
	//�A�j���[�V����������`�b�v�f�[�^�̃��X�g
	int m_line;

	int m_nowLine = 0;

	//�Đ�����`�b�v�̐擪�̃`�b�v�f�[�^�����i�[
	std::vector<CAnimation*> m_pAnimations;

	

public:
	CPlayerAttackAnimation() {}

	~CPlayerAttackAnimation() {
		for (CAnimation* pAnimation : this->m_pAnimations) {
			SAFE_DELETE(pAnimation);
		}
	}

	/**
	* @desc	�A�j���[�V�����̍X�V����
	* @return	�\������t���[�����i-1���������܂��s���Ă��Ȃ��j
	*/
	virtual int update()override;

	/**
	* @desc �`�b�v�f�[�^�̒ǉ�
	* @param �`�b�v�f�[�^
	*/
	void addChipData(CChip* pChip)override {

	}

	void addChipData(CAnimation* pAnimation) {

		//�`�b�v�f�[�^��ǉ�����
		this->m_pAnimations.push_back(pAnimation);

		//�`�b�v�f�[�^���X�V������A�j���[�V�����̍ő吔���X�V����
		this->m_line = this->m_pAnimations.size();
	}

	/**
	* @desc ���݃t���[���̃`�b�v���擾����
	* @return ���݂̃t���[���`�b�v
	*/
	virtual CChip getCurrentChip() override {

		return this->m_pAnimations[this->m_nowLine]->getCurrentChip();
	}

	int getCurrentFrame()override {
		this->m_currentFrame = 0;

		for (int i = 0; i < this->m_line; i++) {
			this->m_currentFrame += this->m_pAnimations[i]->getCurrentFrame();
		}

		return this->m_currentFrame;
	}

	void reset(void)override {
		for (CAnimation* pAnimation : this->m_pAnimations) {
			pAnimation->reset();
		}
		
		this->m_nowLine = 0;

		this->m_isEnd = false;
	}

};