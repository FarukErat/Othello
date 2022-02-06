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

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif

// to generate random numbers for cpu response
#ifndef _CTIME_
#define _CTIME_
#include <ctime>
#endif

// for getch to keep the terminal still to see the result
#ifndef _INC_CONIO
#define _INC_CONIO
#include <conio.h>
#endif

// for rand()
#ifndef _CSTDLIB_
#define _CSTDLIB_
#include <cstdlib>
#endif

// for vector of valid moves of cpu
#ifndef _VECTOR_
#define _VECTOR_
#include <vector>
#endif

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
