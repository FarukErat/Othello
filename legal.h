#pragma once

#include "board.h"

char board[8][8];

bool legal(int col, int row, char turn)
{
    int i;
	int j;
	int m;
	int dir;

	int dirs[8][2] = {
        {-1, -1},   {0, -1},   {1, -1},
        {-1, 0},/*played coor*/{1, 0},
        {-1, 1},    {0, 1},    {1, 1}
    };

	bool flip = false;

	if (col < 1 || col > 8 || row < 1 || row > 8)
		return false;

	if (board[col - 1][row - 1] != '-')
		return false;

	for (dir = 0; dir < 8; dir++)
	{
		i = col - 1 + dirs[dir][0];
		j = row - 1 + dirs[dir][1];

		for (m = 1; (i >= 0 && i <= 7) && (j >= 0 && j <= 7); m++)
		{
			i = col - 1 + m * dirs[dir][0];
			j = row - 1 + m * dirs[dir][1];

			if (board[i][j] == '-')
				break;

			if (board[i][j] != turn)
			{
				flip = true;
				continue;
			}

			if (board[i][j] == turn)
			{
				if (flip == true)
					return true;

				if (flip == false)
					break;
			}
		}
		flip = false;
	}

	return false;
}