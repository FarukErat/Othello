#pragma once

#include "table.h"
/**
 * @brief: lets cpu play randomly
 *
 * @param none
 * @return the coordinates cpu choose
 */
coor Table::cpuPlays()
{
    coor c;

    int row, col;
    int random;
	int count = 0;
	int legalMoves[60][2]; // to keep the legal moves

    for (row = 0; row < 8; row++) // tries all the squares on the board
	{						 // if they are legal
		for (col = 0; col < 8; col++)
		{
            c.row = row;
            c.col = col;
			if (isLegal(c))
			{ // if they are legal, they are saved
				legalMoves[count][0] = row;
				legalMoves[count][1] = col;
				count++;
			}
		}
	}
    srand(time(NULL));
	random = rand() % count; // generates random numbers [0, count)

	c.row = legalMoves[random][0];
	c.col = legalMoves[random][1];

	Sleep(1000);
	std::cout << "row: " << c.row + 1 << std::endl; // for a better game exp
	std::cout << "col: " << c.col + 1 << std::endl; // prints cpu's moves
	Sleep(1000);

	return c;
}