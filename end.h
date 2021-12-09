#pragma once

#include "possible.h"

bool end()
{
	if (possible('B'))
		return true;

	if (possible('W'))
		return true;

	return false;
}