#include "Date.h"
#include <stdexcept>

Date::Date()
{
	_den = 1;
	_mesic = 1;
	_rok = 1970;
}

Date::Date(int den, int mesic, int rok)
{
	
	if (den <= 0 || den > 31) {
		throw std::invalid_argument("invalide date");
	}

	if (den > 28 && mesic == 2) {
		if (((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0)) {
			if (den > 29) {
				throw std::invalid_argument("invalide date");
			}
		}
		else {
			throw std::invalid_argument("invalide date");
		}
	}

	if (den > 30 && mesic == 4 && mesic == 6 && mesic == 9 && mesic == 11) {
		throw std::invalid_argument("invalide date");
	}

	this->_den = den;
	this->_mesic = mesic;
	this->_rok = rok;
}

Date::~Date()
{
}

int Date::GetDay() const
{
	return _den;
}

int Date::GetMonth() const
{
	return _mesic;
}

int Date::GetYear() const
{
	return _rok;
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
	os << obj._den << ";" << obj._mesic << ";" << obj._rok;
	return os;
}

std::istream& operator>>(std::istream& is, Date& obj)
{
	is >> obj._den >> obj._mesic >> obj._rok;
	return is;
}