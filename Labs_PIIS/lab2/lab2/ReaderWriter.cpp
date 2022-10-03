#include "ReaderWriter.h"

#include <vector>
#include <iomanip>  
#include <exception>

#include "EnemyRandom.h"

Maze ReaderWriter::read_maze_with_file(string filename)
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


void ReaderWriter::write_console_maze(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys)
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
            else
            {
                line.push_back(" ");
            }
        }
        maze_output.push_back(line);
    }

    //maze_output[maze.get_start().first][maze.get_start().second] = "S";
    maze_output[maze.get_end().first][maze.get_end().second] = "E";
    maze_output[player.get_line()][player.get_column()] = "@";

    for (int i = 0; i < enemys.size(); i++)
    {
        maze_output[enemys[i]->get_line()][enemys[i]->get_column()] = enemys[i]->symbol_view();
    }

    cout << "----Input--Maze-----------" << endl;

    for (int i = 0; i < maze_output.size(); i++)
    {
        cout << "|";
        for (int j = 0; j < maze_output[i].size(); j++)
        {
            if (j < maze_output[i].size() - 1)
                cout << maze_output[i][j];
            else
                cout << maze_output[i][j] << "|";
        }
        cout << endl;
    }

    cout << "-------------------------" << endl;
}
