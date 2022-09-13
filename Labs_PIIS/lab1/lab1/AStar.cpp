#include "AStar.h"

bool AStar::search_path(Maze& maze)
{
	list_opened.push(make_pair<int, AdjCells>
        (
            0 + calculate_heuristics(maze.get_start(), maze.get_end()),
            AdjCells(maze.get_start(), maze.get_start())
        ));

    bool path_searched = false;

    while (!path_searched && !list_opened.empty())
    {
        AdjCells adj_cells = list_opened.top().second;
        list_opened.pop();
        add_adjacent_cells(adj_cells.cell, maze);
        list_closed[adj_cells.cell] = adj_cells.previous_cell;

        if (adj_cells.cell == maze.get_end())
            path_searched = true;
    }

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

    return path_searched;
}


int AStar::calculate_heuristics(pair<int, int> cell1, pair<int, int> cell2)
{
    int h = (abs(cell1.first - cell2.first) + abs(cell1.second - cell2.second)) * 10;
    return h;
}

void AStar::add_adjacent_cells(pair<int, int> cell, Maze& maze)
{
    //pair<int, int> new_cell;

    pair<int, int> new_cell = make_pair<int, int>((int)cell.first, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze, 10);
    
    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second);
    add_adjacent_cell(cell, new_cell, maze, 10);

    new_cell = make_pair<int, int>((int)cell.first, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze, 10);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second);
    add_adjacent_cell(cell, new_cell, maze, 10);

    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze, 14);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second + 1);
    add_adjacent_cell(cell, new_cell, maze, 14);

    new_cell = make_pair<int, int>((int)cell.first + 1, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze, 14);

    new_cell = make_pair<int, int>((int)cell.first - 1, (int)cell.second - 1);
    add_adjacent_cell(cell, new_cell, maze, 14);
}

void AStar::add_adjacent_cell(pair<int, int> prev_cell, pair<int, int> new_cell, Maze& maze, int g)
{
    if (maze.is_cell(new_cell) && list_closed.find(new_cell) == list_closed.end())
    {
        list_opened.push(make_pair<int, AdjCells>
            (
                g * maze.get_value_cell(new_cell) + calculate_heuristics(new_cell, maze.get_end()),
                AdjCells(new_cell, prev_cell)
            ));
    }
}

bool operator<(const pair<int, AdjCells>& lhs, const pair<int, AdjCells>& rhs)
{
    return lhs.first < rhs.first;
}
