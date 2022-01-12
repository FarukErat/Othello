#pragma once

#include "table.h"
/**
 * @brief: settings menu.
 *
 * @param none
 * @return nothing
 */
void Table::settings()
{
    cout << endl // greeting the users
         << "Welcome to Othello Game" << endl
         << endl
         << "Enter your choice" << endl
         << endl
         << "1 for human vs cpu" << endl
         << "2 for human vs human" << endl
         << "3 for cpu vs cpu" << endl
         << endl;

    cin >> this->choice;

    if (this->choice != 1 && this->choice != 2 && this->choice != 3) // checking the response
    {
        cout << "Invalid choice!!!";
        exit(EXIT_FAILURE);
    }

    if (this->choice == 1) // in case of 1, we let the user choose the side
    {
        cout << "\nEnter 'b' to play BLACK, 'w' to play WHITE\n";
        cin >> this->userSide;

        if (this->userSide != 'b' && this->userSide != 'w')
        {
            cout << "Invalid choice!!!";
            exit(EXIT_FAILURE);
        }

        if (this->userSide == 'b')
            this->userSide = BLACK;

        if (this->userSide == 'w')
            this->userSide = WHITE;
    }
}