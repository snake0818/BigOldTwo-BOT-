#include "Computer.h"

void Computer::print()
{
    for (int i = 0; i < 13; i++) {
        cout << setw(6) << ComputerArr[i];
    }
    cout << endl;
}
