#include <unistd.h>

#include "Table.h"
#include "Tool.h"
#include "OutOfCard.h"
#include "PrintForMac.h"

int Table::cardsType = 0;
int Table::passNumber = 0;

Table::Table()
{
    computer1.setNO(1);
    computer2.setNO(2);
    computer3.setNO(3);
}

Player& Table::getPlayer()
{
    return player;
}

Computer& Table::getComputer1()
{
    return computer1;
}

Computer& Table::getComputer2()
{
    return computer2;
}

Computer& Table::getComputer3()
{
    return computer3;
}

void Table::start()
{
    double *list = new double[52];
    list = Game(1).shuffleCards();

    for (int i = 0; i < 52; i += 4) 
    {
        player.setPlayerArr(list[i], i / 4);
        computer1.setComputerArr(list[i + 1], i / 4);
        computer2.setComputerArr(list[i + 2], i / 4);
        computer3.setComputerArr(list[i + 3], i / 4);
    }

    Tool().arrange(player.getPlayer_arr(), 13);
    Tool().arrange(computer1.getComputer_arr(), 13);
    Tool().arrange(computer2.getComputer_arr(), 13);
    Tool().arrange(computer3.getComputer_arr(), 13);

    delete [] list;

    firstTime = true;
}

int Table::whoFirst()
{
    const double FIRST = 3.1;
    if (player.isInPlayer_arr(FIRST))
    {
        sequence = 4;
    }
    else if (computer1.isInComputer_arr(FIRST))
    {
        sequence = 1;
    }
    else if (computer2.isInComputer_arr(FIRST))
    {
        sequence = 2;
    }
    else if (computer3.isInComputer_arr(FIRST))
    {
        sequence = 3;
    }
    
    return sequence;
}

bool Table::end()
{
    if (player.getHandCardsSize() == 0
        || computer1.getHandCardsSize() == 0
        || computer2.getHandCardsSize() == 0 
        || computer3.getHandCardsSize() == 0)
    {
        return true;
    }
    
    return false;
}

bool Table::getFirstTime() const
{
    return firstTime;
}

void Table::playerFirst()
{
    if(getFirstTime())
    {
        cout << "首回合為你出牌" << endl;
        Player().FirstPlayerOutCard(getPlayer());
        firstTime = false;
        Print().printTable();
    }
    else
    {
        // player 出牌
        cout << "請出牌" << endl;
        Player().playerOutCard(getPlayer());
        Print().printTable();
    }
    
    OutOfCard().computerOutHand(getComputer1());
    Print().printTable();

    OutOfCard().computerOutHand(getComputer2());
    Print().printTable();

    OutOfCard().computerOutHand(getComputer3());
    Print().printTable();
}

void Table::computer1First()
{
    if(getFirstTime())
    {
        OutOfCard().computerFirstOutHand(getComputer1());
        firstTime = false;
        Print().printTable();
    }
    else
    {
        OutOfCard().computerOutHand(getComputer1());
        Print().printTable();
    }

    OutOfCard().computerOutHand(getComputer2());
    Print().printTable();
    
    OutOfCard().computerOutHand(getComputer3());
    Print().printTable();

    // player 出牌
    cout << "player 出牌" << endl;
    Player().playerOutCard(getPlayer());
    Print().printTable();
}

void Table::computer2First()
{
    if(getFirstTime())
    {
        OutOfCard().computerFirstOutHand(getComputer2());
        firstTime = false;
        Print().printTable();
    }
    else
    {
        OutOfCard().computerOutHand(getComputer2());
        Print().printTable();
    }

    OutOfCard().computerOutHand(getComputer3());
    Print().printTable();

    // player 出牌
    cout << "player 出牌" << endl;
    Player().playerOutCard(getPlayer());
    Print().printTable();

    OutOfCard().computerOutHand(getComputer1());
    Print().printTable();
}

void Table::computer3First()
{
    if(getFirstTime())
    {
        OutOfCard().computerFirstOutHand(getComputer3());
        firstTime = false;
        Print().printTable();
    }
    else
    {
        OutOfCard().computerOutHand(getComputer3());
        Print().printTable();
    }

    // player 出牌
    cout << "player 出牌" << endl;
    Player().playerOutCard(getPlayer());
    Print().printTable();

    OutOfCard().computerOutHand(getComputer1());
    Print().printTable();

    OutOfCard().computerOutHand(getComputer2());
    Print().printTable();
}

void Table::outCardSequence()
{
    if(sequence == 1)
    {
        computer1First();
    }
    else if(sequence == 2)
    {
        computer2First();
    }
    else if(sequence == 3)
    {
        computer3First();
    }
    else if(sequence == 4)
    {
        playerFirst();
    }
}

void Table::setCardsType(int type)
{
    cardsType = type;
}

int Table::getCardsType() const
{
    return cardsType;
}
void Table::passNumberPlus(){
    passNumber++;
}
int Table::getPassNumber(){
    return passNumber;
}
