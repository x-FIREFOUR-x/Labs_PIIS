#include "EnemyAStar.h"

#include "AStar.h"

EnemyAStar::EnemyAStar(pair<int, int> coordinates):
	AbstractEnemy(coordinates)
{
}

void EnemyAStar::move(Maze maze, const Player& player, const vector<shared_ptr<AbstractEnemy>> enemys, const int index_cur_enemy)
{
	for (int i = 0; i < index_cur_enemy; i++)
	{
		if (enemys[i]->get_coordinates() != player.get_coordinates())
			maze.set_value_cell(enemys[i]->get_coordinates(), 0);
	}

	AStar algo;
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
