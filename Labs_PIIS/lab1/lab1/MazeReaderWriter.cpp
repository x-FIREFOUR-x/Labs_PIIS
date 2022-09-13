#include "MazeReaderWriter.h"

#include <vector>

Maze MazeReaderWriter::read_maze_with_file(string filename)
{
    ifstream file;
    file.open(folder + "\\" + filename);

    if (file.is_open())
    {
        int height;
        int width;

        file >> height;
        file >> width;

        pair<int, int> start;
        file >> start.first;
        file >> start.second;

        pair<int, int> end;
        file >> end.first;
        file >> end.second;

        vector<vector<int>> maze;
        for (int i = 0; i < height; i++)
        {
            vector<int> line;
            for (int j = 0; j < width; j++)
            {
                int cell;
                file >> cell;
                line.push_back(cell);
            }
            maze.push_back(line);
        }
        file.close();

        return Maze(maze, start, end);
    }
}