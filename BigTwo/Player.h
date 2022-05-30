#include <sstream>
#include "Game.h"
#include "Card.h"

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

	void printPlayer_arr();
	
private:
	bool isCorrect;
	bool isPass;
	Game Gamer;
	double player_arr[13];
};

#endif
