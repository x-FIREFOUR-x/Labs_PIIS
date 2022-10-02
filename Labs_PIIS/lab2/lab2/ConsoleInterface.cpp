#include "ConsoleInterface.h"

#include "AlphaBetaMiniMax.h"

void ConsoleInterface::run()
{
    string namefile;
    cout << " -Input name file: ";
    cin >> namefile;

    ReaderWriter reader_writer;
    Maze maze;
    try
    {
        maze = reader_writer.read_maze_with_file(namefile);
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << namefile << endl;
        return;
    }

    Player player(maze);
    vector<AbstractEnemy*> enemys = CreaterEnemy::createEnemys(2, 2, maze, player);

    bool is_exit = false;
    while (!is_exit)
    {
        reader_writer.write_console_maze(maze, player, enemys);
        /*
        for (int i = 0; i < enemys.size(); i++)
        {
            enemys[i]->move(maze, player);
        }
        */

        AlphaBetaMiniMax algo;
        algo.coordinate_move(maze, player, enemys);

        string exit = "";
        cin >> exit;
        if (exit == "e")
            is_exit = true;
    }
}