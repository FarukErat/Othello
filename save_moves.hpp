#pragma once

#include "table.hpp"

void Table::saveMoves(string fileName)
{
    ofstream file;
    file.open(fileName);
    for (int i = 0; i < moves.size(); i++)
    {
        file << moves[i].row << "." << moves[i].col << ",";
    }
    file.close();
}