#ifndef Com_H
#define Com_H

#include <iostream>
#include <iomanip>
#include "Game.h"
using namespace std;

class Computer
{
public:
	void print();
	double computerArr[13] = { 0 };
	Computer();
	Computer(double[]);
private:
	Game Gamer;

};

#endif
