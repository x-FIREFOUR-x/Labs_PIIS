#pragma once

#include <vector>
#include <functional>

#include "Point.h"

using namespace std;
class SimplexMatrix
{
private:
	vector<Point> points;

	vector<float> function_values;

public:
	SimplexMatrix(int amount_points, int amount_varlibes);

	Point& operator[](int index_point);
	Point& worst_point();

	void calculate_values_function(float (*function)(Point));
	void sort(float (*function)(Point));

	void print();
};

