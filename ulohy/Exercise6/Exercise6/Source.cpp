#include "ExpandingArray.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	ExpandingArray <std::string> arr;
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("7777");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");
	arr.Add("ahoj");

	std::cout << arr.GetE(1) << std::endl;
	std::cout << arr.GetEAdress(7) << std::endl;
	std::cout << arr.GetElementCount();
	return 0;
}