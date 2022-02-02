#pragma once

#include "table.hpp"
/**
 * @brief flips the valid tiles
 * @param move: coordinates of the moves
 * @return nothing
 */
void Table::flipTiles(coor move, int dir[2])
{
    coor c, temp;
    bool flag = false;
    int i;

    for (int i = 1;; i++)
    {
        // multiplying by 'i' to move along the directions
        c.row = move.row + dir[0] * i;
        c.col = move.col + dir[1] * i;

        // if the square is not on the board, then it is not a legal move
        if (!isOnBoard(c))
            return;

        // if the square is empty, break
        if (this->board[c.row][c.col] == EMPTY)
            return;

        // it changes to true if there is a tile to flip
        // when the player's square is found, there must be at least one tile to flip
        if (this->board[c.row][c.col] == this->oponent)
            flag = true;

        // when a square in the same color as players is found
        if (this->board[c.row][c.col] == this->turn)
        {
            if (!flag)
                return;

            // temp.row and temp.col are assigned the number along the legal direction
            temp.row = move.row + dir[0];
            temp.col = move.col + dir[1];

            // assigning the squares, when the direction is horizontal
            if (dir[0] == 0)
            {
                // assign till c.col
                while (temp.col != c.col)
                {
                    // incrase the number by the delta
                    board[temp.row][temp.col] = this->turn;
                    temp.col += dir[1];
                }
            }
            
            // assigning the squares, when the direction is vertical
            else if (dir[1] == 0)
            {
                // assign till c.row
                while (temp.row != c.row)
                {
                    // incrase the number by the delta
                    board[temp.row][temp.col] = this->turn;
                    temp.row += dir[0];
                }
            }

            // assigning the squares, when the direction is cross
            else
            {
                // assign till i or j
                while (temp.row != c.row && temp.col != c.col)
                {
                    // incrase the numbers by the delta
                    board[temp.row][temp.col] = this->turn;
                    temp.row += dir[0];
                    temp.col += dir[1];
                }
            }
            break;
        }
    }
    // the color of the one playing chosen square, if legal, turns to
    this->board[move.row][move.col] = this->turn;
}
