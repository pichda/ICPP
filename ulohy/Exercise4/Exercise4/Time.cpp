#include "Time.h"

using namespace Utils;

Time::Time(int hours, int minutes, int seconds)
{
	if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
		this->_hours = hours;
		this->_minutes = minutes;
		this->_seconds = seconds;
	}
	else {
		throw new std::exception("Zadej HH(0-23):MM(0-59):SS(0-59)");
	}
}

Time::~Time()
{
}

int Time::CompareTo(IComparable* time) const
{
	if (_hours == ((Time*)time)->_hours && _minutes == ((Time*)time)->_minutes && _seconds == ((Time*)time)->_seconds) {
		return 0;
	}
	else if (_hours <= ((Time*)time)->_hours) {  // pokud hodiny jsou vetsi nebo rovno
		if (_hours == ((Time*)time)->_hours) {  // tak zkontroluji, jestli jsou si rovny, pokud ano, tak kontroluji minuty, sekundy
			if (_minutes <= ((Time*)time)->_minutes) {
				if (_minutes == ((Time*)time)->_minutes) {
					if (_seconds < ((Time*)time)->_seconds) { // pokud je mensi, tak vratí -1, jinak vyskoci z else if a pokracuje do else, kde vraci ze je vetsi (1)
						return -1;
					}
				}
				else {
					return -1;
				}
			}
		}
		else {  // hodiny se nerovnaji, tak musi byt mensi
			return -1;
		}
	}
	else {
		return 1;
	}
}

std::string Time::ToString() const
{
	std::string str = "";

	if (_hours < 10) {
		str += "0" + std::to_string(_hours) + ":";
	}
	else {
		str += std::to_string(_hours) + ":";
	}

	if (_minutes < 10) {
		str += "0" + std::to_string(_minutes) + ":";
	}
	else {
		str += std::to_string(_minutes) + ":";
	}

	if (_seconds < 10) {
		str += "0" + std::to_string(_seconds);
	}
	else {
		str += std::to_string(_seconds);
	}

	return str;
}