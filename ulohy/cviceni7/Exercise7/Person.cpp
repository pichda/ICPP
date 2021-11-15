#include "Person.h"

Person::Person()
{
	_jmeno = "";
	_prijmeni = "";
	_trvaleBydliste = Address();
	_datumNarozeni = Date();
}

Person::Person(std::string jmeno, std::string prijmeni, Address trvaleBydliste, Date datumNarozeni)
{
	if (jmeno == "" || prijmeni == "") {
		throw std::invalid_argument("Enter atleast one character");
	}

	this->_jmeno = jmeno;
	this->_prijmeni = prijmeni;
	this->_trvaleBydliste = trvaleBydliste;
	this->_datumNarozeni = datumNarozeni;
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	os << obj._jmeno << ";" << obj._prijmeni << ";" << obj._datumNarozeni << ";" << obj._trvaleBydliste << ";" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
	is >> obj._jmeno >> obj._prijmeni >> obj._trvaleBydliste >> obj._datumNarozeni;
	return is;
}