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

