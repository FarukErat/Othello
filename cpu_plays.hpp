#pragma once

#include "table.hpp"
/**
 * @param nothing
 * @return the coordinates cpu choose
 */
coor Table::cpuPlays()
//lets cpu play randomly
{
	coor c;

	int row, col;
	int random;
	int count = 0;
	vector<int> rowes; // to keep the legal moves
	vector<int> coles; // to keep the legal moves

	for (row = 0; row < SIZE; row++) // tries all the squares on the board if they are legal
	{
		for (col = 0; col < SIZE; col++)
		{
			c.row = row;
			c.col = col;
			if (isLegal(c))
			{
				// if they are legal, they are saved
				rowes.push_back(row);
				coles.push_back(col);
				count++;
			}
		}
	}
	srand(time(NULL));
	random = rand() % count; // generates random numbers [0, count)

	c.row = rowes.at(random);
	c.col = coles.at(random);

	sleep(1); // delays in second
	// for a better game exp prints cpu's moves
	std::cout << "row: " << c.row + 1 << std::endl;
	std::cout << "col: " << c.col + 1 << std::endl; 
	sleep(1); // delays in second

	return c;
}
