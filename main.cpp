#include <iostream>

#include "othello.hpp"

using namespace std;

int main()
{
    //! UNSTABLE, GAME ENDS WHEN NOT SUPPOSED TO
    //? most likely caused by the use of has_tile_to_flip
    Table t;
    t.game();

    return 0;
}
