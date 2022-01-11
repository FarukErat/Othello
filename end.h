#pragma once

#include "possible.h"

bool end()
{
	// this checks if there is any legal move for each side
	if (possible('B'))
		return true;

	if (possible('W'))
		return true;

	return false;
}