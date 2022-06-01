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
    void printTable();
    void printShape();

private:
    void clear();
};

#endif
