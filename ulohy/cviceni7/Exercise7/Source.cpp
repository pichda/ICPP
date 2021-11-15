#include "Person.h"
#include<fstream>
#include<iostream>
#include<sstream>

Person* loadPeople() {
	std::ifstream soubor("data.dat");
	char oddelovac = ';';
	std::string radek, tmp;

	if (soubor.good()) {
		std::getline(soubor, radek); // vezmi prvni radek
		int size = std::stoi(radek); // uloz velikost
		Person* pole = new Person[size];

		std::string tmp;
		for (int i = 0; i < size; i++)
		{
			std::string jmeno, prijmeni, ulice, mesto;
			int den, mesic, rok, psc;

			std::getline(soubor, radek);
			std::stringstream ss(radek);

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> jmeno;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> prijmeni;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> den;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> mesic;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> rok;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> ulice;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> mesto;

			std::getline(ss, tmp, oddelovac);
			std::istringstream(tmp) >> psc;

			Address adresa = Address(ulice, mesto, psc);
			Date datum = Date(den, mesic, rok);
			pole[i] = Person(jmeno, prijmeni, adresa, datum);
		}
		soubor.close();
		return pole;
	}
	else {
		std::cout << "File can't be opened.";
		return nullptr;
	}
}

void writePeopleToFile() {

	int size = 3;
	Person* pole = new Person[size];

	Address adress = Address(std::string("miru 3"), std::string("Chrudim"), 11111);
	Date date = Date();
	Person p1 = Person(std::string("Daniel"), std::string("Novak"), adress, date);
	Person p2 = Person(std::string("Milan"), std::string("Novak"), adress, date);
	Person p3 = Person(std::string("Petr"), std::string("Novak"), adress, date);

	pole[0] = p1;
	pole[1] = p2;
	pole[2] = p3;

	std::ofstream soubor("data.dat");
	if (soubor.is_open()) {
		soubor << size << std::endl;
		for (int i = 0; i < 3; i++) {
			soubor << pole[i];
		}
		soubor.close();
	}
	else {
		std::cout << "File can't be opened.";
		exit(1);
	}
	delete[] pole;
}

int main(int argc, char** argv)
{
	writePeopleToFile();
	Person* poleOsob;
	poleOsob = loadPeople();

	if (poleOsob != nullptr) {
		for (int i = 0; i < 3; i++)
		{
			std::cout << poleOsob[i];
		}
	}
	delete[] poleOsob;
	return 0;
}