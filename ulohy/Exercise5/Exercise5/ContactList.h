#pragma once
#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <string>
#include "Person.h"

namespace Model {
	class ContactList {
		class Node {
		public:
			Node* next;
			Entity::Person* data;

			Node(Entity::Person* pers) { this->next = nullptr; this->data = pers; }
		};

	private:
		Node* _start;

	public:
		ContactList();
		~ContactList();

		void AddContact(Entity::Person* person);
		int FindContactNumber(std::string name) const;
		int FindContactNumber(int id) const;
	};
}

#endif