#include "Person.h"

Person::Person()
{
	_name = "";
	_surname = "";
	domicile = Address();
	_birthDate = Date();
}

Person::Person(std::string _name, std::string _surname, Address domicile, Date _birthDate)
{
	if (_name == "" || _surname == "") {
		throw std::invalid_argument("Enter atleast one character");
	}

	this->_name = _name;
	this->_surname = _surname;
	this->domicile = domicile;
	this->_birthDate = _birthDate;
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	os << obj._name << " " << obj._surname << " | " << obj._birthDate << " | " << obj.domicile;
	return os;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
	is >> obj._name >> obj._surname >> obj.domicile >> obj._birthDate;
	return is;
}