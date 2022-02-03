#pragma once

#include "table.hpp"
/**
 * @brief Prints the board with two nested for loops
 * @param nothing
 * @return nothing
 */
void Table::printBoard()
{
    int row, col;
    // clear the screen
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
