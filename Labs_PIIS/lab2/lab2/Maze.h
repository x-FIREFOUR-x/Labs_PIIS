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

	pair<int,int> get_start() const;
	pair<int, int> get_end()const;
	void set_start(const pair<int, int> start);
	void set_end(const pair<int, int> end);

	void set_path(list<pair<int, int>>& path);
	list<pair<int, int>> get_path() const;

	vector<vector<int>> get_maze() const;

	int get_width_maze() const;
	int get_hight_maze() const;

	bool is_cell(pair<int, int> cell) const;
	bool is_start(pair<int, int> cell) const;
	bool is_end(pair<int, int> cell) const;

	int get_value_cell(pair<int, int> cell) const;
	int get_value_cell(int line, int column) const;
	void set_value_cell(pair<int, int> cell, int value);
	void set_value_cell(int line, int column, int value);
};

