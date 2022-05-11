#include <iostream>
#include <iomanip>
using namespace std;

#include "Computer.h"
#include "Tool.h"

Computer::Computer()
{
    for(int i = 0; i < 13; i++)
    {
        computer_arr[i] = 0;
    }
}

void Computer::setComputerArr(double num, int index)
{
    computer_arr[index] = num;
}

bool Computer::isInComputer_arr(double num)
{
    for (int i = 0; i < 13; i++)
    {
        if (computer_arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int Computer::getHandCardsSize() const
{
    int count = 0;
    for (int i = 0; i < 13; i++)
    {
        if (computer_arr[i] != 0)
        {
            count++;
        }
    }
    return count;
}

double Computer::getIndexOfCard(int index) const
{
    return computer_arr[index];
}

// test
void Computer::print()
{
    for(auto i:computer_arr)
    {
        cout << i << endl;
    }
    cout << endl;
}
