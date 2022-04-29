#include "Computer.h"

void Computer::setArr(double Num, int index)
{
    ComputerArr[index] = Num;
}

bool Computer::find(double num)
{
    for (int i = 0; i < 13; i++) {
        if (ComputerArr[i] == num) return true;
    }
    return false;
}

int Computer::getNumOfCards() const
{
    int count = 0;
    for (int i = 0; i < 13; i++) {
        if (ComputerArr[i] != 0) count++;
    }
    return count;
}
void Computer::arrange()
{
    const int size = 13;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ComputerArr[j] > ComputerArr[i])
            {
                double temp = ComputerArr[j];
                ComputerArr[j] = ComputerArr[i];
                ComputerArr[i] = temp;
            }
        }
    }
}

double Computer::getCard(int index)
{
    return ComputerArr[index];
}

void Computer::print()
{
    for (int i = 0; i < 13; i++) {
        cout << setw(6) << ComputerArr[i];
    }
    cout << endl;
}
