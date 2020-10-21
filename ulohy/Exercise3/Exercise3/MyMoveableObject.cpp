#define _USE_MATH_DEFINES
#include "MyMoveableObject.h"
#include <cmath>
#include <stdexcept>

MyMoveableObject::MyMoveableObject(int id, double angl) 
	: MyObject(id), angle(angl) {
	this->angle = angl;
}

double MyMoveableObject::GetAngle() const{
	return angle;
}

void MyMoveableObject::SetAngle(double angle) {
	if (angle < 0 || angle > 2 * M_PI) {
		throw std::out_of_range{ "uhel natoceni" };
	}
	this->angle = angle;
}