#include "Computer.h"

void Computer::print()
{
    for (int i = 0; i < 13; i++) {
        cout << setw(6) << computerArr[i];
    }
    cout << endl;
}

Computer::Computer()
{

}

Computer::Computer(double card[])
{
    for (int i = 0; i < 13; i++) {
        computerArr[i] = card[i];
    }
}
