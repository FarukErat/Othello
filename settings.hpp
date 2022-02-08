#pragma once

#include "table.hpp"
/**
 * @brief lets user set the table
 * @param nothing
 * @return nothing
 */
void Table::settings()
{
    // greeting the users
    cout << "Welcome to Othello Game" << endl
         << endl
         << "Enter your choice" << endl
         << endl
         << "1 for human vs cpu" << endl
         << "2 for human vs human" << endl
         << "3 for cpu vs cpu" << endl
         << endl;

    // getting the choice
    int choice;
    cin >> choice;
    setChoice(choice);
    // checking the choice
    if (getChoice() != 1 && getChoice() != 2 && getChoice() != 3)
    {
        cout << "Invalid choice!!!";
        exit(EXIT_FAILURE);
    }
    // in case of 1, we let the user choose the side
    if (getChoice() == 1)
    {
        cout << "\nEnter 'b' to play BLACK, 'w' to play WHITE\n";
        char side;
        cin >> side;
        setUserSide(side);

        if (getUserSide() == 'b' || getUserSide() == 'B')
            setUserSide(BLACK);

        else if (getUserSide() == 'w' || getUserSide() == 'W')
            setUserSide(WHITE);

        else
        {
            cout << "Invalid choice!!!";
            exit(EXIT_FAILURE);
        }
    }
    char guidance;
    cout << endl
         << "Would you like guidance? (y/n): ";
    cin >> guidance;
    if (guidance == 'y' || guidance == 'Y')
        setMarking(true);
    else
        setMarking(false);
}
