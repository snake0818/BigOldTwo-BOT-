#include <iostream>
using namespace std;

#include "Game.h"
#include "Check.h"

bool Check::isNumberInRpt(const double card) const
{
    Game *bufferGame = new Game;
    for(int index = 0; index < 52; index++)
    {
        if(card == bufferGame->get1RptCard(index))
        {
            delete bufferGame;
            return true;
        }
    }
    delete bufferGame;
    return false;
}

void Check::checkInRpt(double cards[], bool &isInRpt)
{
    
}

// bool Check::numberInPairs(const double card_1) const
// {
//     if( card_1 > Game().getCardsOnField(1))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Check::numberInTriples(const double card_1) const
// {
//     if( card_1 > Game().getCardsOnField(2))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }    