#pragma once

#include "table.hpp"
/**
 * @param nothing
 * @return coordinates of the square the user choose
 */
coor Table::userPlays()
// this takes coordinates, if they are not legal the user is warned and asked to enter again
{
    coor c;
    bool flag;

    do
    {
        flag = false;

        cout << "row and col\n";
        cin  >> c.row >> c.col;

        c.row--;
        c.col--;

        if (!isLegal(c))
        {
            cout << "\nInvalid position!!!" << endl
                 << "Enter again\n\n";
            flag = true;
        }
    } while (flag);
    return c;
}
