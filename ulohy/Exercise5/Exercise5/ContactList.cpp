#include "ContactList.h"
#include <stdexcept>

using namespace Model;
using namespace Entity;

Model::ContactList::ContactList()
{
	_start = nullptr;
}

Model::ContactList::~ContactList()
{
	Node* node = _start;
	while (node != nullptr) {
		Node* tmp = node->next;
		delete node;
		node = tmp;
	}
}

void Model::ContactList::AddContact(Person person)
{
	if (_start == nullptr)
	{
		Node* node = new Node(person);
		_start = node;
	}
	else {
		Node* newNode = _start;

		// kontrola, jestli se shoduje s prvnim prvek
		if (newNode->data.GetId() == person.GetId() || newNode->data.GetName() == person.GetName()) {
			throw std::invalid_argument("Jmeno nebo id uz existuje");
		}
		while (newNode->next != nullptr) {
			// vyhodi vyjimku, pokud id nebo jmeno je stejne uz s prvkem v seznamu
			if (newNode->data.GetId() == person.GetId() || newNode->data.GetName() == person.GetName()) {
				throw std::invalid_argument("Jmeno nebo id uz existuje");
			}
			newNode = newNode->next;
		}
		Node* contact = new Node(person);
		newNode->next = contact;
	}
}

int Model::ContactList::FindContactNumber(std::string name) const
{
	if (_start == nullptr)
	{
		throw std::invalid_argument("Neni zadny prvek v seznamu");
	}
	Node* tempN = _start;
	while (true) {
		if (name == tempN->data.GetName()) {
			return tempN->data.GetContactNumber();
		}
		if (tempN->next == nullptr) {
			throw std::invalid_argument("Zadny kontakt nenalezen.");
		}
		else {
			tempN = tempN->next;
		}
	}
}

int Model::ContactList::FindContactNumber(int id) const
{
	if (_start == nullptr)
	{
		throw std::invalid_argument("Neni zadny prvek v seznamu");
	}
	Node* tempN = _start;
	while (true) {
		if (id == tempN->data.GetId()) {
			return tempN->data.GetContactNumber();
		}
		if (tempN->next == nullptr) {
			throw std::invalid_argument("Zadny kontakt nenalezen.");
		}
		else {
			tempN = tempN->next;
		}
	}
}