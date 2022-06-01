#pragma once

#include "table.hpp"

/**
 * @brief pre-plays the moves from a file to see if the file has valid moves
 *
 * @param none
 *
 * @return true
 * @return false
 */
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
        switchTurn();
        // in case there is no legal move for the next user the side is switched
        if (!hasTileToFlip())
        {
            switchTurn();
        }
    }
    // reconstructing the board
    constructor();
    return true;
}
