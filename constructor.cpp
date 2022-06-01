#pragma once

#include "table.hpp"

/**
 * @brief constructor is defined here to be able to reconstruct the board
 *
 * @param none
 *
 * @return nothing
 */
void Table::constructor()
{
    this->moveCount = 0;

    // player black starts the game
    setTurn(BLACK);

    // creating a blank board
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            setBoard(row, col, EMPTY);

    // adding the initial squares
    setBoard(SIZE/2 - 1, SIZE/2,     BLACK);
    setBoard(SIZE/2, SIZE/2 - 1,     BLACK);
    setBoard(SIZE/2 - 1, SIZE/2 - 1, WHITE);
    setBoard(SIZE/2, SIZE/2,         WHITE);

    // mark legal moves initially
    marker();
}
