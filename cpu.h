#pragma once

#include "coordinates.h"
#include "legal.h"

using namespace std;

coordinates cpu(char turn)
{
	coordinates coor;

	int i;
	int j;
	int random;
	int count = 0;
	int legalMoves[2][60];

	for (j = 1; j <= 8; j++)
	{
		for (i = 1; i <= 8; i++)
		{
			if (legal(i, j, turn))
			{
				legalMoves[0][count] = i;
				legalMoves[1][count] = j;
				count++;
			}
		}
	}

	srand(time(NULL));
	random = rand() % count;

	coor.col = legalMoves[0][random];
	coor.row = legalMoves[1][random];

	cout << "col: " << coor.col << endl;
	cout << "row: " << coor.row << endl;

	return coor;
}