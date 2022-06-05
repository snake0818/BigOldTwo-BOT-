#include <sstream>
#include "Game.h"
#include "Player.h"
#include "Computer.h"
#include "Tool.h"

#ifndef T_H
#define T_H

class Table : public Game
{
public:
    Table();
    void start();
    bool end();
    int whoFirst();
    Player& getPlayer();
    Computer& getComputer1();
    Computer& getComputer2();
    Computer& getComputer3();
    bool getFirstTime() const;
    void setCardsType(int);
    int getCardsType() const;
    void passNumberPlus();
    int getPassNumber();

    // Out of card sequence.
    void outCardSequence();
    void playerFirst();
    void computer1First();
    void computer2First();
    void computer3First();
    
private:
    int sequence;
    Player player;
    static int cardsType;
    static int passNumber;

    Computer computer1, computer2, computer3;
    bool firstTime;
};

#endif
