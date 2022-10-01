#include "Maze.h"

Maze::Maze()
{
}

Maze::Maze(const vector<vector<int>>& maze, const pair<int, int> start, const pair<int, int> end)
{
    this->maze = maze;
    this->end = end;
}

pair<int, int> Maze::get_end() const
{
    return end;
}

void Maze::set_end(const pair<int, int> end)
{
    this->end = end;
}

vector<vector<int>> Maze::get_maze() const
{
    return maze;
}

int Maze::get_width_maze() const
{
    return maze[0].size();
}

int Maze::get_hight_maze() const
{
    return maze.size();
}

bool Maze::is_cell(pair<int, int> cell) const
{
    if (cell.first < 0 || cell.first > maze.size() - 1)
        return false;
    if (cell.second < 0 || cell.second > maze[0].size() - 1)
        return false;
    if(maze[cell.first][cell.second] == 0)
        return false;

    return true;
}


bool Maze::is_end(pair<int, int> cell) const
{
    if (cell == end)
        return true;
    else
        return false;
}

int Maze::get_value_cell(pair<int, int> cell) const
{
    return maze[cell.first][cell.second];
}

int Maze::get_value_cell(int line, int column) const
{
    return maze[line][column];
}

void Maze::set_value_cell(pair<int, int> cell, int value)
{
    maze[cell.first][cell.second] = value;
}

void Maze::set_value_cell(int line, int column, int value)
{
    maze[line][column] = value;
}

