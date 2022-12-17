#include "SimplexMatrix.h"

#include <algorithm>

SimplexMatrix::SimplexMatrix(int amount_points, int amount_varlibes)
{
	function_values = vector<float>(amount_points, 0);

	for (int i = 0; i < amount_points; i++)
	{
		Point point(amount_varlibes);
		points.push_back(point);
	}
}

Point& SimplexMatrix::operator[](int index_point)
{
	return points[index_point];
}


void SimplexMatrix::calculate_values_function(float (*function)(Point))
{
	for (int i = 0; i < points.size(); i++)
	{
		function_values[i] = function(points[i]);
	}
}

void SimplexMatrix::sort(float (*function)(Point))
{
	stable_sort(points.begin(), points.end(), [&function](Point a, Point b) {return function(a) < function(b); });

	stable_sort(function_values.begin(), function_values.end(), [](float a, float b) {return a < b; });
}


