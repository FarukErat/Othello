#pragma once

#include "possible.h"

bool end()
{
	// this checks if there is any legal move for both sides
	if (possible('B'))
		return true;

	if (possible('W'))
		return true;

	return false;
}