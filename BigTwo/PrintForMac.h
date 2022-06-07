#include "Table.h"

#ifndef PMAC_H
#define PMAC_H

class Print
{
public:
    Print();
    void welcome();
    void rule();
    void printHandCard(Table&);
    void fieldCard();
    void shuffleCard();
    void printSequence(int);
    void OutCard(Table&);
    void printTable();
    void printShape();
    void printWhoWin(Table&);

private:
    void clear();
};

#endif
