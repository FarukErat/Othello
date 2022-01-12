#pragma once

#include "table.h"
/**
 * @brief: checks if the coordinate is between 1 and 8 which is valid coordinate.
 *
 * @param c: coordinate of the moves
 * @return boolean
 */
bool Table::isOnBoard(coor c)
{
    if (c.row >= 0 && c.row < 8 && c.col >= 0 && c.col < 8)
        return true;
    else
        return false;
}