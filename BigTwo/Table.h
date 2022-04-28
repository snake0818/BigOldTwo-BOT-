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
    void Arrange();
    void Print();
    void print();
    void printHandCards();
    void whoFirst();

private:
    void arrange(double* card);
    Game game;
    Computer computer1, computer2, computer3;
    Player player;
};

#endif // !T_H