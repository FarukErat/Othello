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
        sleep(2000);
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
        sleep(2000);
        return;
    }

    // offering some game modes to the user
    settings();
    cout << " ";

    // the game starts
    coor c;
    while (true)
    {
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
        if (getGameMode() == HUMAN_VS_CPU)
        {
            if (getTurn() == getUserSide())
            {
                c = userPlays();
            }
            else
            {
                c = cpuPlays(500);
            }
        }

        // if the choice is 2, user will play multiplayer
        if (getGameMode() == HUMAN_VS_HUMAN)
        {
            c = userPlays();
        }

        // if the choice is 3, only computer will play
        if (getGameMode() == CPU_VS_CPU)
        {
            c = cpuPlays(500);
        }

        // if the choice is 4, the game will load from a file
        if (getGameMode() == LOAD_GAME)
        {
            c = filePlays(500);
        }

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
    // to count how many black and white squares there are
    int blacks = 0;
    int whites = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (getBoard(row, col) == BLACK)
                blacks++;

            if (getBoard(row, col) == WHITE)
                whites++;
        }
    }
    cout << "\n\nG A M E   O V E R\n\n";

    // print the final result

    if (blacks == whites)
        cout << "DRAW";

    else
    {
        if (blacks > whites)
            cout << "Player black won." << endl;

        else
            cout << "Player white won." << endl;

        cout << "SCORE" << endl
             << "Black: " << blacks << endl
             << "White: " << whites;
    }
    // ask the user if he wants to save it to a file
    if (getGameMode() != LOAD_GAME)
    {
        cout << "\n\nDo you want to save the game to a file? (y/n) ";
        char choice;
        choice = getche();
        if (choice == 'y' || choice == 'Y')
        {
            cout << "\nEnter the file name: ";
            string fileName;
            cin >> fileName;
            saveMoves(fileName);
        }
    }

    cout << "\nPress any key to quit";
    getch();
}
