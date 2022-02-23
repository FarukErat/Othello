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
    if (BLACK == WHITE ||
        BLACK == EMPTY ||
        BLACK == LEGAL ||
        WHITE == EMPTY ||
        WHITE == LEGAL ||
        EMPTY == LEGAL)
    {
        cout << "The characters are not appropriate";
        sleep(2);
        return;
    }

    // offering some game modes to the user
    settings();
    cout << " ";

    coor c;
    int row, col;

    int p = 0;
    // the game starts
    while (true)
    {
        marker();
        printBoard();

        if (!hasTileToFlip())
            break;

        // print the side to indicate which side is playing
        if (getTurn() == BLACK)
            cout << "\nBlack\n";
        else
            cout << "\nWhite\n";

        // getting coordinates from the players
        // if the choice is 1, user plays against computer
        if (getChoice() == 1)
        {
            if (getTurn() == getUserSide())
            {
                c = userPlays();
            }
            else
            {
                c = cpuPlays(0.5);
            }
        }

        // if the choice is 2, user will play multiplayer
        if (getChoice() == 2)
        {
            c = userPlays();
        }

        // if the choice is 3, only computer will play
        if (getChoice() == 3)
        {
            c = cpuPlays(0.5);
        }

        // if the choice is 4, the game will load from a file
        if (getChoice() == 4)
        {
            c = filePlays(0.5);
        }

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

        // updating the legal tiles after changing the side
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
        }
    }
    // to count how many black and white squares there are
    int blackDisks = 0;
    int whiteDisks = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (getBoard(row, col) == BLACK)
                blackDisks++;

            if (getBoard(row, col) == WHITE)
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
    // ask the user if he wants to save it to a file
    if (getChoice() != 4)
    {
        cout << "\n\nDo you want to save the game to a file? (y/n) ";
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter the file name: ";
            string fileName;
            cin >> fileName;
            saveMoves(fileName);
        }
    }

    cout << "\nPress any key to quit";
    getch();
}
