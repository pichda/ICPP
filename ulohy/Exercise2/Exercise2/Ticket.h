#pragma once
#ifndef TICKET_H
#define TICKET_H

class Ticket {

private:
	int id;
	double cost;
	double dph;

public:

	Ticket();
	~Ticket();

	void SetId(int id) ;
	int GetId() const ;
	double GetCost() ;
	void SetCost(double cost);
	double GetDph();
	void SetDph(double dph);

};

#endif // !TICKET_H
