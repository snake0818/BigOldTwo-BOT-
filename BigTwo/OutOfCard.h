
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

private:
    int code;
    double handCard[13];
};

#endif