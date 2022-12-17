#include <iostream>

#include "NelderMeadMethod.h"

int main()
{
    std::cout << "Hello World!\n";

    NelderMeadMethod algo;

    vector<float> startpoint{ 3, 3, 2 };
    algo.calculate(startpoint, 1, 0.01, 10);
}
