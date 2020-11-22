#pragma once
#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <istream>

struct Date {
private:
	int _day, _month, _year;
public:
	Date();
	Date(int _day, int _month, int _year);
	~Date();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& obj);
	friend std::istream& operator>>(std::istream& is, Date& obj);
};
#endif // !DATE_H
