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
    bool pairsCompare(double*);
    bool tripleCompare(double*);
    bool straightCompare(double*);
    bool flushCompare(double*);
    bool fullHouseCompare(double*);
    bool tikiCompare(double*);
    bool straightFlushCompare(double*);
};

#endif
