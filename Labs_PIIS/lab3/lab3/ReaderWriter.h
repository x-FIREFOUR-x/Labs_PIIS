#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "Maze.h"
#include "Player.h"
#include "AbstractEnemy.h"

using namespace std;
class ReaderWriter
{
private:
	string folder = "FilesMaze";

public:
	Maze read_maze_with_file(string filename);

	void write_console_maze(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys);
};

