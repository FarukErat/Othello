#pragma once

// for Sleep() and system("cls")
#ifdef _WIN32
#include <Windows.h>
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

// for input and output
#include <iostream>
// to deal with files
#include <fstream>
// to deal with strings
#include <string>
// to generate random numbers for cpu response
#include <ctime>
// for getch to keep the terminal still to see the result
#include <conio.h>
// for rand()
#include <cstdlib>
// for vector of valid moves of cpu
#include <vector>

using namespace std;

#include "table.hpp"
#include "constructor.cpp"
#include "is_legal.cpp"
#include "has_tile_to_flip.cpp"
#include "print_board.cpp"
#include "user_plays.cpp"
#include "random_moves.cpp"
#include "flip_tiles.cpp"
#include "game.cpp"
#include "settings.cpp"
#include "marker.cpp"
#include "save_moves.cpp"
#include "load_from_file.cpp"
#include "file_moves.cpp"
#include "check_file.cpp"
#include "get_set.cpp"
