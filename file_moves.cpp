#pragma once

#include "table.hpp"

/**
 * @brief returns moves from a file in order whenever called
 *
 * @param none
 *
 * @return coordinates in form of coor
 */
coor Table::fileMoves()
{
	// returns moves from files
	return moves[moveCount++];
}

/**
 * @brief the parameter delay, delays in miliseconds
 *
 * @param delayInMs
 * 
 * @return coordinates in form of coor
 */
coor Table::filePlays(unsigned delayInMs)
{
	coor c = fileMoves();
	sleep(delayInMs); // delays in second
	// for a better game exp, prints cpu's moves
	cout << "row: " << moves[moveCount].row + 1 << endl;
	cout << "col: " << moves[moveCount].col + 1 << endl;
	sleep(delayInMs); // delays in second
	return c;
}
