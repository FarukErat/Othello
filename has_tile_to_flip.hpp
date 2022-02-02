#pragma once

#include "table.hpp"
/**
 * @param none
 * @return boolean
 */
bool Table::hasTileToFlip()
// checks if a side has tile to flip
{
	coor c;
	// this checks if there is any legal move for only one side
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			c.row = row;
			c.col = col;
			for (auto dir : moveDirs)
				if (isLegal(c, dir))
					return true;
		}
	}
	return false;
}
