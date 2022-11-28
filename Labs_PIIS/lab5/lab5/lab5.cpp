#include <iostream>

#include "FileWorker.h"

int main()
{
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;

    FileWorker fileworker;
    fileworker.read_matrix("file2.txt", A, B, C);
}

