#include "Compare.h"
#include "Card.h"

Compare::Compare() {}

bool Compare::singleComapre(double num)
{
    double tableSingle = Game().get1CardOnField(0);

    if(num < 3)
    {
        num += 13;
    }
    return (num > tableSingle);
}