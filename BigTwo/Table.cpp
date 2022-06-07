#include <unistd.h>
#include <iostream>
using namespace std;

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
    getPlayer().printPlayer_arr();
    if(getFirstTime())
    {
        cout << "首回合為你出牌" << endl;
        Player().FirstPlayerOutCard(getPlayer());
        firstTime = false;
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    else
    {
        if(!end())
        {
            cout << "請出牌" << endl;

            if(passNumber == 3)
            {
                Player().nLimitPlayerOutCard(getPlayer());
            }
            else
            {
                Player().playerOutCard(getPlayer());
            }
            getPlayer().printPlayer_arr();
            Print().printTable();
        }
    }

    if(!end())
    {
        cout << "等待 computer1 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer1());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer1());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    
    if(!end())
    {
        cout << "等待 computer2 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer2());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer2());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }

    if(!end())
    {
        cout << "等待 computer3 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer3());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer3());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
}

void Table::computer1First()
{
    getPlayer().printPlayer_arr();
    if(getFirstTime())
    {
        cout << "等待 computer1 出牌，請稍候" << endl;
        sleep(2);
        OutOfCard().computerFirstOutHand(getComputer1());
        firstTime = false;
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    else
    {
        if(!end())
        {
            cout << "等待 computer1 出牌，請稍候" << endl;
            sleep(2);
            if(passNumber == 3)
            {
                OutOfCard().nLimitComputerOutHand(getComputer1());
            }
            else
            {
                OutOfCard().computerOutHand(getComputer1());
            }

            getPlayer().printPlayer_arr();
            Print().printTable();
        }
    }

    if(!end())
    {
        cout << "等待 computer2 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer2());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer2());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    
    if(!end())
    {
        cout << "等待 computer3 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer3());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer3());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();  
    }

    if(!end())
    {
        // player 出牌
        cout << "請出牌" << endl;
        
        if(passNumber == 3)
        {
            Player().nLimitPlayerOutCard(getPlayer());
        }
        else
        {
            Player().playerOutCard(getPlayer());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
}

void Table::computer2First()
{
    getPlayer().printPlayer_arr();
    if(getFirstTime())
    {
        cout << "等待 computer2 出牌，請稍候" << endl;
        sleep(2);
        OutOfCard().computerFirstOutHand(getComputer2());
        firstTime = false;
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    else
    {
        if(!end())
        {
            cout << "等待 computer2 出牌，請稍候" << endl;
            sleep(2);
            if(passNumber == 3)
            {
                OutOfCard().nLimitComputerOutHand(getComputer2());
            }
            else
            {   
                OutOfCard().computerOutHand(getComputer2());
            }
            getPlayer().printPlayer_arr();
            Print().printTable();
        }
    }

    if(!end())
    {    
        cout << "等待 computer3 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer3());
        }
        else
        { 
            OutOfCard().computerOutHand(getComputer3());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }

    if(!end())
    {
        // player 出牌
        cout << "請出牌" << endl;

        if(passNumber == 3)
        {
            Player().nLimitPlayerOutCard(getPlayer());
        }
        else
        {
            Player().playerOutCard(getPlayer());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }

    if(!end())
    {
        cout << "等待 computer1 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer1());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer1());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
}

void Table::computer3First()
{
    getPlayer().printPlayer_arr();
    if(getFirstTime())
    {
        cout << "等待 computer3 出牌，請稍候" << endl;
        sleep(2);
        OutOfCard().computerFirstOutHand(getComputer3());
        firstTime = false;
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
    else
    {
        if(!end())
        {
            cout << "等待 computer3 出牌，請稍候" << endl;
            sleep(2);
            if(passNumber == 3)
            {
                OutOfCard().nLimitComputerOutHand(getComputer3());
            }
            else
            {   
                OutOfCard().computerOutHand(getComputer3());
            }
            getPlayer().printPlayer_arr();
            Print().printTable();
        }
    }

    if(!end())
    {
        // player 出牌
        cout << "請出牌" << endl;

        if(passNumber == 3)
        {
            Player().nLimitPlayerOutCard(getPlayer());
        }
        else
        {
            Player().playerOutCard(getPlayer());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }

    if(!end())
    {
        cout << "等待 computer1 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer1());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer1());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }

    if(!end())
    {
        cout << "等待 computer2 出牌，請稍候" << endl;
        sleep(2);
        if(passNumber == 3)
        {
            OutOfCard().nLimitComputerOutHand(getComputer2());
        }
        else
        {   
            OutOfCard().computerOutHand(getComputer2());
        }
        getPlayer().printPlayer_arr();
        Print().printTable();
    }
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

void Table::resetPassNumber()
{
    this->passNumber = 0;
}
