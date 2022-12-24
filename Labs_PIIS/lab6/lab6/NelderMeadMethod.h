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
    const double beta_lower = 0.4;
    const double beta_upper = 0.6;
    const double sigma = 0.5;
    int n = 3;

public:
    static double target_function(Point point);
    
    void calculate(Point start_point, double distance_two_points, double precision, int number_iterations);

private:

    SimplexMatrix create_start_points(Point start_point, double distance_two_points);

    Point get_point_center_gravity(SimplexMatrix simplex);
    Point get_reflected_point(Point center_point, Point worst_point);
    Point get_expanded_point(Point center_point, Point reflected_point);
    Point get_contracted_point(Point center_point, Point reflected_point);
    SimplexMatrix replace_points_to_best(SimplexMatrix simplex);

    bool check_stop(SimplexMatrix simplex, Point center_point, double precision);
};

