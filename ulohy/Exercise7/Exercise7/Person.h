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
	std::string _name;
	std::string _surname;
	Address domicile;
	Date _birthDate;

public:
	Person();
	Person(std::string _name, std::string _surname, Address domicile, Date _birthDate);
	~Person();

	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
};
#endif // !PERSON_H
