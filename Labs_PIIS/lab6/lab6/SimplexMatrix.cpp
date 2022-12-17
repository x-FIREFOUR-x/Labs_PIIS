#include "SimplexMatrix.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

SimplexMatrix::SimplexMatrix(int amount_points, int amount_varlibes)
{
	function_values = vector<double>(amount_points, 0);

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

Point& SimplexMatrix::worst_point()
{
	return points.back();
}


void SimplexMatrix::calculate_values_function(double (*function)(Point))
{
	for (int i = 0; i < points.size(); i++)
	{
		function_values[i] = function(points[i]);
	}
}

void SimplexMatrix::sort(double (*function)(Point))
{
	stable_sort(points.begin(), points.end(), [&function](Point a, Point b) {return function(a) < function(b); });

	stable_sort(function_values.begin(), function_values.end(), [](double a, double b) {return a < b; });
}

void SimplexMatrix::print()
{
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < points[i].size(); j++)
		{
			cout << std::fixed << std::setprecision(3) << " " << setw(7) << points[i][j];
		}

		cout << " = " << std::fixed << std::setprecision(3) << " " << setw(20) << function_values[i] << endl;
	}
	cout << endl;
}
