#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Ticket.h"

class CashRegister {
	Ticket* tickets;
	static int idCounter;
public:

	CashRegister();
	~CashRegister();
	Ticket& createTicket(double cost, double dph) {};
	Ticket& getTicket(int id) {};
	double getCost() {};
	double getCostInDph() {};
};

#endif