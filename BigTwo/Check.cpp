#include "Check.h"
#include "Card.h"

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
    for (int index = 0; index < 2; index++)
    {
        if (Check().isNumberInRpt(cards[index]) == false)
        {
            isInRpt = false;
            break;
        }
    }
}

void Check::checkSame(double cards[], bool &isSame)
{
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
}

void Check::checkFlush(double cards[], bool &isFlush)
{
    for(int i = 1; i < 5; i++)
    {
        if(Card().returnFlower(cards[0]) != Card().returnFlower(cards[i]))
        {
            isFlush = false;
        }
    }
}

void Check::checkStraight(double cards[], bool &isStraight)
{
    for (int i = 1; i < 5; i++)
    {
        if (Card().returnNumber(cards[0]) + i != Card().returnNumber(cards[i]))
        {
            isStraight = false;
        }
    }
}

void Check::checkSpecialStraight(double cards[], bool &isSpecialStraight)
{
    if (Card().returnNumber(cards[0]) ==  1 &&
        Card().returnNumber(cards[1]) == 10 && 
        Card().returnNumber(cards[2]) == 11 && 
        Card().returnNumber(cards[3]) == 12 && 
        Card().returnNumber(cards[4]) == 13)
    {
        isSpecialStraight = true;
    }
}
    
string Check::checkCardsType(double cards[],int size){
    bool type=false;
    if(size==5){
        checkSpecialStraight(cards,type);
        if(type==true){
            return "SpecialStraight";
        }
        type=true;
        checkStraight(cards,type);
        if(type==true){
            return "Straight";
        }
        type=true;
        checkFlush(cards,type);
        if(type==true){
            return "Flush";
        }
    }
    return "no";
}
