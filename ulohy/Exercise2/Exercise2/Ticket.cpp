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

void Ticket::SetId(int id) {
	this->id = id;
}

int Ticket::GetId() const {
	return id;
}

void Ticket::SetCost(double cost) {
	this->cost = cost;
}

double Ticket::GetCost() {
	return cost;
}

double Ticket::GetDph() {
	return dph;
}

void Ticket::SetDph(double dph) {
	this->dph = dph;
}
