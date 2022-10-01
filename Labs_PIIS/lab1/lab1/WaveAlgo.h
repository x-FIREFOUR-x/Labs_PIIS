#pragma once

#include <vector>
#include <list>
#include <queue>
#include <map>
#include <iostream>

#include "Maze.h"
#include "AdjCells.h"

using namespace std;
class WaveAlgo
{
private:
	map<pair<int, int>, pair<int, int>> list_closed;
	queue<AdjCells> list_opened;

public:
	bool search_path(Maze& maze);

private:
	void add_adjacent_cells(pair<int, int> cell, Maze& maze);
	void add_adjacent_cell(pair<int, int> prev_cell, pair<int, int> new_cell, Maze& maze);
	void build_path(bool path_searched, Maze& maze);

	void clean_maze(Maze& maze);
};

