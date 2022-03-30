#include <iostream>
using namespace std;

#include "Card.h"
#include "Check.h"

void Card::setNumber(double number)
{
    this->number = int(number);
}

void Card::setFlower(double number)
{
    this->flower = int(number*10)%10;
}

void Card::setSingle(double card)
{
    if(Check().numberAndFlower(card))
    {
        this->single_arr[0] = card;
    }
    else
    {
        this->single_arr[0] = 0;
    }
}

int Card::getNumber() const
{
    return number;
}

int Card::getFlower() const
{
    return flower;
}

// Test
void Card::print() const
{
    for (auto i : single_arr)
        cout << i << " ";
    cout << endl;
}