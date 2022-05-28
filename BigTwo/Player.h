#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "Game.h"

#ifndef P_H
#define P_H

class Player
{
public:
	Player();
	void setPlayerArr(double, int);
	bool isInPlayer_arr(double);
	int getHandCardsSize() const;
	double getIndexOfCard(int) const;
	double *getPlayer_arr();
	void playerOutCard();
    bool isCorrect;
	
	// test
	void print();
	
private:
	Game Gamer;
	double player_arr[13];
};

#endif
