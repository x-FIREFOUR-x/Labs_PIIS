#include <iostream>

#include "NelderMeadMethod.h"

int main()
{
    NelderMeadMethod algo;

    Point startpoint (vector<float>{ 3, 3, 2 });
    algo.calculate(startpoint, 1, 0.01, 10);
}
