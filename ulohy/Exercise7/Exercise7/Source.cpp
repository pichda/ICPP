#include "Person.h"
#include<fstream>
#include<iostream>

void loadPeople(Person* array) {
	std::ifstream inf("data.dat", std::ios::in, std::ios::binary);

	if (inf.is_open()) {
		//	for (int i = 0; i < 3; i++) {
		inf.read((char*)array, 3 * sizeof(Person));
		//	}
		inf.close();
	}
	else {
		std::cout << "File can't be opened.";
		exit(1);
	}
}

void writePeopleToFile() {
	Person* arr = new Person[3];

	Address adress = Address(std::string("miru 3"), std::string("Chrudim"), 11111);
	Date date = Date();
	Person p1 = Person(std::string("Daniel"), std::string("Novak"), adress, date);
	Person p2 = Person(std::string("Milan"), std::string("Novak"), adress, date);
	Person p3 = Person(std::string("Petr"), std::string("Novak"), adress, date);

	arr[0] = p1;
	arr[1] = p2;
	arr[2] = p3;

	std::ofstream wf("data.dat", std::ios::out, std::ios::binary);
	if (wf.is_open()) {
		for (int i = 0; i < 3; i++) {
			wf.write((char*)&arr[i], sizeof(Person));
		}
		wf.close();
	}
	else {
		std::cout << "File can't be opened.";
		exit(1);
	}
	delete[] arr;
}

int main(int argc, char** argv)
{
	writePeopleToFile();
	Person* arr2;
	arr2 = new Person[3];
	loadPeople(arr2);

	for (int i = 0; i < 3; i++)
	{
		std::cout << arr2[i] << std::endl;
	}
	return 0;
}