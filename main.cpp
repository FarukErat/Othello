#include <iostream>
#include <ctime>     //to generate random numbers for cpu response
#include <conio.h>   //for getch to keep the terminal still to see the result
#include <cstdlib>   //for rand()

#ifdef _WIN32
#include <Windows.h> //for Sleep() and system("cls")
void sleep(unsigned sec){
    Sleep(sec * 1000);
}
#else
#include <unistd.h>
void sleep(unsigned sec){
    usleep(sec * 1000);
}
#endif

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