#pragma once

#include "table.h"
/**
 * @param move: coordinates of the moves
 * @return nothing
 */
void Table::flipTiles(coor move)
// flips the valid tiles
{
    coor c, temp;
    bool flag = false;
    int i;

    for (auto dir : moveDirs) // for each directions
    {
        // initializition of i and j before the for loop to check the conditions in the loop
        c.row = move.row + dir[0];
        c.col = move.col + dir[1];
        for (int i = 1; isOnBoard(c); i++)
        {
            // multiplying by 'i' to move along the directions
            c.row = move.row + dir[0] * i;
            c.col = move.col + dir[1] * i;
            if (this->board[c.row][c.col] == EMPTY)
                // if the square is empty, break
                break;
            if (this->board[c.row][c.col] != this->turn)
                flag = true;
            // it changes to true if there is a tile to flip
            // when the player's square is found, there must be at least one tile to flip
            if (this->board[c.row][c.col] == this->turn) // when a square in the same color as players is found
            {
                if (!flag)
                    break;
                // temp.row and temp.col are assigned the number along the legal direction
                temp.row = move.row + dir[0];
                temp.col = move.col + dir[1];
                // assigning the squares, when the direction is horizontal
                if (dir[0] == 0)
                {
                    while (temp.col != c.col) // assign till c.col
                    {
                        board[temp.row][temp.col] = this->turn;
                        // incrase the number by the delta
                        temp.col += dir[1];
                    }
                }
                // assigning the squares, when the direction is vertical
                if (dir[1] == 0)
                {
                    while (temp.row != c.row) // assign till c.row
                    {
                        board[temp.row][temp.col] = this->turn;
                        // incrase the number by the delta
                        temp.row += dir[0];
                    }
                }
                // assigning the squares, when the direction is cross
                else
                {
                    while (temp.row != c.row && temp.col != c.col) // assign till i or j
                    {
                        board[temp.row][temp.col] = this->turn;
                        // incrase the numbers by the delta
                        temp.row += dir[0];
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