
#include <iostream>

#include "FileWorker.h"
#include "SimplexMethodMax.h"


int main()
{
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;

    FileWorker fileworker;
    fileworker.read_matrix("file2.txt", A, B, C);

    SimplexMethodMax s(A, B, C);
    s.CalculateSimplex();
}

