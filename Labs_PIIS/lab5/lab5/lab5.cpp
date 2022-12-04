#include <iostream>

#include "FileWorker.h"
#include "SimplexMethod.h"

int main()
{
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;

    FileWorker fileworker;
    fileworker.read_matrix("file2.txt", A, B, C);

    SimplexMethod algo;
    vector<float> basis = algo.calculate_min();

    for (int i = 0; i < basis.size(); i++)
    {
        cout << "x" << i + 1 << ": " << basis[i] << endl;
    }

    cout << "value function: " << algo.get_value_function() << endl;
}

