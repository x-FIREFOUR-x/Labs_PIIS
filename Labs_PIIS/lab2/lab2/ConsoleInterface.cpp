#include "ConsoleInterface.h"

#include "AlphaBetaMiniMax.h"
#include <thread>
#include <chrono>

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
    vector<AbstractEnemy*> enemys = CreaterEnemy::createEnemys(0, 4, maze, player);
    reader_writer.write_console_maze(maze, player, enemys);

    bool is_exit = false;
    while (!is_exit)
    {
        if (is_finish(maze, player, enemys))
            break;

        string exit = "";
        cin >> exit;
        if (exit == "e")
            is_exit = true;

        Player old_player = player;

        Algorithm* algo = (Algorithm*) new AlphaBetaMiniMax();
        player.move(algo, maze, enemys);

        for (int i = 0; i < enemys.size(); i++)
        {
            enemys[i]->move(maze, old_player, enemys, i);
        }

        //std::this_thread::sleep_for(2s);

        reader_writer.write_console_maze(maze, player, enemys);
       
    }
}

bool ConsoleInterface::is_finish(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys)
{
    if (player.get_coordinates() == maze.get_end())
    {
        cout << "  !!Player Win" << endl;
        return true;
    }

    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->get_coordinates() == player.get_coordinates())
        {
            cout << "  !!Player lose" << endl;
            return true;
        } 
    }
    
    return false;
}
