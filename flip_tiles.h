#pragma once

#include "table.h"
/**
 * @brief: flips the valid tiles.
 *
 * @param move: coordinates of the moves
 * @return nothing
 */
void Table::flipTiles(coor move)
{
    coor c, temp;
    bool flag = false;
    int i;

    for (auto dir : moveDirs)
    {
        c.row = move.row + dir[0];
        c.col = move.col + dir[1];
        for (int i = 1; isOnBoard(c); i++)
        {
            c.row = move.row + dir[0] * i;
            c.col = move.col + dir[1] * i;
            if (this->board[c.row][c.col] == EMPTY)
                break;
            if (this->board[c.row][c.col] != this->turn)
                flag = true;
            if (this->board[c.row][c.col] == this->turn)
            {
                if (!flag)
                    break;
                temp.row = move.row + dir[0];
                temp.col = move.col + dir[1];

                if (dir[0] == 0) // assigning the squares, when the direction is horizontal
                {
                    while (temp.col != c.col) // assign till i
                    {
                        board[temp.row][temp.col] = this->turn;
                        temp.col += dir[1]; // incrase the number by the delta
                    }
                }

                if (dir[1] == 0) // assigning the squares, when the direction is vertical
                {
                    while (temp.row != c.row) // assign till j
                    {
                        board[temp.row][temp.col] = this->turn;
                        temp.row += dir[0]; // incrase the number by the delta
                    }
                }

                else // assigning the squares, when the direction is cross
                {
                    while (temp.row != c.row && temp.col != c.col) // assign till i or j
                    {
                        board[temp.row][temp.col] = this->turn;

                        temp.row += dir[0]; // incrase the numbers by the delta
                        temp.col += dir[1];
                    }
                }

                break;
            }
        }
    }
    // the color of the one playing chosen square, if legal, turns to
    this->board[move.row][move.col] = this->turn;
}