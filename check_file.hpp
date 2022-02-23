#pragma once

#include "table.hpp"

bool Table::checkFile()
{
    if (moves.size() == 0)
    {
        return false;
    }
    coor c;
    marker();
    while (true)
    {
        if (!hasTileToFlip())
            break;
        c = fileMoves();
        if (!isLegal(c))
            return false;
        // legal tiles are flipped here
        flipTiles(c);
        // switching the side when a move is done
        if (getTurn() == BLACK)
        {
            setTurn(WHITE);
            setOponent(BLACK);
        }
        else
        {
            setTurn(BLACK);
            setOponent(WHITE);
        }
        marker();
        // in case there is no legal move for the next user the side is switched
        if (!hasTileToFlip())
        {
            if (getTurn() == BLACK)
            {
                setTurn(WHITE);
                setOponent(BLACK);
            }
            else
            {
                setTurn(BLACK);
                setOponent(WHITE);
            }
            // updating the legal tiles after changing the side
            marker();
        }
    }
    // reconstructing the board
    constructor();
    return true;
}