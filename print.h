#pragma once

#include "board.h"

void print()
{
    int i, j;

    for (i = 1; i < 9; i++)
        cout << " " << i;

    cout << endl;

    for (i = 0; i < 8; i++)
    {
        cout << i + 1 << " ";

        for (j = 0; j < 8; j++)
        {
            cout << board[j][i] << " ";
        }
        cout << i + 1 << " ";
        cout << endl;
    }

    cout << " ";
    for (i = 1; i < 9; i++)
        cout << " " << i;
}