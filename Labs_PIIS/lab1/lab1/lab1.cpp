#include <iostream>

#include "Maze.h"
#include "MazeReaderWriter.h"

int main()
{
    MazeReaderWriter reader;
    Maze maze = reader.read_maze_with_file("Maze1.txt");

    return 0;
}
