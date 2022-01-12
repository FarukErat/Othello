#pragma once

#include "table.h"

bool Table::hasTileToFlip()
{
    coor c;
    // this checks if there is any legal move for only one side
	for (int row = 1; row <= 8; row++)
	{
		for (int col = 1; col <= 8; col++)
		{
            c.row = row;
            c.col = col;
			if (isLegal(c))
				return true;
		}
	}
	return false;
}