#pragma once

#include "table.hpp"
/**
 * @brief Cpu tries all the squares,
 * finds all the legal moves and stores the moves in a vector,
 * chooses a random move from the vector and returns it.
 * @param nothing
 * @return the coordinates cpu choose
 */
coor Table::randomMoves()
{
	int random;
	vector<vector<int>> moves;
	for (int row = 0; row < SIZE; row++) // tries all the squares on the board if they are legal
	{
		for (int col = 0; col < SIZE; col++)
		{
			// if they are legal, they are saved
			if (getBoard(row, col) == LEGAL)
				moves.push_back({row, col});
		}
	}
	srand(time(NULL));
	random = rand() % moves.size(); // generates random numbers [0, count)
	coor c;
	c.row = moves[random][0];
	c.col = moves[random][1];
	return c;
}

coor Table::cpuPlays(float delay)
{
	coor c = randomMoves();
	sleep(delay); // delays in second
	// for a better game exp, prints cpu's moves
	cout << "row: " << c.row + 1 << endl;
	cout << "col: " << c.col + 1 << endl;
	sleep(delay / 2); // delays in second
	return c;
}
