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
         << "1 for human vs cpu" << endl
         << "2 for human vs human" << endl
         << "3 for cpu vs cpu" << endl
         << "4 to load a game from a file" << endl
         << endl
         << "Enter your choice: ";

    // getting the choice
    char temp;
    temp = getche();
    GameMode choice = (GameMode)stoi(&temp);
    cout << endl;
    // checking the choice
    try
    {
        if (choice != HUMAN_VS_HUMAN && choice != HUMAN_VS_CPU && choice != CPU_VS_CPU && choice != LOAD_GAME)
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
    setGameMode((GameMode)choice);
    // in case of 1, we let the user choose the side
    if (getGameMode() == HUMAN_VS_CPU)
    {
        cout << "\nEnter 'b' to play BLACK, 'w' to play WHITE: ";
        char side;
        side = getche();
        cout << endl;

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
    if (getGameMode() == LOAD_GAME)
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
    cout << "Would you like guidance? (y/n): ";
    guid = getche();
    if (guid == 'y' || guid == 'Y')
        setGuidance(true);
    else
        setGuidance(false);
}
