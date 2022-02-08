#pragma once

// the size is adjustable, but the size must be even and grater than 3
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
#define LEGAL '+'

struct coor
{
    int col;
    int row;
};

// Define all the possible directions in which a player's move can flip
// their adversary's tiles as constant (0 – the current row/column,
// +1 – the next row/column, -1 – the previous row/column)
const int DIRS[8][2] =
{
    {-1, -1},   {-1, 0},    {-1, 1},
    {0, -1},                {0, 1},
    {1, -1},    {1, 0},     {1, 1}
};

// getter and setter functions are defined in this file
// other functions are defined in other header files
class Table
{
private:
    char board[SIZE][SIZE];
    bool marking;
    int choice;
    char turn;
    char oponent;
    char userSide;

public:
    // Constructor and destructor
    Table();
    ~Table();

    // bool return type functions
    bool hasTileToFlip();
    bool isLegal(coor);
    bool isOnBoard(coor);

    // void return type functions
    void settings();
    void game();
    void printBoard();
    void flipTiles(coor);
    void marker();

    // int coor(user-defined) type functions
    coor userPlays();
    coor cpuPlays();

    // getter functions
    char getBoard(int row, int col);
    bool getMarking();
    int getChoice();
    char getTurn();
    char getOponent();
    char getUserSide();

    // setter functions
    void setBoard(int row, int col, char value);
    void setMarking(bool);
    void setChoice(int);
    void setTurn(char);
    void setOponent(char);
    void setUserSide(char);
};

char Table::getBoard(int row, int col)
{
    return this->board[row][col];
}
bool Table::getMarking()
{
    return this->marking;
}
int Table::getChoice()
{
    return this->choice;
}
char Table::getTurn()
{
    return this->turn;
}
char Table::getOponent()
{
    return this->oponent;
}
char Table::getUserSide()
{
    return this->userSide;
}

void Table::setBoard(int row, int col, char value)
{
    this->board[row][col] = value;
}
void Table::setMarking(bool m)
{
    this->marking = m;
}
void Table::setChoice(int c)
{
    this->choice = c;
}
void Table::setTurn(char t)
{
    this->turn = t;
}
void Table::setOponent(char o)
{
    this->oponent = o;
}
void Table::setUserSide(char s)
{
    this->userSide = s;
}
