#pragma once

#include "board.h"

void flipper(int col, int row, char turn)
{
	int i;
	int j;
	int k;
    int l;
    int m;
	int dir;

	int dirs[8][2] = {
        {-1, -1},   {0, -1},   {1, -1},
        {-1, 0},/*played coor*/{1, 0},
        {-1, 1},    {0, 1},    {1, 1}
    };

    for (dir = 0; dir < 8; dir++)
    {
        i = col - 1 + dirs[dir][0];
        j = row - 1 + dirs[dir][1];

        for (m = 1; (i >= 0 && i <= 7) && (j >= 0 && j <= 7); m++)
        {
            i = col - 1 + m * dirs[dir][0];
            j = row - 1 + m * dirs[dir][1];

            if ((board[i][j] == '-') || (board[col - 1 + dirs[dir][0]][row - 1 + dirs[dir][1]] == turn))
                break;

            if (board[i][j] == turn)
            {
                k = col - 1 + dirs[dir][0];
                l = row - 1 + dirs[dir][1];

                if (dirs[dir][0] == 0)
                {
                    while (l != j)
                    {
                        board[k][l] = turn;
                        l += dirs[dir][1];
                    }
                }

                if (dirs[dir][1] == 0)
                {
                    while (k != i)
                    {
                        board[k][l] = turn;
                        k += dirs[dir][0];
                    }
                }

                else
                {
                    while (k != i && l != j)
                    {
                        board[k][l] = turn;

                        k += dirs[dir][0];
                        l += dirs[dir][1];
                    }
                }
                break;
            }
        }
    }
}