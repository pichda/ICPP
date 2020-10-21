#include "MyObject.h"
#include "MyMoveAbleObject.h"
#include "MyStaticObject.h"
#include "ObstacleType.h"
#include "MyGame.h"

#include <iostream>

int main(int argc, char** argv) {

	MyObject obj1 = MyObject(1);
	MyStaticObject staticObj = MyStaticObject(ObstacleType::SmallFlower, 2);
	staticObj.SetX(10);
	staticObj.SetY(10);
	MyMoveableObject moveObj = MyMoveableObject(10, 1);
	moveObj.SetX(90);
	moveObj.SetY(90);


	MyGame game = MyGame();
	game.insertNewObject(&staticObj);
	game.insertNewObject(&moveObj);

	std::cout << "Id hledaneho je: " << game.findMoveableObjectsInArea(80,80,5)[0]->GetId() << std::endl;

	//std::cout << "Id of staticObj: " << staticObj.GetId();
	//std::cout << "Id hledaneho je: " << game.findIdOfStaticObjects(0, 11, 0, 11)[0] << std::endl;

	return 0;												  
}