#include "Player.h"
#include "Table.h"
#include "Check.h"
#include "Card.h"
double Player::player_arr[13] = {0};
bool Player::wasDo = false;
Player::Player()
{
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

void Player::playerOutCard()
{
    const int type = Table().getCardsType();

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
                RUN = true;
            }
            else if(type == 692 && cardSize == 2)
            {
                RUN = true;
            }
            else if(type == 693 && cardSize == 3)
            {
                RUN = true;
            }
            else if(type == 694 && cardSize == 5)
            {
                RUN = true;
            }
            else if(type == 695 && cardSize == 5)
            {
                RUN = true;
            }
            else if(type == 696 && cardSize == 5)
            {
                RUN = true;
            }
            else
            {
                cout<<"你輸入的牌型不正確 or 出的牌比場上的牌還要來得小"<<endl;
                cout<<"請再輸入一遍"<<endl;
                Player().playerOutCard();
            }
        }
        else
        {
            cout << "The input is error !!" << endl;
            cout << "Please enter again" << endl;
            Player().playerOutCard();
        }
    }
}

void Player::FirstPlayerOutCard()
{
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
        if (cardByCin[i] == "pass" or cardByCin[i] == "Pass" or cardByCin[i] == "PASS")
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
    if (isCorrect == true)
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
        // if(){
        //     //檢測牌
        // }
        // else{
        //     cout<<"The input is error !!"<<endl;
        //     cout<<"Please enter again"<<endl;
        //     Player().playerOutCard();
        // }
    }
    else
    {
        cout << "The input is error !!" << endl;
        cout << "Please enter again" << endl;
        Player().playerOutCard();
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