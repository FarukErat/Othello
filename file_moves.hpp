#pragma once

#include "table.hpp"

coor Table::fileMoves()
{
	// returns moves from files
	this->moveCount++;
	return moves[moveCount];
}

coor Table::filePlays(float delay)
{
	coor c = fileMoves();
    sleep(delay); // delays in second
	// for a better game exp, prints cpu's moves
	cout << "row: " << moves[moveCount].row + 1 << endl;
	cout << "col: " << moves[moveCount].col + 1 << endl;
	sleep(delay); // delays in second
    return c;
}
