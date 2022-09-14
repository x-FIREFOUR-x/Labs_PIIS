#include "MazeReaderWriter.h"

#include <vector>
#include <iomanip>  
#include <exception>

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
    else
    {
        throw exception("Not exist file: ");
    }
}

void MazeReaderWriter::write_console_maze_and_path(Maze& maze)
{
    vector<vector<string>> maze_output;
    for (int i = 0; i < maze.get_hight_maze(); i++)
    {
        vector<string> line;
        for (int j = 0; j < maze.get_width_maze(); j++)
        {
            if (maze.get_value_cell(i, j) == 0)
            {
                line.push_back("#");
            }
            else if (maze.get_value_cell(i, j) == -1)
            {
                line.push_back("0");
            }
            else
            {
                line.push_back(to_string(maze.get_value_cell(i, j)));
            }
        }
        maze_output.push_back(line);
    }

    list<pair<int, int>> path = maze.get_path();

    
    int code = 65;
    for (auto elem : path)
    {
        char c = code;
        maze_output[elem.first][elem.second] = c;

        code++;
        if (code > 90)
            code = 65;
    }
    

    cout << "----------Maze-----------" << endl;

    for (int i = 0; i < maze_output.size(); i++)
    {
        for (int j = 0; j < maze_output[i].size(); j++)
        {
            cout << setw(3) << maze_output[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Path: " << endl;
    for (auto elem : path)
    {

        if (elem != path.back())
            cout << elem.first << ";" << elem.second << " -> ";
        else
            cout << elem.first << ";" << elem.second << endl;
    }

    cout << "-------------------------" << endl << endl;
}