#include "OutOfCard.h"
#include "Card.h"
#include "Tool.h"

OutOfCard::OutOfCard() {}

void OutOfCard::ComputerFirstOutHand(Computer computer)
{
    double *computerArr = computer.getComputer_arr();
    Tool().copyDouble_arr(computerArr, handCard, 13);
}