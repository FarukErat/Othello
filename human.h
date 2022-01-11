#pragma once

#include "coordinates.h"
#include "legal.h"

using std::cin;
using std::cout;
using std::endl;

coordinates human(char turn) // this takes coordinates, if they are not legal
{                            // the user is warned and asked to enter again
    coordinates coor;
    bool flag;

    do
    {
        flag = false;

        cout << "col and row\n";
        cin >> coor.col >> coor.row;

        if (!legal(coor.col, coor.row, turn))
        {
            cout << "\nInvalid position!!!" << endl
                 << "Enter again\n\n";
            flag = true;
        }
    } while (flag);

    return coor;
}