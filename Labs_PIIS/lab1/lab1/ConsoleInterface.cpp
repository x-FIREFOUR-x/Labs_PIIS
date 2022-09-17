#include "ConsoleInterface.h"

void ConsoleInterface::run()
{
    bool is_run = true;
    bool file_input = false;
    bool output_maze = false;
    string namefile;

    while (is_run)
    {
        if (!file_input)
        {
            cout << " -Input name file: ";
            cin >> namefile;
            file_input = true;
            output_maze = true;
        }

        MazeReaderWriter reader_writer;
        Maze maze;
        try
        {
            maze = reader_writer.read_maze_with_file(namefile);
            
            if (output_maze)
            {
                reader_writer.write_console_maze(maze);
                output_maze = false;
            }
                
            int operation = 0;
            cout << "*Input 1 (Algorithm A*), 2 (Algorithm Li, Wave), 3 (two algo), 4(change file), other (exist): ";
            cin >> operation;

            AStar algo_astar;
            WaveAlgo algo_wave;
            bool success;

            switch (operation)
            {
            case 1:
                cout << endl << "Algorithm A*:" << endl;
                success = algo_astar.search_path(maze);

                if (success)
                    reader_writer.write_console_maze_and_path(maze);
                else
                    cout << " !The path is missing" << endl;

                break;

            case 2:
                cout << endl << "Algorithm Li or Wave:" << endl;
                success = algo_wave.search_path(maze);

                if (success)
                    reader_writer.write_console_maze_and_path(maze);
                else
                    cout << " !The path is missing" << endl;

                break;

            case 3:
                cout << endl << "Algorithm A*:" << endl;
                success = algo_astar.search_path(maze);

                if (success)
                    reader_writer.write_console_maze_and_path(maze);
                else
                    cout << " !The path is missing" << endl;

                cout << "Algorithm Li or Wave:" << endl;
                maze = reader_writer.read_maze_with_file(namefile);
                success = algo_wave.search_path(maze);

                if (success)
                    reader_writer.write_console_maze_and_path(maze);
                else
                    cout << " !The path is missing" << endl;

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