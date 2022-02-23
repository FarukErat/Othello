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
         << "4 to load a game from a file" << endl
         << endl;

    // getting the choice
    int choice;
    cin >> choice;
    setChoice(choice);
    // checking the choice
    if (getChoice() != 1 && getChoice() != 2 && getChoice() != 3 && getChoice() != 4)
    {
        cout << "Invalid choice" << endl;
        sleep(2);
        exit(0);
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
    if (getChoice() == 4)
    {
        cout << "Enter the file name: ";
        string fileName;
        cin >> fileName;
        fstream file;
        file.open(fileName, ios::in);
        if (!file.is_open())
        {
            cout << "File not found!!!";
            sleep(2);
            exit(EXIT_FAILURE);
        }
        file.close();
        this->moves = loadFromFile(fileName);
        if (!checkFile())
        {
            cout << "The file is not valid";
            sleep(2);
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
