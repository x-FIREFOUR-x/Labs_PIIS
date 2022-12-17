#pragma once

#include <vector>
#include <functional>

using namespace std;
class SimplexMatrix
{
private:
	vector<vector<float>> points;

	vector<float> function_values;

public:
	SimplexMatrix(int amount_points, int amount_varlibes);

	void set_point(int index_point, vector<float> point);

	vector<float> get_point(int index_point);

	vector<float> add_points(int index_point1, int index_point2);

	vector<float> sub_points(int index_point1, int index_point2);

	vector<float>& operator[](int index_point);

	void calculate_values_function(float (*function)(vector<float>));
	void sort(float (*function)(vector<float>));
};

