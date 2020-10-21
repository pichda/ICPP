#pragma once
#ifndef MYOBJECT_H
#define MYOBJECT_H

class MyObject {

	int id;
	double x;
	double y;

public:

	MyObject(int id);
	
	virtual ~MyObject();

	double GetX() const;

	double GetY() const;

	int GetId() const;

	void SetX(double x);

	void SetY(double x);
};


#endif // !MYOBJECT_H