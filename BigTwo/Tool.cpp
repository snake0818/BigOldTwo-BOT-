#include "Tool.h"

Tool::Tool() {}

void Tool::arrange(double *card, int size)
{
    double temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (card[j] > card[i])
            {
                temp = card[j];
                card[j] = card[i];
                card[i] = temp;
            }
        }
    }
}

void Tool::postZero(double* card, int size)
{
    arrange(card, size);
    while (card[0] == 0)
    {
        for (int i = 1; i < size; i++)
        {
            card[i - 1] = card[i];
        }
        card[4] = 0;
    }
}

void Tool::copyDouble_arr(double sourceArr[], double targetArr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        targetArr[i] = sourceArr[i];
    }
}

void Tool::Print(double* cards, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(6) << cards[i];
    }
    cout << endl;
}
