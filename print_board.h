#pragma once

#include "table.h"
/**
 * @param nothing
 * @return nothing
 */
void Table::printBoard()
// this prints the board with two nested for loops
{
    int row, col;
    system("cls");

    cout << " ";
    // printing the number for a better understanding of the coordinates
    for (row = 1; row <= SIZE; row++)
        cout << " " << row;

    cout << endl;

    for (row = 0; row < SIZE; row++)
    {
        cout << row + 1 << " ";
        for (col = 0; col < SIZE; col++)
        {
            // printing the tiles
            cout << board[row][col] << " ";
        }
        cout << row + 1;
        cout << endl;
    }
    cout << " ";
    for (row = 1; row <= SIZE; row++)
        cout << " " << row;
}