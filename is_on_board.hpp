#pragma once

#include "table.hpp"
/**
 * @param c: coordinate of the moves
 * @return boolean
 */
bool Table::isOnBoard(coor c)
// checks if the coordinate is between 1 and 8 which is valid coordinate
{
    if (c.row >= 0 && c.row < SIZE && c.col >= 0 && c.col < SIZE)
        return true;
    else
        return false;
}
