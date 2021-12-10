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
            i = col - 1 + m * dirs[dir][0]; //multiplying by 'm'
            j = row - 1 + m * dirs[dir][1]; //to move along the directions

            if ((board[i][j] == empty) || (board[col - 1 + dirs[dir][0]][row - 1 + dirs[dir][1]] == turn))
                // if the calculated square is empty, break
                // or
                // if the square which is by the chosen square
                // is in the same color as players, break
                break;

            if (board[i][j] == turn) // when a square in the same color as players is found
            {
                k = col - 1 + dirs[dir][0]; //k and l are assigned the number along the legal direction
                l = row - 1 + dirs[dir][1];

                if (dirs[dir][0] == 0) // assigning the squares, when the direction is upward or downward
                {
                    while (l != j) //assign till j
                    {
                        board[k][l] = turn;
                        l += dirs[dir][1]; //incrase the number by the delta
                    }
                }

                if (dirs[dir][1] == 0) // assigning the squares, when the direction is left or right
                {
                    while (k != i) //assign till i
                    {
                        board[k][l] = turn;
                        k += dirs[dir][0]; //incrase the number by the delta
                    }
                }

                else  // assigning the squares, when the direction is cross
                {
                    while (k != i && l != j) //assign till i or j
                    {
                        board[k][l] = turn;

                        k += dirs[dir][0]; //incrase the numbers by the delta
                        l += dirs[dir][1];
                    }
                }
                break;
            }
        }
    }
}