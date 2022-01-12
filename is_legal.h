#pragma once

#include "table.h"
#include "is_on_board.h"

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
    {
        temp.row = c.row + dir[0];
        temp.col = c.col + dir[1];
        for (int i = 1; isOnBoard(temp); i++)
        {
            temp.row = c.row + dir[0] * i;
            temp.col = c.col + dir[1] * i;
            if (this->board[temp.row][temp.col] == EMPTY)
                break;
            if (this->board[temp.row][temp.col] != this->turn)
            {
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