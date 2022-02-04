#pragma once

#ifdef _WIN32
#include <Windows.h> //for Sleep() and system("cls")
void sleep(float sec)
{
    Sleep(sec * 1000);
}
#else
#include <unistd.h>
void sleep(float sec)
{
    usleep(sec * 1000);
}
#endif

#include <ctime>   //to generate random numbers for cpu response
#include <conio.h> //for getch to keep the terminal still to see the result
#include <cstdlib> //for rand()
#include <vector>  //for vector of valid moves of cpu

using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
#include "marker.hpp"
