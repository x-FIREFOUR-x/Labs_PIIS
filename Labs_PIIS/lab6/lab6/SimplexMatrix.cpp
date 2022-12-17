#include "SimplexMatrix.h"

#include <algorithm>

SimplexMatrix::SimplexMatrix(int amount_points, int amount_varlibes)
{
	function_values = vector<float>(amount_points, 0);

	for (int i = 0; i < amount_points; i++)
	{
		vector<float> line(amount_varlibes, 0);
		points.push_back(line);
	}
}

void SimplexMatrix::set_point(int index_point, vector<float> point)
{
	points[index_point] = point;
}

vector<float> SimplexMatrix::get_point(int index_point)
{
	return points[index_point];
}

vector<float> SimplexMatrix::add_points(int index_point1, int index_point2)
{
	vector<float> result;
	for (int i = 0; i < points[index_point1].size(); i++)
	{
		result.push_back(points[index_point1][i] + points[index_point2][i]);
	}
	return result;
}

vector<float> SimplexMatrix::sub_points(int index_point1, int index_point2)
{
	vector<float> result;
	for (int i = 0; i < points[index_point1].size(); i++)
	{
		result.push_back(points[index_point1][i] - points[index_point2][i]);
	}
	return result;
}

vector<float>& SimplexMatrix::operator[](int index_point)
{
	return points[index_point];
}

void SimplexMatrix::calculate_values_function(float (*function)(vector<float>))
{
	for (int i = 0; i < points.size(); i++)
	{
		function_values[i] = function(points[i]);
	}
}

void SimplexMatrix::sort(float (*function)(vector<float>))
{
	sort_heap(points.begin(), points.end(), [&function](vector<float> a, vector<float> b) {return function(a) < function(b); });

	sort_heap(function_values.begin(), function_values.end(), [](float a, float b) {return a < b; });
}
