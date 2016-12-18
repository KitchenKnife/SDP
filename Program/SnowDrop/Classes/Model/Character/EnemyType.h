/*
* EnemyType.h
*
*	2016/11/11	Yamasaki
*
*/
#pragma once

#include"Character.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


/*
	@ 種族で敵の絵が決まる
	@ 行動タイプで移動アニメーションが変わる
	@ 武器で攻撃アニメーションが変わる
*/

/*

//===========================================
// 敵の種族タイプ
//===========================================
class CEnemyRaceType {
public:
	virtual ~CEnemyRaceType(){}
	// 攻撃
	virtual void attack() = 0;
};

// クリボー
class CKuribo :public CEnemyRaceType {

	// 攻撃
	virtual void attack()override {
		
	};
};

// パタパタ
class CFly :public CEnemyRaceType {

	// 攻撃
	virtual void attack()override {

	};
};

// テレサ
class CTeresa :public CEnemyRaceType {

	// 攻撃
	virtual void attack()override {

	};
};



//===========================================
// 敵の行動タイプ
//===========================================
// 追いかける
class CChase : public CEnemyCharacter {
public:

	// 行動
	virtual void action() override{

	}
};


// 空から追いかける
class CFryingChase : public CEnemyCharacter {
public:

	// 行動
	virtual void action() override {

	}
};

// ホールド
class CHold : public CEnemyCharacter {
public:

	// 行動
	virtual void action() override {

	}
};



//===========================================
// 敵の武器タイプ
//===========================================
class CWeaponType {
public:
	~CWeaponType(){}

	// 武器攻撃
	virtual void weaponAttack() = 0;
};


// ナイフ（振りかざす系）
class CKnife : public CWeaponType {
public:
	virtual void weaponAttack() override{

	}

};


// 飛び道具
class CThrow : public CWeaponType {
public:

	virtual void weaponAttack() override {

	}

};


*/

