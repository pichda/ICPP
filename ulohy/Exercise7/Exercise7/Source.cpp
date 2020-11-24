#include "Person.h"
#include<fstream>
#include<iostream>

Person* loadPeople() {
	std::ifstream inf("data.dat", std::ios::in, std::ios::binary);

	if (inf.is_open()) {
		int size = 0;
		inf.read((char*)&size, 1 * sizeof(int));
		Person* array = new Person[size];
		inf.read((char*)array, size * sizeof(Person));
		inf.close();
		return array;
	}
	else {
		std::cout << "File can't be opened.";
		return nullptr;
	}
}

void writePeopleToFile() {
	int size = 3;
	Person* arr = new Person[size];

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
		wf.write((char*)&size, sizeof(int));
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
	arr2 = loadPeople();

	if (arr2 != nullptr) {
		for (int i = 0; i < 3; i++)
		{
			std::cout << arr2[i] << std::endl;
		}
	}
	return 0;
}