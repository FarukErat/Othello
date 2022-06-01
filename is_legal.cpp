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

/**
 * @brief Checks if a move is legal in one direction.
 *
 * @param c: coordinate of the moves
 * @param dir: direction
 *
 * @return true
 * @return false
 */
bool Table::isLegal(coor c)
{
    coor curr;
    bool flip = false;

    // if the coordinate is not on the board, then it is not a legal move
    if (!this->isOnBoard(c))
        return false;

    // non-empty squares cannot be filled, thus it is not a legal move
    if (getBoard(c.row, c.col) != EMPTY && getBoard(c.row, c.col) != LEGAL)
        return false;

    // for each direction
    for (auto dir : DIRS)
    {
        flip = false;
        for (int i = 1;; i++)
        {
            // multiplying by "i" to move along the directions
            curr.row = c.row + dir[0] * i;
            curr.col = c.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(curr))
                break;

            // if the square is empty, break
            if (getBoard(curr.row, curr.col) == EMPTY || getBoard(curr.row, curr.col) == LEGAL)
                break;

            // if the square is not the same as player's, assign flip true, then continue
            if (getBoard(curr.row, curr.col) == getOpponent())
            {
                flip = true;
                continue;
            }

            // if the square is the current player's and at least one tile is flipped
            // then it is a legal move
            if (getBoard(curr.row, curr.col) == getTurn())
            {
                if (flip)
                    return true;
                else
                    break;
            }
        }
    }
    // if no legal move is found, then it is not a legal move
    return false;
}
