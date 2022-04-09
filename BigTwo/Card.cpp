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
void Card::setPairs(double card1, double card2) {
    double card[2] = { card1,card2 };
    
    if (check.numberInPairs(card1, card2)) {
        for (int i = 0; i < 2; i++) {
            this->pairs_arr[i] = card[i];
        }
    }else {
        for (int i = 0; i < 2; i++) {
            this->pairs_arr[i] = 0;
        }
    }
}
void Card::setTriples(double card1, double card2, double card3) {
    double card[3] = { card1,card2,card3 };

    if (check.numberInTriples(card1, card2,card3)) {
        for (int i = 0; i < 3; i++) {
            this->triples_arr[i] = card[i];
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            this->triples_arr[i] = 0;
        }
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
