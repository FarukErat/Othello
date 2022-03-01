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
    vector<coor> moves;
    char board[SIZE][SIZE];
    bool marking = true;
    int gameMode = 3;
    int moveCount;
    char turn;
    char opponent;
    char userSide;

public:
    // Constructor
    Table();

    // bool return type functions
    bool hasTileToFlip();
    bool isLegal(coor);
    bool isOnBoard(coor);
    bool checkFile();

    // void return type functions
    void settings();
    void game();
    void printBoard();
    void flipTiles(coor);
    void marker();
    void saveMoves(string);
    void constructor();

    // int coor(user-defined) type functions
    coor userPlays();
    coor randomMoves();
    coor cpuPlays(float delay = 0);
    coor fileMoves();
    coor filePlays(float delay = 0);
    
    vector<coor> loadFromFile(string);

    // getter functions
    char getBoard(int row, int col);
    bool getMarking();
    int getGameMode();
    char getTurn();
    char getOpponent();
    char getUserSide();

    // setter functions
    void setBoard(int row, int col, char value);
    void setMarking(bool);
    void setGameMode(int);
    void setTurn(char);
    void setOpponent(char);
    void setUserSide(char);
};

Table::Table()
{
    constructor();
}

char Table::getBoard(int row, int col)
{
    if(isOnBoard({row, col}))
        return board[row][col];
    else
        return '\0';
}
bool Table::getMarking()
{
    return this->marking;
}
int Table::getGameMode()
{
    return this->gameMode;
}
char Table::getTurn()
{
    return this->turn;
}
char Table::getOpponent()
{
    return this->opponent;
}
char Table::getUserSide()
{
    return this->userSide;
}

void Table::setBoard(int row, int col, char value)
{
    if(isOnBoard({row, col}) && (value == BLACK || value == WHITE || value == EMPTY || value == LEGAL))
        board[row][col] = value;
}
void Table::setMarking(bool m)
{
    this->marking = m;
}
void Table::setGameMode(int c)
{
    this->gameMode = c;
}
void Table::setTurn(char t)
{
    this->turn = t;
}
void Table::setOpponent(char o)
{
    this->opponent = o;
}
void Table::setUserSide(char s)
{
    this->userSide = s;
}
