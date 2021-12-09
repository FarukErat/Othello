#include <iostream>
#include <time.h>   //to generate random numbers for cpu response
#include <unistd.h> //to slow down the cpu response to make it more realistic
#include <conio.h>  //for getch to keep the terminal still to see the result

#include "board.h"
#include "coordinates.h"
#include "cpu.h"
#include "end.h"
#include "flipper.h"
#include "human.h"
#include "legal.h"
#include "possible.h"
#include "print.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    coordinates coor;

    int i;
    int j;
    int k;
    int col;
    int row;
    int choice;

    char side;
    char turn = 'B';

    for (row = 0; row < 8; row++) // creating empty squares of the board
    {
        for (col = 0; col < 8; col++)
        {
            board[col][row] = '-';
        }
    }

    board[3][3] = 'W'; // adding the initial squares
    board[4][4] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';

    cout << "Welcome to Othello Game\n\n"; // greeting the users
    cout << "Enter your choice\n\n";
    cout << "1 for human vs cpu\n";
    cout << "2 for human vs human\n";
    cout << "3 for cpu vs cpu\n\n";

    cin >> choice;

    if (choice != 1 && choice != 2 && choice != 3) // checking the response
    {
        cout << "Invalid choice!!!";
        exit(EXIT_FAILURE);
    }

    if (choice == 1) // in case of 1, we let the user choose the side
    {
        cout << "\nEnter 'b' to play BLACK, 'w' to play WHITE\n";
        cin >> side;

        if (side != 'b' && side != 'w')
        {
            cout << "Invalid choice!!!";
            exit(EXIT_FAILURE);
        }

        if (side == 'b')
            side = 'B';

        if (side == 'w')
            side = 'W';
    }

    cout << " "; // printing the initial board
    print();

    do
    {
        if (turn == 'B') // to indicate which side is playing
            cout << "\nBlack\n";
        else
            cout << "\nWhite\n";

        if (choice == 1 && turn == side) // when it is human's turn this
            coor = human(turn);          // this calls "human" func

        if (choice == 1 && turn != side)
        {
            sleep(1); // to get cpu to wait
            coor = cpu(turn);
        }

        if (choice == 2)
            coor = human(turn);

        if (choice == 3)
            coor = cpu(turn);

        col = coor.col; // getting values from the funcs
        row = coor.row;

        board[col - 1][row - 1] = turn; // chosen square, if legal, turns to
                                        // the color of the one playing

        flipper(col, row, turn); // flips the legal squares

        cout << "\n ";

        print();

        if (turn == 'B')
            turn = 'W';
        else
            turn = 'B';

        if (possible(turn) == 0) // to change the side in case that
        {                        // there is no legal moves
            if (turn == 'B')
                turn = 'W';
            else
                turn = 'B';
        }

    } while (end());

    int black = 0; // to count how many black and white squares there are
    int white = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            switch (board[i][j])
            {
            case 'B':
                black++;
                break;

            case 'W':
                white++;
                break;
            }
        }
    }
    cout << "\n\nG A M E   O V E R\n\n";

    // print the final result

    if (black == white)
        cout << "DRAW";

    else
    {
        if (black > white)
        {
            cout << "Player black won." << endl;
        }

        else
        {
            cout << "Player white won." << endl;
        }

        cout << "SCORE" << endl
             << "Black: " << black << endl
             << "White: " << white;
    }

    cout << "\n\nPress any key to quit";
    getch();

    return 0;
}