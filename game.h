#pragma once

#include "table.h"

void Table::game()
{
    settings();
    printBoard();
    coor c;
    int row, col;
    while(true)
    {
        if (this->turn == BLACK) // to indicate which side is playing
            cout << "\nBlack\n";
        else
            cout << "\nWhite\n";

        if (this->choice == 1)
            if (this->turn == this->userSide)
            {
                c = userPlays();
            }
            else
                c = cpuPlays();

        if (this->choice == 2)
            c = userPlays();

        if (this->choice == 3)
        
            c = cpuPlays();
        
        flipTiles(c); // flips the legal squares

        cout << "\n ";

        printBoard();

        if (this->turn == BLACK)
            this->turn = WHITE;
        else
            this->turn = BLACK;

        if (!hasTileToFlip()) // to change the side in case that
        {                     // there is no legal moves
            if (this->turn == BLACK)
                this->turn = WHITE;
            else
                this->turn = BLACK;
            if (!hasTileToFlip())
                break;
        }
    }
    int blackDisks = 0; // to count how many black and white squares there are
    int whiteDisks = 0;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (this->board[row][col] == BLACK)
                blackDisks++;

            if (this->board[row][col] == WHITE)
                whiteDisks++;
        }
    }
    cout << "\n\nG A M E   O V E R\n\n";

    // print the final result

    if (blackDisks == whiteDisks)
        cout << "DRAW";

    else
    {
        if (blackDisks > whiteDisks)
        {
            cout << "Player black won." << endl;
        }

        else
        {
            cout << "Player white won." << endl;
        }

        cout << "SCORE" << endl
             << "Black: " << blackDisks << endl
             << "White: " << whiteDisks;
    }

    cout << "\n\nPress any key to quit";
    getch();
}