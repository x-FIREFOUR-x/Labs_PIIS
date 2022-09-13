#pragma once

#include <vector>
#include <string>
#include <list>

using namespace std;
class Maze
{
private:
	pair<int, int> start;
	pair<int, int> end;
	vector<vector<int>> maze;
	list<pair<int, int>> path;

public:
	Maze();
	Maze(const vector<vector<int>>& maze, const pair<int, int> start, const pair<int, int> end);

	pair<int,int> get_start();
	pair<int, int> get_end();

	void set_start(const pair<int, int> start);
	void set_end(const pair<int, int> end);

	void set_path(list<pair<int, int>>& path);
	list<pair<int, int>> get_path();

	vector<vector<int>> get_maze();

	bool is_cell(pair<int, int> cell);
	bool get_value_cell(pair<int, int> cell);
};

