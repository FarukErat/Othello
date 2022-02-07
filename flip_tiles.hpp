#pragma once

#include "table.hpp"
/**
 * @brief When called, it flips the valid tiles in the direction of the move.
 * @param move: coordinates of the moves
 * @param dir: direction
 * @return nothing
 */
void Table::flipTiles(coor move)
{
    coor c, temp;
    bool flag = false;

    // for each direction
    for (auto dir : Table::dirs)
    {
        flag = false;
        for (int i = 1;; i++)
        {
            // multiplying by 'i' to move along the directions
            c.row = move.row + dir[0] * i;
            c.col = move.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(c))
                break;

            // if the square is empty, the goal is not reached
            if (getBoard(c.row, c.col) == EMPTY || getBoard(c.row, c.col) == LEGAL)
                break;

            // flag changes to true if there is a tile to flip
            // when the player's square is found, there must be at least one tile to flip
            if (getBoard(c.row, c.col) == getOponent())
                flag = true;

            // when a square in the same color as players is found
            if (getBoard(c.row, c.col) == getTurn())
            {
                // if flag is not true, then it is not a legal move
                if (!flag)
                    break;

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
                        setBoard(temp.row, temp.col, getTurn());
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
                        setBoard(temp.row, temp.col, getTurn());
                        temp.row += dir[0];
                    }
                }

                // assigning the squares, when the direction is cross
                else
                {
                    // assign till c.row and c.col
                    while (temp.row != c.row && temp.col != c.col)
                    {
                        // incrase the numbers by the delta
                        setBoard(temp.row, temp.col, getTurn());
                        temp.row += dir[0];
                        temp.col += dir[1];
                    }
                }
                break;
            }
        }
    }
    // the chosen square is assigned to current player's color
    setBoard(move.row, move.col, getTurn());
    Table::dirs.clear();
}
