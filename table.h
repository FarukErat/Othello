#pragma once

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
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