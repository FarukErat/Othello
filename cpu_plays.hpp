#pragma once

#include "table.hpp"
/**
 * @brief Cpu tries all the squares,
 * finds all the legal moves and stores the moves in a vector,
 * chooses a random move from the vector and returns it.
 * @param nothing
 * @return the coordinates cpu choose
 */
coor Table::cpuPlays()
{
	coor c;

	int row, col;
	int random;
	vector<vector<int>> moves;

	for (row = 0; row < SIZE; row++) // tries all the squares on the board if they are legal
	{
		for (col = 0; col < SIZE; col++)
		{
			c.row = row;
			c.col = col;
			// if they are legal, they are saved
			if (getBoard(c.row, c.col) == LEGAL)
				moves.push_back({row, col});
		}
	}
	srand(time(NULL));
	random = rand() % moves.size(); // generates random numbers [0, count)

	c.row = moves[random][0];
	c.col = moves[random][1];

	sleep(0.5); // delays in second
	// for a better game exp prints cpu's moves
	std::cout << "row: " << c.row + 1 << std::endl;
	std::cout << "col: " << c.col + 1 << std::endl;
	sleep(1); // delays in second

	return c;
}
