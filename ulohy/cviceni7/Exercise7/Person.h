#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "Address.h"
#include <string>
#include <istream>
#include <ostream>

struct Person {
private:
	std::string _jmeno;
	std::string _prijmeni;
	Address _trvaleBydliste;
	Date _datumNarozeni;

public:
	Person();
	Person(std::string jmeno, std::string prijmeni, Address trvaleBydliste, Date datumNarozeni);
	~Person();

	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
};
#endif // !PERSON_H
