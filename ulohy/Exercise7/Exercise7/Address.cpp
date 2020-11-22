#include "Address.h"
#include <stdexcept>

Address::Address()
{
	_street = "";
	_city = "";
	_zipCode = 00000;
}

Address::Address(std::string _street, std::string _city, unsigned int _zipCode)
{
	if (_zipCode > 99999 || _zipCode < 0) {
		throw std::invalid_argument("wrong range for zipcode");
	}

	// vyuzit metodu compare() nebo ==?
	if (_street == "" || _city == "") {
		throw std::invalid_argument("Enter atleast one character");
	}

	this->_street = _street;
	this->_city = _city;
	this->_zipCode = _zipCode;
}

Address::~Address()
{
}

std::ostream& operator<<(std::ostream& os, const Address& obj)
{
	os << obj._street << ", " << obj._city << ", " << obj._zipCode;
	return os;
}

std::istream& operator>>(std::istream& is, Address& obj)
{
	is >> obj._city >> obj._street >> obj._zipCode;
	return is;
}