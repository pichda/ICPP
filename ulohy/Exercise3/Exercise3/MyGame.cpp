#include "MyGame.h"
#include "MyStaticObject.h"
#include "MyMoveableObject.h"

MyGame::MyGame() {

		this->arrSize = 10;
		this->objects = new MyObject* [arrSize];
		this->objCounter = 0;

}

MyGame::~MyGame() {

	delete[] objects;

}

void MyGame::insertNewObject(MyObject* obj) { // kontrola
	
	if (objCounter == arrSize) {
		MyObject** newArr = new MyObject * [arrSize + 10];

		for (int i = 0; i < arrSize; i++)
		{
			newArr[i] = objects[i];
		}
		arrSize += 10;
		delete[] objects;
		objects = newArr;
	}

	objects[objCounter++] = obj;

}

int* MyGame::findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax){

		int foundCounter = 0;
		for (int i = 0; i < objCounter; i++)
		{
			MyStaticObject* staticObj = dynamic_cast<MyStaticObject*>(objects[i]);
			if (staticObj) {
				if (staticObj->GetX() >= xmin && staticObj->GetX() < xmax && staticObj->GetY() >= ymin && staticObj->GetY() < ymax) {
					foundCounter++;
				}
			}
		}

		int* arrIds = new int[foundCounter + 1];
		arrIds[foundCounter] = -1;

		int j = 0;
		for (int i = 0; i < objCounter; i++)
		{
			MyStaticObject* staticObj = dynamic_cast<MyStaticObject*>(objects[i]);
			if (staticObj) {
				if (staticObj->GetX() >= xmin && staticObj->GetX() < xmax && staticObj->GetY() >= ymin && staticObj->GetY() < ymax) {
					arrIds[j++] = staticObj->GetId();
				}
			}
		}
		return arrIds;

}

MyMoveableObject** MyGame::findMoveableObjectsInArea(double x, double y, double r)
{
	int foundCounter = 0;
	for (int i = 0; i < objCounter; i++)
	{
		MyMoveableObject* moveObj = dynamic_cast<MyMoveableObject*>(objects[i]);
		if (moveObj) {
			if (moveObj->GetX() < x+r && moveObj->GetX() > x-r && moveObj->GetY() < y+r && moveObj->GetY() > y - r) {
				foundCounter++;
			}
		}
	}

	MyMoveableObject** moveObjs = new MyMoveableObject*[foundCounter + 1];
	moveObjs[foundCounter] = nullptr;

	int j = 0;
	for (int i = 0; i < objCounter; i++)
	{
		MyMoveableObject* moveObj = dynamic_cast<MyMoveableObject*>(objects[i]);
		if (moveObj) {
			if (moveObj->GetX() < x + r && moveObj->GetX() > x - r && moveObj->GetY() < y + r && moveObj->GetY() > y - r) {
				moveObjs[j++] = moveObj;
			}
		}
	}
	return moveObjs;
}

MyMoveableObject** MyGame::findMoveableObjectsInAreaAndAngle(double x, double y, double r, double amin, double amax)
{
	int foundCounter = 0;
	for (int i = 0; i < objCounter; i++)
	{
		MyMoveableObject* moveObj = dynamic_cast<MyMoveableObject*>(objects[i]);
		if (moveObj) {
			if (moveObj->GetX() < x + r && moveObj->GetX() > x - r && moveObj->GetY() < y + r && moveObj->GetY() > y - r) {
				foundCounter++;
			}
		}
	}

	MyMoveableObject** moveObjs = new MyMoveableObject * [foundCounter + 1];
	moveObjs[foundCounter] = nullptr;

	int j = 0;
	for (int i = 0; i < objCounter; i++)
	{
		MyMoveableObject* moveObj = dynamic_cast<MyMoveableObject*>(objects[i]);
		if (moveObj) {
			if (moveObj->GetX() < x + r && moveObj->GetX() > x - r 
				&& moveObj->GetY() < y + r && moveObj->GetY() > y - r 
				&& moveObj->GetAngle()>amin && moveObj->GetAngle() < amax) {

				moveObjs[j++] = moveObj;

			}
		}
	}
	return moveObjs;
}

/*

void resize() {
    size_t newSize = size * 2;
    int* newArr = new int[newSize];

    memcpy( newArr, arr, size * sizeof(int) );

    size = newSize;
    delete [] arr;
    arr = newArr;
}
// https://stackoverflow.com/questions/39437153/
*/