#pragma once

#include "table.hpp"
/**
 * @param nothing
 * @return nothing
 */
void Table::settings()
// sets the menu options
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
    // checking the choice
    if (this->choice != 1 && this->choice != 2 && this->choice != 3)
    {
        cout << "Invalid choice!!!";
        exit(EXIT_FAILURE);
    }
    // in case of 1, we let the user choose the side
    if (this->choice == 1)
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
