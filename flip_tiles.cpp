#pragma once

#include "table.hpp"

/**
 * @brief When called, it flips the valid tiles in the direction of the move.
 *
 * @param move: coordinates of the moves
 * @param dir: direction
 *
 * @return nothing
 */
void Table::flipTiles(coor move)
{
    coor curr, toFlip;
    bool isFlipped = false;
    // valid move guard in case there is a problem with isLegal function
    bool isValid = false;

    // for each direction
    for (auto dir : DIRS)
    {
        isFlipped = false;
        for (int i = 1;; i++)
        {
            // multiplying by 'i' to move along the directions
            curr.row = move.row + dir[0] * i;
            curr.col = move.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(curr))
                break;

            // if the square is empty, the goal is not reached
            if (getBoard(curr.row, curr.col) == EMPTY || getBoard(curr.row, curr.col) == LEGAL)
                break;

            // isFlipped changes to true if there is a tile to flip
            // when the player's square is found, there must be at least one tile to flip
            if (getBoard(curr.row, curr.col) == getOpponent())
                isFlipped = true;

            // when a square in the same color as players is found
            if (getBoard(curr.row, curr.col) == getTurn())
            {
                // if isFlipped is not true, then it is not a legal move
                if (!isFlipped)
                    break;
                isValid = true;

                // toFlip is assigned the numbers along the legal direction
                // to flip the tiles between curr and move, not including curr and move
                // [curr]-----[toFlip]-----[move]
                toFlip.row = move.row + dir[0];
                toFlip.col = move.col + dir[1];

                // assigning the squares, when the direction is horizontal
                if (dir[0] == 0)
                {
                    // assign till curr.col
                    while (toFlip.col != curr.col)
                    {
                        // incrase the number by the delta
                        setBoard(toFlip.row, toFlip.col, getTurn());
                        toFlip.col += dir[1];
                    }
                }

                // assigning the squares, when the direction is vertical
                else if (dir[1] == 0)
                {
                    // assign till curr.row
                    while (toFlip.row != curr.row)
                    {
                        // incrase the number by the delta
                        setBoard(toFlip.row, toFlip.col, getTurn());
                        toFlip.row += dir[0];
                    }
                }

                // assigning the squares, when the direction is cross
                else
                {
                    // assign till curr.row and curr.col
                    while (toFlip.row != curr.row && toFlip.col != curr.col)
                    {
                        // incrase the numbers by the delta
                        setBoard(toFlip.row, toFlip.col, getTurn());
                        toFlip.row += dir[0];
                        toFlip.col += dir[1];
                    }
                }
                break;
            }
        }
    }
    try
    {
        if (isValid)
        {
            this->moves.push_back(move);
            // the chosen square is assigned to current player's color
            setBoard(move.row, move.col, getTurn());
        }
        else
        {
            throw "flipTiles: Illegal move\n";
        }
    }
    catch (const char *msg)
    {
        std::cerr << msg;
    }
}
