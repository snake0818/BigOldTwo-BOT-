#include "Compare.h"

Compare::Compare() {}

bool Compare::singleCompare(double num)
{
    double tableSingle = Game().get1CardOnField(0);

    if (num < 3)
    {
        num += 13;
    }

    if(tableSingle < 3)
    {
        return (num > tableSingle + 13);
    }
    
    return (num > tableSingle);
}

bool Compare::pairsCompare(double* Pairs)
{
    double *table = Game().getCardsOnField();
    double tableMax = table[0];
    if(table[0] < table[1])
    {
        tableMax = table[1];
    }

    if(tableMax < 3)
    {
        tableMax += 13;
    }

    double pairsMax = Pairs[0];
    if(Pairs[0] < Pairs[1])
    {
        pairsMax = Pairs[1];
    }

    if(pairsMax < 3)
    {
        pairsMax += 13;
    }

    return (pairsMax > tableMax);
}

bool Compare::tripleCompare(double* Triple)
{
    double triple[5] = { 0 };
    double tableTriple[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        tableTriple[i] = Game().getCardsOnField()[i];
        if (Triple[i] != 0) triple[i] = Triple[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(triple[i]) == 1 or
            Card().returnNumber(triple[i]) == 2)
            triple[i] += 13;
        if (Card().returnNumber(tableTriple[i]) == 1 or
            Card().returnNumber(tableTriple[i]) == 2) 
            tableTriple[i] += 13;
    }

    Tool().postZero(triple, 5);
    Tool().postZero(tableTriple, 5);

    if (triple[0] > tableTriple[0]) return true;

    return false;
}

bool Compare::straightCompare(double* Straight)
{
    double straight[5] = { 0 };
    double tableStraight[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        tableStraight[i] = Game().getCardsOnField()[i];
        straight[i] = Straight[i];
    }

    Tool().postZero(straight, 5);
    Tool().postZero(tableStraight, 5);

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straight[i]) == 1 or
            Card().returnNumber(straight[i]) == 2)
            straight[i] += 13;
        if (Card().returnNumber(tableStraight[i]) == 1 or
            Card().returnNumber(tableStraight[i]) == 2)
            tableStraight[i] += 13;
    }

    {
        if (Card().returnNumber(straight[0]) == 14 &&
            Card().returnNumber(straight[1]) == 15 &&
            Card().returnNumber(straight[2]) == 3 &&
            Card().returnNumber(straight[3]) == 4 &&
            Card().returnNumber(straight[4]) == 5)
        {
            straight[0] -= 13;
            straight[1] -= 13;
        }
        if (Card().returnNumber(tableStraight[0]) == 14 &&
            Card().returnNumber(tableStraight[1]) == 15 &&
            Card().returnNumber(tableStraight[2]) == 3 &&
            Card().returnNumber(tableStraight[3]) == 4 &&
            Card().returnNumber(tableStraight[4]) == 5)
        {
            straight[0] -= 13;
            straight[1] -= 13;
        }

        if (Card().returnNumber(straight[0]) == 15 &&
            Card().returnNumber(straight[1]) == 3 &&
            Card().returnNumber(straight[2]) == 4 &&
            Card().returnNumber(straight[3]) == 5 &&
            Card().returnNumber(straight[4]) == 6)
        {
            straight[0] -= 13;
            straight[1] -= 13;
        }
        if (Card().returnNumber(tableStraight[0]) == 15 &&
            Card().returnNumber(tableStraight[1]) == 3 &&
            Card().returnNumber(tableStraight[2]) == 4 &&
            Card().returnNumber(tableStraight[3]) == 5 &&
            Card().returnNumber(tableStraight[4]) == 6)
        {
            straight[0] -= 13;
            straight[1] -= 13;
        }
    }

    Tool().postZero(straight, 5);
    Tool().postZero(tableStraight, 5);
     
    if (straight[0] > tableStraight[0]) return true;

    return false;
}

bool Compare::flushCompare(double* Flush)
{
    double flush[5] = { 0 };
    double tableFlush[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        tableFlush[i] = Game().getCardsOnField()[i];
        flush[i] = Flush[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(flush[i]) == 1 or
            Card().returnNumber(flush[i]) == 2)
            flush[i] += 13;
        if (Card().returnNumber(tableFlush[i]) == 1 or
            Card().returnNumber(tableFlush[i]) == 2)
            tableFlush[i] += 13;
    }

    Tool().postZero(flush, 5);
    Tool().postZero(tableFlush, 5);

    if (flush[4] > tableFlush[4]) return true;

    return false;
}

bool Compare::fullHouseCompare(double* FullHouse)
{
    double fullHouse[5] = { 0 };
    double tableFullHouse[5] = { 0 };;
    double tableFullHouseValue = 0, fullHouseValue = 0;

    for (int i = 0; i < 5; i++)
    {
        tableFullHouse[i] = Game().getCardsOnField()[i];
        fullHouse[i] = FullHouse[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(fullHouse[i]) == 1 or
            Card().returnNumber(fullHouse[i]) == 2)
            fullHouse[i] += 13;
        if (Card().returnNumber(tableFullHouse[i]) == 1 or
            Card().returnNumber(tableFullHouse[i]) == 2)
            tableFullHouse[i] += 13;
    }

    Tool().postZero(fullHouse, 5);
    Tool().postZero(tableFullHouse, 5);

    if (Card().returnNumber(fullHouse[0]) == Card().returnNumber(fullHouse[2]))
        fullHouseValue = Card().returnNumber(fullHouse[0]);
    else
        fullHouseValue = Card().returnNumber(fullHouse[2]);

    if (Card().returnNumber(tableFullHouse[0]) == Card().returnNumber(tableFullHouse[2]))
        tableFullHouseValue = Card().returnNumber(tableFullHouse[0]);
    else
        tableFullHouseValue = Card().returnNumber(tableFullHouse[2]);

    if (fullHouseValue > tableFullHouseValue) return true;

    return false;
}

bool Compare::tikiCompare(double* Tiki)
{
    double tiki[5] = { 0 };
    double tableTiki[5] = { 0 };
    double tableTikiValue = 0, tikiValue = 0;

    for (int i = 0; i < 5; i++)
    {
        tableTiki[i] = Game().getCardsOnField()[i];
        tiki[i] = Tiki[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(tiki[i]) == 1 or
            Card().returnNumber(tiki[i]) == 2)
            tiki[i] += 13;
        if (Card().returnNumber(tableTiki[i]) == 1 or
            Card().returnNumber(tableTiki[i]) == 2)
            tableTiki[i] += 13;
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
    double straightFlush[5] = {0};
    double tableStraight[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        tableStraight[i] = Game().getCardsOnField()[i];
        straightFlush[i] = StraightFlush[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (Card().returnNumber(straightFlush[i]) == 1 or
            Card().returnNumber(straightFlush[i]) == 2) straightFlush[i] += 13;
        if (Card().returnNumber(tableStraight[i]) == 1 or
            Card().returnNumber(tableStraight[i]) == 2) tableStraight[i] += 13;
    }

    Tool().postZero(straightFlush, 5);
    Tool().postZero(tableStraight, 5);

    if (straightFlush[4] > tableStraight[4]) return true;

    return false;
}
