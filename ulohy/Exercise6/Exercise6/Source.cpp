#include "ExpandingArray.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	//ExpandingArray <std::string> arr;
	ExpandingArray <std::string> arr("parametricky konst");

	for (size_t i = 1; i < arr.GetArraySize(); i++)
	{
		std::cout << arr.GetE(i) << "\n";
	}

	// pridani 11 prvku
	for (size_t i = 0; i < 11; i++)
	{
		arr.Add("ahoj");
	}
	

	std::cout << arr.GetE(1) << std::endl;
	std::cout << arr.GetEAdress(7) << std::endl;
	std::cout << arr.GetElementCount();
	std::cout << arr.GetArraySize();
	return 0;
}