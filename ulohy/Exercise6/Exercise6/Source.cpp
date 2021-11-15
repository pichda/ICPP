#include "RoustouciKontejner.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	//ExpandingArray <std::string> arr;
	RoustouciKontejner <std::string> arr("parametricky konst");

	for (int i = 1; i < arr.DejVelikostPole(); i++)
	{
		std::cout << arr.Dej(i) << "\n";
	}

	// pridani 11 prvku
	for (int i = 0; i < 11; i++)
	{
		arr.Pridej("ahoj");
	}

	std::cout << arr.Dej(1) << std::endl;
	std::cout << arr.Dej(7) << std::endl;
	std::cout << arr.DejPocetPrvku() << std::endl;
	std::cout << arr.DejVelikostPole() << std::endl;

	arr.Realokuj(30, "realokace");
	std::cout << arr.Dej(17) << std::endl;

	arr.Realokuj(2, "realokace2");
	std::cout << arr.Dej(1) << std::endl;
	return 0;
}