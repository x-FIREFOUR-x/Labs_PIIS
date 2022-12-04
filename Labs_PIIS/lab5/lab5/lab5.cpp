#include <iostream>

#include "FileWorker.h"
#include "SimplexMethod.h"

int main()
{
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;

    FileWorker fileworker;
    bool is_correct = false;
    while (!is_correct)
    {
        is_correct = true;
        cout << "Input name file: ";
        string filename;
        cin >> filename;
        try
        {
            fileworker.read_matrix(filename, A, B, C);
        }
        catch (const std::exception&)
        {
            cout << " !Fail.Unexist file" << endl;
            is_correct = false;
        }
    }
    
    SimplexMethod algo(A, B, C);
    vector<float> basis = algo.calculate_min();

    cout << "==============Result====================" << endl;
    for (int i = 0; i < basis.size(); i++)
    {
        cout << "x" << i + 1 << ": " << basis[i] << endl;
    }
    cout << "value function: " << algo.get_value_function() << endl;
}

