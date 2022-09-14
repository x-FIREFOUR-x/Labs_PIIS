#include "ConsoleInterface.h"

void ConsoleInterface::run()
{
    bool is_run = true;
    bool file_input = false;
    string namefile;

    while (is_run)
    {
        if (!file_input)
        {
            cout << " -Input name file: ";
            cin >> namefile;
            file_input = true;
        }

        MazeReaderWriter reader_writer;
        Maze maze;
        try
        {
            maze = reader_writer.read_maze_with_file(namefile);

            int operation = 0;
            cout << " Input 1 (Algorithm A*), 2 (Algorithm Li, Wave), 3 (two algo), 4(change file), other (exist): ";
            cin >> operation;

            AStar algo_astar;
            WaveAlgo algo_wave;

            switch (operation)
            {
            case 1:
                cout << endl << "Algorithm A*:" << endl;
                algo_astar.search_path(maze);
                reader_writer.write_console_maze_and_path(maze);
                break;

            case 2:
                cout << endl << "Algorithm Li or Wave:" << endl;
                algo_wave.search_path(maze);
                reader_writer.write_console_maze_and_path(maze);
                break;

            case 3:
                cout << endl << "Algorithm A*:" << endl;
                algo_astar.search_path(maze);
                reader_writer.write_console_maze_and_path(maze);

                cout << "Algorithm Li or Wave:" << endl;
                maze = reader_writer.read_maze_with_file(namefile);
                algo_wave.search_path(maze);
                reader_writer.write_console_maze_and_path(maze);
                break;

            case 4:
                file_input = false;
                break;

            default:
                is_run = false;
                break;
            }
            
        }
        catch (const std::exception& ex)
        {
            cout << ex.what() << endl;
            file_input = false;
        }
    }

   
}