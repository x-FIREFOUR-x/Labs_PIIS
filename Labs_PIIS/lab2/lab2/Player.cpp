#include "Player.h"

Player::Player(const Maze& maze)
{
	srand(time(NULL));

	bool rand_correct = false;
	int column;
	int line;

	while (!rand_correct)
	{
		column = rand() % maze.get_width_maze();
		line = rand() % maze.get_hight_maze();

		if (maze.is_cell(make_pair(line, column)) && !maze.is_end(make_pair(line, column)))
			rand_correct = true;
	}

	this->line = line;
	this->column = column;
}

Player::Player(int line, int column)
{
	this->line = line;
	this->column = column;
}

int Player::get_line() const
{
	return this->line;
}

int Player::get_column() const
{
	return this->column;
}

pair<int, int> Player::get_coordinates() const
{
	return make_pair(line, column);
}

void Player::move(const shared_ptr<Algorithm>& algorithm, const Maze& maze, const vector<shared_ptr<AbstractEnemy>>& enemys)
{
	pair<int, int> coordinate_move = algorithm->coordinate_move(maze, *this, enemys);

	this->line = coordinate_move.first;
	this->column = coordinate_move.second;
}

