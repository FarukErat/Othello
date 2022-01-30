#pragma once

#include <ctime>     //to generate random numbers for cpu response
#include <conio.h>   //for getch to keep the terminal still to see the result
#include <cstdlib>   //for rand()

// custom includes are at the bottom of the file

#ifdef _WIN32
#include <Windows.h> //for Sleep() and system("cls")
void sleep(unsigned sec){
    Sleep(sec * 1000);
}
#else
#include <unistd.h>
void sleep(unsigned sec){
    usleep(sec * 1000);
}
#endif

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
//the size is adjustable, but the size must be even and grater than 3
#define SIZE 8

using namespace std;

struct coor
{
	int col;
	int row;
};

// Define all the possible directions in which a player's move can flip
// their adversary's tiles as constant (0 – the current row/column, 
// +1 – the next row/column, -1 – the previous row/column)
int moveDirs[8][2] =
{
    {-1, -1},   {-1, 0},    {-1, 1},
    {0, -1},                {0, 1},
    {1, -1},    {1, 0},     {1, 1}
};

class Table
{
public:
    char board[SIZE][SIZE];
    int choice;
    char turn;
    char userSide;

    Table();
    ~Table();
    
    bool isLegal(coor);
    bool isOnBoard(coor);
    bool hasTileToFlip();

    void settings();
    void game();
    void printBoard();
    void flipTiles(coor);

    coor userPlays();
    coor cpuPlays();
};

Table::Table()
{
    this->turn = BLACK;

    // creating a blank board
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            this->board[row][col] = EMPTY;

    // adding the initial squares
    this->board[SIZE/2 - 1][SIZE/2]     = BLACK;
    this->board[SIZE/2][SIZE/2 - 1]     = BLACK;
    this->board[SIZE/2 - 1][SIZE/2 - 1] = WHITE;
    this->board[SIZE/2][SIZE/2]         = WHITE;
}

Table::~Table()
{
    system("cls");
    cout << endl
    << "The program has ended." << endl
    << "Have a good day!"
    << endl;
}

#include "is_legal.h"
#include "is_on_board.h"
#include "has_tile_to_flip.h"
#include "print_board.h"
#include "user_plays.h"
#include "cpu_plays.h"
#include "flip_tiles.h"
#include "game.h"
#include "settings.h"
