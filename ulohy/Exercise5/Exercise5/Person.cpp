#include "Person.h"

using namespace Entity;

Entity::Person::Person()
{
}

Person::Person(std::string name, int contactNumber, int id)
{
	this->name = name;
	this->contactNumber = contactNumber;
	this->id = id;
}

Person::~Person()
{
}

std::string Person::GetName() const
{
	return name;
}

int Person::GetContactNumber() const
{
	return contactNumber;
}

int Person::GetId() const
{
	return id;
}