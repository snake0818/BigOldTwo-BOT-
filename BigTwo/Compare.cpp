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

bool Compare::pairsCompare(double* pairs)
{
    double* tablePairs = Game().getCardsOnField();

    for (int i = 0; i < 2; i++)
    {
        if (Card().returnNumber(pairs[i]) < 3) pairs[i] += 13;
        if (Card().returnNumber(tablePairs[i]) < 3) tablePairs[i] += 13;
    }

    Tool().arrange(pairs, 2);
    Tool().arrange(tablePairs, 2);

    if (pairs[0] > tablePairs[0]) return true;

    return false;
}

bool Compare::tripleCompare(double* triple)
{
    double* tableTriple = Game().getCardsOnField();

    for (int i = 0; i < 3; i++)
    {
        if (Card().returnNumber(triple[i]) < 3) triple[i] += 13;
        if (Card().returnNumber(tableTriple[i]) < 3) tableTriple[i] += 13;
    }

    Tool().arrange(triple, 3);
    Tool().arrange(tableTriple, 3);

    if (triple[0] > tableTriple[0]) return true;

    return false;
}

bool Compare::straightCompare(double* straight)
{
    double* tableStraight = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straight[i]) < 3) straight[i] += 13;
        if (Card().returnNumber(tableStraight[i]) < 3) tableStraight[i] += 13;
    }

    Tool().arrange(straight, 5);
    Tool().arrange(tableStraight, 5);

    if (straight[0] > tableStraight[0]) return true;

    return false;
}

bool Compare::flushCompare(double* flush)
{
    double* tableFlush = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(flush[i]) < 3) flush[i] += 13;
        if (Card().returnNumber(tableFlush[i]) < 3) tableFlush[i] += 13;
    }

    Tool().arrange(flush, 5);
    Tool().arrange(tableFlush, 5);

    if (flush[4] > tableFlush[4]) return true;

    return false;
}

bool Compare::fullHouseCompare(double* fullHouse)
{
    double* tableFullHouse = Game().getCardsOnField();
    double tableFullHouseValue = 0, fullHouseValue = 0;

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(fullHouse[i]) < 3) fullHouse[i] += 13;
        if (Card().returnNumber(tableFullHouse[i]) < 3) tableFullHouse[i] += 13;
    }

    Tool().arrange(fullHouse, 5);
    Tool().arrange(tableFullHouse, 5);

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

bool Compare::tikiCompare(double* tiki)
{
    double* tableTiki = Game().getCardsOnField();
    double tableTikiValue = 0, tikiValue = 0;

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(tiki[i]) < 3) tiki[i] += 13;
        if (Card().returnNumber(tableTiki[i]) < 3) tableTiki[i] += 13;
    }

    Tool().arrange(tiki, 5);
    Tool().arrange(tableTiki, 5);

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

bool Compare::straightFlushCompare(double* straightFlush)
{
    double* tableStraight = Game().getCardsOnField();

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straightFlush[i]) < 3) straightFlush[i] += 13;
        if (Card().returnNumber(tableStraight[i]) < 3) tableStraight[i] += 13;
    }

    Tool().arrange(straightFlush, 5);
    Tool().arrange(tableStraight, 5);

    if (straightFlush[0] > tableStraight[0]) return true;

    return false;
}
