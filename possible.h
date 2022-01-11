#pragma once

#include "legal.h"

bool possible(char turn)
{
	int i;
	int j;

	for (j = 1; j <= 8; j++) // this checks if there is any legal move
	{						 // for only one side
		for (i = 1; i <= 8; i++)
		{
			if (legal(i, j, turn))
				return true;
		}
	}
	return false;
}