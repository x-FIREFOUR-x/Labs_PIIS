#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "Maze.h"
#include "Player.h"

using namespace std;
class ReaderWriter
{
private:
	string folder = "FilesMaze";

public:
	Maze read_maze_with_file(string filename);

	void write_console_maze(const Maze& maze, const Player& player);
};

