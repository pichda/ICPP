#include "Address.h"
#include <stdexcept>

Address::Address()
{
	_ulice = "";
	_mesto = "";
	_psc = 00000;
}

Address::Address(std::string ulice, std::string mesto, unsigned int psc)
{
	if (psc > 99999 || psc < 0) {
		throw std::invalid_argument("wrong range for zipcode");
	}

	// vyuzit metodu compare() nebo ==?
	if (ulice == "" || mesto == "") {
		throw std::invalid_argument("Enter atleast one character");
	}

	this->_ulice = ulice;
	this->_mesto = mesto;
	this->_psc = psc;
}

Address::~Address()
{
}

std::ostream& operator<<(std::ostream& os, const Address& obj)
{
	os << obj._ulice << ";" << obj._mesto << ";" << obj._psc;
	return os;
}

std::istream& operator>>(std::istream& is, Address& obj)
{
	is >> obj._mesto >> obj._ulice >> obj._psc;
	return is;
}