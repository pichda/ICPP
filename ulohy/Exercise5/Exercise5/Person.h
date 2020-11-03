#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace Entity {
	class Person {
	private:

		std::string name;
		int contactNumber;
		int id;

	public:
		Person();
		Person(std::string name, int contactNumber, int id);
		~Person();

		std::string GetName() const;
		int GetContactNumber() const; // int protoze mi nedava smysl to mit ve stringu cislo
		int GetId() const;			//  jedine ze by jsme pak chteli formatovat napr. (777 666 555)
	};
}

#endif