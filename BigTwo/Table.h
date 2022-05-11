#include <iostream>
using namespace std;

#include "Game.h"
#include "Player.h"
#include "Computer.h"

#ifndef T_H
#define T_H

class Table
{
public:
    void start();
    void printHandCards();
    bool end();
    int whoFirst();
    Player getPlayer() const;
    Computer getComputer1() const;
    Computer getComputer2() const;
    Computer getComputer3() const;

private:
    static int count;
    Player player;
    Computer computer1, computer2, computer3;
};

#endif