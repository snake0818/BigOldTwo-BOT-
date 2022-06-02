#include "OutOfCard.h"
#include "Card.h"
#include "Tool.h"
#include "Table.h"

OutOfCard::OutOfCard() {}

void OutOfCard::computerFirstOutHand(Computer& computer)
{
    double *computerArr = computer.getComputer_arr();
    
    /* 
        電腦要是有方塊 3 出牌想法很簡單
        先判斷能否構成 3 tiki 無法的話
        在判斷能否構成 3 fullhouse...
        依序類推 3 pairs, 3 single
    */
    int numOfThree = 0;
    for(int i = 0; i < 13; i++)
    {
        int card = computer.getIndexOfCard(i);
        if(card == 3)
        {
            numOfThree++;
        }
        if(card > 3)
        {
            break;
        }
    }

    if(numOfThree == 4)
    {
        int index = computer.returnIndex(3.1);
        for(int i = 0; i < 4; i++, index++)
        {
            Game().setField(computer.getIndexOfCard(index), i);
            computer.setComputerArr(0, index);
        }

        int singleIndex;
        bool allPairs = true;
        for(int i = index; i < 12; i++)
        {
            int num1 = Card().returnNumber(computer.getIndexOfCard(i));
            int num2 = Card().returnNumber(computer.getIndexOfCard(i+1));

            if(num1 == num2)
            {
                i++;
            }
            else
            {
                singleIndex = i;
                allPairs = false;
                break;
            }
        }

        if(allPairs)
        {
            Game().setField(computer.getIndexOfCard(index), 4);
            computer.setComputerArr(0, index);
        }
        else
        {
            Game().setField(computer.getIndexOfCard(singleIndex), 4);
            computer.setComputerArr(0, singleIndex);
        }
        Tool().arrange(computer.getComputer_arr(), 13);
        computer.addBeginIndex(5);

        Table().setCardsType(697);
    }
    else if(numOfThree == 3)
    {
        int index = computer.returnIndex(3.1);
        int pairsIndex;
        bool isFullHouse = false;
        for(int i = index+3; i < 12; i++)
        {
            int num1 = Card().returnNumber(computer.getIndexOfCard(i));
            int num2 = Card().returnNumber(computer.getIndexOfCard(i+1));

            if(num1 == num2)
            {
                pairsIndex = i;
                isFullHouse = true;
                break;
            }
        }

        if(isFullHouse)
        {
            for(int i = 0; i < 3; i++, index++)
            {
                Game().setField(computer.getIndexOfCard(index), i);
                computer.setComputerArr(0, index);
            }

            for(int i = 3; i < 5; i++, pairsIndex++)
            {
                Game().setField(computer.getIndexOfCard(pairsIndex), i);
                computer.setComputerArr(0, pairsIndex);
            }
            Tool().arrange(computer.getComputer_arr(), 13);
            computer.addBeginIndex(5);

            Table().setCardsType(696);
        }
        else
        {
            for(int i = 0; i < 3; i++, index++)
            {
                Game().setField(computer.getIndexOfCard(index), i);
                computer.setComputerArr(0, index);
            }
            Tool().arrange(computer.getComputer_arr(), 13);
            computer.addBeginIndex(3);

            Table().setCardsType(693);
        }
    }
    else if(numOfThree == 2)
    {
        int index = computer.returnIndex(3.1);
        
        for(int i = 0; i < 2; i++, index++)
        {
            Game().setField(computer.getIndexOfCard(index), i);
            computer.setComputerArr(0, index);
        }
        Tool().arrange(computer.getComputer_arr(), 13);
        computer.addBeginIndex(2);

        Table().setCardsType(692);
    }
    else if(numOfThree == 1)
    {
        int index = computer.returnIndex(3.1);
        Game().setField(3.1, 0);
        computer.setComputerArr(0, index);
        Tool().arrange(computer.getComputer_arr(), 13);
        computer.addBeginIndex(1);

        Table().setCardsType(691);
    }
    else
    {
        throw runtime_error("numOfThree out of range.");
    }
}

void OutOfCard::computerOutHand(Computer& computer)
{
    int type = Table().getCardsType();

    bool isOutHand = false;
    if(type == 691)
    {
        /* 
            場上單張時
            判斷有沒有單張可以出，有的話出單張
        */
        isOutHand = true;
    }
    else if(type == 692)
    {
        /*
            場上呸時
            判斷有沒有呸可以出，有的話出呸
        */
        isOutHand = true;
    }
    else if(type == 693)
    {
        /*
            場上三條時
            判斷有沒有三條可以出，有的話出三條
        */
        isOutHand = true;
    }
    else if(type == 694)
    {
        /*
            場上順子時
            判斷有沒有順子可以出，有的話出順子
        */
        isOutHand = true;
    }
    else if(type == 695)
    {
        /*
            場上同花時
            判斷有沒有同花可以出，有的話出同花
        */
        isOutHand = true;
    }
    else if(type == 696)
    {
        /*
            場上葫蘆時
            判斷有沒有葫蘆可以出，有的話出葫蘆
        */
        isOutHand = true;
    }

    if(!isOutHand)
    {
        if(type == 697)
        {
            /*
                場上鐵支時
                判斷有沒有鐵支可以出，有的話出鐵支
            */
            isOutHand = true;
        }
        if(!isOutHand && type == 698)
        {
            /*
                場上同花順時
                判斷有沒有同花順可以出，有的話出同花順
            */
        }
    }

    if(!isOutHand)
    {
        // Computer pass
        cout << "Cpmputer pass" << endl;
    }
}

void OutOfCard::computer_2outHand(Computer& computer)
{
    // wait for programing.
}