/*
 * Animation.h
 *
 *	2016/11/07	Osumi
 *
 */
#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"cocos2d.h"
#include"Constants.h"

//=====================================
// チップデータクラス
//　　　　画像の1部分の位置とサイズのデータ
//=====================================
typedef cocos2d::Rect CChip;

//=====================================
// アニメーションクラス
//		このクラスにはチップの情報は存在しない
//		アニメーション間隔と枚数をもとに
//		現在のフレーム数を計算するだけのクラス
//=====================================
class CAnimation {
protected:
	//カウンター
	int m_counter = 0;

	//切り替え間隔（パラパラ漫画の速度になる）
	int m_interval = 0;

	//アニメーション枚数
	int m_number = 0;

	//現在のフレーム
	int m_currentFrame = 0;

	//フレームの開始
	int m_startFrame = 0;

	//ループするかどうかのフラグ
	//true...ループする
	bool m_isLoop = false;

	//アニメーションが終了したかどうかのフラグ
	//true...終了した
	bool m_isEnd = false;

public:
	//コンストラクタ
	CAnimation(int interval, int number,bool isLoop = false, int startFrame = 0) :
		m_interval(interval), m_number(number), m_startFrame(startFrame), m_isLoop(isLoop) {}

	//デストラクタ
	virtual ~CAnimation() {}

	/**
	 * @desc	現在のフレームの取得
	 * @return	現在のフレーム
	 */
	int getCurrentFrame() {
		return this->m_currentFrame;
	}

	/**
	 * @desc	アニメーション終了フラグの取得
	 * @return	true...終了しました。
	 */
	bool isEnd() {
		return this->m_isEnd;
	}

	/**
	* @desc	アニメーションをリセットする
	* @atuhr	Shinya Ueba
	*/
	void reset(void) {
		this->m_counter = 0;
		this->m_currentFrame = 0;
		this->m_isEnd = false;
	}

	
	/**
	 * @desc	アニメーションの更新処理
	 * @return	表示するフレーム数（-1初期化がまだ行われていない）
	 */
	virtual int update() {

		//アニメーションが終了していなければカウンターの更新を行う
		if (this->m_isEnd ==false) {

			this->m_counter++;

			//カウンターの数がアニメーションさせる枚数以上になったらカウンターをリセットする
			if (this->m_counter >= this->m_interval*this->m_number) {

				//ループするなら
				if (this->m_isLoop == true) {

					//カウンターをリセット
					this->m_counter = 0;
				}
				else {

					//アニメーションが終了したかどうかのフラグに対してtrueを入れる
					this->m_isEnd = true;

					//ループしないアニメーションに対しては飛び出たカウンターをデクリメントする
					this->m_counter --;
				}
			}
		}

		//表示するフレーム数
		m_currentFrame = this->m_counter / this->m_interval;

		//更新した現在のフレームを一応返す。
		return m_currentFrame;
	}

	/**
	 * @desc	チップデータの追加
	 * @para	チップデータ
	 */
	virtual void addChipData(CChip* pChip) = 0;

	/**
	 * @desc	現在フレームのチップを取得する
	 * @return	現在のフレームチップ
	 */
	virtual CChip getCurrentChip() = 0;

};

//========================================================================
// チップアニメーションクラス
//		アニメーションする画像が横に並んでる場合のみに限る
//		アニメーションクラスを元に現在のフレームから切り取るべき画像を取得
//========================================================================
class CChipAnimation : public CAnimation {
protected:
	//参照するチップデータ
	CChip* m_pChip = NULL;

public:
	CChipAnimation(int interval, int number, bool isLoop = false, int startFrame = 0) :
		CAnimation(interval, number, isLoop, startFrame) {}

	virtual ~CChipAnimation() {}

	/**
	* @desc チップデータの追加
	* @param チップデータ
	*/
	void addChipData(CChip* pChip) override{
	
		this->m_pChip = pChip;
	}

	/**
	* @desc 現在フレームのチップを取得する
	* @return 現在のフレームチップ
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
// チップノットアニメーションクラス
//		チップクラスをアニメーションクラスに統合したので
//　　　アニメーション無しの1枚絵の画像の表示を行うためのキャラクターを
//　　　生成することが困難になる。
//　　　もちろんCChipAnimation内部でif文を使ったり
//　　　1枚絵を使用するクラスのみチップデータクラスを持たせたりでもよいのだが
//		今回は状態によってが画像を複数扱ったりしているので
//		CAnimationの派生クラスとして存在した邦画扱いやすい
//		なのでアニメーションしないアニメーションクラスを1つ用意しておく方が
//		スマートで開発しやすくなる。
//========================================================================
class CChipNotAnimation :public CChipAnimation {
public:
	CChipNotAnimation(int startFrame = 0):CChipAnimation(0,0,false,startFrame){}
	~CChipNotAnimation(){}

	/**
	* @desc 更新処理は行わず返す値は必ず1になる
	*/
	int update()override { return 1; }

	/**
	* @desc 現在フレームのチップを取得する
	* @return 現在のフレームチップ
	*/
	virtual CChip getCurrentChip() override {

		return (*this->m_pChip);
	}

};

//========================================================================
// チップリストアニメーションクラス
//		画像がある程度バラバラに並んでいても対応可能だが
//　　　チップデータのサイズは統一されなければならない
//　　　チップデータのサイズが統一されない場合はそれに応じた中心位置を
//　　　計算しなければならないということを考慮すること
//　　　アニメーションクラスを元に現在のフレームのチップデータをリストから取得
//========================================================================
class CChipListAnimation : public CAnimation {
protected:
	//アニメーションさせるチップデータのリスト
	std::vector<CChip*>m_chipList;

public:
	CChipListAnimation(int interval, bool isLoop = false,int startFrame = 0) :CAnimation(interval, 0, isLoop, startFrame) {}

	~CChipListAnimation() {
		//チップの解放
		std::vector<CChip*>::iterator itr = this->m_chipList.begin();
		while (itr != this->m_chipList.end()) {
			SAFE_DELETE((*itr));
			itr++;
		}

	}

	/**
	* @desc チップデータの追加
	* @param チップデータ
	*/
	void addChipData(CChip* pChip) override {

		//チップデータを追加する
		this->m_chipList.push_back(pChip);

		//チップデータも更新したらアニメーションの最大数も更新する
		this->m_number = this->m_chipList.size();
	}

	/**
	* @desc 現在フレームのチップを取得する
	* @return 現在のフレームチップ
	*/
	virtual CChip getCurrentChip() override {
		//添字演算子で取得したデータ自体がCChip*なのでその中身を返す。
		return *(this->m_chipList[this->m_currentFrame]);
	}

};