
#include "Computer.h"

#ifndef O_H
#define O_H

class OutOfCard
{
public:
    OutOfCard();
    void computerFirstOutHand(Computer&);
    void computerOutHand(Computer&);
    void computer_2outHand(Computer&);
    void nLimitComputerOutHand(Computer&);
};

#endif