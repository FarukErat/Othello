#pragma once

#include "table.hpp"
/**
 * @brief checks if the coordinate is in range of the size which is valid coordinates
 * @param c: coordinate of the moves
 * @return boolean
 */
bool Table::isOnBoard(coor c)
{
    if (c.row >= 0 && c.row < SIZE && c.col >= 0 && c.col < SIZE)
        return true;
    else
        return false;
}
