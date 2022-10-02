#pragma once

#include<ctime>

#include "Maze.h"

using namespace std;
class Player
{
	int line;
	int column;

public:
	Player(const Maze& maze);
	Player(int line, int column);	

	int get_line() const;
	int get_column() const;
	pair<int,int> get_coordinates() const;

};

