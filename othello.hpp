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
#include "constructor.hpp"
#include "is_legal.hpp"
#include "has_tile_to_flip.hpp"
#include "print_board.hpp"
#include "user_plays.hpp"
#include "random_moves.hpp"
#include "flip_tiles.hpp"
#include "game.hpp"
#include "settings.hpp"
#include "marker.hpp"
#include "save_moves.hpp"
#include "load_from_file.hpp"
#include "file_moves.hpp"
#include "check_file.hpp"
