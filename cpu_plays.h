#pragma once

#include "table.h"
/**
 * @param nothing
 * @return the coordinates cpu choose
 */
coor Table::cpuPlays()
//lets cpu play randomly
{
	coor c;

	int row, col;
	int random;
	int count = 0;
	int legalMoves[60][2]; // to keep the legal moves

	for (row = 0; row < SIZE; row++) // tries all the squares on the board if they are legal
	{
		for (col = 0; col < SIZE; col++)
		{
			c.row = row;
			c.col = col;
			if (isLegal(c))
			{
				// if they are legal, they are saved
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

	sleep(1); // delays 1 second
	// for a better game exp prints cpu's moves
	std::cout << "row: " << c.row + 1 << std::endl;
	std::cout << "col: " << c.col + 1 << std::endl; 
	sleep(1); // delays 1 second

	return c;
}