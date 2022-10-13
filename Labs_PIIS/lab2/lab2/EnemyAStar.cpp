#include "EnemyAStar.h"

#include "AStar.h"

EnemyAStar::EnemyAStar(pair<int, int> coordinates):
	AbstractEnemy(coordinates)
{
}

void EnemyAStar::move(Maze maze, const Player& player, const vector<shared_ptr<AbstractEnemy>> enemys, const int index_cur_enemy)
{
	AStar algo;

	for (int i = 0; i < index_cur_enemy; i++)
	{
		maze.set_value_cell(enemys[i]->get_coordinates(), 0);
	}

	bool path_searched = algo.search_path(maze, make_pair(line, column), player.get_coordinates());

	if (path_searched)
	{
		pair<int, int> coordinates = algo.coordinate_move();
		line = coordinates.first;
		column = coordinates.second;
	}
}

char EnemyAStar::symbol_view()
{
	return '*';
}
