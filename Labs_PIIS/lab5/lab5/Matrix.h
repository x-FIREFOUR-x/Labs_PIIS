#include "vector"
#include <iostream>
#include <iomanip>
#include <queue>

#pragma once
using namespace std;
class Matrix
{
	vector<vector<float>> matrix;

public:
	Matrix() {};
	Matrix(vector<vector<float>> matrix);

	vector<int> get_free_variables(int amount_free_variables);

	void print();
};

