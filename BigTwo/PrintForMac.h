#include "Table.h"

#ifndef PMAC_H
#define PMAC_H

class Print
{
public:
    void welcome();
    void rule();
    void printHandCard(const Table&);
    void fieldCard();
    void shuffleCard();
    void printSequence(int);
    void OutCard(const Table&);

private:
    void clear();
};

#endif
