#include "Math.h"
#include "Model/Character/Character.h"
#include "Model/Character/Enemycharacter/EnemyCharacter.h"

//コンストラクタ
CCustomMath::CCustomMath(){}

//共有インスタンス
CCustomMath* CCustomMath::m_pSharedCustomMath = NULL;

//デストラクタ
CCustomMath::~CCustomMath(){}

//インスタンスの取得
CCustomMath* CCustomMath::getInstance() {

	if (CCustomMath::m_pSharedCustomMath == NULL) {
		CCustomMath::m_pSharedCustomMath = new CCustomMath();
	}

	return CCustomMath::m_pSharedCustomMath;
}

//インスタンスの破棄
void CCustomMath::removeInstance() {
	SAFE_DELETE(CCustomMath::m_pSharedCustomMath);
}

/*
* @desc 2点間の距離を求める式
* @param 点1
* @param 点2
* @return 点1と点2の距離
*/
float CCustomMath::length(cocos2d::Point pt1, cocos2d::Point pt2) {

	float length;
	length = sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));

	return length;
}

/*
* @desc 2体のキャラの距離を求める式
* @param　キャラ1
* @param　キャラ2
* @return キャラ1とキャラ2の距離
*/
float CCustomMath::lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2) {

	float length = this->length(pChara1->m_pMove->m_pos, pChara2->m_pMove->m_pos);

	return length;
}

/*
* @desc ターゲットの選択
* @return ターゲットが決まったかどうか　true...決まった
* @tips 少女と騎士で敵に近い方の距離を導き
*　　　 近い方が追跡範囲にならターゲットに設定
*/
bool CCustomMath::seachAndSelectTarget(CCharacter* pChara) {
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//敵と少年の距離
	float lemgthFromBoy = this->lengthBitweenChara(pChara, pBoy);
	//敵と少女の距離
	float lemgthFromGirl = this->lengthBitweenChara(pChara, pGirl);

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//近い方が敵の追跡範囲内なら、近い方を敵のターゲットに設定
	/*
	if ((lemgthFromBoy < lemgthFromGirl) && lemgthFromBoy <= pEne->m_chaseRange) {
		pEne->setTarget(pBoy);
		return true;
	}
	else if ((lemgthFromBoy >= lemgthFromGirl) && lemgthFromGirl <= pEne->m_chaseRange) {
		pEne->setTarget(pGirl);
		return true;
	}
	*/

	return false;
}

/*
* @desc ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
* @param アクションを行うキャラクター
* @param ターゲットのタイプ
*/
void CCustomMath::checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//優先ターゲットが両方でなければ
	if (type != TARGET_TYPE::BOTH) {
		/*
		//ターゲットとの距離が追跡範囲内なら
		if (pEne->m_chaseRange >= this->lengthBitweenChara(pEne, pEne->m_currentTarget)) {
			//動作を停止
			this->stop();
			//敵を追跡状態に移行
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
		*/
	}
	//両方なら
	else {
		/*
		//ターゲットの検索と設定
		if (seachAndSelectTarget(pEne) == true) {
			//動作を停止
			this->stop();
			//敵を追跡状態に移行
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
		*/
	}
}

/*
* @desc キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
* @param アクションを行うキャラクター
* @param 目標地点の座標
*/
void CCustomMath::normalizeVel_X(CCharacter* pChara, cocos2d::Point pt) {

	float nomalizevelX = (pt.x - pChara->m_pMove->m_pos.x) / abs(pt.x - pChara->m_pMove->m_pos.x);

	pChara->m_pMove->m_vel.x = pChara->m_status.getSpeed()*nomalizevelX;
}

/*
* @desc 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
* @param アクションを行うキャラクター
* @param 目標地点の座標
*/
void CCustomMath::normalizeVel(CCharacter* pChara, cocos2d::Point pt) {

	//ターゲットまでの距離を求める
	float length = this->length(pChara->m_pMove->m_pos, pt);
	float lengthX = pt.x - pChara->m_pMove->m_pos.x;
	float lengthY = pt.y - pChara->m_pMove->m_pos.y;

	//キャラクターのスピードに各成分の正規化ベクトルをかける
	float velX = (pChara->m_status.getSpeed()*lengthX) / length;
	float velY = (pChara->m_status.getSpeed()*lengthY) / length;

	pChara->m_pMove->m_vel.set(velX, velY);
}



