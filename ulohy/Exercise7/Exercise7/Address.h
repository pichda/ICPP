#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <ostream>
#include <istream>

struct Address {
private:
	std::string _street;
	std::string _city;
	unsigned int _zipCode;

public:
	Address();
	Address(std::string _street, std::string _city, unsigned int _zipCode);
	~Address();
	friend std::ostream& operator<<(std::ostream& os, const Address& obj);
	friend std::istream& operator>>(std::istream& is, Address& obj);
};
#endif // !ADDRESS_H
