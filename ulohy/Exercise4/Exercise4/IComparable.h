#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
#include "IObject.h"

class IComparable : public IObject {

public:
	virtual ~IComparable();
	virtual int CompareTo(IComparable* obj) const = 0;
};

#endif