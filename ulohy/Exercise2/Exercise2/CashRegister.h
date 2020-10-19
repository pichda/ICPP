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
	Ticket& CreateTicket(double cost, double dph);
	Ticket& GetTicket(int id);
	double GetCost() const;
	double GetCostInDph() const;
};

#endif // !CASHREGISTER_H