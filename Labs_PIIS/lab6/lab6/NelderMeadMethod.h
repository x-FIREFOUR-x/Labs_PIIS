#pragma once

#include <vector>
#include "SimplexMatrix.h"

using namespace std;
class NelderMeadMethod
{
private:
    const int alpha = 1;
    const int gamma_lower = 2;
    const int gamma_upper = 3;
    const float beta_lower = 0.4;
    const float beta_upper = 0.6;
    const float sigma = 0.5;
    int n;

public:
    static float target_function(Point point);
    
    void calculate(Point start_point, float distance_two_points, float precision, int number_iterations);

private:

    SimplexMatrix create_start_points(Point start_point, float distance_two_points);

    Point get_point_center_gravity(SimplexMatrix simplex);
    Point get_reflected_point(Point center_point, Point worst_point);
    Point get_expanded_point(Point center_point, Point reflected_point);
    Point get_contracted_point(Point center_point, Point reflected_point, float precision);
    SimplexMatrix replace_points_to_best(SimplexMatrix simplex);
};

