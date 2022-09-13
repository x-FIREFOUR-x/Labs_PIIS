#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "Maze.h"

using namespace std;
class MazeReaderWriter
{
private:
	string folder = "FilesMaze";

public:
	Maze read_maze_with_file(string filename);

	void write_console_maze_and_path(Maze& maze);
};

