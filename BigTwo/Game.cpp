#include <ctime>

#include "Game.h"

double Game::cardsOnField[5] = {0, 0, 0, 0, 0};

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

double *Game::shuffleCards()
{
    double *bufferRpt = new double[52];
    for (int index = 0; index < 52; index++)
    {
        bufferRpt[index] = repository[index];
    }

    srand(time(0));
    for (int i = 0; i < 52; i++)
    {
        int index = rand() % 52;
        double buffer = bufferRpt[i];
        bufferRpt[i] = bufferRpt[index];
        bufferRpt[index] = buffer;
    }

    return bufferRpt;
}

bool Game::compare(double* cards, string type) const
{
    for (int i = 0; i < getNumOfCardsOnField(); i++)
    {
        // if (cardsOnField < cards) return true; //未完成
    }
    return false;
}

int Game::getNumOfCardsOnField() const
{
    int NumOfCards = 0;
    for (int i = 0; i < 5; i++)
    {
        if (cardsOnField[i] != 0) NumOfCards++;
    }
    return NumOfCards;
}

void Game::setField(double card_1, double card_2,
    double card_3, double card_4, double card_5)
{
    double card[5] = {card_1, card_2, card_3, card_4, card_5};

    for (int index = 0; index < 5; index++)
    {
        if (card[index] != 0)
        {
            cardsOnField[index] = card[index];
        }
    }
}

double Game::get1CardOnField(int index) const
{
    return cardsOnField[index];
}

double* Game::getCardsOnField() const
{
    return cardsOnField;
}

void Game::setField(double number, int side)
{
    cardsOnField[side] = number;
}
