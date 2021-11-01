#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H

#include <string>

class IObject {

public:
	IObject();
	virtual ~IObject();
	virtual std::string ToString() const = 0;

};

#endif