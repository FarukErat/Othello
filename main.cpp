#include <iostream>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "board.h"
#include "coordinates.h"
#include "cpu.h"
#include "end.h"
#include "flipper.h"
#include "human.h"
#include "legal.h"
#include "possible.h"
#include "print.h"

using namespace std;

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

    for (row = 0; row < 8; row++)
    {
        for (col = 0; col < 8; col++)
        {
            board[col][row] = '-';
        }
    }

    board[3][3] = 'W';
    board[4][4] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';

    cout << "Welcome to Othello Game\n\n";
    cout << "Enter your choice\n\n";
    cout << "1 for human vs cpu\n";
    cout << "2 for human vs human\n";
    cout << "3 for cpu vs cpu\n\n";

    cin >> choice;

    if (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "Invalid choice!!!";
        exit(EXIT_FAILURE);
    }

    if (choice == 1)
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

    cout << " ";
    print();

    do
    {
        if (turn == 'B')
            cout << "\nBlack\n";
        else
            cout << "\nWhite\n";

        if (choice == 1 && turn == side)
            coor = human(turn);

        if (choice == 1 && turn != side)
        {
            sleep(1);
            coor = cpu(turn);
        }

        if (choice == 2)
            coor = human(turn);

        if (choice == 3)
            coor = cpu(turn);

        col = coor.col;
        row = coor.row;

        board[col - 1][row - 1] = turn;

        flipper(col, row, turn);

        cout << "\n ";

        print();

        if (turn == 'B')
            turn = 'W';
        else
            turn = 'B';

        if (possible(turn) == 0)
        {
            if (turn == 'B')
                turn = 'W';
            else
                turn = 'B';
        }

    } while (end());

    int black = 0;
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