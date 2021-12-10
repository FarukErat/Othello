#pragma once

#include "board.h"

char board[8][8];

bool legal(int col, int row, char turn)
{
    int i;
	int j;
	int m;
	int dir;

	int dirs[8][2] = { // declaring deltas for each 8 diretions on the board
        {-1, -1}/*left and up*/,   {0, -1}/*up*/,   {1, -1},/*up and right*/
        {-1, 0}/*left*/,   /*[chosen coordinate]*/    {1, 0}/*right*/,
        {-1, 1}/*left and down*/,   {0, 1}/*down*/, {1, 1}/*down and right*/
    };

	bool flip = false;

	if (col < 1 || col > 8 || row < 1 || row > 8) // if  the square is out of the board, return false
		return false;

	if (board[col - 1][row - 1] != empty) // if the square is not empty, return false
		return false;

	for (dir = 0; dir < 8; dir++) // for each directions
	{
		i = col - 1 + dirs[dir][0]; //initializition of i and j before the for loop
		j = row - 1 + dirs[dir][1]; //to check the conditions in the loop

		for (m = 1; (i >= 0 && i <= 7) && (j >= 0 && j <= 7); m++)
		{
			i = col - 1 + m * dirs[dir][0]; //k and l are assigned the number along the legal direction
			j = row - 1 + m * dirs[dir][1];

			if (board[i][j] == empty) // if an empty square is found, break
				break;

			if (board[i][j] != turn) // if the square is not in the same color as the players
			{
				flip = true; // flip is assigned as true, since, at least one square must be legal to be turned
				continue;
			}

			if (board[i][j] == turn) //when a square in the same color as the players is found
			{
				if (flip == true) // if, at least, one square can be turned 
					return true;

				if (flip == false) // if there is no square having not been changed, break
					break;
			}
		}
		flip = false; // assign flip false for the next step for the for-loop
	}

	return false; //if not any legal square found, return false
}