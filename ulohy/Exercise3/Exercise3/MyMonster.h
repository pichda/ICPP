#pragma once
#ifndef MYMONSTER_H
#define MYMONSTER_H

#include "MyStaticObject.h"
#include "ObstacleType.h"

class MyMonster : public MyStaticObject {

	int hp;
	int maxHp;

public:

	MyMonster(int id, int hp, int maxHp, ObstacleType obstType);


	int GetHp() const;
	int GetMaxHp() const;
	void SetHp();
	void SetMaxHp();
};

#endif // !MYMONSTER_H