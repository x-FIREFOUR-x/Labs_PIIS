#pragma once

#include "Maze.h"
#include "Player.h"

class AbstractEnemy
{
protected:
	int line;
	int column;
public:
	AbstractEnemy(pair<int, int> coordinates);

	virtual void move(const Maze& maze, const Player& player) = 0;
	virtual char symbol_view() = 0;

	int get_line() const;
	int get_column() const;
	pair<int, int> get_coordinates() const;
};

