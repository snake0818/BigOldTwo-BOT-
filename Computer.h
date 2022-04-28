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
	double ComputerArr[13] = { 0 };
private:
	Game Gamer;
	
};

#endif