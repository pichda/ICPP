#include "CashRegister.h"
#include <exception>
#include <iostream>


#define ID_COUNTER_INIT_VALUE 1000;

int CashRegister::idCounter = ID_COUNTER_INIT_VALUE;

CashRegister::CashRegister() {
	tickets = new Ticket[10];
	ticketsCount = 0;
}

CashRegister::~CashRegister() {
	delete[] tickets;
}

Ticket& CashRegister::CreateTicket(double cost, double dph){

	if (ticketsCount == 10) {
		std::cout << "maximalni pocet ticketu";
	}
	else {
		tickets[ticketsCount].SetId(idCounter);

		tickets[ticketsCount].SetCost(cost);
		tickets[ticketsCount].SetDph(dph);
		idCounter++;
		ticketsCount++;
		return tickets[ticketsCount - 1];
	}

	
}

Ticket& CashRegister::GetTicket(int id) {
	for (int i = 0; i < ticketsCount; i++)
	{
		if (tickets[i].GetId() == id) {
			return tickets[i];
		}
	}
	return tickets[0];  // returns default first
}

double CashRegister::GetCost() const {
	double ticketsCost = 0;
	for (int i = 0; i < ticketsCount; i++)
	{
		ticketsCost += tickets[i].GetCost();
	}
	return ticketsCost;
}

double CashRegister::GetCostInDph() const {
	double ticketsCostDph = 0;
	for (int i = 0; i < ticketsCount; i++)
	{
		ticketsCostDph += tickets[i].GetCost() * (tickets[i].GetDph()/100);
		ticketsCostDph += tickets[i].GetCost();
	}
	return ticketsCostDph;
}
