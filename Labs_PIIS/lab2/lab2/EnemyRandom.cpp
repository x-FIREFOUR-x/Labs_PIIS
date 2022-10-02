#include "EnemyRandom.h"

#include <vector>

EnemyRandom::EnemyRandom(pair<int, int> coordinates):
	AbstractEnemy(coordinates)
{
}

void EnemyRandom::move(Maze maze, const Player& player, const vector<AbstractEnemy*> enemys, const int index_cur_enemy)
{
	for (int i = 0; i < index_cur_enemy; i++)
	{
		maze.set_value_cell(enemys[i]->get_coordinates(), 0);
	}

	srand(time(NULL));

	vector<pair<int, int>> available_moves;

	if (maze.is_cell(make_pair(line + 1, column)))
		available_moves.push_back(make_pair(line + 1, column));
	if (maze.is_cell(make_pair(line - 1, column)))
		available_moves.push_back(make_pair(line - 1, column));
	if (maze.is_cell(make_pair(line, column + 1)))
		available_moves.push_back(make_pair(line, column + 1));
	if (maze.is_cell(make_pair(line, column - 1)))
		available_moves.push_back(make_pair(line, column - 1));

	if (available_moves.size() > 0)
	{
		int number_move = rand() % available_moves.size();
		this->line = available_moves[number_move].first;
		this->column = available_moves[number_move].second;
	}
	else
	{
		throw exception("There are no moves");
	}
	
}

char EnemyRandom::symbol_view()
{
	return '&';
}
