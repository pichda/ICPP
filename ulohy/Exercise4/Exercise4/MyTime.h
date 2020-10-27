#pragma once
#ifndef MYTIME_H
#define MYTIME_H

#include "IObject.h"
#include <string.h>
#include "IComparable.h"

struct MyTime : IComparable {
private:
	int _hours;
	int _minutes;
	int _seconds;

public:
	MyTime(int hours, int minutes, int seconds);
	~MyTime();
	int CompareTo(IComparable* obj) const override;
	std::string ToString() const override;
};



#endif