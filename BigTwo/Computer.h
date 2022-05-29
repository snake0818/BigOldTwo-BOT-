#include "Game.h"

#ifndef Com_H
#define Com_H

class Computer
{
public:
	Computer();
	void setComputerArr(double, int);
	bool isInComputer_arr(double);
	int getHandCardsSize() const;
	double getIndexOfCard(int) const;
	double *getComputer_arr();
    void computerOutCard();
	
	// test
	void print();

private:
	Game Gamer;
	double computer_arr[13];
};

#endif
