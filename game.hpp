#pragma once

#include "table.hpp"
/**
 * @brief The game is processed here.
 * @param none
 * @return nothing
 */
void Table::game()
{
    if (SIZE % 2 != 0 || SIZE <= 2)
    {
        cout << "The size of the board is not appropriate";
        sleep(2);
        return;
    }
    if (BLACK == WHITE
     || BLACK == EMPTY
     || BLACK == LEGAL
     || WHITE == EMPTY
     || WHITE == LEGAL
     || EMPTY == LEGAL)
    {
        cout << "The characters are not appropriate";
        sleep(2);
        return;
    }

    // offering some game modes to the user
    settings();
    cout << " ";

    // printing the initial board
    printBoard();

    coor c;
    int row, col;
    while (true)
    {
        // print the side to indicate which side is playing
        if (this->turn == BLACK)
            cout << "\nBlack\n";
        else
            cout << "\nWhite\n";

        // getting coordinates from the players
        if (this->choice == 1)
        {
            if (this->turn == this->userSide)
                c = userPlays();
            else
                c = cpuPlays();
        }

        if (this->choice == 2)
            c = userPlays();

        if (this->choice == 3)
            c = cpuPlays();

        // legal tiles are flipped here
        flipTiles(c);

        // switching the side when a move is done
        if (this->turn == BLACK)
        {
            this->turn = WHITE;
            this->oponent = BLACK;
        }
        else
        {
            this->turn = BLACK;
            this->oponent = WHITE;
        }

        printBoard();

        // in case there is no legal move for the next user the side is switched
        if (!hasTileToFlip())
        {
            if (this->turn == BLACK)
            {
                this->turn = WHITE;
                this->oponent = BLACK;
            }
            else
            {
                this->turn = BLACK;
                this->oponent = WHITE;
            }

            printBoard();
            // even after switching, if there is no legal move, game is over
            if (!hasTileToFlip())
                break;
        }
    }
    // to count how many black and white squares there are
    int blackDisks = 0;
    int whiteDisks = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
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
            cout << "Player black won." << endl;

        else
            cout << "Player white won." << endl;

        cout << "SCORE" << endl
             << "Black: " << blackDisks << endl
             << "White: " << whiteDisks;
    }

    cout << "\n\nPress any key to quit";
    getch();
}
