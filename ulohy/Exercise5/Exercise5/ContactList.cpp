#include "ContactList.h"

using namespace Model;
using namespace Entity;

Model::ContactList::ContactList()
{
	_start = nullptr;
}

Model::ContactList::~ContactList()
{
}

void Model::ContactList::addContact(Person person)
{
	if (_start == nullptr)
	{
		Node* node = new Node(person);
		_start = node;
	}
	else {
		// bez kontroly klice, zadani nedava rozum, protoze klic by se nemel opakovat

		if (_start == nullptr)
		{
			Node* node = new Node(person);
			_start = node;
		}
		else {
			Node* newNode = new Node(person);
			newNode->next = _start;
			_start = newNode;
		}
	}
}

int Model::ContactList::FindContactNumber(std::string name) const
{
	if (_start == nullptr)
	{
		throw std::exception("Neni zadny prvek v seznamu");
	}
	else {
		Node* tempN = _start;
		while (true) {
			if (name == tempN->data.GetName()) {
				return tempN->data.GetContactNumber();
			}
			if (tempN->next == nullptr) {
				throw std::exception("Zadny kontakt nenalezen.");
			}
			else {
				tempN = tempN->next;
			}
		}
	}
}

int Model::ContactList::FindContactNumber(int id) const
{
	if (_start == nullptr)
	{
		throw std::exception("Neni zadny prvek v seznamu");
	}
	else {
		Node* tempN = _start;
		while (true) {
			if (id == tempN->data.GetId()) {
				return tempN->data.GetContactNumber();
			}
			if (tempN->next == nullptr) {
				throw std::exception("Zadny kontakt nenalezen.");
			}
			else {
				tempN = tempN->next;
			}
		}
	}
}