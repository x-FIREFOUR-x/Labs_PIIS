#include "NelderMeadMethod.h"

float NelderMeadMethod::target_function(vector<float> point)
{
    float f = -5 * point[0] * pow(point[1], 2) * point[2]
        + 2 * pow(point[0], 2) * point[1]
        - 3 * point[0] * pow(point[1], 4)
        + point[0] * pow(point[2], 2);

    return f;
}

void NelderMeadMethod::calculate(vector<float> start_point, float distance_two_points, float precision, int number_iterations)
{
    n = start_point.size();
    SimplexMatrix simplex = get_start_points(start_point, distance_two_points);
    simplex.calculate_values_function(target_function);

    for (int i = 0; i < number_iterations; i++)
    {
        simplex.sort(target_function);

    }
    
}


SimplexMatrix NelderMeadMethod::get_start_points(vector<float> start_point, float distance_two_points)
{
    float d1 = 1 / (n * sqrt(2)) * (sqrt(n + 1) + n - 1);
    float d2 = 1 / (n * sqrt(2)) * (sqrt(n + 1) - 1);

    SimplexMatrix simplex(n + 1, n);
    simplex.set_point(0, start_point);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i - 1)
            {
                simplex[i][j] = simplex[1][j] + d1;
            }
            else
            {
                simplex[i][j] = simplex[1][j] + d2;
            }
        }

    }

    return simplex;
}
