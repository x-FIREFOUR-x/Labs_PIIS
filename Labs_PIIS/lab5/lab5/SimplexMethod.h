#pragma once

#include <vector>

#include "Matrix.h"

using namespace std;
class SimplexMethod
{
	vector<vector<float>> A;
	vector<float> B;
	vector<float> C;

	bool is_unbounded = false;
	float maximum;

public:
	SimplexMethod(vector<vector<float>>& A, vector<float> B, vector<float> C);
	void print();

	void CalculateSimplex();

	bool simplex_algorithm_calculataion();
	bool check_optimality();

	void make_pivotting(int pivotRow, int pivotColumn);
	int find_pivot_column();
	int find_pivot_row(int pivotColumn);
};

