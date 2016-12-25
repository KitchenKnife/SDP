
#include "LaunchTrigger.h"
#include "Model/Character/Factory/EnemyFactory.h"
#include "Model/Character/Factory/GimmickFactory.h"
#include "Model/Character/Factory/EffectFactory.h"

//=======================================
//
//  敵出撃トリガー
//		敵出撃データをトリガーとして敵出撃というイベントを実行させる
//
//=======================================
//デストラクタ
CEnemyLaunchTrigger::~CEnemyLaunchTrigger() {
	//敵出撃データを削除
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	イベントを行えるかどうか
 * @retrun	true...イベント実行可
 */
bool CEnemyLaunchTrigger::isTrigger(){
	//敵出撃データに中身がなければ
	if(this->m_pLaunchdata == NULL){
		//イベント実行　不可　を返す。
		return false;
	}
	//イベント実行　可　を返す
	return true;
}

/**
 * @desc	設定されている敵出撃データを元に敵を生成する
 * @tips	トリガーを元にイベントを実行
 */
CCharacter* CEnemyLaunchTrigger::action(){

	//敵を生成
	//引数に出撃させるポイントと敵のタイプを渡す
	CCharacter* pEnemyCharacter = CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		this->m_pLaunchdata->m_type
	);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	//生成した敵キャラクターを返す。
	return pEnemyCharacter;
}

//=======================================
//
//  ギミック生成トリガー
//
//=======================================
//デストラクタ
CGimmickLaunchTrigger::~CGimmickLaunchTrigger() {
	//ギミック出撃データを削除
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	イベントを行えるかどうか
 * @retrun	true...イベント実行可
 */
bool CGimmickLaunchTrigger::isTrigger() {
	//ギミック出撃データに中身がなければ
	if (this->m_pLaunchdata == NULL) {
		//イベント実行　不可　を返す
		return false;
	}
	//イベント実行　可　を返す
	return true;
}

/**
 * @desc	設定されている敵出撃データを元に敵を生成する
 * @tips	トリガーを元にイベントを実行
 */
CCharacter* CGimmickLaunchTrigger::action() {

	//ギミックを生成
	//引数にギミックのタイプと出撃させる位置を渡す
	CCharacter* pGimmickCharacter = CGimmickFactoryManager::getInstance()->create(
		(int)this->m_pLaunchdata->m_type,
		this->m_pLaunchdata->m_pos
	);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	//生成したギミックを返す。
	return pGimmickCharacter;
}


//=======================================
//
//  エフェクト生成トリガー
//
//=======================================
//デストラクタ
CEffectLaunchTrigger::~CEffectLaunchTrigger() {
	//エフェクト出撃データを削除
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
 * @desc	イベントを行えるかどうか
 * @retrun	true...イベント実行可
 */
bool CEffectLaunchTrigger::isTrigger() {
	//エフェクト出撃データに中身がなければ
	if (this->m_pLaunchdata == NULL) {
		//イベント実行　不可　を返す
		return false;
	}
	//イベント実行　可　を返す
	return true;
}

/**
 * @desc	設定されているエフェクト出撃データを元にエフェクトを生成する
 * @tips	トリガーを元にイベントを実行
 */
CCharacter* CEffectLaunchTrigger::action() {

	//エフェクトの生成
	//引数にエフェクトのタイプと出撃させる位置を渡す
	CCharacter* pEffectCharacter = CEffectFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		this->m_pLaunchdata->m_type
	);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	//生成したギミックを返す。
	return pEffectCharacter;
}

//=======================================
//
//  出撃スケジューラー
//	Singleton
//
//=======================================
//共有インスタンス本体
CLaunchScheduler* CLaunchScheduler::m_pSharedScheduler = NULL;

//コンストラクタ
CLaunchScheduler::CLaunchScheduler(){}

//共有インスタンスの取得
CLaunchScheduler* CLaunchScheduler::getInstance() {

	//共有インスタンスが存在しなければ
	if (CLaunchScheduler::m_pSharedScheduler == NULL) {
		//共有インスタンスを生成
		CLaunchScheduler::m_pSharedScheduler = new CLaunchScheduler();
	}
	//共有インスタンスを返す。
	return CLaunchScheduler::m_pSharedScheduler;
}

//共有インスタンスの破棄
void CLaunchScheduler::removeInstance() {
	//共有インスタンスの削除
	SAFE_DELETE(CLaunchScheduler::m_pSharedScheduler);
}

//デストラクタ
CLaunchScheduler::~CLaunchScheduler() {
	//共有インスタンスの削除
	SAFE_DELETE(this->m_pLauncher);
}

/**
 * @desc	発射台の生成
 * @param	発射台に設定する出撃スケジュールのアドレス
 */
void CLaunchScheduler::createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule) {
	//発射台が存在しなければ
	if (this->m_pLauncher == NULL) {
		//発射台を生成
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}
}

/**
 * @desc	キャラクターの出撃
 * @param	取り付けるレイヤー
 */
void CLaunchScheduler::launchCharacter(cocos2d::Layer* pLayer) {

	//スケジューラに取り付けられている起動ができるトリガー全てを起動する
	std::shared_ptr<CLauncher::CLaunchTriggerIterator>itr = this->m_pLauncher->iterator();
	//次の起動可能な出撃トリガーがあるかどうかをチェック
	while (itr->hasNext() == true) {
		//起動可能な出撃トリガーを取得して出撃トリガーイテレーターを次へ進める
		CLaunchTrigger* pTrigger = itr->next();

		//出撃トリガーを起動してキャラクターを生成し取得
		CCharacter* pChara = pTrigger->action();

		//NULLチェック
		if(pChara != NULL){
			
			//キャラクターをキャラクターの集合体に取り付ける
			CCharacterAggregate::getInstance()->add(pChara);

			//キャラクターをメインレイヤーに取り付ける
			pLayer->addChild(pChara);

			CCLOG("%d", CCharacterAggregate::getInstance()->getSize());
		}
	}
}

