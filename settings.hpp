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
    // checking the choice
    try
    {
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            throw "Invalid game mode";
        }
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
        sleep(2);
        exit(EXIT_FAILURE);
    }
    setGameMode(choice);
    // in case of 1, we let the user choose the side
    if (getGameMode() == 1)
    {
        cout << "\nEnter 'b' to play BLACK, 'w' to play WHITE\n";
        char side;
        cin >> side;

        if (side == 'b' || side == 'B')
            setUserSide(BLACK);

        else if (side == 'w' || side == 'W')
            setUserSide(WHITE);

        else
        {
            cout << "Invalid choice!!!";
            sleep(2);
            exit(EXIT_FAILURE);
        }
    }
    if (getGameMode() == 4)
    {
        cout << "Enter the file name: ";
        string fileName;
        cin >> fileName;
        fstream file;
        // open the file in read mode
        try
        {
            file.open(fileName, ios::in);
            if (!file.is_open())
            {
                throw "File not found";
                sleep(2);
                exit(EXIT_FAILURE);
            }
        }
        catch (const char* msg)
        {
            std::cerr << msg << '\n';
            sleep(2);
            exit(EXIT_FAILURE);
        }
        file.close();
        // check if the file has valid data
        this->moves = loadFromFile(fileName);
        try
        {
            if (!checkFile())
            {
                throw "Invalid file";
            }
        }
        catch(const char* msg)
        {
            std::cerr << msg << '\n';
            sleep(2);
            exit(EXIT_FAILURE);
        }
    }
    char guid;
    cout << endl
         << "Would you like guidance? (y/n): ";
    cin >> guid;
    if (guid == 'y' || guid == 'Y')
        setGuidance(true);
    else
        setGuidance(false);
}
