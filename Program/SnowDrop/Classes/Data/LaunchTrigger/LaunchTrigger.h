#pragma once

#include <stdio.h>
#include <memory>
#include "cocos2d.h"
#include "Constants.h"
#include "Data/LaunchData/LaunchData.h"

//=======================================
//  前方宣言
//=======================================
class CCharacter;

//=======================================
//
//  出撃トリガー
//
//=======================================
class CLaunchTrigger {

public:
	//有効フラグ　false...出撃スケジュールから取り外す
	bool m_activeFlag = false;

	//コンストラクタ
	CLaunchTrigger() {
		this->m_activeFlag = true;
	}

	//デストラクタ
	virtual ~CLaunchTrigger() {}

	/**
	 * @desc	発射し終わったかどうか
	 * @retrun	true...発射した　false...発射していない
	 * @tips	発射し終わったかどうかは派生クラスによって
	 *			フラグが変化する場合が存在する
	 */
	virtual bool isLaunched() {
		return this->m_activeFlag;
	}

	/**
	 * @desc	設定されているトリガーがイベントを行えるかどうか
	 * @retrun	true...イベント実行が可能
	 * @tips	イベントの実行可能条件は派生クラスによって変化する
	 */
	virtual bool isTrigger() = 0;

	/**
	 * @desc	トリガーイベントの実行
	 * @tips	ここでのトリガーイベントはキャラクターの生成
	 */
	virtual CCharacter* action() = 0;

};

//=======================================
//
//  敵出撃トリガー
//		敵出撃データをトリガーとして敵出撃というイベントを実行させる
//
//=======================================
class CEnemyLaunchTrigger :public CLaunchTrigger{
private:
	//敵出撃データ
	CEnemyLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	コンストラクタ
	 * @param	敵出撃データ
	 * @tips	敵出撃データをトリガーとして設定する
	 */
	CEnemyLaunchTrigger(CEnemyLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//デストラクタ
	virtual ~CEnemyLaunchTrigger();

	/**
	 * @desc	イベントを行えるかどうか
	 * @retrun	true...イベント実行可
	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	設定されている敵出撃データを元に敵を生成する
	 * @tups	トリガーを元にイベントを実行
	 */
	virtual CCharacter* action()override;

};

//=======================================
//
//  ギミック生成トリガー
//
//=======================================
class CGimmickLaunchTrigger :public CLaunchTrigger {
private:
	//弾出撃データ
	CGimmickLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	コンストラクタ
	 * @param	敵出撃データ
	 * @tips	敵出撃データをトリガーとして設定する
	 */
	CGimmickLaunchTrigger(CGimmickLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//デストラクタ
	virtual ~CGimmickLaunchTrigger();

	/**
	 * @desc	イベントを行えるかどうか
	 * @retrun	true...イベント実行可
 	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	設定されている敵出撃データを元に敵を生成する
	 * @tips	トリガーを元にイベントを実行
	 */
	virtual CCharacter* action()override;

};


//=======================================
//
//  エフェクト生成トリガー
//
//=======================================
class CEffectLaunchTrigger :public CLaunchTrigger {
private:
	//エフェクト出撃データ
	CEffectLaunchData* m_pLaunchdata = NULL;

public:

	/**
	 * @desc	コンストラクタ
	 * @param	エフェクト出撃データ
	 * @tips	エフェクト出撃データをトリガーとして設定する
	 */
	CEffectLaunchTrigger(CEffectLaunchData* pLaunchdata)
		:m_pLaunchdata(pLaunchdata) {}

	//デストラクタ
	virtual ~CEffectLaunchTrigger();

	/**
	 * @desc	イベントを行えるかどうか
	 * @retrun	true...イベント実行可
	 */
	virtual bool isTrigger()override;

	/**
	 * @desc	設定されている敵出撃データを元に敵を生成する
	 * @tips	トリガーを元にイベントを実行
	 */
	virtual CCharacter* action()override;

};

//=======================================
//
//  発射台
//		出撃スケジュールの参照を設定して
//		出撃スケジュールに取り付けられている出撃トリガーの順番通りに
//		イベントを実行していく。
//		つまり取り付けられた順番通りに出撃を行なっていく。
//
//		Aggregate
//
//=======================================
class CLauncher {
public:
	//出撃スケジュールの参照（つまりこのクラスで生成や破棄を行わない）
	//1フレームに出撃させるトリガーイベントの集まり
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	/**
	 * @desc	コンストラクタ
	 * @param	出撃スケジュールのアドレス
	 */
	CLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule)
		:m_pLaunchSchedule(pLaunchSchedule){}

	//デストラクタ
	~CLauncher(){}

	/**
	 * @desc	トリガーの追加
	 * @param	追加するトリガー
	 */
	void add(CLaunchTrigger* pLaunchTrigger) {
		this->m_pLaunchSchedule->push_back(pLaunchTrigger);
	}

	/**
	 * @desc	出撃スケジュールのサイズを取得
	 * @return	取り付けられている数
	 */
	int getSize() {
		return (int)this->m_pLaunchSchedule->size();
	}

	/**
	 * @desc	キャラタクー１体を取得
	 * @param	添え字番号
	 * @return	キャラクター
	 */
	CLaunchTrigger* getAt(int index) {
		//最大数以上ならNULLを返すように設定しておく
		if (this->getSize() <= index) {
			return NULL;
		}

		return (*this->m_pLaunchSchedule)[index];
	}


	//=======================================
	//
	//  出撃トリガーイテレーター
	//		発射台に取り付けられているトリガーを発射可能かしらべて、
	//		発射可能なら1つずつ出撃させるためのクラス
	//		Aggregateの中に実装
	//
	//		Iterator
	//
	//=======================================
	class CLaunchTriggerIterator {
	public:
		//発射台
		CLauncher* m_pLaucher = NULL;

		//現在参照中の番号
		int m_triggerCount = 0;

		//コンストラクタ
		CLaunchTriggerIterator(CLauncher* pLaucher) 
			:m_pLaucher(pLaucher){}


		/**
		 * @desc	次の出撃があるかどうか調べる
		 * @tips	もしくは出撃トリガーが起動可能かどうか調べる
		 */
		bool hasNext(){
		
			//トリガーイベントの集まりのサイズを調べる
			if (this->m_pLaucher->getSize() <= this->m_triggerCount) {
				return false;
			}

			//出撃トリガーが起動可能かどうかを調べる
			if (this->m_pLaucher->getAt(this->m_triggerCount)->isTrigger() == false) {
				//起動でない場合は添え字番号を次に進めて
				this->m_triggerCount++;
				//次をチェック
				return this->hasNext();
			}
		
			return true;
		}

		/**
		 * @desc	現在の出撃トリガーを取得し添え字番号を次に進める
		 */
		CLaunchTrigger* next() {

			CLaunchTrigger* pTrigger = this->m_pLaucher->getAt(this->m_triggerCount);
				this->m_triggerCount++;
				return pTrigger;
		}
	};

	/**
	 * @desc	出撃トリガーイテレーターの生成
	 * @param	出撃トリガーイテレーター
	 */
	std::shared_ptr<CLaunchTriggerIterator> iterator() {
		return std::shared_ptr<CLaunchTriggerIterator>(new CLaunchTriggerIterator(this));
	}

};

//=======================================
//
//  出撃スケジューラー
//	Singleton
//
//=======================================
class CLaunchScheduler {

	//===========================================================
	//　ここからの提供は　シングルトン　（株）です
	//===========================================================
private:
	//共有インスタンス
	static CLaunchScheduler* m_pSharedScheduler;

	//コンストラクタ
	CLaunchScheduler();

public:
	//共有インスタンスの取得
	static CLaunchScheduler* getInstance();

	//教諭ンインスタンスの破棄
	static void removeInstance();

	//デストラクタ
	~CLaunchScheduler();

	//===========================================================
	//　ここまでの提供は　シングルトン　（株）のでした
	//===========================================================
	
public:
	//発射台
	CLauncher* m_pLauncher = NULL;

	/**
	 * @desc	発射台の生成
	 * @param	発射台に設定する出撃スケジュールのアドレス
	 */
	void createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule);

	/**
	 * @desc	キャラクターの出撃
	 * @param	取り付けるレイヤー
	 */
	void launchCharacter(cocos2d::Layer* pLayer);

};

