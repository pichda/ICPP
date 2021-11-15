#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <ostream>
#include <istream>

struct Address {
private:
	std::string _ulice;
	std::string _mesto;
	unsigned int _psc;

public:
	Address();
	Address(std::string ulice, std::string mesto, unsigned int psc);
	~Address();
	friend std::ostream& operator<<(std::ostream& os, const Address& obj);
	friend std::istream& operator>>(std::istream& is, Address& obj);
};
#endif // !ADDRESS_H
