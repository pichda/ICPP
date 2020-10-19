#include "Ticket.h"
#include "CashRegister.h"
#include <iostream>

int main(int argc, char** argv)
{
	CashRegister* cashRegist = new CashRegister();

	cashRegist->CreateTicket(100, 20);
	cashRegist->CreateTicket(1000, 50);
	cashRegist->CreateTicket(60, 100);

	std::cout << "cost of ticket 1001:" << cashRegist->GetTicket(1000).GetCost() << "\n";
	std::cout << "cost of ticket 1002:" << cashRegist->GetTicket(1001).GetCost() << "\n";
	std::cout << "cost of ticket 1003:" << cashRegist->GetTicket(1002).GetCost() << "\n";

	std::cout << "cost of tickets:" << cashRegist->GetCost() << "\n";
	std::cout << "cost of tickets with tax:" << cashRegist->GetCostInDph() << "\n";

	return 0;

}