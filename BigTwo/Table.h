#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Game.h"
#include "Player.h"
#include "Computer.h"

#ifndef T_H
#define T_H

class Table : public Game
{
public:
    void start();
    bool end();
    int whoFirst();
    Player getPlayer() const;
    Computer getComputer1() const;
    Computer getComputer2() const;
    Computer getComputer3() const;
    bool getFirstTime() const;
    void setCardsType(string);
    string getCardsType();

    // Out of card sequence.
    void playerFirst();
    void computer1First();
    void computer2First();
    void computer3First();
    
private:
    static int sequence;
    Player player;
    Computer computer1, computer2, computer3;
    bool firstTime;
};

#endif
