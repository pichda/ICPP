#include "Ticket.h"


Ticket::Ticket() {
	this->id = 0;
	this->cost = 0;
	this->dph = 0;
}

Ticket::~Ticket() {
	delete &id;
	delete &cost;
	delete &dph;
}

void Ticket::setId(int id) {
	this->id = id;
}

int Ticket::getId() const {
	return id;
}

void Ticket::setCost(double cost) {
	this->cost = cost;
}

double Ticket::getCost() {
	return cost;
}
