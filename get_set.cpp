#pragma once

#include "table.hpp"

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
