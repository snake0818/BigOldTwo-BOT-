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

        Table().setCardsType(692);
    }
    else if (numOfThree == 1)
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

void OutOfCard::computerOutHand(Computer &computer)
{
    int type = Table().getCardsType();

    bool isOutHand = false;
    if(type == 691)
    {
        /* 
            場上單張時
            判斷有沒有單張可以出，有的話出單張
        */
        if(computer.getHandCardsSize() > 4)
        {
            int beginIndex = computer.getBeginIndex();
            for(int i = beginIndex; i < 12; i++)
            {
                // 前後只要不一樣就出前面那張，要是一樣跳第 3 張(1, 2 先排除)
                // 要是上述沒有出
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
            }
        }
    }
    else if (type == 692)
    {
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
                        break;
                    }
                }
            }
        }
    }
    else if (type == 693)
    {
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
                    break;
                }
            }
        }
    }
    else if (type == 694)
    { /* 場上順子時 判斷有沒有順子可以出，有的話出順子 */
        // double card[5] = {0};

        // double minValue = Game().getCardsOnField()[0];
        // for (int i = 1; i < 5; i++)
        // {
        //     if (Game().getCardsOnField()[i] < minValue)
        //         minValue = Game().getCardsOnField()[i];
        // }

        // if (Check().checkStraight(Computer().getComputer_arr(), card, minValue))
        // {
        //     if (Compare().straightCompare(card))
        //     {
        //         Tool().arrange(card, 5);
        //         for (int i = 0; i < 3; i++)
        //         {
        //             Game().setField(card, 5);
        //         }
        //     }
        // }
        // else
        //     isOutHand = true;
    }
    else if (type == 695)
    { /* 場上同花時 判斷有沒有同花可以出，有的話出同花 */
        // double card[5] = {0};

        // double minValue = Game().getCardsOnField()[0];
        // for (int i = 1; i < 5; i++)
        // {
        //     if (Game().getCardsOnField()[i] < minValue)
        //         minValue = Game().getCardsOnField()[i];
        // }

        // if (Check().checkTriples(Computer().getComputer_arr(), card, minValue))
        // {
        //     if (Compare().tripleCompare(card))
        //     {
        //         Tool().arrange(card, 5);
        //         for (int i = 0; i < 3; i++)
        //         {
        //             Game().setField(card, 5);
        //         }
        //     }
        // }
        // else
        //     isOutHand = true;
    }
    else if (type == 696)
    { /* 場上葫蘆時 判斷有沒有葫蘆可以出，有的話出葫蘆 */
        // double card[5] = {0};

        // double minValue = Game().getCardsOnField()[0];

        // Tool().arrange(Game().getCardsOnField(), 5);
        // if (Card().returnNumber(Game().getCardsOnField()[0]) != Card().returnNumber(Game().getCardsOnField()[2]))
        //     minValue = Game().getCardsOnField()[2];

        // if (Check().checkFullHouse(Computer().getComputer_arr(), card, minValue))
        // {
        //     if (Compare().fullHouseCompare(card))
        //     {
        //         Tool().arrange(card, 5);
        //         for (int i = 0; i < 3; i++)
        //         {
        //             Game().setField(card, 5);
        //         }
        //     }
        // }
        // else
        //     isOutHand = true;
    }

    if (!isOutHand)
    {
        if (type == 697)
        { /* 場上鐵支時 判斷有沒有鐵支可以出，有的話出鐵支 */
            // double card[5] = {0};

            // double minValue = Game().getCardsOnField()[0];
            // Tool().arrange(Game().getCardsOnField(), 5);
            // if (Card().returnNumber(Game().getCardsOnField()[0]) != Card().returnNumber(Game().getCardsOnField()[1]))
            //     minValue = Game().getCardsOnField()[4];

            // if (Check().checkTiki(Computer().getComputer_arr(), card, minValue))
            // {
            //     if (Compare().tikiCompare(card))
            //     {
            //         Tool().arrange(card, 5);
            //         for (int i = 0; i < 3; i++)
            //         {
            //             Game().setField(card, 5);
            //         }
            //     }
            // }
            // else
            //     isOutHand = true;
        }
        if (!isOutHand && type == 698)
        { /* 場上同花順時 判斷有沒有同花順可以出，有的話出同花順 */
        }
    }

    if (!isOutHand)
    {
        // Computer pass
        cout << "Cpmputer pass" << endl;
    }
}

void OutOfCard::computer_2outHand(Computer &computer)
{
    // wait for programing.
}
