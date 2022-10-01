#include "EnemyAStar.h"

#include "AStar.h"

EnemyAStar::EnemyAStar(pair<int, int> coordinates):
	AbstractEnemy(coordinates)
{
}

void EnemyAStar::move(const Maze& maze, const Player& player)
{
	AStar algo;

	bool path_searched = algo.search_path(maze, make_pair(line, column), player.get_coordinates());

	if (path_searched)
	{
		pair<int, int> coordinates = algo.coordinate_move();
		line = coordinates.first;
		column = coordinates.second;
	}
	else
	{
		throw exception("Path not is searched");
	}
}

char EnemyAStar::symbol_view()
{
	return '*';
}
