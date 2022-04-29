#ifndef P_H
#define P_H

#include "Game.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Player
{
public:
	void setArr(double, int);
	void arrange();
	bool find(double);
	int getNumOfCards() const;
	double getCard(int) const;

	void print();
	
private:
	double PlayerArr[13] = { 0 };
	Game Gamer;
	
};

#endif
