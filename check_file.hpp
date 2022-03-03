#pragma once

#include "table.hpp"

bool Table::checkFile()
{
    // Check if the file is empty
    if (moves.size() == 0)
    {
        return false;
    }
    // simulating the game
    coor c;
    marker();
    while (true)
    {
        if (!hasTileToFlip())
            break;
        c = fileMoves();
        // if any illegal move is found, the file is not valid
        if (!isLegal(c))
            return false;
        // legal tiles are flipped here
        flipTiles(c);
        // switching the side when a move is done
        if (getTurn() == BLACK)
        {
            setTurn(WHITE);
        }
        else
        {
            setTurn(BLACK);
        }
        marker();
        // in case there is no legal move for the next user the side is switched
        if (!hasTileToFlip())
        {
            if (getTurn() == BLACK)
            {
                setTurn(WHITE);
            }
            else
            {
                setTurn(BLACK);
            }
            // updating the legal tiles after changing the side
            marker();
        }
    }
    // reconstructing the board
    constructor();
    return true;
}
