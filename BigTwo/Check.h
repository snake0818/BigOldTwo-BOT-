#include "Game.h"

#ifndef CHECK_H
#define CHECK_H

class Check
{
public:
    bool isNumberInRpt(const double) const;
    void checkInRpt(double [], bool &);
    void checkSame(double [], bool &);
    void checkFlush(double [], bool &);
    void checkStraight(double [], bool &);
    void checkSpecialStraight(double [], bool &);

    bool numberInPairs(const double) const;
    bool numberInTriples(const double) const;

};

#endif
