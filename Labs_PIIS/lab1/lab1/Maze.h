#pragma once

#include <vector>
#include <string>

using namespace std;
class Maze
{
private:
	pair<int, int> start;
	pair<int, int> end;
	vector<vector<int>> maze;

public:
	Maze();
	Maze(const vector<vector<int>>& maze, const pair<int, int> start, const pair<int, int> end);

	pair<int,int> get_start();
	pair<int, int> get_end();

	void set_start(const pair<int, int> start);
	void set_end(const pair<int, int> end);

	
};

