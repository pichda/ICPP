#pragma once
#ifndef TIME_H
#define TIME_H

#include "IObject.h"
#include <string.h>
#include "IComparable.h"

namespace Utils {
	struct Time : IComparable {
	private:
		int _hours;
		int _minutes;
		int _seconds;
		int _miliseconds;

	public:
		Time(int hours, int minutes, int seconds, int miliseconds);
		~Time();
		int CompareTo(IComparable* obj) const override;
		std::string ToString() const override;
	};
}

#endif