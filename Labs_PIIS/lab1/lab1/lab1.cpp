#include <iostream>

#include "Maze.h"
#include "MazeReaderWriter.h"
#include "AStar.h"
#include "WaveAlgo.h"

#include<list>

int main()
{
    MazeReaderWriter reader;
    Maze maze = reader.read_maze_with_file("Maze3.txt");

    /*
    AStar algo;
    algo.search_path(maze);
    list<pair<int, int>> res = maze.get_path();

    reader.write_console_maze_and_path(maze);
    */
    
    WaveAlgo algo;
    algo.search_path(maze);
    list<pair<int, int>> res = maze.get_path();

    reader.write_console_maze_and_path(maze);
    

    return 0;
}
