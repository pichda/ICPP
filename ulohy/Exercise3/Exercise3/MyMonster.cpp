#include "MyMonster.h"

MyMonster::MyMonster(int id, int hp, int maxHp, ObstacleType obstType) :
	MyStaticObject(obstType, id), hp(hp), maxHp(maxHp) {

	this->hp = hp;
	this->maxHp = maxHp;

}

int MyMonster::GetHp() const {
	return hp;
}

int MyMonster::GetMaxHp() const {
	return maxHp;
}

void MyMonster::SetHp() {
	this->hp = hp;
}

void MyMonster::SetMaxHp() {
	this->maxHp = maxHp;
}