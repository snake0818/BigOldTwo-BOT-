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

    cout << numOfThree << endl;

    if(numOfThree == 4)
    {
        // 找除了 1, 2, 3 最小的一張牌合併成 tiki
    }
    else if(numOfThree == 3)
    {
        // 找除了 1, 2, 3 最小的兩張牌能組合成 pairs 和本來 3 張成 fullHouse
        // 假如沒有 next = true;
        // else
            if(numOfThree == 2)
            {
                // 出最小的 2 張 3
            }
            else if(numOfThree == 1)
            {
                // 出方塊 3
            }
    }
    else if(numOfThree == 2)
    {
        int index, index2;
        index = computer.returnIndex(3.1);
        
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