#pragma once

#include "table.hpp"

Table::Table()
{
    this->turn = BLACK;
    this->oponent = WHITE;

    // creating a blank board
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            this->board[row][col] = EMPTY;

    // adding the initial squares
    this->board[SIZE/2 - 1][SIZE/2]     = BLACK;
    this->board[SIZE/2][SIZE/2 - 1]     = BLACK;
    this->board[SIZE/2 - 1][SIZE/2 - 1] = WHITE;
    this->board[SIZE/2][SIZE/2]         = WHITE;
}
