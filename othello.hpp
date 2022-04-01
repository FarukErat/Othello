#pragma once

#include <iostream> // for input and output
#include <fstream>  // to deal with files
#include <ctime>    // to generate random numbers for cpu response
#include <conio.h>  // for getch to keep the terminal still to see the result and for getche
#include <cstdlib>  // for rand()
#include <vector>   // for vector of valid moves of cpu
#include <cstring>  // for strtok

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
inline void sleep(unsigned ms)
{
    Sleep(ms);
}

#else // presume POSIX
#include <unistd.h>
inline void sleep(unsigned ms)
{
    usleep(ms);
}
#endif

/**
 * @brief delays the program for a given amount of time in milliseconds
 * However, cpu load is too high, so it is not prefered to use this function
 *
 * @param milliseconds
 */
/*
void sleep(unsigned milliseconds)
{
    clock_t time_end = clock() + milliseconds;
    while (clock() < time_end); // wait until time_end
}
*/

using namespace std;

#include "table.hpp"
#include "get_set.cpp"
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
