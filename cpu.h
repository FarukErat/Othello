#pragma once

#include "coordinates.h"
#include "legal.h"

coordinates cpu(char turn)
{
	coordinates coor;

	int i;
	int j;
	int random;
	int count1 = 0;
	int count2 = 0;
	int legalMoves[2][56]; // to keep the legal moves
	int cornerMoves[2][4];

	for (j = 1; j <= 8; j++) // tries all the squares on the board
	{						 // if they are legal
		for (i = 1; i <= 8; i++)
		{
			if (legal(i, j, turn))
			{ // if they are legal, they are saved
				if ((i == 2 && j == 2 && board[0][0] == empty) || (i == 7 && j == 2 && board[7][0] == empty) || (i == 7 && j == 7 && board[7][7] == empty) || (i == 2 && j == 7 && board[0][7] == empty))
				{
					cornerMoves[0][count1] = i;
					cornerMoves[1][count1] = j;
					count1++;
				}

				else
				{
					legalMoves[0][count2] = i;
					legalMoves[1][count2] = j;
					count2++;
				}
			}
		}
	}

	srand(time(NULL));
	if (count2 > 0)
	{
		random = rand() % count2; // generates random numbers [0, count)

		coor.col = legalMoves[0][random];
		coor.row = legalMoves[1][random];
	}

	else
	{
		random = rand() % count1; // generates random numbers [0, count)

		coor.col = cornerMoves[0][random];
		coor.row = cornerMoves[1][random];
	}

	std::cout << "col: " << coor.col << std::endl; // prints cpu's moves
	std::cout << "row: " << coor.row << std::endl; // for a better game exp

	return coor;
}