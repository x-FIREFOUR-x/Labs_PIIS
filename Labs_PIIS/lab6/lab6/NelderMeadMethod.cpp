#include "NelderMeadMethod.h"

#include <iostream>

float NelderMeadMethod::target_function(Point point)
{
    float f = -5 * point[0] * pow(point[1], 2) * point[2]
        + 2 * pow(point[0], 2) * point[1]
        - 3 * point[0] * pow(point[1], 4)
        + point[0] * pow(point[2], 2);

    return f;
}

void NelderMeadMethod::calculate(Point start_point, float distance_two_points, float precision, int number_iterations)
{
    n = start_point.size();
    SimplexMatrix simplex = create_start_points(start_point, distance_two_points);

    for (int i = 0; i < number_iterations; i++)
    {
        simplex.calculate_values_function(target_function);
        simplex.sort(target_function);

        cout << i << "===================================================" << endl;
        simplex.print();

        Point center_point = get_point_center_gravity(simplex);

        if (check_stop(simplex, center_point, precision))
            break;

        //3 Reflection
        Point reflected_point = get_reflected_point(center_point, simplex[n]);  
        if (target_function(reflected_point) >= target_function(simplex[0]) && 
            target_function(reflected_point) < target_function(simplex[n-1]))
        {
            simplex[n] = reflected_point;
            continue;
        }

            //4 Expansion
        if (target_function(reflected_point) < target_function(simplex[0]))
        {
            Point expanded_point = get_expanded_point(center_point, reflected_point);
            if (target_function(expanded_point) < target_function(reflected_point))
            {
                simplex[n] = expanded_point;
                continue;
            }
            else
            {
                simplex[n] = reflected_point;
                continue;
            }
        }

            //5 Contraction
        if (target_function(reflected_point) < target_function(simplex[n]))
        {
            Point contracted_point = get_contracted_point(center_point, reflected_point);
            if (target_function(contracted_point) < target_function(reflected_point))
            {
                simplex[n] = contracted_point;
                continue;
            }
        }
        if (target_function(reflected_point) >= target_function(simplex[n]))
        {
            Point contracted_point = get_contracted_point(center_point, simplex[n]);
            if (target_function(contracted_point) < target_function(simplex[n]))
            {
                simplex[n] = contracted_point;
                continue;
            }
        }

            //6 Shrink
        replace_points_to_best(simplex);
    }
    

    cout << number_iterations << "===================================================" << endl;
    simplex.print();
}


SimplexMatrix NelderMeadMethod::create_start_points(Point start_point, float distance_two_points)
{
    float d1 = 1 / (n * sqrt(2)) * (sqrt(n + 1) + n - 1);
    float d2 = 1 / (n * sqrt(2)) * (sqrt(n + 1) - 1);

    SimplexMatrix simplex(n + 1, n);
    simplex[0] = start_point;

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

Point NelderMeadMethod::get_point_center_gravity(SimplexMatrix simplex)
{
    Point center_point = simplex[0];
    for (int i = 1; i < n; i++)
    {
        center_point = center_point + simplex[i];
    }

    center_point = center_point / n;

    return center_point;
}

Point NelderMeadMethod::get_reflected_point(Point center_point, Point worst_point)
{
    return center_point + (center_point - worst_point) * alpha;
}

Point NelderMeadMethod::get_expanded_point(Point center_point, Point reflected_point)
{
    float gamma = (gamma_lower + gamma_upper) / 2;
    return center_point + (reflected_point - center_point) * gamma;
}

Point NelderMeadMethod::get_contracted_point(Point center_point, Point point)
{
    float beta = (beta_lower + beta_upper) / 2;
    return center_point + (point - center_point) * beta;
}

SimplexMatrix NelderMeadMethod::replace_points_to_best(SimplexMatrix simplex)
{
    for (int i = 1; i < n + 1; i++)
    {
        simplex[i] = simplex[0] + (simplex[i] - simplex[0]) * sigma;
    }

    return simplex;
}

bool NelderMeadMethod::check_stop(SimplexMatrix simplex, Point center_point, float precision)
{
    float suma = 0;
    for (int i = 0; i < n + 1; i++)
    {
        suma += pow(target_function(simplex[i]) - target_function(center_point), 2);
    }

    suma = sqrt(suma / (n + 1));
    
    return suma <= precision;
}

