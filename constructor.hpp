#pragma once

#include "table.hpp"

void Table::constructor()
{
    this->moveCount = -1;
    
    // player black starts the game
    setTurn(BLACK);
    setOponent(WHITE);

    // creating a blank board
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            setBoard(row, col, EMPTY);

    // adding the initial squares
    setBoard(SIZE/2 - 1, SIZE/2,     BLACK);
    setBoard(SIZE/2, SIZE/2 - 1,     BLACK);
    setBoard(SIZE/2 - 1, SIZE/2 - 1, WHITE);
    setBoard(SIZE/2, SIZE/2,         WHITE);
}
