#pragma once

//the size is adjustable, but the size must be even and grater than 3
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'

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
    char oponent;
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
