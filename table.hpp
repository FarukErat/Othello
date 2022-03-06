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
    // this struct can be defined with its values initialized
    // if no parameter passed, the default value is 0
    coor(int c = 0, int r = 0) : col(c), row(r) {}
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
    bool guidance = true;
    int gameMode = 3;
    int moveCount;
    char turn;
    char opponent;
    char userSide = BLACK;

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
    bool getGuidance();
    int getGameMode();
    char getTurn();
    char getOpponent();
    char getUserSide();

    // setter functions
    void setBoard(int row, int col, char value);
    void setGuidance(bool);
    void setGameMode(int);
    void setTurn(char);
    void switchTurn();
    void setUserSide(char);
};

Table::Table()
{
    constructor();
}

char Table::getBoard(int row, int col)
{
    try
    {
        if (isOnBoard({row, col}))
            return board[row][col];
        else
            throw "getBoard: Invalid row or column";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
bool Table::getGuidance()
{
    return this->guidance;
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
    try
    {
        if (isOnBoard({row, col}) && (value == BLACK ||
                                      value == WHITE ||
                                      value == EMPTY ||
                                      value == LEGAL))
            board[row][col] = value;
        else
            throw "setBoard: Invalid row or column or value";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
void Table::setGuidance(bool m)
{
    this->guidance = m;
}
void Table::setGameMode(int c)
{
    try
    {
        if (c == 1 || c == 2 || c == 3 || c == 4)
            this->gameMode = c;
        else
            throw "setGameMode: Invalid game mode";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
void Table::setTurn(char t)
{
    try
    {
        if (t == BLACK)
        {
            this->turn = BLACK;
            this->opponent = WHITE;
        }
        else if (t == WHITE)
        {
            this->turn = WHITE;
            this->opponent = BLACK;
        }
        else
            throw "setTurn: Invalid turn";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}

void Table::switchTurn()
{
    if (getTurn() == BLACK)
    {
        setTurn(WHITE);
    }
    else
    {
        setTurn(BLACK);
    }
    // update legal moves after switching turns
    marker();
}

void Table::setUserSide(char s)
{
    try
    {
        if (s == BLACK || s == WHITE)
            this->userSide = s;
        else
            throw "setUserSide: Invalid side";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
