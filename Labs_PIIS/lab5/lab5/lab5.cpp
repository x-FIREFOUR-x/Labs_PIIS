
#include <iostream>

#include "FileWorker.h"
#include "SimplexMethod.h"


int main()
{
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;

    FileWorker fileworker;
    fileworker.read_matrix("file.txt", A, B, C);

    SimplexMethod s(A, B, C);
    s.CalculateSimplex();
}

