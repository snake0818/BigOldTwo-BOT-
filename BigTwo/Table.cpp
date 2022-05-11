#include "Table.h"
#include "Tool.h"

int Table::count = 1;

Player Table::getPlayer() const
{
    return player;
}

Computer Table::getComputer1() const
{
    return computer1;
}

Computer Table::getComputer2() const
{
    return computer2;
}

Computer Table::getComputer3() const
{
    return computer3;
}

void Table::start()
{
    double *list = new double[52];
    list = Game().shuffleCards();

    for (int i = 0; i < 52; i += 4) 
    {
        player.setPlayerArr(list[i], i / 4);
        computer1.setComputerArr(list[i + 1], i / 4);
        computer2.setComputerArr(list[i + 2], i / 4);
        computer3.setComputerArr(list[i + 3], i / 4);
    }

    Tool().arrange(player.getPlayer_arr(), 13);
    Tool().arrange(computer1.getComputer_arr(), 13);
    Tool().arrange(computer2.getComputer_arr(), 13);
    Tool().arrange(computer3.getComputer_arr(), 13);

    delete [] list;
}

int Table::whoFirst()
{
    const double firstNum = 3.1;
    if (player.isInPlayer_arr(firstNum))
    {
        count = 4;
    }
    if (computer1.isInComputer_arr(firstNum))
    {
        count = 1;
    }
    if (computer2.isInComputer_arr(firstNum))
    {
        count = 2;
    }
    if (computer3.isInComputer_arr(firstNum))
    {
        count = 3;
    }
    return count;
}

bool Table::end()
{
    if (player.getHandCardsSize() == 0 || computer1.getHandCardsSize() == 0 || computer2.getHandCardsSize() == 0 || computer3.getHandCardsSize() == 0)
        return true;
    return false;
}