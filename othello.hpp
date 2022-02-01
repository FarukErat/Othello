#pragma once

#include <ctime>     //to generate random numbers for cpu response
#include <conio.h>   //for getch to keep the terminal still to see the result
#include <cstdlib>   //for rand()
#include <vector>    //for vector of valid moves of cpu

#ifdef _WIN32
#include <Windows.h> //for Sleep() and system("cls")
void sleep(float sec){
    Sleep(sec * 1000);
}
#else
#include <unistd.h>
void sleep(float sec){
    usleep(sec * 1000);
}
#endif

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
//the size is adjustable, but the size must be even and grater than 3
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

#include "table.hpp"
#include "constructor.hpp"
#include "destructor.hpp"
#include "is_legal.hpp"
#include "is_on_board.hpp"
#include "has_tile_to_flip.hpp"
#include "print_board.hpp"
#include "user_plays.hpp"
#include "cpu_plays.hpp"
#include "flip_tiles.hpp"
#include "game.hpp"
#include "settings.hpp"
