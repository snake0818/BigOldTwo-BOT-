#include "Player.h"
#include "Table.h"
#include "Check.h"
#include "Card.h"

Player::Player()
{
    for (int i = 0; i < 13; i++)
    {
        player_arr[i] = 0;
    }
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
        if(Flower == 1)
        {
            cout << player_arr[i] << "  ";
        }
        else if(Flower == 2)
        {
            cout << "\e[31m" << player_arr[i] << "  \e[0m";
        }
        else if(Flower == 3)
        {
            cout << "\e[33m" << player_arr[i] << "  \e[0m";
        }
        else if(Flower == 4)
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
    isPass = false;
    isCorrect = false;
    string playerOutCard;
    getline(cin, playerOutCard);
    stringstream word(playerOutCard);

    string cardByCin[5];
    double card[5] = { 0 };

    int numberOfCards = 0;
    while (!word.eof()) {
        word >> cardByCin[numberOfCards];
        numberOfCards++;
    }

    for (int i = 0; i < numberOfCards; i++) {
        if ((cardByCin[i] == "pass" or cardByCin[i] == "Pass" or cardByCin[i] == "PASS") and
            (cardByCin[0] != "pass" or cardByCin[0] != "Pass" or cardByCin[0] != "PASS"))
        {
            isCorrect = false;
            break;
        }
        if (cardByCin[0] == "pass" or cardByCin[0] == "Pass" or cardByCin[0] == "PASS")
        {
            isPass = true;
            break;
        }

        stringstream ss(cardByCin[i]);
        char sign;
        ss >> sign >> card[i];

        isCorrect = false;
        switch (sign)
        {
            case 'd':
            case 'D':
                card[i] += 0.1;
                isCorrect = true;
                break;
            case 'c':
            case 'C':
                card[i] += 0.2;
                isCorrect = true;
                break;
            case 'h':
            case 'H':
                card[i] += 0.3;
                isCorrect = true;
                break;
            case 's':
            case 'S':
                card[i] += 0.4;
                isCorrect = true;
                break;
        }
        if (!isCorrect) break;
    }

    if (isPass) cout << "---Pass---" << endl;
    else
    {
        if (isCorrect and Game().compare(card, Table().getCardsType())
            and Table().getCardsType() == Check().checkCardsType(card, numberOfCards))
        {
            Game().setField(card);
        }
        else
        {
            cout << "Please recin" << endl;
            Player().playerOutCard();
        }
    }
}
