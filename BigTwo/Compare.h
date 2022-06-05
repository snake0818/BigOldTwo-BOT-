#include "Table.h"
#include "Game.h"
#include "Card.h"
#include "Tool.h"

#ifndef COMP_H
#define COMP_H

class Compare
{
public:
    Compare();
    bool singleCompare(double);
    bool pairsCompare(const double*);
    bool tripleCompare(const double*);
    bool straightCompare(const double*);
    bool flushCompare(const double*);
    bool fullHouseCompare(const double*);
    bool tikiCompare(const double*);
    bool straightFlushCompare(const double*);
};

#endif
