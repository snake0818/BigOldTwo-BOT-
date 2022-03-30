#include <iostream>
using namespace std;

#include "Game.h"

void Game::setRpt()
{
    int index = 0;
    for(int i = 1; i <= 13; i++)
    {
        for(double j = 0.1; j <= 0.4; j += 0.1)
        {
            repository[index] = i+j;
            index++;
        }
    }
}

double Game::getRpt(int index)
{
    return repository[index];
}

Game::Game()
{
    this->setRpt();
}
