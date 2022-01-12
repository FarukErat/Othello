#pragma once

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'

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
    char board[8][8];
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
    for (int row = 0; row < 8; row++)
        for (int col = 0; col < 8; col++)
            this->board[row][col] = EMPTY;

    // adding the initial squares
    this->board[3][4] = BLACK;
    this->board[4][3] = BLACK;
    this->board[3][3] = WHITE;
    this->board[4][4] = WHITE;
}

Table::~Table()
{
    system("cls");
    cout << endl
    << "The program has ended." << endl
    << "Have a good day!"
    << endl;
}