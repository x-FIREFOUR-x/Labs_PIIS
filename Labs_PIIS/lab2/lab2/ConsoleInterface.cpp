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

        ReaderWriter reader_writer;
        Maze maze;
        
        try
        {
            maze = reader_writer.read_maze_with_file(namefile);
            Player player(maze);
            
            if (output_maze)
            {
                reader_writer.write_console_maze(maze, player);
                output_maze = false;
            }

            int operation = 0;
            cout << "*Input 1 (Algorithm A*), 2 (Algorithm Li, Wave), 3 (two algo), 4(change file), other (exist): ";
            cin >> operation;

            bool success;

            switch (operation)
            {

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