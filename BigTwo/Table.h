#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Computer.h"
using namespace std;

#ifndef T_H
#define T_H

class Table
{
public:
    void Start();
    void printHandCards();
    bool end();
    int whoFirst();
private:
    static int count;
    Player player;
    Computer computer1, computer2, computer3;
};

#endif // !T_H
