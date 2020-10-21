#include "MyObject.h"

MyObject::MyObject(int id) {
	this->id = id;
	this->x = x;
	this->y = y;
}

MyObject::~MyObject() {
}

	double MyObject::GetX() const {
		return x;
	}

	double MyObject::GetY() const {
		return y;
	}

	int MyObject::GetId() const {
		return id;
	}

	void MyObject::SetX(double x) {
		this->x = x;
	}

	void MyObject::SetY(double y) {
		this->y = y;
	}
