#pragma once

#include "table.hpp"
/**
 * @brief Prints the board with two nested for loops
 * @param nothing
 * @return nothing
 */
void Table::printBoard()
{
    // at first the legal squares are marked
    marker();

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
            // in case user does not want guidiance
            // legal squares are hidden with EMPTY
            if (!getMarking())
            {
                if (getBoard(row, col) == LEGAL)
                {
                    cout << EMPTY << " ";
                    continue;
                }
            }
            // printing the tiles
            cout << getBoard(row, col) << " ";
        }
        cout << row + 1;
        cout << endl;
    }
    cout << " ";
    for (row = 1; row <= SIZE; row++)
        cout << " " << row;
}
