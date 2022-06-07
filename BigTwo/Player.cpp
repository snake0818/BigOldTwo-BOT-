#include "Player.h"
#include "Table.h"
#include "Check.h"
#include "Card.h"
#include "Compare.h"

double Player::player_arr[13] = {0};

bool Player::wasDo = false;

Player::Player()
{
    beginIndex = 0;
}

void Player::setPlayerArr(double num, int index)
{
    player_arr[index] = num;
}

bool Player::isInPlayer_arr(double num)
{
    for (int i = 0; i < 13; i++)
    {
        if (player_arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int Player::getHandCardsSize() const
{
    int count = 0;
    for (int i = 0; i < 13; i++)
    {
        if (player_arr[i] != 0)
            count++;
    }
    return count;
}

double Player::getIndexOfCard(int index) const
{
    return player_arr[index];
}

void Player::printPlayer_arr()
{
    for (int i = 0; i < 13; i++)
    {
        int Flower = Card().returnFlower(player_arr[i]);
        if (Flower == 1)
        {
            cout << player_arr[i] << "  ";
        }
        else if (Flower == 2)
        {
            cout << "\e[31m" << player_arr[i] << "  \e[0m";
        }
        else if (Flower == 3)
        {
            cout << "\e[33m" << player_arr[i] << "  \e[0m";
        }
        else if (Flower == 4)
        {
            cout << "\e[35m" << player_arr[i] << "  \e[0m";
        }
    }
    cout << endl;
}

double *Player::getPlayer_arr()
{
    return player_arr;
}

void Player::playerOutCard(Player &player)
{
    const int type = Table().getCardsType();
    const int INDEX = player.getBeginIndex();

    bool isPass = false;
    bool isCorrect = true;
    string playerOutCard;
    cout << "Enter your number : ";
    getline(cin, playerOutCard);
    stringstream word(playerOutCard);

    string cardByCin[5];
    double card[5] = {0};

    int numberOfCards = 0;
    while (!word.eof())
    {
        word >> cardByCin[numberOfCards];
        numberOfCards++;
    }
    for (int i = 0; i < numberOfCards; i++)
    {
        string text = cardByCin[i];
        if (((cardByCin[i] == "pass" or cardByCin[i] == "Pass" or cardByCin[i] == "PASS") and
             (cardByCin[0] != "pass" or cardByCin[0] != "Pass" or cardByCin[0] != "PASS") and i != 0) or
            isCorrect == false)
        {
            isCorrect = false;
            break;
        }
        if ((cardByCin[0] == "pass" or cardByCin[0] == "Pass" or cardByCin[0] == "PASS") and
            (cardByCin[i] != "pass" or cardByCin[i] != "Pass" or cardByCin[i] != "PASS"))
        {
            isPass = true;
        }
        double num = 0;
        double numPo = 0;
        for (int k = 0; k < text.size(); k++)
        {
            if (text[k] == '.')
            {
                if (int(text[k + 1]) > 48 and int(text[k + 1]) < 53)
                {
                    numPo = text[k + 1] - 48;
                }
                else
                {
                    isCorrect = false;
                }
                break;
            }
            else
            {
                if (int(text[k]) < 58 and int(text[k]) > 47)
                {
                    num = (num * 10) + (int(text[k]) - 48);
                }
                else
                {
                    isCorrect = false;
                    break;
                }
            }
        }
        num = num + (numPo * 0.1);
        if (isCorrect == true)
        {
            for (int k = 0; k < 13; k++)
            {
                if (num != player_arr[k])
                {
                    isCorrect = false;
                }
                else
                {
                    card[i] = num;
                    isCorrect = true;
                    break;
                }
            }
            for (int t = 0; t < i; t++)
            {
                if (num == card[t])
                {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect == true)
            {
                card[i] = num;
            }
            else
            {
                break;
            }
        }
    }
    if (isPass == true)
    {
        Table().passNumberPlus();
    }
    else
    {
        if (isCorrect == true)
        {
            if (numberOfCards > 1)
            {
                for (int i = 0; i < numberOfCards; i++)
                {
                    for (int k = 0; k < numberOfCards; k++)
                    {
                        if (i < k and card[i] > card[k])
                        {
                            double t = card[i];
                            card[i] = card[k];
                            card[k] = t;
                        }
                    }
                }
            }

            int cardSize = 0;
            for(int t = 0; t < 5; t++)
            {
                if(card[t] != 0)
                {
                    cardSize++;
                }
            }
            
            int RUN = false;
            bool isOutHand = false;

            if(type == 691 && cardSize == 1)
            {
                int bufferIndex[1] = {0};
                RUN = true;
                if(Compare().singleCompare(card[0]))
                {
                    for(int k = INDEX; k < 13; k++)
                    {
                        double target = player.getIndexOfCard(k);
                        if(target == card[0])
                        {
                            bufferIndex[0] = k;
                        }
                    }

                    Game().setField(card[0], 0);
                    player.setPlayerArr(0, bufferIndex[0]);
                    Tool().arrange(player.getPlayer_arr(), 13);
                    isOutHand = true;
                    Table().getPlayer().addBeginIndex(1);
                }

            }
            else if(type == 692 && cardSize == 2)
            {
                RUN = true;
                int bufferIndex[2] = {0};
                int card1Num = Card().returnNumber(card[0]);
                int card2Num = Card().returnNumber(card[1]);
                if(card1Num == card2Num)
                {
                    if(Compare().pairsCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 2; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 2; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 2; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(2);
                    }
                }
            }
            else if(type == 693 && cardSize == 3)
            {
                RUN = true;
                int bufferIndex[3] = {0};
                int card1Num = Card().returnNumber(card[0]);
                int card2Num = Card().returnNumber(card[1]);
                int card3Num = Card().returnNumber(card[2]);

                if(card1Num == card2Num && card1Num == card3Num)
                {
                    if(Compare().tripleCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 3; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 3; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 3; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(3);
                    }
                }
            }
            else if(type == 694 && cardSize == 5)
            {
                RUN = true;
                int bufferIndex[5] = {0};
                int card1Num = Card().returnNumber(card[0]);
                int card2Num = Card().returnNumber(card[1]);
                int card3Num = Card().returnNumber(card[2]);
                int card4Num = Card().returnNumber(card[3]);
                int card5Num = Card().returnNumber(card[4]);

                if(card1Num+1 == card2Num &&
                    card1Num+2 == card3Num &&
                    card1Num+3 == card4Num &&
                    card1Num+4 == card5Num)
                {
                    if(Compare().straightCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 5; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(5);
                    }
                }
            }
            else if(type == 695 && cardSize == 5)
            {
                RUN = true;
                int bufferIndex[5] = {0};
                int card1F = Card().returnFlower(card[0]);
                int card2F = Card().returnFlower(card[1]);
                int card3F = Card().returnFlower(card[2]);
                int card4F = Card().returnFlower(card[3]);
                int card5F = Card().returnFlower(card[4]);

                if(card1F == card2F &&
                    card1F == card3F &&
                    card1F == card4F &&
                    card1F == card5F)
                {
                    if(Compare().flushCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 5; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(5);
                    }
                }
            }
            else if(type == 696 && cardSize == 5)
            {
                RUN = true;
                int bufferIndex[5] = {0};
                int card1Number = Card().returnNumber(card[0]);
                int card2Number = Card().returnNumber(card[4]);

                int sumF1 = 0;
                int sumF2 = 0;

                bool isFullHouse = false;
                for(int i = 0; i < 5; i++)
                {
                    int cardNumber = Card().returnNumber(card[i]);
                    if(cardNumber == card1Number)
                    {
                        sumF1++;
                    }
                    else if(cardNumber == card2Number)
                    {
                        sumF2++;
                    }
                }

                if(sumF1 == 3 && sumF2 == 2 || sumF1 == 2 && sumF2 == 3)
                {
                    isFullHouse = true;
                }

                if(isFullHouse)
                {
                    if(Compare().fullHouseCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 5; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(5);
                    }
                }
            }

            if (!isOutHand && type != 698)
            {
                int bufferIndex[5] = {0};
                int card1Number = Card().returnNumber(card[0]);
                int card2Number = Card().returnNumber(card[4]);

                int sumF1 = 0;
                int sumF2 = 0;

                bool isTiki = false;
                for(int i = 0; i < 5; i++)
                {
                    int cardNumber = Card().returnNumber(card[i]);
                    if(cardNumber == card1Number)
                    {
                        sumF1++;
                    }
                    else if(cardNumber == card2Number)
                    {
                        sumF2++;
                    }
                }

                if(sumF1 == 1 && sumF2 == 4 || sumF1 == 4 && sumF2 == 1)
                {
                    isTiki = true;
                }

                if(isTiki)
                {
                    if(RUN)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            Game().setField(0, i);
                        }
                    }

                    if(Compare().tikiCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 5; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(5);
                    }
                }
            }

            if (!isOutHand)
            {
                int bufferIndex[5] = {0};

                if(card[0]+1 == card[1] &&
                    card[0]+2 == card[2] &&
                    card[0]+3 == card[3] &&
                    card[0]+4 == card[4])
                {
                    if(type != 698)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            Game().setField(0, i);
                        }
                    }

                    if(Compare().straightFlushCompare(card))
                    {
                        for(int i = INDEX; i < 13; i++)
                        {
                            double target = player.getIndexOfCard(i);
                            for(int j = 0; j < 5; j++)
                            {
                                if(target == card[j])
                                {
                                    bufferIndex[j] = i;
                                    break;
                                }
                            }
                        }

                        for(int j = 0; j < 5; j++)
                        {
                            Game().setField(card[j], j);
                        }
                        for(int j = 0; j < 5; j++)
                        {
                            player.setPlayerArr(0, bufferIndex[j]);
                        }
                        Tool().arrange(player.getPlayer_arr(), 13);
                        isOutHand = true;
                        player.addBeginIndex(5);
                    }
                }
            }
            
            if(!isOutHand)
            {
                cout << "\n你輸入的牌型不正確 or 出的牌比場上的牌還要來得小" << endl;
                cout << "請再輸入一遍\n" << endl;
                Player().playerOutCard(player);
            }
        }
        else
        {
            cout << "\n你輸入的牌不正確 !!" << endl;
            cout << "請再輸入一遍\n" << endl;
            Player().playerOutCard(player);
        }
    }
}

void Player::FirstPlayerOutCard(Player &player)
{
    bool isCorrect = true;
    string playerOutCard;
    cout << "請輸入卡牌（此回合必須出 3.1 並且不行 pass) : ";
    getline(cin, playerOutCard);
    stringstream word(playerOutCard);

    string cardByCin[5];
    double card[5] = {0};

    int numberOfCards = 0;
    while (!word.eof())
    {
        word >> cardByCin[numberOfCards];
        numberOfCards++;
    }
    for (int i = 0; i < numberOfCards; i++)
    {
        string text = cardByCin[i];
        if (cardByCin[i] == "pass" || cardByCin[i] == "Pass" || cardByCin[i] == "PASS")
        {
            isCorrect = false;
            break;
        }

        double num = 0;
        double numPo = 0;
        for (int k = 0; k < text.size(); k++)
        {
            if (text[k] == '.')
            {
                if (int(text[k + 1]) > 48 and int(text[k + 1]) < 53)
                {
                    numPo = text[k + 1] - 48;
                }
                else
                {
                    isCorrect = false;
                }
                break;
            }
            else
            {
                if (int(text[k]) < 58 and int(text[k]) > 47)
                {
                    num = (num * 10) + (int(text[k]) - 48);
                }
                else
                {
                    isCorrect = false;
                    break;
                }
            }
        }
        num = num + (numPo * 0.1);
        if (isCorrect == true)
        {
            for (int k = 0; k < 13; k++)
            {
                if (num != player_arr[k])
                {
                    isCorrect = false;
                }
                else
                {
                    card[i] = num;
                    isCorrect = true;
                    break;
                }
            }
            for (int t = 0; t < i; t++)
            {
                if (num == card[t])
                {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect == true)
            {
                card[i] = num;
            }
            else
            {
                break;
            }
        }
    }

    if (isCorrect)
    {
        for (int i = 0; i < numberOfCards; i++)
        {
            if (card[i] != 3.1)
            {
                isCorrect = false;
            }
            else
            {
                isCorrect = true;
                break;
            }
        }
    }

    if (isCorrect)
    {
        if (numberOfCards > 1)
        {
            for (int i = 0; i < numberOfCards; i++)
            {
                for (int k = 0; k < numberOfCards; k++)
                {
                    if (i < k and card[i] > card[k])
                    {
                        double t = card[i];
                        card[i] = card[k];
                        card[k] = t;
                    }
                }
            }
        }

        int cardSize = 0;
        for(int i = 0; i < 5; i++)
        {
            if(card[i] != 0)
            {
                cardSize++;
            }
        }
        
        bool isOutHand = false;

        if(cardSize == 1)
        {
            cout << "hi1\n";
            int bufferIndex[1] = {0};
            for(int k = 0; k < 13; k++)
            {
                double target = player.getIndexOfCard(k);
                if(target == card[0])
                {
                    bufferIndex[0] = k;
                }
            }

            Game().setField(card[0], 0);
            player.setPlayerArr(0, bufferIndex[0]);
            Tool().arrange(player.getPlayer_arr(), 13);
            isOutHand = true;
            Table().getPlayer().addBeginIndex(1);
            Table().setCardsType(691);
        }
        else if(cardSize == 2)
        {
            cout << "hi2" << endl;
            int bufferIndex[2] = {0};
            int card1Num = Card().returnNumber(card[0]);
            int card2Num = Card().returnNumber(card[1]);
            if(card1Num == card2Num)
            {
                for(int i = 0; i < 13; i++)
                {
                    double target = player.getIndexOfCard(i);
                    for(int j = 0; j < 2; j++)
                    {
                        if(target == card[j])
                        {
                            bufferIndex[j] = i;
                            break;
                        }
                    }
                }

                for(int j = 0; j < 2; j++)
                {
                    Game().setField(card[j], j);
                }
                for(int j = 0; j < 2; j++)
                {
                    player.setPlayerArr(0, bufferIndex[j]);
                }
                Tool().arrange(player.getPlayer_arr(), 13);
                isOutHand = true;
                player.addBeginIndex(2);
                Table().setCardsType(692);
            }
        }
        else if(cardSize == 3)
        {
            int bufferIndex[3] = {0};
            int card1Num = Card().returnNumber(card[0]);
            int card2Num = Card().returnNumber(card[1]);
            int card3Num = Card().returnNumber(card[2]);

            if(card1Num == card2Num && card1Num == card3Num)
            {
                for(int i = 0; i < 13; i++)
                {
                    double target = player.getIndexOfCard(i);
                    for(int j = 0; j < 3; j++)
                    {
                        if(target == card[j])
                        {
                            bufferIndex[j] = i;
                            break;
                        }
                    }
                }

                for(int j = 0; j < 3; j++)
                {
                    Game().setField(card[j], j);
                }
                for(int j = 0; j < 3; j++)
                {
                    player.setPlayerArr(0, bufferIndex[j]);
                }
                Tool().arrange(player.getPlayer_arr(), 13);
                isOutHand = true;
                player.addBeginIndex(3);
                Table().setCardsType(693);
            }
        }
        else if(cardSize == 5)
        {
            int bufferIndex[5] = {0};
            int card1Number = Card().returnNumber(card[0]);
            int card2Number = Card().returnNumber(card[4]);

            int sumF1 = 0;
            int sumF2 = 0;

            bool isFullHouse = false;
            for(int i = 0; i < 5; i++)
            {
                int cardNumber = Card().returnNumber(card[i]);
                if(cardNumber == card1Number)
                {
                    sumF1++;
                }
                else if(cardNumber == card2Number)
                {
                    sumF2++;
                }
            }

            if(sumF1 == 3 && sumF2 == 2 || sumF1 == 2 && sumF2 == 3)
            {
                isFullHouse = true;
            }

            if(isFullHouse)
            {
                for(int i = 0; i < 13; i++)
                {
                    double target = player.getIndexOfCard(i);
                    for(int j = 0; j < 5; j++)
                    {
                        if(target == card[j])
                        {
                            bufferIndex[j] = i;
                            break;
                        }
                    }
                }

                for(int j = 0; j < 5; j++)
                {
                    Game().setField(card[j], j);
                }
                for(int j = 0; j < 5; j++)
                {
                    player.setPlayerArr(0, bufferIndex[j]);
                }
                Tool().arrange(player.getPlayer_arr(), 13);
                isOutHand = true;
                player.addBeginIndex(5);
                Table().setCardsType(696);
            }
            
            if (!isOutHand)
            {
                int bufferIndex[5] = {0};

                if(card[0]+1 == card[1] &&
                    card[0]+2 == card[2] &&
                    card[0]+3 == card[3] &&
                    card[0]+4 == card[4])
                {
                    for(int i = 0; i < 13; i++)
                    {
                        double target = player.getIndexOfCard(i);
                        for(int j = 0; j < 5; j++)
                        {
                            if(target == card[j])
                            {
                                bufferIndex[j] = i;
                                break;
                            }
                        }
                    }

                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(card[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        player.setPlayerArr(0, bufferIndex[j]);
                    }
                    Tool().arrange(player.getPlayer_arr(), 13);
                    isOutHand = true;
                    player.addBeginIndex(5);
                    Table().setCardsType(698);
                }
            }

            if (!isOutHand)
            {
                int bufferIndex[5] = {0};
                int card1Num = Card().returnNumber(card[0]);
                int card2Num = Card().returnNumber(card[1]);
                int card3Num = Card().returnNumber(card[2]);
                int card4Num = Card().returnNumber(card[3]);
                int card5Num = Card().returnNumber(card[4]);

                if(card1Num+1 == card2Num &&
                    card1Num+2 == card3Num &&
                    card1Num+3 == card4Num &&
                    card1Num+4 == card5Num)
                {
                    for(int i = 0; i < 13; i++)
                    {
                        double target = player.getIndexOfCard(i);
                        for(int j = 0; j < 5; j++)
                        {
                            if(target == card[j])
                            {
                                bufferIndex[j] = i;
                                break;
                            }
                        }
                    }

                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(card[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        player.setPlayerArr(0, bufferIndex[j]);
                    }
                    Tool().arrange(player.getPlayer_arr(), 13);
                    isOutHand = true;
                    player.addBeginIndex(5);
                    Table().setCardsType(694);
                }
            }

            if(!isOutHand)
            {
                int bufferIndex[5] = {0};
                int card1F = Card().returnFlower(card[0]);
                int card2F = Card().returnFlower(card[1]);
                int card3F = Card().returnFlower(card[2]);
                int card4F = Card().returnFlower(card[3]);
                int card5F = Card().returnFlower(card[4]);

                if(card1F == card2F &&
                    card1F == card3F &&
                    card1F == card4F &&
                    card1F == card5F)
                {
                    for(int i = 0; i < 13; i++)
                    {
                        double target = player.getIndexOfCard(i);
                        for(int j = 0; j < 5; j++)
                        {
                            if(target == card[j])
                            {
                                bufferIndex[j] = i;
                                break;
                            }
                        }
                    }

                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(card[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        player.setPlayerArr(0, bufferIndex[j]);
                    }
                    Tool().arrange(player.getPlayer_arr(), 13);
                    isOutHand = true;
                    player.addBeginIndex(5);
                    Table().setCardsType(695);
                }
            }

            if(!isOutHand)
            {
                int bufferIndex[5] = {0};
                int card1Number = Card().returnNumber(card[0]);
                int card2Number = Card().returnNumber(card[4]);

                int sumF1 = 0;
                int sumF2 = 0;

                bool isTiki = false;
                for(int i = 0; i < 5; i++)
                {
                    int cardNumber = Card().returnNumber(card[i]);
                    if(cardNumber == card1Number)
                    {
                        sumF1++;
                    }
                    else if(cardNumber == card2Number)
                    {
                        sumF2++;
                    }
                }

                if(sumF1 == 1 && sumF2 == 4 || sumF1 == 4 && sumF2 == 1)
                {
                    isTiki = true;
                }

                if(isTiki)
                {
                    for(int i = 0; i < 13; i++)
                    {
                        double target = player.getIndexOfCard(i);
                        for(int j = 0; j < 5; j++)
                        {
                            if(target == card[j])
                            {
                                bufferIndex[j] = i;
                                break;
                            }
                        }
                    }

                    for(int j = 0; j < 5; j++)
                    {
                        Game().setField(card[j], j);
                    }
                    for(int j = 0; j < 5; j++)
                    {
                        player.setPlayerArr(0, bufferIndex[j]);
                    }
                    Tool().arrange(player.getPlayer_arr(), 13);
                    isOutHand = true;
                    player.addBeginIndex(5);
                    Table().setCardsType(697);
                }
            }
        }
        
        if(!isOutHand)
        {
            cout << "\n你輸入的牌型不正確 or 出的牌比場上的牌還要來得小" << endl;
            cout << "請再輸入一遍\n" << endl;
            Player().FirstPlayerOutCard(player);
        }
    }
    else
    {
        cout << "\n你輸入的牌不正確 !!" << endl;
        cout << "請再輸入一遍\n" << endl;
        Player().FirstPlayerOutCard(player);
    }
}

void Player::addBeginIndex(int add)
{
    beginIndex += add;
}

int Player::getBeginIndex() const
{
    return beginIndex;
}
