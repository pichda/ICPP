#include "ExpandingArray.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	//ExpandingArray <std::string> arr;
	RoustouciKontejner <std::string> arr("parametricky konst");

	for (size_t i = 1; i < arr.DejVelikostPole(); i++)
	{
		std::cout << arr.Dej(i) << "\n";
	}

	// pridani 11 prvku
	for (size_t i = 0; i < 11; i++)
	{
		arr.Pridej("ahoj");
	}
	

	std::cout << arr.Dej(1) << std::endl;
	std::cout << arr.Dej(7) << std::endl;
	std::cout << arr.DejPocetPrvku();
	std::cout << arr.DejVelikostPole();
	return 0;
}