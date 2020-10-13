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

	void setId(int id) {};
	int getId() const {};
	double getCost() {};
	void setCost(double cost){}
	double getDph() {};
	void setDph(double cost) {}

};

#endif // !TICKET_H
