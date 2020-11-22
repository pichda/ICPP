#include "Date.h"
#include <stdexcept>

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1970;
}

Date::Date(int _day, int _month, int _year)
{
	// check if the date is valid
	if (_day <= 0 || _day > 31) {
		throw std::invalid_argument("invalide date");
	}

	if (_day > 28 && _month == 2) {
		// https://www.tutorialspoint.com/learn_c_by_examples/leap_year_program_in_c.htm
		if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0)) {
			if (_day > 29) {
				throw std::invalid_argument("invalide date");
			}
		}
		else {
			throw std::invalid_argument("invalide date");
		}
	}

	if (_day > 30 && _month == 4 && _month == 6 && _month == 9 && _month == 11) {
		throw std::invalid_argument("invalide date");
	}

	this->_day = _day;
	this->_month = _month;
	this->_year = _year;
}

Date::~Date()
{
}

int Date::GetDay() const
{
	return _day;
}

int Date::GetMonth() const
{
	return _month;
}

int Date::GetYear() const
{
	return _year;
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
	os << obj._day << "." << obj._month << "." << obj._year;
	return os;
}

std::istream& operator>>(std::istream& is, Date& obj)
{
	is >> obj._day >> obj._month >> obj._year;
	return is;
}