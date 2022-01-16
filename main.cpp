#include <iostream>
#include <ctime>     //to generate random numbers for cpu response
#include <conio.h>   //for getch to keep the terminal still to see the result
#include <cstdlib>   //for rand()
#include <Windows.h> //for Sleep() and system("cls")

#include "libraries.h"

using namespace std;

int main()
{
    //! UNSTABLE, GAME ENDS WHEN NOT SUPPOSED TO
    //? most likely caused by the use of has_tile_to_flip
    Table t;
    t.game();

    return 0;
}