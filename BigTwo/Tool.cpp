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

void Tool::copyDouble_arr(double sourceArr[], double targetArr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        targetArr[i] = sourceArr[i];
    }
}