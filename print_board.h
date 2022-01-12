#pragma once

#include "table.h"
/**
 * @brief: prints the board.
 *
 * @param none
 * @return nothing
 */
void Table::printBoard() //this prints the board with two nested for loops
{
    int row, col;
    system("cls");
    
    cout << " ";
    for (row = 1; row < 9; row++)
        cout << " " << row;

    cout << endl;

    for (row = 0; row < 8; row++)
    {
        cout << row + 1 << " ";
        for (col = 0; col < 8; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << row + 1;
        cout << endl;
    }
    cout << " ";
    for (row = 1; row < 9; row++)
        cout << " " << row;
}