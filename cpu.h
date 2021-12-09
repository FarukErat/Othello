#pragma once

#include "coordinates.h"
#include "legal.h"

coordinates cpu(char turn)
{
	coordinates coor;

	int i;
	int j;
	int random;
	int count = 0;
	int legalMoves[2][60]; // to keep the legal moves

	for (j = 1; j <= 8; j++) // tries all the squares on the board
	{						 // if they are legal
		for (i = 1; i <= 8; i++)
		{
			if (legal(i, j, turn))
			{ // if they are legal, they are saved
				legalMoves[0][count] = i;
				legalMoves[1][count] = j;
				count++;
			}
		}
	}

	srand(time(NULL));
	random = rand() % count; // generates random numbers [0, count)

	coor.col = legalMoves[0][random];
	coor.row = legalMoves[1][random];

	std::cout << "col: " << coor.col << std::endl; // prints cpu's moves
	std::cout << "row: " << coor.row << std::endl; // for a better game exp

	return coor;
}