#pragma once

#include "table.hpp"

Table::Table()
{
    constructor();
}

char Table::getBoard(coor c)
{
    try
    {
        if (isOnBoard(c))
            return board[c.row][c.col];
        else
            throw "getBoard: Invalid row or column\n";
    }
    catch (const char *msg)
    {
        std::cerr << msg;
    }
    return '\0';
}

bool Table::getGuidance()
{
    return this->guidance;
}

GameMode Table::getGameMode()
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

void Table::setBoard(coor c, char value)
{
    try
    {
        if (isOnBoard(c) && (value == BLACK ||
                                      value == WHITE ||
                                      value == EMPTY ||
                                      value == LEGAL))
            board[c.row][c.col] = value;
        else
            throw "setBoard: Invalid row or column or value\n";
    }
    catch (const char *msg)
    {
        std::cerr << msg;
    }
}

void Table::setGuidance(bool m)
{
    this->guidance = m;
}

void Table::setGameMode(GameMode gm)
{
    try
    {
        if (gm == HUMAN_VS_HUMAN || gm == HUMAN_VS_CPU || gm == CPU_VS_CPU || gm == LOAD_GAME)
            this->gameMode = gm;
        else
            throw "setGameMode: Invalid game mode\n";
    }
    catch (const char *msg)
    {
        std::cerr << msg;
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
            throw "setTurn: Invalid turn\n";
    }
    catch (const char *msg)
    {
        std::cerr << msg;
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
            throw "setUserSide: Invalid side\n";
    }
    catch (const char *msg)
    {
        std::cerr << msg;
    }
}
