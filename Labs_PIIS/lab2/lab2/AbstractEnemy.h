#pragma once
#include "Maze.h"
#include "Player.h"

#include <iostream>
#include <exception>

class AbstractEnemy
{
protected:
	int line;
	int column;
public:
	AbstractEnemy(pair<int, int> coordinates);
	AbstractEnemy(int line, int column);

	virtual void move(Maze maze, const Player& player, const vector<shared_ptr<AbstractEnemy>> enemys, const int index_cur_enemy) { throw exception("No realization this method in abstract class"); };
	virtual char symbol_view() { throw exception("No realization this method in abstract class"); };

	int get_line() const;
	int get_column() const;
	pair<int, int> get_coordinates() const;
};

