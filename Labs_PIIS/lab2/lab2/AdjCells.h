#pragma once

#include <iostream>

using namespace std;
class AdjCells
{
public:
	pair<int, int> cell;
	pair<int, int> previous_cell;

	AdjCells(pair<int, int> cell, pair<int, int> previous_cell);
};

