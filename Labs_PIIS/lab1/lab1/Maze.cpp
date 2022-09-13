#include "Maze.h"

Maze::Maze()
{
}

Maze::Maze(const vector<vector<int>>& maze, const pair<int, int> start, const pair<int, int> end)
{
    this->maze = maze;
    this->start = start;
    this->end = end;
}

pair<int, int> Maze::get_start()
{
    return start;
}

pair<int, int> Maze::get_end()
{
    return end;
}

void Maze::set_start(const pair<int, int> start)
{
    this->start = start;
}

void Maze::set_end(const pair<int, int> end)
{
    this->end = end;
}

void Maze::set_path(list<pair<int, int>>& path)
{
    this->path = path;
}

list<pair<int, int>> Maze::get_path()
{
    return path;
}

vector<vector<int>> Maze::get_maze()
{
    return maze;
}

int Maze::get_width_maze()
{
    return maze[0].size();
}

int Maze::get_hight_maze()
{
    return maze.size();
}

bool Maze::is_cell(pair<int, int> cell)
{
    if (cell.first < 0 || cell.first > maze.size() - 1)
        return false;
    if (cell.second < 0 || cell.second > maze[0].size() - 1)
        return false;
    if(maze[cell.first][cell.second] == 0)
        return false;

    return true;
}

int Maze::get_value_cell(pair<int, int> cell)
{
    return maze[cell.first][cell.second];
}

int Maze::get_value_cell(int line, int column)
{
    return maze[line][column];
}

