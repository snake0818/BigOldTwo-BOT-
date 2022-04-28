#ifndef P_H
#define P_H

#include "Game.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Player
{
public:
	void setHandCards();

	void print();
	double PlayerArr[13] = { 0 };
private:
	Game Gamer;
	
};

#endif