#pragma once

// the size is adjustable, but the size must be even and grater than 3
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
#define LEGAL '+'

class coor
{
public:
    int row, col;
    // this struct can be defined with its values initialized
    // if no parameter passed, the default value is 0
    coor(int r = 0, int c = 0) : row(r), col(c) {}
    // equavalent to the above
    /*
    coor(int c = 0, int r = 0)
    {
        col = c.col;
        row = c.row;
    }
    */
    // coor(const coor &c) : col(c.col), row(c.row) {}
    void operator+=(const int dir[2])
    {
        row += dir[0];
        col += dir[1];
    }
};

// Define all the possible directions in which a player's move can flip
// their adversary's tiles as constant (0 – the current row/column,
// +1 – the next row/column, -1 – the previous row/column)
// left-up, up, right-up, left, right, left-down, down, right-down
const int DIRS[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

typedef enum
{
    HUMAN_VS_CPU = 1,
    HUMAN_VS_HUMAN,
    CPU_VS_CPU,
    LOAD_GAME
} GameMode;

// getter and setter functions are defined in this file
// other functions are defined in other header files
class Table
{
private:
    vector<coor> moves;
    GameMode gameMode = CPU_VS_CPU;
    char board[SIZE][SIZE];
    bool guidance = true;
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
    coor cpuPlays(unsigned miliseconds = 0);
    coor fileMoves();
    coor filePlays(unsigned miliseconds = 0);

    vector<coor> loadFromFile(string);
    GameMode getGameMode();

    // getter functions
    char getBoard(coor);
    bool getGuidance();
    char getTurn();
    char getOpponent();
    char getUserSide();

    // setter functions
    void setBoard(coor, char value);
    void setGuidance(bool);
    void setGameMode(GameMode);
    void setTurn(char);
    void switchTurn();
    void setUserSide(char);
};
