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
private:
	ReaderWriter reader_writer;

	Maze maze;
	shared_ptr<Algorithm> algorithm;
	Player player;
	vector<shared_ptr<AbstractEnemy>> enemys;

	bool is_exit = false;
	bool is_auto = true;

public:
	void run();
private:
	bool choose_mode_game();
	bool input_file_date();
	bool input_enemys_date();
	bool is_finish( const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys);
};

