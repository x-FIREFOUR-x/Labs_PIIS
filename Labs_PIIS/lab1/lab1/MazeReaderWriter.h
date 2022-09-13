#pragma once

#include <fstream>
#include <string>

#include "Maze.h"

using namespace std;
class MazeReaderWriter
{
private:
	string folder = "FilesMaze";

public:
	Maze read_maze_with_file(string filename);
};

