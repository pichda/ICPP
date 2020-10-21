#pragma once
#ifndef MYSTATIC_OBJECT_H
#define MYSTATIC_OBJECT_H

#include "MyObject.h"
#include "ObstacleType.h"

class MyStaticObject: public MyObject {

	ObstacleType obstacleType;

public:	

	MyStaticObject(ObstacleType obstType, int id);

	ObstacleType GetObstacleType() const;
};

#endif // !MYSTATIC_OBJECT_H