#include "Compare.h"

Compare::Compare() {}

bool Compare::singleCompare(double num)
{
    double tableSingle = Game().get1CardOnField(0);

    if (num < 3)
    {
        num += 13;
    }
    return (num > tableSingle);
}

bool Compare::pairsCompare(double* Pairs)
{
    double* pairs = Pairs;
    double* tablePairs = Game().getCardsOnField();

    for (int i = 0; i < 2; i++)
    {
        if (Card().returnNumber(pairs[i]) < 3) pairs[i] += 13;
        if (Card().returnNumber(tablePairs[i]) < 3) tablePairs[i] += 13;
    }

    Tool().postZero(pairs, 2);
    Tool().postZero(tablePairs, 2);

    if (pairs[0] > tablePairs[0]) return true;

    return false;
}

bool Compare::tripleCompare(double* Triple)
{
    double* triple = Triple;
    double* tableTriple = Game().getCardsOnField();

    for (int i = 0; i < 3; i++)
    {
        if (Card().returnNumber(triple[i]) < 3) triple[i] += 13;
        if (Card().returnNumber(tableTriple[i]) < 3) tableTriple[i] += 13;
    }

    Tool().postZero(triple, 3);
    Tool().postZero(tableTriple, 3);

    if (triple[0] > tableTriple[0]) return true;

    return false;
}

bool Compare::straightCompare(double* Straight)
{
    double* straight = Straight;
    double* tableStraight = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straight[i]) < 3) straight[i] += 13;
        if (Card().returnNumber(tableStraight[i]) < 3) tableStraight[i] += 13;
    }

    Tool().postZero(straight, 5);
    Tool().postZero(tableStraight, 5);

    if (straight[0] > tableStraight[0]) return true;

    return false;
}

bool Compare::flushCompare(double* Flush)
{
    double* flush = Flush;
    double* tableFlush = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(flush[i]) < 3) flush[i] += 13;
        if (Card().returnNumber(tableFlush[i]) < 3) tableFlush[i] += 13;
    }

    Tool().postZero(flush, 5);
    Tool().postZero(tableFlush, 5);

    if (flush[4] > tableFlush[4]) return true;

    return false;
}

bool Compare::fullHouseCompare(double* FullHouse)
{
    double* fullHouse = FullHouse;
    double* tableFullHouse = Game().getCardsOnField();
    double tableFullHouseValue = 0, fullHouseValue = 0;

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(fullHouse[i]) < 3) fullHouse[i] += 13;
        if (Card().returnNumber(tableFullHouse[i]) < 3) tableFullHouse[i] += 13;
    }

    Tool().postZero(fullHouse, 5);
    Tool().postZero(tableFullHouse, 5);

    if (Card().returnNumber(fullHouse[0]) == Card().returnNumber(fullHouse[1]))
        fullHouseValue = Card().returnNumber(fullHouse[0]);
    else
        fullHouseValue = Card().returnNumber(fullHouse[2]);

    if (Card().returnNumber(tableFullHouse[0]) == Card().returnNumber(tableFullHouse[1]))
        tableFullHouseValue = Card().returnNumber(tableFullHouse[0]);
    else
        tableFullHouseValue = Card().returnNumber(tableFullHouse[2]);

    if (fullHouseValue > tableFullHouseValue) return true;

    return false;
}

bool Compare::tikiCompare(double* Tiki)
{
    double* tiki = Tiki;
    double* tableTiki = Game().getCardsOnField();
    double tableTikiValue = 0, tikiValue = 0;

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(tiki[i]) < 3) tiki[i] += 13;
        if (Card().returnNumber(tableTiki[i]) < 3) tableTiki[i] += 13;
    }

    Tool().postZero(tiki, 5);
    Tool().postZero(tableTiki, 5);

    if (Card().returnNumber(tiki[0]) == Card().returnNumber(tiki[1]))
        tikiValue = Card().returnNumber(tiki[4]);
    else
        tikiValue = Card().returnNumber(tiki[0]);

    if (Card().returnNumber(tableTiki[0]) == Card().returnNumber(tableTiki[1]))
        tableTikiValue = Card().returnNumber(tableTiki[4]);
    else
        tableTikiValue = Card().returnNumber(tableTiki[0]);

    if (tikiValue > tableTikiValue) return true;

    return false;
}

bool Compare::straightFlushCompare(double* StraightFlush)
{
    double* straightFlush = StraightFlush;
    double* tableStraight = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straightFlush[i]) < 3) straightFlush[i] += 13;
        if (Card().returnNumber(tableStraight[i]) < 3) tableStraight[i] += 13;
    }

    Tool().postZero(straightFlush, 5);
    Tool().postZero(tableStraight, 5);

    if (straightFlush[0] > tableStraight[0]) return true;

    return false;
}
