#pragma once

// for input and output
#include <iostream>
// to deal with files
#include <fstream>
// to generate random numbers for cpu response
#include <ctime>
// for getch to keep the terminal still to see the result, for getche
#include <conio.h>
// for rand()
#include <cstdlib>
// for vector of valid moves of cpu
#include <vector>
// for strtok
#include <cstring>

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

/*
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
inline void delay(unsigned long ms)
{
    Sleep(ms);
}

#else // presume POSIX
#include <unistd.h>
inline void delay(unsigned long ms)
{
    usleep(ms);
}
#endif
*/
