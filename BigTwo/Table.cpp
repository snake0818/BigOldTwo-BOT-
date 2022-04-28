#include "Table.h"

void Table::Start()
{
    for (int i = 0; i < 52; i += 4) {
        player.PlayerArr[i / 4] = *(game.shuffleCards() + i);
        computer1.ComputerArr[i / 4] = *(game.shuffleCards() + i + 1);
        computer2.ComputerArr[i / 4] = *(game.shuffleCards() + i + 2);
        computer3.ComputerArr[i / 4] = *(game.shuffleCards() + i + 3);
    }
}

void Table::arrange(double* card)
{
    const int size = 13;
    double* list = card;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[j] > list[i])
            {
                double temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }
}

void Table::Arrange()
{
    arrange(player.PlayerArr);
    arrange(computer1.ComputerArr);
    arrange(computer2.ComputerArr);
    arrange(computer3.ComputerArr);
}

void Table::printHandCards()
{
    cout << "       ";
    for (int i = 1; i <= 13; i++) {
        cout << setw(7) << i;
    }
    cout << endl;
    for (int i = 1; i <= 4 ; i++) {
        cout << " player" << i;
        for (int j = 0; j < 13; j++) {
            if (i == 1) cout << setw(7) << player.PlayerArr[j];
            if (i == 2) cout << setw(7) << computer1.ComputerArr[j];
            if (i == 3) cout << setw(7) << computer2.ComputerArr[j];
            if (i == 4) cout << setw(7) << computer3.ComputerArr[j];
        }
        cout << endl;
    }
    
    cout << endl;
}
