#include "ConsoleInterface.h"

#include "MiniMax.h"
#include "AlphaBetaMiniMax.h"
#include "Expectimax.h"

#include <thread>
#include <chrono>
#include <ctime>

void ConsoleInterface::run()
{
    bool input_gamemode_correct = false;
    while (!input_gamemode_correct)
    {
        input_gamemode_correct = choose_mode_game();
    }
    if (is_exit)
        return;

    bool input_file_correct = false; 
    while (!input_file_correct)
    {
        input_file_correct = input_file_date();
    }
    if (is_exit)
        return;

    bool input_enemys_correct = false;
    while (!input_enemys_correct)
    {
        input_enemys_correct = input_enemys_date();
    }
    if (is_exit)
        return;

    bool chose_algorithm_correct = false;
    while (!chose_algorithm_correct)
    {
        chose_algorithm_correct = chose_algorithm();
    }
    if (is_exit)
        return;

    while (!is_exit)
    {
        reader_writer.write_console_maze(maze, player, enemys);

        if (is_finish(maze, player, enemys))
            break;

        
        if (!is_auto)
        {
            string exit = "";
            cin >> exit;
            if (exit == "exit")
                is_exit = true;
        }
        
        clock_t start_time = clock();

        Player old_player = player;

        player.move(algorithm, maze, enemys);

        for (int i = 0; i < enemys.size(); i++)
        {
            enemys[i]->move(maze, old_player, enemys, i);
        }

        clock_t end_time = clock();
        if (is_auto)
        {
            clock_t mseconds = (end_time - start_time);
            clock_t time_stop = 1 * CLOCKS_PER_SEC;
            if (mseconds < time_stop)
            {
                mseconds = time_stop - mseconds;
                std::this_thread::sleep_for(std::chrono::milliseconds(mseconds));
                
            }
        }
    }
}

bool ConsoleInterface::choose_mode_game()
{
    string mode;
    cout << " Choose mode game(1 - render console auto, 2 - render console manual): ";
    cin >> mode;

    if (mode == "exit")
    {
        is_exit = true;
        return true;
    }

    int gamemode = stoi(mode);
    switch (gamemode)
    {
    case 1:
        is_auto = true;
        break;
    case 2:
        is_auto = false;
        break;
    default:
        return false;
    }

    return true;
}

bool ConsoleInterface::input_file_date()
{
    string namefile;
    cout << " -Input name file: ";
    cin >> namefile;

    if (namefile == "exit")
    {
        is_exit = true;
        return true;
    }

    try
    {
        maze = reader_writer.read_maze_with_file(namefile);
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << namefile << endl;
        return false;
    }
    player = Player(maze);
    return true;
}

bool ConsoleInterface::input_enemys_date()
{
    string amount_enemys;
    cout << " -Input amount enemys: ";
    cin >> amount_enemys;

    if (amount_enemys == "exit")
    {
        is_exit = true;
        return true;
    }

    int amount = stoi(amount_enemys);
    if (amount <= 0)
    {
        return false;
    }

    string type_enemys;
    cout << " -Input type enemys (1 - random, 2 - A*): ";
    cin >> type_enemys;

    if (type_enemys == "exit")
    {
        is_exit = true;
        return true;
    }
    
    int type = stoi(type_enemys);
    switch (type)
    {
    case 1:
        enemys = CreaterEnemy::createEnemys(amount, 0, maze, player);
        break;
    case 2:
        enemys = CreaterEnemy::createEnemys(0, amount, maze, player);
        break;
    default:
        return false;
    }

    return true;
}

bool ConsoleInterface::chose_algorithm()
{
    string type_algo;
    cout << " -Input algorithm(1 - MiniMax, 2 - Alpha-Beta MiniMax, 3 - Expectimax): ";
    cin >> type_algo;

    if (type_algo == "exit")
    {
        is_exit = true;
        return true;
    }
    int type = stoi(type_algo);

    switch (type)
    {
    case 1:
        algorithm = make_shared<MiniMax>(MiniMax(11, 1, 2));
    case 2:
        algorithm = make_shared<AlphaBetaMiniMax>(AlphaBetaMiniMax(11, 1, 2));
        break;
    case 3:
        algorithm = make_shared<Expectimax>(Expectimax(1, 1, 1000));
        break;
    default:
        return false;
    }

    return true;
}


bool ConsoleInterface::is_finish(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys)
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
