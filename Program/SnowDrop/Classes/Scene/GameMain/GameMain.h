/*
* GameMain.h
*
*	2016/11/10	Osumi
*
*/

#pragma once

//=========================================================================
//	追加のインクルードはここから
//=========================================================================
#include "Data/LaunchTrigger/LaunchTrigger.h"
#include "cocos2d.h"
#include "Constants.h"
#include <vector>

/*
 *	ゲームメインレイヤー
 *
 *		ゲームのメインとなるレイヤー
 *		初めはこの部分に全てを書いていく
 *
 */
class CGameMain : public cocos2d::Layer
{
public:
	//=========================================================================
	//	ここからは理解出来るまでは変更禁止
	//=========================================================================

	// デストラクタ
	~CGameMain() ;
	
	/**
	 *	@desc	シーンの生成
	 *	@return	CMain レイヤーを内包したシーンクラスインスタンス
	 *	@tips	静的メンバ関数
	 */
    static cocos2d::Scene* createScene() ;
	
	/*
	 *	@desc	シーン生成時に初期化関数を処理
	 *			初期化関数失敗時は NULL を返す
	 */
    CREATE_FUNC( CGameMain );
	
	/**
	 *	@desc	キーボードのキーを押した際のイベント
	 *	@param	キーコード
	 *	@param	イベント
	 */
	virtual void onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) override ;
	
	/**
	 *	@desc	キーボードのキーを離した際のイベント
	 *	@param	キーコード
	 *	@param	イベント
	 */
	virtual void onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event ) override ;
	
	/**
	 *	@desc	初期化
	 *	@return	true...成功	false...失敗
	 */
    virtual bool init() override ;
	
	/*
	* @desc 画面スクロール
	* @tips 今回は強制スクロールではなくキャラクターの移動による画面のスクロールとなる
	*/
	void scroll();

	/**
	 *	@desc	更新処理
	 *	@param	経過時間
	 */
	virtual void update( float deltaTime_ ) override ;

	/**
	* @desc		タイトルに遷移
	* @param	タイトルレイヤーのインスタンス
	* @tips		スタートボタンが押された時に呼び出される
	*/
	void callbackChangeGameOver(cocos2d::Ref* pSender);
	
	//=========================================================================
	//	ここまでは理解出来るまでは変更禁止
	//=========================================================================
	
public:

	//=========================================================================
	//	メンバ宣言
	//		ゲームメイン内で使用するメンバはここ以降に記述していく
	//=========================================================================
	
	//メインレイヤー
	Layer* m_pMainLayer = NULL;

	//UIレイヤー
	Layer* m_pUILayer = NULL;

	//キャラクターの集まり
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//出撃スケジュール
	std::vector<CLaunchTrigger*>* m_pLaunchSchedule = NULL;

	//背景
	cocos2d::Sprite* m_pBackGround = NULL;
	cocos2d::Sprite* m_pHrizon = NULL;

	// ギミック
	
	/**
	 *	@desc	チェックと取り外し処理 ( 単体 )
	 *	@tips	有効フラグが false のインスタンスをレイヤーから取り外す
	 */
	template <typename Ty>
	void checkAndRemove( Ty* pChara ) {
		
		if ( pChara->m_activeFlag == false ) {
			pChara->removeFromParent() ;
		}
	}
	
	/**
	 *	@desc	チェックと取り外し処理 ( 複数 )
	 *	@tips	有効フラグが false のインスタンスをレイヤーと std::vector から取り外す
	 */
	template <typename Ty>
	void checkAndRemove( std::vector<Ty*>* pCharas ) {
	
		// ローカル変数の型のテンプレート引数の指定として
		// テンプレート引数を指定する場合は typename 指定をつけなければならない
		typename std::vector<Ty*>::iterator itr = pCharas->begin() ;
		while( itr != pCharas->end() ) {
		
			if ( (*itr)->m_activeFlag == false ) {
			
				(*itr)->removeFromParent() ;
				itr = pCharas->erase( itr ) ;
				
			} else {
				itr++ ;
			}
		}
	}

	/**
	*	@desc	チェックと解放 ( 複数 )
	*	@tips	有効フラグが false のインスタンスを解放しレイヤーと std::vector から取り外す
	*/
	template <typename Ty>
	void checkAndDelete(std::vector<Ty*>* pVector) {

		// ローカル変数の型のテンプレート引数の指定として
		// テンプレート引数を指定する場合は typename 指定をつけなければならない
		typename std::vector<Ty*>::iterator itr = pVector->begin();
		while (itr != pVector->end()) {

			if ((*itr)->m_activeFlag == false) {
				SAFE_DELETE((*itr));
				itr = pVector->erase(itr);
			}
			else {
				itr++;
			}
		}
	}



} ;



