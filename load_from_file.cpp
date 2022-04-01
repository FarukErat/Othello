#pragma once

#include "table.hpp"

// board has SIZE x SIZE elements
// 4 of them are initialized
// it makes SIZE * SIZE - 4
// moves are saved row.column, format
// so it is multiplied by 4
#define LENGTH (SIZE * SIZE - 4) * 4
/**
 * @brief get moves from file and return them as a vector
 * @param none
 * @return vector of moves from file
 */
vector<coor> Table::loadFromFile(string fileName)
{
    vector<coor> moves;
    coor c;
    ifstream file;
    char text[LENGTH];
    // copy the moves from the file to string
    file.open(fileName);
    file.getline(text, LENGTH);
    file.close();
    char *ptr;
    // the delimiter is a dot (.)
    // because rows end with a dot
    // use strtok() function to separate string using delimiter
    ptr = strtok(text, ".");
    while (ptr != NULL)
    {
        // use stoi() function to convert string to integer
        c.row = stoi(ptr);
        // the delimiter is a comma (,)
        // because columns end with a comma
        ptr = strtok(NULL, ",");
        c.col = stoi(ptr);
        moves.push_back(c);
        ptr = strtok(NULL, ".");
    }
    return moves;
}
