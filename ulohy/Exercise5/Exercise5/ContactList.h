#pragma once
#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <string>
#include "Person.h"

using namespace Entity;

namespace Model {
	class ContactList {
		class Node {
		public:
			Node* next;
			Person data;

			Node(Person pers) { this->next = nullptr; this->data = pers; }
		};

	private:
		Node* _start;

	public:
		ContactList();
		~ContactList();

		void addContact(Person person);
		int FindContactNumber(std::string name) const;
		int FindContactNumber(int id) const;
	};
}

#endif