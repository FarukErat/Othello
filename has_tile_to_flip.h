#pragma once

#include "table.h"
/**
 * @param none
 * @return boolean
 */
bool Table::hasTileToFlip()
// checks if a side has tile to flip
{
    coor c;
    // this checks if there is any legal move for only one side
	for (int row = 1; row <= SIZE; row++)
	{
		for (int col = 1; col <= SIZE; col++)
		{
            c.row = row;
            c.col = col;
			if (isLegal(c))
				return true;
		}
	}
	return false;
}