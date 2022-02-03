#pragma once

#include "table.hpp"
/**
 * @brief Checks if a side has any tile to flip, any legal move.
 * @param none
 * @return boolean
 */
bool Table::hasTileToFlip()
{
	coor c;
	// all the squares are checked
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			c.row = row;
			c.col = col;
			if (isLegal(c))
				return true;
		}
	}
	return false;
}
