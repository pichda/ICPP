#pragma once
#ifndef MYMOVEABLE_OBJECT_H
#define MYMOVEABLE_OBJECT_H

#include "MyObject.h"

class MyMoveableObject : public MyObject {

	double angle;

public:

	MyMoveableObject(int id, double angl);

	double GetAngle() const;
	void SetAngle(double angle);
};

#endif // !MYMOVEABLE_OBJECT_H