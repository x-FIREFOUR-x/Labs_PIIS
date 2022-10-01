#pragma once

#include<ctime>

#include "Maze.h"

using namespace std;
class Player
{
	int column;
	int line;

public:
	Player(const Maze& maze);

	int get_line() const;
	int get_column() const;
};

