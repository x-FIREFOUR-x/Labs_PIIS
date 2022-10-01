#include "WaveAlgo.h"

bool WaveAlgo::search_path(Maze& maze)
{
    clean_maze(maze);

    bool path_searched = false;


    add_adjacent_cells(maze.get_start(), maze);

    int k = 1;
    maze.set_value_cell(maze.get_start(), k);
    list_closed[maze.get_start()] = maze.get_start();

    if (maze.get_start() == maze.get_end())
        path_searched = true;

    
    while (!path_searched && !list_opened.empty())
    {
        AdjCells adj_cells = list_opened.front();
        list_opened.pop();

        if (list_closed.find(adj_cells.cell) == list_closed.end())
        {
            add_adjacent_cells(adj_cells.cell, maze);

            k = maze.get_value_cell(adj_cells.previous_cell) + 1;
            maze.set_value_cell(adj_cells.cell, k);

            list_closed[adj_cells.cell] = adj_cells.previous_cell;
        }

        if (adj_cells.cell == maze.get_end())
            path_searched = true;
    }

    build_path(path_searched, maze);

	return path_searched;
}

void WaveAlgo::add_adjacent_cells(pair<int, int> cell, Maze& maze)
{
    pair<int, int> new_cell = make_pair<int, int>((int)cell.first, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second);
    add_adjacent_cell(cell, new_cell, maze);


    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze);
}

void WaveAlgo::add_adjacent_cell(pair<int, int> prev_cell, pair<int, int> new_cell, Maze& maze)
{
    if (maze.is_cell(new_cell) && list_closed.find(new_cell) == list_closed.end())
    {
        list_opened.push(AdjCells(new_cell, prev_cell));
       
    }
}

void WaveAlgo::build_path(bool path_searched, Maze& maze)
{
    list<pair<int, int>> result_path;
    if (path_searched)
    {
        pair<int, int> cur_cell = maze.get_end();
        while (cur_cell != maze.get_start())
        {
            result_path.push_front(cur_cell);
            cur_cell = list_closed[cur_cell];
        }
        result_path.push_front(cur_cell);
    }
    maze.set_path(result_path);
}

void WaveAlgo::clean_maze(Maze& maze)
{
    for (int i = 0; i < maze.get_hight_maze(); i++)
    {
        for (int j = 0; j < maze.get_width_maze(); j++)
        {
            if (maze.get_value_cell(i, j) > 0)
            {
                maze.set_value_cell(i, j, -1);
            }
        }
    }
}

