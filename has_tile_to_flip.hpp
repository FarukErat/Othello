#pragma once

#include "table.hpp"
/**
 * @brief Checks if a side has any tile to flip, any legal move.
 * @param none
 * @return boolean
 */
bool Table::hasTileToFlip()
{
	// all the squares are checked
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (getBoard(row, col) == LEGAL)
				return true;
		}
	}
	return false;
}
