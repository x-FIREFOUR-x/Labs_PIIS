#pragma once

#include "Maze.h"
#include "ReaderWriter.h"
#include "Player.h"
#include "EnemyAStar.h"
#include "EnemyRandom.h"
#include "CreaterEnemy.h"

#include <string>;

class ConsoleInterface
{
public:
	void run();
private:
	bool is_finish( const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys);
};

