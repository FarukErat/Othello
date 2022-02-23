#pragma once

#include "table.hpp"
/**
 * @brief Checks if a move is legal in one direction.
 * @param c: coordinate of the moves
 * @param dir: direction
 * @return boolean
 */
bool Table::isLegal(coor c)
{
    coor temp;
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
            temp.row = c.row + dir[0] * i;
            temp.col = c.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(temp))
                break;

            // if the square is empty, break
            if (getBoard(temp.row, temp.col) == EMPTY || getBoard(temp.row, temp.col) == LEGAL)
                break;

            // if the square is not the same as player's, assign flip true, then continue
            if (getBoard(temp.row, temp.col) == getOpponent())
            {
                flip = true;
                continue;
            }

            // if the square is the current player's and at least one tile is flipped
            // then it is a legal move
            if (getBoard(temp.row, temp.col) == getTurn())
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
