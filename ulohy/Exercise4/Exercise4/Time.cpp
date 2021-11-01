#include "Time.h"
#include <stdexcept> 

using namespace Utils;

Time::Time(int hours, int minutes, int seconds, int miliseconds)
{
	if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
		this->_hours = hours;
		this->_minutes = minutes;
		this->_seconds = seconds;
		this->_miliseconds = miliseconds;
	}
	else {
		throw new std::invalid_argument("Zadej HH(0-23):MM(0-59):SS(0-59)::MS(0-999)");
	}
}

Time::~Time()
{
}

int Time::CompareTo(IComparable* right) const
{
	try
	{
		// pokud je cas roven, vraci 0
		if (_hours == ((Time*)right)->_hours && _minutes == ((Time*)right)->_minutes && _seconds == ((Time*)right)->_seconds && _miliseconds==((Time*)right)->_miliseconds) {
			return 0;
		}

		else if (_hours <= ((Time*)right)->_hours) {  // pokud vlevo hodiny jsou vetsi nebo rovno
			if (_hours == ((Time*)right)->_hours) {  // tak zkontroluji, jestli jsou si rovny, pokud ano, tak kontroluji minuty, sekundy, milisekundy
				if (_minutes <= ((Time*)right)->_minutes) {
					if (_minutes == ((Time*)right)->_minutes) {
						if (_seconds <= ((Time*)right)->_seconds) { 
							if (_seconds == ((Time*)right)->_seconds) {
								if (_miliseconds < ((Time*)right)->_miliseconds) { // pokud je mensi, tak vratí -1, jinak vyskoci 
									return -1;									  // z else if a pokracuje do else, kde vraci ze je vetsi (1)
								}
							}
							else {  // sekundy se nerovnaji, tak musi byt mensi
								return -1;
							}
						}
					}
					else { // minuty se nerovnaji, tak musi byt mensi
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
	catch (const std::exception&)
	{
		throw "invalid comparison";
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
		str += "0" + std::to_string(_seconds) + ":";
	}
	else {
		str += std::to_string(_seconds) + ":";
	}

	if (_miliseconds < 100) {
		str += "0" + std::to_string(_miliseconds);
	}
	else if (_miliseconds < 10) {
		str += "00" + std::to_string(_miliseconds);
	}
	else {
		str += std::to_string(_miliseconds);
	}

	return str;
}