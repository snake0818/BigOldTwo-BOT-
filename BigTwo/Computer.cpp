#include "Computer.h"
#include "Tool.h"

Computer::Computer()
{
    for(int i = 0; i < 13; i++)
    {
        computer_arr[i] = 0;
    }
    beginIndex = 0;
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
        cout << setw(6) << i;
    }
    cout << endl;
}

double* Computer::getComputer_arr()
{
	return computer_arr;
}

int Computer::returnIndex(double num) const
{
    int index;
    for(int i = 0; i < 13; i++)
    {
        if(computer_arr[i] == num)
        {
            index = i;
            break;
        }
    }
    return index;
}

void Computer::addBeginIndex(int add)
{
    beginIndex += add;
}

int Computer::getBeginIndex() const
{
    return beginIndex;
}

void Computer::setNO(int NO)
{
    this->NO = NO;
}

int Computer::getNO() const
{
    return NO;
}