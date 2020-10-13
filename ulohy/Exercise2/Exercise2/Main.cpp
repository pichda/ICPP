#include "Ticket.h"
#include "CashRegister.h"

int main(int argc, char** argv)
{
	Ticket* ticket = new Ticket();
	ticket->SetId(1001);
	(*ticket).GetId();
	ticket->GetId();

	Ticket ticket2 = Ticket();
	ticket2.SetId(1002);
	const Ticket ticket3 = Ticket();
	ticket3.GetId();
	//ticket3.SetId(1003);

	return 0;

}