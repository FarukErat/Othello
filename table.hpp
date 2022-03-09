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
    // equavalent to the above
    /*
    coor(int c = 0, int r = 0)
    {
        col = c.col;
        row = c.row;
    }
    */
    // coor(const coor& c) : col(c.col), row(c.row) {}
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
