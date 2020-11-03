#include "Person.h"
#include "ContactList.h"
#include <iostream>

using namespace Model;
using namespace std;

int main(int argc, char** argv) {
	Person* p1 = new Person("asdf", 777666555, 1);
	Person* p2 = new Person("asdf2", 111222333, 1);
	Person* p3 = new Person("asdf3", 999888777, 3);

	ContactList* contactList = new ContactList();
	contactList->addContact(*p1);
	contactList->addContact(*p2);
	contactList->addContact(*p3);

	std::cout << contactList->FindContactNumber("asdf2") << std::endl;
	std::cout << contactList->FindContactNumber(3);

	return 0;
}