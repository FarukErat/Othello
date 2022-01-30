#pragma once

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
