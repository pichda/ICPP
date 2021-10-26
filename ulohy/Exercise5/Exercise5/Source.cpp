#include "Person.h"
#include "ContactList.h"
#include <iostream>

using namespace Model;
using namespace std;

int main(int argc, char** argv) {
	Person* p1 = new Person("asdf", 777666555, 1);
	Person* p2 = new Person("asdf2", 111222333, 2);
	Person* p3 = new Person("asdf3", 999888777, 3);

	ContactList* contactList = new ContactList();
	contactList->AddContact(p1);
	contactList->AddContact(p2);
	contactList->AddContact(p3);

	std::cout << contactList->FindContactNumber("asdf2") << std::endl;
	std::cout << contactList->FindContactNumber(3);
	delete contactList;
	return 0;
}