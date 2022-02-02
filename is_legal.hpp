#pragma once

#include "table.hpp"
/**
 * @param c: coordinate of the moves
 * @return boolean
 */
bool Table::isLegal(coor c, int dir[2])
{
    coor temp;

    bool flip = false;

    if (!this->isOnBoard(c))
        return false;
    if (this->board[c.row][c.col] != EMPTY)
        return false;

    for (auto dir : moveDirs)
    {
        flip = false;
        for (int i = 1;; i++)
        {
            // multiplying by "i" to move along the directions
            temp.row = c.row + dir[0] * i;
            temp.col = c.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(temp))
                break;

            // if the square is empty, break
            if (this->board[temp.row][temp.col] == EMPTY)
                break;

            // if the square is not the same as player's, assign flip true, then continue
            if (this->board[temp.row][temp.col] == this->oponent)
            {
                flip = true;
                continue;
            }
            // if the square is the current player's and at least one tile is flipped
            // then it is a legal move
            if (this->board[temp.row][temp.col] == this->turn)
            {
                if (flip)
                    return true;
                else
                    break;
            }
        }
    }
    return false;
}
