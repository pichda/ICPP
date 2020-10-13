#include "CashRegister.h"
#include <exception>


#define ID_COUNTER_INIT_VALUE 1000;

int CashRegister::idCounter = ID_COUNTER_INIT_VALUE;
int ticketsCount = 0;

CashRegister::CashRegister() {
	tickets = new Ticket[10];
}

CashRegister::~CashRegister() {
	delete[]tickets;
	delete &idCounter;
}

Ticket& CashRegister::createTicket(double cost, double dph){

	if (idCounter == 10) {
		throw new std::exception("CashRegister is full");
	}
	tickets[ticketsCount].setId(idCounter + ticketsCount);
	tickets[ticketsCount].setCost(cost);
	tickets[ticketsCount].setDph(dph);
	ticketsCount++;
	return tickets[ticketsCount - 1];
}

Ticket& CashRegister::getTicket(int id) {
	for (int i = 0; i < ticketsCount; i++)
	{
		if (tickets[i].getId() == id) {
			return tickets[i];
		}
	}
	return tickets[0];  // returns default first
}

double CashRegister::getCost() {
	double ticketsCost = 0;
	for (int i = 0; i < ticketsCount; i++)
	{
		ticketsCost += tickets[i].getCost();
	}
	return ticketsCost;
}

double CashRegister::getCostInDph() {
	double ticketsCostDph = 0;
	for (int i = 0; i < ticketsCount; i++)
	{
		ticketsCostDph += tickets[i].getCost() * (1 + tickets[i].getDph());
	}
	return ticketsCostDph;
}