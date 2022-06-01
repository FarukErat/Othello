#pragma once

#include "table.hpp"

/**
 * @brief Legal moves are marked with LEGAL
 *
 * @param none
 *
 * @return nothing
 */
void Table::marker()
{
    // unmarkes all the old marked squares
    /////////////////////////////////////////////////////
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (getBoard(row, col) == LEGAL)
                setBoard(row, col, EMPTY);
        }
    }
    /////////////////////////////////////////////////////

    // marks all the legal squares for the current player
    /////////////////////////////////////////////////////
    coor c;
    // all the squares are checked
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            c.row = row;
            c.col = col;
            if (isLegal(c))
                setBoard(c.row, c.col, LEGAL);
        }
    }
    /////////////////////////////////////////////////////
}
