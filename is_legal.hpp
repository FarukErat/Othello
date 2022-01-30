#pragma once

#include "table.hpp"
#include "is_on_board.hpp"
/**
 * @param c: coordinate of the moves
 * @return boolean
 */
bool Table::isLegal(coor c)
{
    coor temp;

    int i;
    bool flip = false;

    if (!this->isOnBoard(c))
        return false;
    if (this->board[c.row][c.col] != EMPTY)
        return false;

    for (auto dir : moveDirs)
    {   // initializing temp for the for loop
        temp.row = c.row + dir[0];
        temp.col = c.col + dir[1];
        for (int i = 1; isOnBoard(temp); i++)
        {   //multiplying by "i" to move along the directions
            temp.row = c.row + dir[0] * i;
            temp.col = c.col + dir[1] * i;
            if (this->board[temp.row][temp.col] == EMPTY)
            // if the square is empty, break
                break;
            if (this->board[temp.row][temp.col] != this->turn)
            {   // if the square is not the same as player's, assign flip true, then continue
                flip = true;
                continue;
            }
            if (this->board[temp.row][temp.col] == this->turn)
            {
                if (flip)
                    return true;
                else
                    break;
            }
        }
        flip = false;
    }
    return false;
}
