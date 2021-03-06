#include "Card.h"
#include "Check.h"
#include "Tool.h"

void Card::setNumber(double number)
{
    number = int(number);
}

void Card::setFlower(double number)
{
    flower = int(number * 10) % 10;
}

int Card::returnNumber(double number)
{
    return int(number);
}

int Card::returnFlower(double card)
{
    return int(card * 10) % 10;
}

void Card::setSingle(double card)
{
    if (Check().isNumberInRpt(card))
    {
        single_arr[0] = card;
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
    Check().checkInRpt(cards, isInRpt);

    bool isSame = (cards[0] == cards[1])? false : true;

    bool isPairs = returnNumber(card_1) == returnNumber(card_2)? true : false;

    if (isPairs && isInRpt && isSame)
    {
        for (int index = 0; index < 2; index++)
        {
            pairs_arr[index] = cards[index];
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
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);

    bool isTriples = true;
    if(returnNumber(card_1) != returnNumber(card_2) ||
        returnNumber(card_1) != returnNumber(card_3))
    {
        isTriples = false;
    }

    if (isTriples && isInRpt && isSame)
    {
        for (int index = 0; index < 3; index++)
        {
            this->triples_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）
    }
}

void Card::setFlush(double card_1, double card_2, double card_3, double card_4, double card_5)
{
    double cards[5] = {card_1, card_2, card_3, card_4, card_5};

    bool isInRpt = true;
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);

    Tool().arrange(cards, 5);

    bool isFlush = true;
    Check().checkFlush(cards, isFlush);

    if (isFlush && isInRpt && isSame)
    {
        for (int index = 0; index < 5; index++)
        {
            this->flush_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）
    }
}

void Card::setFullHouse(double card_1, double card_2, double card_3, double card_4, double card_5)
{
    double cards[5] = {card_1, card_2, card_3, card_4, card_5};
    Tool().arrange(cards, 5);

    bool isInRpt = true;
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);

    double *pairs = new double[2];
    double *triples = new double[3];
    int *pairsIndex = new int;
    int *triplesIndex = new int;
    *pairsIndex = *triplesIndex = 0;

    Card *indexNumber = new Card;
    Card *targetNumber = new Card;
    targetNumber->setNumber(cards[2]);
    for(int index = 0; index < 5; index++)
    {
        indexNumber->setNumber(cards[index]);
        if(indexNumber->getNumber() == targetNumber->getNumber())
        {
            triples[*triplesIndex] = cards[index];
            (*triplesIndex)++;
        }
        else
        {
            pairs[*pairsIndex] = cards[index];
            (*pairsIndex)++;
        }
    }

    delete indexNumber;
    delete targetNumber;
    delete pairsIndex;
    delete triplesIndex;

    bool isPairs = returnNumber(pairs[0]) == returnNumber(pairs[1])? true : false;

    bool isTriples = true;
    if(returnNumber(triples[0]) != returnNumber(triples[1]) ||
        returnNumber(triples[0]) != returnNumber(triples[2]))
    {
        isTriples = false;
    }

    for(int index = 0; index < 5; index++)
    {
        if(index < 3)
        {
            this->fullHouse_arr[index] = triples[index];
        }
        else
        {
            this->fullHouse_arr[index] = pairs[index-3];
        }
    }

    delete [] pairs;
    delete [] triples;
}

void Card::setStraight(double card_1, double card_2, double card_3, double card_4, double card_5)
{
    double cards[5] = {card_1, card_2, card_3, card_4, card_5};
    Tool().arrange(cards, 5);

    bool isInRpt = true;
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);

    bool isStraight = true;
    Check().checkStraight(cards, isStraight);

    Check().checkSpecialStraight(cards, isStraight);

    if (isStraight && isInRpt && isSame)
    {
        for (int index = 0; index < 5; index++)
        {
            this->straight_arr[index] = cards[index];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）
    }
}

void Card::setTiki(double card_1, double card_2, double card_3, double card_4, double card_5)
{
    double cards[5] = {card_1, card_2, card_3, card_4, card_5};
    Tool().arrange(cards, 5);

    bool isInRpt = true;
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);
    
    bool is_C1_C2_Same = true;
    if(returnNumber(cards[0]) != returnNumber(cards[1]))
    {
        is_C1_C2_Same = false;
    }

    bool fourCardsSame = true;

    if(is_C1_C2_Same)
    {
        for(int index = 0; index < 4; index++)
        {
            if(returnNumber(cards[0]) != returnNumber(cards[index]))
            {
                fourCardsSame = false;
                break;
            }
        }
    }
    else
    {
        for(int index = 1; index < 5; index++)
        {
            if(returnNumber(cards[1]) != returnNumber(cards[index]))
            {
                fourCardsSame = false;
                break;
            }
        }
        
        double buffer = cards[0];
        cards[0] = cards[4];
        cards[4] = buffer;
    }

    if (fourCardsSame && isInRpt && isSame)
    {
        for (int i = 0; i < 5; i++)
        {
            this->tiki_arr[i] = cards[i];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）已寫入setCardsOnField 有防呆 沒做pass的情況
    }
}

void Card::setStraightFlush(double card_1, double card_2, double card_3, double card_4, double card_5)
{
    double cards[5] = {card_1, card_2, card_3, card_4, card_5};
    Tool().arrange(cards, 5);
    
    bool isInRpt = true;
    Check().checkInRpt(cards, isInRpt);

    bool isSame = true;
    Check().checkSame(cards, isSame);

    bool isFlush = true;
    Check().checkFlush(cards, isFlush);

    bool isStraight = true;
    Check().checkStraight(cards, isStraight);

    Check().checkSpecialStraight(cards, isStraight);

    if(isInRpt && isSame && isStraight && isFlush)
    {
        for(int i = 0; i < 5; i++)
        {
            straightFlush_arr[i] = cards[i];
        }
    }
    else
    {
        // 重新出牌（還未開發此功能）
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

double* Card::getSingle()
{
    return single_arr;
}

double* Card::getPairs()
{
    return pairs_arr;
}

double* Card::getTriples()
{
    return triples_arr;
}

double* Card::getStraight()
{
    return straight_arr;
}

double* Card::getFlush()
{
    return flush_arr;
}

double* Card::getFullHouse()
{
    return fullHouse_arr;
}

double* Card::getTiki()
{
    return tiki_arr;
}

double* Card::getStraightFlush()
{
    return straightFlush_arr;
}
