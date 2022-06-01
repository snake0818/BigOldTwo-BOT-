
#include "Computer.h"

#ifndef O_H
#define O_H

class OutOfCard
{
public:
    OutOfCard();
    void FirstOutHand(Computer);

private:
    int code;
    double handCard[13];
};

#endif