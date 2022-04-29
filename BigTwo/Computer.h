#ifndef Com_H
#define Com_H

#include <iostream>
#include <iomanip>
#include "Game.h"
using namespace std;

class Computer
{
public:
	void setArr(double,int);
	void arrange();
	bool find(double);
	int getNumOfCards()const;
	double getCard(int);

	void print();
private:
	Game Gamer;
	double ComputerArr[13] = { 0 };
	
};

#endif
