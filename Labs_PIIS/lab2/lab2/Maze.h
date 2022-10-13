#pragma once

#include <vector>
#include <string>
#include <list>

using namespace std;
class Maze
{
private:
	pair<int, int> end;
	vector<vector<int>> maze;

public:
	Maze();
	Maze(const vector<vector<int>>& maze, const pair<int, int> start, const pair<int, int> end);

	pair<int, int> get_end()const;
	void set_end(const pair<int, int> end);

	vector<vector<int>> get_maze() const;

	int get_width_maze() const;
	int get_hight_maze() const;

	bool is_cell(pair<int, int> cell) const;
	bool is_cell(const int line, const int column) const;
	bool is_end(pair<int, int> cell) const;

	int get_value_cell(pair<int, int> cell) const;
	int get_value_cell(int line, int column) const;
	void set_value_cell(pair<int, int> cell, int value);
	void set_value_cell(int line, int column, int value);
};

