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

	int dirs[8][2] = { // declaring deltas for each 8 diretions on the board
        {-1, -1}/*left and up*/,   {0, -1}/*up*/,   {1, -1},/*up and right*/
        {-1, 0}/*left*/,   /*[chosen coordinate]*/    {1, 0}/*right*/,
        {-1, 1}/*left and down*/,   {0, 1}/*down*/, {1, 1}/*down and right*/
    };

    for (dir = 0; dir < 8; dir++) // for each directions
    {
        i = col - 1 + dirs[dir][0]; //initializition of i and j before the for loop
        j = row - 1 + dirs[dir][1]; //to check the conditions in the loop

        for (m = 1; (i >= 0 && i <= 7) && (j >= 0 && j <= 7); m++)
        {
            i = col - 1 + m * dirs[dir][0]; //multiplying by m
            j = row - 1 + m * dirs[dir][1]; //to move along the directions

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