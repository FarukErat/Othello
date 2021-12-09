#pragma once

#include "coordinates.h"

#include "legal.h"

using std::cout;
using std::endl;
using std::cin;

coordinates human(char turn) // this takes coordinates, if they are not legal
{                            // the user is warned and asked to enter again
    coordinates coor;
    do
    {
        do
        {
            cout << "col: ";
            cin >> coor.col;
            if (coor.col < 1 || coor.col > 8)
            {
                cout << "\nInvalid column value!!!" << endl
                     << "Enter again\n\n";
            }

        } while (coor.col < 1 || coor.col > 8);

        do
        {
            cout << "row: ";
            cin >> coor.row;

            if (coor.row < 1 || coor.row > 8)
            {
                cout << "\nInvalid row value!!!" << endl
                     << "Enter again\n\n";
            }

        } while (coor.row < 1 || coor.row > 8);

        if (!legal(coor.col, coor.row, turn))
            cout << "\nInvalid position!!!" << endl
                 << "Enter again\n\n";

    } while (!legal(coor.col, coor.row, turn));

    return coor;
}