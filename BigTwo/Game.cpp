#include <iostream>
using namespace std;

#include "Game.h"

void Game::setRpt()
{
    int index = 0;
    for (int i = 1; i <= 13; i++)
    {
        for (double j = 0.1; j <= 0.4; j += 0.1)
        {
            repository[index] = i + j;
            index++;
        }
    }
}

Game::Game()
{
    this->setRpt();
}

double Game::get1RptCard(int index)
{
    return repository[index];
}

// void Game::setCardsOnField(double card_1, double card_2, double card_3, double card_4, double card_5)
// {
//     double card[5] = {card_1, card_2, card_3, card_4, card_5};
//     for (int index = 0; index < 5; index++)
//     {
//         cardsOnField[index] = card[index];
//     }
// }

// double Game::get1CardOnField(int index) const
// {
//     return cardsOnField[index];
// }

// double *Game::getCardsOnField() const
// {
//     return cardsOnField;
// }
