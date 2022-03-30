#include <iostream>
using namespace std;

#include "Check.h"

bool Check::numberAndFlower(const double card) const
{
    Game *bufferGame = new Game;
    for(int index = 0; index < 52; index++)
    {
        if(card == bufferGame->getRpt(index))
        {
            delete bufferGame;
            return true;
        }
    }
    delete bufferGame;
    return false;
}