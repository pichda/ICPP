#include "MyStaticObject.h"
#include "ObstacleType.h"

MyStaticObject::MyStaticObject(ObstacleType obstType, int id)
	: MyObject(id), obstacleType(obstType) {
	this->obstacleType = obstType;
}

ObstacleType MyStaticObject::GetObstacleType() const {
	return obstacleType;
}