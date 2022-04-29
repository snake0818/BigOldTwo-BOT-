#include "Table.h"

int Table::count = 1;

void Table::Start()
{
    double* list = Game().shuffleCards();

    for (int i = 0; i < 52; i += 4) {
        player.setArr(list[i], i / 4);
        computer1.setArr(list[i + 1], i / 4);
        computer2.setArr(list[i + 2], i / 4);
        computer3.setArr(list[i + 3], i / 4);
    }
    player.arrange();
    computer1.arrange();
    computer2.arrange();
    computer3.arrange();
}

void Table::printHandCards()
{
    for (int i = 0; i < 8; i++) cout << " ";
    for (int i = 1; i <= 13; i++) {
        cout << setw(7) << i;
    }
    cout << endl;
    for (int i = 1; i <= 4 ; i++) {
        if (i == 1) cout << "Player   ";
        else cout << "Computer" << i - 1;
        for (int j = 0; j < 13; j++) {
            if (i == 1) cout << setw(7) << player.getCard(j);
            if (i == 2) cout << setw(7) << computer1.getCard(j);
            if (i == 3) cout << setw(7) << computer2.getCard(j);
            if (i == 4) cout << setw(7) << computer3.getCard(j);
        }
        cout << endl;
    }
    cout << endl;
}

int Table::whoFirst()
{
    const double firstNum = 3.1;
    if (player.find(firstNum)) {
        count = 4;
    }
    if (computer1.find(firstNum)) {
        count = 1;
    }
    if (computer2.find(firstNum)) {
        count = 2;
    }
    if (computer3.find(firstNum)) {
        count = 3;
    }
    return count;
}

bool Table::end()
{
    if (player.getNumOfCards() == 0 || computer1.getNumOfCards() == 0 || computer2.getNumOfCards() == 0 || computer3.getNumOfCards() == 0) return true;
    return false;
}
