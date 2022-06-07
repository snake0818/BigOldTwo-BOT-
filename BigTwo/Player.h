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
	void playerOutCard(Player&);
	void FirstPlayerOutCard(Player&);
	void addBeginIndex(int);
	int getBeginIndex() const;

	void printPlayer_arr();
	
private:
	Game Gamer;
	static bool wasDo;
	static double player_arr[13];
	int beginIndex;
};

#endif
