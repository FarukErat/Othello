#pragma once

#include "table.hpp"
/**
 * @brief this takes coordinates
 * if they are not legal the user is warned and asked to enter again
 * @param nothing
 * @return coordinates of the square the user choose
 */
coor Table::userPlays()
{
    coor c;
    do
    {
        cout << "row and col\n";
        cin >> c.row >> c.col;

        c.row--;
        c.col--;
        if (this->board[c.row][c.col] == LEGAL)
            return c;

        cout << "\nInvalid position!!!" << endl
             << "Enter again\n\n";
    } while (true);
}
