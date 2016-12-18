
#include "LaunchTrigger.h"
#include "Model/Character/Character.h"
#include "Model/Character/EnemyCharacter/EnemyFactory.h"
#include "Model/Character/GimmickFactory.h"

//=======================================
//
//  敵出撃トリガー
//		敵出撃データをトリガーとして敵出撃というイベントを実行させる
//
//=======================================
//デストラクタ
CEnemyLaunchTrigger::~CEnemyLaunchTrigger() {
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
* @desc		イベントを行えるかどうか
* @retrun	true...イベント実行可
*/
bool CEnemyLaunchTrigger::isTrigger(){
	if(this->m_pLaunchdata == NULL){
		return false;
	}
	return true;
}

/**
* @desc		設定されている敵出撃データを元に敵を生成する
*			トリガーを元にイベントを実行
*/
CCharacter* CEnemyLaunchTrigger::action(){

	//敵を生成
	CCharacter* pEnemyCharacter = (CCharacter*)CEnemyFactoryManager::getInstance()->create(
		this->m_pLaunchdata->m_pos,
		(int)this->m_pLaunchdata->m_type
	);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	return pEnemyCharacter;
}

//=======================================
//
//  弾発射トリガー
//		弾発射データをトリガーとして弾発射というイベントを実行させる
//
//=======================================


//=======================================
//
//  ギミック生成トリガー
//
//=======================================
//デストラクタ
CGimmickLaunchTrigger::~CGimmickLaunchTrigger() {
	SAFE_DELETE(this->m_pLaunchdata);
}

/**
* @desc		イベントを行えるかどうか
* @retrun	true...イベント実行可
*/
bool CGimmickLaunchTrigger::isTrigger() {
	if (this->m_pLaunchdata == NULL) {
		return false;
	}
	return true;
}

/**
* @desc		設定されている敵出撃データを元に敵を生成する
*			トリガーを元にイベントを実行
*/
CCharacter* CGimmickLaunchTrigger::action() {

	//弾を生成
	CCharacter* pGimmickCharacter = (CCharacter*)CGimmickFactoryManager::getInstance()->create(
		(int)this->m_pLaunchdata->m_type,
		this->m_pLaunchdata->m_pos
	);

	//発射し終わったかどうかのフラグを立てる
	this->m_activeFlag = false;

	return pGimmickCharacter;
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

	if (CLaunchScheduler::m_pSharedScheduler == NULL) {
		CLaunchScheduler::m_pSharedScheduler = new CLaunchScheduler();
	}
	return CLaunchScheduler::m_pSharedScheduler;
}

//共有インスタンスの破棄
void CLaunchScheduler::removeInstance() {
	SAFE_DELETE(CLaunchScheduler::m_pSharedScheduler);
}

//デストラクタ
CLaunchScheduler::~CLaunchScheduler() {
	SAFE_DELETE(this->m_pLauncher);
}

/**
* @desc		発射台の生成
* @param	発射台に設定する出撃スケジュールのアドレス
*/
void CLaunchScheduler::createLauncher(std::vector<CLaunchTrigger*>* pLaunchSchedule) {

	if (this->m_pLauncher == NULL) {
		this->m_pLauncher = new CLauncher(pLaunchSchedule);
	}

}

/**
* @desc		キャラクターの出撃
* @param	取り付けるレイヤー
*/
void CLaunchScheduler::launchCharacter(cocos2d::Layer* pLayer) {

	//スケジューラに取り付けられている起動ができるトリガー全てを起動する
	std::shared_ptr<CLauncher::CLaunchTriggerIterator>itr = this->m_pLauncher->iterator();
	//次の起動可能な出撃トリガーがあるかどうかをチェック
	while (itr->hasNext() == true) {
		//起動可能な出撃トリガーを取得して出撃トリガーイテレーターを次へ進める
		CLaunchTrigger* pTrigger = itr->next();

		//出撃トリガーを起動
		CCharacter* pChara = pTrigger->action();

		//NULLチェック
		if(pChara != NULL){
			
			//キャラクターをキャラクターの集合体に取り付ける
			CCharacterAggregate::getInstance()->add(pChara);

			//キャラクターをメインレイヤーに取り付ける
			pLayer->addChild(pChara);
		}

	}

}

