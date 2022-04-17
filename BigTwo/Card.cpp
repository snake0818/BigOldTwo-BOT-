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
    this->flower = int(number * 10) % 10;
}

void Card::setSingle(double card)
{
    if (Check().isNumberInRpt(card))
    {
        this->single_arr[0] = card;
    }
    else
    {
        // 重新出牌（還未開發此功能）
    }
}

void Card::setPairs(double card_1, double card_2)
{
    double cards[2] = {card_1, card_2};

    bool isInRpt = true;
    for (int index = 0; index < 2; index++)
    {
        if (Check().isNumberInRpt(cards[index]) == false)
        {
            isInRpt = false;
            break;
        }
    }

    bool isSame = (cards[0] == cards[1])? false : true;

    if ((int(card_1) == int(card_2)) && isInRpt && isSame)
    {
        for (int index = 0; index < 2; index++)
        {
            this->pairs_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）
    }
}

void Card::setTriples(double card_1, double card_2, double card_3)
{
    double cards[3] = {card_1, card_2, card_3};

    bool isInRpt = true;
    for (int index = 0; index < 3; index++)
    {
        if (Check().isNumberInRpt(cards[index]) == false)
        {
            isInRpt = false;
            break;
        }
    }

    bool isSame = true;
    for(int i = 0; i < 2; i++)
    {
        for(int j = i+1; j < 3; j++)
        {
            if (cards[i] == cards[j])
            {
                isSame = false;
                break;
            }
        }
    }
    
    if ((int(card_1) == int(card_2) && int(card_1) == int(card_3)) && isInRpt && isSame)
    {
        for (int index = 0; index < 3; index++)
        {
            this->triples_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌
    }
}

void Card::setFlush(double card1, double card2, double card3, double card4, double card5)
{
    double cards[5] = {card1, card2, card3, card4, card5};

    bool isInRpt = true;
    for (int index = 0; index < 5; index++)
    {
        if (Check().isNumberInRpt(cards[index]) == false)
        {
            isInRpt = false;
            break;
        }
    }

    bool isSame = true;
    for(int i = 0; i < 4; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if (cards[i] == cards[j])
            {
                isSame = false;
                break;
            }
        }
    }

    int Decide = 0;
    arrange(cards, 5);

    int *firstFlower = new int;
    int *secondFlower = new int;
    setFlower(cards[0]);
    *firstFlower = getFlower();

    for (int index = 1; index < 5; index++)
    {
        setFlower(cards[index]);
        *secondFlower = getFlower();

        if (*firstFlower == *secondFlower)
        {
            Decide++;
        }
    }

    delete firstFlower;
    delete secondFlower;

    if (Decide == 4 && isInRpt && isSame)
    {
        for (int index = 0; index < 5; index++)
        {
            this->flush_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌
    }
}

void Card::setFullHouse(double card1, double card2, double card3, double card4, double card5) {
    double cards[5] = { card1, card2, card3, card4, card5 };
    arrange(card, size);
    if (int(card[0]) == int(card[1] && (int(card[2]) == int(card[3]) && int(card[2]) == int(card[4])) ||
        int(card[3]) == int(card[4]) && (int(card[0]) == int(card[1]) && int(card[0]) == int(card[2]))) {
        for (int index = 0; index < 5; index++) {
            this->fullHouse_arr[index] = cards[index];
        }
    }
    else {
        // 重新出牌（還未開發此功能）
    }
}

// void Card::setTiki(double card1, double card2, double card3, double card4, double card5) {
//     double card[5] = { card1,  card2,  card3,  card4,  card5 };
//     arrange(card, 5);
//     int Decide = 0;

//     for (int i = 0; i < 5; i++) {
//         if (int(card[3]) == int(card[i])) {
//             Decide++;
//         }
//     }
//     if (Decide == 4) {
//         for (int i = 0; i < 5; i++) {
//             this->tiki_arr[i] = card[i];
//         }
//     }
//     else {
//         for (int i = 0; i < 5; i++) {
//             this->tiki_arr[i] = 0;
//         }
//     }
// }

int Card::getNumber() const
{
    return number;
}

int Card::getFlower() const
{
    return flower;
}

void Card::arrange(double *card, int size)
{
    double temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (card[j] > card[i])
            {
                temp = card[j];
                card[j] = card[i];
                card[i] = temp;
            }
        }
    }
}

// Test
void Card::print() const
{
    for (auto i : flush_arr)
        cout << i << " ";
    cout << endl;
}
