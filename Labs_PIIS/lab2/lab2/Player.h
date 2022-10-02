#pragma once

#include<ctime>

#include "Maze.h"
#include "Algorithm.h"

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

	void move(const Algorithm* algorithm, const Maze& maze, const vector<AbstractEnemy*> enemys);

};

