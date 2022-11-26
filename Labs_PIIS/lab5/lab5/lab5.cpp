
#include <iostream>

#include "FileWorker.h"


int main()
{
    Matrix A;
    Matrix B;
    Matrix C;

    FileWorker fileworker;
    fileworker.read_matrix("file.txt", A, B, C);
    A.print();
    B.print();
    C.print();
}

