#include "AdjCells.h"

AdjCells::AdjCells(pair<int, int> cell, pair<int, int> previous_cell)
{
	this->cell = cell;
	this->previous_cell = previous_cell;
}
