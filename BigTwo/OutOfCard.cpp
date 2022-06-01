#include "OutOfCard.h"
#include "Card.h"
#include "Tool.h"
#include "Table.h"

OutOfCard::OutOfCard() {}

void OutOfCard::computerFirstOutHand(Computer& computer)
{
    double *computerArr = computer.getComputer_arr();
    Tool().copyDouble_arr(computerArr, handCard, 13);
    
    /* 
        電腦要是有方塊 3 出牌想法很簡單
        先判斷能否構成 3 tiki 無法的話
        在判斷能否構成 3 fullhouse...
        依序類推 3 pairs, 3 single
    */
    int numOfThree = 0;
    for(int i = 0; i < 13; i++)
    {
        int card = Card().returnNumber(handCard[i]);
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
        }
        else
        {
            if(numOfThree == 2)
            {
                int index = computer.returnIndex(3.1);
                
                for(int i = 0; i < 2; i++, index++)
                {
                    Game().setField(computer.getIndexOfCard(index), i);
                    computer.setComputerArr(0, index);
                }
                Tool().arrange(computer.getComputer_arr(), 13);
            }
            else if(numOfThree == 1)
            {
                int index = computer.returnIndex(3.1);
                Game().setField(3.1, 0);
                computer.setComputerArr(0, index);
                Tool().arrange(computer.getComputer_arr(), 13);
            }
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
    }
    else if(numOfThree == 1)
    {
        int index = computer.returnIndex(3.1);
        Game().setField(3.1, 0);
        computer.setComputerArr(0, index);
        Tool().arrange(computer.getComputer_arr(), 13);
    }
    else
    {
        throw runtime_error("numOfThree out of range.");
    }
}