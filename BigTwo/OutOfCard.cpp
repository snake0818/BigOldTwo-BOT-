#include "OutOfCard.h"
#include "Card.h"
#include "Tool.h"
#include "Table.h"
#include "Compare.h"

OutOfCard::OutOfCard() {}

void OutOfCard::computerFirstOutHand(Computer &computer)
{
    double *computerArr = computer.getComputer_arr();

    /*
        電腦要是有方塊 3 出牌想法很簡單
        先判斷能否構成 3 tiki 無法的話
        在判斷能否構成 3 fullhouse...
        依序類推 3 pairs, 3 single
    */
    int numOfThree = 0;
    for (int i = 0; i < 13; i++)
    {
        int card = computer.getIndexOfCard(i);
        if (card == 3)
        {
            numOfThree++;
        }
        if (card > 3)
        {
            break;
        }
    }

    if (numOfThree == 4)
    {
        int index = computer.returnIndex(3.1);
        for (int i = 0; i < 4; i++, index++)
        {
            Game().setField(computer.getIndexOfCard(index), i);
            computer.setComputerArr(0, index);
        }

        int singleIndex;
        bool allPairs = true;
        for (int i = index; i < 12; i++)
        {
            int num1 = Card().returnNumber(computer.getIndexOfCard(i));
            int num2 = Card().returnNumber(computer.getIndexOfCard(i + 1));

            if (num1 == num2)
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

        if (allPairs)
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
        Table().resetPassNumber();
        system("clear");

        Table().setCardsType(697);
    }
    else if (numOfThree == 3)
    {
        int index = computer.returnIndex(3.1);
        int pairsIndex;
        bool isFullHouse = false;
        for (int i = index + 3; i < 12; i++)
        {
            int num1 = Card().returnNumber(computer.getIndexOfCard(i));
            int num2 = Card().returnNumber(computer.getIndexOfCard(i + 1));

            if (num1 == num2)
            {
                pairsIndex = i;
                isFullHouse = true;
                break;
            }
        }

        if (isFullHouse)
        {
            for (int i = 0; i < 3; i++, index++)
            {
                Game().setField(computer.getIndexOfCard(index), i);
                computer.setComputerArr(0, index);
            }

            for (int i = 3; i < 5; i++, pairsIndex++)
            {
                Game().setField(computer.getIndexOfCard(pairsIndex), i);
                computer.setComputerArr(0, pairsIndex);
            }
            Tool().arrange(computer.getComputer_arr(), 13);
            computer.addBeginIndex(5);
            Table().resetPassNumber();
            system("clear");

            Table().setCardsType(696);
        }
        else
        {
            for (int i = 0; i < 3; i++, index++)
            {
                Game().setField(computer.getIndexOfCard(index), i);
                computer.setComputerArr(0, index);
            }
            Tool().arrange(computer.getComputer_arr(), 13);
            computer.addBeginIndex(3);
            Table().resetPassNumber();
            system("clear");

            Table().setCardsType(693);
        }
    }
    else if (numOfThree == 2)
    {
        int index = computer.returnIndex(3.1);

        for (int i = 0; i < 2; i++, index++)
        {
            Game().setField(computer.getIndexOfCard(index), i);
            computer.setComputerArr(0, index);
        }
        Tool().arrange(computer.getComputer_arr(), 13);
        computer.addBeginIndex(2);
        Table().resetPassNumber();
        system("clear");

        Table().setCardsType(692);
    }
    else if (numOfThree == 1)
    {
        int index = computer.returnIndex(3.1);
        Game().setField(3.1, 0);
        computer.setComputerArr(0, index);
        Tool().arrange(computer.getComputer_arr(), 13);
        computer.addBeginIndex(1);
        Table().resetPassNumber();
        system("clear");

        Table().setCardsType(691);
    }
    else
    {
        throw runtime_error("numOfThree out of range.");
    }
}

void OutOfCard::computerOutHand(Computer &computer)
{
    int type = Table().getCardsType();
    bool RUN = false;
    bool isOutHand = false;
    if(type == 691)
    {
        RUN = true;
        if(computer.getHandCardsSize() > 4)
        {
            int beginIndex = computer.getBeginIndex();
            for(int i = beginIndex; i < 12; i++)
            {
                double card1 = Card().returnNumber(computer.getIndexOfCard(i));
                if(card1 < 3)
                {
                    continue;
                }

                double card2 = Card().returnNumber(computer.getIndexOfCard(i+1));
                if(card1 == card2)
                {
                    i++;
                    continue;
                }

                double card = computer.getIndexOfCard(i);
                if(Compare().singleCompare(card))
                {
                    Game().setField(card, 0);
                    computer.setComputerArr(0, i);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(1);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }

            if(!isOutHand)
            {
                for(int i = beginIndex; i < 12; i++)
                {
                    double card1 = Card().returnNumber(computer.getIndexOfCard(i));
                    if(card1 > 2)
                    {
                        break;
                    }

                    double card2 = Card().returnNumber(computer.getIndexOfCard(i+1));
                    if(card1 == card2)
                    {
                        i++;
                        continue;
                    }

                    double card = computer.getIndexOfCard(i);
                    if(Compare().singleCompare(card))
                    {
                        Game().setField(card, 0);
                        computer.setComputerArr(0, i);
                        Tool().arrange(computer.getComputer_arr(), 13);
                        isOutHand = true;
                        computer.addBeginIndex(1);
                        Table().resetPassNumber();
                        system("clear");
                        break;
                    }
                }
            }
        }
        else if(computer.getHandCardsSize() > 3)
        {
            const int INDEX = 9;
            double num1 = Card().returnNumber(computer.getIndexOfCard(INDEX));
            int sameOfNum = 1;
            for(int i = INDEX+1; i < 13; i++)
            {
                double num2 = Card().returnNumber(computer.getIndexOfCard(i));
                if(num1 == num2)
                {
                    sameOfNum++;
                }
            }

            if(sameOfNum == 1)
            {
                double card = computer.getIndexOfCard(INDEX);
                if(Compare().singleCompare(card))
                {
                    Game().setField(card, 0);
                    computer.setComputerArr(0, INDEX);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(1);
                    Table().resetPassNumber();
                    system("clear");
                }
                
                if(!isOutHand)
                {
                    const int INDEX = 10;
                    double num1 = Card().returnNumber(computer.getIndexOfCard(INDEX));
                    int sameOfNum = 1;
                    for(int i = INDEX+1; i < 13; i++)
                    {
                        double num2 = Card().returnNumber(computer.getIndexOfCard(i));
                        if(num1 == num2)
                        {
                            sameOfNum++;
                        }
                    }

                    if(sameOfNum == 1)
                    {
                        double card = computer.getIndexOfCard(10);
                        if(Compare().singleCompare(card))
                        {
                            Game().setField(card, 0);
                            computer.setComputerArr(0, 10);
                            Tool().arrange(computer.getComputer_arr(), 13);
                            isOutHand = true;
                            computer.addBeginIndex(1);
                            Table().resetPassNumber();
                            system("clear");
                        }
                    }
                    else if(sameOfNum == 2)
                    {
                        double lastOne = computer.getIndexOfCard(12);
                        if(Compare().singleCompare(lastOne))
                        {
                            Game().setField(lastOne, 0);
                            computer.setComputerArr(0, 12);
                            Tool().arrange(computer.getComputer_arr(), 13);
                            isOutHand = true;
                            computer.addBeginIndex(1);
                            Table().resetPassNumber();
                            system("clear");
                        }
                    }
                    else if(sameOfNum == 3)
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double card = computer.getIndexOfCard(i);
                            if(Compare().singleCompare(card))
                            {
                                Game().setField(card, 0);
                                computer.setComputerArr(0, i);
                                Tool().arrange(computer.getComputer_arr(), 13);
                                isOutHand = true;
                                computer.addBeginIndex(1);
                                Table().resetPassNumber();
                                system("clear");
                                break;
                            }
                        }
                    }
                }
            }
            else if(sameOfNum == 2)
            {
                bool twoPairs = false;
                int card1 = Card().returnNumber(computer.getIndexOfCard(INDEX+2));
                int card2 = Card().returnNumber(computer.getIndexOfCard(INDEX+3));

                if(card1 == card2)
                {
                    twoPairs = true;
                }

                if(!twoPairs)
                {
                    for(int i = INDEX+2; i < 13; i++)
                    {
                        double card = computer.getIndexOfCard(i);
                        if(Compare().singleCompare(card))
                        {
                            Game().setField(card, 0);
                            computer.setComputerArr(0, i);
                            Tool().arrange(computer.getComputer_arr(), 13);
                            isOutHand = true;
                            computer.addBeginIndex(1);
                            Table().resetPassNumber();
                            system("clear");
                            break;
                        }
                    }
                }
            }
            else if(sameOfNum == 3 || sameOfNum == 4)
            {
                for(int i = INDEX; i < 13; i++)
                {
                    double card = computer.getIndexOfCard(i);
                    if(Compare().singleCompare(card))
                    {
                        Game().setField(card, 0);
                        computer.setComputerArr(0, i);
                        Tool().arrange(computer.getComputer_arr(), 13);
                        isOutHand = true;
                        computer.addBeginIndex(1);
                        Table().resetPassNumber();
                        system("clear");
                        break;
                    }
                }
            }
        }
        else if(computer.getHandCardsSize() > 2)
        {
            const int INDEX = 10;
            double num1 = Card().returnNumber(computer.getIndexOfCard(INDEX));
            int sameOfNum = 1;
            for(int i = INDEX+1; i < 13; i++)
            {
                double num2 = Card().returnNumber(computer.getIndexOfCard(i));
                if(num1 == num2)
                {
                    sameOfNum++;
                }
            }

            if(sameOfNum == 1)
            {
                double card = computer.getIndexOfCard(10);
                if(Compare().singleCompare(card))
                {
                    Game().setField(card, 0);
                    computer.setComputerArr(0, 10);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(1);
                    Table().resetPassNumber();
                    system("clear");
                }
                
                if(!isOutHand)
                {
                    for(int i = 11; i < 13; i++)
                    {
                        double card = computer.getIndexOfCard(i);
                        if(Compare().singleCompare(card))
                        {
                            Game().setField(card, 0);
                            computer.setComputerArr(0, i);
                            Tool().arrange(computer.getComputer_arr(), 13);
                            isOutHand = true;
                            computer.addBeginIndex(1);
                            Table().resetPassNumber();
                            system("clear");
                            break;
                        }
                    }
                }
            }
            else if(sameOfNum == 2)
            {
                double lastOne = computer.getIndexOfCard(12);
                if(Compare().singleCompare(lastOne))
                {
                    Game().setField(lastOne, 0);
                    computer.setComputerArr(0, 12);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(1);
                    Table().resetPassNumber();
                    system("clear");
                }
            }
            else if(sameOfNum == 3)
            {
                for(int i = INDEX; i < 13; i++)
                {
                    double card = computer.getIndexOfCard(i);
                    if(Compare().singleCompare(card))
                    {
                        Game().setField(card, 0);
                        computer.setComputerArr(0, i);
                        Tool().arrange(computer.getComputer_arr(), 13);
                        isOutHand = true;
                        computer.addBeginIndex(1);
                        Table().resetPassNumber();
                        system("clear");
                        break;
                    }
                }
            }
        }
        else if(computer.getHandCardsSize() > 1)
        {
            for(int i = 11; i < 13; i++)
            {
                double card = computer.getIndexOfCard(i);
                if(Compare().singleCompare(card))
                {
                    Game().setField(card, 0);
                    computer.setComputerArr(0, i);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(1);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
        }
        else
        {
            double lastOne = computer.getIndexOfCard(12);
            if(Compare().singleCompare(lastOne))
            {
                Game().setField(lastOne, 0);
                computer.setComputerArr(0, 12);
                isOutHand = true;
                computer.addBeginIndex(1);
                Table().resetPassNumber();
                system("clear");
            }
        }
    }
    else if (type == 692)
    {
        RUN = true;
        const int INDEX = computer.getBeginIndex();

        for(int i = INDEX; i < 12; i++)
        {
            int card1num = Card().returnNumber(computer.getIndexOfCard(i));
            double card1 = computer.getIndexOfCard(i);
            if(card1num < 3)
            {
                continue;
            }

            int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
            double card2 = computer.getIndexOfCard(i+1);
            if(card1num == card2num)
            {
                double pairs[2] = {card1, card2};
                if(Compare().pairsCompare(pairs))
                {
                    Game().setField(card1, 0);
                    Game().setField(card2, 1);
                    computer.setComputerArr(0, i);
                    computer.setComputerArr(0, i+1);
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(2);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
        }
        
        if(!isOutHand)
        {
            for(int i = INDEX; i < 12; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);
                if(card1num > 2)
                {
                    break;
                }

                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                if(card1num == card2num)
                {
                    double pairs[2] = {card1, card2};
                    if(Compare().pairsCompare(pairs))
                    {
                        Game().setField(card1, 0);
                        Game().setField(card2, 1);
                        computer.setComputerArr(0, i);
                        computer.setComputerArr(0, i+1);
                        Tool().arrange(computer.getComputer_arr(), 13);
                        isOutHand = true;
                        computer.addBeginIndex(2);
                        Table().resetPassNumber();
                        system("clear");
                        break;
                    }
                }
            }
        }
    }
    else if (type == 693)
    {
        RUN = true;
        const int INDEX = computer.getBeginIndex();

        bool isTriples = false;
        int numOfSame = 0;
        for(int i = INDEX; i < 11; i++)
        {
            int card1num = Card().returnNumber(computer.getIndexOfCard(i));
            double card1 = computer.getIndexOfCard(i);

            if(card1num < 3)
            {
                continue;
            }

            int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
            double card2 = computer.getIndexOfCard(i+1);
            int card3num = Card().returnNumber(computer.getIndexOfCard(i+2));
            double card3 = computer.getIndexOfCard(i+2);
            int card4num = Card().returnNumber(computer.getIndexOfCard(i+3));
            double card4 = computer.getIndexOfCard(i+3);

            if(card1num != card2num)
            {
                continue;
            }

            if(card1num == card2num && card1num != card3num)
            {
                i++;
                continue;
            }

            if(card1num == card2num && card1num == card3num && card1num == card4num)
            {
                i += 3;
                continue;
            }

            double triples[3] = {card1, card2, card3};
            if(Compare().pairsCompare(triples))
            {
                Game().setField(card1, 0);
                Game().setField(card2, 1);
                Game().setField(card3, 2);
                for(int j = 0; j < 3; j++)
                {
                    computer.setComputerArr(0, i+j);
                }
                Tool().arrange(computer.getComputer_arr(), 13);
                isOutHand = true;
                computer.addBeginIndex(3);
                Table().resetPassNumber();
                system("clear");
                break;
            }
        }

        if(!isOutHand)
        {
            for(int i = INDEX; i < 11; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);

                if(card1num > 2)
                {
                    break;
                }
                
                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                int card3num = Card().returnNumber(computer.getIndexOfCard(i+2));
                double card3 = computer.getIndexOfCard(i+2);
                int card4num = Card().returnNumber(computer.getIndexOfCard(i+3));
                double card4 = computer.getIndexOfCard(i+3);

                if(card1num != card2num)
                {
                    continue;
                }

                if(card1num == card2num && card1num != card3num)
                {
                    i++;
                    continue;
                }

                if(card1num == card2num && card1num == card3num && card1num == card4num)
                {
                    i += 3;
                    continue;
                }

                double triples[3] = {card1, card2, card3};
                if(Compare().pairsCompare(triples))
                {
                    Game().setField(card1, 0);
                    Game().setField(card2, 1);
                    Game().setField(card3, 2);
                    for(int j = 0; j < 3; j++)
                    {
                        computer.setComputerArr(0, i+j);
                    }
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(3);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
        }
    }
    else if (type == 694)
    {
        RUN = true;
        const int INDEX = computer.getBeginIndex();

        for(int i = INDEX; i < 13; i++)
        {
            int card1num = Card().returnNumber(computer.getIndexOfCard(i));
            double card1 = computer.getIndexOfCard(i);
            if(card1num > 9)
            {
                break;
            }

            double straight[5] = {0};
            straight[0] = card1;

            int index2;
            bool isCorrect = false;
            for(int j = i+1; j < 13; j++)
            {
                int card2num = Card().returnNumber(computer.getIndexOfCard(j));
                double card2 = computer.getIndexOfCard(j);
                if(card1num+1 == card2num)
                {
                    straight[1] = card2;
                    isCorrect = true;
                    index2 = j;
                    break;
                }
                else
                {
                    continue;
                }
            }

            int index3;
            bool isCorrect2 = false;
            if(isCorrect)
            {
                for(int j = i+1; j < 13; j++)
                {
                    int card3num = Card().returnNumber(computer.getIndexOfCard(j));
                    double card3 = computer.getIndexOfCard(j);
                    if(card1num+2 == card3num)
                    {
                        straight[2] = card3;
                        isCorrect2 = true;
                        index3 = j;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }

            int index4;
            bool isCorrect3 = false;
            if(isCorrect2)
            {
                for(int j = i+1; j < 13; j++)
                {
                    int card4num = Card().returnNumber(computer.getIndexOfCard(j));
                    double card4 = computer.getIndexOfCard(j);
                    if(card1num+3 == card4num)
                    {
                        straight[3] = card4;
                        isCorrect3 = true;
                        index4 = j;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }

            int index5;
            bool isCorrect4 = false;
            if(isCorrect3)
            {
                for(int j = i+1; j < 13; j++)
                {
                    int card5num = Card().returnNumber(computer.getIndexOfCard(j));
                    double card5 = computer.getIndexOfCard(j);
                    if(card1num+4 == card5num)
                    {
                        straight[4] = card5;
                        isCorrect4 = true;
                        index5 = j;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }

            int indexArr[5] = {i, index2, index3, index4, index5};
            if(isCorrect4)
            {
                if(Compare().straightCompare(straight))
                {
                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(straight[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        computer.setComputerArr(0, indexArr[j]);
                    }
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(5);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }
    else if (type == 695)
    {
        RUN = true;
        const int INDEX = computer.getBeginIndex();

        int numOfFlower[4] = {0};

        for(int i = INDEX; i < 13; i++)
        {
            int flower = Card().returnFlower(computer.getIndexOfCard(i));

            for(int j = 0; j < 4; j++)
            {
                if(flower == j+1)
                {
                    numOfFlower[j]++;
                }
            }
        }

        for(int t = 0; t < 4; t++)
        {
            if(numOfFlower[t] >= 5 && (!isOutHand))
            {
                double flush[5] = {0};
                int bufferIndex[5] = {0};
                int flushIndex = 0;
                for(int i = INDEX; i < 13; i++)
                {
                    int flower = Card().returnFlower(computer.getIndexOfCard(i));
                    double card = computer.getIndexOfCard(i);

                    if(flower == t+1)
                    {
                        flush[flushIndex] = card;
                        bufferIndex[flushIndex] = i;
                        flushIndex++;
                    }

                    if(flushIndex > 4)
                    {
                        break;
                    }
                }

                if(Compare().flushCompare(flush))
                {
                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(flush[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        computer.setComputerArr(0, bufferIndex[j]);
                    }
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(5);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
        }
    }
    else if (type == 696)
    {
        RUN = true;
        const int INDEX = computer.getBeginIndex();

        bool isTriples = false;
        bool isPairs = false;
        double fullHouse[5] = {0};
        int bufferIndex[5] = {0};

        for(int i = INDEX; i < 11; i++)
        {
            int card1num = Card().returnNumber(computer.getIndexOfCard(i));
            double card1 = computer.getIndexOfCard(i);

            if(card1num < 3)
            {
                continue;
            }

            int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
            double card2 = computer.getIndexOfCard(i+1);
            int card3num = Card().returnNumber(computer.getIndexOfCard(i+2));
            double card3 = computer.getIndexOfCard(i+2);
            int card4num = Card().returnNumber(computer.getIndexOfCard(i+3));
            double card4 = computer.getIndexOfCard(i+3);

            if(card1num != card2num)
            {
                continue;
            }

            if(card1num == card2num && card1num != card3num)
            {
                i++;
                continue;
            }

            if(card1num == card2num && card1num == card3num && card1num == card4num)
            {
                i += 3;
                continue;
            }

            fullHouse[0] = card1;
            fullHouse[1] = card2;
            fullHouse[2] = card3;

            for(int j = 0; j < 3; j++)
            {
                bufferIndex[j] = i+j;
            }

            isTriples = true;
        }

        if(!isTriples)
        {
            for(int i = INDEX; i < 11; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);

                if(card1num > 2)
                {
                    break;
                }
                
                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                int card3num = Card().returnNumber(computer.getIndexOfCard(i+2));
                double card3 = computer.getIndexOfCard(i+2);
                int card4num = Card().returnNumber(computer.getIndexOfCard(i+3));
                double card4 = computer.getIndexOfCard(i+3);

                if(card1num != card2num)
                {
                    continue;
                }

                if(card1num == card2num && card1num != card3num)
                {
                    i++;
                    continue;
                }

                if(card1num == card2num && card1num == card3num && card1num == card4num)
                {
                    i += 3;
                    continue;
                }

                fullHouse[0] = card1;
                fullHouse[1] = card2;
                fullHouse[2] = card3;

                for(int j = 0; j < 3; j++)
                {
                    bufferIndex[j] = i+j;
                }

                isTriples = true;
            }
        }
        
        const int FIRSTNUM = Card().returnNumber(fullHouse[0]);
        if(isTriples)
        {
            for(int i = INDEX; i < 12; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);
                if(card1num < 3 || card1num == FIRSTNUM)
                {
                    continue;
                }

                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                if(card1num == card2num)
                {
                    fullHouse[3] = card1;
                    fullHouse[4] = card2;
                    isPairs = true;
                }

                for(int j = 3; j < 5; j++)
                {
                    bufferIndex[j] = i+j-3;
                }

                if(isPairs)
                {
                    break;
                }
            }
        }
        
        if(isTriples && (!isPairs))
        {
            for(int i = INDEX; i < 12; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);
                if(card1num > 2 || card1num == FIRSTNUM)
                {
                    break;
                }

                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                if(card1num == card2num)
                {
                    fullHouse[3] = card1;
                    fullHouse[4] = card2;
                    isPairs = true;
                }

                for(int j = 3; j < 5; j++)
                {
                    bufferIndex[j] = i+j-3;
                }
                
                if(isPairs)
                {
                    break;
                }
            }
        }

        if(isTriples && isPairs)
        {
            if(Compare().fullHouseCompare(fullHouse))
            {
                for(int j = 0; j < 5; j++)
                {
                    Game().setField(fullHouse[j], j);
                }
                for(int j = 0; j < 5; j++)
                {
                    computer.setComputerArr(0, bufferIndex[j]);
                }
                Tool().arrange(computer.getComputer_arr(), 13);
                isOutHand = true;
                computer.addBeginIndex(5);
                Table().resetPassNumber();
                system("clear");
            }
        }
    }

    if (!isOutHand && type != 698)
    {
        const int INDEX = computer.getBeginIndex();
        double tiki[5] = {0};
        int bufferIndex[5] = {0};
        if(computer.getHandCardsSize() > 4)
        {
            bool isSingle = false;
            for(int i = INDEX; i < 10; i++)
            {
                int card1num = Card().returnNumber(computer.getIndexOfCard(i));
                double card1 = computer.getIndexOfCard(i);
                int card2num = Card().returnNumber(computer.getIndexOfCard(i+1));
                double card2 = computer.getIndexOfCard(i+1);
                int card3num = Card().returnNumber(computer.getIndexOfCard(i+2));
                double card3 = computer.getIndexOfCard(i+2);
                int card4num = Card().returnNumber(computer.getIndexOfCard(i+3));
                double card4 = computer.getIndexOfCard(i+3);

                if(card1num != card2num
                    || (card1num != card3num)
                    || (card1num != card4num))
                {
                    continue;
                }

                tiki[0] = card1;
                tiki[1] = card2;
                tiki[2] = card3;
                tiki[3] = card4;

                for(int j = 0; j < 4; j++)
                {
                    bufferIndex[j] = i+j;
                }

                const int BUFFER = card1num;

                for(int j = INDEX; j < 13; j++)
                {
                    int cardNum = Card().returnNumber(computer.getIndexOfCard(j));
                    double card = computer.getIndexOfCard(j);
                    if(BUFFER == cardNum || cardNum < 3)
                    {
                        continue;
                    }

                    tiki[4] = card;
                    bufferIndex[4] = j;
                    isSingle = true;
                    break;
                }

                if(!isSingle)
                {
                    for(int j = INDEX; j < 13; j++)
                    {
                        int cardNum = Card().returnNumber(computer.getIndexOfCard(j));
                        double card = computer.getIndexOfCard(j);
                        if(cardNum > 2)
                        {
                            break;
                        }
                        
                        if(BUFFER == cardNum)
                        {
                            continue;
                        }

                        tiki[4] = card;
                        bufferIndex[4] = j;
                        isSingle = true;
                        break;
                    }
                    break;
                }

                cout << endl;
                if(isSingle)
                {
                    if(RUN)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            Game().setField(0, i);
                        }
                    }

                    if(Compare().tikiCompare(tiki))
                    {
                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(tiki[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            computer.setComputerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(computer.getComputer_arr(), 13);
                        isOutHand = true;
                        computer.addBeginIndex(5);
                        Table().setCardsType(697);
                        Table().resetPassNumber();
                        system("clear");
                        break;
                    }
                }
            }
        }
    }

    if (!isOutHand)
    {
        const int INDEX = computer.getBeginIndex();

        for(int i = INDEX; i < 13; i++)
        {
            double card1 = computer.getIndexOfCard(i);
            if(card1 > 9.4)
            {
                break;
            }

            double straightFlush[5] = {0};
            straightFlush[0] = card1;

            int index2;
            bool isCorrect = false;
            for(int j = i+1; j < 13; j++)
            {
                double card2 = computer.getIndexOfCard(j);
                if(card1+1 == card2)
                {
                    straightFlush[1] = card2;
                    isCorrect = true;
                    index2 = j;
                    break;
                }
                else
                {
                    continue;
                }
            }

            int index3;
            bool isCorrect2 = false;
            if(isCorrect)
            {
                for(int j = i+1; j < 13; j++)
                {
                    double card3 = computer.getIndexOfCard(j);
                    if(card1+2 == card3)
                    {
                        straightFlush[2] = card3;
                        isCorrect = true;
                        index3 = j;
                        isCorrect2 = true;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }

            int index4;
            bool isCorrect3 = false;
            if(isCorrect2)
            {
                for(int j = i+1; j < 13; j++)
                {
                    double card4 = computer.getIndexOfCard(j);
                    if(card1+3 == card4)
                    {
                        straightFlush[3] = card4;
                        isCorrect = true;
                        index4 = j;
                        isCorrect3 = true;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }

            int index5;
            bool isCorrect4 = false;
            if(isCorrect3)
            {
                for(int j = i+1; j < 13; j++)
                {
                    double card5 = computer.getIndexOfCard(j);
                    if(card1+4 == card5)
                    {
                        straightFlush[4] = card5;
                        isCorrect = true;
                        index5 = j;
                        isCorrect4 = true;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }
            
            int indexArr[5] = {i, index2, index3, index4, index5};

            if(isCorrect4)
            {
                if(Table().getCardsType() != 698)
                {
                    for(int i = 0; i < 5; i++)
                    {
                        Game().setField(0, i);
                    }
                }

                if(Compare().straightFlushCompare(straightFlush))
                {
                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(straightFlush[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        computer.setComputerArr(0, indexArr[j]);
                    }
                    Tool().arrange(computer.getComputer_arr(), 13);
                    isOutHand = true;
                    computer.addBeginIndex(5);
                    Table().setCardsType(697);
                    Table().resetPassNumber();
                    system("clear");
                    break;
                }
            }
            else
            {
                continue;
            }
        }
    }

    if (!isOutHand)
    {
        cout << "Cpmputer" << computer.getNO() << " pass\n"
            << endl;
        
        Table().passNumberPlus();
    }
}

void OutOfCard::computer_2outHand(Computer &computer)
{
    // wait for programing.
}

void OutOfCard::nLimitComputerOutHand(Computer &computer)
{
    // clear field
    for(int i = 0; i < 5; i++)
    {
        Game().setField(0, i);
    }

    const int INDEX = computer.getBeginIndex();
    
    int singleSum = 0;
    int pairsSum = 0;

    for(int i = INDEX; i < 13; i++)
    {
        int card1 = Card().returnNumber(computer.getIndexOfCard(i));
        int card2 = Card().returnNumber(computer.getIndexOfCard(i+1));

        if(card1 == card2)
        {
            pairsSum++;
            i++;
        }
        else
        {
            singleSum++;
        }
    }

    if(singleSum >= pairsSum)
    {
        for(int i = INDEX; i < 13; i++)
        {
            int card1 = Card().returnNumber(computer.getIndexOfCard(i));
            int card2 = Card().returnNumber(computer.getIndexOfCard(i+1));
            
            if(card1 != card2)
            {
                double card = computer.getIndexOfCard(i);
                Game().setField(card, 0);
                computer.setComputerArr(0, i);
                Tool().arrange(computer.getComputer_arr(), 13);
                computer.addBeginIndex(1);
                Table().setCardsType(691);
                break;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        for(int i = INDEX; i < 12; i++)
        {
            int card1 = Card().returnNumber(computer.getIndexOfCard(i));
            int card2 = Card().returnNumber(computer.getIndexOfCard(i+1));
            
            if(card1 == card2)
            {
                double card = computer.getIndexOfCard(i);
                double cardx = computer.getIndexOfCard(i+1);
                Game().setField(card, 0);
                Game().setField(cardx, 1);
                computer.setComputerArr(0, i);
                computer.setComputerArr(0, i+1);
                Tool().arrange(computer.getComputer_arr(), 13);
                computer.addBeginIndex(2);
                Table().setCardsType(692);
                break;
            }
        }
    }
    system("clear");
    Table().resetPassNumber();
}
