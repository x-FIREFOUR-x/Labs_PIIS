#pragma once

#include "Maze.h"
#include "AdjCells.h"

#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<map>
#include <iostream>

using namespace std;
class AStar
{
private:
	priority_queue<pair<int, AdjCells>, vector<pair<int, AdjCells>>, std::greater<pair<int, AdjCells>>> list_opened;
	map<pair<int, int>, pair<int, int>> list_closed;

public:
	bool search_path(Maze& maze);

private:
	int calculate_heuristics(pair<int, int> cell1, pair<int, int> cell2);
	void add_adjacent_cells(pair<int, int> cell, Maze& maze);
	void add_adjacent_cell(pair<int, int> prev_cell, pair<int, int> new_cell, Maze& maze, int g);

	friend bool operator<(const pair<int, AdjCells>&, const pair<int, AdjCells>&);
	
};

