#pragma once
#ifndef MYGAME_H
#define MYGAME_H

#include "MyObject.h"
#include "MyMoveableObject.h"

class MyGame {

	MyObject** objects;
	int arrSize;
	int objCounter;

public:

	MyGame();
	~MyGame();

	void insertNewObject(MyObject* obj);
	int* findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MyMoveableObject** findMoveableObjectsInArea(double x, double y, double r);
	MyMoveableObject** findMoveableObjectsInAreaAndAngle(double x, double y, double r, 
		double amin, double amax);

	//void resize(); 

};

#endif // !MYGAME_H